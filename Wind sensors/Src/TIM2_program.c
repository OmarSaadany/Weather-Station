/*
 * TIM2_program.c
 *
 *  Created on: Jan 9, 2024
 *      Author: SaadanyOmar
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIM2_config.h"
#include "TIM2_interface.h"
#include "TIM2_private.h"



void TIM2_voidInit (void)
{
#if TIM2_Mode==TIM2_CounterMode

	clr_bit(TIMER2->TIM2_CR1,7);
	TIMER2->TIM2_CR1&=~(0b11<<5);
	clr_bit(TIMER2->TIM2_CR1,4);

	set_bit(TIMER2->TIM2_SMCR,14);
	clr_bit(TIMER2->TIM2_SMCR,15);
	TIMER2->TIM2_ARR=(TIM2_ReloadValue-1);

	set_bit(TIMER2->TIM2_CR1,0);		//CEN=’1’
#else
#endif
}

u32  TIM2_u32GetCounterValue (void)
{

	return TIMER2->TIM2_CNT;
}

