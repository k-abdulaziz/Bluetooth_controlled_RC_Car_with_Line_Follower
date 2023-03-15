/*
 * Motor_Driver_Interface.h
 *
 *  Created on: Mar 9, 2023
 *      Author: khale
 */

#ifndef HAL_MOTORDRIVER_HEADER_MOTORDRIVER_INTERFACE_H_
#define HAL_MOTORDRIVER_HEADER_MOTORDRIVER_INTERFACE_H_

#include "../../MotorDriver/Header/MotorDriver_Config.h"

void MDriver_init(void);
void MDriver_MoveForward(void);
void MDriver_MoveBackward(void);
void MDriver_MoveRight(void);
void MDriver_MoveLeft(void);
void MDriver_MoveForRight(void);
void MDriver_MoveForLeft(void);
void MDriver_MoveBackRight(void);
void MDriver_MoveBackLeft(void);
void MDriver_Stop(void);

#endif /* HAL_MOTORDRIVER_HEADER_MOTORDRIVER_INTERFACE_H_ */
