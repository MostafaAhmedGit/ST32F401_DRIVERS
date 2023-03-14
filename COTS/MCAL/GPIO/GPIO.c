/*************************************************************
 *
 * Filename: GPIO.c
 * Description: Sourc (interface) file of the GPIO driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/
#include "GPIO.h"
#define NULL (void*)0



/****************************************************************			MACROS				********************************************************************************************************************************/
#define MODE_CLR 	  	0b11
#define MODE_INPUT    	0b00
#define MODE_SHIFT	   	 2
#define MODE_ANALOG   	0b11
#define MODE_AF		 	0b10
#define MODE_OP		  	0b01

#define PULL_UP		  	0b01
#define PULL_DOWN	  	0b10
#define NO_PU_PD	  	0b00


#define OP_OPEN_DRAIN	  0b1
#define OP_PP	  	  	  0b0
#define CLR_1			  0b1
#define BIT_1			  0b1


#define CLR_SPEED	0b00
#define LOW_SPEED	0b00
#define MED_SPEED	0b01
#define HIGH_SPEED  0b10
#define VHIGH_SPEED	0b11


#define REG_16_SHIFT  16












/****************************************************************************************************************************************************************************************************************************/
GPIO_enuError_Status GPIO_enuInit(GPIO_strConfig_t *CpyPtr_ConfigStr)
{
	GPIO_enuError_Status Local_enuStatus=GPIO_OK;
	u32 Local_u32RegisterHold = 0;
	u32 Local_u32RegisterHold2 = 0;
	u32 Local_u32RegisterHold3 = 0;

	u32 Local_u32PortHold = CpyPtr_ConfigStr->Port;
	u32 Local_u32PinHold = CpyPtr_ConfigStr->Pin;

	// Check if pointer is equal to NULL
	if(CpyPtr_ConfigStr==NULL)
	{
		Local_enuStatus = GPIO_NULL_PTR;
	}

	else
	{

		// Switch case on the modes
		switch(CpyPtr_ConfigStr->Mode)
	{
		case GPIO_MODE_INPUT_PULL_UP:
		{
			// Get the register value and save into a local variable

			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));

			// Setting the pin to input
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

			// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;

		}break;
		case GPIO_MODE_INPUT_PULL_DOWN:
		{
			// Get the register value and save into a local variable

			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));

			// Setting the pin to input
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;;


		}break;
		case GPIO_MODE_INPUT_FLOATING:
		{
			// Get the register value and save into a local variable

			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));

			// Setting the pin to input
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

			/*Setting it to Floating */
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold2 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold2 |= (NO_PU_PD<<(Local_u32PinHold*2));
			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;

		}break;
		case GPIO_MODE_ANALOG:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_ANALOG<<(Local_u32PinHold*2));

			// Setting the pin to analog
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;



		}break;
		case GPIO_MODE_OUTPUT_OPEN_DRAIN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);
		}break;
		case GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_UP:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);



			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_UP<<(Local_u32PinHold*2));
			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;




		}break;
		case GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_DOWN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);



			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;


		}break;
		case GPIO_MODE_OUTPUT_PUSH_PULL:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

			// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;

		}break;
		case GPIO_MODE_OUTPUT_PUSH_PULL_PULL_UP:
		{

			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


						// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;



			// Sets the pin to pull up
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold2 |= (PULL_UP<<(Local_u32PinHold*2));




		}break;
		case GPIO_MODE_OUTPUT_PUSH_PULL_PULL_DOWN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;




			// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;


			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;


		}break;
		case GPIO_MODE_AF_PUSH_PULL:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;



						// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;


		}break;
		case GPIO_MODE_AF_PUSH_PULL_PULL_UP:
		{

			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


			// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;



			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));

			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;





		}break;
		case GPIO_MODE_AF_PUSH_PULL_PULL_DOWN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;



			// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;


			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;



		}break;
		case GPIO_MODE_AF_OPEN_DRAIN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to AF
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			((volatile GPIO*)Local_u32PortHold)->OTYPER =Local_u32RegisterHold2 ;






		}break;
		case GPIO_MODE_AF_OPEN_DRAIN_PULL_UP:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to AF
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);
			((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;

			// Pull up
			Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_UP<<(Local_u32PinHold*2));
			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;



		}break;
		case GPIO_MODE_AF_OPEN_DRAIN_PULL_DOWN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to AF
			((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);



			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
			((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;




		}break;
		default:
			Local_enuStatus = GPIO_INVALID_MODE;


	}




	}



			// To hold the register value to set the speed
			Local_u32PinHold = ((volatile GPIO*)Local_u32PortHold)->OSPEEDR;
			Local_u32PinHold &= (CLR_SPEED<<Local_u32PinHold*2);
			Local_u32PinHold |= CpyPtr_ConfigStr->Speed;
			((volatile GPIO*)Local_u32PortHold)->OSPEEDR = Local_u32PinHold;


	return Local_enuStatus;
}

GPIO_enuError_Status GPIO_enuSetPinDirection(GPIO_enuPORT_t Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_enuMODE_t Cpy_enuMode,GPIO_enuSpeed_t Cpy_enuSpeed)
{

	GPIO_enuError_Status Local_enuStatus=GPIO_OK;
		u32 Local_u32RegisterHold = 0;
		u32 Local_u32RegisterHold2 = 0;
		u32 Local_u32RegisterHold3 = 0;

		u32 Local_u32PortHold = Cpy_enuPort;
		u32 Local_u32PinHold = Cpy_enuPin;


			// Switch case on the modes
			switch(Cpy_enuMode)
		{
			case GPIO_MODE_INPUT_PULL_UP:
			{
				// Get the register value and save into a local variable

				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));

				// Setting the pin to input
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

				// Setting the pin to Push Pull
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

				((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;

			}break;
			case GPIO_MODE_INPUT_PULL_DOWN:
			{
				// Get the register value and save into a local variable

				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));

				// Setting the pin to input
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

				// Pull Down
				Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;;


			}break;
			case GPIO_MODE_INPUT_FLOATING:
			{
				// Get the register value and save into a local variable

				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));

				// Setting the pin to input
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

				/*Setting it to Floating */
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold2 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold2 |= (NO_PU_PD<<(Local_u32PinHold*2));
				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;

			}break;
			case GPIO_MODE_ANALOG:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_ANALOG<<(Local_u32PinHold*2));

				// Setting the pin to analog
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;



			}break;
			case GPIO_MODE_OUTPUT_OPEN_DRAIN:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

				// Setting the pin to open drain
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);
			}break;
			case GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_UP:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

				// Setting the pin to open drain
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);



				// Pull Down
				Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold3 |= (PULL_UP<<(Local_u32PinHold*2));
				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;




			}break;
			case GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_DOWN:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

				// Setting the pin to open drain
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);



				// Pull Down
				Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;


			}break;
			case GPIO_MODE_OUTPUT_PUSH_PULL:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;

				// Setting the pin to Push Pull
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

				((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;

			}break;
			case GPIO_MODE_OUTPUT_PUSH_PULL_PULL_UP:
			{

				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


							// Setting the pin to Push Pull
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

				((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;



				// Sets the pin to pull up
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold2 |= (PULL_UP<<(Local_u32PinHold*2));




			}break;
			case GPIO_MODE_OUTPUT_PUSH_PULL_PULL_DOWN:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;




				// Setting the pin to Push Pull
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

				((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;


				// Pull Down
				Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;


			}break;
			case GPIO_MODE_AF_PUSH_PULL:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;



							// Setting the pin to Push Pull
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

				((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;


			}break;
			case GPIO_MODE_AF_PUSH_PULL_PULL_UP:
			{

				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


				// Setting the pin to Push Pull
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

				((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;



				// Pull Down
				Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));

				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;





			}break;
			case GPIO_MODE_AF_PUSH_PULL_PULL_DOWN:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

				// Setting the pin to output
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;



				// Setting the pin to Push Pull
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

				((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;


				// Pull Down
				Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;



			}break;
			case GPIO_MODE_AF_OPEN_DRAIN:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

				// Setting the pin to AF
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


				// Setting the pin to open drain
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				((volatile GPIO*)Local_u32PortHold)->OTYPER =Local_u32RegisterHold2 ;






			}break;
			case GPIO_MODE_AF_OPEN_DRAIN_PULL_UP:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

				// Setting the pin to AF
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


				// Setting the pin to open drain
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);
				((volatile GPIO*)Local_u32PortHold)->OTYPER = Local_u32RegisterHold2;

				// Pull up
				Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold3 |= (PULL_UP<<(Local_u32PinHold*2));
				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;



			}break;
			case GPIO_MODE_AF_OPEN_DRAIN_PULL_DOWN:
			{
				Local_u32RegisterHold = ((volatile GPIO*)Local_u32PortHold)->MODER;
				Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
				Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

				// Setting the pin to AF
				((volatile GPIO*)Local_u32PortHold)->MODER = Local_u32RegisterHold;


				// Setting the pin to open drain
				Local_u32RegisterHold2 = ((volatile GPIO*)Local_u32PortHold)->OTYPER;
				Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
				Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);



				// Pull Down
				Local_u32RegisterHold3 = ((volatile GPIO*)Local_u32PortHold)->PUPDR;
				Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
				Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
				((volatile GPIO*)Local_u32PortHold)->PUPDR = Local_u32RegisterHold3;




			}break;
			default:
				Local_enuStatus = GPIO_INVALID_MODE;


		}


				// To hold the register value to set the speed
				Local_u32PinHold = ((volatile GPIO*)Local_u32PortHold)->OSPEEDR;
				Local_u32PinHold &= (CLR_SPEED<<Local_u32PinHold*2);
				Local_u32PinHold |= Cpy_enuSpeed;
				((volatile GPIO*)Local_u32PortHold)->OSPEEDR = Local_u32PinHold;


		return Local_enuStatus;
	}

GPIO_enuError_Status GPIO_enuSetPinValue(GPIO_PORT_VALUE_t Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_PIN_STATE Cpy_enuPinState)
{
	GPIO_enuError_Status Status = GPIO_OK;


	// Save the actual value of the BSRR

	u32 Local_u32RegisterHold = ((volatile GPIO*)Cpy_enuPort)->BSRR;

	/*CLEAR THE PIN'S BIT TO AVOID ANY UNWANTED RESULTS */



	switch(Cpy_enuPinState)
	{
	case GPIO_SET:
		Local_u32RegisterHold &=~(CLR_1<<Cpy_enuPin);
		Local_u32RegisterHold |=(BIT_1<<(Cpy_enuPin));



		break;

	case GPIO_RESET:
		Local_u32RegisterHold &=~(CLR_1<<(Cpy_enuPin+REG_16_SHIFT));
		Local_u32RegisterHold |=(BIT_1<<(Cpy_enuPin+REG_16_SHIFT));
		break;


	default:
		Status = GPIO_INVALID_MODE;
	}

	((volatile GPIO*)Cpy_enuPort)->BSRR = Local_u32RegisterHold;



	return Status;
}
