#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_prv.h"
#include "ADC_int.h"
#include "ADC_cfg.h"

//#define NULL  		((void*)0)

//static void (*SGlobal_ptrFunc)(void); //=null
//static u16	 * SGlobal_ptrU16ADCValue; //=null

void MADC_voidInit (void)
{
	// Voltage Difference Reference
	//INTERNAL VOLTAGE WITH EXTERNAL CAPACITOR AT AREF PIN
#if VOLTAGE_DIFF_REF == V_REF
	SET_BIT(ADMUX , REFS0);
	SET_BIT(ADMUX , REFS1);

	//A-REF
#elif VOLTAGE_DIFF_REF == A_REF
	CLR_BIT(ADMUX , REFS0);
	CLR_BIT(ADMUX , REFS1);

	//A-VCC WITH EXTERNAL CAPACITOR AT AREF PIN
#elif VOLTAGE_DIFF_REF == A_VCC
	SET_BIT(ADMUX , REFS0);
	CLR_BIT(ADMUX , REFS1);

#endif

	//ADC Adjustment
#if ADC_ADJUSTMENT == LEFT
	SET_BIT(ADMUX , ADLAR);

#elif ADC_ADJUSTMENT == RIGHT
	CLR_BIT(ADMUX , ADLAR);

#endif

	//SELECT PRESCALLER
#if ADC_PRESCALER == CLK_2
	CLR_BIT(ADCSRA , ADPS0);
	CLR_BIT(ADCSRA , ADPS1);
	CLR_BIT(ADCSRA , ADPS2);

#elif ADC_PRESCALER == CLK_4
	CLR_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	CLR_BIT(ADCSRA , ADPS2);

#elif ADC_PRESCALER == CLK_8
	SET_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	CLR_BIT(ADCSRA , ADPS2);

#elif ADC_PRESCALER == CLK_16
	CLR_BIT(ADCSRA , ADPS0);
	CLR_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);

#elif ADC_PRESCALER == CLK_32
	SET_BIT(ADCSRA , ADPS0);
	CLR_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);

#elif ADC_PRESCALER == CLK_64
	CLR_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);

#elif ADC_PRESCALER == CLK_128
	SET_BIT(ADCSRA , ADPS0);
	SET_BIT(ADCSRA , ADPS1);
	SET_BIT(ADCSRA , ADPS2);
#endif

	//Enable ADC
	SET_BIT(ADCSRA, 7);
}

void MADC_voidStartConversion (void)
{
	//ADC Channel Selection
#if ADC_CHANNEL == CHANNEL_0    //ADC0
	CLR_BIT(ADMUX , MUX0);
	CLR_BIT(ADMUX , MUX1);
	CLR_BIT(ADMUX , MUX2);

#elif ADC_CHANNEL == CHANNEL_1  // ADC1
	SET_BIT(ADMUX , MUX0);
	CLR_BIT(ADMUX , MUX1);
	CLR_BIT(ADMUX , MUX2);

#elif ADC_CHANNEL == CHANNEL_2  //ADC2
	CLR_BIT(ADMUX , MUX0);
	SET_BIT(ADMUX , MUX1);
	CLR_BIT(ADMUX ,MUX2);

#elif ADC_CHANNEL == CHANNEL_3  //ADC3
	SET_BIT(ADMUX , MUX0);
	SET_BIT(ADMUX , MUX1);
	CLR_BIT(ADMUX , MUX2);

#elif ADC_CHANNEL == CHANNEL_4  //ADC4
	CLR_BIT(ADMUX , MUX0);
	CLR_BIT(ADMUX , MUX1);
	SET_BIT(ADMUX , MUX2);

#elif ADC_CHANNEL == CHANNEL_5  //ADC5
	SET_BIT(ADMUX , MUX0);
	CLR_BIT(ADMUX , MUX1);
	SET_BIT(ADMUX , MUX2);

#elif ADC_CHANNEL == CHANNEL_6  //ADC6
	CLR_BIT(ADMUX , MUX0);
	SET_BIT(ADMUX , MUX1);
	SET_BIT(ADMUX , MUX2);

#elif ADC_CHANNEL == CHANNEL_7  //ADC37
	SET_BIT(ADMUX , MUX0);
	SET_BIT(ADMUX , MUX1);
	SET_BIT(ADMUX , MUX2);
#endif

	//ADC Start Conversion
	SET_BIT(ADCSRA , ADSC);
}

u16  MADC_u16ReadSync (void)
{
	//MADC_voidStartConversion ();
	u16 local_value ;

#if ADC_ADJUSTMENT == LEFT

	//Check Flag
	while (GET_BIT(ADCSRA , ADIF) == 0);
	local_value = (ADCL_RIGHT_ADJ >> 6) ;

	//Clear Flag
	SET_BIT(ADCSRA , ADIF);

	return local_value ;

#elif ADC_ADJUSTMENT == RIGHT

	//Check Flag
	while (GET_BIT(ADCSRA , ADIF) == 0);
	//local_value = ADC;
	local_value  =  ADCL;
	local_value |= (ADCH << 8);

	//Clear Flag
	SET_BIT(ADCSRA , ADIF);

	return local_value ;
#endif
}

/*
void MADC_ReadASync(void (*ptr)(void), u16* Copy_u16Data)
{
	MADC_voidStartConversion ();

	if(ptr != NULL)
		{
			MADC_Func = ptr;
		}

	if(Copy_u16Data != NULL)
		{
			Global_u16Data = Copy_u16Data;
		}

}*/

/*******/
/*void MADC_voidADCEnableINT ()
{
	SET_BIT(MADC_ADCSRA,ADCSRA_ADIE);
}
void MADC_voidADCDisableINT ()
{
	CLR_BIT(MADC_ADCSRA,ADCSRA_ADIE);
}
void MADC_voidADCInt_CallBack(void (*Copy_ptrFuncADCInt) (void) , u16 * Copy_ptrU16ADCValue)
{
	SGlobal_ptrFunc = Copy_ptrFuncADCInt;
	SGlobal_ptrU16ADCValue = Copy_ptrU16ADCValue ;
}

void __vector_16 (void) __attribute__ ( ( signal ) );
void __vector_16(void)
{
	*SGlobal_ptrU16ADCValue   =           ADCL  ;
	*SGlobal_ptrU16ADCValue   |=         ADCH<<8  ;
	SGlobal_ptrFunc();
}*/
