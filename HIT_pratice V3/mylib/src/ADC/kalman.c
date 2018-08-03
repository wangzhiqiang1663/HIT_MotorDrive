# include "kalman.h"

 KalmanType Kalman;


 void KalmanfilterInit(void)
 {
	 Kalman.Q=1e-8;
	 Kalman.R=5.95e-5;
	 
	 Kalman.A=1;
	 Kalman.B=0;
	 Kalman.H=1;
	 
	 Kalman.X_estimate=0;
	 Kalman.P_estimate=0;
	 Kalman.P_forecast=0;
	 Kalman.X_forecast=0;
	 
	 Kalman.K=0;
	 Kalman.I=1;
 }
	
 float kalmanfilter(float x)
 {
   float y;
	 y=x;
	 //1.获得预测值以及预测值与真实值之间的误差协方差矩阵
	 Kalman.X_forecast=Kalman.A*Kalman.X_estimate+Kalman.B;
	 Kalman.P_forecast=Kalman.P_estimate+Kalman.Q;
	 
	 //2.测量更新过程，计算卡尔曼增益获得估计值
	 Kalman.K=Kalman.P_forecast/(Kalman.P_forecast+Kalman.R);
	 Kalman.X_estimate=Kalman.X_forecast+Kalman.K*(y-Kalman.X_forecast);
	 
	 //3.计算真实值与估计值之间的协方差矩阵以便下次使用
	 Kalman.P_estimate=(Kalman.I-Kalman.H*Kalman.K)*Kalman.P_forecast;
	 
	 return Kalman.X_estimate;
	 
 } 
 
 
 
 
 