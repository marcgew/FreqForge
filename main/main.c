#include <stdio.h>
#include "driver/gpio.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "input.h"




void app_main(void)
{  
    button_init_interrupt(25);
   
    while(1)
    {
          if (button_was_pressed(25)) {
            printf("Button pressed!\n");
        }
        vTaskDelay(300 / portTICK_PERIOD_MS);
        
        
        //TODO ISR Für knöpfe, Potis und Encoder 
    }
    

}