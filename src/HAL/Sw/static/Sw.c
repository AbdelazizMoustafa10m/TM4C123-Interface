/*
 * Sw.c
 *
 * Created: 9/12/2021 9:25:26 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Dio.h"
#include "Sw.h"


Sw_Type *Sw = gaStr_SwConfig;

void Sw_Init(uint8 SwNum)
{
	Dio_SetPinDirection(Sw[SwNum].Sw_Port, Sw[SwNum].Sw_Pin, DIO_PIN_IN);
    Dio_ResistorStateSet(Sw[SwNum].Sw_Port,Sw[SwNum].Sw_Pin, DIO_PULLUP_ENABLED);
	Sw->Sw_PrevState = Dio_ReadChannel(Sw[SwNum].Sw_Port, Sw[SwNum].Sw_Pin);
}
Sw_StateType Sw_StateGet(uint8 SwNum)
{
	Sw_StateType LocalSwState = SW_RELEASED;
    Sw->Sw_PrevState = Dio_ReadChannel(Sw[SwNum].Sw_Port, Sw[SwNum].Sw_Pin);
    if (Sw->Sw_PrevState == STD_LOW)
    {
        LocalSwState = SW_PRESSED;
    }
    else
    {
        LocalSwState = SW_RELEASED;
    }
	return LocalSwState;
}
