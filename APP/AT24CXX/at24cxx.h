#ifndef _at24cxx_H_
#define _at24cxx_H_
#include "stm32f10x.h"
#include "iic.h"
#include "systick.h"
#define AT24C01   127  //各版本存储器大小定义
#define AT24C02   255
#define AT24C04   511
#define AT24C08   1023
#define AT24C16   4095
#define AT24C32   8191
#define AT24C64   16383
#define AT24C128  32767
#define EE_TYPE  AT24C02
u8 AT24Cxx_ReadOneByte(u8 addr);
void AT24Cxx_WriteOneByte(u8 addr,u8 dat);
u16 AT24Cxx_ReadTwoByte(u16 addr);
void AT24Cxx_WriteTwoByte(u16 addr,u16 dat);
#endif
