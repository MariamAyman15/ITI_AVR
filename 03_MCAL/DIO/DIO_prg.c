
#include "DIO_cfg.h"
#include "DIO_prv.h"
#include "DIO_int.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


void MDIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Dir)
{
	switch (Copy_u8Port)
	{
	case PORTA: 
		switch (Copy_u8Dir)
		{
		case PIN_IN:
			CLR_BIT(MDIO_DDRA, Copy_u8Pin);
			break;

		case PIN_OUT:
			SET_BIT(MDIO_DDRA,Copy_u8Pin);
			break;
		}
		break;

		case PORTB:
			switch (Copy_u8Dir)
			{
			case PIN_IN: 
				CLR_BIT(MDIO_DDRB, Copy_u8Pin);
				break;

			case PIN_OUT:
				SET_BIT(MDIO_DDRB,Copy_u8Pin);
				break;
			}
			break;

			case PORTC:
				switch (Copy_u8Dir)
				{
				case PIN_IN:
					CLR_BIT(MDIO_DDRC, Copy_u8Pin);
					break;

				case PIN_OUT:
					SET_BIT(MDIO_DDRC,Copy_u8Pin);
					break;
				}
				break;

				case PORTD:
					switch (Copy_u8Dir)
					{
					case PIN_IN:
						CLR_BIT(MDIO_DDRD, Copy_u8Pin);
						break;

					case PIN_OUT:
						SET_BIT(MDIO_DDRD,Copy_u8Pin);
						break;
					}
					break;
	}

}

void MDIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value )
{
	switch (Copy_u8Port)
	{
	case PORTA: 
		switch (Copy_u8Value)
		{
		case PIN_LOW:
			CLR_BIT(MDIO_PORTA, Copy_u8Pin);
			break;

		case PIN_HIGH:
			SET_BIT(MDIO_PORTA,Copy_u8Pin);
			break;
		}
		break;

		case PORTB:
			switch (Copy_u8Value)
			{
			case PIN_LOW: 
				CLR_BIT(MDIO_PORTB, Copy_u8Pin);
				break;

			case PIN_HIGH:
				SET_BIT(MDIO_PORTB,Copy_u8Pin);
				break;
			}
			break;

			case PORTC:
				switch (Copy_u8Value)
				{
				case PIN_LOW:
					CLR_BIT(MDIO_PORTC, Copy_u8Pin);
					break;

				case PIN_HIGH:
					SET_BIT(MDIO_PORTC,Copy_u8Pin);
					break;
				}
				break;

				case PORTD:
					switch (Copy_u8Value)
					{
					case PIN_LOW:
						CLR_BIT(MDIO_PORTD, Copy_u8Pin);
						break;

					case PIN_HIGH:
						SET_BIT(MDIO_PORTD,Copy_u8Pin);
						break;
					}
					break;
	}
}

u8 MDIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin )
{
	u8 Local_U8Data;
	switch (Copy_u8Port)
	{
	case PORTA:
		Local_U8Data = GET_BIT (MDIO_PINA, Copy_u8Pin)	;
		break;

	case PORTB:
		Local_U8Data = GET_BIT (MDIO_PINB, Copy_u8Pin)	;
		break;

	case PORTC:
		Local_U8Data = GET_BIT (MDIO_PINC, Copy_u8Pin)	;
		break;

	case PORTD:
		Local_U8Data = GET_BIT (MDIO_PIND, Copy_u8Pin)	;
		break;
	}
	return Local_U8Data;
}

void MDIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Dir)
{
	switch (Copy_u8Port)
	{
	case PORTA :
		MDIO_DDRA = Copy_u8Dir ;
		break;

	case PORTB :
		MDIO_DDRB = Copy_u8Dir ;
		break;

	case PORTC :
		MDIO_DDRC = Copy_u8Dir ;
		break;

	case PORTD :
		MDIO_DDRD = Copy_u8Dir ;
		break;

	default:
		break;
	}
}

void MDIO_voidSetPortValue (u8 Copy_u8Port,u8 Copy_u8Value )
{
	u8   i =0 ;
	for(i=0 ; i<8;i++)
	{
		MDIO_voidSetPinValue(Copy_u8Port , i , ((Copy_u8Value>>i)&1));
	}
}

u8 MDIO_u8GetPortValue (u8 Copy_u8Port)
{
	u8 Local_U8Data;
	switch (Copy_u8Port)
	{
	case PORTA:
		Local_U8Data = MDIO_PINA	;
		break;

	case PORTB:
		Local_U8Data = MDIO_PINB	;
		break;

	case PORTC:
		Local_U8Data = MDIO_PINC	;
		break;

	case PORTD:
		Local_U8Data = MDIO_PIND	;
		break;

	default:
		break ;
	}
	return Local_U8Data;
}

void MDIO_voidSetPullupRessistor(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		SET_BIT(MDIO_PORTA,Copy_u8Pin);
		break;
	case PORTB:
		SET_BIT(MDIO_PORTB,Copy_u8Pin);
		break;
	case PORTC:
		SET_BIT(MDIO_PORTC,Copy_u8Pin);
		break;
	case PORTD:
		SET_BIT(MDIO_PORTD,Copy_u8Pin);
		break;
	}
}

/*void MDIO_voidSetPortPullupResistor( u8 Copy_u8Port)
{
	 u8   i =0 ;
	for(i=0 ; i<8;i++)
		{
		MDIO_voidSetPinPullupResistor(Copy_u8Port , i );
		}
}*/

void MDIO_voidToggleBin (u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch (Copy_u8Port)
	{
	case PORTA:
		TOGGLE_BIT(MDIO_PORTA,Copy_u8Pin)	;
		break;

	case PORTB:
		TOGGLE_BIT(MDIO_PORTB,Copy_u8Pin)	;
		break;

	case PORTC:
		TOGGLE_BIT(MDIO_PORTC,Copy_u8Pin)	;
		break;

	case PORTD:
		TOGGLE_BIT(MDIO_PORTD,Copy_u8Pin)	;
		break;

	default:
		break ;
	}
}
