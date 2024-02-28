/*
 * GPS_program.c
 *
 *  Created on: Feb 15, 2024
 *      Author: UAS
 */
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include "USART_interface.h"



typedef struct {
	u8 	time_Hr;
	u8 	time_Min;
	u8 	time_Sec;
	f32 latitude;
	u8 	latitude_Indicator;
	f32 longitude;
	f32 longitude_Indicator;
	u8 	date_Day;
	u8 	date_Month;
	u8 	date_Year;
}GPS_values;




GPS_values* GPS_Read(void)
{
//	USART_StrReceiveString(LOCAL_STR);

}
