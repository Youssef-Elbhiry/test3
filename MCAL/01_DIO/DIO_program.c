/*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
* Author :youssef elbhiry
* Layer  :MCAL
* SWC    :DIO/GPIO
*
*/

#include "STD_types.h"
#include "BIT_MATH.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"

DIO_enumstatus DIO_enumSetPinDirection(u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Direction)
{ 

 DIO_enumstatus LOC_enumstatus=DIO_NOK;
 
if(copy_u8PORT<=DIO_PORTD && copy_u8PIN<=DIO_PIN7 && copy_u8Direction<=DIO_PIN_OUTPUT)
{
	if(copy_u8Direction==DIO_PIN_OUTPUT)
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA :SET_BIT(DDRA,copy_u8PIN); break;
			case DIO_PORTB :SET_BIT(DDRB,copy_u8PIN); break;
			case DIO_PORTC :SET_BIT(DDRC,copy_u8PIN); break;
			case DIO_PORTD :SET_BIT(DDRD,copy_u8PIN); break;
		}
		
	}
	else if(copy_u8Direction==DIO_PIN_INPUT)
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA :CLR_BIT(DDRA,copy_u8PIN); break;
			case DIO_PORTB :CLR_BIT(DDRB,copy_u8PIN); break;
			case DIO_PORTC :CLR_BIT(DDRC,copy_u8PIN); break;
			case DIO_PORTD :CLR_BIT(DDRD,copy_u8PIN); break;
		}
	} 
	LOC_enumstatus=DIO_OK;
}
return LOC_enumstatus;

}
DIO_enumstatus DIO_enumSetPinValue    (u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Value    )
{
	DIO_enumstatus LOC_enumstatus=DIO_NOK;
	if(copy_u8PORT<=DIO_PORTD && copy_u8PIN<=DIO_PIN7 && copy_u8Value<=DIO_PIN_HIGH)
{
if(copy_u8Value==DIO_PIN_HIGH)
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA :SET_BIT(PORTA,copy_u8PIN); break;
			case DIO_PORTB :SET_BIT(PORTB,copy_u8PIN); break;
			case DIO_PORTC :SET_BIT(PORTC,copy_u8PIN); break;
			case DIO_PORTD :SET_BIT(PORTD,copy_u8PIN); break;
		}
		
	}
	else if(copy_u8Value==DIO_PIN_LOW)
	{
		switch(copy_u8PORT)
		{
			case DIO_PORTA :CLR_BIT(PORTA,copy_u8PIN); break;
			case DIO_PORTB :CLR_BIT(PORTB,copy_u8PIN); break;
			case DIO_PORTC :CLR_BIT(PORTC,copy_u8PIN); break;
			case DIO_PORTD :CLR_BIT(PORTD,copy_u8PIN); break;
		}
	}
	LOC_enumstatus=DIO_OK;
}
return LOC_enumstatus;
}


DIO_enumstatus   DIO_enumGetPinValue      (u8 copy_u8PORT,u8 copy_u8PIN,u8 *copy_u8Return )
{     
    DIO_enumstatus LOC_enumstatus=DIO_NOK;

    if(copy_u8PORT<=DIO_PORTD && copy_u8PIN<=DIO_PIN7 && copy_u8Return!=NULL)
	{
	
	switch(copy_u8PORT)
		{
			case DIO_PORTA :*copy_u8Return=GET_BIT(PINA,copy_u8PIN); break;
			case DIO_PORTB :*copy_u8Return=GET_BIT(PINB,copy_u8PIN); break;
			case DIO_PORTC :*copy_u8Return=GET_BIT(PINC,copy_u8PIN); break;
			case DIO_PORTD :*copy_u8Return=GET_BIT(PIND,copy_u8PIN); break;
		}
		LOC_enumstatus=DIO_OK;
	}
	return LOC_enumstatus;
}
DIO_enumstatus DIO_enumTogglePin       (u8 copy_u8PORT,u8 copy_u8PIN  )
{  
   
    DIO_enumstatus LOC_enumstatus=DIO_NOK;

    if(copy_u8PORT<=DIO_PORTD && copy_u8PIN<=DIO_PIN7 )
	{
	switch(copy_u8PORT)
	{
	case DIO_PORTA : TOG_BIT(PORTA,copy_u8PIN); break;
	case DIO_PORTB : TOG_BIT(PORTB,copy_u8PIN); break;
	case DIO_PORTC : TOG_BIT(PORTC,copy_u8PIN); break;
	case DIO_PORTD : TOG_BIT(PORTD,copy_u8PIN); break;
	}
	LOC_enumstatus=DIO_OK;
	}
	return LOC_enumstatus;
}
DIO_enumstatus DIO_enumSetPortDirection(u8 copy_u8PORT ,u8 copy_u8Direction                           )
{ 
     DIO_enumstatus LOC_enumstatus=DIO_NOK;

    if(copy_u8PORT<=DIO_PORTD && copy_u8Direction<=DIO_PORT_OUTPUT )
	{
    
	switch(copy_u8PORT)
	{
	case DIO_PORTA : DDRA=DIO_PORT_OUTPUT; break;
	case DIO_PORTB : DDRB=DIO_PORT_OUTPUT; break;
	case DIO_PORTC : DDRC=DIO_PORT_OUTPUT; break;
	case DIO_PORTD : DDRD=DIO_PORT_OUTPUT; break;
	} 
	
	
	LOC_enumstatus=DIO_OK;
	}
	return LOC_enumstatus;
}
DIO_enumstatus DIO_enumSetPortValue    (u8 copy_u8PORT,u8 copy_u8PortValue              )
{
	DIO_enumstatus LOC_enumstatus=DIO_NOK;

    if(copy_u8PORT<=DIO_PORTD && copy_u8PortValue<=DIO_PORT_HIGH )
	{
	 
	switch(copy_u8PORT)
	{
	case DIO_PORTA : PORTA=copy_u8PortValue; break;
	case DIO_PORTB : PORTB=copy_u8PortValue; break;
	case DIO_PORTC : PORTC=copy_u8PortValue; break;
	case DIO_PORTD : PORTD=copy_u8PortValue; break;
	} 
	
	
	
	LOC_enumstatus=DIO_OK;
}
	return LOC_enumstatus;
}


DIO_enumstatus   DIO_enumGetPortValue      (u8 copy_u8PORT,u8 *copy_u8Return )
{    DIO_enumstatus LOC_enumstatus=DIO_NOK;

    if(copy_u8PORT<=DIO_PORTD && copy_u8Return!=NULL )
	{
	switch(copy_u8PORT)
	{
	case DIO_PORTA : *copy_u8Return=PINA; break;
	case DIO_PORTB : *copy_u8Return=PINB; break;
	case DIO_PORTC : *copy_u8Return=PINC; break;
	case DIO_PORTD : *copy_u8Return=PIND; break;
	}
	LOC_enumstatus=DIO_OK;
	}
     return LOC_enumstatus;
}
DIO_enumstatus DIO_enumTogglePortValue   (u8 copy_u8PORT )
{
DIO_enumstatus LOC_enumstatus=DIO_NOK;
    if(copy_u8PORT<=DIO_PORTD)
	{
		switch(copy_u8PORT)
		{
            case DIO_PORTA : PORTA=~PORTA; break;
	        case DIO_PORTB : PORTB=~PORTB; break;
	        case DIO_PORTC : PORTC=~PORTC; break;
	        case DIO_PORTD : PORTD=~PORTD; break; 
		}
		LOC_enumstatus=DIO_OK;
	}
	return LOC_enumstatus;
}


DIO_enumstatus DIO_enumWriteToRightNibble(u8 copy_u8PORT,u8 copy_u8PortValue)
{
   DIO_enumstatus LOC_enumstatus=DIO_NOK;	
   if(copy_u8PORT<=DIO_PORTD)
	{
		switch(copy_u8PORT)
		{
            case DIO_PORTA : PORTA&=0xf0;copy_u8PortValue&=0x0f;PORTA|=copy_u8PortValue; break;
	        case DIO_PORTB : PORTB&=0xf0;copy_u8PortValue&=0x0f;PORTB|=copy_u8PortValue; break;
	        case DIO_PORTC : PORTC&=0xf0;copy_u8PortValue&=0x0f;PORTC|=copy_u8PortValue; break;
	        case DIO_PORTD : PORTD&=0xf0;copy_u8PortValue&=0x0f;PORTD|=copy_u8PortValue; break; 
		}
		LOC_enumstatus=DIO_OK;
	}
	return LOC_enumstatus;
}
DIO_enumstatus DIO_enumWriteToLeftNibble(u8 copy_u8PORT,u8 copy_u8PortValue)
{
	copy_u8PortValue<<=4;;
   DIO_enumstatus LOC_enumstatus=DIO_NOK;	
   if(copy_u8PORT<=DIO_PORTD)
	{
		switch(copy_u8PORT)
		{
            case DIO_PORTA : PORTA&=0x0f;PORTA|=copy_u8PortValue; break;
	        case DIO_PORTB : PORTB&=0x0f;PORTB|=copy_u8PortValue; break;
	        case DIO_PORTC : PORTC&=0x0f;PORTC|=copy_u8PortValue; break;
	        case DIO_PORTD : PORTD&=0x0f;PORTD|=copy_u8PortValue; break; 
		}
		LOC_enumstatus=DIO_OK;
	}
	return LOC_enumstatus;
}

