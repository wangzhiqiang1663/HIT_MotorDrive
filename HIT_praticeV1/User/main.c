/*Include---------------------------*/
#include "stm32f10x_lib.h"		//包含所有的头文件
#include "init.h"

extern float CurrentZeroPoint;
extern int a,f;
/*******************************************************************************
* Function Name  : RCC_Configuration
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_Configuration(void)
{
	//----------使用外部RC晶振-----------
	RCC_DeInit();			//初始化为缺省值
	RCC_HSEConfig(RCC_HSE_ON);	//使能外部的高速时钟 
	while(RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);	//等待外部高速时钟使能就绪
	
	FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);	//Enable Prefetch Buffer
	FLASH_SetLatency(FLASH_Latency_2);		//Flash 2 wait state
	
	RCC_HCLKConfig(RCC_SYSCLK_Div1);		//HCLK = SYSCLK
	RCC_PCLK2Config(RCC_HCLK_Div1);			//PCLK2 =  HCLK
	RCC_PCLK1Config(RCC_HCLK_Div2);			//PCLK1 = HCLK/2
	RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);	//PLLCLK = 8MHZ * 9 =72MHZ
	RCC_PLLCmd(ENABLE);			//Enable PLLCLK

	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);	//Wait till PLLCLK is ready
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);	//Select PLL as system clock
	while(RCC_GetSYSCLKSource()!=0x08);		//Wait till PLL is used as system clock source
	
	//---------打开相应外设时钟--------------------
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO,ENABLE);	//使能APB2外设的GPIOA的时钟		 
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
//	//开启时钟
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOC,ENABLE);
}

 

//void IO_Configuration(void)
//{
//	 GPIO_InitTypeDef GPIO_InitStructure; //GPIO库函数结构体
//	
//	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//	 /* Configure USART1 Tx (PA9) as alternate function push-pull */
//	 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//PA9时钟速度50MHz
//	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //复用输出
//	 GPIO_Init(GPIOB, &GPIO_InitStructure);
//	
//}



/*******************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/ 
int  main(void)
{  
      RCC_Configuration(); //系统时钟初始化
      delay_init(72);//Delay init.
//	  IO_Configuration();
  	  all_init();
	    
	   while(1)
		 {
//         MotorMsg.Current=Get_ADC_Value();
//         SetMotorPWM(0);		
//			  GPIO_SetBits(GPIOB, GPIO_Pin_9);
//			  delay_ms(1000);
//			  GPIO_ResetBits(GPIOB, GPIO_Pin_9);
//			  delay_ms(1000);
//      ADC_SoftwareStartConvCmd(ADC1, ENABLE);	
//	    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));				
//      MotorMsg.Current=ADC_GetConversionValue(ADC1);
//			MotorMsg.Current=((MotorMsg.Current-0)*1.0f/(4096-0)*3.3-1.65)*10000;
//       debug_send_data(n[0],n[1]);
//       printf("%.3f\r\n",(MotorMsg.Encoder.Vol*5/14));	//格式化输出数据，保留三位小数，输出后换行  
//         SetMotorPWM(1000);			 
//		     printf("%.3f\r\n",23.4);
			   if(MotorMsg.Encoder.flag==1)
	       {
//					 printf("%.1f\r\n",MotorMsg.Encoder.Pos*360.0/(36864));
//					 printf("%.1f\r\n",MotorMsg.Encoder.Vol*60000*1.0/(2048*18));
//					 printf("%.3f\r\n",MotorMsg.Current);
					 printf("%f\r\n",PID_Motor_V.Expect);
					 MotorMsg.Encoder.flag=0;
					 
				 }
//			     printf("%.3f\r\n",CurrentZeroPoint);
//			   printf("你好\r\n");
//			  printf("%.3f\r\n",CurrentZeroPoint);
//	     usart1_niming_report(0XA1,n,2);
		     
//			   printf("%.3f\r\n",n[1]);	//格式化输出数据，保留三位小数，输出后换行
		    
		
		 }

	 }




