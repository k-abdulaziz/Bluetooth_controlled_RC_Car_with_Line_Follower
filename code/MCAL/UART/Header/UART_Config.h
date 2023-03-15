/*
 * UART_Config.h
 *
 *  Created on: Oct 28, 2022
 *      Author: hisha
 */

#ifndef MCAL_UART_HEADER_UART_CONFIG_H_
#define MCAL_UART_HEADER_UART_CONFIG_H_
#include "UART_Private.h"
/*
 * will select between UART_NormalMode  U2x = 0
 * UART_DoubleSpeedMode U2X = 1 */
#define UART_OperationMode     UART_NormalMode
#define fosc                   8000000UL
#endif /* MCAL_UART_HEADER_UART_CONFIG_H_ */
