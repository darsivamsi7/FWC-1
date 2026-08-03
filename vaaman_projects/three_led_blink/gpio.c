#include "gpio.h"

#define FGPIO_INPUT_REG      0x40024000
#define FGPIO_OUTPUT_REG     0x40024004
#define FGPIO_DIRECTION_REG  0x40024008


void PyHal_GPIO_SetDir(uint8_t gpionum,uint8_t iomode)
{
    uint32_t temp;

    if(gpionum > 31)
        return;

    temp = *(volatile uint32_t *)FGPIO_DIRECTION_REG;

    if(iomode)
        temp |= (1U << gpionum);
    else
        temp &= ~(1U << gpionum);

    *(volatile uint32_t *)FGPIO_DIRECTION_REG = temp;
}


int PyHal_GPIO_GetDir(uint8_t gpionum)
{
    uint32_t temp;

    if(gpionum > 31)
        return -1;

    temp = *(volatile uint32_t *)FGPIO_DIRECTION_REG;

    return ((temp & (1U << gpionum)) ? GPIO_OUTPUT_MODE : GPIO_INPUT_MODE);
}


int PyHal_GPIO_Set(uint8_t gpionum,uint8_t value)
{
    uint32_t temp;

    if(gpionum > 31)
        return -1;

    temp = *(volatile uint32_t *)FGPIO_OUTPUT_REG;

    if(value)
        temp |= (1U << gpionum);
    else
        temp &= ~(1U << gpionum);

    *(volatile uint32_t *)FGPIO_OUTPUT_REG = temp;

    return 0;
}


int PyHal_GPIO_Get(uint8_t gpionum)
{
    uint32_t temp;

    if(gpionum > 31)
        return -1;

    temp = *(volatile uint32_t *)FGPIO_INPUT_REG;

    return ((temp & (1U << gpionum)) ? 1 : 0);
}
