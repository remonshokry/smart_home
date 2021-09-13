#include        "STD_TYPES.h"
#include        "BIT_MATH.h"
#include        "UART_private.h"
#include        "UART_config.h"
#include        "UART_interface.h"
/************************************************************/
void         UART_VoidInit          (void)
{
	u8 ucsra =0b00000000;
	u8 ucsrb =0b00011000;
	u8 ucsrc =0b10000110;
/*            UCSRA                   */
     #if PARITY_STATE == PARITY_OFF
	     CLR_BIT(ucsra,2);
     #elif PARITY_STATE == PARITY_ON
	     SET_BIT(ucsra,2);
     #endif

     #if PARITY_MODE == DISABLE
	     CLR_BIT(ucsrc,4);
	     CLR_BIT(ucsrc,5);
     #elif PARITY_MODE == EVEN
	     CLR_BIT(ucsrc,4);
	     SET_BIT(ucsrc,5);
     #elif PARITY_MODE == ODD
	     SET_BIT(ucsrc,4);
	     SET_BIT(ucsrc,5);
    #endif

    #if DOUBLE_SPEED_MODE == DOUBLE_SPEED_MODE_OFF
	     CLR_BIT(ucsra,1);
    #elif DOUBLE_SPEED_MODE == DOUBLE_SPEED_MODE_ON
	     SET_BIT(ucsra,1);
    #endif

/*            FRAM SIZE                   */
     #if FRAM_SIZE == FIVE_BITS
	     CLR_BIT(ucsrb,2);
	     CLR_BIT(ucsrc,1);
	     CLR_BIT(ucsrc,2);
     #elif FRAM_SIZE == SIX_BITS
	     CLR_BIT(ucsrb,2);
	     SET_BIT(ucsrc,1);
	     CLR_BIT(ucsrc,2);
     #elif FRAM_SIZE == SEVEN_BITS
	     CLR_BIT(ucsrb,2);
	     CLR_BIT(ucsrc,1);
	     SET_BIT(ucsrc,2);
     #elif FRAM_SIZE == EIGHT_BITS
	     CLR_BIT(ucsrb,2);
	     SET_BIT(ucsrc,1);
	     SET_BIT(ucsrc,2);
     #endif

/*            UART MODE                   */
     #if UART_MODE == Asynchronous
	     CLR_BIT(ucsrc,6);
     #elif UART_MODE == synchronous
	     SET_BIT(ucsrc,6);
     #endif

     #if STOP_BITS == ONE_BIT
	     CLR_BIT(ucsrc,3);
     #elif STOP_BITS == TWO_BITS
	     SET_BIT(ucsrc,3);
     #endif

     #if TRANSMIT_AT == RISING
	     CLR_BIT(ucsrc,0);
     #elif TRANSMIT_AT == FALLING
	     SET_BIT(ucsrc,0);
     #endif
	 
	 UCSRA=ucsra;
	 UCSRB=ucsrb;
	 UCSRC=ucsrc;
	 UBRRL=103;
	 UBRRH=0;	
}
/************************************************************/
void         UART_VoidTransmit      (u8 Data)
{
	while(GET_BIT(UCSRA,5)==0);
	UDR=Data;	
}
/************************************************************/
u8           UART_VoidRecieve       (void)
{ 
	while(GET_BIT(UCSRA,7)==0);

	return UDR;	
}
/************************************************************/
void         UART_voidWriteString   (u8 *ptr)
{
	u8 i = 0 ;

	while( ptr[ i ] != '\0' )
	{
		UART_VoidTransmit(ptr[i] );
		i++;
	}	
}
/************************************************************/
u8 String[20];
u8           * UART_voidReadString  (void)
{
	u8 i=0;u8 x=0;

	while((x=UART_VoidRecieve()) != 'E')
	{
		String[i]=x;
		i++;
	}
	String[i]='\0';
	return String;	
}