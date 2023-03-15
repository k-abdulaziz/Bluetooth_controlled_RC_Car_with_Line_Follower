/*
 * MotorDriver_Program.c
 *
 *  Created on: Mar 9, 2023
 *      Author: khale
 */

#include "../../../Common/STD_types.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macro.h"

#include "../../../MCAL/DIO/Header/DIO_Interface.h"

#include "../Header/MotorDriver_Interface.h"

void MDriver_init(void)
{
	DIO_u8SetPinDir(MDriver_Port, MDriver_IN1, DIO_Output);
	DIO_u8SetPinDir(MDriver_Port, MDriver_IN2, DIO_Output);
	DIO_u8SetPinDir(MDriver_Port, MDriver_IN3, DIO_Output);
	DIO_u8SetPinDir(MDriver_Port, MDriver_IN4, DIO_Output);
}

void MDriver_MoveForward(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_High);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_High);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_Low);
}

void MDriver_MoveBackward(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_High);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_High);
}

void MDriver_MoveRight(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_High);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_Low);
}

void MDriver_MoveLeft(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_High);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_Low);
}

void MDriver_MoveForRight(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_High);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_Low);
}

void MDriver_MoveForLeft(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_High);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_Low);
}

void MDriver_MoveBackRight(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_High);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_Low);
}

void MDriver_MoveBackLeft(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_High);
}

void MDriver_Stop(void)
{
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN1, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN2, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN3, DIO_Low);
	DIO_u8SetPinValue(MDriver_Port, MDriver_IN4, DIO_Low);
}
