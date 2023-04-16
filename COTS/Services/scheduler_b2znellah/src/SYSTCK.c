/*************************************************************
 *
 * Filename: SYSTCK.h
 * Description: Header (interface) file of the SYSTCK driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/

#include "SYSTCK.h"



#define ENABLE_CLK_MASK		0x00000001
#define ENABLE_INT_MASK		0x00000002
#define ENABLE_AHB_PRES		0x00000004
#define COUNT_FLAG_MASK		0x00008000	// CHECKS ON THE COUNT FLAG BIT IN THE CTRL (Returns 1 if timer counted to 0 since last time this was read)

#define TEST				0x00000007
#define AHB_CLK_SELECT		0x00000004	// To enable just OR this with the reg, to Enable AHB/8 clear the 2nd bit
#define ENABLE_EXCEPTION	0x00000002	// To enable just OR this with the reg, to disable clear bit 1
#define CLEAR_LOAD			0xFF000000



static systck_cbf_t Systick_CBF_Notify_App;


void Systck_voidEnable(AHB_CLK_PRESCALER_t AHB_CLK_PRESCALER)
{

	// Saving the value of the register to avoid manipulation of the reserved bits

	u32 Local_u32RegisterHold = SYSTICK->CTRL;

	Local_u32RegisterHold &= (~ENABLE_CLK_MASK);	// Clear the enable bit

	Local_u32RegisterHold |= ENABLE_CLK_MASK;	// Set the enable bit to enable the systick

	if(AHB_CLK_PRESCALER==AHB_DIVIDED_BY_ONE)
	{
		Local_u32RegisterHold |= ENABLE_AHB_PRES;
	}


	SYSTICK->CTRL = Local_u32RegisterHold;

}


void Systck_voidEnableException(void)
{

	// Saving the value of the register to avoid manipulation of the reserved bits

	u32 Local_u32RegisterHold = SYSTICK->CTRL;



	Local_u32RegisterHold |= ENABLE_EXCEPTION;	// Enable the interrupt request mode

	SYSTICK->CTRL = Local_u32RegisterHold;

}



SYSTCK_ERROR_STATUS Systck_SetTime(u32 Copy_u32Time,u32 Copy_u32ClockFreq)
{
	SYSTCK_ERROR_STATUS Status = SYSTCK_OK;

	u32 Local_u32RegisterHold = SYSTICK->CTRL;
	u32 Local_u32Temp = SYSTICK->LOAD;

//	Local_u32Temp = (Copy_u32Time*Copy_u32ClockFreq)/1000UL;	//	--- > Worked perfectly FINE

	if(Copy_u32Time>0x00FFFFFF)			// LARGER THAN THE REGISTER
	{
		Status = SYSTCK_INVALID_COUNTER_TIME;
	}

	else
	{
		if(Local_u32RegisterHold&AHB_CLK_SELECT)		// CHECK THE AHB DIVIDEED BY 8 or not ?
		{

			Local_u32Temp=(Copy_u32Time*Copy_u32ClockFreq)/1000;
		}
		else	// AHB/8
		{
			Local_u32Temp=(Copy_u32Time*Copy_u32ClockFreq)/8000;
		}
	}

	SYSTICK->LOAD = Local_u32Temp-1;
	return Status;

}

void Systck_SetCallBack(systck_cbf_t Copy_Call_BackFunction)
{
	if(Copy_Call_BackFunction)
	{
		Systick_CBF_Notify_App = Copy_Call_BackFunction;
	}
}

void SysTick_Handler(void)
{
	if(Systick_CBF_Notify_App)
	{
		Systick_CBF_Notify_App();
	}
}


SYSTCK_ERROR_STATUS SYSTCK_voidSetBusyWait(u32 Copy_u32Time,u32 Copy_u32ClockFreq)
{
	SYSTCK_ERROR_STATUS Status = SYSTCK_OK;

	u32 Local_u32RegisterHold = SYSTICK->CTRL;
	u32 Local_u32Temp = SYSTICK->LOAD;

//	Local_u32Temp = (Copy_u32Time*Copy_u32ClockFreq)/1000UL;	//	--- > Worked perfectly FINE

	if(Copy_u32Time>0x00FFFFFF)			// LARGER THAN THE REGISTER
	{
		Status = SYSTCK_INVALID_COUNTER_TIME;
	}

	else
	{
		if(Local_u32RegisterHold&AHB_CLK_SELECT)		// CHECK THE AHB DIVIDEED BY 8 or not ?
		{

			Local_u32Temp=(Copy_u32Time*Copy_u32ClockFreq)/1000;
		}
		else	// AHB/8
		{
			Local_u32Temp=(Copy_u32Time*Copy_u32ClockFreq)/8000;
		}
	}

	SYSTICK->LOAD = Local_u32Temp;

	while(!(SYSTICK->VAL));	// HOLD THE PROCESSOR UNTIL THE VALUE FINISHES COUNTING

	return Status;

}

// The main purpose for this function is to call the schedular each 1ms to manage the tasks
SYSTCK_ERROR_STATUS Systck_Call_each_Period(u32 Copy_u32Time,u32 Copy_u32ClockFreq,systck_cbf_t Copy_Call_BackFunction)
{
	SYSTCK_ERROR_STATUS Status = SYSTCK_OK;

	u32 Local_u32RegisterHold = SYSTICK->CTRL;
	u32 Local_u32Temp = SYSTICK->LOAD;

//	Local_u32Temp = (Copy_u32Time*Copy_u32ClockFreq)/1000UL;	//	--- > Worked perfectly FINE

	if(Copy_u32Time>0x00FFFFFF)			// LARGER THAN THE REGISTER
	{
		Status = SYSTCK_INVALID_COUNTER_TIME;
	}

	else
	{
		if(Local_u32RegisterHold&AHB_CLK_SELECT)		// CHECK THE AHB DIVIDEED BY 8 or not ?
		{

			Local_u32Temp=(Copy_u32Time*Copy_u32ClockFreq)/1000;
		}
		else	// AHB/8
		{
			Local_u32Temp=(Copy_u32Time*Copy_u32ClockFreq)/8000;
		}
	}

	SYSTICK->LOAD = Local_u32Temp-1;

	Systck_SetCallBack(Copy_Call_BackFunction);

	return Status;

}

