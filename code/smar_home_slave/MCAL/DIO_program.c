#include    "STD_TYPES.h"
#include    "BIT_MATH.h"
#include    "DIO_interface.h"
#include    "DIO_config.h"


//DIO_voidSetPinDirection(PORT(x), PIN(y), OOUTPUT)
void      DIO_voidSetPinDirection  (u8 PortID, u8 PinID, u8 Direction)
{
	   /*           Range Check           */
    if(PortID<4 && PinID<8)
    {
		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
				case   PORTA   :  SET_BIT(DDRA_REG,PinID);    break;
				case   PORTB   :  SET_BIT(DDRB_REG,PinID);    break;
				case   PORTC   :  SET_BIT(DDRC_REG,PinID);    break;
				case   PORTD   :  SET_BIT(DDRD_REG,PinID);    break;
			}
		}
        else if(Direction == INPUT)
		{
			switch(PortID)
			{
				case   PORTA   :  CLR_BIT(DDRA_REG,PinID);    break;
				case   PORTB   :  CLR_BIT(DDRB_REG,PinID);    break;
				case   PORTC   :  CLR_BIT(DDRC_REG,PinID);    break;
				case   PORTD   :  CLR_BIT(DDRD_REG,PinID);    break;
			}
		}
		else
		{
			/*         DO NOTHING         */
		}			
	}
    else
	{
		/*         DO NOTHING         */
	}			
			
}
void      DIO_voidSetPinValue      (u8 PortID, u8 PinID, u8 Value)
{          
             /*           Range Check           */
    if(PortID<4 && PinID<8)
    {
		if(Value == HIGH)
		{
			switch(PortID)
			{
				case   PORTA   :  SET_BIT(PORTA_REG,PinID);    break;
				case   PORTB   :  SET_BIT(PORTB_REG,PinID);    break;
				case   PORTC   :  SET_BIT(PORTC_REG,PinID);    break;
				case   PORTD   :  SET_BIT(PORTD_REG,PinID);    break;
			}
		}
        else if(Value == LOW)
		{
			switch(PortID)
			{
				case   PORTA   :  CLR_BIT(PORTA_REG,PinID);    break;
				case   PORTB   :  CLR_BIT(PORTB_REG,PinID);    break;
				case   PORTC   :  CLR_BIT(PORTC_REG,PinID);    break;
				case   PORTD   :  CLR_BIT(PORTD_REG,PinID);    break;
			}
		}
		else
		{
			/*         DO NOTHING         */
		}			
	}
    else
	{
		/*         DO NOTHING         */
	}	
	
}
u8        DIO_u8GetPinValue    (u8 PortID, u8 PinID)
{
	u8   Local_u8Data = 0xFF;
	/*		Range Check						*/
	if(PortID<4 && PinID<8)
	{
			switch(PortID)
			{
				case	PORTA	:	Local_u8Data	=	GET_BIT(PINA_REG,PinID);	break;
				case	PORTB	:	Local_u8Data	=	GET_BIT(PINB_REG,PinID);	break;
				case	PORTC	:	Local_u8Data	=	GET_BIT(PINC_REG,PinID);	break;
				case	PORTD	:	Local_u8Data	=	GET_BIT(PIND_REG,PinID);	break;
			}
	}
	else
	{
		/*		Do Nothing					*/
	}	
	return  Local_u8Data;	
}
/********************************************************************************************************/
//DIO_voidSetPortDirection(PORT(x), OUTPUT)
void      DIO_voidSetPortDirection (u8 PortID , u8 Direction)
{
	   /*       Range Check       */
    if(PortID<4)
	{
	    switch( PortID)
	    {
	      case PORTA: DDRA_REG = Direction ; break;
	      case PORTB: DDRB_REG = Direction ; break;
	      case PORTC: DDRC_REG = Direction ; break;
	      case PORTD: DDRD_REG = Direction ; break;
	    }
	}
	else
	{
		/*         DO NOTHING         */
	}	

}
void      DIO_voidSetPortValue     (u8 PortID , u8 Value)
{
	   /*       Range Check       */
    if(PortID<4)
	{
	    switch( PortID)
	    {
	      case PORTA: PORTA_REG = Value ; break;
	      case PORTB: PORTB_REG = Value ; break;
	      case PORTC: PORTC_REG = Value ; break;
	      case PORTD: PORTD_REG = Value ; break;
	    }
	}
	else
	{
		/*         DO NOTHING         */
	}	

}
u8        DIO_u8GetPortValue   (u8 PortID)
{
	u8   Local_u8Data = 0xFF;
	/*		Range Check						*/
	if(PortID<4)
	{
			switch(PortID)
			{
				case	PORTA	:	Local_u8Data	=	PINA_REG;	break;
				case	PORTB	:	Local_u8Data	=	PINB_REG;	break;
				case	PORTC	:	Local_u8Data	=	PINC_REG;	break;
				case	PORTD	:	Local_u8Data	=	PIND_REG;	break;
			}
	}
	else
	{
		/*		Do Nothing					*/
	}	
	return  Local_u8Data;	
}