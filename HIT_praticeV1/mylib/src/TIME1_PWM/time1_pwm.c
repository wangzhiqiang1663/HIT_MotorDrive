#include "time1_pwm.h"


/**********************************************************
** 函数名: TIM1_Config
** 功能描述:  定时器2配置为PWM1输出模式
** 输入参数: 无
** 输出参数: 无
***********************************************************/
void TIM1_Config(void)
{
		TIM1_TimeBaseInitTypeDef  TIM_TimeBaseStructure;//定义结构体
		TIM1_OCInitTypeDef  TIM_OCInitStructure;
		GPIO_InitTypeDef GPIO_InitStructure;
//	  TIM1_OCInitTypeDef  TIMI_OCInitStructure;
	//1.定时器初始化程序
		TIM1_DeInit();
		TIM1_InternalClockConfig();

	//2.开启时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOB, ENABLE);//使能GPIOA及功能复用IO时钟
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);//使能TIM1时钟
	//3.GPIOA和GPI0B配置为：定时器1的PWM第1个通道复用功能互补输出
  	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//I/O时钟为50MHz
  	GPIO_Init(GPIOA, &GPIO_InitStructure);//根据上面指定参数初始化GPIO结构体
	
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	 
	//4.定时器基本配置,设置PWM输出频率，Prescaler/72M*Period=周期
		TIM_TimeBaseStructure.TIM1_Period =2500-1;//计数值为1000
		TIM_TimeBaseStructure.TIM1_Prescaler =1-1;//不分频
		TIM_TimeBaseStructure.TIM1_ClockDivision = 0;//采样分频0
		TIM_TimeBaseStructure.TIM1_CounterMode = TIM_CounterMode_Up;//向上计数
		TIM_TimeBaseStructure.TIM1_RepetitionCounter=0;
		TIM1_TimeBaseInit(&TIM_TimeBaseStructure);
		
	   
		 
  //5.定时器输出通道配置，注意通用寄存器无TIM_OutputNState等带N参数
		TIM_OCInitStructure.TIM1_OCMode = TIM_OCMode_PWM1;//定时器配置为PWM1模式
		TIM_OCInitStructure.TIM1_OutputState=TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM1_OutputNState=TIM_OutputNState_Enable;  //使能互补端输出
		TIM_OCInitStructure.TIM1_Pulse =1250;//脉宽值为1250
	  TIM_OCInitStructure.TIM1_OutputState = TIM1_OutputState_Enable;
    TIM_OCInitStructure.TIM1_OutputNState = TIM1_OutputNState_Enable;
		TIM_OCInitStructure.TIM1_OCPolarity = TIM1_OCPolarity_High;//TIM输出比较极性高
		TIM_OCInitStructure.TIM1_OCNPolarity =TIM1_OCNPolarity_High; 
    TIM_OCInitStructure.TIM1_OCIdleState = TIM1_OCIdleState_Reset;
    TIM_OCInitStructure.TIM1_OCNIdleState = TIM1_OCIdleState_Set;		
//		TIM1_OCInitStructure.TIM1_OCIdleState=TIM_OCIdleState_Set;    //死区后输出状态 
//		TIM1_OCInitStructure.TIM1_OCNIdleState =TIM_OCNIdleState_Reset;  
			
	
		TIM1_OC1Init(&TIM_OCInitStructure); //根据TIM_OCInitStruct中指定的参数初始化TIM1
    TIM1_OC1PreloadConfig(TIM_OCPreload_Enable); //使能TIM1在CCR1上的预装载寄存器
		
		
   
//		TIM_OCInitStructure.TIM1_OCMode = TIM1_OCMode_PWM1;
//		TIM_OCInitStructure.TIM1_OutputState = TIM1_OutputState_Enable;
//		TIM_OCInitStructure.TIM1_OutputNState = TIM1_OutputNState_Enable;
//		TIM_OCInitStructure.TIM1_Pulse = 400;
//		TIM_OCInitStructure.TIM1_OCPolarity = TIM1_OCPolarity_Low;
//		TIM_OCInitStructure.TIM1_OCNPolarity = TIM1_OCNPolarity_Low;
//		TIM_OCInitStructure.TIM1_OCIdleState = TIM1_OCIdleState_Set;
//		TIM_OCInitStructure.TIM1_OCNIdleState = TIM1_OCIdleState_Reset;
//    TIM1_OC3Init(&TIM_OCInitStructure);
//		
//    TIM1_OC3PreloadConfig(TIM_OCPreload_Enable); //使能TIM1在CCR3上的预装载寄存器
	
		TIM1_ARRPreloadConfig(ENABLE);//使能TIM1在ARR上的预装载寄存器
		TIM1_CCxCmd(TIM1_Channel_1, ENABLE);
		TIM1_CCxNCmd(TIM1_Channel_1, ENABLE);
	
	
	
		
//		TIM1_CCxCmd(TIM1_Channel_3, ENABLE);
//		TIM1_CCxNCmd(TIM1_Channel_3, ENABLE);
    TIM1_Cmd(ENABLE);//使能定时器1   
		TIM1_CtrlPWMOutputs(ENABLE);      //PWM输出使能，与time2不同，必须打开    
    
}


void SetMotorPWM(float pwm)
{   
	  pwm=(int)pwm+1250;
		TIM1->CCR1 = pwm;	
}
