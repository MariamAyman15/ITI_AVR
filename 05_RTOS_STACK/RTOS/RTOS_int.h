/*
 * RTOS_int.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Mariam
 */

#ifndef RTOS_STACK_RTOS_RTOS_INT_H_
#define RTOS_STACK_RTOS_RTOS_INT_H_
#include "../../LIB/STD_TYPES.h"

#define OK   0
#define NOK  1

void RTOS_voidStart(void);
u8 RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity, void(*Copy_pvTaskFunc)(void));

#endif /* RTOS_STACK_RTOS_RTOS_INT_H_ */
