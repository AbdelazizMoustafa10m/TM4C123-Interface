/********************************************************************************************************
* Title                 :   Configuration
* Filename              :   Mcu_Cfg.h
* Author                :   AbdelAziz Moustafa
* Origin Date           :   18/07/2020
* Version               :   1.0.0
* Compiler              :   ARM Compiler TI v20.2.1.LTS
* Target                :   TM4C123GH6PM
*
********************************************************************************************************/

/** @file Mcu_Cfg.h
 *  @brief Pre-Compile Configuration file for MCU module
 *
 *  It contains The Prototypes of all function available in
 *  the library,definitions of all Macros, and Enumerations
 */

#ifndef MCU_CFG_H_
#define MCU_CFG_H_

/******************************************************************************
*                            Module's Inclusion files
*******************************************************************************/

/******************************************************************************
*                             Preprocessor Macros
*******************************************************************************/

/******************************************** System Clock Configuration **********************************************/

/******************************************************************************
* User can choice from the next frequency values:
* 4MHz, 8MHz, 10MHz, 16MHz, 20MHz, 25MHz, 40MHz, 50MHz, and 80MHz
*******************************************************************************/
#ifndef F_OSC
#define F_OSC (16000000UL)
#endif

/******************************************** Peripherals Clock Configuration *****************************************/
#define MCU_USE_WDT0            (0U)
#define MCU_USE_WDT1            (0U)

#define MCU_USE_GPIO_PORTA      (1U)
#define MCU_USE_GPIO_PORTB      (0U)
#define MCU_USE_GPIO_PORTC      (0U)
#define MCU_USE_GPIO_PORTD      (0U)
#define MCU_USE_GPIO_PORTF      (1U)
#define MCU_USE_GPIO_PORTE      (0U)

#define MCU_USE_UART0           (0U)
#define MCU_USE_UART1           (0U)
#define MCU_USE_UART2           (0U)
#define MCU_USE_UART3           (0U)
#define MCU_USE_UART4           (0U)
#define MCU_USE_UART5           (0U)
#define MCU_USE_UART6           (0U)
#define MCU_USE_UART7           (0U)

#define MCU_USE_SSI0            (0U)
#define MCU_USE_SSI1            (0U)
#define MCU_USE_SSI2            (0U)
#define MCU_USE_SSI3            (0U)

#define MCU_USE_I2C0            (0U)
#define MCU_USE_I2C1            (0U)
#define MCU_USE_I2C2            (0U)
#define MCU_USE_I2C3            (0U)

#define MCU_USE_ADC0            (0U)
#define MCU_USE_ADC1            (0U)

#define MCU_USE_GPTM_TIMER0     (0U)
#define MCU_USE_GPTM_TIMER1     (0U)
#define MCU_USE_GPTM_TIMER2     (0U)
#define MCU_USE_GPTM_TIMER3     (0U)
#define MCU_USE_GPTM_TIMER4     (0U)
#define MCU_USE_GPTM_TIMER5     (0U)

#define MCU_USE_GPTM_WTIMER0    (0U)
#define MCU_USE_GPTM_WTIMER1    (0U)
#define MCU_USE_GPTM_WTIMER2    (0U)
#define MCU_USE_GPTM_WTIMER3    (0U)
#define MCU_USE_GPTM_WTIMER4    (0U)
#define MCU_USE_GPTM_WTIMER5    (0U)

#define MCU_USE_PWM0            (0U)
#define MCU_USE_PWM1            (0U)

#endif /* MCU_CFG_H_ */
