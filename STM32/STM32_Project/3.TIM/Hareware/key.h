#ifndef _KEY_H_
#define _KEY_H_

#include "stm32f10x.h"

void Key_Init(uint32_t RCC_APB2Periph, GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin_x);
uint8_t Key_GetNum(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif