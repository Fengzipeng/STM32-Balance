#ifndef _spi_H
#define _spi_H
#include "sys.h"
#include "systick.h"

void SPI1_Init(void);  //SPI初始化
u8 SPI1_ReadWriteByte(u8 dat);		 //SPI2读写一个字节
void SPI1_SetSpeed(u8 SPI_BaudRatePrescaler);	//设置SPI2的速度


#endif
