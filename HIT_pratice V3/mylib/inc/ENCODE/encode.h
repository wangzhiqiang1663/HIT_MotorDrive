#ifndef _encode_H
#define _encode_H



#include "stm32f10x_lib.h"		//包含所有的头文件	
#include "pid.h"
#include "spwm.h"
#include "adc.h"


typedef struct
{
	int Pos;
	int Vol;
	float flag;
}EncoderType;

typedef struct
{
	EncoderType Encoder;
	float Current;
	float zero;
}MotorMsgType;


typedef struct
{
 int N_TIME;
 int N_number;
 int P_TIME;
 int I_TIME;
}Motor_Control_TIME;

extern  MotorMsgType MotorMsg;
extern float n[2];

void TIM3_Start(void);
void Encoder_InitConfig(void);
void TIM3_Process(void);
void MotorMsg_InitConfig(void);
#endif





