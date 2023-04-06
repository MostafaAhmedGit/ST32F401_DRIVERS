/*************************************************************
 *
 * Filename: GPIO.h
 * Description: Header (interface) file of the GPIO driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/

#ifndef GPIO_H
#define GPIO_H
#include "Stdtypes.h"
#include "GPIO_priv.h"

// Error Status
typedef enum
{
	GPIO_OK,
	GPIO_NOK,
	GPIO_INVALID_PORT,
	GPIO_INVALID_MODE,
	GPIO_INVALID_PIN,
	GPIO_INVALID_SPEED,
	GPIO_INVALID_DIRECTION,
	GPIO_NULL_PTR,
}GPIO_enuError_Status;


// Mode
typedef enum
{
	GPIO_MODE_INPUT_PULL_UP,
	GPIO_MODE_INPUT_PULL_DOWN,
	GPIO_MODE_INPUT_FLOATING,
	GPIO_MODE_ANALOG,

	GPIO_MODE_OUTPUT_OPEN_DRAIN,
	GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_UP,
	GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_DOWN,
	GPIO_MODE_OUTPUT_PUSH_PULL,
	GPIO_MODE_OUTPUT_PUSH_PULL_PULL_UP,
	GPIO_MODE_OUTPUT_PUSH_PULL_PULL_DOWN,

	GPIO_MODE_AF_PUSH_PULL,
	GPIO_MODE_AF_PUSH_PULL_PULL_UP,
	GPIO_MODE_AF_PUSH_PULL_PULL_DOWN,
	GPIO_MODE_AF_OPEN_DRAIN,
	GPIO_MODE_AF_OPEN_DRAIN_PULL_UP,
	GPIO_MODE_AF_OPEN_DRAIN_PULL_DOWN,

}GPIO_enuMODE_t;


//	Pins
typedef enum
{
	GPIO_PIN_0=0,
	GPIO_PIN_1=1,
	GPIO_PIN_2=2,
	GPIO_PIN_3=3,
	GPIO_PIN_4=4,
	GPIO_PIN_5=5,
	GPIO_PIN_6=6,
	GPIO_PIN_7=7,
	GPIO_PIN_8=8,
	GPIO_PIN_9=9,
	GPIO_PIN_10=10,
	GPIO_PIN_11=11,
	GPIO_PIN_12=12,
	GPIO_PIN_13=13,
	GPIO_PIN_14=14,
	GPIO_PIN_15=15
}GPIO_PIN_t;

// Speed
typedef enum
{
	GPIO_SPEED_LOW=0,
	GPIO_SPEED_MEDIUM=1,
	GPIO_SPEED_HIGH=2,
	GPIO_SPEED_VHIGH=3
}GPIO_enuSpeed_t;

// CONFIG STRUCT
typedef struct
{
	void* Port;
	GPIO_PIN_t Pin;
	GPIO_enuSpeed_t Speed;
	GPIO_enuMODE_t Mode;
}GPIO_strConfig_t;

// Value --> Set reset
typedef enum
{
	GPIO_SET=0,
	GPIO_RESET
}GPIO_VALUE_t;

// Port Value
typedef enum
{
	GPIO_PORT_SET = 0xFFFF,
	GPIO_PORT_RESET=0xFFFF0000
}GPIO_PORT_VALUE_t;


typedef enum
{
	GPIO_PIN_HIGH=0,
	GPIO_PIN_LOW
}GPIO_PIN_STATE;


GPIO_enuError_Status GPIO_enuInit(GPIO_strConfig_t *CpyPtr_ConfigStr);
GPIO_enuError_Status GPIO_enuSetPinDirection(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_enuMODE_t Cpy_enuMode,GPIO_enuSpeed_t Cpy_enuSpeed);
GPIO_enuError_Status GPIO_enuSetPinValue(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_PIN_STATE Cpy_enuPinState);

GPIO_enuError_Status GPIO_enuGetPinValue(void* Cpy_u8Port,GPIO_PIN_t Cpy_u8Pin,GPIO_enuMODE_t Cpy_u8Mode,u8 *Ptr_u8PvToValue);


#endif
