/*
 * AFIO_program.c
 *
 *  Created on: Oct 9, 2023
 *      Author: SaadanyOmar
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"
#include "DIO_interface.h"



/* Function:-			void  AFIO_voidRemap (void);
 * I/O Parameters:-		Void
 * Returns:- 			Void
 * Description:-
 * 		used to Remap peripheral's Pins
 */
void AFIO_voidRemap(void)
{
#if 		SPI1Remap==Remap
	set_bit(AFIO->MAPR, 0); 		//Set PIN 0 in MAPR Register to Remap SPI1 Peripheral
#elif 		SPI1Remap==NORemap
	clr_bit(AFIO->MAPR, 0);			//clr PIN 0 in MAPR Register to use the default PINS for SPI1 Peripheral
#endif

#if			I2C1Remap==Remap
	set_bit(AFIO->MAPR, 1);			//Set PIN 1 in MAPR Register to Remap I2C1 Peripheral
#elif 		I2C1Remap==NORemap
	clr_bit(AFIO->MAPR, 1);			//clr PIN 1 in MAPR Register to use the default PINS for I2C1 Peripheral
#endif

#if			USART1Remap==Remap
	set_bit(AFIO->MAPR, 2);			//Set PIN 2 in MAPR Register to Remap USART1 Peripheral
#elif 		USART1Remap==NORemap
	clr_bit(AFIO->MAPR, 2);			//clr PIN 2 in MAPR Register to use the default PINS for USART1 Peripheral
#endif

#if			USART2Remap==Remap
	set_bit(AFIO->MAPR, 3);			//Set PIN 3 in MAPR Register to Remap USART2 Peripheral
#elif 		USART2Remap==NORemap
	clr_bit(AFIO->MAPR, 3);			//clr PIN 3 in MAPR Register to use the default PINS for USART2 Peripheral
#endif

#if			USART3Remap==Remap
	clr_bit(AFIO->MAPR, 5);			//clr PIN 5 in MAPR Register to Remap USART3 Peripheral
	set_bit(AFIO->MAPR, 4);			//Set PIN 4 in MAPR Register to Remap USART3 Peripheral

#elif 		USART3Remap==NORemap
	clr_bit(AFIO->MAPR, 5);         //clr PIN 5 in MAPR Register to use the default PINS for  USART3 Peripheral
	clr_bit(AFIO->MAPR, 4);         //Set PIN 4 in MAPR Register to use the default PINS for USART3 Peripheral
#endif

#if			TIM1Remap==Remap
	clr_bit(AFIO->MAPR, 7);         //clr PIN 7 in MAPR Register to Remap TIM1 Peripheral
	set_bit(AFIO->MAPR, 6);         //Set PIN 6 in MAPR Register to Remap TIM1 Peripheral
#elif 		TIM1Remap==NORemap
	clr_bit(AFIO->MAPR, 7);         //clr PIN 7 in MAPR Register to use the default PINS for TIM1 Peripheral
	clr_bit(AFIO->MAPR, 6);         //Set PIN 6 in MAPR Register to use the default PINS for TIM1 Peripheral
#endif

#if			TIM2Remap==Remap
	set_bit(AFIO->MAPR, 9);         //set PIN 9 in MAPR Register to Remap TIM2 Peripheral
	clr_bit(AFIO->MAPR, 8);         //clr PIN 8 in MAPR Register to Remap TIM2 Peripheral
#elif 		TIM2Remap==NORemap
	clr_bit(AFIO->MAPR, 9);         //set PIN 9 in MAPR Register to use the default PINS for TIM2 Peripheral
	clr_bit(AFIO->MAPR, 8);         //clr PIN 8 in MAPR Register to use the default PINS for TIM2 Peripheral
#endif

#if			TIM3Remap==Remap
	clr_bit(AFIO->MAPR, 10);        //clr PIN 10 in MAPR Register to Remap TIM3 Peripheral
	set_bit(AFIO->MAPR, 11);        //Set PIN 11 in MAPR Register to Remap TIM3 Peripheral
#elif 		TIM3Remap==NORemap
	clr_bit(AFIO->MAPR, 10);        //set PIN 10 in MAPR Register to use the default PINS for TIM2 Peripheral
	clr_bit(AFIO->MAPR, 11);        //clr PIN 11 in MAPR Register to use the default PINS for TIM2 Peripheral
#endif
}


/* Function:-			void AFIO_voidsetEXTIAltFunc(u8 PORT, u8 pin);
 * I/O Parameters:-		u8, u8
 * Returns:- 			Void
 * Description:-
 * 		initializes DIO pins to be use as EXTI
 */
void		AFIO_voidsetEXTIAltFunc(u8 PORT, u8 pin)
{

	/* General Note: -
	 *		 1- Registers EXTICR 1-->4 is 32 word size and from bit 16 to 31 is reserved so we could access only 16 BITs
	 *		 3- Each Port Contains 16 DIO pins
	 *		 4- there are 7 PORTS. A,B,C,D,E,F and G.
	 *		 2- Registers and PINS
	 *		 			-use EXTICR1 for PINs 0:3
	 *		 			-use EXTICR2 for PINs 4:7
	 *		 			-use EXTICR3 for PINs 8:11
	 *		 			-use EXTICR4 for PINs 12:15
	 *		 3- Each register configure 4 pins .... and each pin needs 4 BITS to be configured are the accessed BITS are 16 (4 Pins* 4 BITS for each)
	 *		 4- for each PIN between 0 to 15 there are 4 specific bits and you can choose the port of this PIN to be EXTI pin
	 *		 write these values in each PIN field(4BITS) to select the needed PORT
	 *		         -0000: PA
	 *		         -0001: PB
	 *		         -0010: PC
	 *		         -0011: PD
	 *		         -0100: PE
	 *		         -0101: PF
	 *		         -0110: PG
	 *
	 */

	// if pin less than or equal 3 use EXTICR1 register (0,1,2 and 3)
	if (pin <=3)
	{
		switch (PORT)
		{

		case 	PORTA:	AFIO->EXTICR1&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						break;									 // Do nothing but clear in case if PORTA as its value = 0b0000

		case 	PORTB:	AFIO->EXTICR1&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						AFIO->EXTICR1|=((0b00000001)<<(pin*4));	 // write in these 4 bits the value of PORTB which is = 0b0001
						break;

		case 	PORTC:	AFIO->EXTICR1&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						AFIO->EXTICR1|=((0b00000010)<<(pin*4));	 // write in these 4 bits the value of PORTC which is = 0b0010
						break;

		}
	}

	// if pin more than 3 and less or equal 7 use EXTICR2 register
	else if (pin <=7)
	{
		pin-=4;
		switch (PORT)
		{
		case 	PORTA:	AFIO->EXTICR2&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						break;                                   // Do nothing but clear in case if PORTA as its value = 0b0000

		case 	PORTB:	AFIO->EXTICR2&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						AFIO->EXTICR2|=((0b00000001)<<(pin*4));	 // write in these 4 bits the value of PORTB which is = 0b0001
						break;

		case 	PORTC:	AFIO->EXTICR2&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						AFIO->EXTICR2|=((0b00000010)<<(pin*4));	 // write in these 4 bits the value of PORTC which is = 0b0010
						break;


		}

	}
	// if pin more than 7 and less or equal 11 use EXTICR3 register
	else if (pin <=11)
	{
		pin-=8;
		switch (PORT)
		{
		case 	PORTA:	AFIO->EXTICR3&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						break;                                   // Do nothing but clear in case if PORTA as its value = 0b0000

		case 	PORTB:	AFIO->EXTICR3&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						AFIO->EXTICR3|=((0b00000001)<<(pin*4));	 // write in these 4 bits the value of PORTB which is = 0b0001
						break;

		case 	PORTC:	AFIO->EXTICR3&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						AFIO->EXTICR3|=((0b00000010)<<(pin*4));	 // write in these 4 bits the value of PORTC which is = 0b0010
						break;


		}

	}
	// if pin more than 11 and less or equal 15 use EXTICR4 register
	else if (pin <=15)
	{
		pin-=12;
		switch (PORT)
		{
		case 	PORTA:	AFIO->EXTICR4&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						break;                                   // Do nothing but clear in case if PORTA as its value = 0b0000

		case 	PORTB:	AFIO->EXTICR4&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						AFIO->EXTICR4|=((0b00000001)<<(pin*4));	 // write in these 4 bits the value of PORTB which is = 0b0001
						break;

		case 	PORTC:	AFIO->EXTICR4&=~((0b00001111)<<(pin*4)); // CLR 4 bit .... these 4 bits shifted left by PIN index
						AFIO->EXTICR4|=((0b00000010)<<(pin*4));	 // write in these 4 bits the value of PORTC which is = 0b0010
						break;


		}

	}
}
