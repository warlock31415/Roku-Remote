/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MF1_Pin GPIO_PIN_14
#define MF1_GPIO_Port GPIOC
#define MF2_Pin GPIO_PIN_15
#define MF2_GPIO_Port GPIOC
#define MF3_Pin GPIO_PIN_0
#define MF3_GPIO_Port GPIOA
#define MF5_Pin GPIO_PIN_1
#define MF5_GPIO_Port GPIOA
#define PWR_Pin GPIO_PIN_2
#define PWR_GPIO_Port GPIOA
#define PWR_EXTI_IRQn EXTI2_3_IRQn
#define BCK_Pin GPIO_PIN_3
#define BCK_GPIO_Port GPIOA
#define BCK_EXTI_IRQn EXTI2_3_IRQn
#define HOME_Pin GPIO_PIN_4
#define HOME_GPIO_Port GPIOA
#define HOME_EXTI_IRQn EXTI4_15_IRQn
#define UP_Pin GPIO_PIN_5
#define UP_GPIO_Port GPIOA
#define UP_EXTI_IRQn EXTI4_15_IRQn
#define RGT_Pin GPIO_PIN_6
#define RGT_GPIO_Port GPIOA
#define RGT_EXTI_IRQn EXTI4_15_IRQn
#define LFT_Pin GPIO_PIN_7
#define LFT_GPIO_Port GPIOA
#define LFT_EXTI_IRQn EXTI4_15_IRQn
#define DWN_Pin GPIO_PIN_0
#define DWN_GPIO_Port GPIOB
#define DWN_EXTI_IRQn EXTI0_1_IRQn
#define OK_Pin GPIO_PIN_1
#define OK_GPIO_Port GPIOB
#define OK_EXTI_IRQn EXTI0_1_IRQn
#define V__Pin GPIO_PIN_8
#define V__GPIO_Port GPIOA
#define V__EXTI_IRQn EXTI4_15_IRQn
#define V_A9_Pin GPIO_PIN_9
#define V_A9_GPIO_Port GPIOA
#define V_A9_EXTI_IRQn EXTI4_15_IRQn
#define MUTE_Pin GPIO_PIN_10
#define MUTE_GPIO_Port GPIOA
#define MUTE_EXTI_IRQn EXTI4_15_IRQn
#define PWM_Pin GPIO_PIN_15
#define PWM_GPIO_Port GPIOA
#define MF4_Pin GPIO_PIN_3
#define MF4_GPIO_Port GPIOB
#define USB_SENSE_Pin GPIO_PIN_4
#define USB_SENSE_GPIO_Port GPIOB
#define LED_IND_Pin GPIO_PIN_5
#define LED_IND_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
