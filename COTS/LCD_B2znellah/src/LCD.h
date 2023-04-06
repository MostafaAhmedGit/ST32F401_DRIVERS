/*************************************************************
 * 
 * Filename: LCD.h
 * Description: Header (interface) file of the LCD driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 * 
 *************************************************************/

#ifndef LCD_H_
#define LCD_H_
#include "GPIO.h"



#define LCD_COUNT	1

// LCD_enuErrorStatus
typedef enum
{
	LCD_enuOK=1,
	LCD_enuNOK
}LCD_enuErrorStatus;


typedef enum
{
	LCD_MAIN,
	LCD_XYZ
}LCD_NAME_t;


typedef struct
{
	GPIO_strConfig_t LCD_VSS_PIN;
	GPIO_strConfig_t LCD_RW_PIN;
	GPIO_strConfig_t LCD_RS_PIN;
	GPIO_strConfig_t  LCD_E_PIN;
	GPIO_strConfig_t  LCD_DATA_L1;
	GPIO_strConfig_t  LCD_DATA_L2;
	GPIO_strConfig_t  LCD_DATA_L3;
	GPIO_strConfig_t  LCD_DATA_L4;
	GPIO_strConfig_t  LCD_DATA_L5;
	GPIO_strConfig_t  LCD_DATA_L6;
	GPIO_strConfig_t  LCD_DATA_L7;
	GPIO_strConfig_t  LCD_DATA_L8;
}LCD_Configurations_t;
	
	
	LCD_enuErrorStatus LCD_enuInit(LCD_NAME_t LCD_NAME);
	LCD_enuErrorStatus LCD_enuSendData(LCD_NAME_t LCD_NAME,u8 Copy_u8Data);
	LCD_enuErrorStatus LCD_enuWriteCommand(LCD_NAME_t LCD_NAME,u8 Copy_enuCommand);
	LCD_enuErrorStatus LCD_enuWriteString(LCD_NAME_t LCD_NAME,const char* Copy_PtrString);
	LCD_enuErrorStatus LCD_enuGoToXY(LCD_NAME_t LCD_NAME,u8 Copy_u8X_Pos,u8 Copy_u8Y_Pos);

	LCD_enuErrorStatus LCD_enuWriteSpecialChar(LCD_NAME_t LCD_NAME,u8 *Copy_u8CustomArray,u8 Block_u8Number,u8 Copy_X_u8Position,u8 Copy_Y_u8Position);
	LCD_enuErrorStatus LCD_enuWriteNumber(LCD_NAME_t LCD_NAME,u16 Copy_u16Number);
	void LCD_enuLCDCLEAR(LCD_NAME_t LCD_NAME);

	extern const LCD_Configurations_t LCD_Configurations[LCD_COUNT];
#endif




