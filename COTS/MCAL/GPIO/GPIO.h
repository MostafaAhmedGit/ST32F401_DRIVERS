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
	GPIO_PIN_0=1,
	GPIO_PIN_1=2,
	GPIO_PIN_2=4,
	GPIO_PIN_3=8,
	GPIO_PIN_4=16,
	GPIO_PIN_5=32,
	GPIO_PIN_6=64,
	GPIO_PIN_7=128,
	GPIO_PIN_8=256,
	GPIO_PIN_9=512,
	GPIO_PIN_10=1024,
	GPIO_PIN_11=2048,
	GPIO_PIN_12=4096,
	GPIO_PIN_13=8192,
	GPIO_PIN_14=16384,
	GPIO_PIN_15=32768,
	GPIO_PINS_ALL=65535,
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
	GPIO_enuPORT_t Port;
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
GPIO_enuError_Status GPIO_enuSetPinDirection(GPIO_enuPORT_t Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_enuMODE_t Cpy_enuMode,GPIO_enuSpeed_t Cpy_enuSpeed);
GPIO_enuError_Status GPIO_enuSetPinValue(GPIO_PORT_VALUE_t Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_PIN_STATE Cpy_enuPinState);

GPIO_enuError_Status GPIO_enuGetPinValue(GPIO_enuPORT_t Cpy_u8Port,GPIO_PIN_t Cpy_u8Pin,GPIO_enuMODE_t Cpy_u8Mode,u8 *Ptr_u8PvToValue);


#endif
