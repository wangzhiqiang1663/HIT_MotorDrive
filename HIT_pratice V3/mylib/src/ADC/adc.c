#include"adc.h"		//包含所有的头文件


/**********************************************************
** 函数名: ADC1__Config
** 功能描述: ADC1的DMA方式配置
** 输入参数: 无
** 输出参数: 无
***********************************************************/
void ADC1_Config(void)
{
  ADC_InitTypeDef ADC_InitStructure;//定义ADC结构体
  
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_ADCCLKConfig(RCC_PCLK2_Div6);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1, ENABLE );	  //使能ADC1通道时钟
	ADC_DeInit(ADC1);
  
  /*作为ADC1的6通道模拟输入的GPIO初始化配置*/
  //PA2,3,4,5,6,7配置为模拟输入
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//模拟输入
  GPIO_Init(GPIOA, &GPIO_InitStructure);

 
  
  /*下面为ADC1的配置*/
  ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;//ADC1工作在独立模式
  ADC_InitStructure.ADC_ScanConvMode = DISABLE;//模数转换工作在单通道
  ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;//模数转换工作在单次扫描
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;//转换由软件而不是外部触发启动
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;//ADC数据右对齐
  ADC_InitStructure.ADC_NbrOfChannel = 1;//转换的ADC通道的数目为1
  ADC_Init(ADC1, &ADC_InitStructure);//要把以下参数初始化ADC_InitStructure

  /* 设置ADC1的1个规则组通道，设置它们的转化顺序和采样时间*/ 
  //转换时间Tconv=采样时间+12.5个周期
  ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_7Cycles5); //ADC1通道2转换顺序为1，采样时间为7.5个周期 
 
  
 /* 使能 ADC1 */
	ADC_Cmd(ADC1, ENABLE);
	/* 复位 ADC1 的校准寄存器 */   
	ADC_ResetCalibration(ADC1);
	/* 等待 ADC1 校准寄存器复位完成 */
	while(ADC_GetResetCalibrationStatus(ADC1));
	/* 开始 ADC1 校准 */
	ADC_StartCalibration(ADC1);
	/* 等待 ADC1 校准完成 */
	while(ADC_GetCalibrationStatus(ADC1));
	/* 启动 ADC1 转换 */ 
  ADC_ClearFlag(ADC1,ADC_FLAG_EOC); 
}



u16 Get_ADC_Value(void)
{
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1,ADC_SampleTime_7Cycles5); //ADC1通道2转换顺序为1，采样时间为7.5个周期 		  			   
	ADC_Cmd(ADC1, ENABLE);			 
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//等待转换结束
  ADC_ClearFlag(ADC1,ADC_FLAG_EOC); 
  return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果
}

/*确定电流零点*/
float CurrentZeroPoint;
void CurrentZeroPointConfirm(void)
{
	u16 i;
	float sum = 0;
		for (i = 0; i <10000;i++)
	{
		kalmanfilter((Get_ADC_Value()*1.0f/4096*3.3));
	}
	
	CurrentZeroPoint = sum / 52000.f;
	for (i = 0; i <3000;i++)
	{
		sum +=kalmanfilter((Get_ADC_Value()*1.0f/4096*3.3));
	}
	
	CurrentZeroPoint = sum / 3000.f;
//	CurrentZeroPoint=kalmanfilter((Get_ADC_Value()*1.0f/4096*3.3));
}

///*电流均值滤波*/
//float CurrentFitlter(float current)
//{
//	static float current_buff[5] = {0};
//	float sum = 0;
//	u8 i;
//	
//	for ( i = 0;i < 3;i++)
//	{
//		current_buff[i] = current_buff[i+1];
//	}
//	current_buff[3] = current;
//	
//	for ( i = 0;i < 4;i++)
//	{
//		sum += current_buff[i];
//	}
//	
//	return sum / 4.0f;
//	
//}

/*
	mode 取0 返回adc采样结果
			 取1 返回实际电流值 单位：毫安
*/
float Get_Current(u8 mode)
{
	float tmp;
	
//	  tmp = Get_ADC_Value();	
////  tmp = Get_ADC_Value();	
//	  tmp = (Get_ADC_Value()*1.0f/(4096-0))*3.3;	
//	    tmp=(Get_ADC_Value()*1.0f/(4096-0))*3.3;
    tmp = kalmanfilter((Get_ADC_Value()*1.0f/(4096-0))*3.3)-CurrentZeroPoint;	
	
	if (mode==1)
	{
		tmp = tmp*1000.f/0.1;
//		  tmp = kalmanfilter((Get_ADC_Value()*1.0f/(4096-0))*3.3);	
	}
	
		
	return (float)tmp;
}


