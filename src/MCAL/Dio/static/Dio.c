/********************************************************************************************************
* Title                 :   DIO Module
* Filename              :   Dio.c
* Author                :   AbdelAziz Moustafa
* Origin Date           :   21/07/2020
* Version               :   1.0.0
* Compiler              :   ARM Compiler TI v20.2.1.LTS
* Target                :   TM4C123GH6PM
*
********************************************************************************************************/
/**
 * @file Dio.c
 * @author Abdelaziz Moustafa
 * @brief Source file for TM4C123 Dio Module
 * @details It contains The function definitions of the TM4C123 Dio module
 * 
 * @version 1.0.0
 * @date 2020-07-21
 * 
 * @copyright Embedded Careers(c) 2020
 * 
 */

/******************************************************************************
* Module's Inclusion files
*******************************************************************************/
#include "Dio.h"
#include "Macros.h"
#include "Tm4c123.h"

/******************************************************************************
* Preprocessor Macros
*******************************************************************************/
/**
 * @brief This MACRO defines the code to unlock a certain GPIO
 */
#define DIO_UNLOCK_CODE (0x4C4F434BU)  

/******************************************************************************
* Function Definitions
*******************************************************************************/

/******************************************************************************************
* Service Name: Dio_SetPinDirection
* Sync/Async: Synchronous
* Service ID[hex]:0x01
* Reentrancy: reentrant
* Parameters (in): PortId > Port ID number
*                : ChannelId > Pin ID number
*                : Direction >  Pin Direction
* Parameters (inout): NOne
* Parameters (out): None
* Return value: None
* Description: Sets the pin direction       
******************************************************************************************/                     
void Dio_SetPinDirection(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_PinDirection Direction)
{ 
	volatile P2VAR(uint32_t, AUTOMATIC, PTR_FAR) pu8LocalPortDirReg = NULL_PTR;
    volatile P2VAR(uint32_t, AUTOMATIC, PTR_FAR) pu8LocalPortDenReg = NULL_PTR;

    /* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
    switch(PortId)
    {
    case DIO_PORTA:    
        pu8LocalPortDirReg = &GPIO_PORTA_DIR_R;
        pu8LocalPortDenReg = &GPIO_PORTA_DEN_R;
        break;
    case DIO_PORTB:    
        pu8LocalPortDirReg = &GPIO_PORTB_DIR_R;
        pu8LocalPortDenReg = &GPIO_PORTB_DEN_R;
        break;
    case DIO_PORTC:    
        pu8LocalPortDirReg = &GPIO_PORTC_DIR_R;
        pu8LocalPortDenReg = &GPIO_PORTC_DEN_R;
        break;
    case DIO_PORTD:    
        pu8LocalPortDirReg = &GPIO_PORTD_DIR_R;
        pu8LocalPortDenReg = &GPIO_PORTD_DEN_R; 
        break;
    case DIO_PORTE:    
        pu8LocalPortDirReg = &GPIO_PORTE_DIR_R;
        pu8LocalPortDenReg = &GPIO_PORTE_DEN_R;
        break;
    case DIO_PORTF:    
        pu8LocalPortDirReg = &GPIO_PORTF_DIR_R;
        pu8LocalPortDenReg = &GPIO_PORTF_DEN_R;
        /* Unlock PORTF by writing to GPIOLOCK register and then commit changes by writing to GPIOCR register */
        GPIO_PORTF_LOCK_R = DIO_UNLOCK_CODE;
        GPIO_PORTF_CR_R = 0xFF; /* Commit changes */
        break;
    default:
        break;
    }

    SET_BIT(*pu8LocalPortDenReg , ChannelId); /* Enable Digital Function */
	if(Direction == DIO_PIN_IN)
    {
        CLEAR_BIT(*pu8LocalPortDirReg , ChannelId);
    }
	else if(Direction == DIO_PIN_OUT)
    {
	    SET_BIT(*pu8LocalPortDirReg , ChannelId); 
    }    
}
/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_LevelType Level)     
{
	volatile P2VAR(uint32_t, AUTOMATIC, PTR_FAR) pu8LocalPortReg = NULL_PTR;

    /* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
    switch(PortId)
    {
    case DIO_PORTA:    
        pu8LocalPortReg = &GPIO_PORTA_DATA_R;
        break;
    case DIO_PORTB:    
        pu8LocalPortReg = &GPIO_PORTB_DATA_R;
        break;
    case DIO_PORTC:    
        pu8LocalPortReg = &GPIO_PORTC_DATA_R;
        break;
    case DIO_PORTD:    
        pu8LocalPortReg = &GPIO_PORTD_DATA_R;
        break;
    case DIO_PORTE:    
        pu8LocalPortReg = &GPIO_PORTE_DATA_R;
        break;
    case DIO_PORTF:    
        pu8LocalPortReg = &GPIO_PORTF_DATA_R;
        break;
    default:
        break;
    }
    if(Level == STD_HIGH)
    {
        /* Write Logic High */
        SET_BIT(*pu8LocalPortReg, ChannelId);
    }
    else if(Level == STD_LOW)
    {
        /* Write Logic Low */
        CLEAR_BIT(*pu8LocalPortReg, ChannelId);
    }
}

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
	volatile P2VAR(uint32_t, AUTOMATIC, PTR_FAR) pu8LocalPortReg = NULL_PTR;
	VAR(Dio_LevelType, AUTOMATIC) u8LocalRetvalue = STD_LOW;
	
	/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
    switch(PortId)
    {
    case DIO_PORTA:    
        pu8LocalPortReg = &GPIO_PORTA_DATA_R;
        break;
    case DIO_PORTB:    
        pu8LocalPortReg = &GPIO_PORTB_DATA_R;
        break;
    case DIO_PORTC:    
        pu8LocalPortReg = &GPIO_PORTC_DATA_R;
        break;
    case DIO_PORTD:    
        pu8LocalPortReg = &GPIO_PORTD_DATA_R;
        break;
    case DIO_PORTE:    
        pu8LocalPortReg = &GPIO_PORTE_DATA_R;
        break;
    case DIO_PORTF:    
        pu8LocalPortReg = &GPIO_PORTF_DATA_R;
        break;
    default:
        break;
    }
    /* Read the required channel */
    if(READ_BIT(*pu8LocalPortReg, ChannelId))
    {
        u8LocalRetvalue = STD_HIGH;
    }
    else
    {
        u8LocalRetvalue = STD_LOW;
    }
        return u8LocalRetvalue;
}

/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/
#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId)
{
	volatile P2VAR(uint32_t, AUTOMATIC, PTR_FAR) pu8LocalPortReg = NULL_PTR;
	VAR(Dio_LevelType, AUTOMATIC) u8LocalRetvalue = STD_LOW;

    switch(PortId)
    {
    case DIO_PORTA:    
        pu8LocalPortReg = &GPIO_PORTA_DATA_R;
        break;
    case DIO_PORTB:    
        pu8LocalPortReg = &GPIO_PORTB_DATA_R;
        break;
    case DIO_PORTC:    
        pu8LocalPortReg = &GPIO_PORTC_DATA_R;
        break;
    case DIO_PORTD:    
        pu8LocalPortReg = &GPIO_PORTD_DATA_R;
        break;
    case DIO_PORTE:    
        pu8LocalPortReg = &GPIO_PORTE_DATA_R;
        break;
    case DIO_PORTF:    
        pu8LocalPortReg = &GPIO_PORTF_DATA_R;
        break;
    default:
        break;
    }
    /* Read the required channel and write the required level */
    if(READ_BIT(*pu8LocalPortReg, ChannelId))
    {
        CLEAR_BIT(*pu8LocalPortReg, ChannelId);
        u8LocalRetvalue = STD_LOW;
    }
    else
    {
        SET_BIT(*pu8LocalPortReg, ChannelId);
        u8LocalRetvalue = STD_HIGH;
    }

        return u8LocalRetvalue;
}
#endif

void Dio_ResistorStateSet(Dio_PortType PortId, Dio_ChannelType ChannelId, Dio_ResistorType ResistorState)
{
	volatile P2VAR(uint32_t, AUTOMATIC, PTR_FAR) pu8LocalPullUpReg = NULL_PTR;
    volatile P2VAR(uint32_t, AUTOMATIC, PTR_FAR) pu8LocalPullDownReg = NULL_PTR;

    /* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
    switch(PortId)
    {
    case DIO_PORTA:    
        pu8LocalPullUpReg = &GPIO_PORTA_PUR_R;
        pu8LocalPullDownReg = &GPIO_PORTA_PDR_R;
        break;
    case DIO_PORTB:    
        pu8LocalPullUpReg = &GPIO_PORTB_PUR_R;
        pu8LocalPullDownReg = &GPIO_PORTB_PDR_R;
        break;
    case DIO_PORTC:    
        pu8LocalPullUpReg = &GPIO_PORTC_PUR_R;
        pu8LocalPullDownReg = &GPIO_PORTC_PDR_R;
        break;
    case DIO_PORTD:    
        pu8LocalPullUpReg = &GPIO_PORTD_PUR_R;
        pu8LocalPullDownReg = &GPIO_PORTD_PDR_R; 
        break;
    case DIO_PORTE:    
        pu8LocalPullUpReg = &GPIO_PORTE_PUR_R;
        pu8LocalPullDownReg = &GPIO_PORTE_PDR_R;
        break;
    case DIO_PORTF:    
        pu8LocalPullUpReg = &GPIO_PORTF_PUR_R;
        pu8LocalPullDownReg = &GPIO_PORTF_PDR_R;
        break;
    default:
        break;
    }

    switch (ResistorState)
    {
    case DIO_PULLUP_ENABLED:
        SET_BIT(*pu8LocalPullUpReg , ChannelId); 
        break;
    case DIO_PULLDOWN_ENABLED:
         SET_BIT(*pu8LocalPullDownReg , ChannelId); 
        break;
    case DIO_RESISTOR_DISABLED:
        CLEAR_BIT(*pu8LocalPullUpReg , ChannelId);
        CLEAR_BIT(*pu8LocalPullDownReg , ChannelId);
        break;
    default:
        /* Do Nothing */
        break;
    }
}
