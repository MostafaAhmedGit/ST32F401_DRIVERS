/*************************************************************
 *
 * Filename: RCC.h
 * Description: Header (interface) file of the RCC driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/

#ifndef RCC_H_
#define RCC_H_
#include "Stdtypes.h"



typedef enum
{
	RCC_HSI=0,
	RCC_HSE=1,
	RCC_PLL=2
}RCC_enuClocks;

typedef enum
{

	RCC_enuOFF,
	RCC_enuON

}RCC_enuPeripheralState;

typedef enum
{
	RCC_enuOK = 0,
	RCC_enuNOK

}RCC_enuErrorStatus_t;

typedef enum
{
	GPIOAEN_AHB1,
	GPIOBEN_AHB1,
	GPIOCEN_AHB1,
	GPIODEN_AHB1,
	GPIOEEN_AHB1,
	GPIOHEN_AHB1,
	CRCEN_AHB1,
	DMA1EN_AHB1,
	DMA2EN_AHB1,


}RCC_enuAHB1_Peripherals;


typedef enum
{
	TIM1EN_APB2,
	USART1EN_APB2,
	USART6EN_APB2,
	ADC1EN_APB2,
	SDIOEN_APB2,
	SPI1EN_APB2,
	SPI4EN_APB2,
	SYSCFGEN_APB2,
	TIM9EN_APB2,
	TIM10EN_APB2,
	TIM11EN_APB2
}RCC_enuAPB2_Peripherals;



typedef enum
{
	TIM2EN_APB1,
	TIM3EN_APB1,
	TIM4EN_APB1,
	TIM5EN_APB1,
	WWDGEN_APB1,
	SPI2EN_APB1,
	SPI3EN_APB1,
	USART2EN_APB1,
	I2C1EN_APB1,
	I2C2EN_APB1,
	I2C3EN_APB1,
	PWREN_APB1
}RCC_enuAPB1_Peripherals;



typedef enum
{
	SYSCLK_NOT_DIVIDED=0,
	SYSCLK_DIV_2,
	SYSCLK_DIV_4,
	SYSCLK_DIV_8,
	SYSCLK_DIV_16,
	SYSCLK_DIV_64,
	SYSCLK_DIV_128,
	SYSCLK_DIV_256,
	SYSCLK_DIV_512

}RCC_AHB_PRESCALER;






/************************************************************************/
/*
	Name:				Enable HSE

	Input: 					void

	Return: 			Error Status

	Output:				Enables the HSE
 */
/************************************************************************/

RCC_enuErrorStatus_t RCC_enuEnableHSE(void);
/************************************************************************/
/*
	Name:					Enable HSI

	Input: 						Void

	Return: 				Error Status

	Output:				Enables the HSI
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_enuEnableHSI(void);

/************************************************************************/
/*
	Name:					RCC_enuDisableHSI

	Input: 							Void

	Return: 					Error Status

	Output:				Disables the HSI clock
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_enuDisableHSI(void);
/************************************************************************/
/*
	Name:					RCC_PLL_Config

	Input: 				Inputs the P,Q,M,N

	Return: 				Error Status

	Output:			Configures the P,Q,M,N in the PLL register
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_PLL_Config(u8 PLL_u8P,u8 PLL_u8Q,u8 PLL_u8M,u16 PLL_u16N);
/************************************************************************/
/*
	Name:					RCC_enuDisablePLL

	Input: 						Void

	Return: 			Error Status

	Output:				Disable the PLL in the H/W
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_enuDisablePLL(void);
/************************************************************************/
/*
	Name:					RCC_enuEnablePLL

	Input: 						Void

	Return: 			Error Status

	Output:				Enable the PLL
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_enuEnablePLL(void);

/************************************************************************/
/*
	Name:					Disable HSE

	Input: 					Void

	Return: 			Error Status

	Output:				Disable the HSE
 */
/************************************************************************/

RCC_enuErrorStatus_t RCC_enuDisableHSE(void);
/************************************************************************/
/*
	Name:					Control Peripheral APB1

	Input: 			State of the peripheral + The peripheral

	Return: 			Error Status

	Output:				Enable and Disable peripheral on the bus APB1
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_enuControlPeripheralAPB1(RCC_enuPeripheralState RCC_enuState,RCC_enuAPB1_Peripherals
		Copy_enuSelectedPeripheral);
/************************************************************************/
/*
	Name:					Control Peripheral APB2

	Input: 			State of the peripheral + The peripheral

	Return: 				Error Status

	Output:		Enable and Disable peripheral on the bus APB2
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_enuControlPeripheralAPB2(RCC_enuPeripheralState RCC_enuState,RCC_enuAPB2_Peripherals
		Copy_enuSelectedPeripheral);

/************************************************************************/
/*
	Name:					Control Peripheral AHB1

	Input: 			State of the peripheral + The peripheral

	Return: 					Error Status

	Output:				Enable and Disable peripheral on the bus AHB1
 */
/************************************************************************/

RCC_enuErrorStatus_t RCC_enuControlPeripheralAHB1(RCC_enuPeripheralState RCC_enuState,RCC_enuAHB1_Peripherals
		Copy_enuSelectedPeripheral);

/************************************************************************/
/*
	Name:					Enable System Clock

	Input: 				Any Clock from the enum in the .h file

	Return: 					Error Status

	Output:				Set and cleared by software to select the system clock source
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_enuEnableSystemCLK(RCC_enuClocks Cpy_enuRCC_CLK);

/************************************************************************/
/*
	Name:					Get System Clcok

	Input: 				Pointer with the value

	Return: 			RCC_tenuErrorStatus to report

	Output:		Checks the system clock and tells which clock is system clock
 */
/************************************************************************/
RCC_enuErrorStatus_t RCC_enuGetSysCLK(u8 *RCC_ptrCLK);




#endif /* RCC_H_ */
