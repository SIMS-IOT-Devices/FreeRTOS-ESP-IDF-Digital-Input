// Recive digital input on pin 15 and GND fron another ESP32

#include <stdio.h>
#include "esp_event.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

#define pin15 15

void app_main(void)
{
    gpio_pad_select_gpio(pin15);                    // Defines GPIO functionality for the pin
    gpio_set_direction(pin15, GPIO_MODE_DEF_INPUT); // Pin input/output definition

    int level = 0;

    printf("\nInput results:\n");
    while (true)
    {
        printf("\nTwo seconds:\n");
        for (size_t i = 0; i < 20; i++)
        {    
            level = gpio_get_level(pin15);          // Read voltage level 0/1
            printf("Timer: %lld miliseconds Level = %d\n", esp_timer_get_time()/1000, level);
            vTaskDelay(100 / portTICK_PERIOD_MS);
        }
        printf("\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
