/*
 * button.h
 *
 *  Created on: Dec 14, 2022
 *      Author: FPTSHOP
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed(int);

void getKeyInput();

#endif /* INC_BUTTON_H_ */
