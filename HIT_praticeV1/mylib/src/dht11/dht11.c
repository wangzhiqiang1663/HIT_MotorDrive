#include"stm32f10x_lib.h"
#include "delay.h" 

#include "QDTFT_demo.h"
#include "Lcd_Driver.h"
#include "GUI.h"




#define DHT11_High GPIO_SetBits(GPIOA,GPIO_Pin_5);
#define DHT11_Low GPIO_ResetBits(GPIOA,GPIO_Pin_5);
#define number 50;
#define outpin GPIO_Pin_5;

static void DHT11_IN_Init(void)
{
GPIO_InitTypeDef GPIO_InitStructure;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
/* 设置端口为输入模式 */
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
GPIO_Init(GPIOA, &GPIO_InitStructure);
GPIO_SetBits(GPIOA,GPIO_Pin_5);
}
/**
* 设置端口为输出模式
*/
static void DHT11_OUT_Init(void)
{
GPIO_InitTypeDef GPIO_InitStructure;
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_Init(GPIOA, &GPIO_InitStructure);
GPIO_SetBits(GPIOA,GPIO_Pin_5);
}
static void DHT11_Rst(void)
{
DHT11_OUT_Init(); //变PA1为输出模式
DHT11_Low;       
delay_ms(19); //保证时间大于18ms
DHT11_High; // 主机发送信号结束
delay_us(30);  //延时20-40us
DHT11_IN_Init();   //准备接受信号

}

static u16 DHT11_Check(void)
{ 
 u8 retry=0;
 DHT11_IN_Init;
 while ((GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5))==1&&retry<100)
 {
 retry++;
 delay_us(1);
 };
 if(retry>=100) return 1;
 else retry=0;
 while ((GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)&&retry<100)
 {
 retry++;
 delay_us(1);
 };
 if(retry>=100) return 1;    
 return 0;
 }

static u16 DHT11_Read_Bit(void)
{ 
	u8 retry=0;
  while ((GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==1)&&retry<100)
 {
 retry++;
 delay_us(1);
 }
 retry=0;
  while ((GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==0)&&retry<100)
 {
 retry++;
 delay_us(1);
 }
 delay_us(40);//??40us
 if((GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5))==1)
 return 1;
 else 
 return 0;   
//	u16 PAin;
//	DHT11_IN_Init(); 
//  PAin=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5);
//  while(!PAin); //等待高电平
//  delay_us(40);
//  if(PAin == 1)
//  {
//  while(PAin); //判断高电平是否结束
//  return 1;
//  }
// else return 0;
}
/**
* @brief ? DHT11 ??????
*/
static u16 DHT11_Read_Byte(void)
{
 u16 i;
 u16 Data = 0;
 for(i=0;i<8;i++)
 {
 Data <<= 1;
 Data |= DHT11_Read_Bit();
 }
 return Data;
 }
/**
* @brief ? DHT11 ?? 8 ????
*/
  void DHT11_Read_Data()
 {
	char check[] = "Device Not Available\n";
  char errordata[] = "Error Data\n";
  u16 Data_Buff[5];
	u16 i = 0;
	
 
  DHT11_Rst();
	

  if (DHT11_Check() == 0) //检测低电平时说明开始响应
  {
	  DHT11_IN_Init();
	 
   for (i = 0; i < 5; i++)
  {
   Data_Buff[i] = DHT11_Read_Byte();
  }
	 

   if ((Data_Buff[0]+Data_Buff[1]+Data_Buff[2]+Data_Buff[3]) == Data_Buff[4])
  {
   
   Gui_DrawFont_GBK16(20,10,RED,GRAY0,"shidu:");
   Gui_DrawFont_Num32(80,10,RED,GRAY0,Data_Buff[0]/100);
   Gui_DrawFont_Num32(110,10,RED,GRAY0,Data_Buff[0]%100/10);
	 Gui_DrawFont_Num32(140,10,RED,GRAY0,Data_Buff[0]%10);
//   Gui_DrawFont_Num32(20,50,RED,GRAY0,Data_Buff[1]/100);
//	 Gui_DrawFont_Num32(50,50,RED,GRAY0,Data_Buff[1]%100/10);
//	 Gui_DrawFont_Num32(80,50,RED,GRAY0,Data_Buff[1]%10);
   Gui_DrawFont_Num32(80,80,RED,GRAY0,Data_Buff[2]/100);
	 Gui_DrawFont_Num32(110,80,RED,GRAY0,Data_Buff[2]%100/10);
	 Gui_DrawFont_Num32(140,80,RED,GRAY0,Data_Buff[2]%10);
		
//   Gui_DrawFont_Num32(20,120,RED,GRAY0,Data_Buff[3]/100);
//	 Gui_DrawFont_Num32(50,120,RED,GRAY0,Data_Buff[3]%100/10);
//	 Gui_DrawFont_Num32(80,120,RED,GRAY0,Data_Buff[3]%10);
//	 Gui_DrawFont_Num32(20,160,RED,GRAY0,Data_Buff[4]/100);
//	 Gui_DrawFont_Num32(50,160,RED,GRAY0,Data_Buff[4]%100/10);
//	 Gui_DrawFont_Num32(80,160,RED,GRAY0,Data_Buff[4]%10);
//	
//	 Gui_DrawFont_Num32(16,120,RED,GRAY0,Data_Buff[0]);

//	 Gui_DrawFont_Num32(16,40,RED,GRAY0,Data_Buff[2]);
   Gui_DrawFont_GBK16(20,80,BLUE,GRAY0,"wendu");
	 
	

 } else 
   {
    Gui_DrawFont_GBK16(16,0,BLUE,GRAY0,"aaaaa");
   }
  } else
   {
    Gui_DrawFont_GBK16(64,2,BLUE,GRAY0,"Error Data");
   }
}
