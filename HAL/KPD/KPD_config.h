/*
*
*  KPD_config.h
*
*  Author : Youssef Sami Elbhiry
*  Layer  : HAL
*  SWC    : KPD
* 
*/


#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H


#define KPD_PORT       DIO_PORTA

#define KPD_NO_KEY_PRESSED       0xff

  // ROW PINS

#define KPD_ROW0_PIN   DIO_PIN0
#define KPD_ROW1_PIN   DIO_PIN1
#define KPD_ROW2_PIN   DIO_PIN2
#define KPD_ROW3_PIN   DIO_PIN3

  // COL PINS
  

#define KPD_COL0_PIN   DIO_PIN4
#define KPD_COL1_PIN   DIO_PIN5
#define KPD_COL2_PIN   DIO_PIN6
#define KPD_COL3_PIN   DIO_PIN7


#define KPD_ARR_VAL  {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#endif