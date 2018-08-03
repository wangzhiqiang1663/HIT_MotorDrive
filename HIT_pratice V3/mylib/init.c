# include"init.h"


void all_init(void)
{
	    MotorMsg_InitConfig();
	    KalmanfilterInit();
	    PID_InitConfig();
	
      TIM1_Config();
	    Usart_Configuration();//串口初始化配置
	    Encoder_InitConfig();
	    ADC1_Config();
	
	    SetMotorPWM(0);
	    CurrentZeroPointConfirm();
     
	    /*********  寻零过程   *********/
//	    while(!MotorMsg.Encoder.flag)
//			{
//			SetMotorPWM(750);
//			}
			
	    TIM3_Start();
	    MotorMsg.Encoder.flag=0;
	    
}
