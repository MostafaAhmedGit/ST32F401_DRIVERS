/*************************************************************
 * 
 * Filename: LCD.C
 * Description: Source (interface) file of the LCD driver.
 * Author: Eng. Mostafa Ahmed
 * Github: https://github.com/MostafaAhmedGit
 * 
 *************************************************************/


#include "GPIO.h"
#include "LCD.h"
#include "LCD_config.h"
#define F_CPU 8000000

#define DATA_BIT_0	0
#define DATA_BIT_1	1
#define DATA_BIT_2	2
#define DATA_BIT_3	3
#define DATA_BIT_4	4
#define DATA_BIT_5	5
#define DATA_BIT_6	6
#define DATA_BIT_7	7

#include "SYSTCK.h"
#include "Bitmath.h"
void delay_ms(s64 Delay)
{
	Delay = (volatile s64)((volatile s64)Delay*((volatile s64)F_CPU/25000000.0)*29.41);
	while(Delay)
	{
		__asm volatile("nop");
		Delay--;
	}

}

static void SET_PORT_USING_HEX(LCD_NAME_t LCD_NAME,u8 Copy_enuCommand);

LCD_enuErrorStatus LCD_enuWriteCommand(LCD_NAME_t LCD_NAME,u8 Copy_enuCommand)
{
	LCD_enuErrorStatus Status = LCD_enuOK;
	
	#if LCD_MODE==LCD_MODE_8_BIT
	
	/*	SET RS PIN LOW TO ENABLE COMMAND MODE IN LCD */
	GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_RS_PIN.Port,LCD_Configurations[LCD_NAME].LCD_RS_PIN.Pin,GPIO_PIN_LOW);
	/*  SET RW PIN LOW TO ENABLE WRITE MODE ON LCD	*/
	GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_RW_PIN.Port,LCD_Configurations[LCD_NAME].LCD_RW_PIN.Pin,GPIO_PIN_LOW);
	/* SET COMMAND TO DATA PINS	  */
	SET_PORT_USING_HEX(LCD_NAME,Copy_enuCommand);
	
	/*	SET ENABLE PULSE							*/
	GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_E_PIN.Port,LCD_Configurations[LCD_NAME].LCD_E_PIN.Pin,GPIO_PIN_HIGH);
	
	
	delay_ms(2);



	GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_E_PIN.Port,LCD_Configurations[LCD_NAME].LCD_E_PIN.Pin,GPIO_PIN_LOW);
	
	#elif LCD_MODE==LCD_MODE_4_BIT
	
	#endif
	
	return Status;
	
}

void LCD_enuLCDCLEAR(LCD_NAME_t LCD_NAME)
{
	LCD_enuWriteCommand(LCD_NAME,0x01);
}

LCD_enuErrorStatus LCD_enuSendData(LCD_NAME_t LCD_NAME,u8 Copy_u8Data)
{
		LCD_enuErrorStatus Status = LCD_enuOK;

		/*	SET RS PIN LOW TO ENABLE DATA MODE IN LCD */
		
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_RS_PIN.Port,LCD_Configurations[LCD_NAME].LCD_RS_PIN.Pin,GPIO_PIN_HIGH);

		/*  SET RW PIN LOW TO ENABLE WRITE MODE ON LCD	*/
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_RW_PIN.Port,LCD_Configurations[LCD_NAME].LCD_RS_PIN.Pin,GPIO_PIN_LOW);
		
		/* SET COMMAND TO DATA PINS						*/
		SET_PORT_USING_HEX(LCD_NAME,Copy_u8Data);
		
		/*	SET ENABLE PULSE							*/
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_E_PIN.Port,LCD_Configurations[LCD_NAME].LCD_E_PIN.Pin,GPIO_PIN_HIGH);
		
		
		delay_ms(3);
//		Systck_SetTime(5,25000000);

		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_E_PIN.Port,LCD_Configurations[LCD_NAME].LCD_E_PIN.Pin,GPIO_PIN_LOW);
		
		return Status;
}

LCD_enuErrorStatus LCD_enuInit(LCD_NAME_t LCD_NAME)
{
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_E_PIN.Port,LCD_Configurations[LCD_NAME].LCD_E_PIN.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_RW_PIN.Port,LCD_Configurations[LCD_NAME].LCD_RW_PIN.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_RS_PIN.Port,LCD_Configurations[LCD_NAME].LCD_RS_PIN.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_DATA_L1.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L1.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_DATA_L2.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L2.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_DATA_L3.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L3.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_DATA_L4.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L4.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_DATA_L5.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L5.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_DATA_L6.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L6.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_DATA_L7.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L7.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);
		GPIO_enuSetPinDirection(LCD_Configurations[LCD_NAME].LCD_DATA_L8.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L8.Pin,GPIO_MODE_OUTPUT_PUSH_PULL,GPIO_SPEED_HIGH);



	LCD_enuErrorStatus Status = LCD_enuOK;
	
	/* Wait for more than 30 ms 	*/
	delay_ms(40);
//	_delay_ms(40);
	
	
	/* Function Set Command : 2 lines , 5*8 Font Size*/
	
	// N  ---> Number of lines 
	// F ----> Font Size   0 = 5*8, 1 = 5*11
	
	//RS RW DL1 DL2 ...
	// 0  0  0  0  1  1  N  F  X  X


	LCD_enuWriteCommand(LCD_NAME,30);
	
	//D  ----> Display enable (Screen),  0--> Disable , 1--> Enable
	//C  ----> Cursor enable 0--> Disable , 1--> Enable
	//B  ----> Blink Cursor 0 ---> No blink, 1 ---> Blink
	
	LCD_enuWriteCommand(LCD_NAME,0x0C);
	
	
	/* CLR Display  */
	
	LCD_enuWriteCommand(LCD_NAME,0x01);
	
	return Status;
}

LCD_enuErrorStatus LCD_enuWriteString(LCD_NAME_t LCD_NAME,const char* Copy_PtrString)
{
	LCD_enuErrorStatus Status=LCD_enuOK;
	u8 Local_u8Counter=0;
	
	while(Copy_PtrString[Local_u8Counter]!='\0')
	{
		LCD_enuSendData(LCD_NAME,Copy_PtrString[Local_u8Counter]);
		Local_u8Counter++;
	}
	
	return Status;
	
}

LCD_enuErrorStatus LCD_enuGoToXY(LCD_NAME_t LCD_NAME,u8 Copy_u8X_Pos,u8 Copy_u8Y_Pos)
{
	
	LCD_enuErrorStatus Status = LCD_enuOK;
	
	u8 Local_u8Address=0;
	
	if(Copy_u8X_Pos==0)
	/*Location is at 1st line	*/
	Local_u8Address=Copy_u8Y_Pos;
	
	else if(Copy_u8X_Pos==1)
	/*Location is at 2nd line	*/
	Local_u8Address=Copy_u8Y_Pos+0x40;
	
	LCD_enuWriteCommand(LCD_NAME,Local_u8Address|0x80);
	
	return Status;
}


LCD_enuErrorStatus LCD_enuWriteNumber(LCD_NAME_t LCD_NAME,u16 Copy_u16Number)
{
	LCD_enuErrorStatus Status = LCD_enuOK;
	
	char arr[5];
	
	//10 means decimal 
	itoa(Copy_u16Number,arr,10);
	
	LCD_enuWriteString(LCD_NAME,arr);
	
	return Status;
	
}


LCD_enuErrorStatus LCD_enuWriteSpecialChar(LCD_NAME_t LCD_NAME,u8 *Copy_u8CustomArray,u8 Block_u8Number,u8 Copy_X_u8Position,u8 Copy_Y_u8Position)
{
	LCD_enuErrorStatus Status=LCD_enuOK;
	
	u8 Local_u8Counter;
	u8 Local_u8CGRAM_Address;
	
	/*	Locating a certain block in the CG-RAM		*/
	Local_u8CGRAM_Address = Block_u8Number*8;
	
	
	/* Sending the command to write on cg ram		*/
	LCD_enuWriteCommand(LCD_NAME,Local_u8CGRAM_Address|64);
	
	/*Writing on this location the special character*/
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		LCD_enuSendData(LCD_NAME,Copy_u8CustomArray[Local_u8Counter]);
	}
	
	LCD_enuGoToXY(LCD_NAME,Copy_X_u8Position,Copy_Y_u8Position);
	LCD_enuSendData(LCD_NAME,Block_u8Number);
	
	
	return Status;
	
}

static void SET_PORT_USING_HEX(LCD_NAME_t LCD_NAME,u8 Copy_enuCommand)
{
	GPIO_PIN_STATE v1=GPIO_PIN_LOW,v2=GPIO_PIN_LOW,v3=GPIO_PIN_LOW,v4=GPIO_PIN_LOW,v5=GPIO_PIN_LOW,v6=GPIO_PIN_LOW,v7=GPIO_PIN_LOW,v8 = GPIO_PIN_LOW;
	/*set pin direction of the data pins to OP PUSH PULL to ensure their direction is OP*/






//	ASSIGN_REG(((volatile GPIO*)GPIO_PORT_B)->BSRR,Copy_enuCommand);

		if(((Copy_enuCommand)&(1<<DATA_BIT_0))!=0)
			v1 = GPIO_PIN_HIGH;


		if(((Copy_enuCommand)&(1<<DATA_BIT_1))!=0)
			v2 = GPIO_PIN_HIGH;


		if(((Copy_enuCommand)&(1<<DATA_BIT_2))!=0)
			v3 = GPIO_PIN_HIGH;


		if(((Copy_enuCommand)&(1<<DATA_BIT_3))!=0)
			v4 = GPIO_PIN_HIGH;


		if(((Copy_enuCommand)&(1<<DATA_BIT_4))!=0)
			v5 = GPIO_PIN_HIGH;


		if(((Copy_enuCommand)&(1<<DATA_BIT_5))!=0)
			v6 = GPIO_PIN_HIGH;

		if(((Copy_enuCommand)&(1<<DATA_BIT_6))!=0)
			v7 = GPIO_PIN_HIGH;
		if(((Copy_enuCommand)&(1<<DATA_BIT_7))!=0)
			v8 = GPIO_PIN_HIGH;

		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_DATA_L1.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L1.Pin,v1);
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_DATA_L2.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L2.Pin,v2);
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_DATA_L3.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L3.Pin,v3);
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_DATA_L4.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L4.Pin,v4);
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_DATA_L5.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L5.Pin,v5);
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_DATA_L6.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L6.Pin,v6);
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_DATA_L7.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L7.Pin,v7);
		GPIO_enuSetPinValue(LCD_Configurations[LCD_NAME].LCD_DATA_L8.Port,LCD_Configurations[LCD_NAME].LCD_DATA_L8.Pin,v8);


}
