/*HEADER FILES INCLUDE*/
#include "Timer0_cfg.h"
#include "Timer0_int.h"
#include "Timer0_prv.h"

/*STD TYPES & BIT MATH HEADER FILES INCLUDE*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

void(*Global_CallBackArr[2])(void) = {0,0};
/*
static u32 NumOfMatches = 0;
static u32 NumOfTicks   = 0;
*/

/*INITIATE TIMER0*/
void MTimer0_voidInit(u8 Copy_u8CompareMode, u8 Copy_u8TimerMode , u8 Copy_u8Prescaler)
{
	TCCR0_REG &= 0b11001111;
	TCCR0_REG |= Copy_u8CompareMode << 4;

	//SELECT TIMER MODE
	switch(Copy_u8TimerMode)
	{
	//TO SELECT NORMAL MODE
	case NORMAL_MODE:
		CLR_BIT(TCCR0_REG,WGM01_BIT);
		CLR_BIT(TCCR0_REG,WGM00_BIT);

		SET_BIT(TIMSK_REG ,  TOIE0_BIT);
		break;

	//TO SELECT CTC MODE
	case CTC_MODE:
		SET_BIT(TCCR0_REG,WGM01_BIT);
		CLR_BIT(TCCR0_REG,WGM00_BIT);

		SET_BIT(TIMSK_REG ,OCIE0_BIT);
		break;

	//TO SELECT FAST PULSE WIDTH MODULATION MODE
	case FAST_PWM_MODE:
		SET_BIT(TCCR0_REG,WGM01_BIT);
		SET_BIT(TCCR0_REG,WGM00_BIT);

		break;

	//TO SELECT PHASE CORRECT MODE
	case PHASE_CORRECT_MODE:
		CLR_BIT(TCCR0_REG,WGM01_BIT);
		SET_BIT(TCCR0_REG,WGM00_BIT);

		break;

	default :
		//DO NOTHING
		break;
	}
	//SELECT PRESCALLER
	TCCR0_REG &= 0B11111000;
	TCCR0_REG |= Copy_u8Prescaler;
}

void MTimer0_voidSetCMPValue(u8 Copy_u8Value)
{
	//SET THE VALUE TI OCR0 REGISTER
	OCR0_REG = Copy_u8Value;
}

void MTIMER0_void_setCallBack(void (*ptrfn)(void),u8 Copy_u8IntID)
{

	if(Copy_u8IntID == TIMER0_OVF_ID || Copy_u8IntID == TIMER0_CMP_ID)
	Global_CallBackArr[Copy_u8IntID] = ptrfn;
}

/*CMP_Vector*/
/*void __vector_11(void) __attribute__ ((signal));
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


/*OVF_Vector*/
/*void __vector_12(void) __attribute__ ((signal));
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
}
*/
