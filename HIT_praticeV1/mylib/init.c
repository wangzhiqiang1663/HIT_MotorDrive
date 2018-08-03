# include"init.h"


void all_init(void)
{
      TIM1_Config();
	    Usart_Configuration();//串口初始化配置
	
	    ADC1_Config();
	    CurrentZeroPointConfirm();
      
	    /*********  寻零过程   *********/
//	    reset_Config();
//	    while(!MotorMsg.Encoder.flag)
//			{
//			SetMotorPWM(750);
//			}
			SetMotorPWM(0);
	    Encoder_InitConfig();
	    TIM3_Start();
	    PID_InitConfig();
	    MotorMsg_InitConfig();
	    MotorMsg.Encoder.flag=0;
}
