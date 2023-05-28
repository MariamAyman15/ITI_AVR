/*
 * TIMERS_prg.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mariam
 */
#include "TIMERS_cfg.h"
#include "TIMERS_prv.h"
#include "TIMERS_int.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

/*void(*Global_CallBackArr[2])(void) = {0,0};
static u32 NumOfMatches = 0;
static u32 NumOfTicks   = 0;*/

/*void MTimer0_voidInit(u8 Copy_u8TimerMode,u8 Copy_u8Prescaller)
{
	switch(Copy_u8TimerMode)
	{
	//INTERVAL_MODE
	case NORMAL_MODE:
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		CLR_BIT(TCCR0_REG,WGM01_BIT);
		SET_BIT(TIMSK_REG,TOIE0_BIT);
		break;

		//CTC_MODE
	case CTC_MODE:
		CLR_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);
		SET_BIT(TIMSK_REG,OCIE0_BIT);
		break;

		//FAST PWM
	case FAST_PWM:
		SET_BIT(TCCR0_REG,WGM00_BIT);
		SET_BIT(TCCR0_REG,WGM01_BIT);

        #if PWM_MODE == INVERTING_MODE
		SET_BIT(TCCR0_REG,COM00_BIT);
		SET_BIT(TCCR0_REG,COM01_BIT);
        #elif PWM_MODE == NON_INVERTING_MODE
		CLR_BIT(TCCR0_REG,COM00_BIT);
		SET_BIT(TCCR0_REG,COM01_BIT);
        #endif
		break;

	default:
		//DO NOTHING
		break;
	}

	//SET PRESCALLER VALUE
	TCCR0_REG &= 0b11111000;
	TCCR0_REG |= Copy_u8Prescaller;
}

void MTimer0_voidSetCompMatchVal (u8 Copy_u8Value)
{
	OCR0_REG = Copy_u8Value;
}*/

/*void M_TIMER0_void_setCallBack(void (*ptrfn)(void),u8 Copy_u8IntID)
{

	if(Copy_u8IntID == TIMER0_OVF_ID || Copy_u8IntID == TIMER0_CMP_ID)
		Global_CallBackArr[Copy_u8IntID] = ptrfn;
}*/

/*CMP_Vector
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)
{
	static u32 CMP_Counter = 0;
	CMP_Counter++;
	if(CMP_Counter == NumOfMatches)
	{
		if(Global_CallBackArr[TIMER0_CMP_ID] != '\0')
		{
			Global_CallBackArr[TIMER0_CMP_ID]();
		}
		CMP_Counter = 0;
	}
}*/
/*OVF_Vector
void __vector_12(void) __attribute__ ((signal));
void __vector_12(void)
{
	static u32 OVR_Counter = 0;
	OVR_Counter++;
	if(OVR_Counter == NumOfTicks)
	{
		if(Global_CallBackArr[TIMER0_OVF_ID] != '\0')
		{
			Global_CallBackArr[TIMER0_OVF_ID]();
		}
	}
}*/
