/*
 * DIO_Imp.c
 *
 *  Created on: Sep 16, 2022
 *      Author: khale
 */

#include "../../../Common/STD_types.h"
#include "../../../Common/Bit_Math.h"
#include "../../../Common/Macro.h"

#include "../Header/DIO_Registers.h"
#include "../Header/DIO_Private.h"
#include "../Header/DIO_Config.h"
#include "../Header/DIO_Interface.h"

RequestState DIO_u8SetPinDir(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinState)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_Group_D) && (Local_GroupName >= DIO_Group_A))
	{
		if ((Local_PinNumber <= DIO_PIN7) && (Local_PinNumber >= DIO_PIN0))
		{
			if (Local_PinState  == DIO_Output)
			{
				switch(Local_GroupName)
				{
				case DIO_Group_A : DIO_DDRA |= (1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_B : DIO_DDRB |= (1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_C : DIO_DDRC |= (1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_D : DIO_DDRD |= (1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				}

			}
			else if (Local_PinState  == DIO_Input)
			{
				switch(Local_GroupName)
				{
				case DIO_Group_A : DIO_DDRA &= ~(1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_B : DIO_DDRB &= ~(1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_C : DIO_DDRC &= ~(1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_D : DIO_DDRD &= ~(1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				}
			}
			else
			{
				Request = RequestErrorNotValidState;
			}

		}
		else
		{
			Request = RequestErrorPinOutOfRange;
		}
	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}

RequestState DIO_u8SetPinValue(u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PinValue)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_Group_D) && (Local_GroupName >= DIO_Group_A))
	{
		if ((Local_PinNumber <= DIO_PIN7) && (Local_PinNumber >= DIO_PIN0))
		{
			if (Local_PinValue  == DIO_High)
			{
				switch(Local_GroupName)
				{
				case DIO_Group_A : DIO_PORTA |= (1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_B : DIO_PORTB |= (1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_C : DIO_PORTC |= (1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				case DIO_Group_D : DIO_PORTD |= (1<<Local_PinNumber);
				Request = RequestHandled;
				break;
				}

			}
			else if (Local_PinValue  == DIO_Low)
			{
				switch(Local_GroupName)
				{
				case DIO_Group_A :
				{
					DIO_PORTA &= ~(1<<Local_PinNumber);
					Request = RequestHandled;
					break;
				}
				case DIO_Group_B :
				{
					DIO_PORTB &= ~(1<<Local_PinNumber);
					Request = RequestHandled;
					break;
				}
				case DIO_Group_C :
				{
					DIO_PORTC &= ~(1<<Local_PinNumber);
					Request = RequestHandled;
					break;
				}
				case DIO_Group_D :
				{
					DIO_PORTD &= ~(1<<Local_PinNumber);
					Request = RequestHandled;
					break;
				}
				}
			}
			else
			{
				Request = RequestErrorNotValidState;
			}
		}
		else
		{
			Request = RequestErrorPinOutOfRange;
		}
	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}


RequestState DIO_u8GetPinValue(u8 Local_GroupName, u8 Local_PinNumber, u8 *Reference_Value)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_Group_D) && (Local_GroupName >= DIO_Group_A))
	{
		if ((Local_PinNumber <= DIO_PIN7) && (Local_PinNumber >= DIO_PIN0))
		{
			switch(Local_GroupName)
			{
			case DIO_Group_A :
			{
				*Reference_Value = Get_Bit(DIO_PINA,Local_PinNumber);
				Request = RequestHandled;
				break;
			}
			case DIO_Group_B :
			{
				*Reference_Value = Get_Bit(DIO_PINB,Local_PinNumber);
				Request = RequestHandled;
				break;
			}
			case DIO_Group_C :
			{
				*Reference_Value = Get_Bit(DIO_PINC,Local_PinNumber);
				Request = RequestHandled;
				break;
			}
			case DIO_Group_D :
			{
				*Reference_Value = Get_Bit(DIO_PIND,Local_PinNumber);
				Request = RequestHandled;
				break;
			}
			}
		}
		else
		{
			Request = RequestErrorPinOutOfRange;
		}
	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}

RequestState DIO_u8SetPortDir(u8 Local_GroupName, u8 Local_PortState)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_Group_D) && (Local_GroupName >= DIO_Group_A))
	{
		if ((Local_PortState <= 0xFF))
		{
			Request = RequestHandled;
			switch(Local_GroupName)
			{
			case DIO_Group_A :
			{
				DIO_DDRA = Local_PortState;
				break;
			}
			case DIO_Group_B :
			{
				DIO_DDRB = Local_PortState;
				break;
			}
			case DIO_Group_C :
			{
				DIO_DDRC = Local_PortState;
				break;
			}
			case DIO_Group_D :
			{
				DIO_DDRD = Local_PortState;
				break;
			}
			}
		}
		else
		{
			Request = RequestErrorNotValidState;
		}
	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}

RequestState DIO_u8SetPortValue(u8 Local_GroupName, u8 Local_PortValue)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_Group_D) && (Local_GroupName >= DIO_Group_A))
	{
		if ((Local_PortValue <= 0xFF))
		{
			Request = RequestHandled;
			switch(Local_GroupName)
			{
			case DIO_Group_A :
			{
				DIO_PORTA = Local_PortValue;
				break;
			}
			case DIO_Group_B :
			{
				DIO_PORTB = Local_PortValue;
				break;
			}
			case DIO_Group_C :
			{
				DIO_PORTC = Local_PortValue;
				break;
			}
			case DIO_Group_D :
			{
				DIO_PORTD = Local_PortValue;
				break;
			}
			}
		}
		else
		{
			Request = RequestErrorNotValidValue;
		}
	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}

RequestState DIO_u8GetPortValue(u8 Local_GroupName, u8 *Local_PortValue)
{
	RequestState Request;
	if ((Local_GroupName <= DIO_Group_D) && (Local_GroupName >= DIO_Group_A))
	{
		switch(Local_GroupName)
		{
		case DIO_Group_A :
		{
			*Local_PortValue = DIO_PINA;
			break;
		}
		case DIO_Group_B :
		{
			*Local_PortValue = DIO_PINB;
			break;
		}
		case DIO_Group_C :
		{
			*Local_PortValue = DIO_PINC;
			break;
		}
		case DIO_Group_D :
		{
			*Local_PortValue = DIO_PIND;
			break;
		}
		}
	}
	else
	{
		Request = RequestErrorGroupOutOfRange;
	}
	return Request;
}

RequestState DIO_u8ControlPullup(u8 Local_ConnectionType, u8 Local_GroupName, u8 Local_PinNumber, u8 Local_PullupState)
{
	RequestState Request;
	if ((Local_ConnectionType == 1))
	{
		if ((Local_GroupName <= DIO_Group_D) && (Local_GroupName >= DIO_Group_A))
		{
			if ((Local_PinNumber <= DIO_PIN7) && (Local_PinNumber >= DIO_PIN0))
			{
				if (Local_PullupState  == DIO_Enable_Pullup)
				{
					Request = RequestHandled;
					switch(Local_GroupName)
					{
					case DIO_Group_A :
					{
						DIO_DDRA  |= (1<<Local_PinNumber);
						DIO_PORTA |= (1<<Local_PinNumber);
						break;
					}
					case DIO_Group_B :
					{
						DIO_DDRB  |= (1<<Local_PinNumber);
						DIO_PORTB |= (1<<Local_PinNumber);
						break;
					}
					case DIO_Group_C :
					{
						DIO_DDRC  |= (1<<Local_PinNumber);
						DIO_PORTC |= (1<<Local_PinNumber);
						break;
					}
					case DIO_Group_D :
					{
						DIO_DDRD  |= (1<<Local_PinNumber);
						DIO_PORTD |= (1<<Local_PinNumber);
						break;
					}
					}

				}
				else if (Local_PullupState  == DIO_Disable_Pullup)
				{
					Request = RequestHandled;
					switch(Local_GroupName)
					{
					case DIO_Group_A :
					{
						DIO_DDRA  |= (1<<Local_PinNumber);
						DIO_PORTA |= (1<<Local_PinNumber);
						break;
					}
					case DIO_Group_B :
					{
						DIO_DDRB  |= (1<<Local_PinNumber);
						DIO_PORTB |= (1<<Local_PinNumber);
						break;
					}
					case DIO_Group_C :
					{
						DIO_DDRC  |= (1<<Local_PinNumber);
						DIO_PORTC |= (1<<Local_PinNumber);
						break;
					}
					case DIO_Group_D :
					{
						DIO_DDRD  |= (1<<Local_PinNumber);
						DIO_PORTD |= (1<<Local_PinNumber);
						break;
					}
					}
				}
				else
				{
					Request = RequestErrorNotValidState;
				}

			}
		}
		else
		{
			//error handling
		}
	}
	else
	{
		//error handling
	}
	return Request;
}
