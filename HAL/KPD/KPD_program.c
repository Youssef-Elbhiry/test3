/*
*
*  KPD_program.c
*
*  Author : Youssef Sami Elbhiry
*  Layer  : HAL
*  SWC    : KPD
* 
*/

#include "STD_types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_private.h"


void KPD_voidInit()
{
	DIO_enumSetPinDirection(KPD_PORT,KPD_ROW0_PIN,DIO_PIN_INPUT );
	DIO_enumSetPinDirection(KPD_PORT,KPD_ROW1_PIN,DIO_PIN_INPUT );
	DIO_enumSetPinDirection(KPD_PORT,KPD_ROW2_PIN,DIO_PIN_INPUT );
	DIO_enumSetPinDirection(KPD_PORT,KPD_ROW3_PIN,DIO_PIN_INPUT );
	DIO_enumSetPinDirection(KPD_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KPD_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KPD_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection(KPD_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);
	
	
	// make the pin internal pull up
	DIO_enumSetPinValue(KPD_PORT,KPD_ROW0_PIN,DIO_PIN_HIGH );
	DIO_enumSetPinValue(KPD_PORT,KPD_ROW1_PIN,DIO_PIN_HIGH );
	DIO_enumSetPinValue(KPD_PORT,KPD_ROW2_PIN,DIO_PIN_HIGH );
	DIO_enumSetPinValue(KPD_PORT,KPD_ROW3_PIN,DIO_PIN_HIGH );
	
	
	DIO_enumSetPinValue(KPD_PORT,KPD_COL0_PIN,DIO_PIN_HIGH );
	DIO_enumSetPinValue(KPD_PORT,KPD_COL1_PIN,DIO_PIN_HIGH );
	DIO_enumSetPinValue(KPD_PORT,KPD_COL2_PIN,DIO_PIN_HIGH );
	DIO_enumSetPinValue(KPD_PORT,KPD_COL3_PIN,DIO_PIN_HIGH );
	
}
u8 KPD_u8ReadPressedSwitch()
{  
  u8 LOC_u8PressedKey=KPD_NO_KEY_PRESSED;

  u8 LOC_u8ColumnIdx,LOC_u8RowIdx,LOC_u8PinState;	
   
  static  u8 LOC_u8KPDArr[COLUMN_NUM][ROW_NUM]=KPD_ARR_VAL;
  
  static  u8 LOC_u8KPDColumnPin[COLUMN_NUM]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
  
  static  u8 LOC_u8KPDRowPin[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
  
  for(LOC_u8ColumnIdx=0;LOC_u8ColumnIdx<COLUMN_NUM;LOC_u8ColumnIdx++)
  {  // activate column pin
	  DIO_enumSetPinValue(KPD_PORT,LOC_u8KPDColumnPin[LOC_u8ColumnIdx],DIO_PIN_LOW );
	    
  for(LOC_u8RowIdx=0;LOC_u8RowIdx<ROW_NUM;LOC_u8RowIdx++)
  {    //read current row
	  DIO_enumGetPinValue(KPD_PORT,LOC_u8KPDRowPin[LOC_u8RowIdx],&LOC_u8PinState);
	  
	  if(DIO_PIN_LOW==LOC_u8PinState)
	  {
		  LOC_u8PressedKey=LOC_u8KPDArr[LOC_u8RowIdx][LOC_u8ColumnIdx];
		  
		  // busy wating until key is not pressed
		  while(DIO_PIN_LOW==LOC_u8PinState)
		  {
			DIO_enumGetPinValue(KPD_PORT,LOC_u8KPDRowPin[LOC_u8RowIdx],&LOC_u8PinState);  
		  }
		  return LOC_u8PressedKey;
	  }
	  
  }
  //deactivate column pin
   DIO_enumSetPinValue(KPD_PORT,LOC_u8KPDColumnPin[LOC_u8ColumnIdx],DIO_PIN_HIGH );
	  
  }
  return LOC_u8PressedKey;

	
	
}