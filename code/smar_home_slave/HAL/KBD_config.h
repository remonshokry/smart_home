#ifndef                KBD_CONFIG_H
#define                KBD_CONFIG_H
/***********************************************************************/
u8 KBD_Arr[4][4] = {
						/* C0    C1   C2     C3           */
						{ '1' , '2' , '3' , '+' } /* Row0 */ ,
						{ '4' , '5' , '6' , '-' } /* Row1 */ ,
						{ '7' , '8' , '9' , '*' } /* Row2 */ ,
						{ 'E' , '0' , 'C' , '/' } /* Row3 */

					};
/***********************************************************************/
#define KBD_COL_INIT  PIN4
#define KBD_COL_END   PIN7
/***********************************************************************/
#define KBD_ROW_INIT  PIN3
#define KBD_ROW_END   PIN6
/***********************************************************************/
#define ROW_PORT     PORTC
#define COL_PORT     PORTB
/***********************************************************************/
#define KBD_ROW0_PIN  PIN3
#define KBD_ROW1_PIN  PIN4
#define KBD_ROW2_PIN  PIN5
#define KBD_ROW3_PIN  PIN6
/***********************************************************************/
#define KBD_COL0_PIN  PIN4
#define KBD_COL1_PIN  PIN5
#define KBD_COL2_PIN  PIN6
#define KBD_COL3_PIN  PIN7
/***********************************************************************/
#endif