#include <stdint.h>

// Register addresses
#define RCC_BASE        0x40023800
#define GPIOC_BASE      0x48000800

#define RCC_AHB1ENR     *((volatile uint32_t*)(RCC_BASE + 0x30))
#define GPIOC_MODER     *((volatile uint32_t*)(GPIOC_BASE + 0x00))
#define GPIOC_ODR       *((volatile uint32_t*)(GPIOC_BASE + 0x14))

// Bit positions
#define RCC_AHB1ENR_GPIOCEN (1 << 2)
#define GPIO_MODER_OUTPUT   (1 << 10) // Assuming pin D4 is PC5 on the MCU
#define GPIO_ODR_PIN        (1 << 5)  // Assuming pin D4 is PC5 on the MCU

int main(void) {
    // Enable clock for GPIOC
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // Set GPIOC pin 5 as output
    GPIOC_MODER &= ~(0x3 << (5 * 2)); // Clear mode bits for pin 5
    GPIOC_MODER |= GPIO_MODER_OUTPUT;

    // Set GPIOC pin 5 high
    GPIOC_ODR |= GPIO_ODR_PIN;

    // Loop forever
    while(1) {
    }

    return 0;
}

