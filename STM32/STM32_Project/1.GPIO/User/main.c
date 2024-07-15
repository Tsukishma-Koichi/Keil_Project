#include "Public.h"

int main(void)
{
	OLED_Init();
	
	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(1, 3, "Hello Wolrd!");
	OLED_ShowNum(2, 1, 1234, 6);
	
	while (1)
	{
		
	}
}