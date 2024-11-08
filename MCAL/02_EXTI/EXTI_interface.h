/*
*
*   EXTI_interface.h
*
* Author : Youssef Sami Elbhiry
* Layer  : MCAL
* SWC    : EXTI
*
*/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define   ACTIVE        1
#define   DEACTIVE      3

#define   RISING_EDGE   1
#define   FALLING_EDGE  2
#define   ANY_CHANGE    3
#define   LOW_LEVEL     4


#define   INT0          0
#define   INT1          1
#define   INT2          2



void EXTI_voidInit(EXTI_t *copy_PstrEXTIConfig);
void EXTI_voidSetSenceMode(u8  copy_u8EXTIid,u8 copy_u8SenceMode);
void EXTI_voidEnableInt(u8 copy_u8EXTIid);
void EXTI_voidDisableInt(u8  copy_u8EXTIid);
void EXTI_voidSetCallBack(void(* copy_PTfuncPtr)(void),u8  copy_u8IsrId);

#endif
