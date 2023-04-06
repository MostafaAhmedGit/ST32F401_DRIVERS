/*************************************************************
 *
 * Filename: LED.c
 * Description: Source (interface) file of the LED driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/
#include "LED.h"
#include "src/GPIO.h"







LED_errorStatus LED_Init(LED_Configuration_t *Ptr_Cfg)
{


	/*You should set the direction separately */

	LED_errorStatus Local_Status = LED_OK;


	if((Ptr_Cfg->InitalState==LED_SET)&&(Ptr_Cfg->Mode==LED_ACTIVE_HIGH))
		GPIO_enuSetPinValue((void*)Ptr_Cfg->Port,Ptr_Cfg->Pin,GPIO_PIN_HIGH);

	else if((Ptr_Cfg->InitalState==LED_SET)&&(Ptr_Cfg->Mode==LED_ACTIVE_LOW))
		GPIO_enuSetPinValue((void*)Ptr_Cfg->Port,Ptr_Cfg->Pin,GPIO_PIN_LOW);


	return Local_Status;

}
LED_errorStatus LED_Set(LED_NAMES LED_NAME,LED_State_t LED_STATE)
{
	LED_errorStatus Local_Status=LED_OK;
	u8 Val;

	if(LED_STATE==LED_SET)
		Val = GPIO_SET;
	else if(LED_STATE==LED_RESET)
		Val = GPIO_RESET;


	if(LED_Configuration[LED_NAME].Mode==LED_ACTIVE_HIGH)
	GPIO_enuSetPinValue((void*)LED_Configuration[LED_NAME].Port,LED_Configuration[LED_NAME].Pin,Val);

	if(LED_Configuration[LED_NAME].Mode==LED_ACTIVE_LOW)
	GPIO_enuSetPinValue((void*)LED_Configuration[LED_NAME].Port,LED_Configuration[LED_NAME].Pin,Val);


	return Local_Status;
}
