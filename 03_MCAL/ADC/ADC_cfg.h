#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_

//VOLTAGE-DIFF SELECTION
#define V_REF					0
#define A_REF					1
#define A_VCC					2
#define VOLTAGE_DIFF_REF 	    A_VCC

//ADC ADJUSTMENT SELECTION
#define LEFT					0
#define RIGHT					1
#define ADC_ADJUSTMENT			RIGHT

//PRE SCALLER SELECTION
#define CLK_2					0
#define CLK_4					1
#define CLK_8					2
#define CLK_16					3
#define CLK_32					4
#define CLK_64					5
#define CLK_128					6
#define ADC_PRESCALER			CLK_8

//CHANNEL SELECTION
#define CHANNEL_0				0
#define CHANNEL_1				1
#define CHANNEL_2				2
#define CHANNEL_3				3
#define CHANNEL_4				4
#define CHANNEL_5				5
#define CHANNEL_6				6
#define CHANNEL_7				7
#define ADC_CHANNEL 			CHANNEL_1

#endif /* MCAL_ADC_ADC_CFG_H_ */
