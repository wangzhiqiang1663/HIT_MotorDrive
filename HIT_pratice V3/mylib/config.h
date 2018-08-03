#ifndef _config_H
#define _config_H
#endif




# define expect -36864       //一圈产生脉冲为512*4*18=36864      1°：100个脉冲
                            //512*4*16=367680
										        //电流单位为mA
//  # define expect 40 // 由于采样周期是4K,则此时的一个脉冲信号为   4000*60/36864=6.5,即1:6.5r/min
//# define expect 40
//# define P_set 10
//# define I_set 0.2       
//# define D_set 0
//# define I_MAX 5000
//# define O_max  2400




/*
 *控制模式
 * P：位置环
 * V：速度环
 * I：电流环
// */
//#define P_V_I_CONTROL_MODE
//#define P_V_CONTROL_MODE
#define P_I_CONTROL_MODE
//#define V_I_CONTROL_MODE 
//#define P_CONTROL_MODE
//#define V_CONTROL_MODE
//#define I_CONTROL_MODE

//#define MAX_VOL_OUTPUT 250
//#define MAX_CUR_OUTPUT 2  //单位：安培
//#define MAX_PWM_OUTPUT 4900



