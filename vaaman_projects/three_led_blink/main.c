#include "gpio.h"
#include "delay.h"

/*---------------------------------------------------------
  SystemInit()
----------------------------------------------------------*/
void SystemInit(void)
{
}

/*---------------------------------------------------------
  Main Program
----------------------------------------------------------*/
int main(void)
{
    PyHal_GPIO_SetDir(5, 1);
    PyHal_GPIO_SetDir(10, 1);
    PyHal_GPIO_SetDir(15, 1);

    while (1)
    {
        PyHal_GPIO_Set(5, 1);
        PyHal_GPIO_Set(10, 0);
        PyHal_GPIO_Set(15, 0);
        delay_ms(500);

        PyHal_GPIO_Set(5, 0);
        PyHal_GPIO_Set(10, 1);
        PyHal_GPIO_Set(15, 0);
        delay_ms(500);

        PyHal_GPIO_Set(5, 0);
        PyHal_GPIO_Set(10, 0);
        PyHal_GPIO_Set(15, 1);
        delay_ms(500);
    }
}   // <-- This brace was missing

/*---------------------------------------------------------
  _start()
----------------------------------------------------------*/
void _start(void)
{
    main();

    while (1)
    {
    }
}
