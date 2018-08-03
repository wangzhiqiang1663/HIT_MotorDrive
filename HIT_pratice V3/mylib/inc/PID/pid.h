#ifndef __PID__H
#define __PID__H


#include "stm32f10x_lib.h"
#include "config.h"
#include "usart.h"


typedef struct POS_PID_Struct
 { 
   float P;   // 比例常数 ProportionalConst
   float I;    // 积分常数 Integral ConstConst
	 float D;
	 float Imax;
	 
	 float SumErr;
   float LastError;     //Error[ k - 1 ]
	 float NowErr;
	 
	 float Measured;
	 float Expect;
	 
	 float O_limitmax;    // 设定输出正转限幅值
	 float OutPut;
 } POS_PID_Struct;
 
extern POS_PID_Struct PID_Motor_P;
extern POS_PID_Struct PID_Motor_V;
extern POS_PID_Struct PID_Motor_I;
 
 	 
void PIDStruct_Init(POS_PID_Struct *pid);
void PID_InitConfig(void);
void PID_Param_Init(POS_PID_Struct *pid,\
	                  float p,float i,float d,\
										float im,float outputmax);
float PIDCalc(POS_PID_Struct *pid);	
										
#endif            

 										