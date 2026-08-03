#include <stdint.h>


extern int main(void);



void Reset_Handler(void)
{

    main();


    while(1);

}



void Default_Handler(void)
{

    while(1);

}



__attribute__((section(".isr_vector")))
void (*vector_table[])(void)=
{

    Reset_Handler,

};
