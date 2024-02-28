/*
 * 	EXTI_interface.h
 *
 *  Created on: Oct, 2023
 *      Author: SaadanyOmar
 */


#ifndef EXTI_INTERFACE_
#define EXTI_INTERFACE_

#include "EXTI_private.h"

//void		EXTI_voidInit(void);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);

void		EXTI_voidSetCallBack(void (*Fptr)(void), u8 line_num);

//void		EXTI_voidSetCallBack(void (*Fptr)(void), EXTI_ID id);






#define   GPIO_PORTA        1
#define   GPIO_PORTB        2
#define   GPIO_PORTC        3

#define   IOC          0
#define   FALLING_EDGE 1
#define   RISING_EDGE  2


#endif

