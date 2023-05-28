/*
 * TWI_prg.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Mariam
 */
#include "TWI_int.h"
#include "TWI_prv.h"
#include "TWI_cfg.h"

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/DIO_int.h"

void MTWI_voidMSTR_Init(u8 Copy_u8SlaveAdress)
{
	TWBR = 0x02;
	//TWPS0 = 0;
	//TWPS1 = 0;
	//SET PRESCALLER TO 1
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
	//ENABLE ACK
	SET_BIT(TWCR,TWEA);
	//ENABLE TWI
	SET_BIT(TWCR,TWEN);
	//SET SLAVE ADDRESS
	//shift one left
	TWAR = (Copy_u8SlaveAdress << 1);
}

void MTWI_voidSlave_Init(u8 Copy_u8SlaveAdress)
{
	//SET SLAVE ADDRESS
	//shift one left
	TWAR = (Copy_u8SlaveAdress << 1);
	//ENABLE ACK
	SET_BIT(TWCR,TWEA);
	//ENABLE TWI
	SET_BIT(TWCR,TWEN);
}

TWI_ErrStatus TWI_SendStartCond(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	//SET START CONDITION
	SET_BIT(TWCR,TWSTA);

	//CLEAR FLAG
	SET_BIT(TWCR,TWINT);

	//WAIT FOR FLAG TO BE RAISED
	//while (!(TWCR & (1<<TWINT)));
	while (GET_BIT(TWCR,TWINT) == 0);

	//CHECK ERROR STATUS AND RETURN IN VARIABLE
	if((TWSR & Checking_Mask) != START_ACK)
	{
		Local_ErrStatus = StartConditionErr;
	}
	else
	{
		//do nothing
	}
	return Local_ErrStatus;
}

/*Local_var = TWI_ErrStatus TWI_SendStartCond();
if (Local_var != 0)
{
	HLCD_SendNumber(Local_var);
}*/

TWI_ErrStatus TWI_SendRepeatedStartCond(void)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	//SET START CONDITION
	SET_BIT(TWCR,TWSTA);

	//CLEAR FLAG
	SET_BIT(TWCR,TWINT);

	//WAIT FOR FLAG TO BE RAISED
	while (GET_BIT(TWCR,TWINT) == 0);

	//CHECK ERROR STATUS AND RETURN IN VARIABLE
	if((TWSR & Checking_Mask) != REP_START_ACK)
	{
		Local_ErrStatus = RepeatedStartErr;
	}
	else
	{
		//do nothing
	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddress_withWrite(u8 Copy_u8SlaveAdress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	//CLEAR START CONDITION
	CLR_BIT(TWCR,TWSTA);
	//SET ADDRESS TO TWDR
	TWDR = Copy_u8SlaveAdress<<1 ;
	//CLR TWDR BIT0
	CLR_BIT(TWDR,TWD0);
	//CLR FLAG
	SET_BIT(TWCR,TWINT);
	//WAIT FOR FLAG TO BE RAISED
	while (GET_BIT(TWCR,TWINT) == 0);

	//CHECK ERROR STATUS AND RETURN IN VARIABLE
	if((TWSR & Checking_Mask) != MSTR_ACK_RECEIVED)
	{
		Local_ErrStatus = SlaveAddressWithWriteErr;
	}
	else
	{
		//do nothing
	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_SendSlaveAddress_withRead(u8 Copy_u8SlaveAdress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;
	//CLEAR START CONDITION
	CLR_BIT(TWCR,TWSTA);

	//SET ADDRESS TO TWDR
	TWDR = Copy_u8SlaveAdress<<1 ;

	//SET TWDR BIT0
	SET_BIT(TWDR,TWD0);

	//CLEAR FLAG
	SET_BIT(TWCR,TWINT);

	//WAIT FOR FLAG TO BE RAISED
	while (GET_BIT(TWCR,TWINT) == 0);

	//CHECK ERROR STATUS AND RETURN IN VARIABLE
	if((TWSR & Checking_Mask) != MSTR_ACK_RECEIVED_SLAR)
	{
		Local_ErrStatus = SlaveAddressWithReadErr;
	}
	else
	{
		//do nothing
	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_MSTRWrite_DatsByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	//set data in TWDR
	TWDR = Copy_u8DataByte;

	//CLEAR FLAG
	SET_BIT(TWCR,TWINT);

	//WAIT FOR FLAG TO BE RAISED
	while (GET_BIT(TWCR,TWINT) == 0);

	//CHECK ERROR STATUS AND RETURN IN VARIABLE
	if((TWSR & Checking_Mask) != MSTR_ACK_RECEIVED_DATA)
	{
		Local_ErrStatus = MasterWriteByteErr;
	}
	else
	{
		//do nothing
	}
	return Local_ErrStatus;
}

TWI_ErrStatus TWI_MSTRRead_DatsByte(u8 * Copy_u8PtrDataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError;
	//CLEAR FLAG
	SET_BIT(TWCR,TWINT);

	//WAIT FOR FLAG TO BE RAISED
	while (GET_BIT(TWCR,TWINT) == 0);

	//CHECK ERROR STATUS AND RETURN IN VARIABLE
	//CHECK NULL PTR
	while (Copy_u8PtrDataByte != NULL_POINTER)
	{
		if((TWSR & Checking_Mask) != MSTR_ACK_RETURNED_DATA)
		{
			Local_ErrStatus = MasterReadByteErr;
		}
		else
		{
			//do nothing
		}
	}
	return Local_ErrStatus;

	//set TWDR in address of data
	TWDR = Copy_u8PtrDataByte ;
}

void  TWI_SendStopCond(void)
{
	//SET STOP CONDITION BIT
	SET_BIT(TWCR,TWSTO);

	//CLEAR FLAG
	SET_BIT(TWCR,TWINT);
}
