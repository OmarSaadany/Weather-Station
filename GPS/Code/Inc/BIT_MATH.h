/*
 * BIT_MATH.h
 *
 *  Created on: Mar 6, 2023
 *      Author: SaadanyOmar
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define clr_bit(value,bit)			 	(value)&= ~((0b00000001)<<bit)
#define set_bit(value,bit) 				(value)|=((0b00000001)<<bit)
#define get_bit(value,bit) 				((value>>bit)&0b00000001)
#define	tog_bit(REG,BIT)				(REG^=  (1<<BIT))
#endif /* BIT_MATH_H_ */
