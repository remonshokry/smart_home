/*
 * Smart_Home_Master.c
 *
 * Created: 9/4/2021 2:05:05 AM
 * Author : Ali
 */ 

#define   F_CPU       16000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.H"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "LED_interface.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "SPI_interface.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"
#include "SSD_interface.h"
#include "SSD_config.h"
#include <util/delay.h>
int main(void)
{
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT); // set led on portc in pin2 and output
	DIO_voidSetPinDirection(PORTD,PIN1,OUTPUT); // set UART on portd in pin1 and output
	DIO_voidSetPinDirection(PORTD,PIN0,INPUT);  // set UART on portd in pin0 and input
    DIO_voidSetPinDirection(PORTA,PIN3,OUTPUT);
	UART_VoidInit();                            // iniallization UART
	SPI_MasterInit();                           // iniallization SPI master
	SSD_voidInit();                           
	u8 flag = 0;                                // decleration variable ( flag )
	while(1)
	{
		_delay_ms(1000); // delay before to prevent data collision

		flag = UART_VoidRecieve();              // put data recieved from bluetooth in flag
		SPI_u8MasterTransmitRecive(flag);       // transimmit flag to other micro through SPI
		if(flag == '1')
		 {
			 DIO_voidSetPinValue(PORTC,PIN2,HIGH);
			 DIO_voidSetPinValue(PORTA,PIN3,HIGH);
			 _delay_ms(500);
			 DIO_voidSetPinValue(PORTA,PIN3,LOW);
			 SSD_voidEnableA();
             SSD_voidSendNumber(1);
		}                                       // check if flag == 1 --> led on
		else if (flag == '0')
		{
			DIO_voidSetPinValue(PORTC,PIN2,LOW); // chech if flag == 0 --> led off
			DIO_voidSetPinValue(PORTA,PIN3,HIGH);
			 _delay_ms(500);
			 DIO_voidSetPinValue(PORTA,PIN3,LOW);
			SSD_voidDisbaleA();
			SSD_voidEnableB();
	        SSD_voidSendNumber(0);
			_delay_ms(1000);
			SSD_voidDisbaleB();
		}
	}
	return 0;
}

