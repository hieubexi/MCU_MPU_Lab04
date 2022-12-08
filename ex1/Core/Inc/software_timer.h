/*
 * software_timer.h
 *
 *  Created on: Sep 23, 2022
 *      Author: hieun
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#define NUM_TIMER	3
extern int timer_flag[NUM_TIMER];
extern int timer1_flag;
extern int timer2_flag;
void setTimer(int duration, int index) ;
void setTimer1(int duration);
void setTimer2(int duration);
void timerRun();
void timerRun1();



#endif /* INC_SOFTWARE_TIMER_H_ */
