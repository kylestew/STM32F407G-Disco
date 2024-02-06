#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

/*
 * Blinks onboard LED @ PD13
 */

void delay(long time) {
    volatile long count = time;
    while (count--) {
        __asm__("nop");
    }
}

static void gpio_setup(void) {
    // Enable port by enabling it's clock
    // pg 148: enable GPIO clock for port E - RCC_AHBENR: IOPE EN = 1
    rcc_periph_clock_enable(RCC_GPIOD);

    // Set control registers for port E pin 8
    // pg 237: general purpose output (open drain) - GPIOE MODER: MODER8 = 01
    // pg 237: set pin to push-pull - GPIOE_OTYPER: OT8 = 0
    // pg 238: set pin to high speed - GPIOE_OSSPEEDER: OSPEEDR8 = 11
    // pg 238: set pin to pull up / pull down - GPIOE_PUPDR: PUPDR8 = 00
    gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);
}

int main(void) {
    /* NOTE: we are not setting up any clocks, this means the MCU will run
     * on default settings using the internal oscillator.
     */

    gpio_setup();

    // Blink the LED (PE8) on the board
    while (1) {
        // toggle LED on/off
        gpio_toggle(GPIOD, GPIO13);
        delay(400000);
    }

    return 0;
}