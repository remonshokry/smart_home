#ifndef          TIM0_CONFIG_H
#define          TIM0_CONFIG_H
/*************************************************************************/
/*    Options:-
        	 1- TIM0_OVF_MODE
 	         2- TIM0_CTC_MODE
 	         3- TIM0_FAST_PWM_MODE
 	         4- TIM0_PHASE_CORRECT_MODE 
*/			 
/*************************************************************************/
#define       TIM0_MODE                 TIM0_FAST_PWM_MODE

#define       TIM0_OCO_STATUS           TIM0_OC0_CLEAR

#define       TIM0_PRESCALLER           TIM0_PRE_256

#define       TIM0_INT_STATUS           TIM0_INT_DISABLE
/*************************************************************************/
#endif