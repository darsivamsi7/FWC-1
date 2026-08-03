#include "gpio.h"
int main(void);
void delay(void)
{
    volatile uint32_t i;

    for(i=0;i<500000;i++);
}
void SystemInit(void)
{
    // Nothing for now
}
void _start(void)
{
    main();

    while (1)
    {
    }
}
int main(void)
{
    PyHal_GPIO_SetDir(22, 1);

    while (1)
    {
        PyHal_GPIO_Set(22, 1);
        for (volatile int i = 0; i < 1000000; i++);

        PyHal_GPIO_Set(22, 0);
        for (volatile int i = 0; i < 1000000; i++);
    }
}

