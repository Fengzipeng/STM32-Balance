#include "beep.h"
u8 Beep_Open=0;
void Beep_Init()
{
	 GPIO_InitTypeDef  GPIO_InitStruct; //结构体变量定义
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	 GPIO_InitStruct.GPIO_Pin=Beep_Pin;  //Beep
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出模式
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(Beep_GPIO,&GPIO_InitStruct); 
	 GPIO_SetBits(Beep_GPIO,GPIO_Pin_11);
}
void Beep_ON(void)
{
	GPIO_ResetBits(Beep_GPIO,Beep_Pin);
}
void Beep_OFF()
{
	GPIO_SetBits(Beep_GPIO,Beep_Pin);
}
void Beep_Flash(u8 times)
{
	u8 i;
	for(i=0;i<times;i++)
	{
		GPIO_ResetBits(Beep_GPIO,Beep_Pin);
		Delay_ms(1000);
		GPIO_SetBits(Beep_GPIO,Beep_Pin);
		Delay_ms(1000);
	}
}
