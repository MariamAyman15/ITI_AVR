#ifndef  TIMER_INTERFACE_H_
#define  TIMER_INTERFACE_H_


#define TIMER1_CHANNEL_A       1
#define TIMER1_CHANNEL_B       2


#define DISCONNECT					0
#define TOGGLE						1
#define CLEAR						2
#define SET							3

#define NON_INVERTING         	  2
#define INVERTING       		  3


#define NORMAL_MODE         	  1
#define CTC_MODE       			  2
#define FASTPWM_MODE       		  3
#define PHASECHORECT_MODE         4

#define PRESCALER_DIV_BY_1        1
#define PRESCALER_DIV_BY_8        2
#define PRESCALER_DIV_BY_64       3
#define PRESCALER_DIV_BY_256      4
#define PRESCALER_DIV_BY_1024     5

#define ICU_FALLING_EDGE          1
#define ICU_RISING_EDGE			  2


#define TIMER0_OVERFLOW_INT			0
#define TIMER0_OUTPUT_COM_INT		1

#define TIMER1_OVERFLOW_INT			2
#define TIMER1_OUTPUT_COM_A_INT		3
#define TIMER1_OUTPUT_COM_B_INT		4
#define TIMER1_ICU_INT				5

//timer0
void TIMER0_voidInit(u8 Copy_u8CompareMode, u8 Copy_u8TimerMode , u8 Copy_u8Prescaler);
void TIMER0_voidSetCompareMatchValue(u8 Copy_u8Value);

//timer1
void TIMER1_voidInit(u8 Copy_u8Channel ,u8 Copy_u8CompareMode, u8 Copy_u8TimerMode , u8 Copy_u8Prescaler);
void TIMER1_voidSetCompareMatchValue(u8 Copy_u8Channel ,u16 Copy_u16Value);
void TIMER1_voidSetMode_14(u8 Copy_u8Channel ,u8 Copy_u8CompareMode , u8 Copy_u8Prescaler);
void TIMER1_voidSetTopValueMode_14(u16 Copy_u16TopValue);
u16  TIMER1_voidu16ReadTimerValue(void);
void TIMER_voidSetCallBack(u8 Copy_u8INT_ID,void (*Copy_pvCallBackFunc)(void));

//timer2
void TIMER2_voidInit(u8 Copy_u8CompareMode, u8 Copy_u8TimerMode , u8 Copy_u8Prescaler);
void TIMER2_voidSetCompareMatchValue(u8 Copy_u8Value);

void ICU_voidInit(void);
void ICU_SetTriggerEdge( u8 Copy_u8Edge);
u16 ICU_u16ReadICU(void);


#endif
