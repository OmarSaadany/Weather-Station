/*
 * GSM_program.c
 *
 *  Created on: Nov 8, 2023
 *      Author: SaadanyOmar
 */
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include    "RCC_interface.h"
#include    "RCC_private.h"
#include    "DIO_interface.h"
#include    "NVIC_interface.h"
#include    "AFIO_interface.h"
#include    "EXTI_interface.h"
#include    "USART3_interface.h"
#include    "USART_interface.h"
#include    "GSM_interface.h"
#include 	"SoilSensor.h"
#include 	"SHT.h"
#include 	"I2C_interface.h"
#include 	"ADC_interface.h"
#include 	"TIM3_interface.h"
#include 	"TIM2_interface.h"

u32 Angle=0;
u32 counter=0;

int main()
{
	RCC_voidSysClkInt();	//System Clock Init


	RCC_voidEnablePerClk(RCC_APB2,  AFIO);		//Enable RCC for Alternate Functions I/O
	RCC_voidEnablePerClk(RCC_APB2,  IOPA);		//Enable RCC for GPIOA
	RCC_voidEnablePerClk(RCC_APB2,  IOPB);		//Enable RCC for GPIOB
	RCC_voidEnablePerClk(RCC_APB2,  IOPC);		//Enable RCC for GPIOC
	RCC_voidEnablePerClk(RCC_APB1,  TIM2);		//Enable RCC for TIM2
	RCC_voidEnablePerClk(RCC_APB1,  TIM3);		//Enable RCC for TIM3


//	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_PULL_UP_DOWN);
//	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_INPUT_PULL_UP_DOWN);
	NVIC_voidInit();
	NVIC_voidEnablePerInt(28);
	TIM3_voidInit();
	TIM2_voidInit();
	while(1)
	{
//		_delay_ms(5000);
		Angle=TIM3_u32GetCounterValue()*6;
		counter=TIM2_u32GetCounterValue();
	}

	return 0;
}


