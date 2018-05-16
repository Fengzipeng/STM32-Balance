#ifndef _led_H
#define _led_H

#include "stm32f10x.h"
#include "public.h"

#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4
#define LED5 5

#define LED1_Status GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_12)
#define LED1_ON GPIO_ResetBits(GPIOA,GPIO_Pin_12)
#define LED1_OFF GPIO_SetBits(GPIOA,GPIO_Pin_12)

#define LED2_Status GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_15)
#define LED2_ON GPIO_ResetBits(GPIOA,GPIO_Pin_15)
#define LED2_OFF GPIO_SetBits(GPIOA,GPIO_Pin_15)

#define LED3_Status GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_3)
#define LED3_ON GPIO_ResetBits(GPIOB,GPIO_Pin_3)
#define LED3_OFF GPIO_SetBits(GPIOB,GPIO_Pin_3)

#define LED4_Status GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_4)
#define LED4_ON GPIO_ResetBits(GPIOB,GPIO_Pin_4)
#define LED4_OFF GPIO_SetBits(GPIOB,GPIO_Pin_4)

#define LED5_Status GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_10)
#define LED5_ON GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define LED5_OFF GPIO_SetBits(GPIOB,GPIO_Pin_10)

void LED_Flash(u8 times);
void Led_Init(void);
void LEDx_Flash(u8 LEDx,u8 times);
#endif
