#ifndef _KALMAN_H
#define _KALMAN_H



typedef struct
 {
	 //1.噪声方差
	 float Q;   //假设过程噪声方差
	 float R;   //测量过程中噪声方差估计
	 
   //2.系统参数设置
	 int A;
	 int B;
	 int H;
	
	 //3.后验估计以及先验估计
	 float X_forecast;
	 float P_forecast;
	 float X_estimate;
	 float P_estimate;
	 
	 //4.计算参数设置
	 float K;
	 float I;
 }KalmanType;
 
 void KalmanfilterInit(void);
 float kalmanfilter(float x);
 
#endif
 
 
 
 
 


 
 
 
 