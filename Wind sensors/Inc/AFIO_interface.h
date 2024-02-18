/*
 * AFIO_interface.h
 *
 *  Created on: Oct 9, 2023
 *      Author: SaadanyOmar
 */
#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_
#include "STD_TYPES.h"


/* Function:-			void AFIO_voidsetEXTIAltFunc(u8 PORT, u8 pin);
 * I/O Parameters:-		u8, u8
 * Returns:- 			Void
 * Description:-
 * 		initializes DIO pins to be use as EXTI
 */
void AFIO_voidRemap(void);


/* Function:-			void AFIO_voidsetEXTIAltFunc(u8 PORT, u8 pin);
 * I/O Parameters:-		u8, u8
 * Returns:- 			Void
 * Description:-
 * 		initializes DIO pins to be use as EXTI
 */
void		AFIO_voidsetEXTIAltFunc(u8 port, u8 line_num);



#endif /* AFIO_INTERFACE_H_ */
