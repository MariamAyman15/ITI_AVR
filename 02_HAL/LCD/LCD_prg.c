#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/DIO/DIO_prv.h"
#include "util/delay.h"

#include "LCD_cfg.h"
#include "LCD_prv.h"
#include "LCD_int.h"

static u8 LCD_u8Status = 0 ;
void HLCD_voidInit (void)
{
#if  LCD_Mode   ==  HLCD_8BIT_MODE
	MDIO_voidSetPortDirection(HLCD_DATA_PORT,0xff);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_RS_PIN, PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_RW_PIN, PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_EN_PIN, PIN_OUT);

	_delay_ms(40);
	HLCD_voidSendCommand (HLCD_FUNCSET_CMD);
	HLCD_voidSendCommand ( HLCD_DOC_CMD );
	HLCD_voidSendCommand ( HLCD_CLR_CMD );
	HLCD_voidSendCommand(HLCD_EMS_CMD);

#elif  LCD_Mode   == HLCD_4BIT_MODE
	MDIO_voidSetPinDirection(HLCD_DATA_PORT, HLCD_PIN4, PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_DATA_PORT, HLCD_PIN5, PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_DATA_PORT, HLCD_PIN6, PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_DATA_PORT, HLCD_PIN7, PIN_OUT);

	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_RS_PIN, PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_RW_PIN, PIN_OUT);
	MDIO_voidSetPinDirection(HLCD_CTRL_PORT,HLCD_EN_PIN, PIN_OUT);

	_delay_ms(30);
	HLCD_voidSendCommand(0x20);
	HLCD_voidSendCommand(0x20);
	HLCD_voidSendCommand(0x80);

	_delay_ms(1);
	HLCD_voidSendCommand(0x00);
	HLCD_voidSendCommand(0xf0);

	_delay_ms(1);
	HLCD_voidSendCommand(0x00);
	HLCD_voidSendCommand(0x10);

	_delay_ms(2);
	LCD_u8Status = 1 ;

#endif
}

void HLCD_voidSendCommand (u8 copy_u8Command)
{
#if  LCD_Mode   ==  HLCD_8BIT_MODE
	MDIO_voidSetPinValue ( HLCD_CTRL_PORT , HLCD_RS_PIN ,PIN_LOW );
	MDIO_voidSetPinValue (HLCD_CTRL_PORT , HLCD_RW_PIN, PIN_LOW);

	MDIO_voidSetPortValue( HLCD_DATA_PORT, copy_u8Command );
	MDIO_voidSetPinValue (HLCD_CTRL_PORT, HLCD_EN_PIN, PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue (HLCD_CTRL_PORT, HLCD_EN_PIN, PIN_LOW);


#elif LCD_Mode   == HLCD_4BIT_MODE
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN   , PIN_LOW );
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN   , PIN_LOW );

	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN4,GET_BIT(copy_u8Command,PIN4));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN5,GET_BIT(copy_u8Command,PIN5));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN6,GET_BIT(copy_u8Command,PIN6));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN7,GET_BIT(copy_u8Command,PIN7));

	MDIO_voidSetPinValue(HLCD_CTRL_PORT , HLCD_EN_PIN , PIN_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT , HLCD_EN_PIN , PIN_LOW);
	if(LCD_u8Status == 1)
	{

		MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN4,GET_BIT(copy_u8Command,PIN0));
		MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN5,GET_BIT(copy_u8Command,PIN1));
		MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN6,GET_BIT(copy_u8Command,PIN2));
		MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN7,GET_BIT(copy_u8Command,PIN3));

		MDIO_voidSetPinValue(HLCD_CTRL_PORT , HLCD_EN_PIN , PIN_HIGH);
		_delay_ms(1);
		MDIO_voidSetPinValue(HLCD_CTRL_PORT , HLCD_EN_PIN , PIN_LOW);
		_delay_ms(2);
	}
#endif
}

void HLCD_voidSendData (u8 copy_u8Data)
{
#if  LCD_Mode   ==  HLCD_8BIT_MODE
	MDIO_voidSetPinValue ( HLCD_CTRL_PORT , HLCD_RS_PIN ,PIN_HIGH );
	MDIO_voidSetPinValue (HLCD_CTRL_PORT , HLCD_RW_PIN, PIN_LOW);

	MDIO_voidSetPortValue( HLCD_DATA_PORT, copy_u8Data );
	MDIO_voidSetPinValue (HLCD_CTRL_PORT, HLCD_EN_PIN, PIN_HIGH);
	_delay_ms(2);
	MDIO_voidSetPinValue (HLCD_CTRL_PORT, HLCD_EN_PIN, PIN_LOW);


#elif  LCD_Mode   == HLCD_4BIT_MODE
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN   , PIN_HIGH );
	MDIO_voidSetPinValue(HLCD_CTRL_PORT, HLCD_RW_PIN   , PIN_LOW );

	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN4,GET_BIT(copy_u8Data,PIN4));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN5,GET_BIT(copy_u8Data,PIN5));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN6,GET_BIT(copy_u8Data,PIN6));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN7,GET_BIT(copy_u8Data,PIN7));

	MDIO_voidSetPinValue(HLCD_CTRL_PORT , HLCD_EN_PIN , PIN_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT , HLCD_EN_PIN , PIN_LOW);

	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN4,GET_BIT(copy_u8Data,PIN0));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN5,GET_BIT(copy_u8Data,PIN1));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN6,GET_BIT(copy_u8Data,PIN2));
	MDIO_voidSetPinValue(HLCD_DATA_PORT,HLCD_PIN7,GET_BIT(copy_u8Data,PIN3));
	MDIO_voidSetPinValue(HLCD_CTRL_PORT , HLCD_EN_PIN , PIN_HIGH);
	_delay_ms(1);
	MDIO_voidSetPinValue(HLCD_CTRL_PORT , HLCD_EN_PIN , PIN_LOW);
	_delay_ms(2);


#endif
}

void HLCD_voidGoToXy (u8 Copy_u8XPosition, u8 Copy_u8YPosition)
{
	/*Checking For X-Position*/
	if(Copy_u8XPosition >= 0 && Copy_u8XPosition <= 0x0F)
	{
		if(Copy_u8YPosition == 0)
		{
			/*Write In Wanted Position On LCD*/
			HLCD_voidSendCommand(LCD_SET_X0_Y0 + Copy_u8XPosition);
		}
		else if (Copy_u8YPosition == 1)
		{
			HLCD_voidSendCommand(LCD_SET_X0_Y1 + Copy_u8XPosition);
		}
	}
	/*u8 Local_u8address =0;
		if ( Copy_u8YPosition == 0 && Copy_u8XPosition <= 0x0f)
		{
			//LCD_Command(Copy_u8XPosition);
			Local_u8address = Copy_u8XPosition;
		}

		else if (Copy_u8YPosition == 1 && Copy_u8XPosition > 0x3f)
		{
			//LCD_Command((Copy_u8XPosition)+0x40);
			Local_u8address = Copy_u8XPosition+0x40;
		}
	    Local_u8address+=128;
	    HLCD_voidSendCommand(Local_u8address);*/
}

/*send string*/
void HLCD_voidSendString (const char *copy_ps8str)
{
	while (*copy_ps8str != '\0')
	{
		HLCD_voidSendData (*copy_ps8str);
		copy_ps8str++;
	}
}

/*send special character*/
void HLCD_SendSpecialChar (u8 *copy_ps8arr, u8 copy_u8Pattern_num , u8 Copy_u8XPosition , u8 Copy_u8YPosition )
{
	u8 Local_CGRAMaddress;
	u8 Local_u8Counter;
	Local_CGRAMaddress = copy_u8Pattern_num*8;
	HLCD_voidSendCommand(Local_CGRAMaddress+64);
	for(Local_u8Counter = 0 ; Local_u8Counter < 8 ; Local_u8Counter++)
	{
		HLCD_voidSendData(copy_ps8arr[Local_u8Counter]);
	}
	HLCD_voidGoToXy (Copy_u8XPosition,Copy_u8YPosition);
	HLCD_voidSendData (copy_u8Pattern_num);
}

/*clear screen*/
void HLCD_voidCLRScreen(void)
{
	HLCD_voidSendCommand(HLCD_CLR_CMD);
}

/*send number*/
void HLCD_voidSendNumber(s32 Copy_s32Number)
{
	s8 Local_s8Counter = 0;
	u8 Local_u8Array[10] = {0};
	//if the number = zero
	if(Copy_s32Number == 0)
	{
		HLCD_voidSendData('0');
		return ;
	}

	//if the number is negative
	else if(Copy_s32Number < 0)
	{
		HLCD_voidSendData('-');
		Copy_s32Number = Copy_s32Number*(-1);
	}
	//if the number is positive
	while (Copy_s32Number > 0)
	{
		Local_u8Array[Local_s8Counter] = Copy_s32Number % 10;
		Copy_s32Number /= 10;
		Local_s8Counter++;
	}
	Local_s8Counter--;
	while(Local_s8Counter >= 0)
	{
		HLCD_voidSendData(Local_u8Array[Local_s8Counter] +'0');
		Local_s8Counter--;
	}
}
