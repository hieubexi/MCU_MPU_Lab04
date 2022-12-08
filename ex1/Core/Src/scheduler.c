/*
 * scheduler.c
 *
 *  Created on: Nov 11, 2022
 *      Author: hieun
 */


#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;
uint8_t current_task = 0;

void SCH_Init(void){
	unsigned char i;
	for( i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
}

void SCH_Add_Task ( void (*pFunction)() ,uint32_t DELAY, uint32_t PERIOD){
		if(current_index_task < SCH_MAX_TASKS){

			SCH_tasks_G[current_index_task].pTask = pFunction;
			SCH_tasks_G[current_index_task].Delay = DELAY/TIME_CYCLE;
			SCH_tasks_G[current_index_task].Period =  PERIOD/TIME_CYCLE;
			SCH_tasks_G[current_index_task].RunMe = 0;

			SCH_tasks_G[current_index_task].TaskID = current_index_task;

			current_index_task++;
		}else return ;
}

void SCH_Update(void){

	for(current_task = 0; current_task < current_index_task; current_task++){
		if(SCH_tasks_G[current_task].Delay > 0){
			SCH_tasks_G[current_task].Delay-- ;
		}else{
			SCH_tasks_G[current_task].Delay = SCH_tasks_G[current_task].Period;
			SCH_tasks_G[current_task].RunMe += 1 ;
		}

	}

}
void SCH_Dispatch_Tasks(void){
	for(int i = 0; i < current_index_task; i++){
		if(SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if(SCH_tasks_G[i].Period <= 0) SCH_Delete_Task(i) ;
		}
	}
}
void SCH_Delete_Task(const uint32_t TASK_INDEX){
	if(current_index_task <= 0 ) return ;
	if(SCH_tasks_G[TASK_INDEX].pTask == 0x0000) return ;
	if(TASK_INDEX == current_index_task - 1){
		SCH_tasks_G[current_index_task - 1].pTask = 0x0000;
		SCH_tasks_G[current_index_task - 1].Delay = 0 ;
		SCH_tasks_G[current_index_task - 1].Period = 0 ;
		SCH_tasks_G[current_index_task - 1].RunMe = 0;
		current_index_task--;
	}
	if(TASK_INDEX == 0){
		for(int  i = 1 ; i < current_index_task; i++){
			SCH_tasks_G[i] = SCH_tasks_G[i+1] ;
		}
		current_index_task--;
	}else{
		for( int i = TASK_INDEX ; i < current_index_task ; i++){
			SCH_tasks_G[i] = SCH_tasks_G[i+1] ;
		}
		current_index_task--;
	}
	SCH_tasks_G[current_index_task].pTask = 0x0000;
	SCH_tasks_G[current_index_task].Delay = 0 ;
	SCH_tasks_G[current_index_task].Period = 0 ;
	SCH_tasks_G[current_index_task].RunMe = 0;
}

