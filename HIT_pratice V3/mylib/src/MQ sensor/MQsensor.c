#include"stm32f10x_lib.h"		//包含所有的头文件
#include"delay.h"
#include<stdio.h>
#include"MQsensor.h"



 void sensor_GPIO_Init(void)
{
 GPIO_InitTypeDef GPIO_InitStructure;
 

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOA, &GPIO_InitStructure);
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

}

 u16 LEDtest(void)
{ 
	sensor_GPIO_Init();
  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==0)
  {
   delay_ms(1000);
	 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)==0)
	 GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	 delay_ms(1000);
	}
  else
	{
	 GPIO_ResetBits(GPIOA,GPIO_Pin_12);
	 delay_ms(1000);
	}

//  delay_ms(1500);
// } 
// else
// GPIO_ResetBits(GPIOA,GPIO_Pin_14);

}