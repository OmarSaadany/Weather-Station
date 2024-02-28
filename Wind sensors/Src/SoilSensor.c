/*
 * SoilSensor.c
 *
 *  Created on: Nov 8, 2023
 *      Author: SaadanyOmar
 */


#include "SoilSensor.h"

// send this array to the sensor to ask for the value of the 7 parameters
u8 soilarr[8]={0x01, 0x03, 0x00, 0x00, 0x00, 0x07, 0x04, 0x08};
// used to receive USART array
u8 soilrecive[19];

// sensor readings
f32 soilHumidity	 	;
f32 soilTemperature  	;
u16 soilConductivity 	;
f32 soilPH 				;
u16 soilnitrogen 		;
u16 soilphosphorus 		;
u16 soilpotassium 		;



/* Function:-			void SOIL_voidSensorReadData(void);
 * I/O Parameters:-		void
 * Returns:- 			Void
 * Description:-
 * 		used to receive and update sensor variables
 */
void SOIL_voidSensorReadData(void){
	// send the request array
	for (u8 i =0 ; i<8; i++)
	{
		USART_voidSendByte(soilarr[i]);
	}
	//Receive 19 element of u8
	for (u8 i =0 ; i<19; i++)
	{
		soilrecive[i]=USART_u8ReciveData();
	}

	soilHumidity 	  	= 	(soilrecive[3]  << 8) | soilrecive[4]; 	// soil Humidity value in element no. 3 and 4
	soilHumidity /= 10.0;											// divided this value by 10 to get the actual value (it will become float)


	soilTemperature  	= 	(soilrecive[5]  << 8) | soilrecive[6];	// soil Temperature  value in element no. 5 and 6
	soilTemperature /= 10.0;                                        // divided this value by 10 to get the actual value (it will become float)


	soilConductivity 	= 	(soilrecive[7]  << 8) | soilrecive[8];	// soil Conductivity value in element no. 7 and 8


	soilPH 				= 	(soilrecive[9]  << 8) | soilrecive[10];	// soil PH value in element no. 9 and 10
	soilPH /= 10.0;                                                 // divided this value by 10 to get the actual value (it will become float)


	soilnitrogen 		= 	(soilrecive[11] << 8) | soilrecive[12]; // soil nitrogen value in element no. 11 and 12


	soilphosphorus 		= 	(soilrecive[13] << 8) | soilrecive[14]; // soil phosphorus value in element no. 13 and 14


	soilpotassium 		= 	(soilrecive[15] << 8) | soilrecive[16]; // soil potassium value in element no. 15 and 16
}
