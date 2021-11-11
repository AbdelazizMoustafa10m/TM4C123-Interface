/**
 * @file Led_Cfg.h
 * @author  Abdelaziz Moustafa
 * @brief   Pre-Compile Configuration for the Led Module
 * @details It contains the header files for and function prototypes for the application.
 *
 * @version 1.0.0
 * @date 2020-09-23
 * 
 * @copyright Embedded Careers(c) 2020
 * 
 */

#ifndef LED_CFG_H_
#define LED_CFG_H_

/******************************************************************************
* Module's Inclusion files
*******************************************************************************/
#include "Dio.h"

/******************************************************************************
* Module's Preprocessor Macros
*******************************************************************************/

#define LED_MODULE_NUM          (3U)

#define RED_LED                 (0U)
#define BLUE_LED                (1U)
#define GREEN_LED               (2U)

#define RED_LED_PORT            (DIO_PORTF)
#define RED_LED_PIN             (DIO_CHANNEL1)
#define RED_LED_INIT_STATE      (STD_LOW)

#define BLUE_LED_PORT           (DIO_PORTF)
#define BLUE_LED_PIN            (DIO_CHANNEL2)
#define BLUE_LED_INIT_STATE     (STD_LOW)

#define GREEN_LED_PORT          (DIO_PORTF)
#define GREEN_LED_PIN           (DIO_CHANNEL3)
#define GREEN_LED_INIT_STATE    (STD_LOW)


#endif /* LED_CFG_H_ */
