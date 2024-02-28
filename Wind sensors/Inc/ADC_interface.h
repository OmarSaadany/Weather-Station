/*
 * ADC_interface.h
 *
 *  Created on: Dec 25, 2023
 *      Author: SaadanyOmar
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



void	ADC_void_Init(void);
void 	ADC_Enable(void);
void 	ADC_Start(void);
u16		ADC_u16_ReadChannel	(u8 Channel_ID);




#endif /* ADC_INTERFACE_H_ */
