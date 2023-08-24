/*
 * can_callbacks.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ajith Pinninti
 */

#include "main.h"
#include <string.h>
#include <stdio.h>

void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan){
	uint8_t msg[50];

	sprintf((char*)msg,"Message Transmitted \r");
	HAL_UART_Transmit(&huart2, msg, strlen((char*)msg), HAL_MAX_DELAY);

}


void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan){

	uint8_t msg[50];

	sprintf((char*)msg,"Message Transmitted \r");
	HAL_UART_Transmit(&huart2, msg, strlen((char*)msg), HAL_MAX_DELAY);

}
void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan){
	uint8_t msg[50];

	sprintf((char*)msg,"Message Transmitted \r");
	HAL_UART_Transmit(&huart2, msg, strlen((char*)msg), HAL_MAX_DELAY);

}
