/*
 * I2C_program.c
 *
 *  Created on: Oct 17, 2023
 *      Author: SaadanyOmar
 */

#include "STD_TYPES.h"
#include "I2C_interface.h"
void I2C_voidInit(void){

	set_bit(I2C1->CR1,15);  //reset the I2c
	clr_bit(I2C1->CR1,15);  // Normal operation


	// Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
	set_bit(I2C1->CR2,3);// PCLK1 FREQUENCY in MHz = 0b00001000 ----> (8MHz)
	// Configure the clock control registers
	I2C1->CCR =(40<<0); // check calculation in PDF (0x28)

	// Configure the rise time register
	I2C1->TRISE = 9;// check PDF

	// Enable I2C
	set_bit(I2C1->CR1,0);

	//Acknowledge enable
	set_bit(I2C1->CR1,10);
}

//01101000 11100100

void I2c_voidSendStartCondition(void){

	// Start generation
	do{
		set_bit(I2C1->CR1,8);
	}
	while (!get_bit(I2C1->SR1,0));  // Wait for SB bit to set
}


void I2C_voidSendSlaveAddress(u8 copy_Slaveaddress){

	do{I2C1->DR = copy_Slaveaddress;}  //  send the address
	while (!get_bit(I2C1->SR1,1));  // wait for ADDR bit to set
	volatile u8 temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit

}
void I2C_voidMasterWriteDataByte(u8 copy_DataByte){
//	while (!get_bit(I2C1->SR1,7));  // wait for TXE bit to set
	I2C1->DR = copy_DataByte;
	while (!get_bit(I2C1->SR1,2));  // wait for BTF bit to set
}
void I2C_voidSendStopCondition(void){
	// stop generation
	set_bit(I2C1->CR1,9);
	// reset sequence
	clr_bit(I2C1->CR1,0);  // disable I2c
	set_bit(I2C1->CR1,0);  // enable I2C
}
u8 I2C_u8MasterReadDataByte(void){

	while (!get_bit(I2C1->SR1,6));  // wait for Rx bit to set

	return I2C1 -> DR;
}
