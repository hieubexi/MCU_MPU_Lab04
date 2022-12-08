/*
 * button.h
 *
 *  Created on: Oct 28, 2022
 *      Author: hieun
 */



#include "button.h"
int button1_flag = 0 ;
int button2_flag = 0 ;
int KeyReg0[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE};



int TimeOutForKeyPress[NUM_OF_BUTTONS] =  {200, 200};


int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0 ;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0 ;
}
void subKey1Process(){
	button1_flag = 1 ;
}
void subKey2Process(){
	button2_flag = 1 ;
}
void getKey1(){
	  KeyReg2[0] = KeyReg1[0];
	  KeyReg1[0] = KeyReg0[0];
	  KeyReg0[0] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	  if ((KeyReg1[0] == KeyReg0[0]) && (KeyReg1[0] == KeyReg2[0])){
	    if (KeyReg2[0] != KeyReg3[0]){
	      KeyReg3[0] = KeyReg2[0];
	      if (KeyReg3[0] == PRESSED_STATE){
	        TimeOutForKeyPress[0] = 200;
	        subKey1Process();
	      }
	    }else{
	       TimeOutForKeyPress[0] --;
	        if (TimeOutForKeyPress[0] == 0){
	          KeyReg3[0] = NORMAL_STATE;
	        }
	    }
	  }
}
/*
void getKey2(){
		KeyReg2[1] = KeyReg1[1];
	  	KeyReg1[1]= KeyReg0[1];
	  	KeyReg0[1] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	  	if ((KeyReg1[1] == KeyReg0[1]) && (KeyReg1[1] == KeyReg2[1])){
	  	   if (KeyReg2[1] != KeyReg3[1]){
	  	      KeyReg3[1] = KeyReg2[1];

	  	      if (KeyReg3[1] == PRESSED_STATE){
	  	        TimeOutForKeyPress[1] = 200;
	  	        subKey2Process();
	  	      }
	  	    }else{
	  	       TimeOutForKeyPress[1] --;
	  	        if (TimeOutForKeyPress[1] == 0){
	  	          KeyReg3[1] = NORMAL_STATE;
	  	        }
	  	    }
	  	  }
}
*/
void getKeyInput(){
	getKey1();
//	getKey2() ;

}

