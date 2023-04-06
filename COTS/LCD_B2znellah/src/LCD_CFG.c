/*************************************************************
 *
 * Filename: LCD_CONFIG.c
 * Description: Source (interface) file of the LCD driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/
#include "LCD.h"


const LCD_Configurations_t LCD_Configurations[LCD_COUNT] =
	{
			[LCD_MAIN] =
			{


					 .LCD_VSS_PIN={

									 .Port = GPIO_PORT_A,
									 .Pin = GPIO_PIN_1,
									 .Speed = GPIO_SPEED_HIGH,
									 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

							 },

					 .LCD_RW_PIN={

									 .Port = GPIO_PORT_A,
									 .Pin = GPIO_PIN_2,
									 .Speed = GPIO_SPEED_HIGH,
									 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,


					 },
					 .LCD_RS_PIN=							 {
							 .Port = GPIO_PORT_A,
							 .Pin = GPIO_PIN_3,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_E_PIN=							 {
							 .Port = GPIO_PORT_A,
							 .Pin = GPIO_PIN_4,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_DATA_L1=							 {		//D0
							 .Port = GPIO_PORT_B,
							 .Pin = GPIO_PIN_0,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_DATA_L2=							 {		//D1
							 .Port = GPIO_PORT_B,
							 .Pin = GPIO_PIN_1,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_DATA_L3=							 {		//D2
							 .Port = GPIO_PORT_B,
							 .Pin = GPIO_PIN_2,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_DATA_L4=							 {		//D3
							 .Port = GPIO_PORT_B,
							 .Pin = GPIO_PIN_3,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_DATA_L5=							 {		//D4
							 .Port = GPIO_PORT_B,
							 .Pin = GPIO_PIN_4,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_DATA_L6=							 {		//D5
							 .Port = GPIO_PORT_B,
							 .Pin = GPIO_PIN_5,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_DATA_L7=							 {		//D6
							 .Port = GPIO_PORT_B,
							 .Pin = GPIO_PIN_6,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 },
					 .LCD_DATA_L8 = 					 {	//D7
							 .Port = GPIO_PORT_B,
							 .Pin = GPIO_PIN_7,
							 .Speed = GPIO_SPEED_HIGH,
							 .Mode = GPIO_MODE_OUTPUT_PUSH_PULL,

					 }
			}
	};
