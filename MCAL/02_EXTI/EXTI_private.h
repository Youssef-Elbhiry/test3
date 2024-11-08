/*
*
*   EXTI_private.h
*
* Author : Youssef Sami Elbhiry
* Layer  : MCAL
* SWC    : EXTI
*
*/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H




#define    MCUCR        *(( volatile u8*)0x55)
#define    MCUCSR       *(( volatile u8*)0x54)
#define    GICR         *(( volatile u8*)0x5B)
#define    GIFR         *(( volatile u8*)0x5A)
            

			
#define	  ISC00        0
#define	  ISC01        1
#define	  ISC10        2
#define	  ISC11        3

#define	  ISC2         6


#endif
