#include "EXTI_cfg.h"
#include "EXTI_int.h"
#include "EXTI_prv.h"

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO_int.h"
#include "../DIO/DIO_prv.h"

void (*EXT_INT_0_CALLBACK)(void);
void (*EXT_INT_1_CALLBACK)(void);
void (*EXT_INT_2_CALLBACK)(void);

void EXTI_voidEnableInt (u8 Copy_u8INT_ID, u8 Copy_u8Sense)
{
	//set global interrupt
	SET_BIT(MSREG_REG,GICR);
	switch (Copy_u8INT_ID)
	{
	case EXT_INT0:
		MDIO_voidSetPinDirection(PORTD,PIN2,PIN_IN);
		MDIO_voidSetPullupRessistor(PORTD,PIN2);
		SET_BIT(MGICR_REG,INT0);

		switch (Copy_u8Sense)
		{
		case LOW_LEVEL:
			CLR_BIT(MMCUCR_REG,ISC00);
			CLR_BIT(MMCUCR_REG,1);
			break;
		case ANY_CHANGE:
			CLR_BIT(MMCUCR_REG,1);
			SET_BIT(MMCUCR_REG,ISC00);
			break;
		case FALLING_EDGE :
			CLR_BIT(MMCUCR_REG,ISC00);
			SET_BIT(MMCUCR_REG,1);
			break;
		case RISING_EDGE:
			SET_BIT(MMCUCR_REG,1);
			SET_BIT(MMCUCR_REG,ISC00);
			break;
		}
		break;

		case EXT_INT1:
			MDIO_voidSetPinDirection(PORTD,PIN3,PIN_IN);
			MDIO_voidSetPullupRessistor(PORTD,PIN3);
			SET_BIT(MGICR_REG,INT1);

			switch (Copy_u8Sense)
			{
			case LOW_LEVEL:
				CLR_BIT(MMCUCR_REG,ISC10);
				CLR_BIT(MMCUCR_REG,ISC11);
				break;
			case ANY_CHANGE:
				CLR_BIT(MMCUCR_REG,ISC11);
				SET_BIT(MMCUCR_REG,ISC10);
				break;
			case FALLING_EDGE :
				CLR_BIT(MMCUCR_REG,ISC10);
				SET_BIT(MMCUCR_REG,ISC11);
				break;
			case RISING_EDGE:
				SET_BIT(MMCUCR_REG,ISC10);
				SET_BIT(MMCUCR_REG,ISC11);
				break;
			}
			break;

			case EXT_INT2:
				MDIO_voidSetPinDirection(PORTB,PIN2,PIN_IN);
				MDIO_voidSetPullupRessistor(PORTB,PIN2);
				SET_BIT(MGICR_REG,INT2);
				switch (Copy_u8Sense)
				{
				case FALLING_EDGE :
					CLR_BIT(MMCUCSR_REG,I2C2);
					break;
				case RISING_EDGE:
					SET_BIT(MMCUCSR_REG,I2C2);
					break;
				}
				break;
	}
}

void EXTI_voidDisableInt (u8 Copy_u8INT_ID)
{
	switch (Copy_u8INT_ID)
	{
	case EXT_INT0:
		CLR_BIT (MGICR_REG,INT0);
		break;

	case EXT_INT1:
		CLR_BIT (MGICR_REG,INT1);
		break;

	case EXT_INT2:
		CLR_BIT (MGICR_REG,INT2);
		break;
	}
}

//INTO
void EXT_INT_0_SET_CALLBACK (void(*ptr)(void))
{
	EXT_INT_0_CALLBACK = ptr;
}

void EXT_INT_1_SET_CALLBACK (void(*ptr)(void))
{
	EXT_INT_1_CALLBACK = ptr;
}
void EXT_INT_2_SET_CALLBACK (void(*ptr)(void))
{
	EXT_INT_2_CALLBACK = ptr;
}

void __vector_1(void)  __attribute__ ((signal));
void __vector_1(void)
{
	EXT_INT_0_CALLBACK();
}

void __vector_2(void)  __attribute__ ((signal));
void __vector_2(void)
{
	EXT_INT_1_CALLBACK();
}

void __vector_3(void)  __attribute__ ((signal));
void __vector_3(void)
{
	EXT_INT_2_CALLBACK();
}



