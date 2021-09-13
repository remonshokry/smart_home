#ifndef       LED_INTERFACE_H
#define       LED_INTERFACE_H
/*************************************************************/
#define       LED_ACTIVE_HIGH             1
#define       LED_ACTIVE_LOW              0
/*************************************************************/
typedef struct{
	u8 LED_PORT         ;
	u8 LED_PIN          ;
	u8 LED_ACTIVE_STATE ;
}LED_Type;
/*************************************************************/
void      LED_voidOn      ( LED_Type LED_Cfg  );
void      LED_voidOff     ( LED_Type LED_Cfg  );
void      LED_voidToggle  ( LED_Type LED_Cfg  );
/*************************************************************/
#endif