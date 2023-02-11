/*
 * RCC.h
 *
 *  Created on: Feb 5, 2023
 *      Author: Mostafa AHMED
 */

#ifndef RCC_H_
#define RCC_H_

typedef enum
{
	RCC_enuOK = 0,
	RCC_enuNOK

}RCC_enuErrorStatus_t;

typedef enum
{
	RCC_BUS_APB1,
	RCC_BUS_APB2,
	RCC_BUS_AHB1,
	RCC_BUS_AHB2

}RCC_enuBusID_t;

/*
 * Uses : Initalize the RCC based on the pre-build configurations in the config.h
 *
 * Input : VOID
 *
 * Output : Clock chosen in the RCC_config.h is configured Inshallah
 *
 * Return : Enum Error Status OK or NOK
 */

RCC_enuErrorStatus_t RCC_enuInitSys(void);

RCC_CLOCK_STATUS_t RCC_enuGetClockStatus(RCC_CLOCK_TYPES_t CopyClock_enuID);

RCC_enuErrorStatus_t RCC_enuDisableClock(RCC_enuBusID_t Cpy_enuBusID,u8 Cpy_u8PeripheralID);

RCC_enuErrorStatus_t RCC_enuEnableClock(RCC_enuBusID_t Cpy_enuBusID,u8 Cpy_u8PeripheralID);





#endif /* RCC_H_ */
