// input.h
#pragma once
#include "driver/gpio.h"
#include <driver/adc.h>

void button_init_init(void);


void button_init_interrupt(uint8_t pin);
static void IRAM_ATTR button_isr(void* arg);
bool button_was_pressed(uint8_t pin);

int read_button(uint8_t id);

int read_pot(uint8_t adc_pin);