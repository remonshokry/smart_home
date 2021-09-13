#include      "STD_TYPES.h"
#include      "BIT_MATH.h"
#include      "DIO_interface.h"
#include      "SSD_config.h"
#include      "SSD_interface.h"
#include      <util/delay.h>
/***************************************************************************/
void SSD_voidInit( void )
{
	DIO_voidSetPinDirection( PORTA , PIN4 , OUTPUT );
	DIO_voidSetPinDirection( PORTA , PIN5 , OUTPUT );
	DIO_voidSetPinDirection( PORTA , PIN6 , OUTPUT );
	DIO_voidSetPinDirection( PORTA , PIN7 , OUTPUT );

	#if SSD_NUM_1 == SSD_A
		DIO_voidSetPinDirection( PORTB , PIN2 , OUTPUT );
	#endif
	
	#if SSD_NUM_2 == SSD_B
		DIO_voidSetPinDirection( PORTB , PIN1 , OUTPUT );
	#endif
}
/***************************************************************************/
void SSD_voidSendNumber( u8 Copy_u8Number )
{
	DIO_voidSetPortValue( PORTA , ( Copy_u8Number << 4 ) );
}
/***************************************************************************/
void SSD_voidEnableA  (void)
{
	if( SSD_NUM_1 == SSD_A )
	{	
		DIO_voidSetPinValue( PORTB , PIN2 , HIGH );
	}	
	else
	{
	  /*       DO NOTHING       */	
	}
}
/***************************************************************************/
void SSD_voidEnableB  (void){
	if( SSD_NUM_2 == SSD_B )
    {
		DIO_voidSetPinValue( PORTB , PIN1 , HIGH );
	}
	else
	{
	  /*       DO NOTHING       */		
	}
}
/***************************************************************************/
void SSD_voidDisbaleA (void)
{

	if( SSD_NUM_1 == SSD_A )
    {
		DIO_voidSetPinValue( PORTB , PIN2 , LOW );
	}
	else
	{
	  /*       DO NOTHING       */			
	}
}
/***************************************************************************/
void SSD_voidDisbaleB (void)
{
	if( SSD_NUM_2 == SSD_B )
    {
		DIO_voidSetPinValue( PORTB , PIN1 , LOW );
	}	
	else 
	{
	  /*       DO NOTHING       */		
	}
}
/***************************************************************************/
void SSD_voidSendTwoNumbers( u8 Number1,u8 Number2 )
{
	SSD_voidDisbaleB();
	SSD_voidSendNumber(Number1);
	SSD_voidEnableA();
	_delay_ms(10);

	SSD_voidDisbaleA();
	SSD_voidSendNumber(Number2);
	SSD_voidEnableB();
	_delay_ms(10);
}