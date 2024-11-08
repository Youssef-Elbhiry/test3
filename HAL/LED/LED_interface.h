>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>LED_interface.h<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/*
*
* Author : Youssef sami elbhiry
* Layer  :HAL
* SW     :LED
*
*/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H
/////////////////////////// types

#define LED_PORTA 0
#define LED_PORTB 1
#define LED_PORTC 2
#define LED_PORTD 3

#define LED_PIN0 0
#define LED_PIN1 1
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7

#define ACTIVE_LOW 0
#define ACTIVE_HIGH 1

typedef struct{
	u8 port;
	u8 pin;
	u8 activestate;
}LED_Type;

void LED_voidInit  (LED_Type LED_configuration);
void LED_voidLedOn (LED_Type LED_configuration);
void LED_voidLedOf (LED_Type LED_configuration);
void LED_voidToggle(LED_Type LED_configuration);
#endif