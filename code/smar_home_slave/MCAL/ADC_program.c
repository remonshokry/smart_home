#include  "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "ADC_config.h"
#include  "ADC_private.h"
#include  "ADC_interface.h"

void       ADC_voidInit(void)
{
	ADMUX_Reg  = 0b01000000;
	ADCSRA_Reg = 0b10010111;
}
void       ADC_voidSetType(u8 copy_u8type)
{
	ADMUX_Reg |= copy_u8type;
}
u16        ADC_u16GetResult(void)
{
	u16 Result = 0;
    #if ADCD == right
	     SET_BIT(ADCSRA_Reg,6);
	     while (GET_BIT(ADCSRA_Reg,4) == 0);
	     SET_BIT(ADCSRA_Reg,4);
	     Result = (ADCL_Reg | (ADCH_Reg << 8));
		 
    #elif ADCD == left
		 SET_BIT(ADMUX_Reg,5);
	     SET_BIT(ADCSRA_Reg,6);
	     while (GET_BIT(ADCSRA_REG,4) == 0);
	     SET_BIT(ADCSRA_REG,4);
	     Result = (ADCH_Reg << 2);
         
    #endif
         return Result;	
}
void       ADC_voidSetAutoTrigger(u8 copy_u8type)
{
	SET_BIT(ADCSRA_Reg,5);
	SFIOR_Reg |= copy_u8type;
}
