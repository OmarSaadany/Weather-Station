/*
 * USART_config.h
 *
 *  Created on: Oct 10, 2023
 *      Author: SaadanyOmar
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


/**
 * Configuration Parameters
 * 		1- Baud rate
 * 		2- Parity control
 * 		3- Parity selection
 * 		4- Stop bits
 */

#define BaudRateUSART_3 		9600
/**
 * Options
 * 		1- 115200
 * 		2- 9600
 */


/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
#define ParityUSART_3			DisableUSART_3
/*
 * options
 * 		1- Enable
 * 		2- Disable
 */


/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
#define ParityTypeUSART_3 		EvenUSART_3
/*
 * options
 * 		1- Odd
 * 		2- Even
 */


/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
#define StopBitsUSART_3 		OneStopBitUSART_3
/*
 * options
 * 		1- OneStopBit
 * 		2- TwoStopBits
 */

// Configuration Parameter
#define OneStopBitUSART_3		1
#define TwoStopBitsUSART_3		2

#define OddUSART_3				1
#define EvenUSART_3				2

#define EnableUSART_3			1
#define DisableUSART_3			2

#endif /* USART_CONFIG_H_ */
