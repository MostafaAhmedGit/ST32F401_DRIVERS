
/*************************************************************
 *
 * Filename: APP_TWO.c
 * Description: Source (Interface) file of the Task
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/

#include "Stdtypes.h"
#include "GPIO.h"
#include "APP_TWO.h"

void LED_BLINK2(void)
{
	static u8 local;

	local^=1;

	if(local==0)
	GPIO_enuSetPinValue(GPIO_PORT_C,GPIO_PIN_13,GPIO_SET);
	else
	GPIO_enuSetPinValue(GPIO_PORT_C,GPIO_PIN_13,GPIO_RESET);

}
