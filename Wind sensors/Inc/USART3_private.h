/*
 * USART_private.h
 *
 *  Created on: Oct 10, 2023
 *      Author: SaadanyOmar
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


// USART Base address in the memory (address of the first register)
#define USART3_Base_Address		0x40004800
// these values are calculated using the datasheet
#define USART3_BRRValue115200	0x45
#define USART3_BRRValue9600		0x341
#define USART3_BRRValue4800		0x683


// USART Registers
typedef struct
{
	u32 SR     ;
	u32 DR     ;
	u32 BRR    ;
	u32 CR1    ;
	u32 CR2    ;
	u32 CR3    ;
	u32 GPTR   ;
}USART3_Reg;
#define  USART3  ((volatile  USART3_Reg *)(USART3_Base_Address))

// BITS of Register SR
enum {
	SR_PE       ,
	SR_FE       ,
	SR_NE       ,
	SR_ORE      ,
	SR_IDLE     ,
	SR_RXNE     ,
	SR_TC       ,
	SR_TXE      ,
	SR_LBD      ,
	SR_CTS
}SR_Bits;

// BITS of Register CR1
enum {
	CR1_SBK     ,
	CR1_RWU     ,
	CR1_RE      ,
	CR1_TE      ,
	CR1_IDLEIE  ,
	CR1_RXNEIE  ,
	CR1_TCIE    ,
	CR1_TXEIE   ,
	CR1_PEIE    ,
	CR1_PS      ,
	CR1_PCE     ,
	CR1_WAKE    ,
	CR1_M       ,
	CR1_UE
}CR1_Bits;


// BITS of Register CR2
enum {
	CR2_STOP0=12,
	CR2_STOP1=13
}CR2_Bits;






#endif /* USART_PRIVATE_H_ */
