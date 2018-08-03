#ifndef _time1_pwm_H
#define _time1_pwm_H

#endif

#include "stm32f10x_lib.h"		//包含所有的头文件
#include "config.h"

void TIM1_Config(void);
void NVIC_Config(void);
void SetMotorPWM(float pwm);
