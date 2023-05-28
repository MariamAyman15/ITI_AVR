#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

typedef enum{
	SINGLE_ENDED=0,
	Positive_Differential,
	Negative_Differential
}ADCInput_t;


//FUNCTIONS PROTOTYPES
void MADC_voidInit (void);
void MADC_voidStartConversion (void);
u16  MADC_u16ReadSync (void);
//void MADC_ReadASync(void (*ptr)(void), u16* Copy_u16Data);


#endif /* MCAL_ADC_ADC_INT_H_ */
