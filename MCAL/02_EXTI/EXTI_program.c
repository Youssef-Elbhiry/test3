/*
*
*   EXTI_program.h
*
* Author : Youssef Sami Elbhiry
* Layer  : MCAL
* SWC    : EXTI
*
*/

#include "../../LIB/STD_types.h"
#include "../../LIB/BIT_MATH.h"

#include "../01_DIO/DIO_interface.h"


#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "interrupt.h"
static volatile void (*EXTI_APtrTIntfunc[3])(void)={NULL,NULL,NULL};

void EXTI_voidInit(EXTI_t *copy_PstrEXTIConfig)
{
	u8 LOC_u8Iterator=0;
	for(LOC_u8Iterator=0;LOC_u8Iterator<3;LOC_u8Iterator++)
	{
		if(copy_PstrEXTIConfig[LOC_u8Iterator].EXTI_u8state==ACTIVE)
		{  
	       switch(LOC_u8Iterator)
		   {
		   case INT0:
			SET_BIT(GICR,6);
			
			switch(copy_PstrEXTIConfig[LOC_u8Iterator].EXTI_u8sencemode)
		   {
		   case RISING_EDGE :
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case ANY_CHANGE :
			CLR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
			case LOW_LEVEL :
			CLR_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
			break;
		   }
			break;
			case INT1:
			SET_BIT(GICR,7);
			
		switch(copy_PstrEXTIConfig[LOC_u8Iterator].EXTI_u8sencemode)
		   {
		   case RISING_EDGE :
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCR,ISC2);
			SET_BIT(MCUCR,ISC11);
			break;
			case ANY_CHANGE :
			CLR_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break;
			case LOW_LEVEL :
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		   }
			break;
			case INT2:
			SET_BIT(GICR,5);
			switch(copy_PstrEXTIConfig[LOC_u8Iterator].EXTI_u8sencemode)
		   {
		   case RISING_EDGE :
			SET_BIT(MCUCSR,ISC2);
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCSR,ISC2);
			break;
			
		   }
			break;
		   }
		   
		   
			
		}
	}
}
void EXTI_voidSetSenceMode(u8  copy_u8EXTIid,u8 copy_u8SenceMode)
{   

    if(copy_u8EXTIid>=0&&copy_u8EXTIid<=2)
	{
     switch(copy_u8EXTIid )
    {
	    case INT0 :
		EXTI_AstrConfig[0].EXTI_u8sencemode=copy_u8SenceMode;
		switch(copy_u8SenceMode)
		{
	       case RISING_EDGE :
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case ANY_CHANGE :
			CLR_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
			break;
			case LOW_LEVEL :
			CLR_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
			break;
		}
		break;
		case INT1 :
		EXTI_AstrConfig[1].EXTI_u8sencemode=copy_u8SenceMode;
		switch(copy_u8SenceMode)
		{
	      case RISING_EDGE :
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case FALLING_EDGE :
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			case ANY_CHANGE :
			CLR_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break;
			case LOW_LEVEL :
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		}
		break;
		case INT2 :
		EXTI_AstrConfig[2].EXTI_u8sencemode=copy_u8SenceMode;
		switch(copy_u8SenceMode)
	{
		    case RISING_EDGE  :  SET_BIT(MCUCSR,ISC2); break;
			case FALLING_EDGE :  CLR_BIT(MCUCSR,ISC2); break;
			
    }
		break;
	
    }
	
}
}  






void EXTI_voidEnableInt(u8 copy_u8EXTIid)
{
	
	
	    switch(copy_u8EXTIid )
    {
	    case INT0 :
		EXTI_AstrConfig[0].EXTI_u8state=ACTIVE;
		SET_BIT(GICR,6);
		break;
		case INT1 :
		EXTI_AstrConfig[1].EXTI_u8state=ACTIVE;
		SET_BIT(GICR,7);
		break;
		case INT2 :
		EXTI_AstrConfig[2].EXTI_u8state=ACTIVE;
	    SET_BIT(GICR,5);
	   break;
    }
	
}
void EXTI_voidDisableInt(u8  copy_u8EXTIid)
{
	    switch(copy_u8EXTIid )
    {
	    case INT0 :
		EXTI_AstrConfig[0].EXTI_u8state=DEACTIVE;
		CLR_BIT(GICR,6);
		break;
		case INT1 :
		EXTI_AstrConfig[1].EXTI_u8state=DEACTIVE;
		CLR_BIT(GICR,7);
		break;
		case INT2 :
		EXTI_AstrConfig[2].EXTI_u8state=DEACTIVE;
	    CLR_BIT(GICR,5);
	   break;
    }
	
}

void EXTI_voidSetCallBack(void (* copy_PTfuncPtr) (void),u8  copy_u8IsrId)
{    if(copy_PTfuncPtr!=NULL&&copy_u8IsrId>=0&&copy_u8IsrId<=2)
	{

    EXTI_APtrTIntfunc[copy_u8IsrId]=copy_PTfuncPtr;

	}
}

ISR(VECT_INT0)

{
	if(EXTI_APtrTIntfunc[0]!=NULL)
	{
		EXTI_APtrTIntfunc[0]();
	}
}
ISR(VECT_INT1)

{
	if(EXTI_APtrTIntfunc[1]!=NULL)
	{
		EXTI_APtrTIntfunc[1]();
	}	
}
ISR(VECT_INT2)

{
	if(EXTI_APtrTIntfunc[2]!=NULL)
	{
		EXTI_APtrTIntfunc[2]();
	}
}
