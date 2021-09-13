#ifndef                LCD_INTERFACE_H
#define                LCD_INTERFACE_H
/**************************************************************************************************/
#define                LCD_NOT_USE                  0
#define                LCD_USE                      1
/**********************Function Set****************************************************************/
#define                LCD_8_BIT_MODE               1
#define                LCD_4_BIT_MODE               0
/**************************************************************************************************/
#define                LCD_2_LINE                   1
#define                LCD_1_LINE                   0
/**************************************************************************************************/
#define                LCD_5_7                      1
#define                LCD_5_8                      0
/**********************Display ON / OFF************************************************************/
#define                LCD_DISPLAY_ON               1
#define                LCD_DISPLAY_OFF              0
/**************************************************************************************************/
#define                LCD_CURSOR_ON                1
#define                LCD_CURSOR_OFF               0
/**************************************************************************************************/
#define                LCD_CURSOR_BLINK_ON          1
#define                LCD_CURSOR_BLINK_OFF         0
/**********************Entry Mode******************************************************************/
#define                LCD_SHIFT_LEFT               0
#define                LCD_SHIFT_RIGHT              1
#define                LCD_DISABLE_SHIFT            2
/**********************Clear The Entire Display****************************************************/											        
#define                LCD_DISPLAY_CLEAR            1
/**************************************************************************************************/											        
#define                LCD_ROW_1                    1
#define                LCD_ROW_2                    2
/**************************************************************************************************/											        
#define                LCD_COL_1                    1
#define                LCD_COL_2                    2
#define                LCD_COL_3                    3
#define                LCD_COL_4                    4
#define                LCD_COL_5                    5
#define                LCD_COL_6                    6
#define                LCD_COL_7                    7
#define                LCD_COL_8                    8
#define                LCD_COL_9                    9
#define                LCD_COL_10                   10
#define                LCD_COL_11                   11
#define                LCD_COL_12                   12
#define                LCD_COL_13                   13
#define                LCD_COL_14                   14
#define                LCD_COL_15                   15
#define                LCD_COL_16                   16
/**************************************************************************************************/
void          LCD_voidInit            ( void );
void          LCD_voidWriteCommend    ( u8 Copy_u8Commend );
void          LCD_voidWriteData       ( u8 Copy_u8Data    );
	          
void          LCD_voidWriteString     ( u8 * Copy_u8ptrString );
void          LCD_voidSetPosition     ( u8   Copy_u8Row , u8 Copy_u8Col );
void          LCD_voidWriteNumber     ( u64  Copy_u8Number );
	          
void          LCD_voidWriteCustomChar ( u8 Copy_u8Row , u8 Copy_u8Col , u8 * Copy_u8CustomChar , u8 Copy_u8CharSize );
/**************************************************************************************************/
#endif