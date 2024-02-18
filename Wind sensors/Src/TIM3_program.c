/*
 * TIM2_program.c
 *
 *  Created on: Jan 8, 2024
 *      Author: SaadanyOmar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <TIM3_config.h>
#include <TIM3_interface.h>
#include <TIM3_private.h>



void TIM3_voidInit (void)
{
#if TIM3_Mode==TIM3_EncoderMode


	TIMER3->TIM3_CCMR1&=~(0b11<<0);
	TIMER3->TIM3_CCMR1|=(0b01<<0);		//CC1S=’01’

	TIMER3->TIM3_CCMR1&=~(0b11<<8);
	TIMER3->TIM3_CCMR1|=(0b01<<8);		//CC2S=’01’

	clr_bit(TIMER3->TIM3_CCER,1);		//CC1P=’0’			raising
	TIMER3->TIM3_CCMR1&=~(0b1111<<4);	//IC1F = ‘0000’

	clr_bit(TIMER3->TIM3_CCER,5);		//CC2P=’0’			raising
	TIMER3->TIM3_CCMR1&=~(0b1111<<12);	//IC1F = ‘0000’

	set_bit(TIMER3->TIM3_CCER,0);
	set_bit(TIMER3->TIM3_CCER,4);

	TIMER3->TIM3_SMCR&=~(0b111<<0);
	TIMER3->TIM3_SMCR|=(0b011<<0);		//SMS=’011’
	TIMER3->TIM3_ARR=(TIM3_ReloadValue-1);



//  interrupt enable
//	set_bit(TIMER3>TIM3_DIER,1);
//	set_bit(TIMER3->TIM3_DIER,2);



	set_bit(TIMER3->TIM3_CR1,0);		//CEN=’1’
#else
#endif
}

u32  TIM3_u32GetCounterValue (void)
{

	return TIMER3->TIM3_CNT;
}



