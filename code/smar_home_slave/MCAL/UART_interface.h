#ifndef             UART_INTERFACE_H
#define             UART_INTERFACE_H
/************************************************************/
#define      PARITY_ON                     1
#define      PARITY_OFF                    0
/************************************************************/
#define      MPCM_ON                       1
#define      MPCM_OFF                      0
/*********************Frame Size*****************************/
#define      FIVE_BITS                     0
#define      SIX_BITS                      1
#define      SEVEN_BITS                    2
#define      EIGHT_BITS                    3
/*********************Stop Bit*******************************/
#define      ONE_BIT                       1
#define      TWO_BITS                      2
/************************************************************/
#define      RISING                        0
#define      FALLING                       1
/************************************************************/
#define      Asynchronous                  1
#define      synchronous                   0
/************************************************************/
#define      DISABLE                       0
#define      EVEN                          1
#define      ODD                           2
/************************************************************/
#define      DOUBLE_SPEED_MODE_ON          1
#define      DOUBLE_SPEED_MODE_OFF         0
/************************************************************/
void         UART_VoidInit          (void);
void         UART_VoidTransmit      (u8 Data);
u8           UART_VoidRecieve       (void);
void         UART_voidWriteString   (u8 *ptr);
u8           * UART_voidReadString  (void);
/************************************************************/
#endif