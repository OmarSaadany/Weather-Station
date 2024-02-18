/*
 * GSM_program.c
 *
 *  Created on: Nov 8, 2023
 *      Author: SaadanyOmar
 */
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include    "RCC_interface.h"
#include    "RCC_private.h"
#include    "DIO_interface.h"
#include    "AFIO_interface.h"
#include    "USART_interface.h"

u8 time[9];
u8 latitude[10];
u8 latitude_Indicator;
u8 longitude[11];
u8 longitude_Indicator;
u8 date[6];

int main()
{

	u8 GPS_Arr[100]={0};
	RCC_voidSysClkInt();	//System Clock Init


	RCC_voidEnablePerClk(RCC_APB2,  AFIO);		//Enable RCC for Alternate Functions I/O
	RCC_voidEnablePerClk(RCC_APB2,  IOPA);		//Enable RCC for GPIOA
	RCC_voidEnablePerClk(RCC_APB2,  USART1RCC);	//Enable RCC for USART1



	DIO_voidSetPinDirection(PORTA,PIN9,GPIO_OUTPUT_2MHZ_AFPP);		//Set Pin9  in PORTA as Output to use it as TX for USART1
	DIO_voidSetPinDirection(PORTA,PIN10,GPIO_INPUT_FLOAT);    		//Set Pin10 in PORTA as INPUT  to use it as RX for USART1






	USART_voidInit();		// Initialize USART3
	USART_enableRX();       // Enable USART3 Receive
	USART_enableTX();       // Enable USART3 Transmit
	u8 counter;
	u8 index;
	while(1)
	{
		while (!(GPS_Arr[1]=='G' && GPS_Arr[2]=='P'&& GPS_Arr[3]=='R' && GPS_Arr[4]=='M' && GPS_Arr[5]=='C'))//
		{
			while (GPS_Arr[0]!='$')
			{
				GPS_Arr[0]=USART_u8ReciveData();
			}

			GPS_Arr[1]=USART_u8ReciveData();
			GPS_Arr[2]=USART_u8ReciveData();
			GPS_Arr[3]=USART_u8ReciveData();
			GPS_Arr[4]=USART_u8ReciveData();
			GPS_Arr[5]=USART_u8ReciveData();
			GPS_Arr[0]=0;
		}
		counter=5;
		while (GPS_Arr[counter]!='\n')
		{
			counter++;
			GPS_Arr[counter]=USART_u8ReciveData();
		}



		//move to the next "," or next section
		counter=0;
		while (GPS_Arr[counter]!=',')
		{
			counter++;
		}
		//copy time from GPS array to time variable
		index =0;
		counter++;
		while (GPS_Arr[counter]!=',')
		{

			time[index]=GPS_Arr[counter];
			index ++;
			counter++;
		}
		counter++;
		if (GPS_Arr[counter]=='V')
		{
			for (u8 i=0;i>9;i++)
			{
				time[i]='\0';
			}
			for (u8 i=0;i<10;i++)
			{
				latitude[i]='\0';
			}
			for (u8 i=0;i<11;i++)
			{
				longitude[i]='\0';
			}
			for (u8 i=0;i<6;i++)
			{
				date[i]='\0';
			}
		}
		else if (GPS_Arr[counter]=='A')
		{
			while (GPS_Arr[counter]!=',')
			{
				counter++;
			}

			index =0;
			counter++;
			while (GPS_Arr[counter]!=',')
			{

				latitude[index]=GPS_Arr[counter];
				index ++;
				counter++;
			}
			counter++;
			latitude_Indicator=GPS_Arr[counter];
			counter+=2;
			index =0;
			while (GPS_Arr[counter]!=',')
			{

				longitude[index]=GPS_Arr[counter];
				index ++;
				counter++;
			}
			counter++;
			longitude_Indicator=GPS_Arr[counter];
			counter+=2;
			while (GPS_Arr[counter]!=',')
			{
				counter++;
			}
			counter+=2;
			index =0;
			while (GPS_Arr[counter]!=',')
			{

				date[index]=GPS_Arr[counter];
				index ++;
				counter++;
			}

		}
		for (u8 i=0; i<100; i++)
		{
			GPS_Arr[i]=0;
		}
	}

	return 0;
}
