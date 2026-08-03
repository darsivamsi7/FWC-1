#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIO_OUTPUT_MODE    1
#define GPIO_INPUT_MODE     0

void PyHal_GPIO_SetDir(uint8_t gpionum, uint8_t iomode);
int  PyHal_GPIO_GetDir(uint8_t gpionum);

int  PyHal_GPIO_Set(uint8_t gpionum, uint8_t value);
int  PyHal_GPIO_Get(uint8_t gpionum);

#endif
