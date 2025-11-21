#include "input.h"


#define BUTTON1_PIN 33
#define POT1_PIN   ADC1_CHANNEL_6


/**
 * @brief Initializes a GPIO pin as a button input.
 *
 * Configures the specified GPIO pin as an input with an internal
 * pull-up resistor enabled. No interrupts are attached; the pin
 * must be polled manually using read_button().
 *
 * @param button_id  GPIO pin number to configure (e.g., GPIO_NUM_25).
 */
void button_init(uint8_t button_id) {
 
    gpio_config_t btn_conf = {
        .pin_bit_mask = 1ULL << button_id,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&btn_conf); 
}


void button_init_interrupt(uint8_t pin) {
    gpio_install_isr_service(0);

    gpio_config_t btn_conf = {
        .pin_bit_mask = 1ULL << pin,
        .mode = GPIO_MODE_INPUT,
        .pull_up_en = GPIO_PULLUP_ENABLE,
        .intr_type = GPIO_INTR_NEGEDGE
    };
    gpio_config(&btn_conf);

    gpio_isr_handler_add(pin, button_isr, (void*) pin);
}

static volatile uint32_t button_flags = 0;

static void IRAM_ATTR button_isr(void* arg) {
    uint8_t pin = (uint32_t) arg;
     button_flags |= (1U << pin);
}

// Getter: gibt true, wenn gedrückt, und löscht Flag
bool button_was_pressed(uint8_t pin) {
    bool pressed = (button_flags & (1U << pin)) != 0;
    if (pressed) {
        button_flags &= ~(1U << pin); // Flag zurücksetzen
    }
    return pressed;
}


/**
 * @brief Reads the current logic level of a button input.
 *
 * Returns the raw GPIO level of the specified button pin.
 * If the button is wired to ground with an internal pull-up,
 * the function returns:
 *   - 0 when the button is pressed  
 *   - 1 when the button is released
 *
 * @param button_id  GPIO pin number to read from.
 * @return int       Logic level (0 or 1).
 */
int read_button(uint8_t button_id) {
   
    return gpio_get_level(button_id);
}


/**
 * @brief Reads a potentiometer value and returns it as a percentage.
 *
 * This function reads the raw ADC value from the given channel,
 * applies offset correction, smooths the signal using an exponential
 * moving average, and converts the result into a normalized 0–100%
 * range.
 *
 * @param channel  ADC1 channel to read from (e.g., ADC1_CHANNEL_6).
 * @return float   Potentiometer position as a value between 0.0 and 100.0.
 */
int read_pot(uint8_t adc_pin) {
    
    static float smooth_val = 0.0f;   // start value 
    static const float alpha = 0.15f; // smoothing factor
    

    int raw = adc1_get_raw(adc_pin); 

    smooth_val = (alpha * raw) + ((1.0f - alpha) * smooth_val);

   
    float percent = (smooth_val / 4095.0f) * 100.0f; //calc % 

    return(percent);
}