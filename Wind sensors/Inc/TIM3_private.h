/*
 * TIM2_private.h
 *
 *  Created on: Jan 8, 2024
 *      Author: SaadanyOmar
 */

#ifndef TIM3_PRIVATE_H_
#define TIM3_PRIVATE_H_

#define 	TIM3_BaseAddress 	0x40000400
typedef struct {
	u32   TIM3_CR1  ;
	u32   TIM3_CR2  ;
	u32   TIM3_SMCR ;
	u32   TIM3_DIER ;
	u32   TIM3_SR   ;
	u32   TIM3_EGR  ;
	u32   TIM3_CCMR1;
	u32   TIM3_CCMR2;
	u32   TIM3_CCER ;
	u32   TIM3_CNT  ;
	u32   TIM3_PSC  ;
	u32   TIM3_ARR  ;
	u32   Reserved  ;
	u32   TIM3_CCR1 ;
	u32   TIM3_CCR2 ;
	u32   TIM3_CCR3 ;
	u32   TIM3_CCR4 ;
	u32	  Reserved2 ;
	u32   TIM3_DCR  ;
	u32   TIM3_DMAR ;
}TIM3_Reg;


#define TIMER3	((volatile TIM3_Reg*)(TIM3_BaseAddress))


#endif /* TIM3_PRIVATE_H_ */
