#include "at24cxx.h"
u8 AT24Cxx_ReadOneByte(u8 addr)//读取一个字节
{                         //add--数据地址
	u8 temp;
	IIC_Start();
	if(EE_TYPE>AT24C16) 
	{
		IIC_Send_Byte(0xa0);
		IIC_Wait_Ack();             //等待应答
		IIC_Send_Byte(addr>>8);
	}
	else 
	{
		IIC_Send_Byte(0xa0+ ((addr/256)<<1) );//器件地址+数据地址
	}
	IIC_Wait_Ack();
	IIC_Send_Byte(addr%256);
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(0xa1);
	IIC_Wait_Ack();
	temp=IIC_Read_Byte(0);//非应答
	IIC_Stop();
	return temp;
}
void AT24Cxx_WriteOneByte(u8 addr,u8 dat)
{
	IIC_Start();
  if(EE_TYPE>AT24C16) 
	{
		IIC_Send_Byte(0xa0);
		IIC_Wait_Ack();             //等待应答
		IIC_Send_Byte(addr>>8);
	}
	else 
	{
		IIC_Send_Byte(0xa0+ ((addr/256)<<1) );//数据地址
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
u16 AT24Cxx_ReadTwoByte(u16 addr)//读两字节
{
	u16 temp;
	IIC_Start();
	if(EE_TYPE>AT24C16) 
	{
		IIC_Send_Byte(0xa0);
		IIC_Wait_Ack();             //等待应答
		IIC_Send_Byte(addr>>8);
	}
	else 
	{
		IIC_Send_Byte(0xa0+ ((addr/256)<<1) );//器件地址+数据地址
	}
	IIC_Wait_Ack();
	IIC_Send_Byte(addr%256);
	IIC_Wait_Ack();
	
	IIC_Start();
	IIC_Send_Byte(0xa1);
	IIC_Wait_Ack();
	temp=IIC_Read_Byte(1);//非应答
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
		IIC_Wait_Ack();             //等待应答
		IIC_Send_Byte(addr>>8);     //地址的高位
	}
	else 
	{
		IIC_Send_Byte(0xa0+ ((addr/256)<<1) );//数据地址
	}
	IIC_Wait_Ack();
	IIC_Send_Byte(addr%256);//地址的地低位
	IIC_Wait_Ack();
	
	IIC_Start();
	IIC_Send_Byte(dat>>8);//发送高字节
	IIC_Wait_Ack();
	IIC_Send_Byte(dat&0xff);//发送低字节
	IIC_Wait_Ack();
	IIC_Stop();
	Delay_ms(10);
}
