#include "actions.h"   
#include "cycfg_pins.h"
#include <lvgl.h>

void action_button1_pressed(lv_event_t * e)
{
	(void)e;
   	Cy_GPIO_Inv(CYBSP_USER_LED1_PORT,CYBSP_USER_LED1_NUM);
	
}
