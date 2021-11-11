/********************************************************************************************************
* Title                 :   TM4C123 Dio Module
* Filename              :   Dio.h
* Author                :   AbdelAziz Moustafa
* Origin Date           :   21/07/2020
* Version               :   1.0.0
* Compiler              :   ARM Compiler TI v20.2.1.LTS
* Target                :   TM4C123GH6PM
*
********************************************************************************************************/

/** @file    Dio.h
 *  @author  Abdelaziz Moustafa
 *  @brief   Header file for the TM4C123 Dio Module
 *  @details It contains the prototypes of all function available in the library, definitions of all Macros, and Enumerations
 *
 *  @version 1.0.0
 *  @date 2020-07-21
 *
 *  @copyright Embedded Careers(c) 2020
 *
 */

#ifndef DIO_H
#define DIO_H

/* Standard AUTOSAR types */
#include "Std_Types.h"
/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"
/* Non AUTOSAR files */
#include "Macros.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

/* Description: Enum to hold PIN direction */
typedef enum
{
    DIO_PIN_IN,
    DIO_PIN_OUT
}Dio_PinDirection;

/* Description: Enum to hold Resistor state */
typedef enum
{
    DIO_PULLUP_ENABLED,
    DIO_PULLDOWN_ENABLED,
    DIO_RESISTOR_DISABLED
}Dio_ResistorType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function to Sets the port pin direction */
void Dio_SetPinDirection(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_PinDirection Direction);

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function for DIO read Channel API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function for DIO write Channel API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId);
#endif

void Dio_ResistorStateSet(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_ResistorType ResistorState);


#endif /* DIO_H */
