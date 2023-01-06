/*
 * button.c
 *
 *  Created on: Dec 14, 2022
 *      Author: FPTSHOP
 */

#include "button.h"
#include "main.h"
#define NUMBER_OF_BUTTON 3

int button_list[NUMBER_OF_BUTTON] = {MODE_BUTTON_Pin, INCREASE_BUTTON_Pin, SET_BUTTON_Pin};
int KeyReg0[NUMBER_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUMBER_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUMBER_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUMBER_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeOutForKeyPress = 300;
int button_flag[NUMBER_OF_BUTTON] = {0, 0, 0};

int isButtonPressed(int index){
	if (button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	//TODO
	button_flag[index] = 1;
}

void getKeyInput(){
	for (int i = 0; i < NUMBER_OF_BUTTON; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(GPIOC, button_list[i]);
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
			  KeyReg3[i] = KeyReg2[i];

			  if (KeyReg3[i] == PRESSED_STATE){
				TimeOutForKeyPress = 600;
				subKeyProcess(i);
			  }
			}
			else {
			   TimeOutForKeyPress--;
				if (TimeOutForKeyPress == 0){
					if (KeyReg2[i] == PRESSED_STATE){
						subKeyProcess(i);
					}
					TimeOutForKeyPress = 100;
				}
			}
		}
	}
}
