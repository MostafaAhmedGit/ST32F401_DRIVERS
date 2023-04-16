/*************************************************************
 *
 * Filename: OS_INTERFACE.h
 * Description: Header (interface) file of the Schedular driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/
#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_


#include "Stdtypes.h"
#define TASK_COUNT	2
typedef void(*Task_CBF_t)(void);
 
 
 typedef struct{
	 
	 Task_CBF_t TASK_ptr;
	 u16 Task_Periodicity;
	 u8 state;
	 u16 first_delay;
	 u16 last_run;
	 u8 first_time;

 }TASK_t;

 typedef enum
 {
	 READY,
	 SUSPENDED
 }TASK_STATE_t;



		 void Create_voidTask(u8 TASK_Priority,u16 Periodicity,Task_CBF_t TASK_CBF,u8	 TASK_First_Time);
 void SCHED(void);
 void SCHED_voidSTART(void);

TASK_t TASKS_INFO[2];

#endif
