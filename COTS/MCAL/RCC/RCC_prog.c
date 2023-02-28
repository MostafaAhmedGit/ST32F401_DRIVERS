/*
 * RCC_prog.c
 *
 *  Created on: Feb 5, 2023
 *      Author: Mostafa AHMED
 */
#include "RCC.h"
#include "RCC_priv.h"
#include "Stdtypes.h"
#include "RCC_config.h"

#define HSE_Enable_Mask	  0x00090000	// Enables the HSE + Enable CSS + Enable OSC bypass
#define HSE_Ready_Check   0x00020000	// Mask to check if the HSE is ready or not ?
#define HSE_Disable_Mask  0xFFFEFFFF	// Mask to disable HSE


#define PLL_Enable_Mask	  0x01000000	// Enables the PLL
#define PLL_Disable_Mask  0xFEFFFFFF	// Disables the PLL
#define PLL_Ready_Check	  0x02000000	// Gets the PLLRDY
#define PLL_REG_RESET	  0xF0BC8000	// Gives all config

#define HSI_Enable_Mask	  0x00000001	//Enables the HSI
#define HSI_Ready_Check	  0x00000010
#define HSI_Disable_Mask  0x11111110


#define SWS_Check_Mask	  0x0000000C;


/*				AHB1's Bus MASKS		*/

#define DMA2EN_AHB1_ENABLE		  0x00400000
#define DMA2EN_AHB1_DISABLE		  0xFFBFFFFF

#define DMA1EN_AHB1_ENABLE		  0x00200000
#define DMA1EN_AHB1_DISABLE		  0xFFDFFFFF


#define GPIOAEN_AHB1_DISABLE		0xFFFFFFFE
#define GPIOBEN_AHB1_DISABLE		0xFFFFFFFD
#define GPIOCEN_AHB1_DISABLE		0xFFFFFFFB
#define GPIODEN_AHB1_DISABLE		0xFFFFFFF7
#define GPIOEEN_AHB1_DISABLE		0xFFFFFFEF
#define GPIOHEN_AHB1_DISABLE		0xFFFFFF7F
#define CRCEN_AHB1_DISABLE			0xFFFFEFFF

#define GPIOAEN_AHB1_ENABLE		 	0x00000001
#define GPIOBEN_AHB1_ENABLE		  	0x00000002
#define GPIOCEN_AHB1_ENABLE		 	0x00000004
#define GPIODEN_AHB1_ENABLE		  	0x00000008
#define GPIOEEN_AHB1_ENABLE	      	0x00000010
#define GPIOHEN_AHB1_ENABLE		  	0x00000020
#define CRCEN_AHB1_ENABLE         	0x00001000


/*				APB2's Bus MASKS		*/

#define TIM1EN_APB2_ENABLE			0x00000001
#define USART1EN_APB2_ENABLE		0x00000010
#define USART6EN_APB2_ENABLE		0x00000020
#define ADC1EN_APB2_ENABLE			0x00000100
#define SDIOEN_APB2_ENABLE			0x00000800
#define SPI1EN_APB2_ENABLE			0x00001000
#define SPI4EN_APB2_ENABLE			0x00002000
#define SYSCFGEN_APB2_ENABLE		0x00004000
#define TIM9EN_APB2_ENABLE			0x00010000
#define TIM10EN_APB2_ENABLE			0x00020000
#define TIM11EN_APB2_ENABLE			0x00040000


#define TIM1EN_APB2_DISABLE			0xFFFFFFFE
#define USART1EN_APB2_DISABLE		0xFFFFFFEF
#define USART6EN_APB2_DISABLE		0xFFFFFFDF
#define ADC1EN_APB2_DISABLE			0xFFFFFEFF
#define SDIOEN_APB2_DISABLE			0xFFFFF7FF
#define SPI1EN_APB2_DISABLE			0xFFFFEFFF
#define SPI4EN_APB2_DISABLE			0xFFFFDFFF
#define SYSCFGEN_APB2_DISABLE		0xFFFFBFFF
#define TIM9EN_APB2_DISABLE			0xFFFEFFFF
#define TIM10EN_APB2_DISABLE		0xFFFDFFFF
#define TIM11EN_APB2_DISABLE		0xFFFBFFFF


/* Check the SW  */
#define SW_CLR						0xFFFFFFFC
#define SW_SET_HSI					0x00000000
#define SW_SET_HSE					0x00000001
#define SW_SET_PLL					0x00000002







RCC_enuErrorStatus_t RCC_enuEnableHSE(void)
{
	RCC_enuErrorStatus_t Local_Status = RCC_enuOK;


	/* Timer to Exit checking the RDY flag 	*/
	u8 Local_timer = 253;

	/* Holding the register value */
	u32 Local_u32RegisterHold = RCC_CR;

	/* OR-ing the local value with Enable mask to enable HSE,CSS and OSC's Bypass */
	Local_u32RegisterHold|=HSE_Enable_Mask;

/*	Giving the control register the value after enabling the HSE  */

	RCC_CR = Local_u32RegisterHold;


	/*Loop to check the bit of HSE RDY, make sure its ON + Counter to avoid staying forever */

	while(!(RCC_CR&(1<<17)))
	{
		Local_timer--;
		if((RCC_CR&HSE_Ready_Check)==1)
			break;
	}


	return Local_Status;
}

RCC_enuErrorStatus_t RCC_enuDisableHSE(void)
{
	RCC_enuErrorStatus_t Local_Status = RCC_enuOK;


	/* Timer to Exit checking the RDY flag 	*/
	u8 Local_timer = 253;

	/* Holding the register value */
	u32 Local_u32RegisterHold = RCC_CR;

	/* AND-ing the register with the disable mask , all bits are equal 1 to keep value except HSE ON */

	Local_u32RegisterHold&=HSE_Disable_Mask;

	/* Passing the value to the CR register */
	RCC_CR = Local_u32RegisterHold;


	/*Loop to check the bit of HSE RDY, make sure its OFF + Counter to avoid staying forever */

	while((RCC_CR&HSE_Ready_Check)&&Local_timer)
	{
		Local_timer--;
	}


	return Local_Status;


}
RCC_enuErrorStatus_t RCC_enuEnableHSI(void)
{
	RCC_enuErrorStatus_t Status = RCC_enuOK;

	/* Timer to Exit checking the RDY flag 	*/

		u8 Local_timer = 253;

	/* Holding the register value */

		u32 Local_u32RegisterHold = RCC_CR;

	Local_u32RegisterHold|=HSI_Enable_Mask;

	while(!(RCC_CR&HSI_Ready_Check))
	{
		Local_timer--;

		//To exit the loop in case HSI is not ready to avoid staying in loop forever
		if(Local_timer==0)
			break;
	}

	return Status;

}
RCC_enuErrorStatus_t RCC_enuDisableHSI(void)
{
	RCC_enuErrorStatus_t Status = RCC_enuOK;

	/* Timer to Exit checking the RDY flag 	*/

		u8 Local_timer = 253;

	/* Holding the register value */

		u32 Local_u32RegisterHold = RCC_CR;

	Local_u32RegisterHold|=HSI_Disable_Mask;

	while((RCC_CR&HSI_Ready_Check))
	{
		Local_timer--;
	}
		//To exit the loop in case HSI is not ready to avoid staying in loop forever
	if(Local_timer==0)
		Status = RCC_enuNOK;


	return Status;

}
RCC_enuErrorStatus_t RCC_enuEnablePLL(void)
{
	RCC_enuErrorStatus_t Status = RCC_enuOK;

	u8 Local_timer = 255;

	/* Holding the register value */

	u32 Local_u32RegisterHold = RCC_CR;

	/*Enable the PLLON */

	Local_u32RegisterHold|=PLL_Enable_Mask;


	/*Loop to check the bit of PLL RDY, make sure its OFF + Counter to avoid staying forever */

	while((RCC_CR&PLL_Ready_Check)&&Local_timer)
	{
		Local_timer--;
	}

	if(Local_timer==0)
		Status = RCC_enuNOK;


	return Status;

}
RCC_enuErrorStatus_t RCC_PLL_Config(u8 PLL_u8P,u8 PLL_u8Q,u8 PLL_u8M,u16 PLL_u16N)
{
	RCC_enuErrorStatus_t Status = RCC_enuOK;

	u32 Local_u32RegisterHold;



	Local_u32RegisterHold = RCC_PLL_CFGR;

	if(PLL_u8M==0||PLL_u8M==1)
		Status = RCC_enuNOK;

	if(PLL_u16N==0||PLL_u16N==0)
		Status = RCC_enuNOK;

	if(PLL_u16N>=433||PLL_u16N<=511)
		Status = RCC_enuNOK;
//	/*	Turn Off PLL to configure it */
//
//	Local_u32RegisterHold&=PLL_Disable_Mask;	// Turns OFF the PLL

	if(Status==RCC_enuOK)
	{
		Local_u32RegisterHold&=PLL_REG_RESET;			// Reset for the PQMN

		Local_u32RegisterHold|=(PLL_u8M&0x3F);			// Ensure there is no bits at the 6,7 bits


		Local_u32RegisterHold|=(PLL_u16N&0x01FF)<<6;	// Ensure there is no bits at the 6,7 bits

		Local_u32RegisterHold|=(PLL_u8P&0x03)<<16;

		Local_u32RegisterHold|=(PLL_u8Q&0x0F)<<24;

		RCC_PLL_CFGR=Local_u32RegisterHold;
	}

	return Status;
}

//RCC_enuErrorStatus_t RCC_enuControlPeripheralAPB1(RCC_enuPeripheralState RCC_enuState,RCC_enuAPB1_Peripherals Copy_enuSelectedPeripheral)
//{
//
//}

RCC_enuErrorStatus_t RCC_enuControlPeripheralAHB1(RCC_enuPeripheralState RCC_enuState,RCC_enuAHB1_Peripherals Copy_enuSelectedPeripheral)
{
	RCC_enuErrorStatus_t Status = RCC_enuOK;

	u32 Local_RegisterHold = RCC_AHB1ENR;

	switch(Copy_enuSelectedPeripheral)
	{
	case DMA2EN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=DMA2EN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=DMA2EN_AHB1_DISABLE;break;
	case GPIOAEN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=GPIOAEN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=GPIOAEN_AHB1_DISABLE		;break;



	case GPIOBEN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=GPIOBEN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=GPIOBEN_AHB1_DISABLE;break;


	case GPIOCEN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=GPIOCEN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=GPIOCEN_AHB1_DISABLE;	break;


	case GPIODEN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=GPIODEN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=GPIODEN_AHB1_DISABLE;	break;



	case GPIOEEN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=GPIOEEN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=GPIOEEN_AHB1_DISABLE;	break;


	case GPIOHEN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=GPIOHEN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=GPIOHEN_AHB1_DISABLE;	break;

	case CRCEN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=CRCEN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=CRCEN_AHB1_DISABLE;	break;

	case DMA1EN_AHB1:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=DMA1EN_AHB1_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=DMA1EN_AHB1_DISABLE;	break;

	}

	RCC_AHB1ENR = Local_RegisterHold;
	return Status;

}
RCC_enuErrorStatus_t RCC_enuControlPeripheralAPB2(RCC_enuPeripheralState RCC_enuState,RCC_enuAPB2_Peripherals Copy_enuSelectedPeripheral)
{
	RCC_enuErrorStatus_t Status = RCC_enuOK;


	u32 Local_RegisterHold = RCC_APB2ENR;

	switch(Copy_enuSelectedPeripheral)
	{
	case TIM1EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=TIM1EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=TIM1EN_APB2_DISABLE;break;



	case USART1EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=USART1EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=USART1EN_APB2_DISABLE;break;


	case USART6EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=USART6EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=USART6EN_APB2_DISABLE;	break;


	case ADC1EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=ADC1EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=ADC1EN_APB2_DISABLE;	break;



	case SDIOEN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=SDIOEN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=SDIOEN_APB2_DISABLE;	break;


	case SPI1EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=SPI1EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=SPI1EN_APB2_DISABLE;	break;

	case SPI4EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=SPI4EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=SPI4EN_APB2_DISABLE;	break;

	case SYSCFGEN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=SYSCFGEN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=SYSCFGEN_APB2_DISABLE;	break;


	case TIM9EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=TIM9EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=TIM9EN_APB2_DISABLE;	break;

	case TIM10EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=TIM10EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=TIM10EN_APB2_DISABLE;	break;


	case TIM11EN_APB2:

		if(RCC_enuState==RCC_enuON)			Local_RegisterHold |=TIM11EN_APB2_ENABLE;
		else if(RCC_enuState==RCC_enuON)	Local_RegisterHold &=TIM11EN_APB2_DISABLE;	break;



	}


	return Status;

}
RCC_enuErrorStatus_t RCC_enuDisablePLL(void)
{
	RCC_enuErrorStatus_t Local_Status = RCC_enuOK;


	/* Timer to Exit checking the RDY flag 	*/
	u8 Local_timer = 253;

	/* Holding the register value */
	u32 Local_u32RegisterHold = RCC_CR;

	/* AND-ing the register with the disable mask , all bits are equal 1 to keep value except HSE ON */

	Local_u32RegisterHold&=PLL_Disable_Mask;

	/* Passing the value to the CR register */
	RCC_CR = Local_u32RegisterHold;


	/*Loop to check the bit of HSE RDY, make sure its OFF + Counter to avoid staying forever */

	while((RCC_CR&HSE_Ready_Check)&&Local_timer)
	{
		Local_timer--;
	}


	return Local_Status;


}


RCC_enuErrorStatus_t RCC_enuGetSysCLK(u8 *RCC_ptrCLK)
{
	//	Bits 3:2 SWS: System clock switch status
	//	Set and cleared by hardware to indicate which clock source is used as the system clock.
	//	00: HSI oscillator used as the system clock
	//	01: HSE oscillator used as the system clock
	//	10: PLL used as the system clock
	//	11: not applicable


	RCC_enuErrorStatus_t Status = RCC_enuOK;
	//The function checks the SWS

	u8 Check_on_SWS;

	u32 Local_u32RegisterHold;

	Local_u32RegisterHold=RCC_CFGR;

	Check_on_SWS = Local_u32RegisterHold&SWS_Check_Mask;

	switch(Check_on_SWS)
	{
		case 0:	*RCC_ptrCLK = 0;break;	//HSI
		case 1:	*RCC_ptrCLK = 1;break;	//HSE
		case 2:	*RCC_ptrCLK = 2;break;  //PLL
		default: Status = RCC_enuNOK;
	}

	return Status;
}
RCC_enuErrorStatus_t RCC_enuEnableSystemCLK(RCC_enuClocks Cpy_enuRCC_CLK)
{


	RCC_enuErrorStatus_t Status = RCC_enuOK;

	/*	Dedicated to SET the SW */


	u32 Local_u32RegisterHold = RCC_CFGR;

//Bits 1:0 SW: System clock switch : -

		//Set and cleared by software to select the system clock source.
		//Set by hardware to force the HSI selection when leaving the Stop or Standby mode or in
		//case of failure of the HSE oscillator used directly or indirectly as the system clock.
		//00: HSI oscillator selected as system clock
		//01: HSE oscillator selected as system clock
		//10: PLL selected as system clock


	Local_u32RegisterHold&=SW_CLR;			// Clears the SW bits that determine the System CLK

	switch(Cpy_enuRCC_CLK)
	{
	case RCC_HSI:			Local_u32RegisterHold |= SW_SET_HSI;	break;
	case RCC_HSE:			Local_u32RegisterHold |= SW_SET_HSI;	break;
	case RCC_PLL:			Local_u32RegisterHold |= SW_SET_PLL;	break;
	}

	return Status;
}
