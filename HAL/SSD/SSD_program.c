/*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SSD_prgram.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
* Author : youssef sami elbhiry
* Layer  : HAL
* SWC    : SSD
*
*/

#include "STD_types.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

u8 SSD_u8Numbers[10]=SSD_Values;

void SSD_voidInit (SSD_type  copy_configration)
{
		DIO_enumSetPortDirection(copy_configration.port,DIO_PORT_OUTPUT);
}
void SSD_voidEnable(SSD_type  copy_configration)
{
    if(copy_configration.type==SSD_COMMON_CATHODE)
	{
		DIO_enumSetPinDirection(copy_configration.enableport,copy_configration.enablepin,DIO_PIN_OUTPUT);
	  DIO_enumSetPinValue(copy_configration.enableport,copy_configration.enablepin,DIO_PIN_LOW); 
	}	  
	else if(copy_configration.type==SSD_COMMON_ANODE)
	{
		
		DIO_enumSetPinDirection(copy_configration.enableport,copy_configration.enablepin,DIO_PIN_OUTPUT);
	   DIO_enumSetPinValue(copy_configration.enableport,copy_configration.enablepin,DIO_PIN_HIGH);  
	}	
}

void SSD_voidDisable (SSD_type  copy_configration)
{
	if(copy_configration.type==SSD_COMMON_CATHODE)
	{
		DIO_enumSetPinDirection(copy_configration.enableport,copy_configration.enablepin,DIO_PIN_OUTPUT);
	   DIO_enumSetPinValue(copy_configration.enableport,copy_configration.enablepin,DIO_PIN_HIGH); 
	}	   
	else if(copy_configration.type==SSD_COMMON_ANODE)
	{
		
		DIO_enumSetPinDirection(copy_configration.enableport,copy_configration.enablepin,DIO_PIN_OUTPUT);
	   DIO_enumSetPinValue(copy_configration.enableport,copy_configration.enablepin,DIO_PIN_LOW);  
	}
}


void SSD_voidDisplayNumbers (SSD_type  copy_configration,u8 copy_u8Number){
	if(copy_configration.type==SSD_COMMON_CATHODE)
	{
		DIO_enumSetPortValue(copy_configration.port,SSD_u8Numbers[copy_u8Number]);
	}
	else if(copy_configration.type==SSD_COMMON_ANODE)
	{
		DIO_enumSetPortValue(copy_configration.port,~(SSD_u8Numbers[copy_u8Number]));
	}
}
