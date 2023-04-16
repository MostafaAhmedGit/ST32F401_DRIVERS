/*************************************************************
 *
 * Filename: OS_PROGRAM.c
 * Description: Header (interface) file of the Schedular driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/


#include "Bitmath.h"

#include "OS_interface.h"

#include "SYSTCK.h"








// Array of structs "
static TASK_t OS_TASKS[TASK_COUNT] = {NULL};




 void Create_voidTask(u8 TASK_Priority,u16 Periodicity,Task_CBF_t TASK_CBF,u8 TASK_First_Time)
 {
	 OS_TASKS[TASK_Priority].Task_Periodicity = Periodicity;
	 OS_TASKS[TASK_Priority].TASK_ptr = TASK_CBF;
	 OS_TASKS[TASK_Priority].first_time = TASK_First_Time;
	 
 }
 void SCHED_voidSTART(void)
 {
	 Systck_voidEnable(AHB_DIVIDED_BY_ONE);
	 Systck_voidEnableException();
 }
 
 
 
 // WILL BE CALLED IN THE systick cbf
 void SCHED(void)
 {
	 static u64 Tick_count;
	 Tick_count++;
	 for(u8 TASK_Priority=0;TASK_Priority<TASK_COUNT;TASK_Priority++)
	 {
		 if(OS_TASKS[TASK_Priority].first_time||(Tick_count-OS_TASKS[TASK_Priority].last_run)==OS_TASKS[TASK_Priority].Task_Periodicity)
		 {
			 // CALLS THE TASK ACCORDING TO THE PERIODICITY
			 
			 OS_TASKS[TASK_Priority].TASK_ptr(); 
			 OS_TASKS[TASK_Priority].last_run  = Tick_count;
			 OS_TASKS[TASK_Priority].first_time  = 0;
		 }
	 }
	 if(Tick_count==0xFFFFFFFFFFFF)
	 {
		 Tick_count = 0;
	 }

 }
