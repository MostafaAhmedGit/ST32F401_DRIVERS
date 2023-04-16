
/*************************************************************
 *
 * Filename: NVIC.c
 * Description: Source (interface) file of the NVIC driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/
#include "NVIC.h"




NVIC_enuErrorStatus NVIC_enuEnableIRQ(IRQn_type IRQn)
{


	//  NVIC_ISERx ---- > Interrupt Set Enable Register

	//	Write:
	//	0: No effect
	//	1: Enable interrupt
	//	Read:
	//	0: Interrupt disabled
	//	1: Interrupt enabled.
	//	If a pending interrupt is


	// Error Status Initialy Set with OK
	NVIC_enuErrorStatus Status = NVIC_enuOK;

	if(IRQn<=NVIC_IRQ_31)
	{
		NVIC->NVIC_ISER[IRQn] |= 1<<IRQn;
	}

	else if(IRQn<=NVIC_IRQ_63)
	{
		IRQn-=32;
		NVIC->NVIC_ISER[IRQn]|= 1<<IRQn;
	}

	else
	{
		Status = NVIC_enuNOK;
	}




	return Status;
}

NVIC_enuErrorStatus NVIC_enuDisableIRQ(IRQn_type IRQn)
{
//  ICERx ----- > Interrupt Clear Enable Register
//	Bits 31:0 CLRENA: Interrupt clear-enable bits.
//	Write:
//	0: No effect
//	1: Disable interrupt
//	Read:
//	0: Interrupt disabled
//	1: Interrupt enabled.


	NVIC_enuErrorStatus Status = NVIC_enuOK;


	if(IRQn<=NVIC_IRQ_31)
	{
		NVIC->NVIC_ICER[IRQn]|= 1<<IRQn;
	}

	else if(IRQn<=NVIC_IRQ_63)
	{
		IRQn-=32;
		NVIC->NVIC_ICER[IRQn]|= 1<<IRQn;
	}

	return Status;

}

NVIC_enuErrorStatus NVIC_enuSetPendingIRQ(IRQn_type IRQn)
{
	// The purpose of this function is to test if an interrupt pulse is trigerred

	NVIC_enuErrorStatus Local_enuStatus = NVIC_enuOK;



	if(IRQn<=NVIC_IRQ_31)
	{
		NVIC->NVIC_ISPR[IRQn]|= 1<<IRQn;
	}

	else if(IRQn<=NVIC_IRQ_63)
	{
		IRQn-=32;
		NVIC->NVIC_ISPR[IRQn]|= 1<<IRQn;
	}


	return Local_enuStatus;
}

//NVIC_enuErrorStatus NVIC_enuGetActive(IRQn_type IRQn,u32 *Cpy_u32GetActiveIRQ)
//{
//	NVIC_enuErrorStatus Local_enuStatus = NVIC_enuOK;
//
//	if(IRQn<=NVIC_IRQ_31)
//	{
//		NVIC->NVIC_IABR[IRQn]|= 1<<IRQn;
//	}
//
//	else if(IRQn<=NVIC_IRQ_63)
//	{
//		IRQn-=32;
//		NVIC->NVIC_IABR[IRQn]|= 1<<IRQn;
//	}
//
//	return Local_enuStatus;
//}
//
//
//NVIC_enuErrorStatus NVIC_enuClearPendingIRQ(IRQn_type IRQn)
//{
//	NVIC_enuErrorStatus Status = NVIC_enuOK;
//
//	if(IRQn<=NVIC_IRQ_31)
//	{
//		NVIC->NVIC_ICPR[IRQn]|= 1<<IRQn;
//	}
//
//	else if(IRQn<=NVIC_IRQ_63)
//	{
//		IRQn-=32;
//		NVIC->NVIC_ICPR[IRQn]|= 1<<IRQn;
//	}
//
//	return Status;
//}
//
//
//NVIC_enuErrorStatus NVIC_enuSetPriority(IRQn_type IRQn,u32 Priority)
//{
//
//}
