/*
 * FAN_prg.c
 *
 *  Created on: Apr 22, 2023
 *      Author: D E L L
 */

#include "DIO/DIO_int.h"
#include "FAN_int.h"
#include "FAN_cfg.h"
#include "FAN_prv.h"

void HFAN_voidInit(void)
{
	MDIO_voidSetPinDirection(FAN_PORT,FAN_PIN,PIN_OUT);
}
void HFAN_voidOn(void)
{
	MDIO_voidSetPinValue(FAN_PORT,FAN_PIN,PIN_HIGH);
}
void HFAN_voidOff(void)
{
	MDIO_voidSetPinValue(FAN_PORT,FAN_PIN,PIN_LOW);
}
