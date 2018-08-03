#ifndef _encode_H
#define _encode_H

#endif

#include "stm32f10x_lib.h"		//包含所有的头文件	
#include "pid.h"
#include "time1_pwm.h"
#include "adc.h"


typedef struct
{
	float Pos;
	float Vol;
	float flag;
}EncoderType;


typedef struct
{
	EncoderType Encoder;
	float Current;
	float zero;
}MotorMsgType;


extern  MotorMsgType MotorMsg;
extern float n[2];

void TIM3_Start(void);
void Encoder_InitConfig(void);
void TIM3_Process(void);
void MotorMsg_InitConfig(void);
