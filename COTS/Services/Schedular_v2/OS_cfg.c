
/*************************************************************
 *
 * Filename: OS_CFG.c
 * Description: Header (interface) file of the Schedular driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 *
 *************************************************************/
#ifndef OS_CFG_H_
#define OS_CFG_H_

#include "OS_interface.h"
#include "APP_ONE.h"
#include "APP_TWO.h"




TASK_t TASKS_INFO[2] =
{
		[0] =
		{
				 .TASK_ptr = LED_BLINK,
				 .Task_Periodicity = 250,
				 .first_time=1,

		},

		[1] =
		{
				 .TASK_ptr = LED_BLINK2,
				 .Task_Periodicity = 500,
				 .first_time=1,

		}
};





#endif
