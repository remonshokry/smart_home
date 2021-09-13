#ifndef               TIM1_PRIVATE_H
#define               TIM1_PRIVATE_H
/*********************************************************/
#define           TCCR1A          *((volatile u8* )0x4F)
#define           TCCR1B          *((volatile u8* )0x4E)
#define           TCNT1           *((volatile u16*)0x4C)
#define           OCR1A           *((volatile u16*)0x4A)
#define           ICR1            *((volatile u16*)0x46)
#define           TIMSK           *((volatile u8* )0x59)
#define           TIFR            *((volatile u8* )0x58)
#define           OCR1B           *((volatile u16*)0x48)
/*********************************************************/
void           __vector_6(void) __attribute__((signal));
void           __vector_9(void) __attribute__((signal));
/*********************************************************/
#endif