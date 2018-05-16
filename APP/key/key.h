#ifndef _key_H
#define _key_H
#include "stm32f10x.h"
#include "public.h"

#define KEY1_STATUS    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define KEY2_STATUS    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)

#define KEY_PRESSED 0 //�������º�IO�������ֵΪ0
void Key_Init(void);
u8 KEY_PRESS_SCAN(void);
#endif

