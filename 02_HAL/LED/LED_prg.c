#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include"../../MCAL/DIO/DIO_int.h"
#include"../../MCAL/DIO/DIO_prv.h"

#include "LED_int.h"
#include "LED_cfg.h"
#include "LED_prv.h"
#include <avr/delay.h>

void HLED_voidInit(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MDIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,PIN_OUT);
}

void HLED_voidOn(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MDIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,PIN_HIGH);
}

void HLED_voidOff(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	MDIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,PIN_LOW);

}

 void HLED_void_LEDFlip(u8 Copy_u8LED)
{
	switch(Copy_u8LED)
	{
	case GRN_LED:
		MDIO_voidToggleBin(LED_PORT,LED_GRN_PIN);
	break;

	case BLUE_LED:
		MDIO_voidToggleBin(LED_PORT,LED_BLUE_PIN);
	break;

	case RED_LED:
		MDIO_voidToggleBin(LED_PORT,LED_RED_PIN);
	break;

	default:
	break;
	}
}
