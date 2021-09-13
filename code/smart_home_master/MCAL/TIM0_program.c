#include     "STD_TYPES.h"
#include     "BIT_MATH.h"
#include     "TIM0_private.h"
#include     "TIM0_config.h"
#include     "TIM0_interface.h"
/*************************************************************************/
void          TIM0_voidInit         (void)
{
	CLR_BIT( TCCR0_REG , 7 );

	#if       TIM0_MODE == TIM0_OVF_MODE

			CLR_BIT( TCCR0_REG , 6 );
			CLR_BIT( TCCR0_REG , 3 );

	#elif     TIM0_MODE == TIM0_CTC_MODE

			CLR_BIT( TCCR0_REG , 6 );
			SET_BIT( TCCR0_REG , 3 );

	#elif     TIM0_MODE == TIM0_FAST_PWM_MODE

			SET_BIT( TCCR0_REG , 6 );
			SET_BIT( TCCR0_REG , 3 );

	#elif      TIM0_MODE ==  TIM0_PHASE_CORRECT_MODE

			SET_BIT( TCCR0_REG , 6 );
			CLR_BIT( TCCR0_REG , 3 );

	#endif

	#if     TIM0_OCO_STATUS == TIM0_OC0_DISCONNECRED

				CLR_BIT( TCCR0_REG , 4 );
				CLR_BIT( TCCR0_REG , 5 );

	#elif   TIM0_OCO_STATUS == TIM0_OC0_TOGGLE

				SET_BIT( TCCR0_REG , 4 );
				CLR_BIT( TCCR0_REG , 5 );

	#elif   TIM0_OCO_STATUS == TIM0_OC0_CLEAR


				CLR_BIT( TCCR0_REG , 4 );
				SET_BIT( TCCR0_REG , 5 );

	#elif   TIM0_OCO_STATUS == TIM0_OC0_SET

				SET_BIT( TCCR0_REG , 4 );
				SET_BIT( TCCR0_REG , 5 );

	#endif


	#if    TIM0_INT_STATUS == TIM0_INT_OVF

					SET_BIT( TIMSK0_REG , 0 );

	#elif  TIM0_INT_STATUS == TIM0_INT_CTC

					SET_BIT( TIMSK0_REG , 1 );

	#elif  TIM0_INT_STATUS == TIM0_INT_DISABLE

					CLR_BIT( TIMSK0_REG , 0 );
					CLR_BIT( TIMSK0_REG , 1 );

	#endif

	TCCR0_REG |= TIM0_PRESCALLER ;	
}
/*************************************************************************/
void          TIM0_voidTovfPreload  ( u8 Copy_u8Value )
{
	TCNT0_REG = Copy_u8Value ;	
}
/*************************************************************************/
void          TIM0_voidTctcfPreload ( u8 Copy_u8Value )
{
	OCR0_REG = Copy_u8Value ;	
}
/*************************************************************************/
u8            TIM0_u8GetFlag        ( u8 Copy_u8Flag )
{
	return GET_BIT( TIFR0_REG , Copy_u8Flag );	
}
/*************************************************************************/
void (*TIM0_CALLBACK[2])(void);
/*************************************************************************/
void TIM0_CTC_voidSetCallBack( void(*ptr)(void))
{
	TIM0_CALLBACK[TIM0_CTC] = ptr;
}
/*************************************************************************/
void __vector_10(void)
{
	TIM0_CALLBACK[TIM0_CTC]();
}
/*************************************************************************/
void TIM0_OV_voidSetCallBack( void(*ptr)(void))
{
	TIM0_CALLBACK[TIM0_OVF] = ptr;
}
/*************************************************************************/
void __vector_11(void)
{
	TIM0_CALLBACK[TIM0_OVF]();
}