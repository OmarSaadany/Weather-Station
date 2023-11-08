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
#include    "NVIC_interface.h"
#include    "AFIO_interface.h"
#include    "EXTI_interface.h"
#include    "USART_interface.h"
#include    "USART3_interface.h"
#include    "GSM_interface.h"
#include 	"SoilSensor.h"

/* Function:-			void  DoorStatusUpdate (void);
 * I/O Parameters:-		Void
 * Returns:- 			Void
 * Description:-
 * 		this is a function called when EXTI pin fires an interrupt to update DOOR Status
 */
void DoorStatusUpdate (void);

u8		 	GSMSTATUS[25]; 	// used to receive GSM respond after uploading data to reconnect to the network if the upload failed
u8	 		GSMTimeOut=0;	// time out used to detect if the GSM did not respond to prevent the CPU to stuck in Receiving function

volatile u8 DoorStatus[6]="Closed"; // initial Status of the door


int main()
{
	RCC_voidSysClkInt();	//System Clock Init


	RCC_voidEnablePerClk(RCC_APB2,  AFIO);		//Enable RCC for Alternate Functions I/O
	RCC_voidEnablePerClk(RCC_APB2,  IOPA);		//Enable RCC for GPIOA
	RCC_voidEnablePerClk(RCC_APB2,  IOPB);		//Enable RCC for GPIOB
	RCC_voidEnablePerClk(RCC_APB2,  USART1RCC);	//Enable RCC for USART1
	RCC_voidEnablePerClk(RCC_APB1,  USART3);	//Enable RCC for USART3


	DIO_voidSetPinDirection(PORTB,PIN10,GPIO_OUTPUT_2MHZ_AFPP);		//Set Pin10 in PORTB as Output to use it as TX for USART3
	DIO_voidSetPinDirection(PORTB,PIN11,GPIO_INPUT_FLOAT);			//Set Pin11 in PORTB as INPUT  to use it as RX for USART3


	DIO_voidSetPinDirection(PORTA,PIN9,GPIO_OUTPUT_2MHZ_AFPP);		//Set Pin9  in PORTA as Output to use it as TX for USART1
	DIO_voidSetPinDirection(PORTA,PIN10,GPIO_INPUT_FLOAT);    		//Set Pin10 in PORTA as INPUT  to use it as RX for USART1


	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_PULL_UP_DOWN); 	//Set Pin0  in PORTA as INPUT to use it as EXTI
	DIO_voidSetPinValue(PORTA, PIN0, GPIO_HIGH); 					//Set Pin0  in PORTA as Pull Up


	NVIC_voidInit();									//Interrupt Initialization
	AFIO_voidsetEXTIAltFunc(PORTA, PIN0);				//Set Pin 0 in PORTA as EXTI
	EXTI_voidEnableInt(EXTI0);							//Enable EXTI0 channel
	EXTI_voidChangeSenseMode(EXTI0, IOC);				//Set Sensitive mode to be On Change
	NVIC_voidEnablePerInt(6);       					//NVIC  EXTI0 Enable
	EXTI_voidSetCallBack(DoorStatusUpdate 	, EXTI0); 	//Call (DoorStatusUpdate) When the interrupt fired


	USART3_voidInit(); 		// Initialize USART3
	USART3_enableRX();		// Enable USART3 Receive
	USART3_enableTX();		// Enable USART3 Transmit


	USART_voidInit();		// Initialize USART3
	USART_enableRX();       // Enable USART3 Receive
	USART_enableTX();       // Enable USART3 Transmit


	GSM_voidConnectToNetwork(); // Connect GSM with Network


	while(1)
	{

		SOIL_voidSensorReadData();  // Update Soil sensor readings
		_delay_ms(100);				// Busy wait delay

		GSM_voidSendData();			// Upload data in google sheet

		// receive 23 character as a respond from GSM
		for (u8 i =0 ; i<23; i++)
		{
			if(i == 0) 				// the first char in expected respond array is '+' so we need a special condition for the first element until we receive '+'
			{
				while (GSMSTATUS[0]!='+' && GSMTimeOut<250) // while it did not receive '+' and the time out value is less than 250, stay in the loop
				{
					GSMSTATUS[0]=USART3_u8ReciveData();		// Receive byte and save it in the first element
					GSMTimeOut++;							// increment the timeout value
				}
				GSMTimeOut=0;								// Timeout value = 0 to use it in the next loop

				if (GSMSTATUS[0]!='+' ) // if timeout exceeded the limit and the USART did not receive '+' in the first element
				{
					break;				// break the FOR loop
				}
			}

			else // if i bigger than 0
			{
				GSMSTATUS[i]=USART3_u8ReciveData(); 		//  Receive byte and save it in the (index of i) element
			}
		}

		/* General Note: - if the uploading of the data is done correctly the Bytes 15:17 will contain "302" */
		if (GSMSTATUS[15]!='3' || GSMSTATUS[16]!='0' || GSMSTATUS[17]!='2') // not uploaded
		{
			GSM_voidConnectToNetwork(); 	// Reconnect to the network and try again
		}
		else // if the uploading of the data is done correctly
		{
			_delay_ms(5000); // busy wait to the next needed upload time
		}
		for (int i =0 ; i<23; i++) // set the whole array = zeros
		{
			GSMSTATUS[i]=0;
		}
	}

	return 0;
}



void DoorStatusUpdate (void)
{
	/* 	this function will be called if EXTI fired an Interrupt */
	if 		(!DIO_u8GetPinValue(PORTA, PIN0)) // check if EXTI pin =0
	{	// change DoorStatus to closed
		DoorStatus[0]='C';
		DoorStatus[1]='l';
		DoorStatus[2]='o';
		DoorStatus[3]='s';
	}
	else if	(DIO_u8GetPinValue(PORTA, PIN0)) // check if EXTI pin =1
	{ 	// change DoorStatus to Opened
		DoorStatus[0]='O';
		DoorStatus[1]='p';
		DoorStatus[2]='e';
		DoorStatus[3]='n';
	}
}


