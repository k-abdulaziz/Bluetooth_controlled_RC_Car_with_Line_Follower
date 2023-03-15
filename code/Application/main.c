/*
 * main.c
 *
 *  Created on: Mar 14, 2023
 *      Author: khale
 */

#include "../Common/STD_types.h"
#include "../Common/Bit_Math.h"
#include "../Common/Macro.h"
#include <stdio.h>
#include <util/delay.h>
#include "../MCAL/DIO/Header/DIO_Interface.h"
#include "../MCAL/UART/Header/UART_Interface.h"
#include "../HAL/IR/Header/IR_Interface.h"
#include "../HAL/MotorDriver/Header/MotorDriver_Interface.h"

int main(void)
{
	/* Initialize Motor Driver, IR sensors, and UART communication */
	MDriver_init();
	IRSensors_init();
	UART_VoidInit(9600);

	int left_sensor_value, right_sensor_value;
	int mode = 0;
	u8 RX;

	while(1)
	{
		/* Get a char from the master device */
		RX = UART_RxChar();

		/* Check the received command and set the mode accordingly */
		if(RX ==  9) /* '9' is the stop command */
		{
			mode = 0;
			MDriver_Stop(); /* Stop the motor */
		}
		else if(RX == 10) /* '10' is the line follower mode command */
		{
			mode = 1;
		}

		if(mode == 0)
		{
			if (RX == 1)
			{
				MDriver_MoveForward();
				UART_TxString("Forward"); /* send status of Movement i.e. Car moving Forward */
			}
			else if (RX == 2)
			{
				MDriver_MoveBackward();
				UART_TxString("Backward"); /* send status of Movement i.e. Car moving Backward */
			}
			else if (RX == 3)
			{
				MDriver_MoveRight();
				UART_TxString("Right"); /* send status of Movement i.e. Car moving Right */
			}
			else if (RX == 4)
			{
				MDriver_MoveLeft();
				UART_TxString("Left"); /* send status of Movement i.e. Car moving Left */
			}
			else if (RX == 5)
			{
				MDriver_MoveForRight();
				UART_TxString("Forward Right"); /* send status of Movement i.e. Car moving Forward Right */
			}
			else if (RX == 6)
			{
				MDriver_MoveForLeft();
				UART_TxString("Forward Left"); /* send status of Movement i.e. Car moving Forward Left */
			}
			else if (RX == 7)
			{
				MDriver_MoveBackRight();
				UART_TxString("Backward Right"); /* send status of Movement i.e. Car moving Backward Right */
			}
			else if (RX == 8)
			{
				MDriver_MoveBackLeft();
				UART_TxString("Backward Left"); /* send status of Movement i.e. Car moving Backward Left */
			}
			else if (RX == 0)
			{
				MDriver_Stop();
				UART_TxString("Stop"); /* send status of Movement i.e. Stop */
			}
			else if (RX == 11)
			{
				MDriver_MoveRight();
				_delay_ms(400);
				RX == 0;
				UART_TxString("Stop"); /* send status of Movement i.e. Stop */
			}
			else if (RX == 12)
			{
				MDriver_MoveLeft();
				_delay_ms(400);
				RX == 0;
				UART_TxString("Stop"); /* send status of Movement i.e. Stop */
			}
		}

		if(mode == 1)
		{
		    /* Line Follower mode is enabled */
		    do
		    {
		        left_sensor_value = Read_IRSensor_Left(); // Read left IR sensor value
		        right_sensor_value = Read_IRSensor_Right(); // Read right IR sensor value

		        if(right_sensor_value == 0 && left_sensor_value == 0)
		        {
		            /* If no black line is detected, move forward */
		            MDriver_MoveForward();
		        }
		        else if(right_sensor_value == 1 && left_sensor_value == 0)
		        {
		            /* If only right sensor detected back, move right */
		            MDriver_MoveRight();
		        }
		        else if(right_sensor_value == 0 && left_sensor_value == 1)
		        {
		            /* If only left sensor detected back, move left */
		            MDriver_MoveLeft();
		        }
		        else if((right_sensor_value == 1 && left_sensor_value == 1))
		        {
		            /* If both right and left sensors detected black, stop */
		            MDriver_Stop();
		        }

		    }while(RX != 9); // Exit autonomous mode when RX is 9 (manual mode)
		}
		_delay_ms(10);
	}
}
