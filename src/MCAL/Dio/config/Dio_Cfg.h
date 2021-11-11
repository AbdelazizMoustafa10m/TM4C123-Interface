/********************************************************************************************************
* Title                 :   TM4C123 Dio Module
* Filename              :   Dio_Cfg.h
* Author                :   AbdelAziz Moustafa
* Origin Date           :   21/07/2020
* Version               :   1.0.0
* Compiler              :   ARM Compiler TI v20.2.1.LTS
* Target                :   TM4C123GH6PM
*
********************************************************************************************************/

/** @file    Dio.h
 *  @author  Abdelaziz Moustafa
 *  @brief   Pre-Compile Configuration Header file for Dio Module.
 *  @details It contains the prototypes of all function available in the library, definitions of all Macros, and Enumerations
 *
 *  @version 1.0.0
 *  @date 2020-07-21
 *
 *  @copyright Embedded Careers(c) 2020
 *
 */


#ifndef DIO_CFG_H
#define DIO_CFG_H

#include "Std_Types.h"

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API (STD_ON)

#define DIO_CHANNEL0         (0U)
#define DIO_CHANNEL1         (1U)
#define DIO_CHANNEL2         (2U)
#define DIO_CHANNEL3         (3U)
#define DIO_CHANNEL4         (4U)
#define DIO_CHANNEL5         (5U)
#define DIO_CHANNEL6         (6U)
#define DIO_CHANNEL7         (7U)

#define DIO_PORTA            (0U)
#define DIO_PORTB            (1U)
#define DIO_PORTC            (2U)
#define DIO_PORTD            (3U)
#define DIO_PORTE            (4U)
#define DIO_PORTF            (5U)

#endif /* DIO_CFG_H */
