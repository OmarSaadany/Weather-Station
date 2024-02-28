/*
 * GSM_interface.h
 *
 *  Created on: Nov 8, 2023
 *      Author: SaadanyOmar
 */

#ifndef GSM_INTERFACE_H_
#define GSM_INTERFACE_H_

void	_delay_ms(u32 ticks);
void reverse(u8* str, u16 len) ;
u16  intToStr(u16 x, u8 str[], u16 d) ;
void ftoa(f32 n, u8* res, u16 afterpoint);


void GSM_voidReceivedStatus (void);


/* Function:-			void GSM_voidSendSMS (u8* PhoneNumSTR, u8* SMS);
 * I/O Parameters:-		u8*, u8*
 * Returns:- 			Void
 * Description:-
 * 		used to make a phone call
 */
void GSM_voidSendSMS (u8* PhoneNum, u8* SMS);



/* Function:-			void GSM_voidPhoneCall(u8* PhoneNumSTR);
 * I/O Parameters:-		u8*
 * Returns:- 			Void
 * Description:-
 * 		used to make a phone call
 */
void GSM_voidPhoneCall(u8* PhoneNum);



/* Function:-			void GSM_voidConnectToNetwork(void);
 * I/O Parameters:-		void
 * Returns:- 			Void
 * Description:-
 * 		connect GSM to network and initialize HTTP mode
 */
void GSM_voidConnectToNetwork (void);



/* Function:-			void GSM_voidSendData(void);
 * I/O Parameters:-		void
 * Returns:- 			Void
 * Description:-
 * 		update data to google sheet
 */
void GSM_voidSendData(void);



#endif /* GSM_INTERFACE_H_ */
