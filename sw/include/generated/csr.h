#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H
#include <stdint.h>
#ifdef CSR_ACCESSORS_DEFINED
extern void csr_writeb(uint8_t value, uint32_t addr);
extern uint8_t csr_readb(uint32_t addr);
extern void csr_writew(uint16_t value, uint32_t addr);
extern uint16_t csr_readw(uint32_t addr);
extern void csr_writel(uint32_t value, uint32_t addr);
extern uint32_t csr_readl(uint32_t addr);
#else /* ! CSR_ACCESSORS_DEFINED */
#include <hw/common.h>
#endif /* ! CSR_ACCESSORS_DEFINED */

/* bbspi */
#define CSR_BBSPI_BASE 0xe0005000
#define CSR_BBSPI_DO_ADDR 0xe0005000
#define CSR_BBSPI_DO_SIZE 1
static inline unsigned char bbspi_do_read(void) {
	unsigned char r = csr_readl(0xe0005000);
	return r;
}
static inline void bbspi_do_write(unsigned char value) {
	csr_writel(value, 0xe0005000);
}
#define CSR_BBSPI_OE_ADDR 0xe0005004
#define CSR_BBSPI_OE_SIZE 1
static inline unsigned char bbspi_oe_read(void) {
	unsigned char r = csr_readl(0xe0005004);
	return r;
}
static inline void bbspi_oe_write(unsigned char value) {
	csr_writel(value, 0xe0005004);
}
#define CSR_BBSPI_DI_ADDR 0xe0005008
#define CSR_BBSPI_DI_SIZE 1
static inline unsigned char bbspi_di_read(void) {
	unsigned char r = csr_readl(0xe0005008);
	return r;
}

/* ctrl */
#define CSR_CTRL_BASE 0xe0000000
#define CSR_CTRL_RESET_ADDR 0xe0000000
#define CSR_CTRL_RESET_SIZE 1
static inline unsigned char ctrl_reset_read(void) {
	unsigned char r = csr_readl(0xe0000000);
	return r;
}
static inline void ctrl_reset_write(unsigned char value) {
	csr_writel(value, 0xe0000000);
}
#define CSR_CTRL_SCRATCH_ADDR 0xe0000004
#define CSR_CTRL_SCRATCH_SIZE 4
static inline unsigned int ctrl_scratch_read(void) {
	unsigned int r = csr_readl(0xe0000004);
	r <<= 8;
	r |= csr_readl(0xe0000008);
	r <<= 8;
	r |= csr_readl(0xe000000c);
	r <<= 8;
	r |= csr_readl(0xe0000010);
	return r;
}
static inline void ctrl_scratch_write(unsigned int value) {
	csr_writel(value >> 24, 0xe0000004);
	csr_writel(value >> 16, 0xe0000008);
	csr_writel(value >> 8, 0xe000000c);
	csr_writel(value, 0xe0000010);
}
#define CSR_CTRL_BUS_ERRORS_ADDR 0xe0000014
#define CSR_CTRL_BUS_ERRORS_SIZE 4
static inline unsigned int ctrl_bus_errors_read(void) {
	unsigned int r = csr_readl(0xe0000014);
	r <<= 8;
	r |= csr_readl(0xe0000018);
	r <<= 8;
	r |= csr_readl(0xe000001c);
	r <<= 8;
	r |= csr_readl(0xe0000020);
	return r;
}

/* reboot */
#define CSR_REBOOT_BASE 0xe0005800
#define CSR_REBOOT_CTRL_ADDR 0xe0005800
#define CSR_REBOOT_CTRL_SIZE 1
static inline unsigned char reboot_ctrl_read(void) {
	unsigned char r = csr_readl(0xe0005800);
	return r;
}
static inline void reboot_ctrl_write(unsigned char value) {
	csr_writel(value, 0xe0005800);
}

/* rgb */
#define CSR_RGB_BASE 0xe0006000
#define CSR_RGB_DAT_ADDR 0xe0006000
#define CSR_RGB_DAT_SIZE 1
static inline unsigned char rgb_dat_read(void) {
	unsigned char r = csr_readl(0xe0006000);
	return r;
}
static inline void rgb_dat_write(unsigned char value) {
	csr_writel(value, 0xe0006000);
}
#define CSR_RGB_ADDR_ADDR 0xe0006004
#define CSR_RGB_ADDR_SIZE 1
static inline unsigned char rgb_addr_read(void) {
	unsigned char r = csr_readl(0xe0006004);
	return r;
}
static inline void rgb_addr_write(unsigned char value) {
	csr_writel(value, 0xe0006004);
}
#define CSR_RGB_CTRL_ADDR 0xe0006008
#define CSR_RGB_CTRL_SIZE 1
static inline unsigned char rgb_ctrl_read(void) {
	unsigned char r = csr_readl(0xe0006008);
	return r;
}
static inline void rgb_ctrl_write(unsigned char value) {
	csr_writel(value, 0xe0006008);
}

/* timer0 */
#define CSR_TIMER0_BASE 0xe0002800
#define CSR_TIMER0_LOAD_ADDR 0xe0002800
#define CSR_TIMER0_LOAD_SIZE 4
static inline unsigned int timer0_load_read(void) {
	unsigned int r = csr_readl(0xe0002800);
	r <<= 8;
	r |= csr_readl(0xe0002804);
	r <<= 8;
	r |= csr_readl(0xe0002808);
	r <<= 8;
	r |= csr_readl(0xe000280c);
	return r;
}
static inline void timer0_load_write(unsigned int value) {
	csr_writel(value >> 24, 0xe0002800);
	csr_writel(value >> 16, 0xe0002804);
	csr_writel(value >> 8, 0xe0002808);
	csr_writel(value, 0xe000280c);
}
#define CSR_TIMER0_RELOAD_ADDR 0xe0002810
#define CSR_TIMER0_RELOAD_SIZE 4
static inline unsigned int timer0_reload_read(void) {
	unsigned int r = csr_readl(0xe0002810);
	r <<= 8;
	r |= csr_readl(0xe0002814);
	r <<= 8;
	r |= csr_readl(0xe0002818);
	r <<= 8;
	r |= csr_readl(0xe000281c);
	return r;
}
static inline void timer0_reload_write(unsigned int value) {
	csr_writel(value >> 24, 0xe0002810);
	csr_writel(value >> 16, 0xe0002814);
	csr_writel(value >> 8, 0xe0002818);
	csr_writel(value, 0xe000281c);
}
#define CSR_TIMER0_EN_ADDR 0xe0002820
#define CSR_TIMER0_EN_SIZE 1
static inline unsigned char timer0_en_read(void) {
	unsigned char r = csr_readl(0xe0002820);
	return r;
}
static inline void timer0_en_write(unsigned char value) {
	csr_writel(value, 0xe0002820);
}
#define CSR_TIMER0_UPDATE_VALUE_ADDR 0xe0002824
#define CSR_TIMER0_UPDATE_VALUE_SIZE 1
static inline unsigned char timer0_update_value_read(void) {
	unsigned char r = csr_readl(0xe0002824);
	return r;
}
static inline void timer0_update_value_write(unsigned char value) {
	csr_writel(value, 0xe0002824);
}
#define CSR_TIMER0_VALUE_ADDR 0xe0002828
#define CSR_TIMER0_VALUE_SIZE 4
static inline unsigned int timer0_value_read(void) {
	unsigned int r = csr_readl(0xe0002828);
	r <<= 8;
	r |= csr_readl(0xe000282c);
	r <<= 8;
	r |= csr_readl(0xe0002830);
	r <<= 8;
	r |= csr_readl(0xe0002834);
	return r;
}
#define CSR_TIMER0_EV_STATUS_ADDR 0xe0002838
#define CSR_TIMER0_EV_STATUS_SIZE 1
static inline unsigned char timer0_ev_status_read(void) {
	unsigned char r = csr_readl(0xe0002838);
	return r;
}
static inline void timer0_ev_status_write(unsigned char value) {
	csr_writel(value, 0xe0002838);
}
#define CSR_TIMER0_EV_PENDING_ADDR 0xe000283c
#define CSR_TIMER0_EV_PENDING_SIZE 1
static inline unsigned char timer0_ev_pending_read(void) {
	unsigned char r = csr_readl(0xe000283c);
	return r;
}
static inline void timer0_ev_pending_write(unsigned char value) {
	csr_writel(value, 0xe000283c);
}
#define CSR_TIMER0_EV_ENABLE_ADDR 0xe0002840
#define CSR_TIMER0_EV_ENABLE_SIZE 1
static inline unsigned char timer0_ev_enable_read(void) {
	unsigned char r = csr_readl(0xe0002840);
	return r;
}
static inline void timer0_ev_enable_write(unsigned char value) {
	csr_writel(value, 0xe0002840);
}

/* usb */
#define CSR_USB_BASE 0xe0004800
#define CSR_USB_PULLUP_OUT_ADDR 0xe0004800
#define CSR_USB_PULLUP_OUT_SIZE 1
static inline unsigned char usb_pullup_out_read(void) {
	unsigned char r = csr_readl(0xe0004800);
	return r;
}
static inline void usb_pullup_out_write(unsigned char value) {
	csr_writel(value, 0xe0004800);
}
#define CSR_USB_EP_0_OUT_EV_STATUS_ADDR 0xe0004804
#define CSR_USB_EP_0_OUT_EV_STATUS_SIZE 1
static inline unsigned char usb_ep_0_out_ev_status_read(void) {
	unsigned char r = csr_readl(0xe0004804);
	return r;
}
static inline void usb_ep_0_out_ev_status_write(unsigned char value) {
	csr_writel(value, 0xe0004804);
}
#define CSR_USB_EP_0_OUT_EV_PENDING_ADDR 0xe0004808
#define CSR_USB_EP_0_OUT_EV_PENDING_SIZE 1
static inline unsigned char usb_ep_0_out_ev_pending_read(void) {
	unsigned char r = csr_readl(0xe0004808);
	return r;
}
static inline void usb_ep_0_out_ev_pending_write(unsigned char value) {
	csr_writel(value, 0xe0004808);
}
#define CSR_USB_EP_0_OUT_EV_ENABLE_ADDR 0xe000480c
#define CSR_USB_EP_0_OUT_EV_ENABLE_SIZE 1
static inline unsigned char usb_ep_0_out_ev_enable_read(void) {
	unsigned char r = csr_readl(0xe000480c);
	return r;
}
static inline void usb_ep_0_out_ev_enable_write(unsigned char value) {
	csr_writel(value, 0xe000480c);
}
#define CSR_USB_EP_0_OUT_LAST_TOK_ADDR 0xe0004810
#define CSR_USB_EP_0_OUT_LAST_TOK_SIZE 1
static inline unsigned char usb_ep_0_out_last_tok_read(void) {
	unsigned char r = csr_readl(0xe0004810);
	return r;
}
#define CSR_USB_EP_0_OUT_RESPOND_ADDR 0xe0004814
#define CSR_USB_EP_0_OUT_RESPOND_SIZE 1
static inline unsigned char usb_ep_0_out_respond_read(void) {
	unsigned char r = csr_readl(0xe0004814);
	return r;
}
static inline void usb_ep_0_out_respond_write(unsigned char value) {
	csr_writel(value, 0xe0004814);
}
#define CSR_USB_EP_0_OUT_DTB_ADDR 0xe0004818
#define CSR_USB_EP_0_OUT_DTB_SIZE 1
static inline unsigned char usb_ep_0_out_dtb_read(void) {
	unsigned char r = csr_readl(0xe0004818);
	return r;
}
static inline void usb_ep_0_out_dtb_write(unsigned char value) {
	csr_writel(value, 0xe0004818);
}
#define CSR_USB_EP_0_OUT_OBUF_HEAD_ADDR 0xe000481c
#define CSR_USB_EP_0_OUT_OBUF_HEAD_SIZE 1
static inline unsigned char usb_ep_0_out_obuf_head_read(void) {
	unsigned char r = csr_readl(0xe000481c);
	return r;
}
static inline void usb_ep_0_out_obuf_head_write(unsigned char value) {
	csr_writel(value, 0xe000481c);
}
#define CSR_USB_EP_0_OUT_OBUF_EMPTY_ADDR 0xe0004820
#define CSR_USB_EP_0_OUT_OBUF_EMPTY_SIZE 1
static inline unsigned char usb_ep_0_out_obuf_empty_read(void) {
	unsigned char r = csr_readl(0xe0004820);
	return r;
}
#define CSR_USB_EP_0_IN_EV_STATUS_ADDR 0xe0004824
#define CSR_USB_EP_0_IN_EV_STATUS_SIZE 1
static inline unsigned char usb_ep_0_in_ev_status_read(void) {
	unsigned char r = csr_readl(0xe0004824);
	return r;
}
static inline void usb_ep_0_in_ev_status_write(unsigned char value) {
	csr_writel(value, 0xe0004824);
}
#define CSR_USB_EP_0_IN_EV_PENDING_ADDR 0xe0004828
#define CSR_USB_EP_0_IN_EV_PENDING_SIZE 1
static inline unsigned char usb_ep_0_in_ev_pending_read(void) {
	unsigned char r = csr_readl(0xe0004828);
	return r;
}
static inline void usb_ep_0_in_ev_pending_write(unsigned char value) {
	csr_writel(value, 0xe0004828);
}
#define CSR_USB_EP_0_IN_EV_ENABLE_ADDR 0xe000482c
#define CSR_USB_EP_0_IN_EV_ENABLE_SIZE 1
static inline unsigned char usb_ep_0_in_ev_enable_read(void) {
	unsigned char r = csr_readl(0xe000482c);
	return r;
}
static inline void usb_ep_0_in_ev_enable_write(unsigned char value) {
	csr_writel(value, 0xe000482c);
}
#define CSR_USB_EP_0_IN_LAST_TOK_ADDR 0xe0004830
#define CSR_USB_EP_0_IN_LAST_TOK_SIZE 1
static inline unsigned char usb_ep_0_in_last_tok_read(void) {
	unsigned char r = csr_readl(0xe0004830);
	return r;
}
#define CSR_USB_EP_0_IN_RESPOND_ADDR 0xe0004834
#define CSR_USB_EP_0_IN_RESPOND_SIZE 1
static inline unsigned char usb_ep_0_in_respond_read(void) {
	unsigned char r = csr_readl(0xe0004834);
	return r;
}
static inline void usb_ep_0_in_respond_write(unsigned char value) {
	csr_writel(value, 0xe0004834);
}
#define CSR_USB_EP_0_IN_DTB_ADDR 0xe0004838
#define CSR_USB_EP_0_IN_DTB_SIZE 1
static inline unsigned char usb_ep_0_in_dtb_read(void) {
	unsigned char r = csr_readl(0xe0004838);
	return r;
}
static inline void usb_ep_0_in_dtb_write(unsigned char value) {
	csr_writel(value, 0xe0004838);
}
#define CSR_USB_EP_0_IN_IBUF_HEAD_ADDR 0xe000483c
#define CSR_USB_EP_0_IN_IBUF_HEAD_SIZE 1
static inline unsigned char usb_ep_0_in_ibuf_head_read(void) {
	unsigned char r = csr_readl(0xe000483c);
	return r;
}
static inline void usb_ep_0_in_ibuf_head_write(unsigned char value) {
	csr_writel(value, 0xe000483c);
}
#define CSR_USB_EP_0_IN_IBUF_EMPTY_ADDR 0xe0004840
#define CSR_USB_EP_0_IN_IBUF_EMPTY_SIZE 1
static inline unsigned char usb_ep_0_in_ibuf_empty_read(void) {
	unsigned char r = csr_readl(0xe0004840);
	return r;
}

/* constants */
#define NMI_INTERRUPT 0
static inline int nmi_interrupt_read(void) {
	return 0;
}
#define TIMER0_INTERRUPT 1
static inline int timer0_interrupt_read(void) {
	return 1;
}
#define UART_INTERRUPT 2
static inline int uart_interrupt_read(void) {
	return 2;
}
#define USB_INTERRUPT 3
static inline int usb_interrupt_read(void) {
	return 3;
}
#define CSR_DATA_WIDTH 8
static inline int csr_data_width_read(void) {
	return 8;
}
#define SYSTEM_CLOCK_FREQUENCY 12000000
static inline int system_clock_frequency_read(void) {
	return 12000000;
}
#define ROM_DISABLE 1
static inline int rom_disable_read(void) {
	return 1;
}
#define CONFIG_CLOCK_FREQUENCY 12000000
static inline int config_clock_frequency_read(void) {
	return 12000000;
}
#define CONFIG_CPU_RESET_ADDR 0
static inline int config_cpu_reset_addr_read(void) {
	return 0;
}
#define CONFIG_CPU_TYPE "VEXRISCV"
static inline const char * config_cpu_type_read(void) {
	return "VEXRISCV";
}
#define CONFIG_CPU_VARIANT "VEXRISCV"
static inline const char * config_cpu_variant_read(void) {
	return "VEXRISCV";
}
#define CONFIG_CSR_DATA_WIDTH 8
static inline int config_csr_data_width_read(void) {
	return 8;
}

#endif
