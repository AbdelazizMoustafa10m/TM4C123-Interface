/**
 * @file Sw_Cfg.h
 * @author  Abdelaziz Moustafa
 * @brief   Pre-Compile Configuration for the Sw Module
 * @details It contains the header files for and function prototypes for the application.
 *
 * @version 1.0.0
 * @date 2020-09-23
 * 
 * @copyright Embedded Careers(c) 2020
 * 
 */

#ifndef SW_CFG_H_
#define SW_CFG_H_

/******************************************************************************
* Module's Inclusion files
*******************************************************************************/
#include "Dio.h"

/******************************************************************************
* Module's Preprocessor Macros
*******************************************************************************/

#define SW_MODULE_NUM          (2U)

#define SW1                    (0U)
#define SW2                    (1U)

#define SW1_PORT                (DIO_PORTF)
#define SW1_PIN                 (DIO_CHANNEL4)
#define SW1_INIT_STATE          (STD_HIGH)              

#define SW2_PORT                (DIO_PORTF)
#define SW2_PIN                 (DIO_CHANNEL0)
#define SW2_INIT_STATE          (STD_HIGH)


#endif /* SW_CFG_H_ */
