#include "math.h"
#include "public.h"
#include "mpu6050.h"
#include "DataScope_DP.h"
#include "iic.h"
#define Ture  1
#define False 0
u8 Send_Data[32]={0x55,0x55,0x55,0x55,0x55};
int main()
{
	u8 Send_Count,i;
	Delay_ms(1000);     //上电延时
	Led_Init();
	LED_Flash(1);
	Delay_ms(500);
	//Beep_Init();
	Printf_init();
	//if(MPU6050_DMP_Init()) LED_Flash(3);
	MPU6050_Init();
	NRF24L01_Init(NRF24L01_RXMode);//数据接收模式
	Encoder_Init();
	Usart_Init(1,115200,0);
	Motor_Control_PWM_Init();
	EXTI5_Init(); //外部中断初始化
	while(Ture)
	{		
		if(flag==5)
		{
			flag=0;
		  //DataScope_Get_Channel_Data(Pitch,Channel_1);
			DataScope_Get_Channel_Data(Angle_Balance,Channel_1);
			//DataScope_Get_Channel_Data(Yaw,Channel_3);
			DataScope_Get_Channel_Data(Gyro_Balance,Channel_2);
	    //DataScope_Get_Channel_Data(Velocity_Pwm,Channel_3);
			//DataScope_Get_Channel_Data(Encoder_Right,Channel_2);
		  Send_Count = DataScope_Data_Generate(2);
	    for(i=0;i<Send_Count;i++)
	   {
		  USART_SendData(USART1,DataScope_OutPut_Buffer[i]);
		  while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=1);
		  USART_ClearFlag(USART1,USART_FLAG_TC);
	   }
		 
		}
	}
}



