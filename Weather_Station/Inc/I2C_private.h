/*
 * I2C_private.h
 *
 *  Created on: Oct 17, 2023
 *      Author: SaadanyOmar
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define I2C_Base_Address		0x40005400
typedef struct{
	u32 CR1   ;
	u32 CR2   ;
	u32 OAR1  ;
	u32 OAR2  ;
	u32 DR    ;
	u32 SR1   ;
	u32 SR2   ;
	u32 CCR   ;
	u32 TRISE ;

}I2C_Reg;

#define I2C1	((volatile I2C_Reg*)(I2C_Base_Address))


#endif /* I2C_PRIVATE_H_ */
