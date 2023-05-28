#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATHS.h"

#include "TIMER_CONFIG.h"
#include "TIMER_INTERFACE.h"
#include "TIMER_PRIVATE.h"


/*void	(*TIMER_pvCallBackFunc[6])(void);

void TIMER0_voidInit(u8 Copy_u8CompareMode, u8 Copy_u8TimerMode , u8 Copy_u8Prescaler)
{
	TCCR0 &= 0b11001111;
	TCCR0 |= Copy_u8CompareMode << 4;
	switch(Copy_u8TimerMode)
	{
	case NORMAL_MODE:
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		SET_BIT(TIMSK ,  0);
		break;
	case CTC_MODE:
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		SET_BIT(TIMSK ,  1);
		break;
	case FASTPWM_MODE:
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		break;
	case PHASECHORECT_MODE:
		CLR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		break;
	default :

		break;
	}

	TCCR0 &= 0B11111000;
	TCCR0 |= Copy_u8Prescaler;
}

void TIMER0_voidSetCompareMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}
*/

void TIMER1_voidInit(u8 Copy_u8Channel ,u8 Copy_u8CompareMode, u8 Copy_u8TimerMode , u8 Copy_u8Prescaler)
{
	if( Copy_u8Channel == TIMER1_CHANNEL_A)
	{
		TCCR1A &= 0b00111111;
		TCCR1A |= Copy_u8CompareMode << 6;
		switch(Copy_u8TimerMode)
		{
		case NORMAL_MODE:
			CLR_BIT(TCCR1A , 0);
			CLR_BIT(TCCR1A , 1);

			//SET_BIT(TIMSK ,  2);
			break;
		case CTC_MODE:
			CLR_BIT(TCCR1A , 0);
			CLR_BIT(TCCR1A , 1);

			SET_BIT(TIMSK ,  4);
			break;
		case FASTPWM_MODE:
			CLR_BIT(TCCR1A , 0);
			SET_BIT(TCCR1A , 1);
			break;
		case PHASECHORECT_MODE:
			CLR_BIT(TCCR1A , 0);
			SET_BIT(TCCR1A , 1);
			break;
		default :

			break;
		}
	}
	else if( Copy_u8Channel == TIMER1_CHANNEL_B)
	{
		TCCR1B &= 0b11001111;
		TCCR1B |= Copy_u8CompareMode << 4;
		switch(Copy_u8TimerMode)
		{
		case NORMAL_MODE:
			CLR_BIT(TCCR1B , 3);
			CLR_BIT(TCCR1B , 4);

			SET_BIT(TIMSK ,  2);
			break;
		case CTC_MODE:
			SET_BIT(TCCR1B , 3);
			CLR_BIT(TCCR1B , 4);

			SET_BIT(TIMSK ,  3);
			break;
		case FASTPWM_MODE:
			SET_BIT(TCCR1B , 3);
			SET_BIT(TCCR1B , 4);
			break;
		case PHASECHORECT_MODE:
			CLR_BIT(TCCR1B , 3);
			SET_BIT(TCCR1B , 4);
			break;
		default :

			break;
		}
	}
	else
	{

	}
	TCCR1B &= 0b11111000;
	TCCR1B |= Copy_u8Prescaler;
}

void TIMER1_voidSetCompareMatchValue(u8 Copy_u8Channel ,u16 Copy_u16Value)
{
	switch(Copy_u8Channel)
	{
	case TIMER1_CHANNEL_A:
		OCR1A = Copy_u16Value;
		break;
	case TIMER1_CHANNEL_B:
		OCR1B = Copy_u16Value;
		break;
	default:
		break;
	}
}

u16 TIMER1_voidu16ReadTimerValue(void)
{
	return TCNT1;
}


void TIMER1_voidSetMode_14(u8 Copy_u8Channel ,u8 Copy_u8CompareMode , u8 Copy_u8Prescaler)
{
	CLR_BIT(TCCR1A , 0);
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);

	if( Copy_u8Channel == TIMER1_CHANNEL_A)
	{
		TCCR1A &= 0b00111111;
		TCCR1A |= Copy_u8CompareMode << 6;
	}
	else if( Copy_u8Channel == TIMER1_CHANNEL_B)
	{
		TCCR1B &= 0b11001111;
		TCCR1B |= Copy_u8CompareMode << 4;
	}
	else
	{

	}
	TCCR1B &= 0b11111000;
	TCCR1B |= Copy_u8Prescaler;
}

void TIMER1_voidSetTopValueMode_14(u16 Copy_u16TopValue)
{
	ICR1 = Copy_u16TopValue;
}


void ICU_voidInit(void)
{
	SET_BIT(TCCR1B , 6);   // set Rising
	SET_BIT(SREG_REG,7);   //TO ENABLE GLOBAL INT


	/*Set Normal mode */
	CLR_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	/*TIMER OVERFLOW INTERRUPT ENABLLED*/
	SET_BIT(TIMSK,2);
	/*ICU INTERRUPT ENABLLED*/
	SET_BIT(TIMSK,5);

	TCCR1B &= 0b11111000;
	TCCR1B |= PRESCALER_DIV_BY_8;
}

void ICU_SetTriggerEdge( u8 Copy_u8Edge)
{
	switch(Copy_u8Edge)
	{
	case ICU_FALLING_EDGE:
		CLR_BIT(TCCR1B , 6);
		break;
	case ICU_RISING_EDGE:
		SET_BIT(TCCR1B , 6);
		break;
	default:
		break;

	}
}

u16 ICU_u16ReadICU(void)
{
	return ICR1;
}


/*void TIMER_voidSetCallBack(u8 Copy_u8INT_ID,void (*Copy_pvCallBackFunc)(void))
{
	TIMER_pvCallBackFunc[Copy_u8INT_ID] = Copy_pvCallBackFunc;
}

void __vector_6 (void) __attribute__ ((signal));
void __vector_6 (void)
{
	TIMER_pvCallBackFunc[TIMER1_ICU_INT]();
}

void __vector_7 (void) __attribute__ ((signal));
void __vector_7 (void)
{
	TIMER_pvCallBackFunc[TIMER1_OUTPUT_COM_A_INT]();
}

void __vector_8 (void) __attribute__ ((signal));
void __vector_8 (void)
{
	TIMER_pvCallBackFunc[TIMER1_OUTPUT_COM_B_INT]();
}

void __vector_9 (void) __attribute__ ((signal));
void __vector_9 (void)
{
	TIMER_pvCallBackFunc[TIMER1_OVERFLOW_INT]();
}

void __vector_10 (void)	__attribute__((signal));
void __vector_10 (void)
{

	TIMER_pvCallBackFunc[TIMER0_OUTPUT_COM_INT]();
}

void __vector_11 (void)	__attribute__((signal));
void __vector_11 (void)
{
	TIMER_pvCallBackFunc[TIMER0_OVERFLOW_INT]();
}*/

/******TIMER 2******/
void TIMER2_voidInit(u8 Copy_u8CompareMode, u8 Copy_u8TimerMode , u8 Copy_u8Prescaler)
{
	TCCR2 &= 0b11001111;
	TCCR2 |= Copy_u8CompareMode << 4;
	switch(Copy_u8TimerMode)
	{
	case NORMAL_MODE:
		CLR_BIT(TCCR2,3);
		CLR_BIT(TCCR2,6);

		SET_BIT(TIMSK ,  0);
		break;
	case CTC_MODE:
		SET_BIT(TCCR2,3);
		CLR_BIT(TCCR2,6);

		SET_BIT(TIMSK ,  1);
		break;
	case FASTPWM_MODE:
		SET_BIT(TCCR2,3);
		SET_BIT(TCCR2,6);

		break;
	case PHASECHORECT_MODE:
		CLR_BIT(TCCR2,3);
		SET_BIT(TCCR2,6);

		break;
	default :

		break;
	}

	TCCR2 &= 0B11111000;
	TCCR2 |= Copy_u8Prescaler;
}

void TIMER2_voidSetCompareMatchValue(u8 Copy_u8Value)
{
	OCR2 = Copy_u8Value;
}

