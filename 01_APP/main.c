//delay lib
#include <util/delay.h>
//include bit maths
#include "../LIB/BIT_MATH.h"

//include std types
#include "../LIB/STD_TYPES.h"

//include DIO
#include "../MCAL/DIO/DIO_int.h"

//include ADC
#include "../MCAL/ADC/ADC_int.h"

//include USART
#include "../MCAL/USART/MUSART_int.h"

//include USART
#include "../MCAL/SPI/SPI_int.h"

//include external interrupt
#include "../MCAL/EXTI/EXTI_int.h"

//include two wire interface
#include "../MCAL/TWI/TWI_int.h"

//include timers 0 1 2
//#include "../MCAL/TIMERS/TIMERS_int.h"
//#include "../MCAL/TIMERS/TIMERS_cfg.h"
#include "../MCAL/TIMER_DRIVER/TIMER_INTERFACE.h"

//include LCD
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_cfg.h"

//include KPD
#include "../HAL/KEYPAD/KPD_cfg.h"
#include "../HAL/KEYPAD/KPD_int.h"

//include EEPROM
#include "../HAL/EEPROM/EEPROM_int.h"

//include LM-sensor
#include "../HAL/LM_SENSOR/LM_SENSOR_int.h"

//include LDR
#include "../HAL/LDR/LDR_int.h"

#define CODE   18
#if CODE == 20
int main (void)
{
	LDR_voidInit();
	HLCD_voidInit();
	MDIO_voidSetPinDirection(PORTD, PIN5, PIN_OUT);
	TIMER1_voidSetMode_14(TIMER1_CHANNEL_A,NON_INVERTING,PRESCALER_DIV_BY_8);
	TIMER1_voidSetTopValueMode_14(2000);
	u16 Read =0;
	while(1)
	{
		Read = LDR_u16Read();
		HLCD_voidSendString("LDR READ: ");
		HLCD_voidSendNumber(Read);
		_delay_ms(1000);
		HLCD_voidCLRScreen();
		if(Read >= 600)
		{
			TIMER1_voidSetCompareMatchValue(TIMER1_CHANNEL_A,1500);
		}
		else if (Read < 600)
		{
			TIMER1_voidSetCompareMatchValue(TIMER1_CHANNEL_A,300);
		}
	}
}
#elif CODE == 19
//LDR TEST
//master
int main (void)
{
	MDIO_voidSetPinDirection(PORTB , PIN5 ,PIN_OUT);  //MOSI
	MDIO_voidSetPinDirection(PORTB , PIN6 ,PIN_IN);  //MISO
	MDIO_voidSetPinDirection(PORTB , PIN7 ,PIN_OUT); //CLOCK
	MDIO_voidSetPinDirection(PORTB , PIN4 ,PIN_OUT); //SLAVE SELECT
	u16 Read;
	HLCD_voidInit();
	LDR_voidInit();
	MSPI_voidInit();
	while (1)
	{
		MDIO_voidSetPinValue(PORTB , PIN4 ,PIN_LOW);
		Read = LDR_u16Read();
		HLCD_voidSendString("LDR READ: ");
		//Read = (Read>>2);
		HLCD_voidSendNumber(Read);
		MSPI_voidSendData(Read);
		_delay_ms(1000);
		HLCD_voidCLRScreen();
		MDIO_voidSetPinValue(PORTB , PIN4 ,PIN_HIGH);
	}
}
#elif CODE == 18
//slave
int main (void)
{
	MDIO_voidSetPinDirection(PORTB , PIN5 ,PIN_IN);  //MOSI
	MDIO_voidSetPinDirection(PORTB , PIN6 ,PIN_OUT);  //MISO
	MDIO_voidSetPinDirection(PORTB , PIN7 ,PIN_IN); //CLOCK
	MDIO_voidSetPinDirection(PORTB , PIN4 ,PIN_IN); //SLAVE SELECT
	u16 var;
	HLCD_voidInit();
	MSPI_voidInit();
	while(1)
	{
		var =  MSPI_u8RecieveData();
		HLCD_voidSendString("LDR READ: ");
		HLCD_voidSendNumber(var);
		_delay_ms(1000);
		HLCD_voidCLRScreen();
	}

}
#elif CODE   ==  17
/**eeprom test**/
int main (void)
{
	u8 Local_u8Data;
	HEEPROM_voidInit();
	HLCD_voidInit();
	HEEPROM_voidWriteDataByte(0x17,50);
	HLCD_voidSendString("w=");
	HLCD_voidSendNumber(50);
	HEEPROM_voidReadDataByte(0x17,Local_u8Data);
	_delay_ms(500);
	while(1)
	{

	}
}

#elif CODE == 16
/****|UART_TEST|****/
/*UART SLAVE*/
int main (void)
{
	HLCD_voidInit();
	MUSART_voidInit();
	//HPush_Button_INIT();
	MDIO_voidSetPinDirection(PORTB, PIN6 , PIN_IN);
	//MDIO_voidSetPinValue(PORTB, PIN6 , PIN_LOW);

	u8 Push;
	u8 Key;
	while(1)
	{
		if(MDIO_u8GetPinValue(PORTB, PIN6) == 1)
		{
			Push = MDIO_u8GetPinValue(PORTB, PIN6);
			MUSART_voidTransmitDataSynch(Push);
		}

		Key = MUSART_u8ReceiveDataSynch();
		HLCD_voidSendNumber(Key);
	}

}

#elif  CODE ==   15
/*MASTER*/
int main (void)
{
	MDIO_voidSetPinDirection(PORTB, PIN3, PIN_OUT);
	HKPD_voidInit();
	MUSART_voidInit();
	u8 Key;
	u8 Receive;
	while(1)
	{
		Key = HKPD_u8GetPressedKey();
		while(Key == 0xff)
		{
			Key = HKPD_u8GetPressedKey();
		}
		MUSART_voidTransmitDataSynch(Key);
		if (Receive == 1 )
		{
			MDIO_voidSetPinValue(PORTB, PIN3, PIN_HIGH);
			_delay_ms(1000);
			MDIO_voidSetPinValue(PORTB, PIN3, PIN_LOW);
		}
	}
}

#elif     CODE == 14
/******check password********/
u8 Cheack_Password(u8 a[],u8 b[],u8 n);
u8 Password [10];     //array to save the first password
u8 Checkpassword[10]; //array to save the entered password to check
int main (void)
{
	//variables decleration and initialization
	u16 KPD_Read = 0xff;
	u8 NumOfDigits = 4; //set number of password digits to 4 digits
	u8 i;
	u8 PWM0 = 0 , PWM2 = 0;

	//functions
	HLCD_voidInit();
	HKPD_voidInit();
	TIMER0_voidInit( NON_INVERTING, FASTPWM_MODE , PRESCALER_DIV_BY_8);
	TIMER2_voidInit( NON_INVERTING, FASTPWM_MODE , PRESCALER_DIV_BY_8);
	MDIO_voidSetPinDirection(PORTD, PIN5, PIN_OUT);
	MDIO_voidSetPinDirection(PORTB, PIN3, PIN_OUT);
	TIMER0_voidSetCompareMatchValue(PWM0);
	TIMER2_voidSetCompareMatchValue(PWM2);

	/*   Set Password for First time   */
	HLCD_voidSendString("ENTER PASSWORD: ");
	_delay_ms(200);
	HLCD_voidCLRScreen();
	for (i=0; i<NumOfDigits;i++)
	{
		while (KPD_Read == 0xff)
		{
			KPD_Read = HKPD_u8GetPressedKey();
		}
		HLCD_voidSendNumber(KPD_Read);
		//_delay_ms(200);
		Password [i] = KPD_Read;
		KPD_Read = 0xff;
	}
	_delay_ms(500);
	HLCD_voidCLRScreen();

	while(1)
	{
		/*    Get Password To Check It    */
		HLCD_voidSendString("CHECK PASSWORD: ");
		_delay_ms(200);
		HLCD_voidCLRScreen();
		_delay_ms(200);
		KPD_Read = 0xff;
		for(i=0;i< NumOfDigits;i++)
		{
			while (KPD_Read == 0xff)
			{
				KPD_Read = HKPD_u8GetPressedKey();
			}
			HLCD_voidSendNumber(KPD_Read);
			//_delay_ms(200);
			Checkpassword [i] = KPD_Read;
			KPD_Read = 0xff;
		}
		_delay_ms(200);
		HLCD_voidCLRScreen();

		//if the password true rotate the motor
		if(Cheack_Password(Checkpassword,Password,NumOfDigits))
		{
			HLCD_voidCLRScreen();
			_delay_ms(200);
			HLCD_voidSendString("welcome");
			_delay_ms(200);
			TIMER2_voidSetCompareMatchValue(255);
		}

		//if the password wrong turn on a LED
		else
		{
			HLCD_voidCLRScreen();
			_delay_ms(200);
			HLCD_voidSendString("wrong password");
			_delay_ms(200);
			TIMER0_voidSetCompareMatchValue(PWM0+=51);
			//MDIO_voidSetPinValue(PORTB, PIN3, PIN_HIGH);
			HLCD_voidCLRScreen();
			_delay_ms(200);
		}
		HLCD_voidCLRScreen();
		_delay_ms(200);
	}
}

u8 Cheack_Password(u8 a[],u8 b[],u8 n)
{
	u8 ret=0;
	for(u8 counter =0 ; counter<n ; counter++)
	{
		if(a[counter] == b[counter])
		{
			ret++;
		}
	}
	if(ret == n)	return 1;
	else            return 0;
}

#elif CODE == 13
//MASTER
int main (void)
{
	MDIO_voidSetPinDirection(PORTB , PIN5 ,PIN_OUT);  //MOSI
	MDIO_voidSetPinDirection(PORTB , PIN6 ,PIN_IN);  //MISO
	MDIO_voidSetPinDirection(PORTB , PIN7 ,PIN_OUT); //CLOCK
	MDIO_voidSetPinDirection(PORTB , PIN4 ,PIN_OUT); //SLAVE SELECT

	MDIO_voidSetPinDirection(PORTD , PIN0 ,PIN_IN);  //BUTTON

	MSPI_voidInit();
	//HKPD_voidInit();

	u8 X;
	while(1)
	{
		X = MDIO_u8GetPinValue(PORTD, PIN0);
		//X = HKPD_u8GetPressedKey();
		MDIO_voidSetPinValue(PORTB , PIN4 ,PIN_LOW);
		MSPI_voidSendData(X);
		_delay_ms(100);
		MDIO_voidSetPinValue(PORTB , PIN4 ,PIN_HIGH);
	}
}


#elif CODE == 12
///SLAVE
int main (void)
{
	MDIO_voidSetPinDirection(PORTB , PIN5 ,PIN_IN);  //MOSI
	MDIO_voidSetPinDirection(PORTB , PIN6 ,PIN_OUT);  //MISO
	MDIO_voidSetPinDirection(PORTB , PIN7 ,PIN_IN); //CLOCK
	MDIO_voidSetPinDirection(PORTB , PIN4 ,PIN_IN); //SLAVE SELECT

	MDIO_voidSetPinDirection(PORTD , PIN0 ,PIN_OUT);  //LED

	MSPI_voidInit();
	//HLCD_voidInit();
	u8 X = 1 ;
	while(1)
	{
		X = MSPI_u8RecieveData();  // 0 HTNWR LW 1 MSH HTNWR
		/*while (X != 0xff)
		{
			_delay_ms(100);
			HLCD_voidSendNumber(X);
			_delay_ms(100);
			HLCD_voidCLRScreen();
		}*/
		if ( X == 0)
		{
			MDIO_voidSetPinValue(PORTD , PIN0 ,PIN_HIGH);
		}
		else
		{
			MDIO_voidSetPinValue(PORTD , PIN0 ,PIN_LOW);
		}
	}
}

#elif CODE == 11
//MC1 UART APP
/*UART CHECKING*/
/*MASTER*/
int main (void)
{
	HLED_void_LEDInit(GRN_LED);
	HKPD_voidInit();
	MUART_voidInit();
	u8 Local_u8Key;
	u8 Local_u8Receive;
	while(1)
	{
		Local_u8Key = HKPD_u8GetPressedKey();
		while(Local_u8Key == 0xff)
		{
			Local_u8Key = HKPD_u8GetPressedKey();
		}
		MUART_voidTransmitDataSync(Local_u8Key);
		if (Local_u8Receive == 0)
		{
			HLED_void_LEDOn(GRN_LED);
			_delay_ms(1000);
			HLED_void_LEDOff(GRN_LED);
		}
	}
}
/*UART SLAVE*/
int main (void)
{
	HLCD_voidInit();
	MUART_voidInit();
	HPushButton_voidInit();
	u8 Local_u8Push;
	u8 Local_u8Key;
	while(1)
	{
		if(HPushButton_u8Read() == 0)
		{
			Local_u8Push = HPushButton_u8Read();
			MUART_voidTransmitDataSync(Local_u8Push);
		}
		Local_u8Key = MUART_u8ReceiveDataSync();
		HLCD_voidSendNumber(Local_u8Key);
	}

}
int main (void)
{
	HKPD_voidInit();
	MDIO_voidSetPinDirection(PORTD, PIN5, PIN_OUT);

	u8 Data;
	u8 Var;

	MDIO_voidSetPinDirection(PORTD, PIN5, PIN_HIGH);
	TIMER1_voidSetMode_14(TIMER1_CHANNEL_A,NON_INVERTING,PRESCALER_DIV_BY_8);
	TIMER1_voidSetTopValueMode_14(2000);
	Data = MUSART_u8ReceiveDataSynch();
	while(1)
	{
		Var = HKPD_u8GetPressedKey();
		if (Var != NOT_PRESSED)
		{
			MUSART_voidTransmitDataSynch(Var);
		}
		if(Data == 0)
			TIMER1_voidSetCompareMatchValue(TIMER1_CHANNEL_A,1500);
	}
	return 0;
}

#elif CODE == 10
//MC2 UART APP
int main (void)
{
	u8 Result;
	HLCD_voidInit();
	HPush_Button_INIT();
	MDIO_voidSetPinDirection(PushButton_PORT, PushButton_PIN, PIN_IN);

	u8 Variable;

	while(1)
	{
		if(HPush_Button_Read() == 0)
		{
			Result = HPush_Button_Read();
			MUSART_voidTransmitDataSynch(Result);
		}
		Variable = MUSART_u8ReceiveDataSynch();
		HLCD_voidSendNumber(Variable);
	}
}

#elif CODE == 9
/***ADC TEST & LM sensor****/
int main (void)
{
	HLCD_voidInit();
	HLM35_voidInit();
	//MADC_voidInit();
	u16 Local_u16Variable;
	while(1)
	{
		//MADC_voidStartConversion();
		Local_u16Variable = HLM35_u8ReadTemp();
		HLCD_voidSendNumber(Local_u16Variable);
		_delay_ms(500);
		HLCD_voidCLRScreen();
	}
}

#elif CODE == 8
/***ICU test*****/
void  LED_Interrupt(void);
u16 period = 0, Ton =0;
void ICU_HW(void);
int main (void)
{
	HLCD_voidInit();
	MDIO_voidSetPinDirection(PORTB,PIN3,PIN_OUT);
	MDIO_voidSetPinDirection(PORTD,PIN6,PIN_IN);

	TIMER0_voidInit(NON_INVERTING,FASTPWM_MODE,PRESCALER_DIV_BY_8);
	TIMER0_voidSetCompareMatchValue(150);

	TIMER_voidSetCallBack(TIMER1_ICU_INT,ICU_HW);

	ICU_voidInit();

	while (1)
	{
		if( (period == 0) || (Ton == 0) )
		{

		}

		else
		{
			HLCD_voidGoToXy(0, 0);
			HLCD_voidSendNumber(period);
			HLCD_voidGoToXy(0, 1);
			HLCD_voidSendNumber(Ton);
			//CLEAR_BIT(MSREG_REG,7);
		}
		_delay_ms(1000);
	}
}

void ICU_HW(void)
{
	static u16 R1,R2,R3;
	static u8 counter =0;
	counter++;
	switch(counter)
	{
	case 1:
		R1 = ICU_u16ReadICU();
		break;
	case 2:
		R2 = ICU_u16ReadICU();
		period = R2 - R1;
		ICU_SetTriggerEdge(ICU_FALLING_EDGE);
		break;
	case 3:
		R3 = ICU_u16ReadICU();
		Ton = R3 - R2;
		break;
	default:
		counter = 5;
		break;
	}
}

void  LED_Interrupt(void)
{
	HLED_voidInit(PORTA,PIN0);
	HLED_void_LEDFlip(GRN_LED);
}

#elif CODE == 7
/*****servo motor test*****/
int main (void)
{
	MDIO_voidSetPinDirection(PORTD, PIN5, PIN_HIGH);
	TIMER1_voidSetMode_14(TIMER1_CHANNEL_A,NON_INVERTING,PRESCALER_DIV_BY_8);
	TIMER1_voidSetTopValueMode_14(2000);
	while(1)
	{
		TIMER1_voidSetCompareMatchValue(TIMER1_CHANNEL_A,1500);
		//pd5
	}
}

#elif CODE == 6
/*timer TEST*/
int main (void)
{
	MDIO_voidSetPinDirection(PORTB, PIN3, PIN_OUT);
	MTimer0_voidInit(FAST_PWM , 8);
	u8 value = 0;
	HLCD_voidInit();
	while(1)
	{
		HLCD_voidSendString("MARIAM");
		_delay_ms(1000);
		HLCD_voidCLRScreen();
		MTimer0_voidSetCompMatchVal(value);
		_delay_ms(100);
		value++;
		if(value == 255)
		{
			value = 0;
		}
	}
}

#elif CODE == 5
/***interrupt test***/
void LED1(void);
void LED2(void);
void LED3(void);
u8 F = 0;
int main(void)
{
	MDIO_voidSetPinDirection(PORTD,PIN2, PIN_IN);   //set int0_pin as input_pin
	MDIO_voidSetPinDirection(PORTB,PIN6, PIN_OUT);
	MDIO_voidSetPortDirection(PORTB, PORT_OUT );

	EXTI_voidEnableInt( EXT_INT0 , FALLING_EDGE );         //enable int0
	EXT_INT_0_SET_CALLBACK(LED1);                        //set callback
	while(1)
	{
		MDIO_voidSetPortValue(PORTB, PIN_LOW);
		switch (F)
		{
		case 1 :
			EXT_INT_0_SET_CALLBACK(LED2);
			MDIO_voidSetPinValue(PORTB,PIN7,PIN_HIGH);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
			MDIO_voidSetPinValue(PORTB,PIN6,PIN_HIGH);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN6,PIN_LOW);
			MDIO_voidSetPinValue(PORTB,PIN5,PIN_HIGH);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN5,PIN_LOW);
			MDIO_voidSetPinValue(PORTB,PIN4,PIN_HIGH);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN4,PIN_LOW);
			MDIO_voidSetPinValue(PORTB,PIN3,PIN_HIGH);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN3,PIN_LOW);
			MDIO_voidSetPinValue(PORTB,PIN2,PIN_HIGH);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(PORTB,PIN1,PIN_HIGH);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(PORTB,PIN0,PIN_HIGH);
			_delay_ms(500);
			break;

		case 2 :
			EXT_INT_0_SET_CALLBACK(LED3);
			MDIO_voidSetPinValue(PORTB,PIN0,PIN_HIGH);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(PORTB,PIN0,PIN_LOW);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(PORTB,PIN1,PIN_LOW);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN3,PIN_HIGH);
			MDIO_voidSetPinValue(PORTB,PIN2,PIN_LOW);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN4,PIN_HIGH);
			MDIO_voidSetPinValue(PORTB,PIN3,PIN_LOW);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN5,PIN_HIGH);
			MDIO_voidSetPinValue(PORTB,PIN4,PIN_LOW);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN6,PIN_HIGH);
			MDIO_voidSetPinValue(PORTB,PIN5,PIN_LOW);
			_delay_ms(500);
			MDIO_voidSetPinValue(PORTB,PIN7,PIN_HIGH);
			MDIO_voidSetPinValue(PORTB,PIN6,PIN_LOW);
			_delay_ms(500);
			break;

		case 3 :
			EXT_INT_0_SET_CALLBACK(LED1);
			MDIO_voidSetPortValue(PORTB, 0b00011000);
			_delay_ms(500);
			MDIO_voidSetPortValue(PORTB, 0b00100100);
			_delay_ms(500);
			MDIO_voidSetPortValue(PORTB, 0b01000010);
			_delay_ms(500);
			MDIO_voidSetPortValue(PORTB, 0b10000001);
			_delay_ms(500);
			break;
		}
	}
	return 0;
}

void LED1(void)
{
	F = 1 ;
	/*MDIO_voidSetPinValue(PORTB,PIN6,PIN_HIGH);
	_delay_ms(1000);
	MDIO_voidSetPinValue(PORTB,PIN6,PIN_LOW);*/
}
void LED2(void)
{
	F = 2;
}
void LED3(void)
{
	F = 3;
}


#elif CODE == 4
/*Seven segment*/
int main(void)
{
	HSSD_voidInit();
	HSSD_voidDisplay_Number(0);
	_delay_ms(250);
	HSSD_voidDisplay_Number(2);
	while(1)
	{

	}
}

#elif CODE == 3
/*****calculator****/
u8 KPDf;
u8 KPDs;
char operation,equal;
int main (void)
{
	HLCD_voidInit();
	HKPD_voidInit();

	while(1)
	{
		//first number
		KPDf = HKPD_u8GetPressedKey();
		while(KPDf == 0xff)
		{
			KPDf = HKPD_u8GetPressedKey();
		}
		HLCD_voidSendNumber(KPDf);

		//operation
		operation = HKPD_u8GetPressedKey();
		while (operation == 0xff)
		{
			operation = HKPD_u8GetPressedKey();
		}
		HLCD_voidSendData(operation);

		//second number
		KPDs = HKPD_u8GetPressedKey();
		while(KPDs == 0xff)
		{
			KPDs = HKPD_u8GetPressedKey();
		}
		HLCD_voidSendNumber(KPDs);
		equal = HKPD_u8GetPressedKey();
		while (equal == 0xff)
		{
			equal = HKPD_u8GetPressedKey();
		}
		HLCD_voidSendData(equal);
		switch(operation)
		{
		case '+':
			HLCD_voidSendNumber(KPDs+KPDf);
			break;
		case '-':
			HLCD_voidSendNumber(KPDf-KPDs);
			break;
		case '*':
			HLCD_voidSendNumber(KPDf*KPDs);
			break;
		case '/':
			HLCD_voidSendNumber(KPDf/KPDs);
		}
		_delay_ms(750);
		HLCD_voidCLRScreen();
		while (HKPD_u8GetPressedKey() != 0xff)
		{
		}
	}
}

#elif CODE == 2
/*****keypad send number*****/
int main  (void)
{
	HLCD_voidInit();
	HKPD_voidInit();
	u8 Copy_u8Localvar;
	while(1)
	{
		Copy_u8Localvar = HKPD_u8GetPressedKey();
		if (Copy_u8Localvar != NOT_PRESSED)
		{
			HLCD_voidSendNumber(Copy_u8Localvar);
		}
	}
}

#elif CODE == 1
/****LED driver TEST**/
int main (void)
{
	HLED_voidInit(LED_PORT,LED_GRN_PIN);
	HLED_voidInit(LED_PORT,LED_BLUE_PIN);
	HLED_voidInit(LED_PORT,LED_RED_PIN);
	while(1)
	{
		HLED_voidOn(LED_PORT, LED_GRN_PIN);
		HLED_voidOn(LED_PORT, LED_RED_PIN);
		HLED_voidOn(LED_PORT, LED_BLUE_PIN);
		_delay_ms(250);
		HLED_voidOff(LED_PORT, LED_GRN_PIN);
		HLED_voidOff(LED_PORT, LED_RED_PIN);
		HLED_voidOff(LED_PORT, LED_BLUE_PIN);
		_delay_ms(250);
	}
}

#elif CODE == 0
/****buzzer and swithces********/
int main (void)
{
	MDIO_voidSetPinDirection(PORTD, PIN7, PIN_OUT);
	MDIO_voidSetPinDirection(PORTD, PIN6, PIN_OUT);
	while(1)
	{
		MDIO_voidSetPinValue(PORTD, PIN7, PIN_LOW);
		MDIO_voidSetPinValue(PORTD, PIN6, PIN_LOW);
		_delay_ms(3000);
		MDIO_voidSetPinValue(PORTD, PIN7, PIN_LOW);
		MDIO_voidSetPinValue(PORTD, PIN6, PIN_HIGH);
		_delay_ms(3000);
		MDIO_voidSetPinValue(PORTD, PIN7, PIN_HIGH);
		MDIO_voidSetPinValue(PORTD, PIN6, PIN_LOW);
		_delay_ms(3000);
		MDIO_voidSetPinValue(PORTD, PIN7, PIN_HIGH);
		MDIO_voidSetPinValue(PORTD, PIN6, PIN_HIGH);
		_delay_ms(3000);
	}
}
#endif
