/*
 * Sw.h
 *
 * Created: 9/12/2021 9:25:14 PM
 *  Author: Abdelaziz Moustafa
 */ 

#ifndef SW_H_
#define SW_H_

#include "Dio.h"
#include "Sw_Cfg.h"

typedef enum
{
	SW_RELEASED,
	SW_PRESSED	
}Sw_StateType;

typedef struct
{
	Dio_PortType Sw_Port;
	Dio_ChannelType Sw_Pin;
	Dio_LevelType Sw_PrevState;
}Sw_Type;

void Sw_Init(uint8 SwNum);
Sw_StateType Sw_StateGet(uint8 SwNum);


extern Sw_Type gaStr_SwConfig[SW_MODULE_NUM];

#endif /* SW_H_ */
