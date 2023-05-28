/*
 * TIMERS_int.h
 *
 *  Created on: Apr 2, 2023
 *      Author: Mariam
 */

#ifndef MCAL_TIMERS_TIMERS_INT_H_
#define MCAL_TIMERS_TIMERS_INT_H_

#include "STD_TYPES.h"
#define NORMAL_MODE      0
#define    CTC_MODE      1
#define    FAST_PWM      2
#define PHASE_CHORECT    4

#define TIMER0_OVF_ID 0
#define TIMER0_CMP_ID 1

void MTimer0_voidInit(u8 Copy_u8TimerMode, u8 Copy_u8Prescaller);
void MTimer0_voidSetCompMatchVal (u8 Copy_u8Value);
void M_TIMER0_void_setCallBack(void (*ptrfn)(void),u8 Copy_u8IntID);


#endif /* MCAL_TIMERS_TIMERS_INT_H_ */
