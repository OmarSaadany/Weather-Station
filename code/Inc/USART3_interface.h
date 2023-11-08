/*
 * USART_interface.h
 *
 *  Created on: Oct 10, 2023
 *      Author: SaadanyOmar
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_
/* Function:-			void  USART3_voidInit (void);
 * I/O Parameters:-		Void
 * Returns:- 			Void
 * Description:-
 * 		initializes the USART peripheral. regarding these parameters
 * 		1-Parity	2- Parity Type 	3- Data lenght 	4-Stop Bits 	5-Baud rate
 */
void USART3_voidInit(void);

/* Function:-			void  USART3_voidSendByte (u8 Data);
 * I/O Parameters:-		u8
 * Returns:- 			Void
 * Description:-
 * 		this function use USART to send byte through it
 */
void USART3_voidSendByte(u8 Data);

/* Function:-			void  USART3_u8ReciveData (u8 Data);
 * I/O Parameters:-		Void
 * Returns:- 			u8
 * Description:-
 * 		this function receives a byte of data from the USART peripheral and returns it.
 */
u8 	 USART3_u8ReciveData(void);

/* Function:-			void  USART3_enableTX (void);
 * I/O Parameters:-		Void
 * Returns:- 			Void
 * Description:-
 * 		enable transmitter
 */
void USART3_enableTX(void);

/* Function:-			void  USART3_enableRX (void);
 * I/O Parameters:-		Void
 * Returns:- 			Void
 * Description:-
 * 		enable receiver
 */
void USART3_enableRX(void);

/* Function:-			void  USART3_voidSendString (u8 *  str);
 * I/O Parameters:-		u8 *
 * Returns:- 			Void
 * Description:-
 * 		The function works by looping through the string until it reaches the end of the string
 * 		(the end of any string marked by the null character \0).
 * 		For each character in the string,
 * 		the function calls the USART3_voidSendByte() to send the character over the USART peripheral.
 */
void USART3_voidSendString(u8 *  str);

/* Function:-			void  USART3_voidReceiveString (u8 Data);
 * I/O Parameters:-		u8
 * Returns:- 			Void
 * Description:-
 * 		this function receives a string of data from the USART3 peripheral.
 * 		The function works by looping until it receives the null character (\0),
 * 		which marks the end of the string. For each character in the string,
 * 		the function calls the USART3_u8ReciveData() to receive the character
 * 		from the USART3 peripheral. The function then stores the character
 * 		in the string pointed to by the LOCAL_STR parameter.
 */
void USART3_voidReceiveString(u8 *LOCAL_STR);



#endif /* USART_INTERFACE_H_ */
