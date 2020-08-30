

#ifndef __APP_CONFIG_H__
#define __APP_CONFIG_H__

#define APP_LED_TOGGLE_EN                1 // simple task that toggle a led
#define APP_LVGL_BUTTON_EN               0 // simple app taht use LVGL library
#define APP_TEST_FLASH_EN                0 // enable test flash code


#if (APP_TEST_FLASH_EN+APP_LED_TOGGLE_EN+APP_LVGL_BUTTON_EN) != 1
# error "Only one enable from APP_xxxxx_EN "
#endif


void BusinessLogic(void);
void AppTestFlash(void);
void HmiLvglExample(void);

#endif

