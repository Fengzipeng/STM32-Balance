#ifndef __Driver__
#define __Driver__
/*--------------------------------------------------------------------------
// �ļ�����Driver.h
// ������  ϵͳ����ͷ�ļ�
// ����ߣ�EU����
// �������ڣ�2013��11��10��
// ����EU���ӳ�Ʒ-��Ȩ����-����ؾ�
// EU-�Ȱ�Ƕ��ʽ����
// http://euse.taobao.com
//-------------------------------------------------------------------------*/
//typedef unsigned char       bool;
typedef unsigned char       u8;
typedef unsigned short      u16;

/*-------------------------------------------------------------------------------------------------------
*  ����ӿ�	ΪӦ�ò��ṩ�Ľӿ�										 
-------------------------------------------------------------------------------------------------------*/
//mcu
extern void Driver_MCU_Init(void);
//lcd
extern void Driver_LcdBacklight(u8 sta);
extern void Driver_LcdReset(u8 sta);
extern void Driver_LcdCS(u8 sta);
extern void Driver_LcdRS(u8 sta);
extern void Driver_LcdRD(u8 sta);
extern void Driver_LcdWR(u8 sta);
extern void Driver_LcdSendData(u16 Temp);
//spi
extern void Driver_SPION(void);
extern void Driver_SPIOFF(void);
extern void Driver_SPICSEN(void);
extern void Driver_SPICSUN(void);
extern void Driver_SPISend(u8 Data);
extern u8 Driver_SPIRecv(void);
//fsmc
extern void Driver_LcdFSMCON(void);
extern void Driver_LcdFSMCWriteReg(u16 Index);
extern void Driver_LcdFSMCWriteData(u16 Data);
extern u16 Driver_LcdFSMCReadData(void);
//Touch
extern void Driver_SPICS(u8 sta);
extern void Driver_SPISCK(u8 sta);
extern void Driver_SPIMOSI(u8 sta);
extern u8 Driver_SPIMISO(void);

#endif



