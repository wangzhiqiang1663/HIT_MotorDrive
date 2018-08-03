# include"encode.h"	
int a,f;
float n[2];

MotorMsgType MotorMsg;


void Encoder_InitConfig(void)
{
  GPIO_InitTypeDef         GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_ICInitTypeDef        TIM_ICInitStructure;
	NVIC_InitTypeDef         NVIC_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  GPIO_StructInit(&GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
   
/***********************TIME2 当做定时器的正交编码器输入*********************************/
  TIM_DeInit(TIM2);	 
	TIM_InternalClockConfig(TIM2);
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除TIM2的更新标志位
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//运行更新中断
	
  TIM_TimeBaseStructure.TIM_Period =0xffff;           // 计数最大值65535    
  TIM_TimeBaseStructure.TIM_Prescaler =0;	            //不分频
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   //上升沿计数
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising); 
  TIM_ICStructInit(&TIM_ICInitStructure);
  TIM_ICInitStructure.TIM_ICFilter = 6;        
  TIM_ICInit(TIM2, &TIM_ICInitStructure);
  
//  TIM3->ARR=30000;
//	TIM3->PSC=0;
//	TIM3->CCMR1|=1<<0;
//	TIM3->CCMR1|=1<<8;
//	TIM3->CCER|=0<<1;
//  TIM3->CCER|=0<<5;
//	TIM3->SMCR|=3<<0;
  TIM_SetCounter(TIM2,30000);  
//	TIM_SetAutoreload(TIM3,30000);
	TIM_ARRPreloadConfig(TIM2, ENABLE);//使能TIM3在ARR上的预装载寄存器
  TIM_Cmd(TIM2, ENABLE);  
	
	//TIM3设置为1ms的定时器
	TIM_TimeBaseStructure.TIM_Period = 100-1;          //定时器频率为72MHZ，分频为720，则定时器2输入频率为100K,计数值为100，则1K溢出1次，即1ms采样一次
	TIM_TimeBaseStructure.TIM_Prescaler =720-1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //采用组别2	 
	NVIC_InitStructure.NVIC_IRQChannel =TIM3_IRQChannel; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);  

}

void TIM3_Start(void)
{
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);	
	TIM_Cmd(TIM3, ENABLE);
	TIM_ClearITPendingBit(TIM3, TIM_IT_Update); 
}

void MotorMsg_InitConfig(void)
{
	MotorMsg.Current     = 0;
	MotorMsg.Encoder.Pos = 0;
	MotorMsg.Encoder.Vol = 0;
}

void TIM3_Process(void)
{
//	int16_t pwm = 0;
//     int a;
//	  static int k;
	  float pwm;
	  
//	MotorMsg.Encoder.Pos += 30000 - TIM3->CNT;	
//	MotorMsg.Encoder.Vol  = 30000 - TIM3->CNT ;
//	MotorMsg.Current      = -Get_Current(2);
//	  V =TIM_GetCounter(TIM4);
//	  V = V-30000;
	  
//	  n=(V*10*60)/(2000*86);
	  a++;
//	n[0]=TIM2->CNT-30000;
//  n[1]=((TIM2->CNT-30000)*1000*60*1.0f)/(2000*86*1.0f);
	  f=1;
//	  f=(a>=5000)?1:-1;
	  MotorMsg.Encoder.Pos += TIM2->CNT-30000;	
	  MotorMsg.Encoder.Vol  = TIM2->CNT-30000;
    MotorMsg.Current      = Get_Current(0);
//	  a=(int)(n[1]*100 + 0.5);
//	  n[1]=(float)(a*1.0f/100);
//	  TIM_SetCounter(TIM4,30000); 
    TIM2->CNT = 30000;
    PID_Motor_P.Measured = MotorMsg.Encoder.Pos;
	  PID_Motor_V.Measured = MotorMsg.Encoder.Vol;
	  PID_Motor_I.Measured = MotorMsg.Current;

#ifdef P_V_I_CONTROL_MODE
	PID_Motor_P.Expect   = expect;
	PID_Motor_V.Expect   = PIDCalc(&PID_Motor_P);
	PID_Motor_I.Expect   = PIDCalc(&PID_Motor_V);
	pwm                  = PIDCalc(&PID_Motor_I);
#endif	
	
#ifdef P_V_CONTROL_MODE  
	PID_Motor_P.Expect   = expect;
	PID_Motor_V.Expect   = PIDCalc(&PID_Motor_P);
	pwm                  = PIDCalc(&PID_Motor_V);
#endif

#ifdef V_I_CONTROL_MODE
	PID_Motor_V.Expect   = expect;
	PID_Motor_I.Expect   = PIDCalc(&PID_Motor_V);
	pwm                  = PIDCalc(&PID_Motor_I);
#endif

#ifdef P_CONTROL_MODE
  PID_Motor_P.Expect   = expect;
	pwm                  = PIDCalc(&PID_Motor_P);
#endif

#ifdef V_CONTROL_MODE 
  PID_Motor_V.Expect   = f*expect;
	pwm                  = PIDCalc(&PID_Motor_V);
#endif

#ifdef I_CONTROL_MODE
	PID_Motor_I.Expect   = expect;
	pwm                  = PIDCalc(&PID_Motor_I);
#endif
	
    SetMotorPWM(pwm);

}
