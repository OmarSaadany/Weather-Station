/*
 * 	EXTI_private.h
 *
 *  Created on: Oct, 2023
 *      Author: SaadanyOmar
 */


#ifndef EXTI_PRIVATE_
#define EXTI_PRIVATE_





#define		EXTI_BASE_ADD			0x40010400


typedef struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define			EXTI				((EXTI_Type *)(EXTI_BASE_ADD))

typedef enum{
    EXTI0 = 0,
    EXTI1 ,
    EXTI2 ,
    EXTI3 ,
    EXTI4 ,
    EXTI5 ,
    EXTI6 ,
    EXTI7 ,
    EXTI8 ,
    EXTI9 ,
    EXTI10,
    EXTI11,
    EXTI12,
    EXTI13,
    EXTI14,
    EXTI15
}EXTI_ID;









#endif
