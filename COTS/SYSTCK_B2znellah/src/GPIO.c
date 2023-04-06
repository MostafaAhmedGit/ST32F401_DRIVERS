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
static void SPEED(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_enuSpeed_t Cpy_enuSpeed);
static void INPUT(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);
static void OUTPUT(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);
static void PU(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);
static void PD(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);
static void ANALOG(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);
static void OD(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);
static void FLOATING(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);
static void PP(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);
static void AF(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin);

/****************************************************************************************************************************************************************************************************************************/
GPIO_enuError_Status GPIO_enuInit(GPIO_strConfig_t *CpyPtr_ConfigStr)
{
	GPIO_enuError_Status Local_enuStatus=GPIO_OK;
	u32 Local_u32RegisterHold = 0;
	u32 Local_u32RegisterHold2 = 0;
	u32 Local_u32RegisterHold3 = 0;

//	u32 CpyPtr_ConfigStr->Port = CpyPtr_ConfigStr->Port;
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
			INPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PU(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);

//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));
//
//			// Setting the pin to input
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;

			// Setting the pin to Push Pull
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
//			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
//			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);
//
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER = Local_u32RegisterHold2;

		}break;
		case GPIO_MODE_INPUT_PULL_DOWN:
		{
			INPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PD(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			// Get the register value and save into a local variable
//
//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));
//
//			// Setting the pin to input
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;
//
//			// Pull Down
//			Local_u32RegisterHold3 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
//			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
//			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
//
//
//
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;


		}break;
		case GPIO_MODE_INPUT_FLOATING:
		{

			INPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			FLOATING(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			// Get the register value and save into a local variable

//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_INPUT<<(Local_u32PinHold*2));
//
//			// Setting the pin to input
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;
//
//			/*Setting it to Floating */
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
//			Local_u32RegisterHold2 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
//			Local_u32RegisterHold2 |= (NO_PU_PD<<(Local_u32PinHold*2));
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;

		}break;
		case GPIO_MODE_ANALOG:
		{
			ANALOG(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
//
//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_ANALOG<<(Local_u32PinHold*2));
//
//			// Setting the pin to analog
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;



		}break;
		case GPIO_MODE_OUTPUT_OPEN_DRAIN:
		{
			OUTPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			OD(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));
//
//			// Setting the pin to output
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;
//
//			// Setting the pin to open drain
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
//			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
//			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);
		}break;
		case GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_UP:
		{
			OUTPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			OD(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PU(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);

//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));
//
//			// Setting the pin to output
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;
//
//			// Setting the pin to open drain
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
//			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
//			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);
//
//
//
//			// Pull Down
//			Local_u32RegisterHold3 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
//			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
//			Local_u32RegisterHold3 |= (PULL_UP<<(Local_u32PinHold*2));
//
//
//
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;




		}break;
		case GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_DOWN:
		{
//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));
//
//			// Setting the pin to output
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;
//
//			// Setting the pin to open drain
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
//			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
//			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);
//
//
//
//			// Pull Down
//			Local_u32RegisterHold3 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
//			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
//			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;
//
			OUTPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			OD(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PD(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
		}break;
		case GPIO_MODE_OUTPUT_PUSH_PULL:
		{
			OUTPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PP(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);


//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));
//
//			// Setting the pin to output
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;
//
//			// Setting the pin to Push Pull
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
//			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
//			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);
//
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER = Local_u32RegisterHold2;

		}break;
		case GPIO_MODE_OUTPUT_PUSH_PULL_PULL_UP:
		{
			OUTPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PP(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PU(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
//
//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));
//
//			// Setting the pin to output
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;
//
//
//						// Setting the pin to Push Pull
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
//			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
//			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);
//
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER = Local_u32RegisterHold2;
//
//
//
//			// Sets the pin to pull up
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
//			Local_u32RegisterHold2 |= (PULL_UP<<(Local_u32PinHold*2));

		}break;
		case GPIO_MODE_OUTPUT_PUSH_PULL_PULL_DOWN:
		{
			OUTPUT(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PP(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
			PD(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin);
//			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
//			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
//			Local_u32RegisterHold |= (MODE_OP<<(Local_u32PinHold*2));
//
//			// Setting the pin to output
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;
//
//
//
//
//			// Setting the pin to Push Pull
//			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
//			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
//			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);
//
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER = Local_u32RegisterHold2;
//
//
//			// Pull Down
//			Local_u32RegisterHold3 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
//			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
//			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
//			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;
//

		}break;
		case GPIO_MODE_AF_PUSH_PULL:
		{
			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;



						// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER = Local_u32RegisterHold2;


		}break;
		case GPIO_MODE_AF_PUSH_PULL_PULL_UP:
		{

			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;


			// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER = Local_u32RegisterHold2;



			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));

			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;





		}break;
		case GPIO_MODE_AF_PUSH_PULL_PULL_DOWN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to output
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;



			// Setting the pin to Push Pull
			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);

			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER = Local_u32RegisterHold2;


			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;



		}break;
		case GPIO_MODE_AF_OPEN_DRAIN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to AF
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;


			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER =Local_u32RegisterHold2 ;






		}break;
		case GPIO_MODE_AF_OPEN_DRAIN_PULL_UP:
		{
			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to AF
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;


			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Local_u32PinHold);
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER = Local_u32RegisterHold2;

			// Pull up
			Local_u32RegisterHold3 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_UP<<(Local_u32PinHold*2));
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;



		}break;
		case GPIO_MODE_AF_OPEN_DRAIN_PULL_DOWN:
		{
			Local_u32RegisterHold = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER;
			Local_u32RegisterHold &=~(MODE_CLR<<(Local_u32PinHold*2));
			Local_u32RegisterHold |= (MODE_AF<<(Local_u32PinHold*2));

			// Setting the pin to AF
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->MODER = Local_u32RegisterHold;


			// Setting the pin to open drain
			Local_u32RegisterHold2 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->OTYPER;
			Local_u32RegisterHold2&=~(CLR_1<<Local_u32PinHold);
			Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Local_u32PinHold);



			// Pull Down
			Local_u32RegisterHold3 = ((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR;
			Local_u32RegisterHold3 &=~(MODE_CLR<<Local_u32PinHold*MODE_SHIFT);
			Local_u32RegisterHold3 |= (PULL_DOWN<<(Local_u32PinHold*2));
			((volatile GPIO*)CpyPtr_ConfigStr->Port)->PUPDR = Local_u32RegisterHold3;




		}break;
		default:
			Local_enuStatus = GPIO_INVALID_MODE;


	}




	}


	SPEED(CpyPtr_ConfigStr->Port,CpyPtr_ConfigStr->Pin,CpyPtr_ConfigStr->Speed);
	return Local_enuStatus;
}

GPIO_enuError_Status GPIO_enuSetPinDirection(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_enuMODE_t Cpy_enuMode,GPIO_enuSpeed_t Cpy_enuSpeed)
{

	GPIO_enuError_Status Local_enuStatus=GPIO_OK;


//		u32 Cpy_enuPort = *(u32*)Cpy_enuPort;
		u32 Local_u32PinHold = Cpy_enuPin;


			// Switch case on the modes
			switch(Cpy_enuMode)
		{
			case GPIO_MODE_INPUT_PULL_UP:
			{
				// Get the register value and save into a local variable
				INPUT(Cpy_enuPort,Cpy_enuPin);
				PU(Cpy_enuPort,Cpy_enuPin);

			}break;
			case GPIO_MODE_INPUT_PULL_DOWN:
			{
				// Get the register value and save into a local variable

				INPUT(Cpy_enuPort,Cpy_enuPin);
				PD(Cpy_enuPort,Cpy_enuPin);


			}break;
			case GPIO_MODE_INPUT_FLOATING:
			{
				// Get the register value and save into a local variable

				INPUT(Cpy_enuPort,Cpy_enuPin);
				FLOATING(Cpy_enuPort,Cpy_enuPin);

			}break;
			case GPIO_MODE_ANALOG:
			{
				ANALOG(Cpy_enuPort,Cpy_enuPin);
			}break;
			case GPIO_MODE_OUTPUT_OPEN_DRAIN:
			{
				OUTPUT(Cpy_enuPort,Cpy_enuPin);
				OD(Cpy_enuPort,Cpy_enuPin);

			}break;
			case GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_UP:
			{
				OUTPUT(Cpy_enuPort,Cpy_enuPin);
				OD(Cpy_enuPort,Cpy_enuPin);
				PU(Cpy_enuPort,Cpy_enuPin);
			}break;
			case GPIO_MODE_OUTPUT_OPEN_DRAIN_PULL_DOWN:
			{
				OUTPUT(Cpy_enuPort,Cpy_enuPin);
				OD(Cpy_enuPort,Cpy_enuPin);
				PD(Cpy_enuPort,Cpy_enuPin);
			}break;
			case GPIO_MODE_OUTPUT_PUSH_PULL:
			{
				OUTPUT(Cpy_enuPort,Cpy_enuPin);
				PP(Cpy_enuPort,Cpy_enuPin);
			}break;
			case GPIO_MODE_OUTPUT_PUSH_PULL_PULL_UP:
			{
				OUTPUT(Cpy_enuPort,Cpy_enuPin);
				PP(Cpy_enuPort,Cpy_enuPin);
				PU(Cpy_enuPort,Cpy_enuPin);
			}break;
			case GPIO_MODE_OUTPUT_PUSH_PULL_PULL_DOWN:
			{
				OUTPUT(Cpy_enuPort,Cpy_enuPin);
				PP(Cpy_enuPort,Cpy_enuPin);
				PD(Cpy_enuPort,Cpy_enuPin);
			}break;
			case GPIO_MODE_AF_PUSH_PULL:
			{
				AF(Cpy_enuPort,Cpy_enuPin);
				PP(Cpy_enuPort,Cpy_enuPin);

			}break;
			case GPIO_MODE_AF_PUSH_PULL_PULL_UP:
			{
				AF(Cpy_enuPort,Cpy_enuPin);
				PP(Cpy_enuPort,Cpy_enuPin);
				PU(Cpy_enuPort,Cpy_enuPin);


			}break;
			case GPIO_MODE_AF_PUSH_PULL_PULL_DOWN:
			{
				AF(Cpy_enuPort,Cpy_enuPin);
				PP(Cpy_enuPort,Cpy_enuPin);
				PD(Cpy_enuPort,Cpy_enuPin);


			}break;
			case GPIO_MODE_AF_OPEN_DRAIN:
			{
				AF(Cpy_enuPort,Cpy_enuPin);
				OD(Cpy_enuPort,Cpy_enuPin);
			}break;
			case GPIO_MODE_AF_OPEN_DRAIN_PULL_UP:
			{


				AF(Cpy_enuPort,Cpy_enuPin);
				OD(Cpy_enuPort,Cpy_enuPin);
				PU(Cpy_enuPort,Cpy_enuPin);

			}break;
			case GPIO_MODE_AF_OPEN_DRAIN_PULL_DOWN:
			{

				AF(Cpy_enuPort,Cpy_enuPin);
				OD(Cpy_enuPort,Cpy_enuPin);
				PD(Cpy_enuPort,Cpy_enuPin);

			}break;
			default:
				Local_enuStatus = GPIO_INVALID_MODE; break;


		}


			SPEED(Cpy_enuPort,Local_u32PinHold,Cpy_enuSpeed);

		return Local_enuStatus;
	}

GPIO_enuError_Status GPIO_enuSetPinValue(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_PIN_STATE Cpy_enuPinState)
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
		Status  = GPIO_INVALID_MODE;
	}

	((volatile GPIO*)Cpy_enuPort)->BSRR = Local_u32RegisterHold;



	return Status;
}


static void OUTPUT(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold;
	Local_u32RegisterHold = ((volatile GPIO*)Cpy_enuPort)->MODER;
	Local_u32RegisterHold &=~(MODE_CLR<<(Cpy_enuPin*2));
	Local_u32RegisterHold |= (MODE_OP<<(Cpy_enuPin*2));

	// Setting the pin to output
	((volatile GPIO*)Cpy_enuPort)->MODER = Local_u32RegisterHold;
}
static void SPEED(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin,GPIO_enuSpeed_t Cpy_enuSpeed)
{
	// To hold the register value to set the speed
	Cpy_enuPin = ((volatile GPIO*)Cpy_enuPort)->OSPEEDR;
	Cpy_enuPin &= (CLR_SPEED<<Cpy_enuPin*2);
	Cpy_enuPin |= Cpy_enuSpeed;
	((volatile GPIO*)Cpy_enuPort)->OSPEEDR = Cpy_enuPin;
}
static void INPUT(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold;
	Local_u32RegisterHold = ((volatile GPIO*)Cpy_enuPort)->MODER;
	Local_u32RegisterHold &=~(MODE_CLR<<(Cpy_enuPin*2));
	Local_u32RegisterHold |= (MODE_INPUT<<(Cpy_enuPin*2));

	// Setting the pin to input
	((volatile GPIO*)Cpy_enuPort)->MODER = Local_u32RegisterHold;
}
static void PU(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold2;
	Local_u32RegisterHold2 = ((volatile GPIO*)Cpy_enuPort)->OTYPER;
	Local_u32RegisterHold2&=~(CLR_1<<Cpy_enuPin);
	Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Cpy_enuPin);

	((volatile GPIO*)Cpy_enuPort)->OTYPER = Local_u32RegisterHold2;
}
static void PD(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold3;
	Local_u32RegisterHold3 = ((volatile GPIO*)Cpy_enuPort)->PUPDR;
	Local_u32RegisterHold3 &=~(MODE_CLR<<Cpy_enuPin*MODE_SHIFT);
	Local_u32RegisterHold3 |= (PULL_DOWN<<(Cpy_enuPin*2));
	((volatile GPIO*)Cpy_enuPort)->PUPDR = Local_u32RegisterHold3;
}
static void ANALOG(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold;
	Local_u32RegisterHold = ((volatile GPIO*)Cpy_enuPort)->MODER;
	Local_u32RegisterHold &=~(MODE_CLR<<(Cpy_enuPin*2));
	Local_u32RegisterHold |= (MODE_ANALOG<<(Cpy_enuPin*2));

	// Setting the pin to analog
	((volatile GPIO*)Cpy_enuPort)->MODER = Local_u32RegisterHold;
}
static void OD(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold2;

	Local_u32RegisterHold2 = ((volatile GPIO*)Cpy_enuPort)->OTYPER;
	Local_u32RegisterHold2&=~(CLR_1<<Cpy_enuPin);
	Local_u32RegisterHold2|=(OP_OPEN_DRAIN<<Cpy_enuPin);
	((volatile GPIO*)Cpy_enuPort)->OTYPER =Local_u32RegisterHold2 ;
}
static void FLOATING(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold2;
	Local_u32RegisterHold2 = ((volatile GPIO*)Cpy_enuPort)->PUPDR;
	Local_u32RegisterHold2 &=~(MODE_CLR<<Cpy_enuPin*MODE_SHIFT);
	Local_u32RegisterHold2 |= (NO_PU_PD<<(Cpy_enuPin*2));
	((volatile GPIO*)Cpy_enuPort)->PUPDR = Local_u32RegisterHold2;
}
static void PP(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold2;
	// Setting the pin to Push Pull
	Local_u32RegisterHold2 = ((volatile GPIO*)Cpy_enuPort)->OTYPER;
	Local_u32RegisterHold2&=~(CLR_1<<Cpy_enuPin);
//	Local_u32RegisterHold2 |= (OP_OPEN_DRAIN<<Cpy_enuPin);

	((volatile GPIO*)Cpy_enuPort)->OTYPER = Local_u32RegisterHold2;

}
static void AF(void* Cpy_enuPort,GPIO_PIN_t Cpy_enuPin)
{
	u32 Local_u32RegisterHold;

	Local_u32RegisterHold = ((volatile GPIO*)Cpy_enuPort)->MODER;
	Local_u32RegisterHold &=~(MODE_CLR<<(Cpy_enuPin*2));
	Local_u32RegisterHold |= (MODE_ANALOG<<(Cpy_enuPin*2));

	// Setting the pin to analog
	((volatile GPIO*)Cpy_enuPort)->MODER = Local_u32RegisterHold;
	}
