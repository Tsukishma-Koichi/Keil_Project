#include "Public.h"

uint16_t ADValue;

int main(void)
{
	OLED_Init();
	AD_Init();
	
	OLED_ShowString(1, 1, "AD0:");
								  
	while (1)
	{
		AD_GetValue();
		OLED_ShowNum(1, 5, AD_Value[0], 4);
		
		Delay_ms(100);
	}
}

