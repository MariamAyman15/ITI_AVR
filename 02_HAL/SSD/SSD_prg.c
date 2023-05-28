/*
 * SSD_prg.c
 *
 *  Created on: Mar 29, 2023
 *      Author: Mariam
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "SSD_cfg.h"
#include "SSD_prv.h"
#include "SSD_int.h"

void HSSD_voidInit ()
{
	MDIO_voidSetPortDirection(SSD_PORT, PORT_OUT);
	MDIO_voidSetPortValue(SSD_PORT, PORT_LOW);
}
void HSSD_voidDisplay_Number(u8 Copy_u8Number)
{
  switch (Copy_u8Number)
  {
  case 0:
	  MDIO_voidSetPortValue(SSD_PORT, zero_c);
	  break;
  case 1:
  	  MDIO_voidSetPortValue(SSD_PORT, one_c);
  	  break;
  case 2:
  	  MDIO_voidSetPortValue(SSD_PORT, two_c);
  	  break;
  case 3:
  	  MDIO_voidSetPortValue(SSD_PORT, three_c);
  	  break;
  case 4:
  	  MDIO_voidSetPortValue(SSD_PORT, four_c);
  	  break;
  case 5:
  	  MDIO_voidSetPortValue(SSD_PORT, five_c);
  	  break;
  case 6:
  	  MDIO_voidSetPortValue(SSD_PORT, six_c);
  	  break;
  case 7:
  	  MDIO_voidSetPortValue(SSD_PORT, seven_c);
  	  break;
  case 8:
  	  MDIO_voidSetPortValue(SSD_PORT, eight_c);
  	  break;
  case 9:
  	  MDIO_voidSetPortValue(SSD_PORT, nine_c);
  	  break;
  }

}
