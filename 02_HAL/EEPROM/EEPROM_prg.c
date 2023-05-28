/*
 * EEPROM_prg.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Mariam
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/TWI/TWI_int.h"
#include "../../MCAL/TWI/TWI_prv.h"
#include <util/delay.h>

#include "../../MCAL/TWI/TWI_cfg.h"
#include "../../MCAL/TWI/TWI_int.h"

#include "EEPROM_prv.h"
#include "EEPROM_int.h"
#include "EEPROM_cfg.h"

//initialization
void HEEPROM_voidInit(void)
{
	u8 Copy_u8SlaveAdress;
	MTWI_voidMSTR_Init(Copy_u8SlaveAdress);
}

//write data byte
void HEEPROM_voidWriteDataByte(u8 Copy_u8DataByte, u16 Copy_u16Adress)
{
	TWI_SendStartCond();
	TWI_SendSlaveAddress_withWrite((EEPROM_FIRST_4BITS | (0<<3) | (Copy_u16Adress>>7)) >>1);
	TWI_MSTRWrite_DatsByte((u8) Copy_u16Adress);
	TWI_MSTRWrite_DatsByte(Copy_u8DataByte);
	TWI_SendStopCond();
}

//READ DATA BYTE
void HEEPROM_voidReadDataByte (u8 *Copy_u8PtrDataByte,u16 Copy_u16Adress)
{
	TWI_SendStartCond();
	TWI_SendSlaveAddress_withWrite((EEPROM_FIRST_4BITS | (0<<3) | (Copy_u16Adress >> 7)) >> 1);
	TWI_MSTRWrite_DatsByte((u8)Copy_u16Adress);
	TWI_SendRepeatedStartCond();
	TWI_SendSlaveAddress_withRead((EEPROM_FIRST_4BITS | (0<<3) | (Copy_u16Adress>>7))>>1);
	TWI_MSTRRead_DatsByte(Copy_u8PtrDataByte);
	TWI_SendStopCond();
}
