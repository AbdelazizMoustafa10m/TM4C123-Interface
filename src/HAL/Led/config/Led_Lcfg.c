/*
 * Led_Lcfg.c
 *
 * Created: 9/12/2021 10:35:59 PM
 *  Author: Abdelaziz Moustafa
 */ 

#include "Led.h"


Led_Type gaStr_LedConfig[LED_MODULE_NUM] =
{
	{RED_LED_PORT, RED_LED_PIN},
	{BLUE_LED_PORT, BLUE_LED_PIN},
	{GREEN_LED_PORT, GREEN_LED_PIN}
}; 
