/*
 * IR_Interface.h
 *
 *  Created on: Mar 12, 2023
 *      Author: khale
 */

#ifndef HAL_IR_HEADER_IR_INTERFACE_H_
#define HAL_IR_HEADER_IR_INTERFACE_H_

#include "../../IR/Header/IR_Config.h"

void IRSensors_init(void);
u8  Read_IRSensor_Right(void);
u8  Read_IRSensor_Left(void);

#endif /* HAL_IR_HEADER_IR_INTERFACE_H_ */
