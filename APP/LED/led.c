#include "led.h"
void Led_Init()  //LED初始化函数
{
	 GPIO_InitTypeDef  GPIO_InitStruct; //结构体变量定义
	 SystemInit();  //打开系统时钟
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO,ENABLE);
	 GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//禁用JTAG  开启复用时钟
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_12;  //LED1
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出模式
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOA,&GPIO_InitStruct); 
	
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_15;  //LED2
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出模式
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOA,&GPIO_InitStruct);  
	
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_3;  //LED3
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出模式
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOB,&GPIO_InitStruct); 
	
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_4;  //LED4
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出模式
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOB,&GPIO_InitStruct); 
	 
	 /*GPIO_InitStruct.GPIO_Pin=GPIO_Pin_10;  //LED5
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;//推挽输出模式
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOB,&GPIO_InitStruct); */
	 /*******************************/
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_10;
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPD;//推挽输出模式
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOB,&GPIO_InitStruct); 
	 
	 GPIO_InitStruct.GPIO_Pin=GPIO_Pin_11;  
	 GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IPD;//推挽输出模式
	 GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	 GPIO_Init(GPIOB,&GPIO_InitStruct); 
	 /********************************/
	 GPIO_SetBits(GPIOA,GPIO_Pin_12);
	 GPIO_SetBits(GPIOA,GPIO_Pin_15);
	 GPIO_SetBits(GPIOB,GPIO_Pin_3);
	 GPIO_SetBits(GPIOB,GPIO_Pin_4);
	 GPIO_SetBits(GPIOB,GPIO_Pin_10);
}
void LEDx_Flash(u8 LEDx,u8 times)
{
	int i;
	switch(LEDx)
	{
		case 1:{{for(i=0;i<times;i++)LED1_ON;Delay_ms(400);LED1_OFF;Delay_ms(400);}break;}
	  case 2:{{for(i=0;i<times;i++)LED2_ON;Delay_ms(400);LED2_OFF;Delay_ms(400);}break;}
		case 3:{{for(i=0;i<times;i++)LED3_ON;Delay_ms(400);LED3_OFF;Delay_ms(400);}break;}
		case 4:{{for(i=0;i<times;i++)LED4_ON;Delay_ms(400);LED4_OFF;Delay_ms(400);}break;}
		case 5:{{for(i=0;i<times;i++)LED5_ON;Delay_ms(400);LED5_OFF;Delay_ms(400);}break;}
		default :break;
	}
}
void LED_Flash(u8 times)
{
	u8 i;
	for(i=0;i<times;i++)
	 {
		 LED1_ON;
		 LED2_ON;
		 LED3_ON;
		 LED4_ON;
		 Delay_ms(200);
		 LED1_OFF;
		 LED2_OFF;
		 LED3_OFF;
		 LED4_OFF;
		 Delay_ms(200);
	 }
}

