/*
 * SW_Cfg.c
 *
 * Created: 9/12/2021 10:22:48 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Sw.h"


Sw_Type gaStr_SwConfig[SW_MODULE_NUM] =
{
	{SW1_PORT, SW1_PIN, SW1_INIT_STATE},
	{SW2_PORT, SW2_PIN, SW2_INIT_STATE}
};
