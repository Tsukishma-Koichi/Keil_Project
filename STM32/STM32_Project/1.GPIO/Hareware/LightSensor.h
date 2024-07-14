#ifndef _LIGHTSENSOR_H_
#define _LIGHTSENSOR_H_

#include "stm32f10x.h"

void LightSensor_Init(uint32_t RCC_APB2Periph, GPIO_TypeDef * GPIOX, uint16_t GPIO_Pin);
uint8_t LightSensor_Get(GPIO_TypeDef * GPIOX, uint16_t GPIO_Pin);


#endif