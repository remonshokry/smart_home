#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "DIO_interface.h"
#include   "EXTI_private.h"
#include   "EXTI_config.h"
#include   "EXTI_interface.h"
/********************************************************************************************************************/
void (*EXTI_CALLBACK[3])(void);
/********************************************************************************************************************/
void      EXTI_voidSetCallBack       (void(*ptr)(void) , u8 copy_u8Line)
{
	EXTI_CALLBACK[copy_u8Line] = ptr;
}
/********************************************************************************************************************/
void __vector_1 (void)
{
	EXTI_CALLBACK[0]();
}
/********************************************************************************************************************/
void __vector_2 (void)
{
	EXTI_CALLBACK[1]();
}
/********************************************************************************************************************/
void __vector_3 (void)
{
	EXTI_CALLBACK[2]();
}
/********************************************************************************************************************/
void      EXTI_voidInit              (void)
{
	MCUCR_REG  = 0;
	MCUCSR_REG = 0;
	
	#if EXTI_LINE == EXTI_LINE0
	    DIO_voidSetPinDirection(PORTD , PIN2 , INPUT);
		MCUCR_REG = EXTI_SENSE_MODE;
		
	#elif EXTI_LINE == EXTI_LINE1
	    DIO_voidSetPinDirection(PORTD , PIN3 , INPUT);
		MCUCR_REG = EXTI_SENSE_MODE << 2;

	#elif EXTI_LINE == EXTI_LINE2
	    DIO_voidSetPinDirection(PORTB , PIN2 , INPUT);
		MCUCSR_REG = (EXTI_SENSE_MODE - 2) << 6;

	#endif	
}
/********************************************************************************************************************/
void      EXTI_voidSetSignalLatch    (u8 copy_u8Line , u8 copy_u8Mode)
{
	if      (copy_u8Line == EXTI_LINE0)
	{
		DIO_voidSetPinDirection(PORTD , PIN2 , INPUT);
		MCUCR_REG = copy_u8Mode;
	}
	else if (copy_u8Line == EXTI_LINE1)
	{
		DIO_voidSetPinDirection(PORTD , PIN3 , INPUT);
		MCUCR_REG = copy_u8Mode << 2;
	}
	if (copy_u8Line == EXTI_LINE2)
	{
		DIO_voidSetPinDirection(PORTB , PIN2 , INPUT);
		MCUCSR_REG = (copy_u8Mode - 2) << 6;
	}	
}
/********************************************************************************************************************/
void      EXTI_voidEnable            (s8 copy_u8Line)
{
	if (copy_u8Line == EXTI_LINE2)
	{
		copy_u8Line -= 3;
	}
	SET_BIT(GICR_REG ,(copy_u8Line + 6));
}
/********************************************************************************************************************/
void      EXTI_voidDisable           (s8 copy_u8Line)
{
	if (copy_u8Line == EXTI_LINE2)
	{
		copy_u8Line -= 3;
	}
	CLR_BIT(GICR_REG ,(copy_u8Line + 6));	
}
/********************************************************************************************************************/
void      EXTI_voidClearFlag         (s8 copy_u8Line)
{
	if (copy_u8Line == EXTI_LINE2)
	{
		copy_u8Line -= 3;
	}
	SET_BIT(GIFR_REG ,(copy_u8Line + 6));	
}