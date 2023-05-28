#ifndef LCD_PRV_H
#define LCD_PRV_H

#define DATA_PINS_OUTPUT  0xff

/*function set command initialization of LCD (0b00111000)*/
//#if  LCD_Mode   ==  HLCD_8BIT_MODE
#define HLCD_FUNCSET_CMD          0x38

//#elif  LCD_Mode   == HLCD_4BIT_MODE
#define HLCD_4BITM_CMD             0x02
//#endif

#define HLCD_DOC_CMD 0x0f //display i/o control 0x0c
#define HLCD_CLR_CMD 0x01 //clear
#define HLCD_EMS_CMD 0x06

/*DISPLAY CURSURE CMD
 * ON  0x0F */
#define HLCD_DISPLAYON_OFF_CONT_CMD       0x0f
#define HLCD_DISPLAYON_OFF_CONT_CMD_4bit  0x00 //4 bit

/*CLEAR SCREEN CMD*/
#define HLCD_CLR_SCRN                     0x01
#define LCD_SET_X0_Y0                     0x80
#define LCD_SET_X0_Y1                     0xC0

#define INIT_4_BIT_MODE_CMD_1   0x33
#define INIT_4_BIT_MODE_CMD_2   0x32
#define INIT_4_BIT_MODE_CMD_3   0x28

#define  COMMAND_0xf0      0xf0
#define  COMMAND_0x0f      0x0f

#define  SHIFTING_LEFT_VAL_4      4



#define DISPLAY_ON_CURSOR_Blinking     0x0E
#define DISPLAY_ON_CURSOR_OFF          0x0c
#define CLEAR_LCD                      0x01
#define HLCD_ON_OFFCONTOL              0x0f

#endif

/*u8 M[8] = {0x00,0x00,0x07,0x05,0x1f,0x00,0x00,0x00};
u8 R[8] = {0x00,0x00,0x02,0x02,0x02,0x04,0x08,0x10};
u8 Y[8] = {0x00,0x00,0x01,0x01,0x1f,0x0A,0x00,0x00};
u8 m[8] = {0x00,0x00,0x07,0x05,0x1f,0x10,0x10,0x10};*/

