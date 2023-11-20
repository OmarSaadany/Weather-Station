/*
 * GSM_program.c
 *
 *  Created on: Nov 8, 2023
 *      Author: SaadanyOmar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GSM_interface.h"
#include "USART3_interface.h"


// this string used with GSM_voidSendData function to convert float numbers into array by using ftoa function
u8 ftoa_Result[20];

extern volatile f32 SensorTempRead;
extern volatile f32 SensorHumdRead;

// these data are global in SOILSENSOR files and updated before calling GSM_voidSendData
extern f32 soilHumidity	 	    ;
extern f32 soilTemperature  	;
extern u16 soilConductivity 	;
extern f32 soilPH 				;
extern u16 soilnitrogen 		;
extern u16 soilphosphorus 		;
extern u16 soilpotassium 		;


// simple busy wait function
void	_delay_ms(u32 ticks)
{
	u32 i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}



/* Function:-			void GSM_voidConnectToNetwork(void);
 * I/O Parameters:-		void
 * Returns:- 			Void
 * Description:-
 * 		connect GSM to network and initialize HTTP mode
 */
void GSM_voidConnectToNetwork (void)
{
	// send AT to make GSM ready to start and sync with boud rate
	USART3_voidSendString("AT");
	USART3_voidSendString("\r\n");
	_delay_ms(100);
	USART3_voidSendString("AT");
	USART3_voidSendString("\r\n");
	_delay_ms(1000);
	USART3_voidSendString("AT+CPIN?");
	USART3_voidSendString("\r\n");
	_delay_ms(1000);
	USART3_voidSendString("AT+CFUN=1");
	USART3_voidSendString("\r\n");
	_delay_ms(1000);
	USART3_voidSendString("AT+CREG?");
	USART3_voidSendString("\r\n");
	_delay_ms(1000);
	USART3_voidSendString("AT+CGATT?");
	USART3_voidSendString("\r\n");
	_delay_ms(1000);
	USART3_voidSendString("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
	USART3_voidSendString("\r\n");
	_delay_ms(1000);
	USART3_voidSendString("AT+SAPBR=3,1,\"APN\",\"internet.vodafone.net\"");
	USART3_voidSendString("\r\n");
	_delay_ms(1000);
	USART3_voidSendString("AT+SAPBR=3,1,\"USER\",\"internet\"");
	USART3_voidSendString("\r\n");
	_delay_ms(1500);
	USART3_voidSendString("AT+SAPBR=1,1");
	USART3_voidSendString("\r\n");
	_delay_ms(1000);
	USART3_voidSendString("AT+SAPBR=2,1");
	USART3_voidSendString("\r\n");
	_delay_ms(1500);
	USART3_voidSendString("AT+HTTPINIT");
	USART3_voidSendString("\r\n");

}


/* Function:-			void GSM_voidSendData(void);
 * I/O Parameters:-		void
 * Returns:- 			Void
 * Description:-
 * 		update data to google sheet
 */
void GSM_voidSendData(void)
{
	// enable HTTPSSL
	USART3_voidSendString("AT+HTTPSSL=1");
	USART3_voidSendString("\r\n");
	_delay_ms(500);

	// Send google sheet script link
	USART3_voidSendString("AT+HTTPPARA=\"URL\",\"https://script.google.com/macros/s/AKfycbyiUN1bmSNm345frzKFq8PqFyeCMFSN9RfPf0dQ0b-GIZpI2YYp2j5B7hdfIjlw0NXU/exec?");

	// scaleID= is the first macro then send its value as string
	USART3_voidSendString("soilHumidity=");
	ftoa(soilHumidity, ftoa_Result, 2);
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("&soilTemperature=");
	ftoa(soilTemperature, ftoa_Result, 2);
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("&soilConductivity=");
	intToStr(soilConductivity, ftoa_Result, 3) ;
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("&soilPH=");
	ftoa(soilPH, ftoa_Result, 2);
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("&soilNitrogen=");
	intToStr(soilnitrogen, ftoa_Result, 2) ;
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("&soilPhosphorus=");
	intToStr(soilphosphorus, ftoa_Result, 2) ;
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("&soilPotassium=");
	intToStr(soilpotassium, ftoa_Result, 2) ;
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("&airTemperature=");
	ftoa(SensorTempRead, ftoa_Result, 2) ;
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("&airHumididty=");
	ftoa(SensorHumdRead, ftoa_Result, 2) ;
	USART3_voidSendString(ftoa_Result);

	USART3_voidSendString("\"\r\n");
	_delay_ms(3000);

	USART3_voidSendString("AT+HTTPACTION=0");
	USART3_voidSendString("\r\n");
	_delay_ms(3000);
}


//void GSM_voidSendData(void)
//{
//	// enable HTTPSSL
//	USART3_voidSendString("AT+HTTPSSL=1");
//	USART3_voidSendString("\r\n");
//	_delay_ms(500);
//
//	// Send google sheet script link
//	USART3_voidSendString("AT+HTTPPARA=\"URL\",\"https://script.google.com/macros/s/AKfycbyiUN1bmSNm345frzKFq8PqFyeCMFSN9RfPf0dQ0b-GIZpI2YYp2j5B7hdfIjlw0NXU/exec?");
//
//	// scaleID= is the first macro then send its value as string
//	USART3_voidSendString("scaleID=");
//	ftoa(5.0, ftoa_Result, 2);
//	USART3_voidSendString(ftoa_Result);
//
//	USART3_voidSendString("&type=");
//	ftoa(5.0, ftoa_Result, 2);
//	USART3_voidSendString(ftoa_Result);
//
//	USART3_voidSendString("&weightLimit=");
//	intToStr(5.0, ftoa_Result, 3) ;
//	USART3_voidSendString(ftoa_Result);
//
//	USART3_voidSendString("&weightTolerance=");
//	ftoa(5.0, ftoa_Result, 2);
//	USART3_voidSendString(ftoa_Result);
//
//	USART3_voidSendString("&weight=");
//	intToStr(5.0, ftoa_Result, 2) ;
//	USART3_voidSendString(ftoa_Result);
//
//	USART3_voidSendString("\"\r\n");
//	_delay_ms(3000);
//
//	USART3_voidSendString("AT+HTTPACTION=0");
//	USART3_voidSendString("\r\n");
//	_delay_ms(3000);
//}

/* Function:-			void GSM_voidPhoneCall(u8* PhoneNumSTR);
 * I/O Parameters:-		u8*
 * Returns:- 			Void
 * Description:-
 * 		used to make a phone call
 */
void GSM_voidPhoneCall(u8* PhoneNumSTR){
	// use ATD command to make a phone call
	USART3_voidSendString("ATD");
	USART3_voidSendString(PhoneNumSTR);
	USART3_voidSendString(";\r\n");

}


/* Function:-			void GSM_voidSendSMS (u8* PhoneNumSTR, u8* SMS);
 * I/O Parameters:-		u8*, u8*
 * Returns:- 			Void
 * Description:-
 * 		used to make a phone call
 */
void GSM_voidSendSMS (u8* PhoneNumSTR, u8* SMS)
{
	USART3_voidSendString("AT+CMGF=1");
	USART3_voidSendString("\r\n");
	_delay_ms(100);
	USART3_voidSendString("AT+CMGS=");
	USART3_voidSendByte('"');
	USART3_voidSendString(PhoneNumSTR);
	USART3_voidSendByte('"');
	USART3_voidSendString("\r\n");
	_delay_ms(100);
	USART3_voidSendString(SMS);
	USART3_voidSendString("\r\n");
	USART3_voidSendByte(0x1A);
}






void reverse(u8* str, u16 len)
{
	// this func reverse the string
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

u16  intToStr(u16 x, u8 str[], u16 d)
{// change int value to string of char
	u16 i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}

// Converts a floating-point/double number to a string.
void ftoa(f32 n, u8* res, u16 afterpoint)
{
	// Extract integer part
	u16 ipart = (u16)n;

	// Extract floating part
	f32 fpart = n - (f32)ipart;

	// convert integer part to string
	u16 i = intToStr(ipart, res, 0);

	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot

		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);

		intToStr((u16)fpart, res + i + 1, afterpoint);
	}
}
