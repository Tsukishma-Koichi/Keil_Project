//=============================================================================
//文件名称:main.c
//功能概要:延时闪烁PC13连接的LED
//         低电平LED——>亮，高电平-->灭
//版权所有:源地工作室 http://www.vcc-gnd.com/  网店 http://vcc-gnd.taobao.com/
//版本更新:2013-10-09 v1.0
//调试方式:ST-Link
//=============================================================================


//头文件
#include "stm32f10x.h"
#include "usart.h"
#include "led.h"
#include "RTC_Time.h" 
#include <stdio.h>

//=============================================================================
//函数名称:Delay
//功能概要:延时函数
//参数说明:无
//函数返回:无
//=============================================================================
void  Delay (uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}
//=============================================================================
//函数名称:main
//功能概要:主函数
//参数说明:无
//函数返回:int
//=============================================================================
int main(void)
{
		

		LED_GPIO_Config();//初始化LED
    USART1_Config();
    printf("*****************************************************************\r\n");
    printf("*                                                               *\r\n");
    printf("*      STM32最小系统板RTC测试后循环点亮PC13端的LED!          ^_^  *\r\n");
    printf("*                                                               *\r\n");
    printf("*****************************************************************\r\n");
	
    RTC_Init();
	
    while (1)
    {

    }
}



/*********************************************************************************************************
      END FILE
*********************************************************************************************************/





