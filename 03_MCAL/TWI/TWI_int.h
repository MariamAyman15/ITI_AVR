/*
 * TWI_int.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Mariam
 */

#ifndef MCAL_TWI_TWI_INT_H_
#define MCAL_TWI_TWI_INT_H_

#include "../../LIB/STD_TYPES.h"

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartErr,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
}TWI_ErrStatus;

void MTWI_voidMSTR_Init (u8 Copy_u8SlaveAdress) ;
void MTWI_voidSlave_Init (u8 Copy_u8SlaveAdress) ;

TWI_ErrStatus TWI_SendStartCond(void);
TWI_ErrStatus TWI_SendRepeatedStartCond(void);

TWI_ErrStatus TWI_SendSlaveAddress_withWrite(u8 Copy_u8SlaveAdress);
TWI_ErrStatus TWI_SendSlaveAddress_withRead(u8 Copy_u8SlaveAdress);

TWI_ErrStatus TWI_MSTRWrite_DatsByte(u8 Copy_u8DataByte);
TWI_ErrStatus TWI_MSTRRead_DatsByte(u8* Copy_u8PtrDataByte);

void  TWI_SendStopCond(void);

#endif /* MCAL_TWI_TWI_INT_H_ */
