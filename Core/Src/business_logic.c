#include "main.h"
#include "cmsis_os.h"

#include "repeat_macro.h"

#include "app_config.h"


#if APP_LED_TOGGLE_EN


void BusinessLogic(void)
{
	volatile uint32_t a = 1;
	volatile uint32_t i = 0;

	/* Infinite loop */
	for(;;)  {
		// this code tests the performance (good pcb routing) of the Dual/Quad-SPI flash. If the led stop to blink the SPI clock must be reduced (it is likely that depend by a bad PCB routing)
		REP(0, 5, 0, 0, i++;a*=i;);
		REP(0, 5, 0, 0, i++;a*=2*i;);
		REP(0, 5, 0, 0, i++;a*=3*i;);
		REP(0, 5, 0, 0, i++;a*=4*i;);
		REP(0, 5, 0, 0, i++;a*=5*i;);
		REP(0, 5, 0, 0, i++;a*=6*i;);
		REP(1, 5, 0, 0, i++;a*=7*i;);

		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		osDelay(25);
	}
}

#endif
