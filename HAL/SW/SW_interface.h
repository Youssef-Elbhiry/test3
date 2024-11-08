/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SW_intrface.h>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*
* Author :youssef elbhiry
* Layer  :HAL
* SWC    :SW
*
*/
#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H 

#define SW_INT_PULL_UP   2
#define SW_EXT_PULL_UP   1
#define SW_EXT_PULL_DOWN 0

#define SW_PRESED    1
#define SW_NOTPRESED 0

typedef struct{
	u8 port;
	u8 pin;
	u8 pullstate;
} SW_t;

void SW_voidInit(SW_t copy_structconfig);
u8   SW_u8ReadSwitch(SW_t copy_structconfig);

#endif