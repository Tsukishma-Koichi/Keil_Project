#ifndef _COUNTSENSOR_H_
#define _COUNTSENSOR_H_

#include "stm32f10x.h"

void CountSensor_Init(void);
uint16_t CountSensor_Get(void);

#endif