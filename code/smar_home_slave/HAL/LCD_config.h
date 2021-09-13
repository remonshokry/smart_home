#ifndef                LCD_CONFIG_H
#define                LCD_CONFIG_H
/*******************************************************************/
/*
 Options :-
 	 1-LCD_USE
 	 2-LCD_NOT_USE
*/ 
#define         LCD_USAGE                  LCD_USE
/*******************************************************************/
/*
  Options :-
  	  1- DIO_PORTA
  	  2- DIO_PORTB
  	  3- DIO_PORTC
  	  4- DIO_PORTD
 */
#define         LCD_DATA_PORT              PORTA
#define         LCD_CONTROL_PORT           PORTB
/*******************************************************************/
/*
  Options :-
  	  1- DIO_PIN0
  	  2- DIO_PIN1
  	  3- DIO_PIN2
  	  4- DIO_PIN3
  	  4- DIO_PIN4
  	  4- DIO_PIN5
  	  4- DIO_PIN6
  	  4- DIO_PIN7
 */
#define          LCD_RS_PIN                PIN1
#define          LCD_RW_PIN                PIN2
#define          LCD_EN_PIN                PIN3
/*******************************************************************/
/*
  Options:-
     1- LCD_4_BIT_MODE
     2- LCD_8_BIT_MODE
 */
#define          LCD_MODE                  LCD_4_BIT_MODE
/*******************************************************************/
/*
  Options:-
     1- LCD_2_LINE
     2- LCD_1_LINE
 */
#define           LCD_NUMBER_OF_DISPLAY    LCD_2_LINE
/*******************************************************************/
/*
  Options:-
     1- LCD_5_7
     2- LCD_5_8
 */
#define           LCD_FONT_SIZE            LCD_5_8
/*******************************************************************/
/*
  Options:-
     1- LCD_DISPLAY_ON
     2- LCD_DISPLAY_OFF
 */
#define           LCD_DISPLAY              LCD_DISPLAY_ON
/*******************************************************************/
/*
  Options:-
     1- LCD_CURSOR_ON
     2- LCD_CURSOR_OFF
 */
#define           LCD_CURSOR               LCD_CURSOR_OFF
/*******************************************************************/
/*
  Options:-
     1- LCD_CURSOR_BLINK_ON
     2- LCD_CURSOR_BLINK_OFF
 */
#define            LCD_CURSOR_BLINK         LCD_CURSOR_BLINK_OFF
/*******************************************************************/
/*
  Options:-
     1- LCD_SHIFT_LEFT
     2- LCD_SHIFT_RIGHT
     3- LCD_DISABLE_SHIFT
 */
/*******************************************************************/
#define           LCD_SHIFT_DIRECTION       LCD_DISABLE_SHIFT
/*******************************************************************/
#endif
