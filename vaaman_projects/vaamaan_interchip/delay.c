#include "delay.h"

/*
 * Simple software delay.
 * This is approximate and depends on CPU clock.
 * We will later replace it with a timer-based delay.
 */

void delay_ms(uint32_t ms)
{
    volatile uint32_t i;

    while(ms--)
    {
        for(i = 0; i < 4000; i++)
        {
            __asm volatile("nop");
        }
    }
}
