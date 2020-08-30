#include "main.h"
#include "cmsis_os.h"

#include "app_config.h"

#if APP_LED_TOGGLE_EN

void BusinessLogic(void)
{
	/* Infinite loop */
	for(;;)  {
	  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	  osDelay(500);
	}
}

#endif
