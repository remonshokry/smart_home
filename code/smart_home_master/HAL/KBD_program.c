#include      "STD_TYPES.h"
#include      "BIT_MATH.h"
#include      "DIO_interface.h"
#include      "KBD_config.h"
#include      "KBD_interface.h"
#include      <util/delay.h>
/***********************************************************************/
void KBD_voidInit(void)
{
	DIO_voidSetPinDirection( ROW_PORT, KBD_ROW0_PIN , INPUT  );
	DIO_voidSetPinDirection( ROW_PORT, KBD_ROW1_PIN , INPUT  );
	DIO_voidSetPinDirection( ROW_PORT, KBD_ROW2_PIN , INPUT  );
	DIO_voidSetPinDirection( ROW_PORT, KBD_ROW3_PIN , INPUT  );

	DIO_voidSetPinValue    ( ROW_PORT, KBD_ROW0_PIN , HIGH   );
	DIO_voidSetPinValue    ( ROW_PORT, KBD_ROW1_PIN , HIGH   );
	DIO_voidSetPinValue    ( ROW_PORT, KBD_ROW2_PIN , HIGH   );
	DIO_voidSetPinValue    ( ROW_PORT, KBD_ROW3_PIN , HIGH   );

	DIO_voidSetPinDirection( COL_PORT, KBD_COL0_PIN , OUTPUT );
	DIO_voidSetPinDirection( COL_PORT, KBD_COL1_PIN , OUTPUT );
	DIO_voidSetPinDirection( COL_PORT, KBD_COL2_PIN , OUTPUT );
	DIO_voidSetPinDirection( COL_PORT, KBD_COL3_PIN , OUTPUT );

	DIO_voidSetPinValue    ( COL_PORT, KBD_COL0_PIN , HIGH   );
	DIO_voidSetPinValue    ( COL_PORT, KBD_COL1_PIN , HIGH   );
	DIO_voidSetPinValue    ( COL_PORT, KBD_COL2_PIN , HIGH   );
	DIO_voidSetPinValue    ( COL_PORT, KBD_COL3_PIN , HIGH   );
}
/***********************************************************************/
u8   KBD_u8GetPressed(void)
{
	u8 LOC_GetPressedData = 0 ;
	u8 LOC_u8RowIterator  = 0 ;
	u8 LOC_u8ColIterator  = 0 ;

	for( LOC_u8ColIterator = 0 + KBD_COL_INIT ; LOC_u8ColIterator <= KBD_COL_END ; LOC_u8ColIterator ++ )
	{
		DIO_voidSetPinValue( COL_PORT, LOC_u8ColIterator , LOW );

		for( LOC_u8RowIterator = 0 + KBD_ROW_INIT  ; LOC_u8RowIterator <= KBD_ROW_END ; LOC_u8RowIterator ++ )
		{

			if( DIO_u8GetPinValue( ROW_PORT, LOC_u8RowIterator ) == 0 )
			{
				_delay_ms(50);

				if( DIO_u8GetPinValue( ROW_PORT, LOC_u8RowIterator ) == 0 )
				{
					//Return The Pressed Data
					LOC_GetPressedData = KBD_Arr[ LOC_u8RowIterator - KBD_ROW_INIT ][ LOC_u8ColIterator - KBD_COL_INIT ] ;
					while( DIO_u8GetPinValue( ROW_PORT, LOC_u8RowIterator ) == 0  );
				}
			}
		}
		DIO_voidSetPinValue( COL_PORT, LOC_u8ColIterator , HIGH );
	}
	return LOC_GetPressedData ;
}