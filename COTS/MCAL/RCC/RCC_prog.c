/*
 * RCC_prog.c
 *
 *  Created on: Feb 5, 2023
 *      Author: Mostafa AHMED
 */
#include "RCC.h"
#include "RCC_priv.h"
#include "Stdtypes.h"



RCC_enuErrorStatus_t RCC_enuInitSys(void)
{
	RCC_enuErrorStatus_t Status = RCC_enuNOK;
	u16 Local_u16Counter;

#if RCC_CLOCK_TYPE==RCC_HSE_CRYSTAL		//		Bypassed with external clock

/*	Write on the HSEON 1 to start intialization		*/
				RCC_CR = 0x00050000;

/*	Polling	check to ensure that the HSE is enabled		*/

	// Getbit ---> ((REG)&(1<<Bit))!=0

				if((((RCC_CR)&(1<<17))!=0))		//check ready or not ?
			{
				for(Local_u16Counter=0;Local_u16Counter<0xFFFF;Local_u16Counter++)
				{
					if(	(RCC_CFGR&(1<<3))==0	&&	(((RCC_CFGR)&(1<<2)))==1 )
					{
						Status = RCC_enuOK;
						break;				// if conditions are OK in SWS(READ ONLY BIT) then break the loop ?
					}
				}
			}
#elif RCC_CLOCK_TYPE==RCC_HSE_RC		//		Not Bypassed

	RCC_CR = 0x000010000;

	for(Local_u16Counter=0;Local_u16Counter<0xFFFF;Local_u16Counter++)
	{
		if(		((RCC_CR)&(1<<17))!=0		&&		(RCC_CFGR&(1<<3)!=0)	&&	((RCC_CFGR)&(1<<2))!=1	)
		{
			Status = RCC_enuOK;
		}
	}

#elif RCC_CLOCK_TYPE==RCC_HSI							//      High Speed Internal
	RCC_CR=0x000000001;
	for(Local_u16Counter=0;Local_u16Counter<0xFFFF;Local_u16Counter++)
	{
		if(		((RCC_CR)&(1<<1))!=0		&&		(RCC_CFGR&(1<<3)!=0)	&&	((RCC_CFGR)&(1<<2))!=0)
		{
			Status = RCC_enuOK;
		}
	}
#elif RCC_CLOCK_TYPE==RCC_PLL							//      Phase Locked Loop as the system clock
	RCC_CR = 0x005000000;

	for(Local_u16Counter=0;Local_u16Counter<0xFFFF;Local_u16Counter++)
	{
		if(		((RCC_CR)&(1<<25))!=0		&&		(RCC_CFGR&(1<<3)!=1)	&&	((RCC_CFGR)&(1<<2))!=0	)
		{
			Status = RCC_enuOK;
		}
	}
#else
#warning INVALID RCC CLOCK TYPE INPUT IN THE CONFIG.H FILE PLEASE CHECK COMMENTS AND USE OPTIONS
#endif

	return Status;
}

RCC_enuErrorStatus_t RCC_enuEnableClock(RCC_enuBusID_t Cpy_enuBusID,u8 Cpy_u8PeripheralID)
{
	RCC_enuErrorStatus_t Status = RCC_enuOK;
	switch(Cpy_enuBusID)
	{
		case RCC_BUS_AHB1:

/*	SET Bit	for the register to enable the chosen bus */

		RCC_AHB1ENR|=(1<<Cpy_u8PeripheralID); break;

		case RCC_BUS_AHB2:

/*	SET Bit	for the register to enable the chosen bus */

		RCC_AHB2ENR|=(1<<Cpy_u8PeripheralID); break;

		case RCC_BUS_APB1:
			/*	SET Bit			*/
		RCC_APB1ENR|=(1<<Cpy_u8PeripheralID); break;

		case RCC_BUS_APB2:

		RCC_APB2ENR|=(1<<Cpy_u8PeripheralID); break;

		default:
		Status = RCC_enuNOK;

	}

	return Status;
}


RCC_enuErrorStatus_t RCC_enuDisableClock(RCC_enuBusID_t Cpy_enuBusID,u8 Cpy_u8PeripheralID)
{
	RCC_enuErrorStatus_t Status = RCC_enuOK;
	switch(Cpy_enuBusID)
	{
		case RCC_BUS_AHB1:

/*	CLR Bit	for the register to enable the chosen bus */

		RCC_AHB1ENR&=~(1<<Cpy_u8PeripheralID); break;

		case RCC_BUS_AHB2:

/*	CLR Bit	for the register to enable the chosen bus */

		RCC_AHB2ENR&=~(1<<Cpy_u8PeripheralID); break;

		case RCC_BUS_APB1:

/*	CLR Bit	for the register to enable the chosen bus */

		RCC_APB1ENR&=~(1<<Cpy_u8PeripheralID); break;

		case RCC_BUS_APB2:

/*	CLR Bit	for the register to enable the chosen bus */

			RCC_APB2ENR&=~(1<<Cpy_u8PeripheralID); break;

		default:
		Status = RCC_enuNOK;

	}

	return Status;
}



//RCC_CLOCK_STATUS_t RCC_enuGetClockStatus(RCC_CLOCK_TYPES_t CopyClock_enuID)
//{
//	RCC_CLOCK_STATUS_t Status = RCC_enuOK;
//	u8 Local_u8CheckVariable;
//
//	if(CopyClock_enuID<0||CopyClock_enuID>3)
//		Status = RCC_enuNOK;
//	else
//	{
//		switch(CopyClock_enuID)
//		{
//		case RCC_HSE_CRYSTAL:
//			Local_u8CheckVariable = (RCC_CR & (1<<17))!=0;
//			break;
//		case RCC_HSE_RC:
//			Local_u8CheckVariable = (RCC_CR & (1<<17))!=0;
//			break;
//		}
//	}
//
//
//	return Status;
//}
