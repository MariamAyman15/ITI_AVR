#ifndef KPD_CFG_H
#define KPD_CFG_H

#include "../../MCAL/DIO/DIO_int.h"

#define KPD_PORT     PORTA

//ROWS PINS
#define KPD_ROW0_PIN PIN0
#define KPD_ROW1_PIN PIN1
#define KPD_ROW2_PIN PIN2
#define KPD_ROW3_PIN PIN3

//COLUMNS PINS
#define KPD_COL0_PIN PIN4
#define KPD_COL1_PIN PIN5
#define KPD_COL2_PIN PIN6
#define KPD_COL3_PIN PIN7

//COL AND ROW NUMBER
#define COL_NUM      4
#define ROW_NUM      4

//keypad button value
#define KPD_Button_Value  {{7,8,9,'/'},{4,5,6,'*'},{1,2,3,'-'},{11,0,'=','+'}}


#endif
