/*
 * RTOS_prg.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Mariam
 */
#include "RTOS_cfg.h"
#include "RTOS_int.h"
#include "RTOS_prv.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../TIMER0/TIMER0_int.h"
#include "../TIMER0/TIMER0_prv.h"
#include "../GIE/GIE_int.h"

Task_t SystemTasks[TASK_NUM] = {{NULL}}; // 0 1 2

void RTOS_voidStart(void)
{
	MTIMER0_void_setCallBack(voidSchedular,TIMER0_CMP_ID);
	GIE_voidDisableGlobalInterrupt();
	MTimer0_voidInit(INERVERTING, CTC_MODE , TIMER0_PRESCALER_64);
}

u8 RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity, void(*Copy_pvTaskFunc)(void))
{
	u8 ErrState = OK;
	if (SystemTasks[Copy_u8Priority].TaskFunc == NULL)
	{
		SystemTasks[Copy_u8Priority].periodicity = Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc = Copy_pvTaskFunc;
	}
	else
	{
		ErrState = NOK;
	}
	return ErrState;
}

static void voidSchedular(void)
{
	static u16 Local_u16TickCounter = 0;
	Local_u16TickCounter++;

	u8 Local_u8TaskCounter;
	//check task priodicety
	for(Local_u8TaskCounter = 0 ; Local_u8TaskCounter<TASK_NUM; Local_u8TaskCounter++ )
	{
		if((Local_u8TaskCounter % SystemTasks[Local_u8TaskCounter].periodicity) == 0)
		{
			if((SystemTasks[Local_u8TaskCounter].TaskFunc) != NULL)
			{
				//execute task fuction
				SystemTasks[Local_u8TaskCounter].TaskFunc();
			}
			else
			{
				//do nothing
			}
		}
	}

}


