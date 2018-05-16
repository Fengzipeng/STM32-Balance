#include "at24cxx.h"
u8 AT24Cxx_ReadOneByte(u8 addr)//��ȡһ���ֽ�
{                         //add--���ݵ�ַ
	u8 temp;
	IIC_Start();
	if(EE_TYPE>AT24C16) 
	{
		IIC_Send_Byte(0xa0);
		IIC_Wait_Ack();             //�ȴ�Ӧ��
		IIC_Send_Byte(addr>>8);
	}
	else 
	{
		IIC_Send_Byte(0xa0+ ((addr/256)<<1) );//������ַ+���ݵ�ַ
	}
	IIC_Wait_Ack();
	IIC_Send_Byte(addr%256);
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(0xa1);
	IIC_Wait_Ack();
	temp=IIC_Read_Byte(0);//��Ӧ��
	IIC_Stop();
	return temp;
}
void AT24Cxx_WriteOneByte(u8 addr,u8 dat)
{
	IIC_Start();
  if(EE_TYPE>AT24C16) 
	{
		IIC_Send_Byte(0xa0);
		IIC_Wait_Ack();             //�ȴ�Ӧ��
		IIC_Send_Byte(addr>>8);
	}
	else 
	{
		IIC_Send_Byte(0xa0+ ((addr/256)<<1) );//���ݵ�ַ
	}
	IIC_Wait_Ack();
	IIC_Send_Byte(addr%256);
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(dat);
	IIC_Wait_Ack();
	IIC_Stop();
	Delay_ms(10);
}
u16 AT24Cxx_ReadTwoByte(u16 addr)//�����ֽ�
{
	u16 temp;
	IIC_Start();
	if(EE_TYPE>AT24C16) 
	{
		IIC_Send_Byte(0xa0);
		IIC_Wait_Ack();             //�ȴ�Ӧ��
		IIC_Send_Byte(addr>>8);
	}
	else 
	{
		IIC_Send_Byte(0xa0+ ((addr/256)<<1) );//������ַ+���ݵ�ַ
	}
	IIC_Wait_Ack();
	IIC_Send_Byte(addr%256);
	IIC_Wait_Ack();
	
	IIC_Start();
	IIC_Send_Byte(0xa1);
	IIC_Wait_Ack();
	temp=IIC_Read_Byte(1);//��Ӧ��
	temp<<=8;
	temp|=IIC_Read_Byte(0);
	IIC_Stop();
	return temp;
}
void AT24Cxx_WriteTwoByte(u16 addr,u16 dat)
{
	IIC_Start();
  if(EE_TYPE>AT24C16) 
	{
		IIC_Send_Byte(0xa0);
		IIC_Wait_Ack();             //�ȴ�Ӧ��
		IIC_Send_Byte(addr>>8);     //��ַ�ĸ�λ
	}
	else 
	{
		IIC_Send_Byte(0xa0+ ((addr/256)<<1) );//���ݵ�ַ
	}
	IIC_Wait_Ack();
	IIC_Send_Byte(addr%256);//��ַ�ĵص�λ
	IIC_Wait_Ack();
	
	IIC_Start();
	IIC_Send_Byte(dat>>8);//���͸��ֽ�
	IIC_Wait_Ack();
	IIC_Send_Byte(dat&0xff);//���͵��ֽ�
	IIC_Wait_Ack();
	IIC_Stop();
	Delay_ms(10);
}
