/*
 * Buzzer_prg.c
 *
 *  Created on: Mar 27, 2023
 *      Author: D E L L
 */

#include "Buzzer_int.h"
#include "Buzzer_cfg.h"
#include "Buzzer_prv.h"
#include "DIO/DIO_int.h"

void HBZR_void_BZRInit(void)
{
	MDIO_voidSetPinDirection(HBZR_PORT,HBZR_PIN,PIN_OUT);
}
void HBZR_voidBZROn(void)
{
	MDIO_voidSetPinValue(HBZR_PORT,HBZR_PIN,PIN_HIGH);
}
void HBZR_voidBZROff(void)
{
	MDIO_voidSetPinValue(HBZR_PORT,HBZR_PIN,PIN_LOW);
}

