/*
 * RCC_priv.h
 *
 *  Created on: Feb 5, 2023
 *      Author: Mostafa AHMED
 */

#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_


#include "Stdtypes.h"



// /* 		CLOCK TYPES			*/
//
//#define RCC_HSE_CRYSTAL		0
//#define RCC_HSE_RC			1
//#define RCC_HSI				2
//#define RCC_PLL				3







/*			PLL OPTIONS			*/

#define RCC_PLL_HSI_DIV2	0
#define RCC_PLL_HSE_DIV2    1
#define RCC_PLL_HSE    		2


#define RCC_CLK__STATE_ON	0
#define RCC_CLK__STATE_OFF	1


/*							Addresses and OFFSETS							*/

#define RCC_BASE				0x40023800	//RCC BASE ADDRESS
#define RCC_CR_OFFSET			0			//RCC clock configuration register
#define RCC_PLL_CFGR_OFFSET		4			//RCC PLL configuration register
#define RCC_CFGR_OFFSET			0x8			//RCC clock configuration register
#define RCC_CIR_OFFSET			C			//RCC clock interrupt register

#define RCC_AHB1RSTR_OFFSET		10			//RCC AHB1 peripheral reset register
#define RCC_AHB2RSTR_OFFSET		14			//RCC AHB2 peripheral reset register
#define RCC_APB1RSTR_OFFSET		20			//RCC APB1 peripheral reset register

#define RCC_AHB1ENR_OFFSET		30			//RCC AHB1 peripheral clock enable register
#define RCC_AHB2ENR_OFFSET		34			//RCC AHB2 peripheral clock enable register

#define RCC_APB1ENR_OFFSET		40			//RCC APB1 peripheral clock enable register
#define RCC_APB2ENR_OFFSET		44			//RCC APB2 peripheral clock enable register

#define RCC_AHB2LPENR_OFFSET	54			//RCC AHB2 peripheral clock enable in low power mode register
#define RCC_APB1LPENR_OFFSET	60			//RCC APB1 peripheral clock enable in low power mode register
#define RCC_APB2LPENR_OFFSET	64			//RCC APB2 peripheral clock enabled in low power mode register
#define RCC_BDCR_OFFSET			70
#define RCC_CSR_OFFSET			74

#define RCC_PLLI2SCFGR_OFFSET	84			//RCC PLLI2S configuration register








#define RCC_CR				*((volatile u32*)RCC_BASE+RCC_CR_OFFSET)
#define RCC_CFGR			*((volatile u32*)0x40023808)

#define RCC_PLL_CFGR		*((volatile u32*) RCC_BASE+RCC_PLL_CFGR_OFFSET)
#define RCC_CIR				*((volatile u32*) RCC_BASE+RCC_CIR_OFFSET)
#define RCC_AHB1RSTR		*((volatile u32*) RCC_BASE+RCC_AHB1RSTR_OFFSET)
#define RCC_AHB2RSTR		*((volatile u32*) RCC_BASE+RCC_AHB2RSTR_OFFSET)
#define RCC_APB1RSTR		*((volatile u32*) RCC_BASE+RCC_APB1RSTR_OFFSET)
#define RCC_CSR				*((volatile u32*) RCC_BASE+RCC_CSR_OFFSET)
#define RCC_BDCR			*((volatile u32*) RCC_BASE+RCC_BDCR_OFFSET)

#define RCC_AHB1ENR			*((volatile u32*) RCC_BASE+RCC_AHB1ENR_OFFSET)
#define RCC_AHB2ENR			*((volatile u32*) RCC_BASE+RCC_AHB2ENR_OFFSET)


#define RCC_APB1ENR			*((volatile u32*) RCC_BASE+RCC_APB1ENR_OFFSET)
#define RCC_APB2ENR			*((volatile u32*) RCC_BASE+RCC_APB2ENR_OFFSET)




#endif /* RCC_PRIV_H_ */
