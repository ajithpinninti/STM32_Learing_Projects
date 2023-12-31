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
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){

	CAN_RxHeaderTypeDef RxHeader;

	uint8_t rcvd_msg[5]; // for hello string
	uint8_t recv_int8_t; // for number receving

	char msg[50];


	if(HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &RxHeader, &recv_int8_t)!= HAL_OK){
		Error_Handler();
	}


	sprintf(msg,"Receieved: %d \r\n",recv_int8_t);
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg),HAL_MAX_DELAY);
}

