
#include "main.h"
#include "cmsis_os.h"
#include "dqspi.h"

#include "app_config.h"


#define DSPI_MEM_MAP_ADDR           0x90000000
#define DT_OFFSET                   111


static int8_t FlashTest(void)
{
	uint32_t i, j, bsize, start_addr;
	uint32_t dat[3] = {0};
	uint32_t *memmap;
	uint8_t mid;
	uint16_t id;

	DQSpiReset();
	DQSpiFlashId(&mid, &id);
	DQSpiFlashInfo(NULL, &bsize, NULL, NULL);
	if (id == FLASH_ID && mid == FLASH_MF_ID) {
		DQSpiEraseBlock(0); // block 0
		DQSpiEraseBlock(bsize); // bloxk 1
		start_addr = bsize/2;
		start_addr = start_addr - (start_addr%sizeof(uint32_t));
		for (i=0; i!=bsize/sizeof(dat); i++) {
			for (j=0; j!=sizeof(dat)/sizeof(uint32_t); j++) {
				dat[j] = i*(sizeof(dat)/sizeof(uint32_t))+j+DT_OFFSET;
			}
			if (DQSpiWrite(start_addr+i*sizeof(dat), (uint8_t *)dat, sizeof(dat)) != 0) {
				return -1;
			}
		}
		j = dat[sizeof(dat)/sizeof(uint32_t)-1]-DT_OFFSET;
		DQSpiReset();
		DQSpiMemoryMapped();

		memmap = (uint32_t *)(DSPI_MEM_MAP_ADDR+start_addr);
		for (i=0; i!=j; i++) {
			if (memmap[i] != i+DT_OFFSET) {
				while (1) {
					HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
					osDelay(50);
				}
				return -2;
			}
		}
	}

	return 0;
}


void AppTestFlash(void)
{
	if (FlashTest() != 0) {
		while (1) {
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			osDelay(100);
		}
	}

	/* Infinite loop */
	for(;;)  {
	  HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	  osDelay(500);
	}
}
