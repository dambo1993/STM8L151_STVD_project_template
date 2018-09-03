#include "stm8l15x.h"

main()
{
	GPIO_Init(GPIOC, GPIO_Pin_1, GPIO_Mode_In_FL_No_IT);
	GPIO_Init(GPIOC, GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Fast);
	GPIO_Init(GPIOE, GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Fast);
	
	while (1)
	{
		if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_1) == FALSE)
		{
			GPIO_SetBits(GPIOC, GPIO_Pin_7);
			GPIO_ResetBits(GPIOE, GPIO_Pin_7);
		}
		
		else
		{
			GPIO_ResetBits(GPIOC, GPIO_Pin_7);
			GPIO_SetBits(GPIOE, GPIO_Pin_7);
		}
	}
}
