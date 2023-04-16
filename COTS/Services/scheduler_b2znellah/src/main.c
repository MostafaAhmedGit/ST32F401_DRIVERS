/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "RCC.h"
#include "GPIO.h"
#include "SYSTCK.h"
#include "OS_interface.h"
// --------------------------- -------------------------------------------------
//
// Standalone STM32F4 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"


void func(void)
{
	static u8 local;

	GPIO_enuSetPinValue(GPIO_PORT_C,GPIO_PIN_13,local);

	local^=1;
}
void func2(void)
{
	static u8 local;

	local^=1;

	GPIO_enuSetPinValue(GPIO_PORT_C,GPIO_PIN_14,local);


}
int
main(int argc, char* argv[])
{
	RCC_enuEnableHSE();
	RCC_enuControlPeripheralAHB1(RCC_enuON,GPIOCEN_AHB1);


	GPIO_enuSetPinDirection(GPIO_PORT_C,GPIO_PIN_13,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
	GPIO_enuSetPinDirection(GPIO_PORT_C,GPIO_PIN_14,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);


	SCHED_voidSTART();
	  Create_voidTask(0,500,func,1);
	  Create_voidTask(1,250,func2,1);

	  Systck_Call_each_Period(1,25000000UL,SCHED);



	while (1)
    {


    }
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
