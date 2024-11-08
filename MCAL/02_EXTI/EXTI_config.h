/*
*
*   EXTI_config.h
*
* Author : Youssef Sami Elbhiry
* Layer  : MCAL
* SWC    : EXTI
*
*/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

//#include "EXTI_private.h"
//#include "EXTI_interface.h"





typedef struct
{
u8 EXTI_u8state;
u8 EXTI_u8sencemode;
}EXTI_t;

#include "EXTI_interface.h"

EXTI_t EXTI_AstrConfig[3]={
	
    {ACTIVE,RISING_EDGE},
	{DEACTIVE},
	{DEACTIVE}
	
};



#endif
