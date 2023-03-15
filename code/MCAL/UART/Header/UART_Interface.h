/*
 * UART_Interface.h
 *
 *  Created on: Oct 28, 2022
 *      Author: hisha
 */

#ifndef DEBUG_MCAL_UART_HEADER_UART_INTERFACE_H_
#define DEBUG_MCAL_UART_HEADER_UART_INTERFACE_H_
#include "../../../Common/STD_types.h"
#include "UART_Register.h"
#include "UART_Private.h"
#include "UART_Config.h"
void UART_VoidInit(u16 Baudrate);
void UART_TxChar(u8 local_data);
void UART_TxString(u8 *string);
u8  UART_RxChar(void);
void UART_RxString(char* string);


#endif /* DEBUG_MCAL_UART_HEADER_UART_INTERFACE_H_ */
