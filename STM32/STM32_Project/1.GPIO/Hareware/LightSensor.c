#include "LightSensor.h"

void LightSensor_Init(uint32_t RCC_APB2Periph, GPIO_TypeDef * GPIOX, uint16_t GPIO_Pin)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOX, &GPIO_InitStructure);
}

uint8_t LightSensor_Get(GPIO_TypeDef * GPIOX, uint16_t GPIO_Pin)
{
	return GPIO_ReadInputDataBit(GPIOX, GPIO_Pin);
}