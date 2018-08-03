#include"stm32f10x_lib.h"	
#include "delay.h"
#include "sim900a.h"
#include "math.h"
#include "stdio.h"
#include "stm32f10x_usart.h"
#include "usart2.h"

u32 RxBuffer3[100];
u32 RecLen3=0;
char wendu[]="00350030";
char shidu[]="00340030";
char cishu[]="0030";
char cishu1[]="00300030";


void sim900a_Init(void)
{

  USART3_Init(115200);
  
  UART3SendString("AT\n");
  delay_ms(500);
 
//  for(i=0;i<RecLen3;i++)
// {
////	GPIO_SetBits(GPIOA,GPIO_Pin_6); 
////	delay_ms(1000);
//  if((RxBuffer3[i]=='O')/*&&(RxBuffer3[i+1]=='K')*/)
//  { 
//   GPIO_SetBits(GPIOA,GPIO_Pin_6); 
//   delay_ms(1000);
//  }
// }
   UART3SendString("AT+CMGF=1\r");
	 delay_ms(500);
   UART3SendString("AT+CSCS=\"UCS2\"\r");
   delay_ms(500);
   UART3SendString("AT+CMGS=\"00310038003400330034003300350031003700370035\"\r");
   delay_ms(500);
   UART3SendString("672C6B216D4B8BD5662F4E3A4E865B9E9A8C77ED4FE163A5653630025BA451856E295EA64E3A");
   UART3SendString(wendu);
//   USART_SendData(USART3,0x30);
//	 while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
	 UART3SendString("64446C0F5EA6FF0C6E7F5EA64E3A"); 
   UART3SendString(shidu);	 
   //USART_SendData(USART3,shidu);
//	 while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
	 UART3SendString("0025FF0C5DF27ECF5582517B");
   UART3SendString(cishu);		 
  // USART_SendData(USART3,cishu);
//	 while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
	 UART3SendString("6B21FF0C5BA072696D3B52A86B635E38"); 
   delay_ms(500);
   USART_SendData(USART3,0x1A);
	 while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
//   if(USART_GetFlagStatus(USART3,USART_FLAG_RXNE)==SET) 
//  {
//	
////  RxBuffer3[RecLen3++]=USART_ReceiveData(USART3);   
//   GPIO_SetBits(GPIOA,GPIO_Pin_6); 
//   delay_ms(1000);
//	 delay_ms(1000);
//	 delay_ms(1000);
//  }
}