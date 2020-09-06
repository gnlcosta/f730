# STM32H730R8 Demo
 * **uC**: STM32H730R8 
 * **SPI Flash**: Winbond W25Q32
 * **OS**: FreeRTOS
 * **Task**: running in the external flash (Dual-SPI)
 * **LCD ILI9431 240x320**: optional
 
# App/Firmware examples
There are two examples that you can select in compilation time:
 * simple led blinking
 * simple LCD example using (the wonderful) [LVGL library](https://lvgl.io/)
 
Both run in the external flash.

## Steps:  
  * open the file [app_config.h](https://github.com/gnlcosta/f730/blob/master/Core/Inc/app_config.h) and select which application to compile
  * if you enable *APP_LED_TOGGLE_EN* then you can stop here, otherwise
  * connect the dispaly to the board LCD ILI9341 240x320. The map is:

  |     uC   |   Display   |
  |:-------- | -----------:|
  |    PA4   |      CS     |
  |    PA5   |      SCK    |
  |    PA6   |     MISO    |
  |    PA7   |     MOSI    |
  |    PC4   |     DC      |
  |    PB0   |     RESET   |
  |    PB1   |     LED/BL  |

 * compile and download the firmware

## Result
<img src="https://github.com/gnlcosta/f730/raw/master/doc/lcd_screen.jpg" alt="Board" width="200">

# External Loader
For STM32CubeProgrammer the external loader can be download [here](https://github.com/gnlcosta/f730_w25q32fv/blob/master/F730_W25Q32FV.stldr)

# SDK
 * STM32CubeIDE 1.4.2
 * STM32CubeMX 6.0.1
 
# Boards
Aliexpress: https://a.aliexpress.com/_BOJKBW  
![Board](https://github.com/gnlcosta/f730/raw/master/doc/board.jpg)

LCD: ILI9341 240x320


# License
MIT License  
Copyright (c) 2020 Gianluca Costa
