/*************************************************************
 *
 * Filename: GPIO_priv.h
 * Description: Header (interface) file of the GPIO driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/


#ifndef GPIO_PRIV_H_
#define GPIO_PRIV_H_







// Address to all the ports

typedef enum
{
									// 32 bit = 8 bytes
	GPIO_PORT_A=0x40020000,
	GPIO_PORT_B=0x40020400,
	GPIO_PORT_C=0x40020800,
	GPIO_PORT_D=0x40020C00,
	GPIO_PORT_E=0x40021000,
	GPIO_PORT_H=0x40021C00
}GPIO_enuPORT_t;




// GPIO REGS
typedef struct
{
	volatile u32 MODER;		// 00
	volatile u32 OTYPER;	// 04
	volatile u32 OSPEEDR;	// 08
	volatile u32 PUPDR;		// 0C
	volatile u32 IDR;		// 10
	volatile u32 ODR;		// 14
	volatile u32 BSRR;		// 18
	volatile u32 LCKR;		// 1C
}GPIO;

//#define GPIOA ((volatile GPIO*)0x40020000)
//#define GPIOB ((volatile GPIO*)0x40020400)
//#define GPIOC ((volatile GPIO*)0x40020800)



//#define MODER_OFFSET			0x00		// Choose i/p, GP O/P , AF , Analog
//#define ODR_OFFSET				0x14		// GPIO port output data register
//#define IDR_OFFSET				0x10		// GPIO port input data register
//#define OSPEEDR_OFFSET			0x08		// GPIO port output speed register
//#define OTYPER_OFFSET			0x10
//#define PUPDR_OFFSET			0x0C
//#define BSRR_OFFSET				0x18
//#define LCKR_OFFSET				0x1C
//#define AFRL_OFFSET				0x20
//#define AFRH_OFFSET				0x24
//
//
//
//#define GPIOA_MODER		*((volatile u32*)( GPIOA_BASE_ADDRESS+ MODER_OFFSET))
//#define GPIOA_ODR		*((volatile u32*)( GPIOA_BASE_ADDRESS+ ODR_OFFSET))
//#define GPIOA_IDR		*((volatile u32*)( GPIOA_BASE_ADDRESS+ IDR_OFFSET))
//#define GPIOA_OSPEEDR	*((volatile u32*)( GPIOA_BASE_ADDRESS+ OSPEEDR_OFFSET))
//#define GPIOA_OTYPER	*((volatile u32*)( GPIOA_BASE_ADDRESS+ OTYPER_OFFSET))
//#define GPIOA_PUPDR		*((volatile u32*)( GPIOA_BASE_ADDRESS+ PUPDR_OFFSET))
//#define GPIOA_BSRR		*((volatile u32*)( GPIOA_BASE_ADDRESS+ BSRR_OFFSET))
//#define GPIOA_LCKR		*((volatile u32*)( GPIOA_BASE_ADDRESS+ LCKR_OFFSET))
//#define GPIOA_AFRL		*((volatile u32*)( GPIOA_BASE_ADDRESS+ AFRL_OFFSET))
//#define GPIOA_AFRH		*((volatile u32*)( GPIOA_BASE_ADDRESS+ AFRH_OFFSET))
//
//
//
//#define GPIOB_MODER		*((volatile u32*)( GPIOB_BASE_ADDRESS+ MODER_OFFSET))
//#define GPIOB_ODR		*((volatile u32*)( GPIOB_BASE_ADDRESS+ ODR_OFFSET))
//#define GPIOB_IDR		*((volatile u32*)( GPIOB_BASE_ADDRESS+ IDR_OFFSET))
//#define GPIOB_OSPEEDR	*((volatile u32*)( GPIOB_BASE_ADDRESS+ OSPEEDR_OFFSET))
//#define GPIOB_OTYPER	*((volatile u32*)( GPIOB_BASE_ADDRESS+ OTYPER_OFFSET))
//#define GPIOB_PUPDR		*((volatile u32*)( GPIOB_BASE_ADDRESS+ PUPDR_OFFSET))
//#define GPIOB_BSRR		*((volatile u32*)( GPIOB_BASE_ADDRESS+ BSRR_OFFSET))
//#define GPIOB_LCKR		*((volatile u32*)( GPIOB_BASE_ADDRESS+ LCKR_OFFSET))
//#define GPIOB_AFRL		*((volatile u32*)( GPIOB_BASE_ADDRESS+ AFRL_OFFSET))
//#define GPIOB_AFRH		*((volatile u32*)( GPIOB_BASE_ADDRESS+ AFRH_OFFSET))
//
//
//#define GPIOC_MODER		*((volatile u32*)( GPIOC_BASE_ADDRESS+ MODER_OFFSET))
//#define GPIOC_ODR		*((volatile u32*)( GPIOC_BASE_ADDRESS+ ODR_OFFSET))
//#define GPIOC_IDR		*((volatile u32*)( GPIOC_BASE_ADDRESS+ IDR_OFFSET))
//#define GPIOC_OSPEEDR	*((volatile u32*)( GPIOC_BASE_ADDRESS+ OSPEEDR_OFFSET))
//#define GPIOC_OTYPER	*((volatile u32*)( GPIOC_BASE_ADDRESS+ OTYPER_OFFSET))
//#define GPIOC_PUPDR		*((volatile u32*)( GPIOC_BASE_ADDRESS+ PUPDR_OFFSET))
//#define GPIOC_BSRR		*((volatile u32*)( GPIOC_BASE_ADDRESS+ BSRR_OFFSET))
//#define GPIOC_LCKR		*((volatile u32*)( GPIOC_BASE_ADDRESS+ LCKR_OFFSET))
//#define GPIOC_AFRL		*((volatile u32*)( GPIOC_BASE_ADDRESS+ AFRL_OFFSET))
//#define GPIOC_AFRH		*((volatile u32*)( GPIOC_BASE_ADDRESS+ AFRH_OFFSET))

//#define GPIOD_MODER		*((volatile u32*)( GPIOD_BASE_ADDRESS+ MODER_OFFSET))
//#define GPIOD_ODR		*((volatile u32*)( GPIOD_BASE_ADDRESS+ ODR_OFFSET))
//#define GPIOD_IDR		*((volatile u32*)( GPIOD_BASE_ADDRESS+ IDR_OFFSET))
//#define GPIOD_OSPEEDR	*((volatile u32*)( GPIOD_BASE_ADDRESS+ OSPEEDR_OFFSET))
//#define GPIOD_OTYPER	*((volatile u32*)( GPIOD_BASE_ADDRESS+ OTYPER_OFFSET))
//#define GPIOD_PUPDR		*((volatile u32*)( GPIOD_BASE_ADDRESS+ PUPDR_OFFSET))
//#define GPIOD_BSRR		*((volatile u32*)( GPIOD_BASE_ADDRESS+ BSRR_OFFSET))
//#define GPIOD_LCKR		*((volatile u32*)( GPIOD_BASE_ADDRESS+ LCKR_OFFSET))
//#define GPIOD_AFRL		*((volatile u32*)( GPIOD_BASE_ADDRESS+ AFRL_OFFSET))
//#define GPIOD_AFRH		*((volatile u32*)( GPIOD_BASE_ADDRESS+ AFRH_OFFSET))
//
//
//
//#define GPIOE_MODER		*((volatile u32*)( GPIOE_BASE_ADDRESS+ MODER_OFFSET))
//#define GPIOE_ODR		*((volatile u32*)( GPIOE_BASE_ADDRESS+ ODR_OFFSET))
//#define GPIOE_IDR		*((volatile u32*)( GPIOE_BASE_ADDRESS+ IDR_OFFSET))
//#define GPIOE_OSPEEDR	*((volatile u32*)( GPIOE_BASE_ADDRESS+ OSPEEDR_OFFSET))
//#define GPIOE_OTYPER	*((volatile u32*)( GPIOE_BASE_ADDRESS+ OTYPER_OFFSET))
//#define GPIOE_PUPDR		*((volatile u32*)( GPIOE_BASE_ADDRESS+ PUPDR_OFFSET))
//#define GPIOE_BSRR		*((volatile u32*)( GPIOE_BASE_ADDRESS+ BSRR_OFFSET))
//#define GPIOE_LCKR		*((volatile u32*)( GPIOE_BASE_ADDRESS+ LCKR_OFFSET))
//#define GPIOE_AFRL		*((volatile u32*)( GPIOE_BASE_ADDRESS+ AFRL_OFFSET))
//#define GPIOE_AFRH		*((volatile u32*)( GPIOE_BASE_ADDRESS+ AFRH_OFFSET))
//
//
//
//#define GPIOH_MODER		*((volatile u32*)( GPIOH_BASE_ADDRESS+ MODER_OFFSET))
//#define GPIOH_ODR		*((volatile u32*)( GPIOH_BASE_ADDRESS+ ODR_OFFSET))
//#define GPIOH_IDR		*((volatile u32*)( GPIOH_BASE_ADDRESS+ IDR_OFFSET))
//#define GPIOH_OSPEEDR	*((volatile u32*)( GPIOH_BASE_ADDRESS+ OSPEEDR_OFFSET))
//#define GPIOH_OTYPER	*((volatile u32*)( GPIOH_BASE_ADDRESS+ OTYPER_OFFSET))
//#define GPIOH_PUPDR		*((volatile u32*)( GPIOH_BASE_ADDRESS+ PUPDR_OFFSET))
//#define GPIOH_BSRR		*((volatile u32*)( GPIOH_BASE_ADDRESS+ BSRR_OFFSET))
//#define GPIOH_LCKR		*((volatile u32*)( GPIOH_BASE_ADDRESS+ LCKR_OFFSET))
//#define GPIOH_AFRL		*((volatile u32*)( GPIOH_BASE_ADDRESS+ AFRL_OFFSET))
//#define GPIOH_AFRH		*((volatile u32*)( GPIOH_BASE_ADDRESS+ AFRH_OFFSET))
//









#endif
