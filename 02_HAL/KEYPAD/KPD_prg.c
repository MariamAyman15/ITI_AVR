#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "KPD_int.h"
#include "KPD_cfg.h"
#include "KPD_prv.h"

void HKPD_voidInit(void)
{ /* Set Columns direction to Output */
	MDIO_voidSetPinDirection(KPD_PORT, KPD_COL0_PIN ,PIN_OUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_COL1_PIN, PIN_OUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_COL2_PIN, PIN_OUT);
	MDIO_voidSetPinDirection(KPD_PORT, KPD_COL3_PIN, PIN_OUT);

	/* Set Column Initial Values to 1111 */
	MDIO_voidSetPinValue(KPD_PORT,KPD_COL0_PIN, PIN_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_COL1_PIN, PIN_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_COL2_PIN, PIN_HIGH);
	MDIO_voidSetPinValue(KPD_PORT,KPD_COL3_PIN, PIN_HIGH);

    /* Set Rows direction to Input */
	MDIO_voidSetPinDirection(KPD_PORT,KPD_ROW0_PIN, PIN_IN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_ROW1_PIN, PIN_IN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_ROW2_PIN,PIN_IN);
	MDIO_voidSetPinDirection(KPD_PORT,KPD_ROW3_PIN, PIN_IN);

    /* Enable Pull Up Resistors at Input Rows */
	MDIO_voidSetPullupRessistor(KPD_PORT,KPD_ROW0_PIN);
	MDIO_voidSetPullupRessistor(KPD_PORT,KPD_ROW1_PIN);
	MDIO_voidSetPullupRessistor(KPD_PORT,KPD_ROW2_PIN);
	MDIO_voidSetPullupRessistor(KPD_PORT,KPD_ROW3_PIN);

	/*MDIO_voidSetPinValue(KPD_PORT,KPD_ROW0_PIN, PIN_HIGH);
	 MDIO_voidSetPinValue(KPD_PORT,KPD_ROW1_PIN, PIN_HIGH);
	 MDIO_voidSetPinValue(KPD_PORT,KPD_ROW2_PIN, PIN_HIGH);
	 MDIO_voidSetPinValue(KPD_PORT,KPD_ROW3_PIN, PIN_HIGH);*/
}

u8 HKPD_u8GetPressedKey(void)
{
	//deceleration of columns and rows
	u8 Local_u8ColArr [COL_NUM]= {KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	u8 Local_u8RowArr [ROW_NUM]= {KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	u8 Local_u8ColCount;
	u8 Local_u8RowCount;
	u8 Local_u8PinState;
	u8 Local_u8PressedKey = NOT_PRESSED ;

	//array of rows and columns
	u8 Local_u8ButtonArr[ROW_NUM][COL_NUM]= KPD_Button_Value ;

	//for loop
	for (Local_u8ColCount = 0 ; Local_u8ColCount < COL_NUM ; Local_u8ColCount++ )
	{
		MDIO_voidSetPinValue(KPD_PORT, Local_u8ColArr[Local_u8ColCount] , PIN_LOW);

		for (Local_u8RowCount = 0 ; Local_u8RowCount < ROW_NUM ; Local_u8RowCount++ )
		{
			Local_u8PinState = MDIO_u8GetPinValue(KPD_PORT, Local_u8RowArr[Local_u8RowCount]);

			if (Local_u8PinState == PIN_LOW)
			{
				Local_u8PressedKey = Local_u8ButtonArr[Local_u8RowCount][Local_u8ColCount];
				while (Local_u8PinState == PIN_LOW)
				{
					Local_u8PinState = MDIO_u8GetPinValue(KPD_PORT , Local_u8RowArr[Local_u8RowCount]);
				}
				return Local_u8PressedKey;
			}
		}
		MDIO_voidSetPinValue(KPD_PORT, Local_u8ColArr[Local_u8ColCount], PIN_HIGH);
	}

	return Local_u8PressedKey;
}
