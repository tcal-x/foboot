#!/usr/bin/env python3
# This variable defines all the external programs that this module
# relies on.  lxbuildenv reads this variable in order to ensure
# the build will finish without exiting due to missing third-party
# programs.
LX_DEPENDENCIES = ["riscv", "icestorm", "yosys"]

# Import lxbuildenv to integrate the deps/ directory
import lxbuildenv

# Disable pylint's E1101, which breaks completely on migen
#pylint:disable=E1101

#from migen import *
from migen import Module, Signal, Instance, ClockDomain, If
from migen.genlib.resetsync import AsyncResetSynchronizer
from litex.build.lattice.platform import LatticePlatform
from litex.build.generic_platform import Pins, IOStandard, Misc, Subsignal
from litex.soc.integration import SoCCore
from litex.soc.integration.builder import Builder
from litex.soc.integration.soc_core import csr_map_update
from litex.soc.interconnect import wishbone

from lxsocsupport import up5kspram, cas, spi_flash

import argparse

_io = [
    ("serial", 0,
        Subsignal("rx", Pins("21")),
        Subsignal("tx", Pins("13"), Misc("PULLUP")),
        IOStandard("LVCMOS33")
    ),
    ("clk48", 0, Pins("44"), IOStandard("LVCMOS33"))
]

_connectors = []

class _CRG(Module):
    def __init__(self, platform):
        clk12 = Signal()
        # "0b00" Sets 48MHz HFOSC output
        # "0b01" Sets 24MHz HFOSC output.
        # "0b10" Sets 12MHz HFOSC output.
        # "0b11" Sets 6MHz HFOSC output
        self.specials += Instance(
            "SB_HFOSC",
            i_CLKHFEN=1,
            i_CLKHFPU=1,
            o_CLKHF=clk12,
            p_CLKHF_DIV="0b10", # 12MHz
        )

        self.clock_domains.cd_sys = ClockDomain()
        self.clock_domains.cd_usb_12 = ClockDomain()
        self.reset = Signal()

        # FIXME: Use PLL, increase system clock to 32 MHz, pending nextpnr
        # fixes.
        self.comb += self.cd_sys.clk.eq(clk12)
        self.comb += self.cd_usb_12.clk.eq(clk12)

        # POR reset logic- POR generated from sys clk, POR logic feeds sys clk
        # reset.
        self.clock_domains.cd_por = ClockDomain()
        reset_delay = Signal(12, reset=4095)
        self.comb += [
            self.cd_por.clk.eq(self.cd_sys.clk),
            self.cd_sys.rst.eq(reset_delay != 0),
            self.cd_usb_12.rst.eq(reset_delay != 0)
        ]
        self.sync.por += \
            If(reset_delay != 0,
                reset_delay.eq(reset_delay - 1)
            )
        self.specials += AsyncResetSynchronizer(self.cd_por, self.reset)

        self.clock_domains.cd_usb_48 = ClockDomain()
        platform.add_period_constraint(self.cd_usb_48.clk, 1e9/48e6)
        self.comb += [
            self.cd_usb_48.clk.eq(platform.request("clk48")),
        ]

class RandomFirmwareROM(wishbone.SRAM):
    def __init__(self, size, seed=2373):
        import random
        # Seed the random data with a fixed number, so different bitstreams
        # can all share firmware.
        random.seed(seed)
        data = []
        for d in range(int(size / 4)):
            data.append(random.getrandbits(32))
        print("Firmware {} bytes of random data".format(size))
        wishbone.SRAM.__init__(self, size, read_only=True, init=data)

class Platform(LatticePlatform):
    def __init__(self, toolchain="icestorm"):
        LatticePlatform.__init__(self, "ice40-up5k-sg48", _io, _connectors, toolchain="icestorm")
    def create_programmer(self):
        raise ValueError("programming is not supported")

    def do_finalize(self, fragment):
        LatticePlatform.do_finalize(self, fragment)

class BaseSoC(SoCCore):
    csr_peripherals = [
        "cpu_or_bridge",
    ]
    csr_map_update(SoCCore.csr_map, csr_peripherals)

    mem_map = {
        "spiflash": 0x20000000,  # (default shadow @0xa0000000)
    }
    mem_map.update(SoCCore.mem_map)

    gateware_size = 0x20000

    def __init__(self, platform, boot_source="random_rom", **kwargs):
        # Disable integrated RAM as we'll add it later
        self.integrated_sram_size = 0

        clk_freq = int(12e6)
        self.submodules.crg = _CRG(platform)
        platform.add_period_constraint(self.crg.cd_sys.clk, 1e9/clk_freq)
        platform.add_period_constraint(self.crg.cd_usb_12.clk, 1e9/clk_freq)

        SoCCore.__init__(self, platform, clk_freq, integrated_sram_size=0, **kwargs)

        # SPRAM- UP5K has single port RAM, might as well use it as SRAM to
        # free up scarce block RAM.
        spram_size = 128*1024
        self.submodules.spram = up5kspram.Up5kSPRAM(size=spram_size)
        self.register_mem("sram", 0x10000000, self.spram.bus, spram_size)

        if boot_source == "random_rom":
            kwargs['cpu_reset_address']=0
            bios_size = 0x2000
            self.submodules.random_rom = RandomFirmwareROM(bios_size)
            self.add_constant("ROM_DISABLE", 1)
            self.register_rom(self.random_rom.bus, bios_size)
        elif boot_source == "bios_rom":
            kwargs['cpu_reset_address']=0
            bios_size = 0x2000
            self.add_memory_region("rom", kwargs['cpu_reset_address'], bios_size)
        elif boot_source == "spi_rom":
            bios_size = 0x8000
            kwargs['cpu_reset_address']=self.mem_map["spiflash"]+self.gateware_size
            self.add_memory_region("rom", kwargs['cpu_reset_address'], bios_size)
            self.add_constant("ROM_DISABLE", 1)
            self.flash_boot_address = self.mem_map["spiflash"]+self.gateware_size+bios_size
            self.add_memory_region("user_flash",
                self.flash_boot_address,
                # Leave a grace area- possible one-by-off bug in add_memory_region?
                # Possible fix: addr < origin + length - 1
                platform.spiflash_total_size - (self.flash_boot_address - self.mem_map["spiflash"]) - 0x100)
        else:
            raise ValueError("unrecognized boot_source: {}".format(boot_source))

        # Disable final deep-sleep power down so firmware words are loaded
        # onto softcore's address bus.
        platform.toolchain.build_template[3] = "icepack -s {build_name}.txt {build_name}.bin"
        platform.toolchain.nextpnr_build_template[2] = "icepack -s {build_name}.txt {build_name}.bin"

def main():
    platform = Platform()

    parser = argparse.ArgumentParser(
        description="Build Fomu Main Gateware",
        add_help=False)
    parser.add_argument(
        "--bios", help="use bios as boot source", action="store_true"
    )
    parser.add_argument(
        "--rand", help="use random data as boot source", action="store_false"
    )
    parser.add_argument(
        "--spi", help="boot from spi", action="store_true"
    )
    (args, rest) = parser.parse_known_args()

    if args.rand:
        boot_source="random_rom"
        compile_software=False
    elif args.bios:
        boot_source="bios_rom"
        compile_software=True
    elif args.spi:
        boot_source = "spi_rom"
        compile_software = False

    soc = BaseSoC(platform, cpu_type="vexriscv", cpu_variant="min", boot_source=boot_source)
    builder = Builder(soc, output_dir="build", csr_csv="test/csr.csv", compile_software=compile_software)
    vns = builder.build()
    soc.do_exit(vns)

if __name__ == "__main__":
    main()
