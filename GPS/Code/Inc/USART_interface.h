/*
 * USART_interface.h
 *
 *  Created on: Oct 10, 2023
 *      Author: SaadanyOmar
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);
void USART_voidSendByte(u8 Data);
u8 USART_u8ReciveData(void);
void USART_enableTX(void);
void USART_enableRX(void);
void USART_voidSendString(u8 *  str);
void USART_StrReceiveString(u8 *LOCAL_STR);


#endif /* USART_INTERFACE_H_ */
