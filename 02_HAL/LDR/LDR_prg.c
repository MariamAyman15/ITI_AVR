/*
 * LDR_prg.c
 *
 *  Created on: Apr 2, 2023
 *      Author: Mariam
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/ADC/ADC_int.h"
#include "util/delay.h"

#include "LDR_cfg.h"
#include "LDR_prv.h"
#include "LDR_int.h"

void LDR_voidInit(void)
{
	MADC_voidInit();
	//MDIO_voidSetPinDirection(LDR_PORT,LDR_CHANNEL,PIN_IN);
}
u16 LDR_u16Read(void)
{
	u16 Local_u16ADCRead;
	//u16 Local_u16LightIntensity;
	MADC_voidStartConversion();

	/*READ DIGITAL VALUE FROM ADC*/
	Local_u16ADCRead =  MADC_u16ReadSync();

	/*MAP DIGITAL VALUE TO ANALOG VALUE*/
	//Local_u16LightIntensity = ((Local_u16ADCRead *2));

	/*RETURN Light Intensity Value*/
	return Local_u16ADCRead;
}
