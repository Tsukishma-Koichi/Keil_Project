#include "Encoder.h"

#define RCC_APB2Periph RCC_APB2Periph_GPIOB
#define GPIOx GPIOB

#define GPIO_Pin_x0 GPIO_Pin_0
#define GPIO_Pin_x1 GPIO_Pin_1

#define GPIO_PinSourcex0 GPIO_PinSource0
#define GPIO_PinSourcex1 GPIO_PinSource1

#define GPIO_PortSource GPIO_PortSourceGPIOB

#define EXTI_Linex0 EXTI_Line0
#define EXTI_Linex1 EXTI_Line1

void Encoder_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_x0 | GPIO_Pin_x1 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSource, GPIO_PinSourcex0);
	GPIO_EXTILineConfig(GPIO_PortSource, GPIO_PinSourcex1);
	
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Linex0 | EXTI_Linex1;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure0;
	NVIC_InitStructure0.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure0.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure0.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure0.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure0);
	
	NVIC_InitTypeDef NVIC_InitStructure1;
	NVIC_InitStructure1.NVIC_IRQChannel = EXTI1_IRQn;
	NVIC_InitStructure1.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure1.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure1.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure1);
}

int16_t Encoder_Count = 0;

int16_t Encoder_Get(void)
{
	int16_t temp = Encoder_Count;
	Encoder_Count = 0;
	
	return temp;
}

void EXTI0_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Linex0) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin_x1) == 0)
		{
			Encoder_Count--;
		}
		EXTI_ClearITPendingBit(EXTI_Linex0);
	}
}

void EXTI1_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Linex1) == SET)
	{
		if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin_x0) == 0)
		{
			Encoder_Count++;
		}
		EXTI_ClearITPendingBit(EXTI_Linex1);
	}
}