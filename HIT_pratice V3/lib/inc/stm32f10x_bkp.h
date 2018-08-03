/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_bkp.h
* Author             : MCD Application Team
* Version            : V2.0
* Date               : 05/23/2008
* Description        : This file contains all the functions prototypes for the
*                      BKP firmware library.
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
#ifndef __STM32F10x_BKP_H
#define __STM32F10x_BKP_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_map.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Tamper Pin active level */
#define BKP_TamperPinLevel_High           ((u16)0x0000)	// 侵入检测管脚高电平有效 ；
#define BKP_TamperPinLevel_Low            ((u16)0x0001)	// 侵入检测管脚低电平有效 ；

#define IS_BKP_TAMPER_PIN_LEVEL(LEVEL) (((LEVEL) == BKP_TamperPinLevel_High) || \
                                        ((LEVEL) == BKP_TamperPinLevel_Low))

/* RTC output source to output on the Tamper pin */
#define BKP_RTCOutputSource_None          ((u16)0x0000)	// 侵入检测管脚上无RTC输出 ；
#define BKP_RTCOutputSource_CalibClock    ((u16)0x0080)	// 侵入检测管脚上输出，其时钟频率为RTC时钟除以64 ；
#define BKP_RTCOutputSource_Alarm         ((u16)0x0100)	// 侵入检测管脚上输出RTC闹钟脉冲 ；
#define BKP_RTCOutputSource_Second        ((u16)0x0300)	// 侵入检测管脚上输出RTC秒脉冲 ；

#define IS_BKP_RTC_OUTPUT_SOURCE(SOURCE) (((SOURCE) == BKP_RTCOutputSource_None) || \
                                          ((SOURCE) == BKP_RTCOutputSource_CalibClock) || \
                                          ((SOURCE) == BKP_RTCOutputSource_Alarm) || \
                                          ((SOURCE) == BKP_RTCOutputSource_Second))

/* Data Backup Register */
#define BKP_DR1                           ((u16)0x0004)	// 选中数据寄存器 1 ；
#define BKP_DR2                           ((u16)0x0008)	// 选中数据寄存器 2 ；
#define BKP_DR3                           ((u16)0x000C)	// 选中数据寄存器 3 ；
#define BKP_DR4                           ((u16)0x0010)	// 选中数据寄存器 4 ；
#define BKP_DR5                           ((u16)0x0014)	// 选中数据寄存器 5 ；
#define BKP_DR6                           ((u16)0x0018)	// 选中数据寄存器 6 ；
#define BKP_DR7                           ((u16)0x001C)	// 选中数据寄存器 7 ；
#define BKP_DR8                           ((u16)0x0020)	// 选中数据寄存器 8 ；
#define BKP_DR9                           ((u16)0x0024)	// 选中数据寄存器 9 ；
#define BKP_DR10                          ((u16)0x0028)	// 选中数据寄存器 10 ；
#define BKP_DR11                          ((u16)0x0040)	// 选中数据寄存器 11 ；
#define BKP_DR12                          ((u16)0x0044)	// 选中数据寄存器 12 ；
#define BKP_DR13                          ((u16)0x0048)	// 选中数据寄存器 13 ；
#define BKP_DR14                          ((u16)0x004C)	// 选中数据寄存器 14 ；
#define BKP_DR15                          ((u16)0x0050)	// 选中数据寄存器 15 ；
#define BKP_DR16                          ((u16)0x0054)	// 选中数据寄存器 16 ；
#define BKP_DR17                          ((u16)0x0058)	// 选中数据寄存器 17 ；
#define BKP_DR18                          ((u16)0x005C)	// 选中数据寄存器 18 ；
#define BKP_DR19                          ((u16)0x0060)	// 选中数据寄存器 19 ；
#define BKP_DR20                          ((u16)0x0064)	// 选中数据寄存器 20 ；
#define BKP_DR21                          ((u16)0x0068)	// 选中数据寄存器 21 ；
#define BKP_DR22                          ((u16)0x006C)	// 选中数据寄存器 22 ；
#define BKP_DR23                          ((u16)0x0070)	// 选中数据寄存器 23 ；
#define BKP_DR24                          ((u16)0x0074)	// 选中数据寄存器 24 ；
#define BKP_DR25                          ((u16)0x0078)	// 选中数据寄存器 25 ；
#define BKP_DR26                          ((u16)0x007C)	// 选中数据寄存器 26 ；
#define BKP_DR27                          ((u16)0x0080)	// 选中数据寄存器 27 ；
#define BKP_DR28                          ((u16)0x0084)	// 选中数据寄存器 28 ；
#define BKP_DR29                          ((u16)0x0088)	// 选中数据寄存器 29 ；
#define BKP_DR30                          ((u16)0x008C)	// 选中数据寄存器 30 ；
#define BKP_DR31                          ((u16)0x0090)	// 选中数据寄存器 31 ；
#define BKP_DR32                          ((u16)0x0094)	// 选中数据寄存器 32 ；
#define BKP_DR33                          ((u16)0x0098)	// 选中数据寄存器 33 ；
#define BKP_DR34                          ((u16)0x009C)	// 选中数据寄存器 34 ；
#define BKP_DR35                          ((u16)0x00A0)	// 选中数据寄存器 35 ；
#define BKP_DR36                          ((u16)0x00A4)	// 选中数据寄存器 36 ；
#define BKP_DR37                          ((u16)0x00A8)	// 选中数据寄存器 37 ；
#define BKP_DR38                          ((u16)0x00AC)	// 选中数据寄存器 38 ；
#define BKP_DR39                          ((u16)0x00B0)	// 选中数据寄存器 39 ；
#define BKP_DR40                          ((u16)0x00B4)	// 选中数据寄存器 40 ；
#define BKP_DR41                          ((u16)0x00B8)	// 选中数据寄存器 41 ；
#define BKP_DR42                          ((u16)0x00BC)	// 选中数据寄存器 42 ；

#define IS_BKP_DR(DR) (((DR) == BKP_DR1)  || ((DR) == BKP_DR2)  || ((DR) == BKP_DR3)  || \
                       ((DR) == BKP_DR4)  || ((DR) == BKP_DR5)  || ((DR) == BKP_DR6)  || \
                       ((DR) == BKP_DR7)  || ((DR) == BKP_DR8)  || ((DR) == BKP_DR9)  || \
                       ((DR) == BKP_DR10) || ((DR) == BKP_DR11) || ((DR) == BKP_DR12) || \
                       ((DR) == BKP_DR13) || ((DR) == BKP_DR14) || ((DR) == BKP_DR15) || \
                       ((DR) == BKP_DR16) || ((DR) == BKP_DR17) || ((DR) == BKP_DR18) || \
                       ((DR) == BKP_DR19) || ((DR) == BKP_DR20) || ((DR) == BKP_DR21) || \
                       ((DR) == BKP_DR22) || ((DR) == BKP_DR23) || ((DR) == BKP_DR24) || \
                       ((DR) == BKP_DR25) || ((DR) == BKP_DR26) || ((DR) == BKP_DR27) || \
                       ((DR) == BKP_DR28) || ((DR) == BKP_DR29) || ((DR) == BKP_DR30) || \
                       ((DR) == BKP_DR31) || ((DR) == BKP_DR32) || ((DR) == BKP_DR33) || \
                       ((DR) == BKP_DR34) || ((DR) == BKP_DR35) || ((DR) == BKP_DR36) || \
                       ((DR) == BKP_DR37) || ((DR) == BKP_DR38) || ((DR) == BKP_DR39) || \
                       ((DR) == BKP_DR40) || ((DR) == BKP_DR41) || ((DR) == BKP_DR42))

#define IS_BKP_CALIBRATION_VALUE(VALUE) ((VALUE) <= 0x7F)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void BKP_DeInit(void);
void BKP_TamperPinLevelConfig(u16 BKP_TamperPinLevel);
void BKP_TamperPinCmd(FunctionalState NewState);
void BKP_ITConfig(FunctionalState NewState);
void BKP_RTCOutputConfig(u16 BKP_RTCOutputSource);
void BKP_SetRTCCalibrationValue(u8 CalibrationValue);
void BKP_WriteBackupRegister(u16 BKP_DR, u16 Data);
u16 BKP_ReadBackupRegister(u16 BKP_DR);
FlagStatus BKP_GetFlagStatus(void);
void BKP_ClearFlag(void);
ITStatus BKP_GetITStatus(void);
void BKP_ClearITPendingBit(void);

#endif /* __STM32F10x_BKP_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
