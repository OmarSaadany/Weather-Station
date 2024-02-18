/*
 * 	DIO_private.h
 *
 *  Created on: Oct, 2023
 *      Author: SaadanyOmar
 */


#ifndef		DIO_PRIVATE_H
#define		DIO_PRIVATE_H

/**********************************************************************************
	-----> Macros
			*  Base_Address GPI0X
************************************************************************************/
#define  AFIO_BASE_ADDRESS						(0x40010000)

#define  GPIOA_BASE_ADDRESS						(0x40010800)
#define  GPIOB_BASE_ADDRESS						(0x40010C00)
#define  GPIOC_BASE_ADDRESS						(0x40011000)
#define  GPIOD_BASE_ADDRESS						(0x40011400)
#define  GPIOE_BASE_ADDRESS						(0x40011800)
#define  GPIOF_BASE_ADDRESS						(0x40011C00)
#define  GPIOG_BASE_ADDRESS						(0x40012000)


/***********************************************************************************
	-----> Macros
			  *  Register Map	 GPIO_A
************************************************************************************/

typedef struct{
	u32 CRL; //Port configuration register low
	u32 CRH; //Port configuration register high
	u32 IDR; //Port input data register
	u32 ODR; //Port output data register
	u32 BSRR;//Port bit set/reset register
	u32 BRR; //Port bit reset register
	u32 LCKR;//Port configuration lock register
}GPIO_REGISTERS;

/* the following are pointers to GPIO_Registers structure
 * */
#define  GPIOA  			((volatile  GPIO_REGISTERS *)(GPIOA_BASE_ADDRESS))
#define  GPIOB  			((volatile  GPIO_REGISTERS *)(GPIOB_BASE_ADDRESS))
#define  GPIOC  			((volatile  GPIO_REGISTERS *)(GPIOC_BASE_ADDRESS))
#define  GPIOD  			((volatile  GPIO_REGISTERS *)(GPIOD_BASE_ADDRESS))
#define  GPIOE  			((volatile  GPIO_REGISTERS *)(GPIOE_BASE_ADDRESS))
#define  GPIOF  			((volatile  GPIO_REGISTERS *)(GPIOF_BASE_ADDRESS))
#define  GPIOG  			((volatile  GPIO_REGISTERS *)(GPIOG_BASE_ADDRESS))



#define 	GPIOA_set_pin		GPIOA->BSRR= (1<<pin)
#define 	GPIOA_clr_pin 		GPIOA->BRR = (1<<pin)

#define 	GPIOB_set_pin		GPIOB->BSRR= (1<<pin)
#define 	GPIOB_clr_pin 		GPIOB->BRR = (1<<pin)

#define 	GPIOC_set_pin		GPIOC->BSRR= (1<<pin)
#define 	GPIOC_clr_pin 		GPIOC->BRR = (1<<pin)
#endif
