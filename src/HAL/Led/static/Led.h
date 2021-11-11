/*
 * Led.h
 *
 * Created: 9/12/2021 10:36:11 PM
 *  Author: Abdelaziz Moustafa
 */ 


#ifndef LED_H_
#define LED_H_

#include "Dio.h"
#include "Led_Cfg.h"

typedef enum
{
	LED_OFF,
	LED_ON,
	LED_TOGGLE,
}Led_StateType;

typedef struct
{
	Dio_PortType Led_Port;
	Dio_ChannelType  Led_Pin;

}Led_Type;

void Led_Init(uint8 LedNum);
void Led_StateSet(uint8 LedNum, Led_StateType state);

extern Led_Type gaStr_LedConfig[LED_MODULE_NUM];

#endif
