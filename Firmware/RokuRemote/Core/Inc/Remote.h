/*
 * Remote.h
 *
 *  Created on: Jun 3, 2020
 *      Author: prati
 */

#ifndef REMOTE_H_
#define REMOTE_H_

#include "stm32l0xx_hal.h"
#include <stdbool.h>

extern TIM_HandleTypeDef htim2;

#define ONTIME 562
#define OFFTIME_0 562
#define OFFTIME_1 1687

void delay_us(uint16_t time);
void sendStart(void);
void sendData(uint32_t);
void sendStop(void);



#endif /* REMOTE_H_ */
