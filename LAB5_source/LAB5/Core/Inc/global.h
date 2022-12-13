/*
 * global.h
 *
 *  Created on: Dec 9, 2022
 *      Author: hieun
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 	0
#define _ 		1
#define _R		2
#define _RS		3
#define _RST	4
#define _RST_	5

#define _O		11
#define _OK		12
#define _OK_	13

#define SEND	20
#define END		21
#define WAIT	22
#define MAX_BUFFER_SIZE 30
extern uint8_t temp ;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

#endif /* INC_GLOBAL_H_ */
