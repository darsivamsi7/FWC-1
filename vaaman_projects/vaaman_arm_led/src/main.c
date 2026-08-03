#include <stdint.h>


#define GPIO_BASE 0x40000000


#define GPIO_DIR (*(volatile uint32_t *)(GPIO_BASE + 0x00))
#define GPIO_OUT (*(volatile uint32_t *)(GPIO_BASE + 0x04))


#define LED1 18
#define LED2 21
#define LED3 22



void delay()
{
    volatile uint32_t i;

    for(i=0;i<1000000;i++)
    {

    }
}



void gpio_init()
{

    GPIO_DIR |= (1<<LED1);
    GPIO_DIR |= (1<<LED2);
    GPIO_DIR |= (1<<LED3);

}



void led_on(uint32_t pin)
{
    GPIO_OUT |= (1<<pin);
}



void led_off(uint32_t pin)
{
    GPIO_OUT &= ~(1<<pin);
}




int main()
{

    gpio_init();


    while(1)
    {

        led_on(LED1);
        delay();
        led_off(LED1);



        led_on(LED2);
        delay();
        led_off(LED2);



        led_on(LED3);
        delay();
        led_off(LED3);

    }


}
