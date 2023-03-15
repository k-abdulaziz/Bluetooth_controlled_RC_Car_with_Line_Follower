/*
 * DUI_Private.h
 *
 *  Created on: Sep 16, 2022
 *      Author: khale
 */

#ifndef MCAL_DIO_HEADER_DIO_PRIVATE_H_
#define MCAL_DIO_HEADER_DIO_PRIVATE_H_

#define DIO_Group_A 1
#define DIO_Group_B 2
#define DIO_Group_C 3
#define DIO_Group_D 4

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_Input  0
#define DIO_Output 1

#define DIO_Low  0
#define DIO_High 1

#define DIO_Enable_Pullup 1
#define DIO_Disable_Pullup 2

#define DIO_PortOutput  0xFF
#define DIO_PortInput   0x00
#define DIO_PortHigh    0xFF
#define DIO_PortLow     0x00

typedef enum EN_DIO_error_t {
	RequestHandled,
    RequestErrorGroupOutOfRange,
	RequestErrorPinOutOfRange,
	RequestErrorNotValidState,
	RequestErrorNotValidValue
}RequestState;

#endif /* MCAL_DIO_HEADER_DIO_PRIVATE_H_ */
