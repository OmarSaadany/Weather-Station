/*
 * USART_private.h
 *
 *  Created on: Oct 10, 2023
 *      Author: SaadanyOmar
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define USART_Base_Address		0x40013800

#define USART_BRRValue115200	0x45
#define USART_BRRValue9600		0x341
#define USART_BRRValue4800		0x683
typedef struct
{
	u32 SR     ;
	u32 DR     ;
	u32 BRR    ;
	u32 CR1    ;
	u32 CR2    ;
	u32 CR3    ;
	u32 GPTR   ;
}USART_Reg;


#define  USART1  ((volatile  USART_Reg *)(USART_Base_Address))
#endif /* USART_PRIVATE_H_ */
