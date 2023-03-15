/*
 * IR_Program.c
 *
 *  Created on: Mar 11, 2023
 *      Author: khale
 */

#include "../../../Common/STD_types.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macro.h"

#include "../../../MCAL/DIO/Header/DIO_Interface.h"

#include "../Header/IR_Interface.h"

void IRSensors_init(void)
{
	DIO_u8SetPinDir(IRSensors_Port, IRSensor_Right, DIO_Input);
	DIO_u8SetPinDir(IRSensors_Port, IRSensor_Left,  DIO_Input);
}

u8 Read_IRSensor_Right(void)
{
	return Get_Bit(IRSensors_Port, IRSensor_Right);
}

u8 Read_IRSensor_Left(void)
{
	return Get_Bit(IRSensors_Port, IRSensor_Left);
}
