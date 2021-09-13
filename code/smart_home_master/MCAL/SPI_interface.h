#ifndef          SPI_INTERFACE_H
#define          SPI_INTERFACE_H
/******************************************************/
void         SPI_MasterInit                (void);
void         SPI_SlaveInit                 (void);
u8           SPI_u8MasterTransmitRecive    (u8 Data);
u8           SPI_u8SlaveTransmitRecive     (u8 Data);
/******************************************************/
#endif