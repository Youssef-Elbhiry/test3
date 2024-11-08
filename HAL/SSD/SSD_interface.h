/*
*
*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SSD_interface.h>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
* Author : youssef sami elbhiry
* Layer  : HAL
* SWC    : SSD
*
*/
#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

#define SSD_COMMON_CATHODE 0
#define SSD_COMMON_ANODE   1

typedef struct{
	u8 port;
	u8 enableport;
	u8 enablepin;
	u8 type;
} SSD_type;

void SSD_voidInit           (SSD_type  copy_configration);
void SSD_voidEnable         (SSD_type  copy_configration);
void SSD_voidDisable        (SSD_type  copy_configration);
void SSD_voidDisplayNumbers (SSD_type  copy_configration,u8 copy_u8Number);


#endif