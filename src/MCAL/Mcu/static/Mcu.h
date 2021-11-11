/********************************************************************************************************
* Title                 :   TM4C123 MCU Module
* Filename              :   Mcu.h
* Author                :   AbdelAziz Moustafa
* Origin Date           :   15/07/2020
* Version               :   1.0.0
* Compiler              :   ARM Compiler TI v20.2.1.LTS
* Target                :   TM4C123GH6PM
*
********************************************************************************************************/

/** @file    Mcu.h
 *  @author  Abdelaziz Moustafa
 *  @brief   Header file for the TM4C123 MCU Module
 *  @details It contains the prototypes of all function available in the library, definitions of all Macros, and Enumerations
 *
 *  @version 1.0.0
 *  @date 2020-07-15
 *
 *  @copyright Embedded Careers(c) 2020
 *
 */

#ifndef MCU_H
#define MCU_H


/******************************************************************************
*                            Module's Inclusion files
*******************************************************************************/
#include "Mcu_Cfg.h"

/******************************************************************************
*                             Preprocessor Macros
*******************************************************************************/

#define XTAL_VAL_16MHZ  (0x00000540UL) /*  External 16 MHz Crystal Connected to TivaC123 */
#define PLLLRIS_BIT     (0x00000040U)


/******************************************************************************
*                            User-defined Data Types
*******************************************************************************/

/**
 *  Defines the setting needed to Initialize PLL.
 */
typedef enum
{
    RCC2_REG_USED     = 0x80000000U,
    DIVIDE_PLL_400MHZ = 0x40000000U,
    PLL_POWER_DOWN    = 0x00002000U,
    BYPASS_PLL        = 0x00000800U,
}PLL_Settings;

/**
 *  Defines the clock sources for the system.
 */
typedef enum
{
    OSCILLATOR_SOURCE_MOSC       = 0x00000000U,
    OSCILLATOR_SOURCE_PIOSC      = 0x00000010U,
    OSCILLATOR_SOURCE_PIOSC_DIV4 = 0x00000020U,
    OSCILLATOR_SOURCE_LFIOSC     = 0x00000030U,
    OSCILLATOR_SOURCE_32_768kHz  = 0x00000070U,
}Oscillator_Source;


/************************************************************************
* Bus frequency is 400MHz/(SYSDIV2+1)
************************************************************************/
/**
 *  Defines the system clock dividers
 */
typedef enum
{
    FREQ_4MHZ_SYSDIV2  = 0x18C00000U,
    FREQ_8MHZ_SYSDIV2  = 0x0C400000U,
    FREQ_10MHZ_SYSDIV2 = 0x09C00000U,
    FREQ_16MHZ_SYSDIV2 = 0x06000000U,
    FREQ_20MHZ_SYSDIV2 = 0x04C00000U,
    FREQ_25MHZ_SYSDIV2 = 0x03C00000U,
    FREQ_40MHZ_SYSDIV2 = 0x02400000U,
    FREQ_50MHZ_SYSDIV2 = 0x01C00000U,
    FREQ_80MHZ_SYSDIV2 = 0x01000000U,
}Freq_SYSDIV2;
/******************************************************************************
*                           Public function prototypes
*******************************************************************************/
/* Function used to initialize the system clock */
void Mcu_Init(void);
/* Function Used to initialize the used peripherals' clock */
void Mcu_PeripheralClkInit(void);


#endif /* MCU_H */
