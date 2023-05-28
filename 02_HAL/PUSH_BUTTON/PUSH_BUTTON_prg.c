/*
 * PUSH_BUTTON_prg.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Mariam
 */
#include "PUSH_BUTTON_cfg.h"
#include "PUSH_BUTTON_int.h"
#include "PUSH_BUTTON_prv.h"

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_int.h"


void HPush_Button_INIT (void)
{
	MDIO_voidSetPinDirection(PushButton_PORT, PushButton_PIN, PIN_IN);
}
u8 HPush_Button_Read (void)
{
	u8 Local_u8Value=1;
	if (MDIO_u8GetPinValue(PushButton_PORT, PushButton_PIN) == 0)//vcc
	{
		Local_u8Value = 0;
		while(MDIO_u8GetPinValue(PushButton_PORT, PushButton_PIN)==0);
	}
	return Local_u8Value;
}

