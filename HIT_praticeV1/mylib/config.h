#ifndef _config_H
#define _config_H
#endif




//# define expect 36864           //一圈产生脉冲为512*4*18=36864      1°：100个脉冲
//														 //电流单位为mA
# define expect -30		    //转速换算：一圈产生脉冲为512*4*18=36864 ： 1: 1.63					 
# define P_set 0.03
# define I_set 0        
# define D_set 0.03
# define I_MAX  500
# define O_max  100




/*
 *控制模式
 * P：位置环
 * V：速度环
 * I：电流环
 */
//#define P_V_I_CONTROL_MODE
// #define P_V_CONTROL_MODE
//#define V_I_CONTROL_MODE
//#define P_CONTROL_MODE
  #define V_CONTROL_MODE
//#define I_CONTROL_MODE

//#define MAX_VOL_OUTPUT 250
//#define MAX_CUR_OUTPUT 2  //单位：安培
//#define MAX_PWM_OUTPUT 4900



