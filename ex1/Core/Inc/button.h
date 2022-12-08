/*
 * button.h
 *
 *  Created on: Oct 28, 2022
 *      Author: hieun
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define NUM_OF_BUTTONS 2
int  isButton1Pressed();
int  isButton2Pressed();
void getKeyInput();


#endif /* INC_BUTTON_H_ */
