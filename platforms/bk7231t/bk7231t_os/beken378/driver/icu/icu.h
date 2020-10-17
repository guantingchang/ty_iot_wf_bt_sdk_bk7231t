#ifndef _ICU_H_
#define _ICU_H_

#define ICU_DEBUG

#ifdef ICU_DEBUG
#define ICU_PRT      os_printf
#define ICU_WARN     warning_prf
#define ICU_FATAL    fatal_prf
#else
#define ICU_PRT      null_prf
#define ICU_WARN     null_prf
#define ICU_FATAL    null_prf
#endif

#define ICU_BASE                                     (0x00802000)

#define ICU_PERI_CLK_MUX                             (ICU_BASE + 0 * 4)
#define PERI_CLK_26M_XTAL                            (1)
#define PERI_CLK_DCO                                 (0)
#if (CFG_SOC_NAME == SOC_BK7231)
#define PERI_CLK_MUX_BIT                             (1 << 0)
#else
#define PERI_CLK_UART1                               (1 << 0)
#define PERI_CLK_UART2                               (1 << 1)
#define PERI_CLK_I2C1                                (1 << 2)
#define PERI_CLK_IRDA                                (1 << 3) 
#define PERI_CLK_I2C2                                (1 << 4)
#define PERI_CLK_SARADC                              (1 << 5)  // hardware bug: This two bits reversed
#define PERI_CLK_SPI                                 (1 << 6)
#define PERI_CLK_PWMS                                (1 << 7)
#define PERI_CLK_SDIO                                (1 << 8) 
#define PERI_CLK_SARADC_AUD                          (1 << 9) 

#define QSPI_CLK_MUX_POSI                            (16)
#define QSPI_CLK_MUX_MASK                            (0x3)
#define QSPI_CLK_MUX_DCO                             (0)
#define QSPI_CLK_MUX_26M                             (1)
#define QSPI_CLK_MUX_120M                            (2)
#if (CFG_SOC_NAME == SOC_BK7221U)
#define DCO_CLK_DIV_POSI                             (18)
#define DCO_CLK_DIV_MASK                             (0x3)
#define DCO_CLK_DIV_1                                (0)
#define DCO_CLK_DIV_2                                (1)
#define DCO_CLK_DIV_4                                (2)
#define DCO_CLK_DIV_8                                (3)
#endif // (CFG_SOC_NAME == SOC_BK7221U)
#endif // (CFG_SOC_NAME == SOC_BK7231)

#define ICU_PWM_CLK_MUX                              (ICU_BASE + 1 * 4)
#define PWM_CLK_MUX_POSI                             (0)
#define PWM_CLK_MUX_MASK                             (0x3F)
#define PWM_CLK_LPO                                  (1)
#define PWM_CLK_PCLK                                 (0)

#define ICU_PERI_CLK_PWD                             (ICU_BASE + 2 * 4)

#if (CFG_SOC_NAME != SOC_BK7231)
#define PWD_TIMER_32K_CLK                                  (1 << 21)
#define PWD_TIMER_26M_CLK                                  (1 << 20)
#endif

#define PWD_FFT_CLK                                  (1 << 19)
#define PWD_USB_CLK                                  (1 << 18)
#define PWD_SDIO_CLK                                 (1 << 17)
#define PWD_TL410_WATCHDOG                           (1 << 16)
#define PWD_AUDIO_CLK                                (1 << 15)
#define PWD_PWM5_CLK                                 (1 << 14)
#define PWD_PWM4_CLK                                 (1 << 13)
#define PWD_PWM3_CLK                                 (1 << 12)
#define PWD_PWM2_CLK                                 (1 << 11)
#define PWD_PWM1_CLK                                 (1 << 10)
#define PWD_PWM0_CLK                                 (1 <<  9)
#define PWD_ARM_WATCHDOG_CLK                         (1 <<  8)
#define PWD_SARADC_CLK                               (1 <<  7)
#define PWD_SPI_CLK                                  (1 <<  6)
#define PWD_I2C2_CLK                                 (1 <<  5)
#define PWD_I2S_PCM_CLK                              (1 <<  4)
#define PWD_IRDA_CLK                                 (1 <<  3)
#define PWD_I2C1_CLK                                 (1 <<  2)
#define PWD_UART2_CLK                                (1 <<  1)
#define PWD_UART1_CLK                                (1 <<  0)

#define ICU_PERI_CLK_GATING                          (ICU_BASE + 3 * 4)
#define CLKGATE_DISABLE_MAC_AHB                      (1 << 16)
#define CLKGATE_DISABLE_FFT_AHB                      (1 << 15)
#define CLKGATE_DISABLE_USB_AHB                      (1 << 14)
#define CLKGATE_DISABLE_SDIO_AHB                     (1 << 13)
#define CLKGATE_DISABLE_SARADC_APB                   (1 << 12)
#define CLKGATE_DISABLE_AUDIO_APB                    (1 << 11)
#define CLKGATE_DISABLE_PWM_APB                      (1 << 10)
#define CLKGATE_DISABLE_WATCHDOG_APB                 (1 << 9)
#define CLKGATE_DISABLE_GPIO_APB                     (1 << 8)
#define CLKGATE_DISABLE_SPI_APB                      (1 << 7)
#define CLKGATE_DISABLE_I2C2_APB                     (1 << 6)
#define CLKGATE_DISABLE_I2S_PCM_APB                  (1 << 5)
#define CLKGATE_DISABLE_IRDA_APB                     (1 << 4)
#define CLKGATE_DISABLE_I2C1_APB                     (1 << 3)
#define CLKGATE_DISABLE_UART2_APB                    (1 << 2)
#define CLKGATE_DISABLE_UART1_APB                    (1 << 1)
#define CLKGATE_DISABLE_ICU_APB                      (1 << 0)

#define ICU_TL410_CLK_PWD                            (ICU_BASE + 4 * 4)
#define TL410_CLK_PWD_BIT                            (1 << 0)
#define BLE_CLK_PWD_BIT                              (1 << 1)

#define ICU_CLK26M_DIV_FACTOR                        (ICU_BASE + 5 * 4)
#define CLK26M_DIV_FACTOR_POSI                       (0)
#define CLK26M_DIV_FACTOR_MASK                       (0x3)
#define CLK26M_DIVISION_1                            (0x00)
#define CLK26M_DIVISION_2                            (0x01)
#define CLK26M_DIVISION_4                            (0x02)
#define CLK26M_DIVISION_8                            (0x03)

#define ICU_JTAG_SELECT                              (ICU_BASE + 6 * 4)
#define JTAG_SEL_WR_ARM                              (0x7111E968)
#define JTAG_SEL_WR_TL4                              (0x7111E410)
#define JTAG_SEL_RD_ARM                              (0x00000000)
#define JTAG_SEL_RD_TL4                              (0x00000001)

#define ICU_INTERRUPT_ENABLE                         (ICU_BASE + 16 * 4)
#define FIQ_DPLL_UNLOCK_EN_BIT                       (1 << 28) 
#define FIQ_SPI_DMA_EN_BIT                           (1 << 27) 
#define FIQ_MAC_WAKEUP_EN_BIT                        (1 << 26)
#if (CFG_SOC_NAME == SOC_BK7231)
#define FIQ_MAILBOX1_EN_BIT                          (1 << 25) 
#define FIQ_MAILBOX0_EN_BIT                          (1 << 24)
#else
#define FIQ_SECURITY_EN_BIT                          (1 << 25) 
#define FIQ_USB_PLUG_INOUT_EN_BIT                    (1 << 24)  
#endif // (CFG_SOC_NAME == SOC_BK7231)
#define FIQ_SDIO_DMA_EN_BIT                          (1 << 23) 
#define FIQ_MAC_GENERAL_EN_BIT                       (1 << 22) 
#define FIQ_MAC_PROT_TRIGGER_EN_BIT                  (1 << 21) 
#define FIQ_MAC_TX_TRIGGER_EN_BIT                    (1 << 20) 
#define FIQ_MAC_RX_TRIGGER_EN_BIT                    (1 << 19) 
#define FIQ_MAC_TX_RX_MISC_EN_BIT                    (1 << 18) 
#define FIQ_MAC_TX_RX_TIMER_EN_BIT                   (1 << 17) 
#define FIQ_MODEM_EN_BIT                             (1 << 16) 
#define IRQ_GDMA_EN_BIT                              (1 << 15) 
#define IRQ_FFT_EN_BIT                               (1 << 14) 
#define IRQ_USB_EN_BIT                               (1 << 13) 
#define IRQ_SDIO_EN_BIT                              (1 << 12) 
#define IRQ_SARADC_EN_BIT                            (1 << 11) 
#define IRQ_AUDIO_EN_BIT                             (1 << 10) 
#define IRQ_PWM_EN_BIT                               (1 << 9) 
#define IRQ_TL410_WATCHDOG_EN_BIT                    (1 << 8) 
#define IRQ_GPIO_EN_BIT                              (1 << 7) 
#define IRQ_SPI_EN_BIT                               (1 << 6) 
#define IRQ_I2C2_EN_BIT                              (1 << 5) 
#define IRQ_I2S_PCM_EN_BIT                           (1 << 4) 
#define IRQ_IRDA_EN_BIT                              (1 << 3) 
#define IRQ_I2C1_EN_BIT                              (1 << 2) 
#define IRQ_UART2_EN_BIT                             (1 << 1) 
#define IRQ_UART1_EN_BIT                             (1 << 0) 

#define ICU_GLOBAL_INT_EN                            (ICU_BASE + 17 * 4)
#define GINTR_FIQ_EN                                 (1 << 1)
#define GINTR_IRQ_EN                                 (1 << 0)

#define ICU_INT_RAW_STATUS                           (ICU_BASE + 18 * 4)
#define ICU_INT_STATUS                               (ICU_BASE + 19 * 4)
#if (CFG_SOC_NAME == SOC_BK7231)
#define FIQ_MAILBOX1_STATUS_BIT                      (1 << 25)
#define FIQ_MAILBOX0_STATUS_BIT                      (1 << 24)
#else
#define FIQ_SECURITY_STATUS_BIT                      (1 << 25) 
#define FIQ_USB_PLUG_INOUT_STATUS_BIT                (1 << 24) 
#endif // (CFG_SOC_NAME == SOC_BK7231)
#define FIQ_SDIO_DMA_STATUS_BIT                      (1 << 23)
#define FIQ_MAC_GENERAL_STATUS_BIT                   (1 << 22)
#define FIQ_MAC_PROT_TRIGGER_STATUS_BIT              (1 << 21)
#define FIQ_MAC_TX_TRIGGER_STATUS_BIT                (1 << 20)
#define FIQ_MAC_RX_TRIGGER_STATUS_BIT                (1 << 19)
#define FIQ_MAC_TX_RX_MISC_STATUS_BIT                (1 << 18)
#define FIQ_MAC_TX_RX_TIMER_STATUS_BIT               (1 << 17)
#define FIQ_MODEM_STATUS_BIT                         (1 << 16)
#define IRQ_RESERVED_STATUS_BIT                      (1 << 15)
#define IRQ_FFT_STATUS_BIT                           (1 << 14)
#define IRQ_USB_STATUS_BIT                           (1 << 13)
#define IRQ_SDIO_STATUS_BIT                          (1 << 12)
#define IRQ_SARADC_STATUS_BIT                        (1 << 11)
#define IRQ_AUDIO_STATUS_BIT                         (1 << 10)
#define IRQ_PWM_STATUS_BIT                           (1 << 9)
#define IRQ_TL410_WATCHDOG_STATUS_BIT                (1 << 8)
#define IRQ_GPIO_STATUS_BIT                          (1 << 7)
#define IRQ_SPI_STATUS_BIT                           (1 << 6)
#define IRQ_I2C2_STATUS_BIT                          (1 << 5)
#define IRQ_I2S_PCM_STATUS_BIT                       (1 << 4)
#define IRQ_IRDA_STATUS_BIT                          (1 << 3)
#define IRQ_I2C1_STATUS_BIT                          (1 << 2)
#define IRQ_UART2_STATUS_BIT                         (1 << 1)
#define IRQ_UART1_STATUS_BIT                         (1 << 0)

#define ICU_ARM_WAKEUP_EN                            (ICU_BASE + 20 * 4)
#define MAC_ARM_WAKEUP_EN_BIT                       	 (1 << 26) 
#define MAILBOX1_ARM_WAKEUP_EN_BIT                      (1 << 25)
#define MAILBOX0_ARM_WAKEUP_EN_BIT                      (1 << 24)
#define SDIO_DMA_ARM_WAKEUP_EN_BIT                      (1 << 23)
#define MAC_GENERAL_ARM_WAKEUP_EN_BIT                   (1 << 22)
#define MAC_PROT_TRIGGER_ARM_WAKEUP_EN_BIT              (1 << 21)
#define MAC_TX_TRIGGER_ARM_WAKEUP_EN_BIT                (1 << 20)
#define MAC_RX_TRIGGER_ARM_WAKEUP_EN_BIT                (1 << 19)
#define MAC_TX_RX_MISC_ARM_WAKEUP_EN_BIT                (1 << 18)
#define MAC_TX_RX_TIMER_ARM_WAKEUP_EN_BIT               (1 << 17)
#define MODEM_ARM_WAKEUP_EN_BIT                         (1 << 16)
#define RESERVED_ARM_WAKEUP_EN_BIT                      (1 << 15)
#define FFT_ARM_WAKEUP_EN_BIT                           (1 << 14)
#define USB_ARM_WAKEUP_EN_BIT                           (1 << 13)
#define SDIO_ARM_WAKEUP_EN_BIT                          (1 << 12)
#define SARADC_ARM_WAKEUP_EN_BIT                        (1 << 11)
#define AUDIO_ARM_WAKEUP_EN_BIT                         (1 << 10)
#define PWM_ARM_WAKEUP_EN_BIT                           (1 << 9)
#if (CFG_SOC_NAME == SOC_BK7231)
#define TL410_WATCHDOG_ARM_WAKEUP_EN_BIT                (1 << 8)
#else
#define TIMER_ARM_WAKEUP_EN_BIT                         (1 << 8)
#endif
#define GPIO_ARM_WAKEUP_EN_BIT                          (1 << 7)
#define SPI_ARM_WAKEUP_EN_BIT                           (1 << 6)
#define I2C2_ARM_WAKEUP_EN_BIT                          (1 << 5)
#define I2S_PCM_ARM_WAKEUP_EN_BIT                       (1 << 4)
#define IRDA_ARM_WAKEUP_EN_BIT                          (1 << 3)
#define I2C1_ARM_WAKEUP_EN_BIT                          (1 << 2)
#define UART2_ARM_WAKEUP_EN_BIT                         (1 << 1)
#define UART1_ARM_WAKEUP_EN_BIT                         (1 << 0)

#define ICU_TL4_INT_EN                              (ICU_BASE + 32 * 4)
#define TL4_INT_EN_MAILBOX1_BIT                     (1 << 17)
#define TL4_INT_EN_MAILBOX0_BIT                     (1 << 16)
#define TL4_INT_EN_RESERVE1_BIT                     (1 << 15)
#define TL4_INT_EN_FFT_BIT                          (1 << 14)
#define TL4_INT_EN_USB_BIT                          (1 << 13)
#define TL4_INT_EN_SDIO_BIT                         (1 << 12)
#define TL4_INT_EN_SARADC_BIT                       (1 << 11)
#define TL4_INT_EN_AUDIO_BIT                        (1 << 10)
#define TL4_INT_EN_PWM_BIT                          (1 << 9)
#define TL4_INT_EN_RESERVE0_BIT                     (1 << 8)
#define TL4_INT_EN_GPIO_BIT                         (1 << 7)
#define TL4_INT_EN_SPI_BIT                          (1 << 6)
#define TL4_INT_EN_I2C2_BIT                         (1 << 5)
#define TL4_INT_EN_I2S_PCM_BIT                      (1 << 4)
#define TL4_INT_EN_IRDA_BIT                         (1 << 3)
#define TL4_INT_EN_I2C1_BIT                         (1 << 2)
#define TL4_INT_EN_UART2_BIT                        (1 << 1)
#define TL4_INT_EN_UART1_BIT                        (1 << 0)

#define ICU_TL4_INT_RAW_STATUS                      (ICU_BASE + 33 * 4)
#define ICU_TL4_INT_STATUS                          (ICU_BASE + 34 * 4)
#define TL4_MAILBOX1_STATUS_BIT                     (1 << 17)
#define TL4_MAILBOX0_STATUS_BIT                     (1 << 16)
#define TL4_RESERVE1_STATUS_BIT                     (1 << 15)
#define TL4_FFT_STATUS_BIT                          (1 << 14)
#define TL4_USB_STATUS_BIT                          (1 << 13)
#define TL4_SDIO_STATUS_BIT                         (1 << 12)
#define TL4_SARADC_STATUS_BIT                       (1 << 11)
#define TL4_AUDIO_STATUS_BIT                        (1 << 10)
#define TL4_PWM_STATUS_BIT                          (1 << 9)
#define TL4_RESERVE0_STATUS_BIT                     (1 << 8)
#define TL4_GPIO_STATUS_BIT                         (1 << 7)
#define TL4_SPI_STATUS_BIT                          (1 << 6)
#define TL4_I2C2_STATUS_BIT                         (1 << 5)
#define TL4_I2S_PCM_STATUS_BIT                      (1 << 4)
#define TL4_IRDA_STATUS_BIT                         (1 << 3)
#define TL4_I2C1_STATUS_BIT                         (1 << 2)
#define TL4_UART2_STATUS_BIT                        (1 << 1)
#define TL4_UART1_STATUS_BIT                        (1 << 0)

#define ICU_TL4_WAKEUP_EN                           (ICU_BASE + 35 * 4)
#define TL4_MAILBOX1_WAKEUP_EN_BIT                  (1 << 17)
#define TL4_MAILBOX0_WAKEUP_EN_BIT                  (1 << 16)
#define TL4_RESERVE1_WAKEUP_EN_BIT                  (1 << 15)
#define TL4_FFT_WAKEUP_EN_BIT                       (1 << 14)
#define TL4_USB_WAKEUP_EN_BIT                       (1 << 13)
#define TL4_SDIO_WAKEUP_EN_BIT                      (1 << 12)
#define TL4_SARADC_WAKEUP_EN_BIT                    (1 << 11)
#define TL4_AUDIO_WAKEUP_EN_BIT                     (1 << 10)
#define TL4_PWM_WAKEUP_EN_BIT                       (1 << 9)
#define TL4_RESERVE0_WAKEUP_EN_BIT                  (1 << 8)
#define TL4_GPIO_WAKEUP_EN_BIT                      (1 << 7)
#define TL4_SPI_WAKEUP_EN_BIT                       (1 << 6)
#define TL4_I2C2_WAKEUP_EN_BIT                      (1 << 5)
#define TL4_I2S_PCM_WAKEUP_EN_BIT                   (1 << 4)
#define TL4_IRDA_WAKEUP_EN_BIT                      (1 << 3)
#define TL4_I2C1_WAKEUP_EN_BIT                      (1 << 2)
#define TL4_UART2_WAKEUP_EN_BIT                     (1 << 1)
#define TL4_UART1_WAKEUP_EN_BIT                     (1 << 0)


/*******************************************************************************
* Function Declarations
*******************************************************************************/

#endif //_ICU_H_ 
