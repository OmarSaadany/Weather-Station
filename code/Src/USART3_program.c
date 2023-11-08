/*
 * USART_program.c
 *
 *  Created on: Oct 10, 2023
 *      Author: SaadanyOmar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "USART3_interface.h"
#include "USART3_private.h"
#include "USART3_config.h"



/* Function:-			void  USART3_voidInit (void);
 * I/O Parameters:-		Void
 * Returns:- 			Void
 * Description:-
 * 		initializes the USART peripheral. regarding these parameters
 * 		1-Parity	2- Parity Type 	3- Data lenght 	4-Stop Bits 	5-Baud rate
 */
void USART3_voidInit(void)
{

	// This section of code sets the baud rate for the USART peripheral.
	// The baud rate is determined by the value of the BaudRateUSART macro.
	// BRR value calculated regarding the datasheet
#if BaudRateUSART_3 == 115200
	USART3->BRR=USART3_BRRValue115200;
#elif BaudRateUSART_3 == 9600
	USART3->BRR=USART3_BRRValue9600;
#elif BaudRateUSART_3 == 4800
	USART3->BRR=USART3_BRRValue4800;
#endif

		clr_bit(USART3->CR1,CR1_M); // clr M  to make word length for the USART to 8 bits

		// this section enables or disables parity for the USART peripheral
#if ParityUSART_3 == EnableUSART_3
	set_bit(USART3->CR1, CR1_PCE);
#elif ParityUSART_3 == DisableUSART_3
	clr_bit(USART3->CR1, CR1_PCE);
#endif



	// This section of code sets the parity type for the USART to be even or odd
#if ParityTypeUSART_3 == OddUSART_3
	set_bit(USART3->CR1, CR1_PS);
#elif ParityTypeUSART_3 == EvenUSART_3
	clr_bit(USART3->CR1, CR1_PS);
#endif


	// This section of code sets the number of stop bits for the USART to be 1 or 2
#if StopBitsUSART_3 == OneStopBitUSART_3
	clr_bit(USART3->CR2, CR2_STOP0);
	clr_bit(USART3->CR2, CR2_STOP1);
#elif StopBitsUSART_3 == TwoStopBitsUSART_3
	clr_bit(USART3->CR2, CR2_STOP0);
	set_bit(USART3->CR2, CR2_STOP1);
#endif

	// This line of code enables the USART peripheral.
	set_bit(USART3->CR1, CR1_UE);
}





/* Function:-			void  USART3_enableTX (void);
 * I/O Parameters:-		Void
 * Returns:- 			Void
 * Description:-
 * 		enable transmitter
 */
void USART3_enableTX(void) {
	set_bit(USART3->CR1,CR1_TE); // set TE bit to enable transmitter
}


/* Function:-			void  USART3_enableRX (void);
 * I/O Parameters:-		Void
 * Returns:- 			Void
 * Description:-
 * 		enable receiver
 */
void USART3_enableRX(void) {
	set_bit(USART3->CR1,CR1_RE); // set RE bit to enable receiver
}



/* Function:-			void  USART3_voidSendByte (u8 Data);
 * I/O Parameters:-		u8
 * Returns:- 			Void
 * Description:-
 * 		this function use USART to send byte through it
 */
void USART3_voidSendByte(u8 ByteData)
{
// waits for the USART transmit buffer to be empty
	while (!get_bit(USART3->SR,SR_TXE)){asm("NOP");}
// This line writes the byte of data to the USART data register.
	USART3->DR=ByteData;
//	This while loop waits for the USART3 transmit complete flag to be set.
	while (!get_bit(USART3->SR,SR_TC)){asm("NOP");}
}



/* Function:-			void  USART3_voidSendString (u8 *  str);
 * I/O Parameters:-		u8 *
 * Returns:- 			Void
 * Description:-
 * 		The function works by looping through the string until it reaches the end of the string
 * 		(the end of any string marked by the null character \0).
 * 		For each character in the string,
 * 		the function calls the USART3_voidSendByte() to send the character over the USART peripheral.
 */
void USART3_voidSendString(u8 *  str)
{
	//The loop will continue to iterate while the character at the current position
	//in the string is not the null character \0
	while (*str != '\0'){
		//calls the USART3_voidSendByte() to send the char at the current position in the string
		USART3_voidSendByte(*str) ;
		//increments the pointer to the string,
		//so that the next iteration of the loop will look at the next character in the string.
		str ++ ;
	}
}




/* Function:-			void  USART3_u8ReciveData (u8 Data);
 * I/O Parameters:-		Void
 * Returns:- 			u8
 * Description:-
 * 		this function receives a byte of data from the USART peripheral and returns it.
 */
u8 USART3_u8ReciveData(void)
{	u8 USART3_Local_Data=0;
	u16 TimeOUT=0;
//The SR_RXNE bit is the receive data ready bit.
//It is set when there is a byte of data available in the USART3 receive buffer.
//The loop will continue to iterate while the SR_RXNE bit is not set.
	while (!get_bit(USART3->SR,SR_RXNE) && TimeOUT<65000 ) {
		TimeOUT++;
	}
//reads the byte of data from the USART3->DR register.
//This register contains the byte of data that was received from the USART peripheral.
	USART3_Local_Data=USART3->DR;
//Returns the received byte of data.
	return USART3_Local_Data;
}




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
void USART3_voidReceiveString(u8 * LOCAL_STR)
{
	do{
		//Call the USART3_u8ReciveData() function to receive a byte of data from the USART3 peripheral.
		//The received byte of data is stored in the character pointed to by the LOCAL_STR parameter.
		*LOCAL_STR=USART3_u8ReciveData() ;
		// increments the pointer to the string,
		// so that the next iteration of the loop will store the next character in the string.
		LOCAL_STR ++ ;
		//The loop will continue to iterate until it receives the null character (\0),
		//which marks the end of the string.
	} while (*(LOCAL_STR-1) != '\000');

}
