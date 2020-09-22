/*
 * Remote.c
 *
 *  Created on: Jun 3, 2020
 *      Author: prati
 */

#include "Remote.h"

void delay_us(uint16_t time)
{
	TIM6->ARR = time;
	TIM6->CR1 |= (1<<0);

	while(TIM6->CR1 & 1);
}

void sendStart()
{

	TIM2->CCMR1|=(1<<5)|(1<<6);  // Set to PWM mode
	TIM2->CCMR1&= ~(1<<4);


	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	delay_us(9000);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	delay_us(4500);

}


void sendData(uint32_t data)
{
	uint32_t dataMask = (1<<31);
	sendStart();

	for(;dataMask > 0;dataMask=dataMask>>1)
	{

		bool bit = dataMask & data;
		if(bit)
		{
			HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
			delay_us(ONTIME);
			HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
			delay_us(OFFTIME_1);
		}
		else
		{
			HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
			delay_us(ONTIME);
			HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
			delay_us(OFFTIME_0);


		}

	}
	sendStop();
}

void sendStop()
{
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	delay_us(562);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);

	TIM2->CCMR1 |= (1<<6);		// Force output to low to improve fall time
	TIM2->CCMR1 &= ~((1<<5)|(1<<4));

}


