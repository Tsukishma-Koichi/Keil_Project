#include "CountSensor.h"

#define RCC_APB2Periph RCC_APB2Periph_GPIOB
#define GPIOx GPIOB
#define GPIO_Pin_x GPIO_Pin_14
#define GPIO_PortSource GPIO_PortSourceGPIOB
#define GPIO_PinSource GPIO_PinSource14
#define EXTI_Linex EXTI_Line14

void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_x;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSource, GPIO_PinSource);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Linex;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
}

uint16_t CountSensor_Count = 0;

void EXTI15_10_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Linex) == SET)
	{
		CountSensor_Count++;
		EXTI_ClearITPendingBit(EXTI_Linex);
	}
}

uint16_t CountSensor_Get(void)
{
	return CountSensor_Count;
}