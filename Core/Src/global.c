/*
 * global.c
 *
 *  Created on: Dec 14, 2022
 *      Author: FPTSHOP
 */

#include "global.h"
#include "main.h"

int red_light_duration = 6000;
int yellow_light_duration = 2000;
int green_light_duration = 4000;

int temp_red_duration = 0;
int temp_yellow_duration = 0;
int temp_green_duration = 0;

int red_light_counter = 0;
int green_light_counter = 0;
int yellow_light_counter = 0;

int status = INIT;
int led_counter = 0;

void display7SEG(uint8_t number){
	switch (number){
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
		break;
	default:
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
		break;
	}
}

void resetAllLED(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin, SET);

	HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, SET);
}


