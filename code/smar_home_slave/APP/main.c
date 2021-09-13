/*
 * Smart_Home_Slave.c
 *
 * Created: 9/4/2021 2:49:24 AM
 * Author : Ali
 */
#define  F_CPU    16000000UL 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "GIE_interface.h"
#include "GIE_private.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "LCD_interface.h"
#include "LED_interface.h"
#include <util/delay.h>

int main(void)
{
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);                  // output led
	SPI_SlaveInit();                                             // initilization SPI

	u8 Data; 
	                                                 // defination data = 0
	while(1)
	{
		
		Data = SPI_u8SlaveTransmitRecive('1');                  // transimmit the data through SPI in variable data
		if(Data == '1')
		{
			
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);
			
			//LCD_voidWriteString("Controlling Room 1");
		}                                                        // check the data if data == 1 --> led on
		else if(Data == '0')
		{
			DIO_voidSetPinValue(PORTC,PIN2,LOW);                  // if data == 0 --> led off
		}
	}
	return 0;
}




