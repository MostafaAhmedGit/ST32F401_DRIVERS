/*
 * RCC_config.h
 *
 *  Created on: Feb 5, 2023
 *      Author: Mostafa AHMED
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


//		For Pre-build configurations


/****OPTIONS FOR CLK TYPE IN RCC:
 * 											*	RCC_HSE_CRYSTAL
 * 											*	RCC_HSE_RC
 * 											*	RCC_HSI
 * 											*	RCC_PLL
 *
 ****/

#define RCC_CLOCK_TYPE	RCC_HSI

/***OPTIONS FOR RCC PLL INPUT :-

 	 	 	 	 	 	 	 	 *	RCC_PLL_IN_HSI_DIV_2
 	 	 	 	 	 	 	 	 *	RCC_PLL_IN_HSE_DIV_2
 	 	 	 	 	 	 	 	 *	RCC_PLL_IN_HSE

****/


//If the user didn't choose the RCC_PLL as the clock type their is no need to define the Input for the PLL
#if RCC_CLOCK_TYPE==RCC_PLL

#define RCC_PLL_INPUT		RCC_PLL_IN_HSE

//Options for RCC_PLL_MUL_VAL ----------------------------------> 2-16
#define RCC_PLL_MUL_VAL 	4

#endif




#endif /* RCC_CONFIG_H_ */
