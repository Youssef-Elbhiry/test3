/*
 * main.c
 *
 *  Created on: Nov 7, 2024
 *      Author: Youssef Sami Elbhiry
 */
#include "LIB/STD_types.h"

#include "MCAL/01_DIO/DIO_interface.h"

#include "MCAL/02_EXTI/EXTI_config.h"
#include "MCAL/02_EXTI/EXTI_interface.h"

 extern EXTI_t EXTI_AstrConfig[3];
 void tog();
int main()
{
	DIO_enumSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_enumSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	EXTI_voidInit(EXTI_AstrConfig);
	EXTI_voidSetCallBack(tog,0);

return 0;
}



void tog()
{
	DIO_enumTogglePin(DIO_PORTA,DIO_PIN2);

}
