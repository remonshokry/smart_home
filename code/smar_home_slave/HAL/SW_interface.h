#ifndef           SW_INTERFACE_H
#define           SW_INTERFACE_H
/******************************************************/
#define       SW_PULL_UP          1
#define       SW_PULL_DOWN        0
/******************************************************/
typedef struct{

	u8 SW_PORT       ;
	u8 SW_PIN        ;
	u8 SW_PULL_STATE ;

}SW_Type;
/******************************************************/
u8 SW_u8GetPressed( SW_Type SW_Cfg );
/******************************************************/
#endif