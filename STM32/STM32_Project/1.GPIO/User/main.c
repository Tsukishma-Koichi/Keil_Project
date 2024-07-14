#include "Public.h"

uint8_t KeyNum;
uint8_t LS_Num;

int main(void)
{
	LED_Init(RCC_APB2Periph_GPIOA, GPIOA, GPIO_Pin_0);
	LED_Init(RCC_APB2Periph_GPIOA, GPIOA, GPIO_Pin_3);
	Key_Init(RCC_APB2Periph_GPIOB, GPIOB, GPIO_Pin_1);
	LightSensor_Init(RCC_APB2Periph_GPIOB, GPIOB, GPIO_Pin_11);
	
	while (1)
	{
		KeyNum = Key_GetNum(GPIOB, GPIO_Pin_1);
		if (KeyNum == 1)
		{
			LED_Turn(GPIOA, GPIO_Pin_0);
		}
		
		LS_Num = LightSensor_Get(GPIOB, GPIO_Pin_11);
		if (LS_Num == 1)
		{
			LED_Turn(GPIOA, GPIO_Pin_3);
		}
	}
}