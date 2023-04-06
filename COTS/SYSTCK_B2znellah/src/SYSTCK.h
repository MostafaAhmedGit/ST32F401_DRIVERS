
/*************************************************************
 *
 * Filename: SYSTCK.h
 * Description: Header (interface) file of the SYSTCK driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/

#include "Stdtypes.h"


#ifndef SYSTCK_H_
#define SYSTCK_H_


typedef void(*systck_cbf_t)(void);


// Error Status
typedef enum
{
	SYSTCK_OK,
	SYSTCK_NOK,
	SYSTCK_INVALID_COUNTER_TIME

}SYSTCK_ERROR_STATUS;

typedef enum
{
	AHB_DIVIDED_BY_ONE,
	AHB_DIVIDED_BY_EIGHT
}AHB_CLK_PRESCALER_t;


// Registers
typedef struct
{
	u32 CTRL;

	u32 LOAD;

	u32 VAL;

	u32 CALIB;
}SYSTICK_t;


#define SYSTICK ((volatile SYSTICK_t*)0xE000E010)






void Systck_voidEnable(AHB_CLK_PRESCALER_t AHB_CLK_PRESCALER);


void Systck_voidEnableException(void);


SYSTCK_ERROR_STATUS Systck_SetTime(u32 Copy_u32Time,u32 Copy_u32ClockFreq);



SYSTCK_ERROR_STATUS Systck_enuStartCount(void);


void Systck_SetCallBack(systck_cbf_t Copy_Call_BackFunction);

SYSTCK_ERROR_STATUS SYSTCK_voidSetBusyWait(u32 Copy_u32Time,u32 Copy_u32ClockFreq);

SYSTCK_ERROR_STATUS Systck_Call_each_Period(u32 Copy_u32Time,u32 Copy_u32ClockFreq,systck_cbf_t Copy_Call_BackFunction);



#endif
