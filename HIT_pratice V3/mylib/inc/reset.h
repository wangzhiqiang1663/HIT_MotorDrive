#ifndef __reset__H
#define __reset__H


#include "stm32f10x_lib.h"
#include "encode.h"	

void NVIC_GPIO_Config(void);
void NVIC_Config(void);
void EXTI_Config(void);
void reset_Config(void);
#endif

