#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../MCAL/DIO/DIO_int.h"

#include "STEP_MOTOR_cfg.h"
#include "STEP_MOTOR_prv.h"
#include "STEP_MOTOR_int.h"

void HStep_Motor_voidinit ()
{
	MDIO_voidSetPinDirection(StMotor_Port, StMotor_PIN0, PIN_OUT);
	MDIO_voidSetPinDirection(StMotor_Port, StMotor_PIN1, PIN_OUT);
	MDIO_voidSetPinDirection(StMotor_Port, StMotor_PIN2, PIN_OUT);
	MDIO_voidSetPinDirection(StMotor_Port, StMotor_PIN3, PIN_OUT);

	MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
	MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN1, PIN_HIGH);
	MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN2, PIN_HIGH);
	MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN3, PIN_HIGH);
}

void HStepMotor_voidFullStepCW (void)
{
	u16 LocalIteration;
	for (LocalIteration= HStepMotor_Initial ; LocalIteration < HStepMotor_Total ; LocalIteration++)
	{
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		_delay_ms(2);
	}
}

void HStepMotor_voidFullStepACW (void)
{
	u16 LocalIteration;
	for (LocalIteration= HStepMotor_Initial ; LocalIteration < HStepMotor_Total ; LocalIteration++)
	{
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);
	}
}

void HStepMotor_voidSpecificDegreeCW (u16 Copy_u16Degree)
{
	u16 LocalIteration;
	Copy_u16Degree = (((Copy_u16Degree/11.25)*64)/4);
	for (LocalIteration= HStepMotor_Initial ; LocalIteration < Copy_u16Degree ; LocalIteration++)
	{
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		_delay_ms(2);
	}

}

void HStepMotor_voidSpecificDegreeACW (u16 Copy_u16Degree)
{
	u16 LocalIteration;
	Copy_u16Degree = (((Copy_u16Degree/11.25)*64)/4);
	for (LocalIteration= HStepMotor_Initial ; LocalIteration < Copy_u16Degree ; LocalIteration++)
	{
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);

		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_HIGH);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		MDIO_voidSetPinValue(StMotor_Port, StMotor_PIN0, PIN_LOW);
		_delay_ms(2);
	}
}


