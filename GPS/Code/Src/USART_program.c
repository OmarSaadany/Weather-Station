/*
 * USART_program.c
 *
 *  Created on: Oct 10, 2023
 *      Author: SaadanyOmar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"




void USART_voidInit(void)
{
#if BaudRate == 115200
	USART1->BRR=0x45;
#elif BaudRate == 9600
	USART1->BRR=0x341;
#elif BaudRate == 4800
	USART1->BRR=0x683;
#elif BaudRate == 19200
	USART1->BRR=0x1A0;
#endif
	clr_bit(USART1->CR1,12); // M bit for size

#if Parity == Enable
	set_bit(USART1->CR1, 10);
#elif Parity == Disable
	clr_bit(USART1->CR1, 10);
#endif




#if ParityType == Odd
	set_bit(USART1->CR1, 9);
#elif ParityType == Even
	clr_bit(USART1->CR1, 9);

#endif



#if StopBits == OneStopBit
	clr_bit(USART1->CR2, 12);
	clr_bit(USART1->CR2, 13);
#elif StopBits == TwoStopBits
	clr_bit(USART1->CR2, 12);
	set_bit(USART1->CR2, 13);


#endif

#if EnableRecieveInterrupt== 1
	set_bit(USART1->CR1, 5);
#else
	clr_bit(USART1->CR1, 5);
#endif

	set_bit(USART1->CR1, 13); // UE ---> Enable

	USART_enableRX();
	USART_enableTX();


}

//enable transmitter
void USART_enableTX(void) {
	set_bit(USART1->CR1,3); // TE
}
//enable receiver
void USART_enableRX(void) {
	set_bit(USART1->CR1,2); // RE
}




void USART_voidSendByte(u8 Data)
{

	while (!get_bit(USART1->SR,7))
	{
		asm("NOP");
	}

	USART1->DR=Data;

	while (!get_bit(USART1->SR,6));
}



void USART_voidSendString(u8 *  str)
{
	while (*str != '\0'){
		USART_voidSendByte(*str) ;
		str ++ ;
	}
}




u8 USART_u8ReciveData(void)
{
	u8 Local_Data=0;
	while (!get_bit(USART1->SR,5))
	{
		asm("NOP");
	}
	Local_Data=USART1->DR;
	return Local_Data;
}





void USART_StrReceiveString(u8 * LOCAL_STR)
{
	while (*LOCAL_STR != '\0'){
		*LOCAL_STR=USART_u8ReciveData() ;
		LOCAL_STR ++ ;
	}
}
//
//volatile void USART_u8ReciveData_Interrupt(void){
//	//USART1_RECIEVED_DATA = USART1->DR;
//}
//
//extern u8 USART1_RECIEVED_DATA ;
//void USART1_IRQHandler(void)
//{
//	USART1_RECIEVED_DATA = USART1->DR;
//}
