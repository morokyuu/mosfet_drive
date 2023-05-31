#include <stdio.h>
#include <pico/stdlib.h>
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint LED_PIN = 25;

int main(void){
    bi_decl(bi_program_description("This is a mosfet drive test"));
    
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(0);
    gpio_init(1);
    gpio_init(2);
    gpio_init(3);
    gpio_set_dir(0, GPIO_OUT);
    gpio_set_dir(1, GPIO_OUT);
    gpio_set_dir(2, GPIO_OUT);
    gpio_set_dir(3, GPIO_OUT);

    while(1){
        gpio_put(LED_PIN, 1);
        gpio_put(1, 1);
        //gpio_put_all(0x0000000F);
        sleep_ms(200);
        gpio_put(LED_PIN, 0);
        gpio_put(1, 0);
        //gpio_put_all(0x00000000);
        sleep_ms(200);
    }
}

