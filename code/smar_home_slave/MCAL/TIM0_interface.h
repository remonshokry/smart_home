#ifndef          TIM0_INTERFACE_H
#define          TIM0_INTERFACE_H
/*************************************************************************/
#define       TIM0_OVF_MODE                  0
#define       TIM0_CTC_MODE                  1	
#define       TIM0_FAST_PWM_MODE             2	
#define       TIM0_PHASE_CORRECT_MODE        3			 
/*************************************************************************/
#define       TIM0_OCO_DISCONNECT            0
#define       TIM0_OCO_TOGGLE                1	
#define       TIM0_OCO_CLEAR                 2	
#define       TIM0_OCO_SET                   3	
/*************************************************************************/
#define       TIM0_PRE_1                     1
#define       TIM0_PRE_8                     2	
#define       TIM0_PRE_64                    3	
#define       TIM0_PRE_256                   4	
#define       TIM0_PRE_1024                  5
/*************************************************************************/
#define       TIM0_INT_OVF                   0
#define       TIM0_INT_CTC                   1
#define       TIM0_INT_DISABLE               2
/*************************************************************************/
#define       TIM0_OVF_FLAG                  0
#define       TIM0_CTC_FLAG                  1
/*************************************************************************/
#define       TIM0_OVF                       0
#define       TIM0_CTC                       1
/*************************************************************************/
void          TIM0_voidInit         (void);
void          TIM0_voidTovfPreload  ( u8 Copy_u8Value );
void          TIM0_voidTctcfPreload ( u8 Copy_u8Value );
u8            TIM0_u8GetFlag        ( u8 Copy_u8Flag );
void          TIM0_voidSetCallBack  (void(*ptr)(void));
/*************************************************************************/
#endif