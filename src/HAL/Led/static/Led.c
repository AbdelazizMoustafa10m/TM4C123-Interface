/*
 * Led.c
 *
 * Created: 9/12/2021 10:35:46 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Led.h"
#include "Dio.h"

Led_Type *Led = gaStr_LedConfig;

void Led_Init(uint8 LedNum)
{
	Dio_SetPinDirection(Led[LedNum].Led_Port, Led[LedNum].Led_Pin, DIO_PIN_OUT);
	Dio_WriteChannel(Led[LedNum].Led_Port, Led[LedNum].Led_Pin, STD_LOW);
}
void Led_StateSet(uint8 LedNum, Led_StateType state)
{
	if (state == LED_TOGGLE)
	{
		Dio_FlipChannel(Led[LedNum].Led_Port, Led[LedNum].Led_Pin);
	}
	else
	{
	    Dio_WriteChannel(Led[LedNum].Led_Port, Led[LedNum].Led_Pin, state);
	}
} 
