#ifndef CV1800B_H
#define CV1800B_H

#include <stdint.h>

typedef volatile uint32_t reg32_t;

struct gpio_registers
{
    reg32_t SWPORTA_DR;
    reg32_t SWPORTA_DDR;
    reg32_t __RESERVED1[10];
    reg32_t INTEN;
    reg32_t INTMASK;
    reg32_t INTTYPE_LEVEL;
    reg32_t INT_POLARITY;
    reg32_t INTSTATUS;
    reg32_t RAW_INTSTATUS;
    reg32_t DEBOUNCE;
    reg32_t PORTA_EOI;
    reg32_t EXT_PORTA;
    reg32_t __RESERVED2[3];
    reg32_t LS_SYNC;
};

#define GPIO_BASE_ADDRESS (0x03020000)
#define GPIO0 ((struct gpio_registers *)(GPIO_BASE_ADDRESS + 0x0000))
#define GPIO1 ((struct gpio_registers *)(GPIO_BASE_ADDRESS + 0x1000))
#define GPIO2 ((struct gpio_registers *)(GPIO_BASE_ADDRESS + 0x2000))
#define GPIO3 ((struct gpio_registers *)(GPIO_BASE_ADDRESS + 0x3000))

#endif // CV1800B_H