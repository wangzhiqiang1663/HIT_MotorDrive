/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_tim.h
* Author             : MCD Application Team
* Version            : V2.0
* Date               : 05/23/2008
* Description        : This file contains all the functions prototypes for the 
*                      TIM firmware library.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
* FOR MORE INFORMATION PLEASE CAREFULLY READ THE LICENSE AGREEMENT FILE LOCATED 
* IN THE ROOT DIRECTORY OF THIS FIRMWARE PACKAGE.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_TIM_H
#define __STM32F10x_TIM_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_map.h"

/* Exported types ------------------------------------------------------------*/

/* TIM Time Base Init structure definition */
typedef struct
{
 /* Set the Prescaler value */
//  TIMx->PSC = TIM_TimeBaseInitStruct->TIM_Prescaler;
  u16 TIM_Prescaler;	// 设置了用来作为TIMx时钟频率除数的预分频值。 
  u16 TIM_CounterMode;	// 选择了计数器模式。
  /*Set the Autoreload value*/ 	
 // TIMx->ARR = TIM_TimeBaseInitStruct->TIM_Period ; //	   自动重装载寄存器(TIMx_ARR)
 //ARR[15:0]: 自动重装载的值
//ARR是将要装载入实际的自动重装载寄存器的数值。	详细参考13.4.1：时基单元有关ARR的更新和动作。

  u16 TIM_Period;  // 设置了在下一个更新事件装入活动的自动重装载寄存器周期的值 ;	                          
  u16 TIM_ClockDivision;  // 设置了时钟分割。
  u8 TIM_RepetitionCounter;	// 设置了周期计数器值。
} TIM_TimeBaseInitTypeDef;

/* TIM Output Compare Init structure definition */
typedef struct
{
  u16 TIM_OCMode;  // 选择定时器模式。
  u16 TIM_OutputState;	// 选择输出比较状态。
  u16 TIM_OutputNState;	//	选择互补输出比较状态。
  u16 TIM_Pulse;  // 设置了待装入捕获比较寄存器的脉冲值。
  u16 TIM_OCPolarity;  // 输出极性。
  u16 TIM_OCNPolarity; // 互补输出极性 ；
  u16 TIM_OCIdleState; // 选择空闲状态下的非工作状态 ；
  u16 TIM_OCNIdleState; // 选择空闲状态下的非工作状态 ；

  u16 TIM_Channel;	// 选择通道 ；
} TIM_OCInitTypeDef;

/* TIM Input Capture Init structure definition */
typedef struct
{
  u16 TIM_Channel;	// 选择通道 ；
  u16 TIM_ICPolarity;  // 输入活动沿。
  u16 TIM_ICSelection; // 选择输入 ；
  u16 TIM_ICPrescaler; // 设置输入捕获预分频器。 ；
  u16 TIM_ICFilter;	 // 选择输入比较滤波器 ；
} TIM_ICInitTypeDef;

/* BDTR structure definition */
typedef struct
{
  u16 TIM_OSSRState; // 设置在运行模式下非工作状态选项 ；
  u16 TIM_OSSIState; // 设置在运行模式下非工作状态选项 ；
  u16 TIM_LOCKLevel; // 设置了锁电平参数 ；
  u16 TIM_DeadTime;	 // 指定了输出打开和关闭状态之间的延时。
  u16 TIM_Break;	// 使能或者失能TIM1刹车输入。
  u16 TIM_BreakPolarity; // 设置TIM1刹车输入管脚极性。
  u16 TIM_AutomaticOutput; // 使能或者失能自动输出功能该参数取值 ；
} TIM_BDTRInitTypeDef;

/* Exported constants --------------------------------------------------------*/                             

#define IS_TIM_ALL_PERIPH(PERIPH) (((*(u32*)&(PERIPH)) == TIM1_BASE) || \
                                   ((*(u32*)&(PERIPH)) == TIM2_BASE) || \
                                   ((*(u32*)&(PERIPH)) == TIM3_BASE) || \
                                   ((*(u32*)&(PERIPH)) == TIM4_BASE) || \
                                   ((*(u32*)&(PERIPH)) == TIM5_BASE) || \
                                   ((*(u32*)&(PERIPH)) == TIM6_BASE) || \
                                   ((*(u32*)&(PERIPH)) == TIM7_BASE) || \
                                   ((*(u32*)&(PERIPH)) == TIM8_BASE))

#define IS_TIM_18_PERIPH(PERIPH) (((*(u32*)&(PERIPH)) == TIM1_BASE) || \
                                  ((*(u32*)&(PERIPH)) == TIM8_BASE))

#define IS_TIM_123458_PERIPH(PERIPH) (((*(u32*)&(PERIPH)) == TIM1_BASE) || \
                                      ((*(u32*)&(PERIPH)) == TIM2_BASE) || \
                                      ((*(u32*)&(PERIPH)) == TIM3_BASE) || \
                                      ((*(u32*)&(PERIPH)) == TIM4_BASE) || \
                                      ((*(u32*)&(PERIPH)) == TIM5_BASE) || \
                                      ((*(u32*)&(PERIPH)) == TIM8_BASE))

/* TIM Output Compare and PWM modes -----------------------------------------*/
//位6:4  0C1M[2:0]：输出比较1模式  
#define TIM_OCMode_Timing                  ((u16)0x0000)    // TIM输出比较时间模式 ；
#define TIM_OCMode_Active                  ((u16)0x0010)    // TIM输出比较主动模式 ；
//1(TIMx_CCR1)相同时，强制OC1REF为高。

#define TIM_OCMode_Inactive                ((u16)0x0020)   // TIM输出比较非主动模式 ；
#define TIM_OCMode_Toggle                  ((u16)0x0030)   // TIM输出比较触发模式 ；
#define TIM_OCMode_PWM1                    ((u16)0x0060)   // TIM脉冲宽度调制模式1 ；
#define TIM_OCMode_PWM2                    ((u16)0x0070)   // TIM脉冲宽度调制模式2 ；

#define IS_TIM_OC_MODE(MODE) (((MODE) == TIM_OCMode_Timing) || \
                              ((MODE) == TIM_OCMode_Active) || \
                              ((MODE) == TIM_OCMode_Inactive) || \
                              ((MODE) == TIM_OCMode_Toggle)|| \
                              ((MODE) == TIM_OCMode_PWM1) || \
                              ((MODE) == TIM_OCMode_PWM2))

#define IS_TIM_OCM(MODE) (((MODE) == TIM_OCMode_Timing) || \
                          ((MODE) == TIM_OCMode_Active) || \
                          ((MODE) == TIM_OCMode_Inactive) || \
                          ((MODE) == TIM_OCMode_Toggle)|| \
                          ((MODE) == TIM_OCMode_PWM1) || \
                          ((MODE) == TIM_OCMode_PWM2) ||	\
                          ((MODE) == TIM_ForcedAction_Active) || \
                          ((MODE) == TIM_ForcedAction_InActive))
/* TIM One Pulse Mode -------------------------------------------------------*/
#define TIM_OPMode_Single                  ((u16)0x0008) //	生成单一的脉冲：计数器在下一个更新事件停止 ;
#define TIM_OPMode_Repetitive              ((u16)0x0000) //	生成重复的脉冲：在更新事件时计数器不停止 ;

#define IS_TIM_OPM_MODE(MODE) (((MODE) == TIM_OPMode_Single) || \
                               ((MODE) == TIM_OPMode_Repetitive))

/* TIM Channel -------------------------------------------------------------*/
#define TIM_Channel_1                      ((u16)0x0000) // 使用TIM通道1 ；
#define TIM_Channel_2                      ((u16)0x0004) // 使用TIM通道2 ；
#define TIM_Channel_3                      ((u16)0x0008) // 使用TIM通道3 ；
#define TIM_Channel_4                      ((u16)0x000C) // 使用TIM通道4 ；

#define IS_TIM_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
                                 ((CHANNEL) == TIM_Channel_2) || \
                                 ((CHANNEL) == TIM_Channel_3) || \
                                 ((CHANNEL) == TIM_Channel_4))

#define IS_TIM_PWMI_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
                                      ((CHANNEL) == TIM_Channel_2))

#define IS_TIM_COMPLEMENTARY_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
                                               ((CHANNEL) == TIM_Channel_2) || \
                                               ((CHANNEL) == TIM_Channel_3))
/* TIM Clock Division CKD --------------------------------------------------*/
#define TIM_CKD_DIV1                       ((u16)0x0000) // TDTS = Tck_TIM ；
#define TIM_CKD_DIV2                       ((u16)0x0100) // TDTS = Tck_2TIM ；
#define TIM_CKD_DIV4                       ((u16)0x0200) // TDTS = Tck_4TIM ；

#define IS_TIM_CKD_DIV(DIV) (((DIV) == TIM_CKD_DIV1) || \
                             ((DIV) == TIM_CKD_DIV2) || \
                             ((DIV) == TIM_CKD_DIV4))

/* TIM Counter Mode --------------------------------------------------------*/
#define TIM_CounterMode_Up                 ((u16)0x0000) // TIM向上计数模式 ;
#define TIM_CounterMode_Down               ((u16)0x0010) // TIM向下计数模式 ；
#define TIM_CounterMode_CenterAligned1     ((u16)0x0020) //	TIM中央对齐模式1计数模式 ；
#define TIM_CounterMode_CenterAligned2     ((u16)0x0040) //	TIM中央对齐模式2计数模式 ；
#define TIM_CounterMode_CenterAligned3     ((u16)0x0060) //	TIM中央对齐模式3计数模式 ；

#define IS_TIM_COUNTER_MODE(MODE) (((MODE) == TIM_CounterMode_Up) ||  \
                                   ((MODE) == TIM_CounterMode_Down) || \
                                   ((MODE) == TIM_CounterMode_CenterAligned1) || \
                                   ((MODE) == TIM_CounterMode_CenterAligned2) || \
                                   ((MODE) == TIM_CounterMode_CenterAligned3))

/* TIM Output Compare Polarity ---------------------------------------------*/
#define TIM_OCPolarity_High                ((u16)0x0000) // TIM输出比较极性高 ；
#define TIM_OCPolarity_Low                 ((u16)0x0002) // TIM输出比较极性低 ；

#define IS_TIM_OC_POLARITY(POLARITY) (((POLARITY) == TIM_OCPolarity_High) || \
                                      ((POLARITY) == TIM_OCPolarity_Low))

/* TIM Output Compare N Polarity -------------------------------------------*/
#define TIM_OCNPolarity_High               ((u16)0x0000) //	TIM输出比较N极性高 ；
#define TIM_OCNPolarity_Low                ((u16)0x0008) //	TIM输出比较N极性低 ；

#define IS_TIM_OCN_POLARITY(POLARITY) (((POLARITY) == TIM_OCNPolarity_High) || \
                                       ((POLARITY) == TIM_OCNPolarity_Low))

/* TIM Output Compare states -----------------------------------------------*/
#define TIM_OutputState_Disable            ((u16)0x0000) // 失能输出比较状态 ；
#define TIM_OutputState_Enable             ((u16)0x0001) // 使能输出比较状态 ；

#define IS_TIM_OUTPUT_STATE(STATE) (((STATE) == TIM_OutputState_Disable) || \
                                    ((STATE) == TIM_OutputState_Enable))

/* TIM Output Compare N States ---------------------------------------------*/
#define TIM_OutputNState_Disable           ((u16)0x0000) //	失能输出比较N状态 ；
#define TIM_OutputNState_Enable            ((u16)0x0004) //	使能输出比较N状态 ；

#define IS_TIM_OUTPUTN_STATE(STATE) (((STATE) == TIM_OutputNState_Disable) || \
                                     ((STATE) == TIM_OutputNState_Enable))

/* TIM Capture Compare States -----------------------------------------------*/
#define TIM_CCx_Enable                      ((u16)0x0001)
#define TIM_CCx_Disable                     ((u16)0x0000)

#define IS_TIM_CCX(CCX) (((CCX) == TIM_CCx_Enable) || \
                         ((CCX) == TIM_CCx_Disable))

/* TIM Capture Compare N States --------------------------------------------*/
#define TIM_CCxN_Enable                     ((u16)0x0004)
#define TIM_CCxN_Disable                    ((u16)0x0000)                                     

#define IS_TIM_CCXN(CCXN) (((CCXN) == TIM_CCxN_Enable) || \
                           ((CCXN) == TIM_CCxN_Disable))

/* Break Input enable/disable -----------------------------------------------*/
#define TIM_Break_Enable                   ((u16)0x1000) // 使能TIM刹车输入 ；
#define TIM_Break_Disable                  ((u16)0x0000) // 失能TIM刹车输入 ；

#define IS_TIM_BREAK_STATE(STATE) (((STATE) == TIM_Break_Enable) || \
                                   ((STATE) == TIM_Break_Disable))

/* Break Polarity -----------------------------------------------------------*/
#define TIM_BreakPolarity_Low              ((u16)0x0000) // TIM刹车输入管脚极性低 ；
#define TIM_BreakPolarity_High             ((u16)0x2000) // TIM刹车输入管脚极性高 ；

#define IS_TIM_BREAK_POLARITY(POLARITY) (((POLARITY) == TIM_BreakPolarity_Low) || \
                                         ((POLARITY) == TIM_BreakPolarity_High))

/* TIM AOE Bit Set/Reset ---------------------------------------------------*/
#define TIM_AutomaticOutput_Enable         ((u16)0x4000) // 自动输出功能使能 ； 
#define TIM_AutomaticOutput_Disable        ((u16)0x0000) // 自动输出功能失能 ；

#define IS_TIM_AUTOMATIC_OUTPUT_STATE(STATE) (((STATE) == TIM_AutomaticOutput_Enable) || \
                                              ((STATE) == TIM_AutomaticOutput_Disable))
/* Lock levels --------------------------------------------------------------*/
#define TIM_LOCKLevel_OFF                  ((u16)0x0000) // 不锁任何位 ；
#define TIM_LOCKLevel_1                    ((u16)0x0100) //	使用锁电平1 ；
#define TIM_LOCKLevel_2                    ((u16)0x0200) //	使用锁电平2 ；
#define TIM_LOCKLevel_3                    ((u16)0x0300) //	使用锁电平3 ；

#define IS_TIM_LOCK_LEVEL(LEVEL) (((LEVEL) == TIM_LOCKLevel_OFF) || \
                                  ((LEVEL) == TIM_LOCKLevel_1) || \
                                  ((LEVEL) == TIM_LOCKLevel_2) || \
                                  ((LEVEL) == TIM_LOCKLevel_3))

/* OSSI: Off-State Selection for Idle mode states ---------------------------*/
#define TIM_OSSIState_Enable               ((u16)0x0400) // 使能TIM OSSI状态 ；
#define TIM_OSSIState_Disable              ((u16)0x0000) // 失能TIM OSSI状态 ；

#define IS_TIM_OSSI_STATE(STATE) (((STATE) == TIM_OSSIState_Enable) || \
                                  ((STATE) == TIM_OSSIState_Disable))

/* OSSR: Off-State Selection for Run mode states ----------------------------*/
#define TIM_OSSRState_Enable               ((u16)0x0800) // 使能TIM OSSR状态 ；
#define TIM_OSSRState_Disable              ((u16)0x0000) // 失能TIM OSSR状态 ；

#define IS_TIM_OSSR_STATE(STATE) (((STATE) == TIM_OSSRState_Enable) || \
                                  ((STATE) == TIM_OSSRState_Disable))

/* TIM Output Compare Idle State -------------------------------------------*/
#define TIM_OCIdleState_Set                ((u16)0x0100)
#define TIM_OCIdleState_Reset              ((u16)0x0000) // 当MOE=0设置TIM输出比较空闲状态

#define IS_TIM_OCIDLE_STATE(STATE) (((STATE) == TIM_OCIdleState_Set) || \
                                    ((STATE) == TIM_OCIdleState_Reset))

/* TIM Output Compare N Idle State -----------------------------------------*/
#define TIM_OCNIdleState_Set               ((u16)0x0200)
#define TIM_OCNIdleState_Reset             ((u16)0x0000) // 当MOE=0设置TIM输出比较N空闲状态 ；

#define IS_TIM_OCNIDLE_STATE(STATE) (((STATE) == TIM_OCNIdleState_Set) || \
                                     ((STATE) == TIM_OCNIdleState_Reset))

/* TIM Input Capture Polarity ----------------------------------------------*/
#define  TIM_ICPolarity_Rising             ((u16)0x0000) // TIM输入捕获上升沿 ；
#define  TIM_ICPolarity_Falling            ((u16)0x0002) // TIM输入捕获下降沿 ；

#define IS_TIM_IC_POLARITY(POLARITY) (((POLARITY) == TIM_ICPolarity_Rising) || \
                                      ((POLARITY) == TIM_ICPolarity_Falling))

/* TIM Input Capture Selection ---------------------------------------------*/
#define TIM_ICSelection_DirectTI           ((u16)0x0001) // TIM1输入2，3或4选择对应地与IC1或IC2或IC3或IC4相连 ；
#define TIM_ICSelection_IndirectTI         ((u16)0x0002) // TIM1输入2，3或4选择对应地与IC2或IC1或IC4或IC3相连 ；
#define TIM_ICSelection_TRC                ((u16)0x0003) // TIM1输入2，3或4选择与TRC相连 ；

#define IS_TIM_IC_SELECTION(SELECTION) (((SELECTION) == TIM_ICSelection_DirectTI) || \
                                        ((SELECTION) == TIM_ICSelection_IndirectTI) || \
                                        ((SELECTION) == TIM_ICSelection_TRC))

/* TIM Input Capture Prescaler ---------------------------------------------*/
#define TIM_ICPSC_DIV1                     ((u16)0x0000) // TIM捕获在捕获输入上每探测到一个边沿执行一次 ；
#define TIM_ICPSC_DIV2                     ((u16)0x0004) // TIM捕获每2个事件执行一次 ；
#define TIM_ICPSC_DIV4                     ((u16)0x0008) // TIM捕获每3个事件执行一次 ；
#define TIM_ICPSC_DIV8                     ((u16)0x000C) // TIM捕获每4个事件执行一次 ；

#define IS_TIM_IC_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ICPSC_DIV1) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV2) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV4) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV8))                                          

/* TIM interrupt sources ---------------------------------------------------*/
#define TIM_IT_Update                      ((u16)0x0001) // TIM中断源 ；
#define TIM_IT_CC1                         ((u16)0x0002) // TIM捕获/比较1中断源 ；
#define TIM_IT_CC2                         ((u16)0x0004) // TIM捕获/比较2中断源 ；
#define TIM_IT_CC3                         ((u16)0x0008) // TIM捕获/比较3中断源 ；
#define TIM_IT_CC4                         ((u16)0x0010) // TIM捕获/比较4中断源 ；
#define TIM_IT_COM                         ((u16)0x0020) //	TIM COM中断源 ；
#define TIM_IT_Trigger                     ((u16)0x0040) // TIM触发中断源 ；
#define TIM_IT_Break                       ((u16)0x0080) //	TIM刹车中断源 ；

#define IS_TIM_IT(IT) ((((IT) & (u16)0xFF00) == 0x0000) && ((IT) != 0x0000))

#define IS_TIM_PERIPH_IT(PERIPH, TIM_IT) ((((((*(u32*)&(PERIPH)) == TIM2_BASE) || (((*(u32*)&(PERIPH)) == TIM3_BASE))||\
                                            (((*(u32*)&(PERIPH)) == TIM4_BASE)) || (((*(u32*)&(PERIPH)) == TIM5_BASE))))&& \
                                            (((TIM_IT) & (u16)0xFFA0) == 0x0000) && ((TIM_IT) != 0x0000)) ||\
                                            (((((*(u32*)&(PERIPH)) == TIM1_BASE) || (((*(u32*)&(PERIPH)) == TIM8_BASE))))&& \
                                            (((TIM_IT) & (u16)0xFF00) == 0x0000) && ((TIM_IT) != 0x0000)) ||\
                                            (((((*(u32*)&(PERIPH)) == TIM6_BASE) || (((*(u32*)&(PERIPH)) == TIM7_BASE))))&& \
                                            (((TIM_IT) & (u16)0xFFFE) == 0x0000) && ((TIM_IT) != 0x0000)))

#define IS_TIM_GET_IT(IT) (((IT) == TIM_IT_Update) || \
                           ((IT) == TIM_IT_CC1) || \
                           ((IT) == TIM_IT_CC2) || \
                           ((IT) == TIM_IT_CC3) || \
                           ((IT) == TIM_IT_CC4) || \
                           ((IT) == TIM_IT_COM) || \
                           ((IT) == TIM_IT_Trigger) || \
                           ((IT) == TIM_IT_Break))

/* TIM DMA Base address ----------------------------------------------------*/
#define TIM_DMABase_CR1                    ((u16)0x0000) // TIM CR1寄存器作为DMA传输起始 ；
#define TIM_DMABase_CR2                    ((u16)0x0001) // TIM CR2寄存器作为DMA传输起始 ；
#define TIM_DMABase_SMCR                   ((u16)0x0002) // TIM SMCR寄存器作为DMA传输起始 ；
#define TIM_DMABase_DIER                   ((u16)0x0003) //	TIM DIER寄存器作为DMA传输起始 ；
#define TIM_DMABase_SR                     ((u16)0x0004) //	TIM SR寄存器作为DMA传输起始 ；
#define TIM_DMABase_EGR                    ((u16)0x0005) //	TIM EGR寄存器作为DMA传输起始 ；
#define TIM_DMABase_CCMR1                  ((u16)0x0006) //	TIM CCMR1寄存器作为DMA传输起始 ；
#define TIM_DMABase_CCMR2                  ((u16)0x0007) //	TIM CCMR2寄存器作为DMA传输起始 ；
#define TIM_DMABase_CCER                   ((u16)0x0008) //	TIM CCER寄存器作为DMA传输起始 ；
#define TIM_DMABase_CNT                    ((u16)0x0009) //	TIM CNT寄存器作为DMA传输起始 ；
#define TIM_DMABase_PSC                    ((u16)0x000A) //	TIM PSC寄存器作为DMA传输起始 ；
#define TIM_DMABase_ARR                    ((u16)0x000B) //	TIM APR寄存器作为DMA传输起始 ；
#define TIM_DMABase_RCR                    ((u16)0x000C) //	TIM RCR寄存器作为DMA传输起始 ；
#define TIM_DMABase_CCR1                   ((u16)0x000D) //	TIM CCR1寄存器作为DMA传输起始 ；
#define TIM_DMABase_CCR2                   ((u16)0x000E) //	TIM CCR2寄存器作为DMA传输起始 ；
#define TIM_DMABase_CCR3                   ((u16)0x000F) //	TIM CCR3寄存器作为DMA传输起始 ；
#define TIM_DMABase_CCR4                   ((u16)0x0010) //	TIM CCR4寄存器作为DMA传输起始 ；
#define TIM_DMABase_BDTR                   ((u16)0x0011) //	TIM BDTR寄存器作为DMA传输起始 ；
#define TIM_DMABase_DCR                    ((u16)0x0012) //	TIM DCR寄存器作为DMA传输起始 ；

#define IS_TIM_DMA_BASE(BASE) (((BASE) == TIM_DMABase_CR1) || \
                               ((BASE) == TIM_DMABase_CR2) || \
                               ((BASE) == TIM_DMABase_SMCR) || \
                               ((BASE) == TIM_DMABase_DIER) || \
                               ((BASE) == TIM_DMABase_SR) || \
                               ((BASE) == TIM_DMABase_EGR) || \
                               ((BASE) == TIM_DMABase_CCMR1) || \
                               ((BASE) == TIM_DMABase_CCMR2) || \
                               ((BASE) == TIM_DMABase_CCER) || \
                               ((BASE) == TIM_DMABase_CNT) || \
                               ((BASE) == TIM_DMABase_PSC) || \
                               ((BASE) == TIM_DMABase_ARR) || \
                               ((BASE) == TIM_DMABase_RCR) || \
                               ((BASE) == TIM_DMABase_CCR1) || \
                               ((BASE) == TIM_DMABase_CCR2) || \
                               ((BASE) == TIM_DMABase_CCR3) || \
                               ((BASE) == TIM_DMABase_CCR4) || \
                               ((BASE) == TIM_DMABase_BDTR) || \
                               ((BASE) == TIM_DMABase_DCR))

/* TIM DMA Burst Length ----------------------------------------------------*/
#define TIM_DMABurstLength_1Byte           ((u16)0x0000) // TIM DMA连续传送长度1字 ；
#define TIM_DMABurstLength_2Bytes          ((u16)0x0100) // TIM DMA连续传送长度2字 ；
#define TIM_DMABurstLength_3Bytes          ((u16)0x0200) // TIM DMA连续传送长度3字 ；
#define TIM_DMABurstLength_4Bytes          ((u16)0x0300) // TIM DMA连续传送长度4字 ；
#define TIM_DMABurstLength_5Bytes          ((u16)0x0400) // TIM DMA连续传送长度5字 ；
#define TIM_DMABurstLength_6Bytes          ((u16)0x0500) // TIM DMA连续传送长度6字 ；
#define TIM_DMABurstLength_7Bytes          ((u16)0x0600) // TIM DMA连续传送长度7字 ；
#define TIM_DMABurstLength_8Bytes          ((u16)0x0700) // TIM DMA连续传送长度8字 ；
#define TIM_DMABurstLength_9Bytes          ((u16)0x0800) // TIM DMA连续传送长度9字 ；
#define TIM_DMABurstLength_10Bytes         ((u16)0x0900) // TIM DMA连续传送长度10字 ；
#define TIM_DMABurstLength_11Bytes         ((u16)0x0A00) // TIM DMA连续传送长度11字 ；
#define TIM_DMABurstLength_12Bytes         ((u16)0x0B00) // TIM DMA连续传送长度12字 ；
#define TIM_DMABurstLength_13Bytes         ((u16)0x0C00) // TIM DMA连续传送长度13字 ；
#define TIM_DMABurstLength_14Bytes         ((u16)0x0D00) // TIM DMA连续传送长度14字 ；
#define TIM_DMABurstLength_15Bytes         ((u16)0x0E00) // TIM DMA连续传送长度15字 ；
#define TIM_DMABurstLength_16Bytes         ((u16)0x0F00) // TIM DMA连续传送长度16字 ；
#define TIM_DMABurstLength_17Bytes         ((u16)0x1000) // TIM DMA连续传送长度17字 ；
#define TIM_DMABurstLength_18Bytes         ((u16)0x1100) // TIM DMA连续传送长度18字 ；

#define IS_TIM_DMA_LENGTH(LENGTH) (((LENGTH) == TIM_DMABurstLength_1Byte) || \
                                   ((LENGTH) == TIM_DMABurstLength_2Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_3Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_4Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_5Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_6Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_7Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_8Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_9Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_10Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_11Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_12Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_13Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_14Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_15Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_16Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_17Bytes) || \
                                   ((LENGTH) == TIM_DMABurstLength_18Bytes))

/* TIM DMA sources ---------------------------------------------------------*/
#define TIM_DMA_Update                     ((u16)0x0100) // TIM更新DMA源 ；
#define TIM_DMA_CC1                        ((u16)0x0200) // TIM捕获/比较1DMA源 ；
#define TIM_DMA_CC2                        ((u16)0x0400) // TIM捕获/比较2DMA源 ；
#define TIM_DMA_CC3                        ((u16)0x0800) // TIM捕获/比较3DMA源 ；
#define TIM_DMA_CC4                        ((u16)0x1000) // TIM捕获/比较4DMA源 ；
#define TIM_DMA_COM                        ((u16)0x2000) //	TIM COM DMA源 ；
#define TIM_DMA_Trigger                    ((u16)0x4000) // TIM触发DMA源 ；

#define IS_TIM_DMA_SOURCE(SOURCE) ((((SOURCE) & (u16)0x80FF) == 0x0000) && ((SOURCE) != 0x0000))

#define IS_TIM_PERIPH_DMA(PERIPH, SOURCE) ((((((*(u32*)&(PERIPH)) == TIM2_BASE) || (((*(u32*)&(PERIPH)) == TIM3_BASE))||\
                                            (((*(u32*)&(PERIPH)) == TIM4_BASE)) || (((*(u32*)&(PERIPH)) == TIM5_BASE))))&& \
                                            (((SOURCE) & (u16)0xA0FF) == 0x0000) && ((SOURCE) != 0x0000)) ||\
                                            (((((*(u32*)&(PERIPH)) == TIM1_BASE) || (((*(u32*)&(PERIPH)) == TIM8_BASE))))&& \
                                            (((SOURCE) & (u16)0x80FF) == 0x0000) && ((SOURCE) != 0x0000)) ||\
                                            (((((*(u32*)&(PERIPH)) == TIM6_BASE) || (((*(u32*)&(PERIPH)) == TIM7_BASE))))&& \
                                            (((SOURCE) & (u16)0xFEFF) == 0x0000) && ((SOURCE) != 0x0000)))

/* TIM External Trigger Prescaler ------------------------------------------*/
#define TIM_ExtTRGPSC_OFF                  ((u16)0x0000) // TIM ETRP 预分频 OFF ;
#define TIM_ExtTRGPSC_DIV2                 ((u16)0x1000) // TIM ETRP频率除以2 ;
#define TIM_ExtTRGPSC_DIV4                 ((u16)0x2000) // TIM ETRP频率除以4 ;
#define TIM_ExtTRGPSC_DIV8                 ((u16)0x3000) // TIM ETRP频率除以8 ;

#define IS_TIM_EXT_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ExtTRGPSC_OFF) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV2) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV4) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV8))

/* TIM Internal Trigger Selection ------------------------------------------*/
#define TIM_TS_ITR0                        ((u16)0x0000) // TIM内部触发0 ；
#define TIM_TS_ITR1                        ((u16)0x0010) // TIM内部触发1 ；
#define TIM_TS_ITR2                        ((u16)0x0020) // TIM内部触发2 ；
#define TIM_TS_ITR3                        ((u16)0x0030) // TIM内部触发3 ；
#define TIM_TS_TI1F_ED                     ((u16)0x0040) // TIM IC1连接到TI1：使用边沿探测 ；
#define TIM_TS_TI1FP1                      ((u16)0x0050) // TIM IC1连接到TI1 ；
#define TIM_TS_TI2FP2                      ((u16)0x0060) // TIM IC2连接到TI2 ；
#define TIM_TS_ETRF                        ((u16)0x0070) // TIM外部触发输入 ;

#define IS_TIM_TRIGGER_SELECTION(SELECTION) (((SELECTION) == TIM_TS_ITR0) || \
                                             ((SELECTION) == TIM_TS_ITR1) || \
                                             ((SELECTION) == TIM_TS_ITR2) || \
                                             ((SELECTION) == TIM_TS_ITR3) || \
                                             ((SELECTION) == TIM_TS_TI1F_ED) || \
                                             ((SELECTION) == TIM_TS_TI1FP1) || \
                                             ((SELECTION) == TIM_TS_TI2FP2) || \
                                             ((SELECTION) == TIM_TS_ETRF))

#define IS_TIM_INTERNAL_TRIGGER_SELECTION(SELECTION) (((SELECTION) == TIM_TS_ITR0) || \
                                                      ((SELECTION) == TIM_TS_ITR1) || \
                                                      ((SELECTION) == TIM_TS_ITR2) || \
                                                      ((SELECTION) == TIM_TS_ITR3))

/* TIM TIx External Clock Source -------------------------------------------*/
#define TIM_TIxExternalCLK1Source_TI1      ((u16)0x0050)
#define TIM_TIxExternalCLK1Source_TI2      ((u16)0x0060)
#define TIM_TIxExternalCLK1Source_TI1ED    ((u16)0x0040)

#define IS_TIM_TIXCLK_SOURCE(SOURCE) (((SOURCE) == TIM_TIxExternalCLK1Source_TI1) || \
                                      ((SOURCE) == TIM_TIxExternalCLK1Source_TI2) || \
                                      ((SOURCE) == TIM_TIxExternalCLK1Source_TI1ED))

/* TIM External Trigger Polarity -------------------------------------------*/
#define TIM_ExtTRGPolarity_Inverted        ((u16)0x8000) // TIM外部触发极性翻转：低电平或下降沿有效 ;
#define TIM_ExtTRGPolarity_NonInverted     ((u16)0x0000) // TIM外部触发极性非翻转：高电平或上升沿有效 ;

#define IS_TIM_EXT_POLARITY(POLARITY) (((POLARITY) == TIM_ExtTRGPolarity_Inverted) || \
                                       ((POLARITY) == TIM_ExtTRGPolarity_NonInverted))

/* TIM Prescaler Reload Mode -----------------------------------------------*/
#define TIM_PSCReloadMode_Update           ((u16)0x0000) // TIM预分频值在更新事件装入 ;
#define TIM_PSCReloadMode_Immediate        ((u16)0x0001) // TIM预分频值即时装入 ;    

#define IS_TIM_PRESCALER_RELOAD(RELOAD) (((RELOAD) == TIM_PSCReloadMode_Update) || \
                                         ((RELOAD) == TIM_PSCReloadMode_Immediate))

/* TIM Forced Action -------------------------------------------------------*/
#define TIM_ForcedAction_Active            ((u16)0x0050) // 置为OCxREF上的活动电平 ;
#define TIM_ForcedAction_InActive          ((u16)0x0040) // 置为OCxREF上的非活动电平 ;

#define IS_TIM_FORCED_ACTION(ACTION) (((ACTION) == TIM_ForcedAction_Active) || \
                                      ((ACTION) == TIM_ForcedAction_InActive))

/* TIM Encoder Mode --------------------------------------------------------*/ 
#define TIM_EncoderMode_TI1                ((u16)0x0001) // 使用TIM编码模式1 ;
#define TIM_EncoderMode_TI2                ((u16)0x0002) //	使用TIM编码模式2 ;
#define TIM_EncoderMode_TI12               ((u16)0x0003) // 使用TIM编码模式3 ;

#define IS_TIM_ENCODER_MODE(MODE) (((MODE) == TIM_EncoderMode_TI1) || \
                                   ((MODE) == TIM_EncoderMode_TI2) || \
                                   ((MODE) == TIM_EncoderMode_TI12))

/* TIM Event Source --------------------------------------------------------*/
#define TIM_EventSource_Update             ((u16)0x0001) // TIM更新事件源 ;
#define TIM_EventSource_CC1                ((u16)0x0002) // TIM捕获比较1事件源 ;
#define TIM_EventSource_CC2                ((u16)0x0004) // TIM捕获比较2事件源 ;
#define TIM_EventSource_CC3                ((u16)0x0008) // TIM捕获比较3事件源 ;
#define TIM_EventSource_CC4                ((u16)0x0010) // TIM捕获比较4事件源 ;
#define TIM_EventSource_COM                ((u16)0x0020) //	TIM COM中断源 ；
#define TIM_EventSource_Trigger            ((u16)0x0040) // TIM触发事件源 ;
#define TIM_EventSource_Break              ((u16)0x0080) //	TIM刹车中断源 ；

#define IS_TIM_EVENT_SOURCE(SOURCE) ((((SOURCE) & (u16)0xFF00) == 0x0000) && ((SOURCE) != 0x0000))

#define IS_TIM_PERIPH_EVENT(PERIPH, EVENT) ((((((*(u32*)&(PERIPH)) == TIM2_BASE) || (((*(u32*)&(PERIPH)) == TIM3_BASE))||\
                                            (((*(u32*)&(PERIPH)) == TIM4_BASE)) || (((*(u32*)&(PERIPH)) == TIM5_BASE))))&& \
                                            (((EVENT) & (u16)0xFFA0) == 0x0000) && ((EVENT) != 0x0000)) ||\
                                            (((((*(u32*)&(PERIPH)) == TIM1_BASE) || (((*(u32*)&(PERIPH)) == TIM8_BASE))))&& \
                                            (((EVENT) & (u16)0xFF00) == 0x0000) && ((EVENT) != 0x0000)) ||\
                                            (((((*(u32*)&(PERIPH)) == TIM6_BASE) || (((*(u32*)&(PERIPH)) == TIM7_BASE))))&& \
                                            (((EVENT) & (u16)0xFFFE) == 0x0000) && ((EVENT) != 0x0000)))

/* TIM Update Source --------------------------------------------------------*/
#define TIM_UpdateSource_Global            ((u16)0x0000) // 生成重复的脉冲：在更新事件时计数器不停止 ;
#define TIM_UpdateSource_Regular           ((u16)0x0001) // 生成单一的脉冲：计数器在下一个更新事件停止 ;

#define IS_TIM_UPDATE_SOURCE(SOURCE) (((SOURCE) == TIM_UpdateSource_Global) || \
                                      ((SOURCE) == TIM_UpdateSource_Regular))

/* TIM Ouput Compare Preload State ------------------------------------------*/
#define TIM_OCPreload_Enable               ((u16)0x0008) // TIMx在CCR1上的预装载寄存器使能 ;
#define TIM_OCPreload_Disable              ((u16)0x0000) // TIMx在CCR1上的预装载寄存器失能 ;

#define IS_TIM_OCPRELOAD_STATE(STATE) (((STATE) == TIM_OCPreload_Enable) || \
                                       ((STATE) == TIM_OCPreload_Disable))

/* TIM Ouput Compare Fast State ---------------------------------------------*/
#define TIM_OCFast_Enable                  ((u16)0x0004) // TIMx输出比较快速特征性能使能 ;
#define TIM_OCFast_Disable                 ((u16)0x0000) //	TIMx输出比较快速特征性能失能 ;

#define IS_TIM_OCFAST_STATE(STATE) (((STATE) == TIM_OCFast_Enable) || \
                                    ((STATE) == TIM_OCFast_Disable))
                                     
/* TIM Ouput Compare Clear State --------------------------------------------*/
#define TIM_OCClear_Enable                 ((u16)0x0080)  // TIMx输出比较清除使能 ;
#define TIM_OCClear_Disable                ((u16)0x0000)  // TIMx输出比较清除失能 ;

#define IS_TIM_OCCLEAR_STATE(STATE) (((STATE) == TIM_OCClear_Enable) || \
                                     ((STATE) == TIM_OCClear_Disable))                                     

/* TIM Trigger Output Source ------------------------------------------------*/ 
#define TIM_TRGOSource_Reset               ((u16)0x0000) //	使用寄存器TIM_EGR的UG位作为触发输出（TRGO） ;
#define TIM_TRGOSource_Enable              ((u16)0x0010) //	使用计数器使能CEN作为触发输出（TRGO） ;
#define TIM_TRGOSource_Update              ((u16)0x0020) //	使用更新事件作为触发输出（TRGO）;
#define TIM_TRGOSource_OC1                 ((u16)0x0030) //	一旦捕获或者比较匹配发生，当标志位CC1F被设置时触发输出发送一个肯定脉冲（TRGO）;
#define TIM_TRGOSource_OC1Ref              ((u16)0x0040) //	使用OC1REF作为触发输出（TRGO） ;
#define TIM_TRGOSource_OC2Ref              ((u16)0x0050) //	使用OC2REF作为触发输出（TRGO） ;
#define TIM_TRGOSource_OC3Ref              ((u16)0x0060) //	使用OC3REF作为触发输出（TRGO） ;
#define TIM_TRGOSource_OC4Ref              ((u16)0x0070) //	使用OC4REF作为触发输出（TRGO） ;

#define IS_TIM_TRGO_SOURCE(SOURCE) (((SOURCE) == TIM_TRGOSource_Reset) || \
                                    ((SOURCE) == TIM_TRGOSource_Enable) || \
                                    ((SOURCE) == TIM_TRGOSource_Update) || \
                                    ((SOURCE) == TIM_TRGOSource_OC1) || \
                                    ((SOURCE) == TIM_TRGOSource_OC1Ref) || \
                                    ((SOURCE) == TIM_TRGOSource_OC2Ref) || \
                                    ((SOURCE) == TIM_TRGOSource_OC3Ref) || \
                                    ((SOURCE) == TIM_TRGOSource_OC4Ref))

#define IS_TIM_PERIPH_TRGO(PERIPH, TRGO)  (((((*(u32*)&(PERIPH)) == TIM2_BASE)||(((*(u32*)&(PERIPH)) == TIM1_BASE))||\
                                           (((*(u32*)&(PERIPH)) == TIM3_BASE))||(((*(u32*)&(PERIPH)) == TIM4_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM6_BASE))||(((*(u32*)&(PERIPH)) == TIM7_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM5_BASE))||(((*(u32*)&(PERIPH)) == TIM8_BASE))) && \
                                           ((TRGO) == TIM_TRGOSource_Reset)) ||\
                                           ((((*(u32*)&(PERIPH)) == TIM2_BASE)||(((*(u32*)&(PERIPH)) == TIM1_BASE))||\
                                           (((*(u32*)&(PERIPH)) == TIM6_BASE))||(((*(u32*)&(PERIPH)) == TIM7_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM3_BASE))||(((*(u32*)&(PERIPH)) == TIM4_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM5_BASE))||(((*(u32*)&(PERIPH)) == TIM8_BASE))) && \
                                           ((TRGO) == TIM_TRGOSource_Enable)) ||\
                                           ((((*(u32*)&(PERIPH)) == TIM2_BASE)||(((*(u32*)&(PERIPH)) == TIM1_BASE))||\
                                           (((*(u32*)&(PERIPH)) == TIM6_BASE))||(((*(u32*)&(PERIPH)) == TIM7_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM3_BASE))||(((*(u32*)&(PERIPH)) == TIM4_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM5_BASE))||(((*(u32*)&(PERIPH)) == TIM8_BASE))) && \
                                           ((TRGO) == TIM_TRGOSource_Update)) ||\
                                           ((((*(u32*)&(PERIPH)) == TIM2_BASE)||(((*(u32*)&(PERIPH)) == TIM1_BASE))||\
                                           (((*(u32*)&(PERIPH)) == TIM3_BASE))||(((*(u32*)&(PERIPH)) == TIM4_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM5_BASE))||(((*(u32*)&(PERIPH)) == TIM8_BASE))) && \
                                           ((TRGO) == TIM_TRGOSource_OC1)) ||\
                                           ((((*(u32*)&(PERIPH)) == TIM2_BASE)||(((*(u32*)&(PERIPH)) == TIM1_BASE))||\
                                           (((*(u32*)&(PERIPH)) == TIM3_BASE))||(((*(u32*)&(PERIPH)) == TIM4_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM5_BASE))||(((*(u32*)&(PERIPH)) == TIM8_BASE))) && \
                                           ((TRGO) == TIM_TRGOSource_OC1Ref)) ||\
                                           ((((*(u32*)&(PERIPH)) == TIM2_BASE)||(((*(u32*)&(PERIPH)) == TIM1_BASE))||\
                                           (((*(u32*)&(PERIPH)) == TIM3_BASE))||(((*(u32*)&(PERIPH)) == TIM4_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM5_BASE))||(((*(u32*)&(PERIPH)) == TIM8_BASE))) && \
                                           ((TRGO) == TIM_TRGOSource_OC2Ref)) ||\
                                           ((((*(u32*)&(PERIPH)) == TIM2_BASE)||(((*(u32*)&(PERIPH)) == TIM1_BASE))||\
                                           (((*(u32*)&(PERIPH)) == TIM3_BASE))||(((*(u32*)&(PERIPH)) == TIM4_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM5_BASE))||(((*(u32*)&(PERIPH)) == TIM8_BASE))) && \
                                           ((TRGO) == TIM_TRGOSource_OC3Ref)) ||\
                                           ((((*(u32*)&(PERIPH)) == TIM2_BASE)||(((*(u32*)&(PERIPH)) == TIM1_BASE))||\
                                           (((*(u32*)&(PERIPH)) == TIM3_BASE))||(((*(u32*)&(PERIPH)) == TIM4_BASE))|| \
                                           (((*(u32*)&(PERIPH)) == TIM5_BASE))||(((*(u32*)&(PERIPH)) == TIM8_BASE))) && \
                                           ((TRGO) == TIM_TRGOSource_OC4Ref)))

/* TIM Slave Mode ----------------------------------------------------------*/
#define TIM_SlaveMode_Reset                ((u16)0x0004) //	选中触发信号（TRGI）的上升沿重初始化计数器并触发寄存器的更新 ;
#define TIM_SlaveMode_Gated                ((u16)0x0005) //	当触发信号（TRGI）为高电平计数器时钟使能 ;
#define TIM_SlaveMode_Trigger              ((u16)0x0006) //	计数器在触发（TRGI）的上升沿开始 ;
#define TIM_SlaveMode_External1            ((u16)0x0007) //	选中触发（TRGI）的上升沿作为计数器时钟 ;

#define IS_TIM_SLAVE_MODE(MODE) (((MODE) == TIM_SlaveMode_Reset) || \
                                 ((MODE) == TIM_SlaveMode_Gated) || \
                                 ((MODE) == TIM_SlaveMode_Trigger) || \
                                 ((MODE) == TIM_SlaveMode_External1))

/* TIM Master Slave Mode ---------------------------------------------------*/
#define TIM_MasterSlaveMode_Enable         ((u16)0x0080) //	TIM主/从模式使能 ;
#define TIM_MasterSlaveMode_Disable        ((u16)0x0000) //	TIM主/从模式失能 ;

#define IS_TIM_MSM_STATE(STATE) (((STATE) == TIM_MasterSlaveMode_Enable) || \
                                 ((STATE) == TIM_MasterSlaveMode_Disable))

/* TIM Flags ---------------------------------------------------------------*/
#define TIM_FLAG_Update                    ((u16)0x0001) // TIM更新标志位 ;
#define TIM_FLAG_CC1                       ((u16)0x0002) // TIM捕获/比较1标志位 ;
#define TIM_FLAG_CC2                       ((u16)0x0004) // TIM捕获/比较2标志位 ;
#define TIM_FLAG_CC3                       ((u16)0x0008) // TIM捕获/比较3标志位 ;
#define TIM_FLAG_CC4                       ((u16)0x0010) // TIM捕获/比较4标志位 ;
#define TIM_FLAG_COM                       ((u16)0x0020)
#define TIM_FLAG_Trigger                   ((u16)0x0040) // TIM触发标志位 ;
#define TIM_FLAG_Break                     ((u16)0x0080)
#define TIM_FLAG_CC1OF                     ((u16)0x0200) // TIM捕获/比较1溢出标志位 ;
#define TIM_FLAG_CC2OF                     ((u16)0x0400) // TIM捕获/比较2溢出标志位 ;
#define TIM_FLAG_CC3OF                     ((u16)0x0800) // TIM捕获/比较3溢出标志位 ;
#define TIM_FLAG_CC4OF                     ((u16)0x1000) // TIM捕获/比较4溢出标志位 ;

#define IS_TIM_GET_FLAG(FLAG) (((FLAG) == TIM_FLAG_Update) || \
                               ((FLAG) == TIM_FLAG_CC1) || \
                               ((FLAG) == TIM_FLAG_CC2) || \
                               ((FLAG) == TIM_FLAG_CC3) || \
                               ((FLAG) == TIM_FLAG_CC4) || \
                               ((FLAG) == TIM_FLAG_COM) || \
                               ((FLAG) == TIM_FLAG_Trigger) || \
                               ((FLAG) == TIM_FLAG_Break) || \
                               ((FLAG) == TIM_FLAG_CC1OF) || \
                               ((FLAG) == TIM_FLAG_CC2OF) || \
                               ((FLAG) == TIM_FLAG_CC3OF) || \
                               ((FLAG) == TIM_FLAG_CC4OF))

#define IS_TIM_CLEAR_FLAG(PERIPH, TIM_FLAG) ((((((*(u32*)&(PERIPH)) == TIM2_BASE) || (((*(u32*)&(PERIPH)) == TIM3_BASE))||\
                                            (((*(u32*)&(PERIPH)) == TIM4_BASE)) || (((*(u32*)&(PERIPH)) == TIM5_BASE))))&& \
                                            (((TIM_FLAG) & (u16)0xE1A0) == 0x0000) && ((TIM_FLAG) != 0x0000)) ||\
                                            (((((*(u32*)&(PERIPH)) == TIM1_BASE) || (((*(u32*)&(PERIPH)) == TIM8_BASE))))&& \
                                            (((TIM_FLAG) & (u16)0xE100) == 0x0000) && ((TIM_FLAG) != 0x0000)) ||\
                                            (((((*(u32*)&(PERIPH)) == TIM6_BASE) || (((*(u32*)&(PERIPH)) == TIM7_BASE))))&& \
                                            (((TIM_FLAG) & (u16)0xFFFE) == 0x0000) && ((TIM_FLAG) != 0x0000)))

#define IS_TIM_PERIPH_FLAG(PERIPH, TIM_FLAG)  (((((*(u32*)&(PERIPH))==TIM2_BASE) || ((*(u32*)&(PERIPH)) == TIM3_BASE) ||\
                                                 ((*(u32*)&(PERIPH)) == TIM4_BASE) || ((*(u32*)&(PERIPH))==TIM5_BASE) || \
                                                 ((*(u32*)&(PERIPH))==TIM1_BASE) || ((*(u32*)&(PERIPH))==TIM8_BASE)) &&\
                                                 (((TIM_FLAG) == TIM_FLAG_CC1) || ((TIM_FLAG) == TIM_FLAG_CC2) ||\
                                                 ((TIM_FLAG) == TIM_FLAG_CC3) || ((TIM_FLAG) == TIM_FLAG_CC4) || \
                                                 ((TIM_FLAG) == TIM_FLAG_Trigger))) ||\
                                                 ((((*(u32*)&(PERIPH))==TIM2_BASE) || ((*(u32*)&(PERIPH)) == TIM3_BASE) || \
                                                 ((*(u32*)&(PERIPH)) == TIM4_BASE) || ((*(u32*)&(PERIPH))==TIM5_BASE) ||\
                                                 ((*(u32*)&(PERIPH))==TIM1_BASE)|| ((*(u32*)&(PERIPH))==TIM8_BASE) || \
                                                 ((*(u32*)&(PERIPH))==TIM7_BASE) || ((*(u32*)&(PERIPH))==TIM6_BASE)) && \
                                                 (((TIM_FLAG) == TIM_FLAG_Update))) ||\
                                                 ((((*(u32*)&(PERIPH))==TIM1_BASE) || ((*(u32*)&(PERIPH)) == TIM8_BASE)) &&\
                                                 (((TIM_FLAG) == TIM_FLAG_COM) || ((TIM_FLAG) == TIM_FLAG_Break))) ||\
                                                 ((((*(u32*)&(PERIPH))==TIM2_BASE) || ((*(u32*)&(PERIPH)) == TIM3_BASE) || \
                                                 ((*(u32*)&(PERIPH)) == TIM4_BASE) || ((*(u32*)&(PERIPH))==TIM5_BASE) || \
                                                 ((*(u32*)&(PERIPH))==TIM1_BASE) || ((*(u32*)&(PERIPH))==TIM8_BASE)) &&\
                                                 (((TIM_FLAG) == TIM_FLAG_CC1OF) || ((TIM_FLAG) == TIM_FLAG_CC2OF) ||\
                                                 ((TIM_FLAG) == TIM_FLAG_CC3OF) || ((TIM_FLAG) == TIM_FLAG_CC4OF))))             
                                                                                            
/* TIM Input Capture Filer Value ---------------------------------------------*/
#define IS_TIM_IC_FILTER(ICFILTER) ((ICFILTER) <= 0xF) 

/* TIM External Trigger Filter -----------------------------------------------*/
#define IS_TIM_EXT_FILTER(EXTFILTER) ((EXTFILTER) <= 0xF)                              

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_ITConfig(TIM_TypeDef* TIMx, u16 TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, u16 TIM_EventSource);
void TIM_DMAConfig(TIM_TypeDef* TIMx, u16 TIM_DMABase, u16 TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, u16 TIM_DMASource, FunctionalState NewState);
void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, u16 TIM_InputTriggerSource);
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, u16 TIM_TIxExternalCLKSource,
                                u16 TIM_ICPolarity, u16 ICFilter);                                
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, u16 TIM_ExtTRGPrescaler, u16 TIM_ExtTRGPolarity,
                             u16 ExtTRGFilter);
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, u16 TIM_ExtTRGPrescaler, 
                             u16 TIM_ExtTRGPolarity, u16 ExtTRGFilter);
void TIM_ETRConfig(TIM_TypeDef* TIMx, u16 TIM_ExtTRGPrescaler, u16 TIM_ExtTRGPolarity,
                   u16 ExtTRGFilter);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, u16 Prescaler, u16 TIM_PSCReloadMode);
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, u16 TIM_CounterMode);
void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, u16 TIM_InputTriggerSource);
void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, u16 TIM_EncoderMode,
                                u16 TIM_IC1Polarity, u16 TIM_IC2Polarity);
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, u16 TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, u16 TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, u16 TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, u16 TIM_ForcedAction);
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, u16 TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, u16 TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, u16 TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, u16 TIM_OCPreload);
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, u16 TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, u16 TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, u16 TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, u16 TIM_OCFast);
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, u16 TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, u16 TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, u16 TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, u16 TIM_OCClear);
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, u16 TIM_OCPolarity);
void TIM_CCxCmd(TIM_TypeDef* TIMx, u16 TIM_Channel, u16 TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, u16 TIM_Channel, u16 TIM_CCxN);
void TIM_SelectOCxM(TIM_TypeDef* TIMx, u16 TIM_Channel, u16 TIM_OCMode);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, u16 TIM_UpdateSource);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, u16 TIM_OPMode);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, u16 TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, u16 TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, u16 TIM_MasterSlaveMode);
void TIM_SetCounter(TIM_TypeDef* TIMx, u16 Counter);
void TIM_SetAutoreload(TIM_TypeDef* TIMx, u16 Autoreload);
void TIM_SetCompare1(TIM_TypeDef* TIMx, u16 Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, u16 Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, u16 Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, u16 Compare4);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, u16 TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, u16 TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, u16 TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, u16 TIM_ICPSC);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, u16 TIM_CKD);
u16 TIM_GetCapture1(TIM_TypeDef* TIMx);
u16 TIM_GetCapture2(TIM_TypeDef* TIMx);
u16 TIM_GetCapture3(TIM_TypeDef* TIMx);
u16 TIM_GetCapture4(TIM_TypeDef* TIMx);
u16 TIM_GetCounter(TIM_TypeDef* TIMx);
u16 TIM_GetPrescaler(TIM_TypeDef* TIMx);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, u16 TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, u16 TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, u16 TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, u16 TIM_IT);
                                                                                                             
#endif /*__STM32F10x_TIM_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/








