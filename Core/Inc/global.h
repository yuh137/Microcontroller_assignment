/*
 * global.h
 *
 *  Created on: Dec 14, 2022
 *      Author: FPTSHOP
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "main.h"

#define INIT 						3
#define NORTH_RED_EAST_GREEN		4
#define NORTH_RED_EAST_YELLOW		5
#define EAST_RED_NORTH_GREEN		6
#define EAST_RED_NORTH_YELLOW		7
#define MODIFY_RED					8
#define MODIFY_YELLOW				9
#define MODIFY_GREEN				10

#define MODE_BUTTON					0
#define INCREASE_BUTTON				1
#define SET_VALUE_BUTTON			2

extern int status;
extern int led_counter;

extern int red_light_duration;
extern int yellow_light_duration;
extern int green_light_duration;

extern int red_light_counter;
extern int yellow_light_counter;
extern int green_light_counter;

extern int temp_red_duration;
extern int temp_yellow_duration;
extern int temp_green_duration;

void display7SEG(uint8_t);
void resetAllLED();

#endif /* INC_GLOBAL_H_ */
