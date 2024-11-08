/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SW_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*
* Author :youssef elbhiry
* Layer  :HAL
* SWC    :SW
*
*/

#include "STD_types.h"

#include "DIO_interface.h"
#include "SW_interface.h "

void SW_voidInit(SW_t copy_structconfig)
{
	DIO_enumSetPinDirection(copy_structconfig.port,copy_structconfig.pin,DIO_PIN_INPUT);
	
	if(copy_structconfig.pullstate==SW_INT_PULL_UP)
	{
		DIO_enumSetPinValue(copy_structconfig.port,copy_structconfig.pin,DIO_PIN_HIGH);
	}
}

u8   SW_u8ReadSwitch(SW_t copy_structconfig)
{ 
     u8 local_u8PinValue=0;
     u8 local_u8PinState=0;
	if(copy_structconfig.pullstate==SW_EXT_PULL_DOWN)
	{
		DIO_enumGetPinValue(copy_structconfig.port,copy_structconfig.pin,&local_u8PinValue);
		
		if(local_u8PinValue==1)
			local_u8PinState=SW_PRESED;
		else if(local_u8PinValue==0)
			local_u8PinState=SW_NOTPRESED;
	}
	else if(copy_structconfig.pullstate==SW_INT_PULL_UP||copy_structconfig.pullstate==SW_EXT_PULL_UP)
	{
		DIO_enumGetPinValue(copy_structconfig.port,copy_structconfig.pin,&local_u8PinValue);
		
		if(local_u8PinValue==0)
			local_u8PinState=SW_PRESED;
		else if(local_u8PinValue==1)
			local_u8PinState=SW_NOTPRESED;
	} 
	return local_u8PinState;
}