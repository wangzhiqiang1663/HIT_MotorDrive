#include "pid.h"

POS_PID_Struct PID_Motor_P;  //位置环
POS_PID_Struct PID_Motor_V;  //速度环
POS_PID_Struct PID_Motor_I;  //电流环

void PIDStruct_Init(POS_PID_Struct *pid)
{
	
	 pid->P= 0;   // 比例常数 ProportionalConst
   pid->I= 0;    // 积分常数 Integral ConstConst
	 pid->D= 0;
	 pid->Imax= 0;
	 
	 pid->SumErr= 0;
   pid->LastError= 0;     //Error[ k - 1 ]
	 pid->NowErr= 0;
	 
	 pid->Measured= 0;
	 pid->Expect= 0;
	 
	 pid->O_limitmax= 0;    // 设定输出正转限幅值
	 pid->OutPut= 0;
}
void PID_Param_Init(POS_PID_Struct *pid,\
	                  float p,float i,float d,\
										float im,float outputmax)
{
	pid->P = p;
	pid->I = i;
	pid->D = d;
	pid->Imax=im;
	pid->O_limitmax = outputmax;
}



void PID_InitConfig(void)
{
	PIDStruct_Init(&PID_Motor_P);
	PIDStruct_Init(&PID_Motor_V);
	PIDStruct_Init(&PID_Motor_I);

	PID_Param_Init(&PID_Motor_P,0,0,0,I_MAX,O_max);
	PID_Param_Init(&PID_Motor_V,0,0,0,5000,1200);
	PID_Param_Init(&PID_Motor_I,0,0,0,I_MAX,O_max);

	#ifdef P_V_I_CONTROL_MODE
	  PID_Param_Init(&PID_Motor_P,0.2,0,0,I_MAX,O_max); 
		PID_Param_Init(&PID_Motor_V,13,0.7,0,5000,1200);
		PID_Param_Init(&PID_Motor_I,0.1,0,0,I_MAX,O_max);
	#endif	
		
	#ifdef P_V_CONTROL_MODE      //调完    
		PID_Param_Init(&PID_Motor_P,P_set,I_set,0,I_MAX,O_max);  
		PID_Param_Init(&PID_Motor_V,40,0.01,0,5000,1000);
	#endif

	#ifdef V_I_CONTROL_MODE
		PID_Param_Init(&PID_Motor_V,13,0.7,0,5000,O_max);
		PID_Param_Init(&PID_Motor_I,0,0,0,I_MAX,O_max); 
//		PID_Param_Init(&PID_Motor_V,0.002,0.000003,0,5000,MAX_CUR_OUTPUT);
//		PID_Param_Init(&PID_Motor_I,75,12,0,5000,MAX_PWM_OUTPUT);
	#endif

	#ifdef P_CONTROL_MODE
		PID_Param_Init(&PID_Motor_P,0.2,0,0,I_MAX,O_max); 
	#endif

	#ifdef V_CONTROL_MODE      //调完了
		PID_Param_Init(&PID_Motor_V,40,1,0,5000,1000);
	#endif

	#ifdef I_CONTROL_MODE   
		PID_Param_Init(&PID_Motor_I,P_set,I_set,D_set,I_MAX,O_max);
	#endif

}
 

 
  float PIDCalc (POS_PID_Struct *pid)     
{ 
		float Pout = 0,Iout = 0,Dout = 0;
	
	/*误差计算*/
	pid->NowErr  = pid->Expect - pid->Measured;
	pid->SumErr += (pid->I == 0) ? 0 : pid->NowErr;
	
	/*P-I-D*/
	Pout = pid->P * pid->NowErr;
	Iout = pid->I * pid->SumErr;
	Dout = pid->D * (pid->NowErr - pid->LastError);
	
	/*积分限幅*/
	if (Iout >= pid->Imax)
	{
		pid->SumErr -= pid->NowErr; 
		Iout        = pid->Imax;
	}
	else if (Iout <= -pid->Imax)
	{
		pid->SumErr -= pid->NowErr;
		Iout        = -pid->Imax;
	}
	
	/*PID输出*/
	pid->OutPut = Pout + Iout + Dout;
	
	/*输出限幅*/
	if (pid->OutPut >= pid->O_limitmax) 
		pid->OutPut = pid->O_limitmax;
	else if (pid->OutPut<=-pid->O_limitmax)
	  pid->OutPut = -pid->O_limitmax;
	
	/*误差更新*/
	pid->LastError = pid->NowErr;
	return pid->OutPut;  
}
