#include "reset.h"

/**********************************************************
** 函数名:All_GPIO_Config
** 功能描述: 所有的GPIO口配置放在这里
** 输入参数: 无
** 输出参数: 无
***********************************************************/
void NVIC_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;  //定义GPIO结构体	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能GPIOA、GPIOB口时钟

	//PA3配置为上拉输入，作为外部中断线3的中断输入引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//PA11
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50M时钟速度
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
}

/**********************************************************
** 函数名: NVIC_Config
** 功能描述: 中断优先级及分组配置
** 输入参数: 无
** 输出参数: 无
***********************************************************/
void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //采用组别2	 
 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQChannel;//配置外部中断3
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//占先式优先级设置为0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //副优先级设置为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//中断使能
	NVIC_Init(&NVIC_InitStructure);//中断初始化
 

}

/**********************************************************
** 函数名: EXTI_Config
** 功能描述:  外部中断配置
** 输入参数: 无
** 输出参数: 无
***********************************************************/
void EXTI_Config(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);	//PA3作为外部中断线3引脚
	EXTI_ClearITPendingBit(EXTI_Line3);	//清除3线标志位
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;	//边沿触发
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	 //根据以上参数初始化结构体

	
}



void reset_Config(void)
{
	 MotorMsg.Encoder.flag=1;
	 NVIC_GPIO_Config();
   NVIC_Config();
	 EXTI_Config(); 
}

