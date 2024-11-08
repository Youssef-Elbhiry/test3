/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LCD_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*
* Author :youssef elbhiry
* Layer  :HAL
* SWC    :LCD
*
*/

#include <util/delay.h>
#include "STD_types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


#include "LCD_config.h"
#include "LCD_private.h"
#include "LCD_interface.h"


void LCD_voidInit()
{
	_delay_ms(40);
	DIO_enumSetPinDirection (LCD_RS_PORT  ,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (LCD_RW_PORT ,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (LCD_EN_PORT  ,LCD_EN_PIN,DIO_PIN_OUTPUT);
	
    DIO_enumSetPinDirection (LCD_D4_PORT  ,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (LCD_D5_PORT  ,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (LCD_D6_PORT  ,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (LCD_D7_PORT  ,LCD_D7_PIN,DIO_PIN_OUTPUT);
	
	#if LCD_MODE==8
	
	//DIO_enumSetPortDirection(LCD_DATA_PORT,DIO_PORT_OUTPUT          );
	
	DIO_enumSetPinDirection (LCD_D0_PORT  ,LCD_D0_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (LCD_D1_PORT  ,LCD_D1_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (LCD_D2_PORT  ,LCD_D2_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection (LCD_D3_PORT  ,LCD_D3_PIN,DIO_PIN_OUTPUT);

		

	LCD_voidSendCommand(LCD_8BitFunction_Set);
	_delay_ms(1);
	
	#elif LCD_MODE==4
	  
	
	LCD_voidSendCommand(LCD_4BitFunction_Set);
	_delay_ms(1);
	
	
	#endif
	
	
	
	
	LCD_voidSendCommand(LCD_Display_On_Coursor_On);
	_delay_ms(1);
	
	
	LCD_voidClearScreen();
	
	LCD_voidSendCommand(LCD_Entry_Mode);
	_delay_ms(1);
}

void LCD_voidSendCommand(u8 copy_u8command)
{
	#if LCD_MODE==8
	
	//DIO_enumSetPortValue(LCD_DATA_PORT,copy_u8command);
	DIO_enumSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	
		LCD_voidSend(copy_u8command);																						
													
	LCD_voidSendFallingEdge();
	
	
	#elif LCD_MODE==4
	
	DIO_enumSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	
     LCD_voidSend(copy_u8Char);	// write most four bit										
		
	LCD_voidSendFallingEdge();
	
	LCD_voidSend(copy_u8Char<<4);	// write most four bit										
		
	LCD_voidSendFallingEdge();
	
	#endif
	
}

void LCD_voidSendChar(u8 copy_u8Char)
{
	#if LCD_MODE==8
	
	//DIO_enumSetPortValue(LCD_DATA_PORT,copy_u8Data);
	
	DIO_enumSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	
		LCD_voidSend(copy_u8Char);											
		
	LCD_voidSendFallingEdge();
	
	
	
	#elif LCD_MODE==4
	
	DIO_enumSetPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	
     LCD_voidSend(copy_u8Char);	// write most four bit										
		
	LCD_voidSendFallingEdge();
	
	LCD_voidSend(copy_u8Char<<4);	// write most four bit										
		
	LCD_voidSendFallingEdge();
	
	#endif
}


void LCD_voidSendString(u8 *copy_u8PtrString)
{ 
u8 LOC_u8Iterator=0;

  while(copy_u8PtrString[LOC_u8Iterator]!='\0')
  {
	  LCD_voidSendChar(copy_u8PtrString[LOC_u8Iterator]);
	  LOC_u8Iterator++;
  }
	
}

void LCD_voidSetPosition(u8 copy_u8Row,u8 copy_u8Col)
{
	u8 LOC_u8Data=0;
	if(copy_u8Row>2||copy_u8Row<1||copy_u8Col>16||copy_u8Col<1)
	{
		LOC_u8Data=LCD_Position11;
	} 
	else if(copy_u8Row==LCD_Row_1)
	{
		LOC_u8Data=LCD_Position11+(copy_u8Col-1);
	}
    else if(copy_u8Row==LCD_Row_2)
	{
		LOC_u8Data=(LCD_Position11+64)+(copy_u8Col-1);
	} 
	LCD_voidSendCommand(LOC_u8Data);
	_delay_ms(1);
}




static void LCD_voidSendFallingEdge()
{
    DIO_enumSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_enumSetPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
    _delay_ms(1);	
}

void LCD_voidClearScreen()
{
	LCD_voidSendCommand(LCD_Clear);
	_delay_ms(10);
}



static   void LCD_voidSend(u8 copy_u8Data)
{
	    DIO_enumSetPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
		
	#if  LCD_MODE==8
		DIO_enumSetPinValue(LCD_D0_PORT,LCD_D0_PIN,(copy_u8Data>>0)&1);
		DIO_enumSetPinValue(LCD_D1_PORT,LCD_D1_PIN,(copy_u8Data>>1)&1);
		DIO_enumSetPinValue(LCD_D2_PORT,LCD_D2_PIN,(copy_u8Data>>2)&1);
		DIO_enumSetPinValue(LCD_D3_PORT,LCD_D3_PIN,(copy_u8Data>>3)&1);
		
	#elif LCD_MODE==4
	
	
	#endif
	
	    DIO_enumSetPinValue(LCD_D4_PORT,LCD_D4_PIN,(copy_u8Data>>4)&1);
		DIO_enumSetPinValue(LCD_D5_PORT,LCD_D5_PIN,(copy_u8Data>>5)&1);
		DIO_enumSetPinValue(LCD_D6_PORT,LCD_D6_PIN,(copy_u8Data>>6)&1);
		DIO_enumSetPinValue(LCD_D7_PORT,LCD_D7_PIN,(copy_u8Data>>7)&1);
     
}


void LCD_voidSendExtraChar(u8 copy_u8row,u8 copy_u8col)
{
 u8 LOC_u8Iterator;
	LCD_voidSendCommand(LCD_SetCGRamAddress);
    for(LOC_u8Iterator=0;LOC_u8Iterator<sizeof(name);LOC_u8Iterator++)
    {
    	LCD_voidSendChar(name[LOC_u8Iterator]);
    }

    LCD_voidSetPosition(copy_u8row, copy_u8col);
	LCD_voidSendCommand(0x04);    // to write arabic letter

	 for(LOC_u8Iterator=0;LOC_u8Iterator<4;LOC_u8Iterator++)
    {
    	LCD_voidSendChar(LOC_u8Iterator);
    }

} 

void LCD_voidSendNumber(s32 copy_s32Number)
{
	if(copy_s32Number<0)
	{
		LCD_voidSendChar('-');
		copy_s32Number*=-1;
	}
	
	 if(copy_s32Number==0)
	{
		LCD_voidSendChar('0');
	} 
	else
	{
	  s32 LOC_s32Reversed=1;
	  while(copy_s32Number!=0)
	  {
		  LOC_s32Reversed=(LOC_s32Reversed*10)+(copy_s32Number%10);
		  copy_s32Number/=10;
	  } 
	  
	   while(LOC_s32Reversed!=1)
	  {
		  
		  
		  LCD_voidSendChar((LOC_s32Reversed%10)+48);
		  LOC_s32Reversed/=10;
	  }
	}
}