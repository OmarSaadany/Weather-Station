/*
 * AFIO_private.h
 *
 *  Created on: Oct 9, 2023
 *      Author: SaadanyOmar
 */
#ifndef AFIO_PRIVATE_H_
#define AFIO_PRIVATE_H_

#define AFIO_BaseAddress		0x40010000			// base address of AFIO Registers

// AFIO registers
typedef struct {
	u32 EVCR;
	u32 MAPR;
	u32 EXTICR1;
	u32 EXTICR2;
	u32 EXTICR3;
	u32 EXTICR4;
	u32 MAPR2;
}AFIO_Reg;
#define AFIO	((volatile AFIO_Reg*)(AFIO_BaseAddress))



#define Remap		1
#define NoRemap		0

#endif /* AFIO_PRIVATE_H_ */
