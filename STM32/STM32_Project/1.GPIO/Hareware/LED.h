#ifndef _LED_H_
#define _LED_H_

#include "stm32f10x.h"

void LED_Init(uint32_t RCC_APB2Periph, GPIO_TypeDef * GPIOX, uint16_t GPIO_Pin_x);
void LED_Set(GPIO_TypeDef * GPIOX, uint16_t GPIO_Pin_x, BitAction BitVal);
void LED_Turn(GPIO_TypeDef * GPIOX, uint16_t GPIO_Pin);

#endif