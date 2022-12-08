/*
 * software_timer.c
 *
 *  Created on: Sep 23, 2022
 *      Author: hieun
 */
#include "software_timer.h"
#define TIME_CYCLE 10

int timer_flag[NUM_TIMER] = {0,0,0};
int timer_counter[NUM_TIMER] = {0,0,0};



int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

void setTimer(int duration, int i){
	timer_counter[i] = duration/TIME_CYCLE ;
	timer_flag[i] = 0 ;
}
void setTimer2(int duration){
	timer2_counter = duration/TIME_CYCLE;
	timer2_flag = 0;
}
void setTimer1(int duration){
	timer1_counter = duration/TIME_CYCLE;
	timer1_flag = 0;
}
void timerRun(){
	for( int i = 0; i < NUM_TIMER; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] == 0){
				timer_flag[i] = 1 ;
			}
		}
	}
/*	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0){
			timer1_flag = 1;
		}
	}

	if(timer2_counter > 0){
			timer2_counter--;
			if(timer2_counter == 0){
				timer2_flag = 1;
			}
		}
*/
}
void timerRun1(){

	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0){
			timer1_flag = 1;
		}
	}

	if(timer2_counter > 0){
			timer2_counter--;
			if(timer2_counter == 0){
				timer2_flag = 1;
			}
		}

}
