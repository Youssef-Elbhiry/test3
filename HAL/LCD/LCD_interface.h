/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LCD_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*
* Author :youssef elbhiry
* Layer  :HAL
* SWC    :LCD
*
*/
#ifndef  LCD_INTERFACE_H
#define  LCD_INTERFACE_H


#define LCD_8BitFunction_Set          0x38
#define LCD_4BitFunction_Set          0x28
#define LCD_Display_On_Coursor_Off    0x0c
#define LCD_Display_On_Coursor_On     0x0f
#define LCD_Display_Off_Coursor_Off   0x08
#define LCD_Clear                     0x01
#define LCD_Entry_Mode                0x06
#define LCD_Position11                0x80
#define LCD_SetCGRamAddress           0x40



 
#define LCD_Row_1                    1 
#define LCD_Row_2                    2 

#define LCD_Col_1                    1 
#define LCD_Col_2                    2 
#define LCD_Col_3                    3 
#define LCD_Col_4                    4 
#define LCD_Col_5                    5 
#define LCD_Col_6                    6 
#define LCD_Col_7                    7 
#define LCD_Col_8                    8 
#define LCD_Col_9                    9 
#define LCD_Col_10                   10 
#define LCD_Col_11                   11
#define LCD_Col_12                   12
#define LCD_Col_13                   13
#define LCD_Col_14                   14
#define LCD_Col_15                   15
#define LCD_Col_16                   16

 u8 name[]={ 0x00, 0x00, 0x01, 0x01, 0x1F, 0x00, 0x06, 0x00,
             0x00, 0x06, 0x09, 0x07, 0x02, 0x04, 0x18, 0x00,
			 0x00, 0x00, 0x00, 0x15, 0x15, 0x1F, 0x00, 0x00,
			 0x00, 0x02, 0x00, 0x07, 0x05, 0x1F, 0x00, 0x00,
			 0x04, 0x04, 0x04, 0x04, 0x04, 0x07, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x1F, 0x05, 0x02, 0x00, 0x00,
			 0x00, 0x00, 0x00, 0x13, 0x12, 0x0C, 0x00, 0x00};
 
 
void LCD_voidInit();
void LCD_voidSendCommand(u8 copy_u8Command);
void LCD_voidSendChar(u8 copy_u8Char);
void LCD_voidSendString(u8 *copy_u8PtrString);
void LCD_voidClearScreen();
void LCD_voidSetPosition(u8 copy_u8Row,u8 copy_u8Col);
void LCD_voidSendExtraChar(u8 copy_u8row,u8 copy_u8col);
void LCD_voidSendNumber(s32 copy_s32Number);
#endif