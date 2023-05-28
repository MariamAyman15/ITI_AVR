/*
 * LM_SENSOR_prg.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mariam
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"

#include "util/delay.h"

#include "LM_SENSOR_cfg.h"
#include "LM_SENSOR_prv.h"
#include "LM_SENSOR_int.h"
void HLM35_voidInit(void)
{
	MADC_voidInit();
	//MDIO_voidSetPinDirection(LM35_PORT,LM35_CHANNEL,PIN_IN);

}

u16  HLM35_u8ReadTemp(void)
{
	u16 Local_u16ADCRead;
	u16 Local_u32Readmv;
	 MADC_voidStartConversion();

	/*READ DIGITAL VALUE FROM ADC*/
	Local_u16ADCRead =  MADC_u16ReadSync();

	/*MAP DIGITAL VALUE TO ANALOG VALUE*/
	Local_u32Readmv = ((Local_u16ADCRead * 0.0048828125)* 100 );

	/*RETURN TEMP*/
	return Local_u32Readmv;
}
