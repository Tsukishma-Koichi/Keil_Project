#include "key.h"
#include "Delay.h"

void Key_Init(uint32_t RCC_APB2Periph, GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}

uint8_t Key_GetNum(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	uint8_t KeyNum = 0;
	
	if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == 0)
			continue;
		Delay_ms(20);
		KeyNum = 1;		
	}
	
	return KeyNum;
}