/*
 * DIO_Interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: khale
 */

#ifndef MCAL_DIO_HEADER_DIO_INTERFACE_H_
#define MCAL_DIO_HEADER_DIO_INTERFACE_H_

#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Registers.h"

RequestState DIO_u8SetPinDir(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinState);
RequestState DIO_u8SetPinValue(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinValue);
RequestState DIO_u8GetPinValue(u8 Local_GroupName, u8 Local_PinNumber, u8 *Local_PinValue);
RequestState DIO_u8SetPortDir(u8 Local_GroupName, u8 Local_PortState);
RequestState DIO_u8SetPortValue(u8 Local_GroupName, u8 Local_PortValue);
RequestState DIO_u8GetPortValue(u8 Local_GroupName, u8 *Local_PortValue);
RequestState DIO_u8ControlPullup(u8 Local_ConnectionType, u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PullupState);

#endif /* MCAL_DIO_HEADER_DIO_INTERFACE_H_ */
