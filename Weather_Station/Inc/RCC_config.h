/*
 *  RCC_config.h
 *
 *  Created on: Oct, 2023
 *      Author: SaadanyOmar
 */

#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H


#define 	sysClk				sysClk_HSI 						//		options
																/*	1- sysClk_HSE
																	2- sysClk_HSI
																	3- sysClk_PLL*/

#define 	HSE_BYB				BYB_ON						//		options
																/*	1- BYB_ON
																	2- BYB_Off*/

#define 	HSE_CSS				CSS_ON						//		options
																/*	1- CSS_ON
																	2- CSS_Off*/
 

#define 	sysState			sysState_HSE 					//		options 
																/*	1- sysState_HSE
																	2- sysState_HSI
																	3- sysState_PLL*/



#define 	sysClkSelect		sysClkSelect_HSE 				//		options 
																/*	1- sysClkSelect_HSE
																	2- sysClkSelect_HSI
																	3- sysClkSelect_PLL*/



#define 	AHB_pre				SYSCLK_divided_1				//		options 
																/*	1- SYSCLK_divided_1
																	2- SYSCLK_divided_2
																	3- SYSCLK_divided_4
																	4- SYSCLK_divided_8
																	5- SYSCLK_divided_16
																	6- SYSCLK_divided_64
																	7- SYSCLK_divided_128
																	8- SYSCLK_divided_256
																	9- SYSCLK_divided_512 */

#define 	APB1_pre			HCLK_divided_1					//		options 
																/*	1-HCLK_divided_1
																	2-HCLK_divided_2
																	3-HCLK_divided_4
																	4-HCLK_divided_8
																	5-HCLK_divided_16*/	

																	
#define 	APB2_pre			HCLK_divided_1					//		options 
																/*	1-HCLK_divided_1
																	2-HCLK_divided_2
																	3-HCLK_divided_4
																	4-HCLK_divided_8
																	5-HCLK_divided_16*/	
																	
#define 	ADC_pre				PCLK2_divided_2					//		options 
																/*	1-HCLK_divided_2
																	2-HCLK_divided_4
																	3-HCLK_divided_6
																	4-HCLK_divided_8*/	

#define 	PLL_source			HSI_divided_2					//		options 
																/*	1-HSI_divided_2
																	2-HSE*/


#define 	PLL_HSE_divided		HSE_NODivided					//		options 
																/*	1-HSE_NODivided
																	2-HSE_divided_2*/			

#define 	PLL_MUL				PLL_input_x4					//		options 
																/*	1- PLL_input_x4
																	2- PLL_input_x5
																	3- PLL_input_x6
																	4- PLL_input_x7
																	5- PLL_input_x8
																	6- PLL_input_x9
																	7- PLL_input_x6&half*/
#endif
