//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LED_program.h<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/*
*
* Author : Youssef sami elbhiry
* Layer  :HAL
* SW     :LED
*
*/
#include "STD_types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"

void LED_voidInit(LED_Type LED_configuration)
{
	DIO_enumSetPinDirection(LED_configuration.port,LED_configuration.pin,DIO_PIN_OUTPUT);
}

void LED_voidLedOn(LED_Type LED_configuration)
{
	if(LED_configuration.activestate==ACTIVE_LOW)
		DIO_enumSetPinValue(LED_configuration.port,LED_configuration.pin,DIO_PIN_LOW);
	
	else if(LED_configuration.activestate==ACTIVE_HIGH)
		DIO_enumSetPinValue(LED_configuration.port,LED_configuration.pin,DIO_PIN_HIGH);
}

void LED_voidLedOf(LED_Type LED_configuration)
{
	if(LED_configuration.activestate==ACTIVE_LOW)
		DIO_enumSetPinValue(LED_configuration.port,LED_configuration.pin,DIO_PIN_HIGH);
	
	else if(LED_configuration.activestate==ACTIVE_HIGH)
		DIO_enumSetPinValue(LED_configuration.port,LED_configuration.pin,DIO_PIN_LOW);
}

void LED_voidToggle(LED_Type LED_configuration)
{
	DIO_enumTogglePin(LED_configuration.port , LED_configuration.pin);
}
