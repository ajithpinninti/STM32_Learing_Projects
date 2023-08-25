/*
 * timer_callbacks.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ajith Pinninti
 */

#include "main.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin); //light will toggle for every tranmission
//	  CAN1_TX(); // sending command for every 2 seconds
	CAN_MSG_TX(); //sending LED number for every 2 seconds

}
