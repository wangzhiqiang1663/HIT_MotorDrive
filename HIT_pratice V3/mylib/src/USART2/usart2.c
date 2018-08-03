#include"stm32f10x_lib.h"	
#include "delay.h"
#include "usart2.h"
#include "stdio.h"	 	 
#include "sim900a.h"	

//初始化IO 串口3
//pclk1:PCLK1时钟频率(Mhz)
//bound:波特率	  
void USART3_Init(u32 bound)
{ 	
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
  USART_ClockInitTypeDef USART_ClockInitStructure;  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	// GPIOB时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO,ENABLE);
 	USART_DeInit(USART3);  //复位串口三
	//USART2_TX   PB10
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PB10
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOB, &GPIO_InitStructure); //初始化PB10
   
  //USART3_RX	  PB11
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOB, &GPIO_InitStructure);  //初始化PB11
	
	USART_InitStructure.USART_BaudRate = bound;//一般设置为9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

	
	USART_Init(USART3, &USART_InitStructure); //初始化串口	3
	USART_Cmd(USART3, ENABLE);                    //使能串口 
	

}
//串口3
void UART3SendByte(unsigned char SendData)
{	   
		USART_SendData(USART3,SendData);
		while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);	    
} 
void UART3SendString(u8 *cmd)
{
	u16 i=0;	
	while(*(cmd+i)!=0)
	{
			UART3SendByte(*(cmd+i));i++;
	}
}

void UART3Sendshuju(u8 a[])
{
	u16 j=0;	
	while(a[j]!=0)
	{
			UART3SendByte(a[j]);j++;
	}
}
