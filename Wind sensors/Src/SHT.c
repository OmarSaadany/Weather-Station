/*
 * SHT.c
 *
 *  Created on: Nov 9, 2023
 *      Author: SaadanyOmar
 */

#include "STD_TYPES.h"
#include "SHT.h"
#include "DIO_interface.h"
#include "I2C_interface.h"

void SHT_SensorInit(void)
{
	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_10MHZ_AFOD);
	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_10MHZ_AFOD);

	DIO_voidSetPinValue(PORTB, PIN7, GPIO_LOW);
	DIO_voidSetPinValue(PORTB, PIN6, GPIO_LOW);

	I2C_voidInit();
}


f32 SHT_RecieveTemp(void)
{

	f32 Local_var=0;
	u8 I2CData[3];

	I2c_voidSendStartCondition();
	I2C_voidSendSlaveAddress(0b10000000);
	I2C_voidMasterWriteDataByte(0b11100011);
	I2C_voidSendStopCondition();

	_delay_ms(500);
	I2c_voidSendStartCondition();
	I2C_voidSendSlaveAddress(0b10000001);

	I2CData[0] = I2C_u8MasterReadDataByte();
	I2CData[1] = I2C_u8MasterReadDataByte();
	I2CData[2] = I2C_u8MasterReadDataByte();
	I2C_voidSendStopCondition();

	Local_var= (	(	( (I2CData[0]<<8)|(I2CData[1]) )	/	65536.000	)	*	175.72) - 46.85;

	return Local_var;
}



f32 SHT_RecieveHumd(void)
{
	f32 Local_var=0;
	u8 I2CData[3];

	I2c_voidSendStartCondition();
	I2C_voidSendSlaveAddress(0b10000000);
	I2C_voidMasterWriteDataByte(0b11100101);
	I2C_voidSendStopCondition();

	_delay_ms(500);
	I2c_voidSendStartCondition();
	I2C_voidSendSlaveAddress(0b10000001);

	I2CData[0] = I2C_u8MasterReadDataByte();
	I2CData[1] = I2C_u8MasterReadDataByte();
	I2CData[2] = I2C_u8MasterReadDataByte();
	I2C_voidSendStopCondition();

	Local_var= (	(	( (I2CData[0]<<8)|(I2CData[1]) )	/	65536.000	)	*	125) - 6;

	return Local_var;
}
