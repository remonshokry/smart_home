#ifndef       ADC_INTERFACE_H
#define       ADC_INTERFACE_H

/******************************************************************/
#define    left      0
#define    right     1
/******************************************************************/
#define    Free_Running                        0b00000000
#define    Analog_Comparator                   0b00100000
#define    External_Interrupt                  0b01000000
/******************************************************************/
#define    Single_ADC0                         0b00000000
#define    Single_ADC1                         0b00000001
#define    Single_ADC2                         0b00000010
#define    Single_ADC3                         0b00000011
#define    Single_ADC4                         0b00000100
#define    Single_ADC5                         0b00000101
#define    Single_ADC6                         0b00000110
#define    Single_ADC7                         0b00000111
/******************************************************************/
#define    Differential_ADC0_ADC0_GAIN10       0b00001000
#define    Differential_ADC1_ADC0_GAIN10       0b00001001
#define    Differential_ADC0_ADC0_GAIN200      0b00001010
#define    Differential_ADC1_ADC0_GAIN200      0b00001011
#define    Differential_ADC2_ADC2_GAIN10       0b00001100
#define    Differential_ADC3_ADC2_GAIN10       0b00001101
#define    Differential_ADC2_ADC2_GAIN200      0b00001110
#define    Differential_ADC3_ADC2_GAIN200      0b00001111
/******************************************************************/
#define    Differential_ADC0_ADC1_GAIN1        0b00010000
#define    Differential_ADC1_ADC1_GAIN1        0b00010001
#define    Differential_ADC2_ADC1_GAIN1        0b00010010
#define    Differential_ADC3_ADC1_GAIN1        0b00010011
#define    Differential_ADC4_ADC1_GAIN1        0b00010100
#define    Differential_ADC5_ADC1_GAIN1        0b00010101
#define    Differential_ADC6_ADC1_GAIN1        0b00010110
#define    Differential_ADC7_ADC1_GAIN1        0b00010111
/******************************************************************/
#define    Differential_ADC0_ADC2_GAIN1        0b00011000
#define    Differential_ADC1_ADC2_GAIN1        0b00011001
#define    Differential_ADC2_ADC2_GAIN1        0b00011010
#define    Differential_ADC3_ADC2_GAIN1        0b00011011
#define    Differential_ADC4_ADC2_GAIN1        0b00011100
#define    Differential_ADC5_ADC2_GAIN1        0b00011101
/******************************************************************/
void       ADC_voidInit(void);
u16        ADC_u16GetResult(void);
void       ADC_voidSetType(u8 copy_u8type);
void       ADC_voidSetAutoTrigger(u8 copy_u8type);
/******************************************************************/
#endif