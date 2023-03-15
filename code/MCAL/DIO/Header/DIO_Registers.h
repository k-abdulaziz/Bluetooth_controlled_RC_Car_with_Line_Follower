/*
 * DUI_Registers.h
 *
 *  Created on: Sep 16, 2022
 *      Author: khale
 */

#ifndef MCAL_DIO_HEADER_DIO_REGISTERS_H_
#define MCAL_DIO_HEADER_DIO_REGISTERS_H_

/* PORT A REGISTERS */
#define DIO_PORTA (*(volatile u8 *)0x3B)
#define DIO_DDRA  (*(volatile u8 *)0x3A)
#define DIO_PINA  (*(volatile u8 *)0x39)

/* PORT B REGISTERS */
#define DIO_PORTB (*(volatile u8 *)0x38)
#define DIO_DDRB  (*(volatile u8 *)0x37)
#define DIO_PINB  (*(volatile u8 *)0x36)

/* PORT C REGISTERS */
#define DIO_PORTC (*(volatile u8 *)0x35)
#define DIO_DDRC  (*(volatile u8 *)0x34)
#define DIO_PINC  (*(volatile u8 *)0x33)

/* PORT D REGISTERS */
#define DIO_PORTD (*(volatile u8 *)0x32)
#define DIO_DDRD  (*(volatile u8 *)0x31)
#define DIO_PIND  (*(volatile u8 *)0x30)

#define DIO_SFIOR  (*(volatile u8 *)0x50)

#endif /* MCAL_DIO_HEADER_DIO_REGISTERS_H_ */
