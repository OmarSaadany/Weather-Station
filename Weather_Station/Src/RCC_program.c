/*
 * 	RCC.c
 *
 *  Created on: Oct, 2023
 *      Author: SaadanyOmar
 */


#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"RCC_private.h"
#include	"RCC_config.h"




void		RCC_voidSysClkInt(void)
{
	#if (sysClk==sysClk_HSE)
		clr_bit(RCC->CR,16) 	;
		if (HSE_BYB==BYB_ON)
		{
			set_bit(RCC->CR,18) 	;
		}
		set_bit(RCC->CR,16) 	;
		while (get_bit(RCC->CR,17)==0);
//			set_bit(RCC_CR,16) 	;
		
		if (HSE_CSS==CSS_ON)
		{
			set_bit(RCC->CR,19) 	;
		}
	#elif (sysClk==sysClk_HSI)															
		set_bit(RCC->CR,0)		;
	while (get_bit(RCC->CR,1)!=1)
		set_bit(RCC->CR,0) 	;
	
	#elif (sysClk==sysClk_PLL)
		set_bit(RCC->CR,24)		;
	while (get_bit(RCC->CR,25)!=1)
			set_bit(RCC->CR,24) 	;
	#endif	
		
		
		
		
	#if (sysClkSelect==sysClkSelect_HSE)
		set_bit(RCC->CFGR,0)	;
		clr_bit(RCC->CFGR,1)	;
												
	#elif (sysClkSelect==sysClkSelect_HSI)		
		clr_bit(RCC->CFGR,0)	;
		clr_bit(RCC->CFGR,1)	;
			
	#elif (sysClkSelect==sysClkSelect_PLL)	
		clr_bit(RCC->CFGR,0)	;
		set_bit(RCC->CFGR,1)	;
	#endif		
		
		
		
	
	#if (AHB_pre==SYSCLK_divided_1)		
		clr_bit(RCC->CFGR,7)	;
												
	#elif (AHB_pre==SYSCLK_divided_2)
		set_bit(RCC->CFGR,7)	;
		clr_bit(RCC->CFGR,6)	;
		clr_bit(RCC->CFGR,5)	;
		clr_bit(RCC->CFGR,4)	;
												
	#elif (AHB_pre==SYSCLK_divided_4)
		set_bit(RCC->CFGR,7)	;
		clr_bit(RCC->CFGR,6)	;
		clr_bit(RCC->CFGR,5)	;
		set_bit(RCC->CFGR,4)	;
							
	#elif (AHB_pre==SYSCLK_divided_8)		
		set_bit(RCC->CFGR,7)	;
		clr_bit(RCC->CFGR,6)	;
		set_bit(RCC->CFGR,5)	;
		clr_bit(RCC->CFGR,4)	;
												
	#elif (AHB_pre==SYSCLK_divided_16)		
		set_bit(RCC->CFGR,7)	;
		clr_bit(RCC->CFGR,6)	;
		set_bit(RCC->CFGR,5)	;
		set_bit(RCC->CFGR,4)	;
												
	#elif (AHB_pre==SYSCLK_divided_64)		
		set_bit(RCC->CFGR,7)	;
		set_bit(RCC->CFGR,6)	;
		clr_bit(RCC->CFGR,5)	;
		clr_bit(RCC->CFGR,4)	;
												                 
	#elif (AHB_pre==SYSCLK_divided_128)		
		set_bit(RCC->CFGR,7)	;
		set_bit(RCC->CFGR,6)	;
		clr_bit(RCC->CFGR,5)	;
		set_bit(RCC->CFGR,4)	;
							
	#elif (AHB_pre==SYSCLK_divided_256)		
		set_bit(RCC->CFGR,7)	;
		set_bit(RCC->CFGR,6)	;
		set_bit(RCC->CFGR,5)	;
		clr_bit(RCC->CFGR,4)	;
												                 
	#elif (AHB_pre==SYSCLK_divided_512)		
		set_bit(RCC->CFGR,7)	;
		set_bit(RCC->CFGR,6)	;
		set_bit(RCC->CFGR,5)	;
		clr_bit(RCC->CFGR,4)	;
	#endif	
		
		
		
	#if (APB1_pre==HCLK_divided_1)
		clr_bit(RCC->CFGR,10);
												
	#elif (APB1_pre==HCLK_divided_2)
		clr_bit(RCC->CFGR,8)	;
		clr_bit(RCC->CFGR,9)	;
		set_bit(RCC->CFGR,10);
												
	#elif (APB1_pre==HCLK_divided_4)			
		set_bit(RCC->CFGR,8)	;
		clr_bit(RCC->CFGR,9)	;
		set_bit(RCC->CFGR,10);
												
	#elif (APB1_pre==HCLK_divided_8)
		clr_bit(RCC->CFGR,8)	;
		set_bit(RCC->CFGR,9)	;
		set_bit(RCC->CFGR,10);
												
	#elif (APB1_pre==HCLK_divided_16)		
		set_bit(RCC->CFGR,8)	;
		set_bit(RCC->CFGR,9)	;
		set_bit(RCC->CFGR,10);
	#endif
		
	

	
	#if (APB2_pre==HCLK_divided_1)			
		clr_bit(RCC->CFGR,10);
												
	#elif (APB2_pre==HCLK_divided_2)				
		clr_bit(RCC->CFGR,8)	;
		clr_bit(RCC->CFGR,9)	;
		set_bit(RCC->CFGR,10);
												
	#elif (APB2_pre==HCLK_divided_4)				
		set_bit(RCC->CFGR,8)	;
		clr_bit(RCC->CFGR,9)	;
		set_bit(RCC->CFGR,10);
		
	#elif (APB2_pre==HCLK_divided_8)				
		clr_bit(RCC->CFGR,8)	;
		set_bit(RCC->CFGR,9)	;
		set_bit(RCC->CFGR,10);
												
	#elif (APB2_pre==HCLK_divided_16)				
		set_bit(RCC->CFGR,8)	;
		set_bit(RCC->CFGR,9)	;
		set_bit(RCC->CFGR,10);
	#endif
	


	
	#if (ADC_pre==PCLK2_divided_2)
		clr_bit(RCC->CFGR,14)	;
		clr_bit(RCC->CFGR,15)	;
												
	#elif (ADC_pre==PCLK2_divided_4)			
		set_bit(RCC->CFGR,14)	;
		clr_bit(RCC->CFGR,15)	;
												
	#elif (ADC_pre==PCLK2_divided_6)		
		clr_bit(RCC->CFGR,14)	;
		set_bit(RCC->CFGR,15)	;
												
	#elif (ADC_pre==PCLK2_divided_8)	
		set_bit(RCC->CFGR,14)	;
		set_bit(RCC->CFGR,15)	;
									
	#endif
		
		
		
	#if (PLL_source==HSI_divided_2)
		clr_bit(RCC->CFGR,14)	;
												
	#elif (PLL_source==HSE)		
		set_bit(RCC->CFGR,14)	;
									
	#endif
	

	
	#if (PLL_HSE_divided==HSE_NODivided)
		clr_bit(RCC->CFGR,14)	;
												
	#elif (PLL_HSE_divided==HSE_divided_2)		
		set_bit(RCC->CFGR,14)	;
									
	#endif
	

	
	#if(AHB_pre==PLL_input_x4)	
		clr_bit(RCC->CFGR,18)	;
		set_bit(RCC->CFGR,19)	;
		clr_bit(RCC->CFGR,20)	;
		clr_bit(RCC->CFGR,21)	;
	
	#elif(AHB_pre==PLL_input_x5)		
			set_bit(RCC->CFGR,18)	;
			set_bit(RCC->CFGR,19)	;
			clr_bit(RCC->CFGR,20)	;
			clr_bit(RCC->CFGR,21)	;
	
	#elif(AHB_pre==PLL_input_x6)		
			clr_bit(RCC->CFGR,18)	;
			clr_bit(RCC->CFGR,19)	;
			set_bit(RCC->CFGR,20)	;
			clr_bit(RCC->CFGR,21)	;
							
	#elif(AHB_pre==PLL_input_x7)
		set_bit(RCC->CFGR,18)	;
		clr_bit(RCC->CFGR,19)	;
		set_bit(RCC->CFGR,20)	;
		clr_bit(RCC->CFGR,21)	;
												
	#elif(AHB_pre==PLL_input_x8)			
		clr_bit(RCC->CFGR,18)	;
		set_bit(RCC->CFGR,19)	;
		set_bit(RCC->CFGR,20)	;
		clr_bit(RCC->CFGR,21)	;
												
	#elif(AHB_pre==PLL_input_x9)
		set_bit(RCC->CFGR,18)	;
		set_bit(RCC->CFGR,19)	;
		set_bit(RCC->CFGR,20)	;
		clr_bit(RCC->CFGR,21)	;
												                 
	#elif(AHB_pre==PLL_input_x6&half)		
		set_bit(RCC->CFGR,18)	;
		clr_bit(RCC->CFGR,19)	;
		set_bit(RCC->CFGR,20)	;
		set_bit(RCC->CFGR,21)	;
	#endif
}





void		RCC_voidEnablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	set_bit(RCC->AHBENR	,PerId) ;	break;
			case	RCC_APB1	:	set_bit(RCC->APB1ENR,PerId)	;	break;
			case	RCC_APB2	:	set_bit(RCC->APB2ENR,PerId)	;	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}
	
}
void		RCC_voidDisablePerClk(u8 BusId , u8 PerId)
{
	/*		Range Check							*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case	RCC_AHB		:	clr_bit(RCC->AHBENR,PerId) ;	break;
			case	RCC_APB1	:	clr_bit(RCC->APB1ENR,PerId);	break;
			case	RCC_APB2	:	clr_bit(RCC->APB2ENR,PerId);	break;
		}
		
	}
	else{	/*	Return Error "Out Of The Range"		*/	}	
}
