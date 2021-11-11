/********************************************************************************************************
* Title                 :   TM4C123 MCU Module
* Filename              :   Mcu.c
* Author                :   AbdelAziz Moustafa
* Origin Date           :   15/07/2020
* Version               :   1.0.0
* Compiler              :   ARM Compiler TI v20.2.1.LTS
* Target                :   TM4C123GH6PM
*
********************************************************************************************************/

/** @file Mcu.c
 *  @brief Source file for TM4C123 MCU Module
 *
 *  It contains The function definitions of the Clock module
 */

/******************************************************************************
*                            Module's Inclusion files
*******************************************************************************/
#include "Mcu.h"
#include "Tm4c123.h"
#include "Macros.h"

/******************************************************************************
*                             Preprocessor Macros
*******************************************************************************/
#define SYSCTL_RCC_XTAL_MASK       (0x000007C0U)  /* Crystal Value Field */
#define SYSCTL_RCC_CLKDIV_MASK     (0x1FC00000U)  /* System clock divider Field */
#define SYSCTL_RCC2_OSCSRC2_MASK   (0x00000070U)  /* Oscillator Source 2 */

/******************************************************************************
*                            function Definitions
*******************************************************************************/

/******************************************************************************
* Function : Mcu_Init()
*//**
* \b Description:
*
* This function is used to initialize the System Clock based on the configuration
*  defined in Mcu_Cfg.h file.
*
* PRE-CONDITION: F_OSC must be defined in the Configuration file
*                Available F_OSC are 4MHz, 8MHz, 10MHz, 16MHz, 20MHz, 25MHz,
*                40MHz, 50MHz, and 80MHz
*
* POST-CONDITION: None
*
* @param        void
*
* @return       void
*
* \b Example:
* @code
*
*   #define F_OSC (16000000UL)
*   Mcu_Init();
*
*  ----------------------
*  - HISTORY OF CHANGES -
*  ----------------------
*    Date    Software Version    Initials   Description
*  18/07/20       0.1.1            AZM      Function Created.
*
*******************************************************************************/
void Mcu_Init(void)
{
    /* 0) configure the system to use RCC2 for advanced features
          such as 400 MHz PLL and non-integer System Clock Divisor */
    SYSCTL_RCC2_R |= RCC2_REG_USED;

    /* 1) bypass PLL while initializing */
    SYSCTL_RCC2_R |= BYPASS_PLL;

    /* 2) select the crystal value  */
    SYSCTL_RCC_R &= ~SYSCTL_RCC_XTAL_MASK;
    SYSCTL_RCC_R |= XTAL_VAL_16MHZ;

    /* 3) select the crystal oscillator source */
    SYSCTL_RCC2_R &= ~SYSCTL_RCC2_OSCSRC2_MASK;
    SYSCTL_RCC2_R |= OSCILLATOR_SOURCE_MOSC;

    /* 4) activate PLL by clearing PWRDN */
    SYSCTL_RCC2_R &= ~PLL_POWER_DOWN;

    /* 5) use 400 MHz PLL */
    SYSCTL_RCC2_R |= DIVIDE_PLL_400MHZ;

    /* 6) set the system divider and the system divider least significant bit based on desired Frequency */
#if F_OSC == 4000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= FREQ_4MHZ_SYSDIV2;
#elif F_OSC == 8000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= FREQ_8MHZ_SYSDIV2;
#elif F_OSC == 10000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= FREQ_10MHZ_SYSDIV2;
#elif F_OSC == 16000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= (uint32_t)FREQ_16MHZ_SYSDIV2;
#elif F_OSC == 20000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= FREQ_20MHZ_SYSDIV2;
#elif F_OSC == 25000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= FREQ_25MHZ_SYSDIV2;
#elif F_OSC == 40000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= FREQ_40MHZ_SYSDIV2;
#elif F_OSC == 50000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= FREQ_50MHZ_SYSDIV2;
#elif F_OSC == 80000000UL
    SYSCTL_RCC2_R &= ~SYSCTL_RCC_CLKDIV_MASK;
    SYSCTL_RCC2_R |= FREQ_80MHZ_SYSDIV2;
#endif

    /* 7) wait for the PLL to lock by polling PLLLRIS */
    while((SYSCTL_RIS_R & PLLLRIS_BIT)==0){};

    /* 8) enable use of PLL by clearing BYPASS */
    SYSCTL_RCC2_R &= ~BYPASS_PLL;
}

/******************************************************************************
* Function : Mcu_PeripheralClkInit()
*//**
* \b Description:
*
* This function is used to initialize the Peripherals Clock based on the configuration
*  defined in Mcu_Cfg.h file.
*
* PRE-CONDITION: any Peripherals used by the application must be defined in the Configuration file
*
* POST-CONDITION: None
*
* @param        void
*
* @return       void
*
* \b Example:
* @code
*
*   #define MCU_USE_GPIO_PORTA  (1U)
*   #define MCU_USE_GPTM_TIMER0 (1U)
*
*   Mcu_PeripheralClkInit();
*
*  ----------------------
*  - HISTORY OF CHANGES -
*  ----------------------
*    Date    Software Version    Initials   Description
*  18/07/20       0.1.1            AZM      Function Created.
*
*******************************************************************************/
void Mcu_PeripheralClkInit(void)
{
    /* WatchDog Timer Peripherals Clock */
#if MCU_USE_WDT0
    SET_BIT(SYSCTL_RCGCWD_R, 0U);
    SET_BIT(SYSCTL_RCGC0_R, 3U);
#endif
#if MCU_USE_WDT1
    SET_BIT(SYSCTL_RCGCWD_R, 1U);
    SET_BIT(SYSCTL_RCGC0_R, 28U);
#endif

    /* GPIO Ports Peripherals Clock */
#if MCU_USE_GPIO_PORTA
    SET_BIT(SYSCTL_RCGCGPIO_R, 0U);
#endif
#if MCU_USE_GPIO_PORTB
    SET_BIT(SYSCTL_RCGCGPIO_R, 1U);
#endif
#if MCU_USE_GPIO_PORTC
    SET_BIT(SYSCTL_RCGCGPIO_R, 2U);
#endif
#if MCU_USE_GPIO_PORTD
    SET_BIT(SYSCTL_RCGCGPIO_R, 3U);
#endif
#if MCU_USE_GPIO_PORTE
    SET_BIT(SYSCTL_RCGCGPIO_R, 4U);
#endif
#if MCU_USE_GPIO_PORTF
    SET_BIT(SYSCTL_RCGCGPIO_R, 5U);
#endif

    /* UART Peripherals Clock */
#if MCU_USE_UART0
    SET_BIT(SYSCTL_RCGCUART_R, 0U);
#endif
#if MCU_USE_UART1
    SET_BIT(SYSCTL_RCGCUART_R, 1U);
#endif
#if MCU_USE_UART2
    SET_BIT(SYSCTL_RCGCUART_R, 2U);
#endif
#if MCU_USE_UART3
    SET_BIT(SYSCTL_RCGCUART_R, 3U);
#endif
#if MCU_USE_UART4
    SET_BIT(SYSCTL_RCGCUART_R, 4U);
#endif
#if MCU_USE_UART5
    SET_BIT(SYSCTL_RCGCUART_R, 5U);
#endif
#if MCU_USE_UART6
    SET_BIT(SYSCTL_RCGCUART_R, 6U);
#endif
#if MCU_USE_UART7
    SET_BIT(SYSCTL_RCGCUART_R, 7U);
#endif

    /* SSI (SPI) Peripherals Clock */
#if MCU_USE_SSI0
    SET_BIT(SYSCTL_RCGCSSI_R, 0U);
#endif
#if MCU_USE_SSI1
    SET_BIT(SYSCTL_RCGCSSI_R, 1U);
#endif
#if MCU_USE_SSI2
    SET_BIT(SYSCTL_RCGCSSI_R, 2U);
#endif
#if MCU_USE_SSI3
    SET_BIT(SYSCTL_RCGCSSI_R, 3U);
#endif

    /* I2C Peripherals Clock */
#if MCU_USE_I2C0
    SET_BIT(SYSCTL_RCGCI2C_R, 0U);
#endif
#if MCU_USE_I2C1
    SET_BIT(SYSCTL_RCGCI2C_R, 1U);
#endif
#if MCU_USE_I2C2
    SET_BIT(SYSCTL_RCGCI2C_R, 2U);
#endif
#if MCU_USE_I2C3
    SET_BIT(SYSCTL_RCGCI2C_R, 3U);
#endif

    /* ADC Peripherals Clock */
#if MCU_USE_ADC0
    SET_BIT(SYSCTL_RCGCADC_R, 0U);
    SET_BIT(SYSCTL_RCGC0_R, 16U);
#endif
#if MCU_USE_ADC1
    SET_BIT(SYSCTL_RCGCADC_R, 1U);
    SET_BIT(SYSCTL_RCGC0_R, 17U);
#endif

    /* GPTM Timer Peripherals Clock */
#if MCU_USE_GPTM_TIMER0
    SET_BIT(SYSCTL_RCGCTIMER_R, 0U);
#endif
#if MCU_USE_GPTM_TIMER1
    SET_BIT(SYSCTL_RCGCTIMER_R, 1U);
#endif
#if MCU_USE_GPTM_TIMER2
    SET_BIT(SYSCTL_RCGCTIMER_R, 2U);
#endif
#if MCU_USE_GPTM_TIMER3
    SET_BIT(SYSCTL_RCGCTIMER_R, 3U);
#endif
#if MCU_USE_GPTM_TIMER4
    SET_BIT(SYSCTL_RCGCTIMER_R, 4U);
#endif
#if MCU_USE_GPTM_TIMER5
    SET_BIT(SYSCTL_RCGCTIMER_R, 5U);
#endif

    /* PWM Peripherals Clock */
#if MCU_USE_PWM0
    SET_BIT(SYSCTL_RCGCPWM_R, 0U);
    SET_BIT(SYSCTL_RCGC0_R, 20U);
#endif
#if MCU_USE_PWM1
    SET_BIT(SYSCTL_RCGCPWM_R, 1U);
#endif

    /* GPTM Wide Timer Peripherals Clock */
#if MCU_USE_GPTM_WTIMER0
    SET_BIT(SYSCTL_RCGCWTIMER_R, 0U);
#endif
#if MCU_USE_GPTM_WTIMER1
    SET_BIT(SYSCTL_RCGCWTIMER_R, 1U);
#endif
#if MCU_USE_GPTM_WTIMER2
    SET_BIT(SYSCTL_RCGCWTIMER_R, 2U);
#endif
#if MCU_USE_GPTM_WTIMER3
    SET_BIT(SYSCTL_RCGCWTIMER_R, 3U);
#endif
#if MCU_USE_GPTM_WTIMER4
    SET_BIT(SYSCTL_RCGCWTIMER_R, 4U);
#endif
#if MCU_USE_GPTM_WTIMER5
    SET_BIT(SYSCTL_RCGCWTIMER_R, 5U);
#endif
}
