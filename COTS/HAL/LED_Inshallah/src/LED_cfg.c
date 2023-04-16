/*************************************************************
 *
 * Filename: LED_CFG.c
 * Description: Source (interface) file of the LED driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/

#include "LED.h"
#include "src/GPIO.h"



const LED_Configuration_t LED_Configuration[MAX_LEDS] =
{
		[ALARM_LED] =
			{
				.Port = GPIO_PORTA,
				.Pin  = GPIO_PIN_0,
				.Speed = GPIO_SPEED_HIGH,
				.Mode = LED_ACTIVE_HIGH,
				.Name = ALARM_LED,
				.InitalState = LED_SET		// Inital State
			}
};
