#include "usart3.h"
void Usart3_Init()   //���ڳ�ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure; 
  //NVIC_InitTypeDef  NVIC_InitStructure;//�ж����ȼ�
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�򿪸��ù���
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);//����ʱ��
	/*********************�ܽ�����***************************/
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//�����������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//txd
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//��������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;//rxd
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	/*******************************************************/
	/***************��������******************/
	USART_InitStructure.USART_BaudRate=9600;//������9600
	USART_InitStructure.USART_StopBits=USART_StopBits_1;//ֹͣλ
	USART_InitStructure.USART_Parity=USART_Parity_No;//У��λ--��
	USART_InitStructure.USART_HardwareFlowControl = //Ӳ����ʧ��
	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Tx |USART_Mode_Rx;//ģʽ
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART3,&USART_InitStructure);
	USART_Cmd(USART3,ENABLE); //����ʹ��
	/*************************************/
	//USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);//�����ж�ʹ��
	USART_ClearFlag(USART3,USART_FLAG_TC);//��շ��ͱ�־λ
}