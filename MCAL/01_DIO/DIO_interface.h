/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*
* Author :youssef elbhiry
* Layer  :MCAL
* SWC    :DIO/GPIO
*
*/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

typedef enum
{
	DIO_OK,
	DIO_NOK
}DIO_enumstatus;

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT  0

#define DIO_PORT_HIGH 0xff
#define DIO_PORT_LOW  0
#define NULL  (void *)0

DIO_enumstatus DIO_enumSetPinDirection   (u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Direction );
DIO_enumstatus DIO_enumSetPinValue       (u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value     );
DIO_enumstatus DIO_enumGetPinValue       (u8 copy_u8PORT , u8 copy_u8PIN,u8 *copy_u8Return     );
DIO_enumstatus DIO_enumTogglePin         (u8 copy_u8PORT , u8 copy_u8PIN                       );
DIO_enumstatus DIO_enumSetPortDirection  (u8 copy_u8PORT , u8 copy_u8Direction                 );
DIO_enumstatus DIO_enumSetPortValue      (u8 copy_u8PORT , u8 copy_u8PortValue                 );
DIO_enumstatus DIO_enumTogglePortValue   (u8 copy_u8PORT                                       );
DIO_enumstatus DIO_enumGetPortValue      (u8 copy_u8PORT , u8 *copy_u8Return                   );
DIO_enumstatus DIO_enumWriteToRightNibble(u8 copy_u8PORT , u8 copy_u8PortValue                 );
DIO_enumstatus DIO_enumWriteToLeftNibble (u8 copy_u8PORT , u8 copy_u8PortValue                 );
 

#endif
