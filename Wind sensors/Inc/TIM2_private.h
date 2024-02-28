/*
 * TIM2_private.h
 *
 *  Created on: Jan 9, 2024
 *      Author: SaadanyOmar
 */

#ifndef TIM2_PRIVATE_H_
#define TIM2_PRIVATE_H_


#define 	TIM2_BaseAddress 	0x40000000
typedef struct {
	u32   TIM2_CR1  ;
	u32   TIM2_CR2  ;
	u32   TIM2_SMCR ;
	u32   TIM2_DIER ;
	u32   TIM2_SR   ;
	u32   TIM2_EGR  ;
	u32   TIM2_CCMR1;
	u32   TIM2_CCMR2;
	u32   TIM2_CCER ;
	u32   TIM2_CNT  ;
	u32   TIM2_PSC  ;
	u32   TIM2_ARR  ;
	u32   Reserved  ;
	u32   TIM2_CCR1 ;
	u32   TIM2_CCR2 ;
	u32   TIM2_CCR3 ;
	u32   TIM2_CCR4 ;
	u32	  Reserved2 ;
	u32   TIM2_DCR  ;
	u32   TIM2_DMAR ;
}TIM2_Reg;


#define TIMER2	((volatile TIM2_Reg*)(TIM2_BaseAddress))




#endif /* TIM2_PRIVATE_H_ */
