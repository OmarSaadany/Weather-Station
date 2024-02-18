/*
 * I2C_interface.h
 *
 *  Created on: Oct 17, 2023
 *      Author: SaadanyOmar
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_config.h"
#include "I2C_private.h"


void I2C_voidInit(void);

void I2c_voidSendStartCondition(void);

void I2C_voidSendSlaveAddress(u8 copy_Slaveaddress);

u8 	 I2C_u8MasterReadDataByte(void);

void I2C_voidMasterWriteDataByte(u8 copy_DataByte);

void I2C_voidSendStopCondition(void);
#endif /* I2C_INTERFACE_H_ */
