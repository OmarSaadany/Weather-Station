/*
 * 	RCC_private.h
 *
 *  Created on: Oct, 2023
 *      Author: SaadanyOmar
 */


#ifndef		RCC_PRIVATE_H
#define		RCC_PRIVATE_H

#define		RCC_BASE_ADD		(0x40021000)

typedef struct
{
	u32 CR		 ;
	u32 CFGR	 ;
	u32 CIR		 ;
	u32 APB2RSTR ;
	u32 APB1RSTR ;
	u32 AHBENR	 ;
	u32 APB2ENR	 ;
	u32 APB1ENR	 ;
	u32 BDCR	 ;
	u32 CSR		 ;

}RCC_Reg;

#define RCC 		((volatile RCC_Reg*)(RCC_BASE_ADD))


#define		sysClkSelect_HSE			1
#define     sysClkSelect_HSI			2
#define     sysClkSelect_PLL			3

#define		SYSCLK_divided_1		1
#define     SYSCLK_divided_2		2
#define     SYSCLK_divided_4		3
#define		SYSCLK_divided_8		4
#define     SYSCLK_divided_16		5
#define     SYSCLK_divided_64		6
#define		SYSCLK_divided_128		7
#define     SYSCLK_divided_256		8
#define     SYSCLK_divided_512		9

#define		HCLK_divided_1			1
#define     HCLK_divided_2			2
#define     HCLK_divided_4			3
#define		HCLK_divided_8			4
#define     HCLK_divided_16			5
#define     HCLK_divided_6			6

#define		HSI_divided_2			1
#define     HSE						2

#define		HSE_NODivided			1
#define     HSE_divided_2			2

#define		PLL_input_x4			1
#define     PLL_input_x5			2
#define     PLL_input_x6			3
#define		PLL_input_x7			4
#define     PLL_input_x8			5
#define     PLL_input_x9			6


#define		sysClk_HSE				1
#define     sysClk_HSI				2
#define     sysClk_PLL				3

#define		sysState_HSE			1
#define     sysState_HSI			2
#define     sysState_PLL			3

#define		BYB_ON					1
#define     BYB_Off					2


#define		CSS_ON					1
#define     CSS_Off					2

typedef enum{
	AFIO = 0,
	IOPA =2 ,
	IOPB ,
	IOPC ,
	IOPD ,
	IOPE ,
	IOPF ,
	IOPG ,
	ADC1 ,
	ADC2 ,
	TIM1 ,
	SPI1 ,
	TIM8 ,
	USART1RCC,
	ADC3,
	TIM9=19,
	TIM10,
	TIM11
}APB2RSTR;


typedef enum{
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDG=11,
	SPI2=14,
	SPI3,
	USART2=17,
	USART3,
	USART4,
	USART5,
	I2C1RCC,
	I2C2RCC,
	USB,
	CAN=25,
	BKP=27,
	PWR,
	DAC
}APB1RSTR;


typedef enum{
	DMA1=0,
	DMA2,
	SRAM,
	FLITF=4,
	CRC=6,
	FSMC=8,
	SDIO=10

}AHBENR;

//typedef enum{
//	AFIO = 0,
//	IOPA =2 ,
//	IOPB ,
//	IOPC ,
//	IOPD ,
//	IOPE ,
//	IOPF ,
//	IOPG ,
//	ADC1 ,
//	ADC2 ,
//	TIM1 ,
//	SPI1 ,
//	TIM8 ,
//	USART1,
//	ADC3,
//	TIM9=19,
//	TIM10,
//	TIM11
//
//}APB2ENR;
//
//
//
//typedef enum{
//	TIM2=0,
//	TIM3,
//	TIM4,
//	TIM5,
//	TIM6,
//	TIM7,
//	TIM12,
//	TIM13,
//	TIM14,
//	WWDG=11,
//	SPI2=14,
//	SPI3,
//	USART2=17,
//	USART3,
//	USART4,
//	USART5,
//	I2C1,
//	I2C2,
//	USB,
//	CAN=25,
//	BKP=27,
//	PWR,
//	DAC
//
//}APB1ENR;
//

#endif
