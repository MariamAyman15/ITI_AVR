#ifndef RTOS_STACK_RTOS_RTOS_PRV_H_
#define RTOS_STACK_RTOS_RTOS_PRV_H_

#include "../../LIB/STD_TYPES.h"

//STRUCT FOR TASKS
typedef struct
{
	u16 periodicity;
	void (*TaskFunc)(void);
	u8 First_Delay;

}Task_t;

//STATIC FUNCTION FOR SCHEDULAR
static void voidSchedular(void);

#endif /* RTOS_STACK_RTOS_RTOS_PRV_H_ */
