#ifndef _ENCODERINF_
#define _ENCODERINF_

#include "stm32f10x.h"

void EncoderInf_Init(void);
int16_t EncoderInf_Get(void);

#endif

/*
int16_t Speed;

int main(void)
{
	OLED_Init();
	Timer_Init();
	EncoderInf_Init();
	
	OLED_ShowString(1, 1, "Speed:");
	
	while (1)
	{
		OLED_ShowSignedNum(1, 7, Speed, 5);
	}
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		Speed = EncoderInf_Get();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
*/