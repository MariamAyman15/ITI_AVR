#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_

/*REGISTERS ADDRESSES*/
#define   ADMUX                             (*(volatile u8 *)(0x27))
#define   ADCSRA                            (*(volatile u8 *)(0x26))
#define   ADCH                              (*(volatile u8 *)(0x25))
#define   ADCL                              (*(volatile u8 *)(0x24))
#define   SFIOR                             (*(volatile u8 *)(0x50))
#define   ADC                               (*(volatile u16*)(0x24))
/*ADMUX REGISTER BITS*/
#define  REFS1                               7   //REF SELECTION
#define  REFS0                               6   //REF SELECTION
#define  ADLAR                               5   //LEFT AGJ RESULT
#define  MUX4                                4   //FROM 0 TO 4 FOR CHANNEL SELECTION
#define  MUX3                                3
#define  MUX2                                2
#define  MUX1                                1
#define  MUX0                                0

/*ADCSRA REGISTER BITS*/
#define ADEN                                 7  //ADC ENABLE
#define ADSC                                 6  //ADC START CONVERSION
#define ADATE                                5  //AUTO TRIGGER ENABLE
#define ADIF                                 4  //INTERRUPT FLAG
#define ADIE                                 3  //INTERRUPT ENABLE

#define ADPS2                                2  //FROM 0 TO 2 PRESCALLER SELECTION BITS
#define ADPS1                                1
#define ADPS0                                0

/*SFIOR REGISTER BITS*/
#define ADTS2                                7
#define ADTS1                                6
#define ADTS0                                5

/*
#define ADCL_RIGHT_ADJ  0xff
#define CLR_AnalogChannel_BITS                     0b11100000
#define CLR_Prescaler_BITS                         0b11111000
#define ConversionNOTcomplete                      0*/
#endif /* MCAL_ADC_ADC_PRV_H_ */
