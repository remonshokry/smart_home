#include     "STD_TYPES.h"
#include     "BIT_MATH.h"
#include     "DIO_interface.h"
#include     "LCD_interface.h"
#include     "LCD_private.h"
#include     "LCD_config.h"
#include     "LCD_customchar.h"
#include     <util/delay.h>
/**************************************************************************************************/
void   LCD_voidInit   ( void )
{
	u8 LOC_u8FunctionSet = LCD_FUNCTION_SET_BIT_COMMEND ;
	u8 LOC_u8Display     = LCD_DISPLAY_ON_OFF_COMMEND   ;
	u8 LOC_u8EntryMode   = LCD_ENTRY_MODE_SET_COMMEND   ;

	DIO_voidSetPinDirection ( LCD_CONTROL_PORT  , LCD_RS_PIN , OUTPUT );
	DIO_voidSetPinDirection ( LCD_CONTROL_PORT  , LCD_RW_PIN , OUTPUT );
	DIO_voidSetPinDirection ( LCD_CONTROL_PORT  , LCD_EN_PIN , OUTPUT );

	_delay_ms( 50 );

	#if    LCD_NUMBER_OF_DISPLAY == LCD_2_LINE
		SET_BIT( LOC_u8FunctionSet , 3 );
	#elif  LCD_NUMBER_OF_DISPLAY == LCD_1_LINE
		CLR_BIT( LOC_u8FunctionSet , 3 );
	#endif

	#if    LCD_FONT_SIZE == LCD_5_7
		SET_BIT( LOC_u8FunctionSet , 2 );
	#elif  LCD_FONT_SIZE == LCD_5_8
		CLR_BIT( LOC_u8FunctionSet , 2 );
	#endif

	#if    LCD_DISPLAY == LCD_DISPLAY_ON
		SET_BIT( LOC_u8Display , 2 );
	#elif  LCD_DISPLAY == LCD_DISPLAY_OFF
		CLR_BIT( LOC_u8Display , 2 );
	#endif

	#if    LCD_CURSOR == LCD_CURSOR_ON
		SET_BIT( LOC_u8Display , 1 );
	#elif  LCD_CURSOR == LCD_CURSOR_OFF
		CLR_BIT( LOC_u8Display , 1 );
	#endif

	#if    LCD_CURSOR_BLINK == LCD_CURSOR_BLINK_ON
		SET_BIT( LOC_u8Display , 0 );
	#elif  LCD_CURSOR_BLINK == LCD_CURSOR_BLINK_OFF
		CLR_BIT( LOC_u8Display , 0 );
	#endif

	#if    LCD_SHIFT_DIRECTION == LCD_SHIFT_LEFT

		SET_BIT( LOC_u8EntryMode , 0 );
		SET_BIT( LOC_u8EntryMode , 1 );

	#elif  LCD_SHIFT_DIRECTION == LCD_SHIFT_RIGHT

		SET_BIT( LOC_u8EntryMode , 0 );
		CLR_BIT( LOC_u8EntryMode , 1 );

	#elif  LCD_SHIFT_DIRECTION == LCD_DISABLE_SHIFT

		CLR_BIT( LOC_u8EntryMode , 0 );
		SET_BIT( LOC_u8EntryMode , 1 );

	#endif

	#if LCD_MODE == LCD_8_BIT_MODE

		DIO_voidSetPortDirection( LCD_DATA_PORT     , 255 );

		SET_BIT( LOC_u8FunctionSet , 4 );
	#elif LCD_MODE == LCD_4_BIT_MODE
		DIO_voidSetPortDirection( LCD_DATA_PORT     , 0b11110000 );

		CLR_BIT( LOC_u8FunctionSet , 4 );
		LCD_voidWriteCommend( LOC_u8FunctionSet >> 4 );
	#endif

	LCD_voidWriteCommend( LOC_u8FunctionSet      );
	_delay_ms(1);
	LCD_voidWriteCommend( LOC_u8Display      );
	_delay_ms(1);
	LCD_voidWriteCommend( LCD_DISPLAY_CLEAR );
	_delay_ms(1);
	LCD_voidWriteCommend( LOC_u8EntryMode    );
	_delay_ms(1);
}
/**************************************************************************************************/
void   LCD_voidWriteCommend    ( u8 Copy_u8Commend )
{
	DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_RS_PIN    , LOW  );
	DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_RW_PIN    , LOW  );

	#if LCD_MODE == LCD_8_BIT_MODE
		DIO_voidSetPortValue( LCD_DATA_PORT    , Copy_u8Commend );

		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , HIGH );
		_delay_ms(1);
		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , LOW  );
		_delay_ms(1);
	#elif LCD_MODE == LCD_4_BIT_MODE
		DIO_voidSetPortValue( LCD_DATA_PORT    , Copy_u8Commend & 0xF0 );

		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , HIGH  );
		_delay_ms(1);
		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , LOW   );
		_delay_ms(1);

		DIO_voidSetPortValue( LCD_DATA_PORT    , Copy_u8Commend << 4 );

		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , HIGH  );
		_delay_ms(1);
		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , LOW   );
		_delay_ms(1);
	#endif
}
/**************************************************************************************************/
void   LCD_voidWriteData       ( u8 Copy_u8Data    )
{
	DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_RS_PIN    , HIGH  );
	DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_RW_PIN    , LOW   );

	#if LCD_MODE == LCD_8_BIT_MODE
		DIO_voidSetPortValue( LCD_DATA_PORT    , Copy_u8Data );

		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , HIGH  );
		_delay_ms(1);
		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , LOW   );
		_delay_ms(1);
	#elif LCD_MODE == LCD_4_BIT_MODE
		DIO_voidSetPortValue( LCD_DATA_PORT    , Copy_u8Data & 0xF0 );

		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , HIGH  );
		_delay_ms(1);
		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , LOW   );
		_delay_ms(1);

		DIO_voidSetPortValue( LCD_DATA_PORT    , Copy_u8Data << 4 );

		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , HIGH  );
		_delay_ms(1);
		DIO_voidSetPinValue ( LCD_CONTROL_PORT , LCD_EN_PIN    , LOW   );
		_delay_ms(1);
	#endif
}
/**************************************************************************************************/
void   LCD_voidWriteString     ( u8 * Copy_u8ptrString )
{
	u8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[ LOC_u8Iterator ] != '\0' )
	{
		LCD_voidWriteData( Copy_u8ptrString[ LOC_u8Iterator ] );
		LOC_u8Iterator++;
	}
}
/**************************************************************************************************/
void   LCD_voidSetPosition     ( u8   Copy_u8Row , u8 Copy_u8Col )
{
	if( Copy_u8Row == LCD_ROW_1 )
	{
		LCD_voidWriteCommend( LCD_SET_DDRAM_ADDRESS_COMMEDN + ( Copy_u8Col - 1 ) );

	}
	else if( Copy_u8Row  == LCD_ROW_2 )
	{
		LCD_voidWriteCommend( LCD_SET_DDRAM_ADDRESS_COMMEDN + 64 + ( Copy_u8Col - 1 ) );
	}
}
/**************************************************************************************************/
void   LCD_voidWriteNumber     ( u64  Copy_u8Number )
{
	u64 LOC_u64Reversed = 1 ;

	if( Copy_u8Number == 0 )
	{
		LCD_voidWriteData('0');
	}
	while( Copy_u8Number != 0 )
	{
		LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u8Number % 10 ) ;
		Copy_u8Number  /= 10 ;
	}
	while( LOC_u64Reversed != 1 )
	{
		LCD_voidWriteData( ( LOC_u64Reversed % 10 ) + 48 );
		LOC_u64Reversed  /= 10 ;
	}
}
/**************************************************************************************************/
/*
void   LCD_voidWriteCustomChar ( u8 Copy_u8Row , u8 Copy_u8Col , u8 * Copy_u8CustomChar , u8 Copy_u8CharSize )
{
	u8 LOC_u8Iterator = 0 ;

	LCD_voidWriteCommend( LCD_SET_CGRAM_ADDRESS_COMMEND );

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < Copy_u8CharSize / sizeof(CLCD_ExtraChar[0]) ; LOC_u8Iterator++ )
	{
		LCD_voidWriteData( (u8)LCD_ExtraChar[LOC_u8Iterator] );
	}
	LCD_voidWriteCommend( LCD_SET_DDRAM_ADDRESS_COMMEDN );

	LCD_voidSetPosition( Copy_u8Row , Copy_u8Col );

	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < Copy_u8CharSize / 8 ; LOC_u8Iterator++ )
	{
		LCD_voidWriteData( LOC_u8Iterator );
	}
}
#endif
*/
/**************************************************************************************************/
/*
void LCD_voidWriteCustomChar  (u8 *Ptr , u8 Len , u8 Row , u8 Col)
{
	s8 i=0;
	LCD_voidWriteCommend  ( 0x40 );
	for (i=0;i<Len;i++)
	{
		LCD_voidWriteData(Ptr[i]);
	}
	LCD_voidSetPosition(Row,Col);
	for (i=(Len/8)-1;i>=0;i--)
	{
		LCD_voidWriteData(i);
	}
}*/