#include "main.h"
#include "cmsis_os.h"

void BusinessLogic(void)
{
	/* Infinite loop */
	for(;;)  {
	  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	  osDelay(500);
	}
}
