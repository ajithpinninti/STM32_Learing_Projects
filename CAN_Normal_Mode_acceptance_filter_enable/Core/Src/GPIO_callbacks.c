/*
 * GPIO_callbacks.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Ajith Pinninti
 */

#include "main.h"

 void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	 if(GPIO_Pin == GPIO_PIN_13){
		 /* Push buttons click detected */

		 HAL_TIM_Base_Start_IT(&htim6);

	 }
 }
