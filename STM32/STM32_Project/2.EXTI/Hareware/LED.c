#include "LED.h"

void LED_Init(uint32_t RCC_APB2Periph, GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}

void LED_Set(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{
	//Bit_RESET = 1;
	GPIO_WriteBit(GPIOx, GPIO_Pin, BitVal);
}

void LED_Turn(GPIO_TypeDef * GPIOx, uint16_t GPIO_Pin)
{
	if (GPIO_ReadOutputDataBit(GPIOx, GPIO_Pin) == 0)
	{
		GPIO_SetBits(GPIOx, GPIO_Pin);
	}
	else
	{
		GPIO_ResetBits(GPIOx, GPIO_Pin);
	}
}