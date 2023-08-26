/*
 * can_callbacks.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Ajith Pinninti
 */

#include "main.h"
#include <string.h>
#include <stdio.h>
static void LED_manage_output(uint8_t led_num);
static void Send_response(uint32_t stdId);

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
//	uint8_t recv_int8_t; // for number receving

	char msg[50];


	if(HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &RxHeader, rcvd_msg)!= HAL_OK){
		Error_Handler();
	}


	if(RxHeader.StdId == 0x65D && RxHeader.RTR == 0){

		//it's a data frame sent by n1 to n2

		LED_manage_output(rcvd_msg[0]);
		sprintf(msg,"Message Received: #%x \r\n",rcvd_msg[0]);

	}
	else if( RxHeader.StdId == 0x651 && RxHeader.RTR == CAN_RTR_REMOTE){
		//it's a remote frame sent by n1 to n2

		Send_response(RxHeader.StdId);
		return;
	}
	else if( RxHeader.StdId == 0x651 && RxHeader.RTR == CAN_RTR_DATA){
		// It's a reply(dataframe) by n2 to n1

		sprintf(msg,"Reply Received : %#X \r\n",rcvd_msg[0]<<8 | rcvd_msg[1]);

	}
	HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg),HAL_MAX_DELAY);

}


static void LED_manage_output(uint8_t led_num){

	switch(led_num){

	case 1:
		__HAL_TIM_SET_AUTORELOAD(&htim13,250);
		break;
	case 2:
		__HAL_TIM_SET_AUTORELOAD(&htim13,500);
		break;
	case 3:
		__HAL_TIM_SET_AUTORELOAD(&htim13,750);
		break;
	case 4:
		__HAL_TIM_SET_AUTORELOAD(&htim13,1000);
		break;

	}

}

static void Send_response(uint32_t stdId){

	CAN_TxHeaderTypeDef TxHeader;

	uint32_t TxMailbox;

	uint8_t response[2] = {0xAB, 0xCD };

	TxHeader.DLC = 2;
	TxHeader.StdId = stdId;
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.RTR = CAN_RTR_DATA;

	if( HAL_CAN_AddTxMessage(&hcan1, &TxHeader, response, &TxMailbox) != HAL_OK){
		Error_Handler();
	}
}
