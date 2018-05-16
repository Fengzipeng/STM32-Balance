#ifndef _BEEP_H
#define _BEEP_H

#include "stm32f10x.h"
#include "public.h"
#define Beep_GPIO GPIOB
#define Beep_Pin GPIO_Pin_11
void Beep_Init(void);
void Beep_Flash(u8 times);
void Beep_ON(void);
void Beep_OFF(void);
extern u8 Beep_Open;
#endif
