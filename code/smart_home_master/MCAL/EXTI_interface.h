#ifndef       EXTI_INTERFACE_H
#define       EXTI_INTERFACE_H
/***********************************************************************/
#define       EXTI_DISABLE                       0
#define       EXTI_ENABLE                        1
/***********************************************************************/
#define       EXTI_FALLING_EDGE                  2
#define       EXTI_RISING_EDGE                   3
#define       EXTI_ON_CHANGE                     1
#define       EXTI_LOW_LEVEL                     0
/***********************************************************************/
#define       EXTI_LINE0                         0    //6
#define       EXTI_LINE1                         0    //7  
#define       EXTI_LINE2                         0    //5
/***********************************************************************/
void      EXTI_voidInit              (void);
void      EXTI_voidSetSignalLatch    (u8 copy_u8Line , u8 copy_u8Mode);
void      EXTI_voidEnable            (s8 copy_u8Line);
void      EXTI_voidDisable           (s8 copy_u8Line);
void      EXTI_voidClearFlag         (s8 copy_u8Line);
void      EXTI_voidSetCallBack       (void(*ptr)(void) , u8 copy_u8Line);
/***********************************************************************/   
#endif