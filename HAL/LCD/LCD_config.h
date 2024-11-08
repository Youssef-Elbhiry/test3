/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LCD_config.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
*
*
* Author :youssef elbhiry
* Layer  :HAL
* SWC    :LCD
*
*/
#ifndef  LCD_CONFIG_H
#define  LCD_CONFIG_H


#define LCD_MODE      8


//#define LCD_DATA_PORT DIO_PORTA

/*    data pins          */
#define LCD_D0_PORT DIO_PORTA
#define LCD_D0_PIN  DIO_PIN0
							
#define LCD_D1_PORT DIO_PORTA
#define LCD_D1_PIN  DIO_PIN1
							
#define LCD_D2_PORT DIO_PORTA
#define LCD_D2_PIN  DIO_PIN2
							
#define LCD_D3_PORT DIO_PORTA
#define LCD_D3_PIN  DIO_PIN3
							
#define LCD_D4_PORT DIO_PORTA
#define LCD_D4_PIN  DIO_PIN4
							
#define LCD_D5_PORT DIO_PORTA
#define LCD_D5_PIN  DIO_PIN5
							
#define LCD_D6_PORT DIO_PORTA
#define LCD_D6_PIN  DIO_PIN6
							
#define LCD_D7_PORT DIO_PORTA
#define LCD_D7_PIN  DIO_PIN7
							


/*      control pins        */
#define LCD_RS_PORT DIO_PORTB
#define LCD_RS_PIN DIO_PIN0
			  
#define LCD_RW_PORT DIO_PORTB
#define LCD_RW_PIN DIO_PIN1
			  
#define LCD_EN_PORT DIO_PORTB
#define LCD_EN_PIN DIO_PIN2




#endif