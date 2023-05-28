#ifndef TIMER0_TIMER0_INT_H_
#define TIMER0_TIMER0_INT_H_

#include "../../LIB/STD_TYPES.h"

/*PRESCALER OPTIONS*/
#define TIMER0_PRESCALER_NO_CLOCK        0
#define TIMER0_PRESCALER_1               1
#define TIMER0_PRESCALER_8               2
#define TIMER0_PRESCALER_64              3
#define TIMER0_PRESCALER_256             4
#define TIMER0_PRESCALER_1024            5
#define TIMER0_PRESCALER_FALLING_EDGE    6
#define TIMER0_PRESCALER_RAISING_EDGE    7


/*TIMER_MODES*/
#define        NORMAL_MODE   1
#define           CTC_MODE   2
#define PHASE_CORRECT_MODE   3
#define      FAST_PWM_MODE   4


#define TIMER0_OVF_ID 0
#define TIMER0_CMP_ID 1

/*FUNCTIONS PROTO-TYPES*/
void MTimer0_voidInit(u8 Copy_u8CompareMode, u8 Copy_u8TimerMode , u8 Copy_u8Prescaler);
void MTimer0_voidSetCMPValue(u8 Copy_u8Value);
void MTIMER0_void_setCallBack(void (*ptrfn)(void),u8 Copy_u8IntID);

#endif /* TIMER0_TIMER0_INT_H_ */
