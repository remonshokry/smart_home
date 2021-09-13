#include      "STD_TYPES.h"
#include      "BIT_MATH.h"
#include      "DIO_interface.h"
#include      "SPI_private.h"
#include      "SPI_interface.h"
/**************************************************************/
void         SPI_MasterInit                (void)
{
	DIO_voidSetPinDirection  (PORTB , PIN5 , OUTPUT);
	DIO_voidSetPinDirection  (PORTB , PIN6 , INPUT );
	DIO_voidSetPinDirection  (PORTB , PIN7 , OUTPUT);
	DIO_voidSetPinDirection  (PORTB , PIN4 , OUTPUT);
	SPCR_REG = 0b01110001;
	SPSR_REG = 0b00000000;
	SPDR_REG = 0b00000001;
}
/**************************************************************/
void         SPI_SlaveInit                 (void)
{
	DIO_voidSetPinDirection  (PORTB , PIN5 , INPUT);
	DIO_voidSetPinDirection  (PORTB , PIN6 ,OUTPUT);
	DIO_voidSetPinDirection  (PORTB , PIN7 , INPUT);
	DIO_voidSetPinDirection  (PORTB , PIN4 , INPUT);
	SPCR_REG = 0b01100000;
}
/**************************************************************/
u8           SPI_u8MasterTransmitRecive    (u8 Data)
{
	DIO_voidSetPinValue      (PORTB , PIN4 , 0);
	SPDR_REG = Data;
	while (GET_BIT (SPSR_REG , 7) == 0);
	return SPDR_REG;
	DIO_voidSetPinValue      (PORTB , PIN4 , 1);

}
/**************************************************************/
u8           SPI_u8SlaveTransmitRecive     (u8 Data)
{
	SPDR_REG = Data;
	while (GET_BIT (SPSR_REG , 7) == 0);
	return SPDR_REG;
}