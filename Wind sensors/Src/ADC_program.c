/*
 * ADC_program.c
 *
 *  Created on: Dec 25, 2023
 *      Author: SaadanyOmar
 */


#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include 	"RCC_interface.h"
#include 	"DIO_interface.h"

#include	"ADC_Config.h"
#include 	"ADC_private.h"
#include 	"ADC_interface.h"



void	ADC_void_Init(void)
{
	/* set scan mode */
	set_bit(ADC1->CR1,8);

	/* Set the Conversion Mode */
	#if (ADC_CONVERSION_MODE==ADC_SINGLE_CONVERSION_MODE)
	{
		/* Set Single Conversion Mode */
		clr_bit(ADC1->CR2,1);
	}
	#elif(ADC_CONVERSION_MODE==ADC_CONTINUOUS_CONVERSION_MODE)
	{
		/* Set Continuous Conversion Mode */
		set_bit(ADC1->CR2,1);
	}
	#endif

	/* External Event Select */
	ADC1->CR2 &=0xFFF1FFFF;
	ADC1->CR2 |=ADC_EXTERNAL_EVENT;


	/* Enable or Disable DMA */
	#if (ADC_DMA_ENABLE==DISABLE)
	{
		/* Disable DMA Mode */
		clr_bit(ADC1->CR2,8);

	}
	#elif(ADC_DMA_ENABLE==ENABLE)
	{
		/* Enable DMA Mode */
		set_bit(ADC1->CR2,8);
	}
	#endif


	/*Set Data Alignment Type */
	#if (ADC_DATA_ALIGNMENT==ADC_RIGHT_ALIGNMENT)
	{
		/*Set Right Data Alignment */
		clr_bit(ADC1->CR2,11);

	}
	#elif(ADC_DATA_ALIGNMENT==ADC_LEFT_ALIGNMENT)
	{
		/*Set Left Data Alignment */
		set_bit(ADC1->CR2,11);
	}
	#endif


	/* Set Channel X Sample Time */
	#if(ADC_CHANNEL<5)
	{
		ADC1->SMPR2 &=~((0b111)<<(ADC_CHANNEL*3));
		ADC1->SMPR2 |=~((ADC_CHANNEL_TIME_SELECTION)<<(ADC_CHANNEL*3));
	}
	#elif(ADC_CHANNEL<10)
	{
		ADC1->SMPR2 &=~((0b111)<<(16+(ADC_CHANNEL*3)));
		ADC1->SMPR2 |=~((ADC_CHANNEL_TIME_SELECTION)<<(16+(ADC_CHANNEL*3)));
	}
	#endif

	/* Set Continuous Conversion Mode */
	set_bit(ADC1->CR2 , 2);

	/* Start Conversion of Regular Channel */
	set_bit(ADC1->CR2,20);

	_delay_ms(10);

}


void 	ADC_Enable(void)
{
	set_bit(ADC1->CR2,0);
	_delay_ms(10);

}


void 	ADC_Disable(void)
{
	clr_bit(ADC1->CR2,0);
	_delay_ms(10);

}


void 	ADC_Start(void)
{
	/* Clear Status Register */
	ADC1->SR = 0;

	/* Start the Conversion of Regular Channel */
//	ADC1->CR2 |= 1<<22;
	set_bit(ADC1->CR2 , 22);


}



u16		ADC_u16_ReadChannel	(u8 Channel_ID)
{


	/* Return the ADC Reading */
	return ADC1->DR;

}
