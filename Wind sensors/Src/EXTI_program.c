/*
 * 	EXTI.c
 *
 *  Created on: Oct, 2023
 *      Author: SaadanyOmar
 */

#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"EXTI_interface.h"
#include	"EXTI_private.h"



#ifndef		NULL
#define		NULL			((void *)0)
#endif


volatile	void	(*EXTI_CallBack[10])	(void)	=
 {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};







void		EXTI_voidEnableInt(u8 line_num)
{
	set_bit(EXTI -> IMR,line_num);
}


void		EXTI_voidDisableInt(u8 line_num)
{
	clr_bit(EXTI -> IMR ,line_num);
}




void		EXTI_voidEnableSWI(u8 line_num)
{
	set_bit(EXTI -> SWIER,line_num);
}



void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	set_bit(EXTI -> RTSR,line_num);
									clr_bit(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	set_bit(EXTI -> FTSR,line_num);
									clr_bit(EXTI -> RTSR,line_num);		break;
		case	IOC				:	set_bit(EXTI -> RTSR,line_num);
									set_bit(EXTI -> FTSR,line_num);		break;
	}
	set_bit(EXTI -> IMR,line_num);
}



void		EXTI_voidSetCallBack(void (*Fptr)(void), u8 line_num)
{
	if(Fptr != NULL)
	{

		EXTI_CallBack[line_num] = Fptr;
	}
}




void EXTI0_IRQHandler(void)
{
	if(EXTI_CallBack[EXTI0] != NULL)
	 {
		 EXTI_CallBack[EXTI0]();
	 }
	set_bit(EXTI -> PR, EXTI0);
}


void EXTI1_IRQHandler(void)
{
	if(EXTI_CallBack[EXTI1] != NULL)
	 {
		 EXTI_CallBack[EXTI1]();
	 }
	set_bit(EXTI -> PR, EXTI1);
}


void EXTI2_IRQHandler(void)
{
	if(EXTI_CallBack[EXTI2] != NULL)
	 {
		 EXTI_CallBack[EXTI2]();
	 }
	set_bit(EXTI -> PR, EXTI2);
}


void EXTI3_IRQHandler(void)
{
	if(EXTI_CallBack[EXTI3] != NULL)
	 {
		 EXTI_CallBack[EXTI3]();
	 }
	set_bit(EXTI -> PR, EXTI3);
}


void EXTI9_5_IRQHandler(void)
{
	if(EXTI_CallBack[EXTI5] != NULL)
	 {
		 EXTI_CallBack[EXTI5]();
		 set_bit(EXTI -> PR, EXTI5);
	 }
	 if(EXTI_CallBack[EXTI6] != NULL)
	 {
		 EXTI_CallBack[EXTI6]();
		 set_bit(EXTI -> PR, EXTI6);
	 }
	 if(EXTI_CallBack[EXTI7] != NULL)
	 {
		 EXTI_CallBack[EXTI7]();
		 set_bit(EXTI -> PR, EXTI7);
	 }
	 if(EXTI_CallBack[EXTI8] != NULL)
	 {
	 	 EXTI_CallBack[EXTI8]();
	 	 set_bit(EXTI -> PR, EXTI8);
	  }
	 if(EXTI_CallBack[EXTI9] != NULL)
	 {
		 EXTI_CallBack[EXTI9]();
		 set_bit(EXTI -> PR, EXTI9);
	 }

}

