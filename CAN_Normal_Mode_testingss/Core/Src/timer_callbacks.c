/*
 * timer_callbacks.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ajith Pinninti
 */

#include "main.h"

uint8_t tim_counter=0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim13){
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin); //Toggling the LED

		return;

	}

	CAN_TxHeaderTypeDef TxHeader;

	uint32_t TxMailbox;

	uint8_t msg; // no meaning for this in remote frame


	CAN_MSG_TX(); //sending LED number for every 1 seconds


	tim_counter++;

	if(tim_counter==4){
		tim_counter=0;
		//N1 sending remote frame to N2
		TxHeader.DLC = 2; //N1 demanding 2 bytes of reply
		TxHeader.StdId = 0x651;
		TxHeader.IDE = CAN_ID_STD;
		TxHeader.RTR = CAN_RTR_REMOTE;

		if(HAL_CAN_AddTxMessage(&hcan1, &TxHeader, &msg, &TxMailbox) != HAL_OK){
			Error_Handler();
		}
	}


}
