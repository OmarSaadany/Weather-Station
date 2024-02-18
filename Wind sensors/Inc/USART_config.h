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

#define BaudRate 		4800
/**
 * Options
 * 		1- 115200
 * 		2- 9600
 */


/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
#define Parity			Disable
/*
 * options
 * 		1- Enable
 * 		2- Disable
 */


/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
#define ParityType 		Even
/*
 * options
 * 		1- Odd
 * 		2- Even
 */


/******************************************************************************************/
/******************************************************************************************/
/******************************************************************************************/
#define StopBits 		OneStopBit
/*
 * options
 * 		1- OneStopBit
 * 		2- TwoStopBits
 */


#define OneStopBit		1
#define TwoStopBits		2

#define Odd				1
#define Even			2

#define Enable			1
#define Disable			2

#define EnableTransmitInterrupt	0
#define EnableRecieveInterrupt	0

#endif /* USART_CONFIG_H_ */
