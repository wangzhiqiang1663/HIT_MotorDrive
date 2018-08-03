# include"stm32f10x_lib.h"
# include"usart.h"
# include<stdio.h>

//void usart_Configuration(void)
//{
//	 GPIO_InitTypeDef GPIO_InitStructure; //GPIO库函数结构体
//	 USART_InitTypeDef USART_InitStructure;//USART库函数结构体
//	 USART_ClockInitTypeDef USART_ClockInitStructure;
//	 //使能串口1，GPIOA，AFIO总线
//	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO|RCC_APB2Periph_USART1,ENABLE);
//	 /* Configure USART1 Tx (PA9) as alternate function push-pull */
//	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//PA9时钟速度50MHz
//	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用输出
//	 GPIO_Init(GPIOA, &GPIO_InitStructure);
//	 /* Configure USART1 Rx (PA10) as input floating */
//	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	//上拉输入
//	 GPIO_Init(GPIOA, &GPIO_InitStructure);
//	 
//	 USART_InitStructure.USART_BaudRate =9600; //波特率9600
//	 USART_InitStructure.USART_WordLength = USART_WordLength_8b; //8位数据
//	 USART_InitStructure.USART_StopBits = USART_StopBits_1; //1个停止位
//	 USART_InitStructure.USART_Parity = USART_Parity_No; //奇偶失能
//	 USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //硬件流控制失能
//	 USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //发送、接收使能
//	
//	 USART_ClockInitStructure.USART_Clock = USART_Clock_Disable;
//	 USART_ClockInitStructure.USART_CPOL = USART_CPOL_Low;//空闲时钟为低电平
//	 USART_ClockInitStructure.USART_CPHA = USART_CPHA_1Edge;//时钟第一个边沿进行数据捕获
//	 USART_ClockInitStructure.USART_LastBit = USART_LastBit_Disable;//最后一位数据的时钟脉冲不从SCLK输出
//	
//	 USART_ClockInit(USART1, &USART_ClockInitStructure);
//	 USART_Init(USART1, &USART_InitStructure);	//初始化结构体
//	
//	 USART_Cmd(USART1, ENABLE); //使能串口1	
//}



///*******************************************************************************
//* Function Name  : GPIO_Configuration
//* Description    : 初始化GPIO外设
//* Input          : None
//* Output         : None
//* Return         : None
//*******************************************************************************/
//void GPIO_Configuration(void)
// { //GPIO_InitTypeDef GPIO_InitStructure;

////  /* Configure USARTx_Tx as alternate function push-pull */
////  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
////  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
////  GPIO_Init(GPIOA, &GPIO_InitStructure);

////  /* Configure USARTx_Rx as input floating */
////  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
////  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
////  GPIO_Init(GPIOA, &GPIO_InitStructure);
////	GPIO_InitTypeDef GPIO_InitStructure;  //定义GPIO结构体	
////	/*允许总线CLOCK,在使用GPIO之前必须允许相应端的时钟.
////	从STM32的设计角度上说,没被允许的端将不接入时钟,也就不会耗能,
////	这是STM32节能的一种技巧,*/
//////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能GPIOA口时钟
////	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);//使能GPIOB口时钟

////	/* PA1,2输出*/
//////	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2; //PA1,PA2配置
//////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//推挽输出
//////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50M时钟速度
//////	GPIO_Init(GPIOA, &GPIO_InitStructure); //根据以上参数初始化结构体
//////	
////	/*PB1,输出*/
////	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//PB1
////	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//推挽输出
////	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50M时钟速度
////	GPIO_Init(GPIOB, &GPIO_InitStructure);
//} 

///**********************************************************
//** 函数名:u32tostr
//** 功能描述: 将一个32位的变量dat转为字符串，比如把1234转为"1234"
//** 输入参数: dat:带转的long型的变量
//             str:指向字符数组的指针，转换后的字节串放在其中 
//** 输出参数: 无
//***********************************************************/
//void u32tostr(unsigned long dat,char *str) 
//{
//	char temp[20];
//	unsigned char i=0,j=0;
//	i=0;
//	while(dat)
//	{
//		temp[i]=dat%10+0x30;
//		i++;
//		dat/=10;
//	}
//	j=i;
//	for(i=0;i<j;i++)
//	{
//	  	str[i]=temp[j-i-1];
//	}
//	if(!i) {str[i++]='0';}
//	str[i]=0;
//}

///**********************************************************
//** 函数名:USART1_Putc
//** 功能描述: 串口1发送一字符
//** 输入参数: c
//** 输出参数: 无
//***********************************************************/
//void USART1_Putc(unsigned char c)
//{
//    USART1->DR = (u8)c; //要发送的字符赋给串口数据寄存器  
//	while((USART1->SR&0X40)==0); //等待发送完成  
//}
///**********************************************************
//** 函数名:USART1_Puts
//** 功能描述: 串口1发送一字符串
//** 输入参数: 指针str
//** 输出参数: 无
//***********************************************************/
//void USART1_Puts(char * str)
//{
//    while(*str)
//    {
//        USART1->DR= *str++;
//		while((USART1->SR&0X40)==0);//等待发送完成  
//    }
//}
///**********************************************************
//** 函数名:UART_Send_Enter
//** 功能描述: 串口1发送一换行符
//** 输入参数: 无
//** 输出参数: 无
//***********************************************************/
//void UART_Send_Enter(void)
//{
//	USART1_Putc(0x0d);
//	USART1_Putc(0x0a);
//}
///**********************************************************
//** 函数名:UART_Send_Str
//** 功能描述: 串口1发送一字符串，带回车换行功能
//** 输入参数: 指针s
//** 输出参数: 无
//***********************************************************/
//void UART_Send_Str(char *s)
//{
// 
// 	for(;*s;s++)
// 	{
//	 	if(*s=='\n') 
//	  		UART_Send_Enter();
//	 	else
//	  		USART1_Putc(*s);
// 	}
//}
