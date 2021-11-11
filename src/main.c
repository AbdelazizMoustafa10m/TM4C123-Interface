

/**
 * main.c
 */

#include "Led.h"
#include "Sw.h"
#include "Mcu.h"

int main(void)
{
    Mcu_Init();
    Mcu_PeripheralClkInit();
    Led_Init(RED_LED);
    Led_Init(BLUE_LED);
    Sw_Init(SW1);
    Sw_Init(SW2);
    while(1)
    {
        if(Sw_StateGet(SW1) == SW_PRESSED)
        {
            Led_StateSet(RED_LED, LED_ON);
            Led_StateSet(BLUE_LED, LED_ON);
        }
        else if (Sw_StateGet(SW2) == SW_PRESSED)
        {
            Led_StateSet(RED_LED, LED_OFF);
        }
    }
}
