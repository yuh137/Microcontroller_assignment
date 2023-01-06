/*
 * fsm.c
 *
 *  Created on: Dec 14, 2022
 *      Author: FPTSHOP
 */

#include "fsm.h"

void fsm(){
	switch (status){
	case INIT:
		setTimer1(1000);
		setTimer2(green_light_duration);
		led_counter = green_light_duration;
//		display7SEG(led_counter);
		status = NORTH_RED_EAST_GREEN;
		break;
	case NORTH_RED_EAST_GREEN:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);

		if (timer1_flag == 1){
			led_counter -= 1000;
//			display7SEG(led_counter);
			setTimer1(1000);
		}

		if (isButtonPressed(MODE_BUTTON)){
			status = MODIFY_RED;
			temp_red_duration = red_light_duration;
			temp_green_duration = green_light_duration;
			led_counter = temp_red_duration;
//			display7SEG(led_counter);
			resetAllLED();
			setTimer1(10);
		}

		if (timer2_flag == 1){
			status = NORTH_RED_EAST_YELLOW;
			led_counter = yellow_light_duration;
//			display7SEG(led_counter);
			setTimer2(yellow_light_duration);
		}
		break;
	case NORTH_RED_EAST_YELLOW:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);

		if (timer1_flag == 1){
			led_counter -= 1000;
//			display7SEG(led_counter);
			setTimer1(1000);
		}

		if (isButtonPressed(MODE_BUTTON)){
			status = MODIFY_RED;
			temp_red_duration = red_light_duration;
			temp_green_duration = green_light_duration;
			led_counter = temp_red_duration;
//			display7SEG(led_counter);
			resetAllLED();
			setTimer1(10);
		}

		if (timer2_flag == 1){
			status = EAST_RED_NORTH_GREEN;
			led_counter = red_light_duration;
//			display7SEG(led_counter);
			setTimer2(green_light_duration);
		}
		break;
	case EAST_RED_NORTH_GREEN:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);

		if (timer1_flag == 1){
			led_counter -= 1000;
//			display7SEG(led_counter);
			setTimer1(1000);
		}

		if (isButtonPressed(MODE_BUTTON)){
			status = MODIFY_RED;
			temp_red_duration = red_light_duration;
			temp_green_duration = green_light_duration;
			led_counter = temp_red_duration;
			display7SEG(led_counter);
			resetAllLED();
			setTimer1(10);
		}

		if (timer2_flag == 1){
			status = EAST_RED_NORTH_YELLOW;
//			led_counter = red_light_duration;
			setTimer2(yellow_light_duration);
		}
		break;
	case EAST_RED_NORTH_YELLOW:
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);

		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);

		if (timer1_flag == 1){
			led_counter -= 1000;
//			display7SEG(led_counter);
			setTimer1(1000);
		}

		if (isButtonPressed(MODE_BUTTON)){
			status = MODIFY_RED;
			temp_red_duration = red_light_duration;
			temp_green_duration = green_light_duration;
			led_counter = temp_red_duration;
//			display7SEG(led_counter);
			resetAllLED();
			setTimer1(10);
		}

		if (timer2_flag == 1){
			status = INIT;
		}
		break;
	case MODIFY_RED:
		//RED_LED blink
//		resetAllLED();
		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(GPIOA, LED_RED_1_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_RED_2_Pin);

			setTimer1(500);
		}

		if (isButtonPressed(INCREASE_BUTTON)){
			temp_red_duration += 1000;
			temp_green_duration += 1000;
			if (temp_red_duration > 9000){
				temp_red_duration = 9000;
				temp_green_duration = 9000 - yellow_light_duration;
			}
			led_counter = temp_red_duration;
//			display7SEG(led_counter);
		}

		if (isButtonPressed(MODE_BUTTON)){
			red_light_duration = temp_red_duration;
			green_light_duration = temp_green_duration;
			status = MODIFY_YELLOW;
			resetAllLED();
			temp_red_duration = red_light_duration;
			temp_yellow_duration = yellow_light_duration;
			led_counter = temp_yellow_duration;
//			display7SEG(led_counter);
			setTimer1(10);
		}

		if (isButtonPressed(SET_VALUE_BUTTON)){
			red_light_duration = temp_red_duration;
			green_light_duration = temp_green_duration;
		}
		break;
	case MODIFY_YELLOW:
//		resetAllLED();
		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_1_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_2_Pin);

			setTimer1(500);
		}

		if (isButtonPressed(INCREASE_BUTTON)){
			temp_red_duration += 1000;
			temp_yellow_duration += 1000;
			if (temp_yellow_duration + green_light_duration > 9000){
				temp_yellow_duration = 9000 - green_light_duration;
				temp_red_duration = 9000;
			}
			led_counter = temp_yellow_duration;
//			display7SEG(led_counter);
		}

		if (isButtonPressed(MODE_BUTTON)){
			red_light_duration = temp_red_duration;
			yellow_light_duration = temp_yellow_duration;
			status = MODIFY_GREEN;
			resetAllLED();
			temp_red_duration = red_light_duration;
			temp_green_duration = green_light_duration;
			led_counter = temp_green_duration;
//			display7SEG(led_counter);
			setTimer1(10);
		}


		if (isButtonPressed(SET_VALUE_BUTTON)){
			red_light_duration = temp_red_duration;
			yellow_light_duration = temp_yellow_duration;
		}
		break;
	case MODIFY_GREEN:
//		resetAllLED();
		if (timer1_flag == 1){
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_1_Pin);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_2_Pin);

			setTimer1(500);
		}

		if (isButtonPressed(INCREASE_BUTTON)){
			temp_green_duration += 1000;
			temp_red_duration += 1000;
			if (temp_green_duration + yellow_light_duration > 9000){
				temp_green_duration = 9000 - yellow_light_duration;
				temp_red_duration = 9000;
			}
			led_counter = temp_green_duration;
//			display7SEG(led_counter);
		}

		if (isButtonPressed(MODE_BUTTON)){
			red_light_duration = temp_red_duration;
			green_light_duration = temp_green_duration;
			status = INIT;
		}

		if (isButtonPressed(SET_VALUE_BUTTON)){
			red_light_duration = temp_red_duration;
			green_light_duration = temp_green_duration;
		}
		break;
	default:
		break;
	}
}
