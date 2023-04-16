/*************************************************************
 *
 * Filename: LED.h
 * Description: Header (interface) file of the LED driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/



#ifndef LED_H_
#define LED_H_
#include "src/GPIO.h"

#define MAX_LEDS	3


// Led Names
typedef enum
{
	ALARM_LED = 0,
	REAR_LED,
	LED_count
}LED_NAMES;

// Error Status
typedef enum
{
	LED_OK,
	LED_NOK,
	LED_INVALID_PIN,
	LED_INVALID_PORT
}LED_errorStatus;
typedef enum
{
	LED_SET,
	LED_RESET
}LED_State_t;

// Mode
typedef enum
{
	LED_ACTIVE_HIGH,
	LED_ACTIVE_LOW,

}LED_MODE_t;

// Configuration
typedef struct
{
	GPIO_AVAILABLE_PORTS Port;
	GPIO_PIN_t Pin;
	GPIO_enuSpeed_t Speed;
	GPIO_enuMODE_t Mode;
	LED_NAMES Name;
	LED_State_t InitalState;

}LED_Configuration_t;





LED_errorStatus LED_Init(LED_Configuration_t *Ptr_Cfg);
LED_errorStatus LED_Set(LED_NAMES LED_NAME,LED_State_t LED_STATE);

extern const LED_Configuration_t LED_Configuration[MAX_LEDS];

#endif
