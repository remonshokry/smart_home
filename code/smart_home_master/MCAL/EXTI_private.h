#ifndef        EXTI_PRIVATE_H
#define        EXTI_PRIVATE_H
/***************************************************/
#define      MCUCR_REG      *((volatile u8 *)0x55)
#define      MCUCSR_REG     *((volatile u8 *)0x54)
#define      GICR_REG       *((volatile u8 *)0x5B)
#define      GIFR_REG       *((volatile u8 *)0x5A)
/***************************************************/
void   __vector_1(void) __attribute__((signal));
/***************************************************/
#endif