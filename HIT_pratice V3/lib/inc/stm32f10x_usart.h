/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_usart.h
* Author             : MCD Application Team
* Version            : V2.0
* Date               : 05/23/2008
* Description        : This file contains all the functions prototypes for the
*                      USART firmware library.
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
#ifndef __STM32F10x_USART_H
#define __STM32F10x_USART_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_map.h"

/* Exported types ------------------------------------------------------------*/
/* USART Init Structure definition */
typedef struct
{
  u32 USART_BaudRate; // 设置了USART传输的波特率 ；
  u16 USART_WordLength; // 提示了在一个帧中传输或者接收到的数据位数 ；
  u16 USART_StopBits; // 定义了发送的停止位数目 ；
  u16 USART_Parity;	  // 定义了奇偶模式	；
  u16 USART_Mode;	  // 指定了使能或者失能发送和接收模式 ；
  u16 USART_HardwareFlowControl;  // 指定了硬件流控制模式使能还是失能 ；
} USART_InitTypeDef;

/* USART Clock Init Structure definition */
typedef struct
{
  u16 USART_Clock;  // 提示了USART时钟使能还是失能 ；
  u16 USART_CPOL;	// 指定了下SLCK引脚上时钟输出的极性 ；
  u16 USART_CPHA;	// 指定了下SLCK引脚上时钟输出的相位，和CPOL位一起配合来产生用户希望的时钟/数据的采样关系 ；
  u16 USART_LastBit; //	来控制是否在同步模式下，在SCLK引脚上输出最后发送的那个数据字 (MSB)对应的时钟脉冲 ；
} USART_ClockInitTypeDef;

/* Exported constants --------------------------------------------------------*/
#define IS_USART_ALL_PERIPH(PERIPH) (((*(u32*)&(PERIPH)) == USART1_BASE) || \
                                     ((*(u32*)&(PERIPH)) == USART2_BASE) || \
                                     ((*(u32*)&(PERIPH)) == USART3_BASE) || \
                                     ((*(u32*)&(PERIPH)) == UART4_BASE) || \
                                     ((*(u32*)&(PERIPH)) == UART5_BASE))

#define IS_USART_123_PERIPH(PERIPH) (((*(u32*)&(PERIPH)) == USART1_BASE) || \
                                     ((*(u32*)&(PERIPH)) == USART2_BASE) || \
                                     ((*(u32*)&(PERIPH)) == USART3_BASE))

#define IS_USART_1234_PERIPH(PERIPH) (((*(u32*)&(PERIPH)) == USART1_BASE) || \
                                      ((*(u32*)&(PERIPH)) == USART2_BASE) || \
                                      ((*(u32*)&(PERIPH)) == USART3_BASE) || \
                                      ((*(u32*)&(PERIPH)) == UART4_BASE))

/* USART Word Length ---------------------------------------------------------*/
#define USART_WordLength_8b                  ((u16)0x0000) // 8位数据 ；
#define USART_WordLength_9b                  ((u16)0x1000) // 9位数据 ；
                                    
#define IS_USART_WORD_LENGTH(LENGTH) (((LENGTH) == USART_WordLength_8b) || \
                                      ((LENGTH) == USART_WordLength_9b))

/* USART Stop Bits -----------------------------------------------------------*/
#define USART_StopBits_1                     ((u16)0x0000) // 在帧结尾传输1个停止位 ；
#define USART_StopBits_0_5                   ((u16)0x1000) // 在帧结尾传输0.5个停止位 ；
#define USART_StopBits_2                     ((u16)0x2000) // 在帧结尾传输2个停止位 ；
#define USART_StopBits_1_5                   ((u16)0x3000) // 在帧结尾传输1.5个停止位 ；

#define IS_USART_STOPBITS(STOPBITS) (((STOPBITS) == USART_StopBits_1) || \
                                     ((STOPBITS) == USART_StopBits_0_5) || \
                                     ((STOPBITS) == USART_StopBits_2) || \
                                     ((STOPBITS) == USART_StopBits_1_5))
/* USART Parity --------------------------------------------------------------*/
#define USART_Parity_No                      ((u16)0x0000) // 奇偶失能 ；
#define USART_Parity_Even                    ((u16)0x0400) // 偶模式 ；
#define USART_Parity_Odd                     ((u16)0x0600) // 奇模式 ；

#define IS_USART_PARITY(PARITY) (((PARITY) == USART_Parity_No) || \
                                 ((PARITY) == USART_Parity_Even) || \
                                 ((PARITY) == USART_Parity_Odd))

/* USART Mode ----------------------------------------------------------------*/
#define USART_Mode_Rx                        ((u16)0x0004) // 接收使能 ；
#define USART_Mode_Tx                        ((u16)0x0008) // 发送使能 ；

#define IS_USART_MODE(MODE) ((((MODE) & (u16)0xFFF3) == 0x00) && ((MODE) != (u16)0x00))

/* USART Hardware Flow Control -----------------------------------------------*/
#define USART_HardwareFlowControl_None       ((u16)0x0000) // 硬件流控制失能 ；
#define USART_HardwareFlowControl_RTS        ((u16)0x0100) // 发送请求RTS使能 ；
#define USART_HardwareFlowControl_CTS        ((u16)0x0200) // 清除发送CTS使能 ；
#define USART_HardwareFlowControl_RTS_CTS    ((u16)0x0300) // RTS和CTS使能 ；

#define IS_USART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == USART_HardwareFlowControl_None) || \
                               ((CONTROL) == USART_HardwareFlowControl_RTS) || \
                               ((CONTROL) == USART_HardwareFlowControl_CTS) || \
                               ((CONTROL) == USART_HardwareFlowControl_RTS_CTS))

#define IS_USART_PERIPH_HFC(PERIPH, HFC) ((((*(u32*)&(PERIPH)) != UART4_BASE) && \
                                          ((*(u32*)&(PERIPH)) != UART5_BASE)) \
                                          || ((HFC) == USART_HardwareFlowControl_None))                                

/* USART Clock ---------------------------------------------------------------*/
#define USART_Clock_Disable                  ((u16)0x0000) // 时钟低电平活动 ；
#define USART_Clock_Enable                   ((u16)0x0800) // 时钟高电平活动 ；

#define IS_USART_CLOCK(CLOCK) (((CLOCK) == USART_Clock_Disable) || \
                               ((CLOCK) == USART_Clock_Enable))

/* USART Clock Polarity ------------------------------------------------------*/
#define USART_CPOL_Low                       ((u16)0x0000) // 时钟低电平 ；
#define USART_CPOL_High                      ((u16)0x0400) // 时钟高电平 ；

#define IS_USART_CPOL(CPOL) (((CPOL) == USART_CPOL_Low) || ((CPOL) == USART_CPOL_High))
                               
/* USART Clock Phase ---------------------------------------------------------*/
#define USART_CPHA_1Edge                     ((u16)0x0000) // 时钟第一个边沿进行数据捕获 ；
#define USART_CPHA_2Edge                     ((u16)0x0200) // 时钟第二个边沿进行数据捕获 ；
#define IS_USART_CPHA(CPHA) (((CPHA) == USART_CPHA_1Edge) || ((CPHA) == USART_CPHA_2Edge))

/* USART Last Bit ------------------------------------------------------------*/
#define USART_LastBit_Disable                ((u16)0x0000) // 最后一位数据的时钟脉冲不从SCLK输出 ；
#define USART_LastBit_Enable                 ((u16)0x0100) // 最后一位数据的时钟脉冲从SCLK输出 ；

#define IS_USART_LASTBIT(LASTBIT) (((LASTBIT) == USART_LastBit_Disable) || \
                                   ((LASTBIT) == USART_LastBit_Enable))

/* USART Interrupt definition ------------------------------------------------*/
#define USART_IT_PE                          ((u16)0x0028) // 奇偶错误中断 ；
#define USART_IT_TXE                         ((u16)0x0727) // 发送中断 ；
#define USART_IT_TC                          ((u16)0x0626) // 传输完成中断  ；
#define USART_IT_RXNE                        ((u16)0x0525) // 接收中断 ；
#define USART_IT_IDLE                        ((u16)0x0424) // 空闲总线中断 ；
#define USART_IT_LBD                         ((u16)0x0846) // LIN中断检测中断 ；
#define USART_IT_CTS                         ((u16)0x096A) // CTS中断 ；
#define USART_IT_ERR                         ((u16)0x0060) // 错误中断 ；
#define USART_IT_ORE                         ((u16)0x0360) // 溢出错误中断 ；
#define USART_IT_NE                          ((u16)0x0260) // 噪声错误中断 ；
#define USART_IT_FE                          ((u16)0x0160) // 帧错误中断 ；

#define IS_USART_CONFIG_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TXE) || \
                               ((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
                               ((IT) == USART_IT_IDLE) || ((IT) == USART_IT_LBD) || \
                               ((IT) == USART_IT_CTS) || ((IT) == USART_IT_ERR))

#define IS_USART_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TXE) || \
                         ((IT) == USART_IT_TC) || ((IT) == USART_IT_RXNE) || \
                         ((IT) == USART_IT_IDLE) || ((IT) == USART_IT_LBD) || \
                         ((IT) == USART_IT_CTS) || ((IT) == USART_IT_ORE) || \
                         ((IT) == USART_IT_NE) || ((IT) == USART_IT_FE))

#define IS_USART_CLEAR_IT(IT) (((IT) == USART_IT_PE) || ((IT) == USART_IT_TC) || \
                               ((IT) == USART_IT_RXNE) || ((IT) == USART_IT_IDLE) || \
                               ((IT) == USART_IT_LBD) || ((IT) == USART_IT_CTS) ||  \
                               ((IT) == USART_IT_ORE) || ((IT) == USART_IT_NE) || \
                               ((IT) == USART_IT_FE))

#define IS_USART_PERIPH_IT(PERIPH, USART_IT) ((((*(u32*)&(PERIPH)) != UART4_BASE) && \
                                              ((*(u32*)&(PERIPH)) != UART5_BASE)) \
                                              || ((USART_IT) != USART_IT_CTS))                                                                           

/* USART DMA Requests --------------------------------------------------------*/
#define USART_DMAReq_Tx                      ((u16)0x0080) // 发送DMA请求 ；
#define USART_DMAReq_Rx                      ((u16)0x0040) // 接收DMA请求 ；

#define IS_USART_DMAREQ(DMAREQ) ((((DMAREQ) & (u16)0xFF3F) == 0x00) && ((DMAREQ) != (u16)0x00))

/* USART WakeUp methods ------------------------------------------------------*/
#define USART_WakeUp_IdleLine                ((u16)0x0000) // 空闲总线唤醒 ；
#define USART_WakeUp_AddressMark             ((u16)0x0800) // 地址标记唤醒 ；

#define IS_USART_WAKEUP(WAKEUP) (((WAKEUP) == USART_WakeUp_IdleLine) || \
                                 ((WAKEUP) == USART_WakeUp_AddressMark))

/* USART LIN Break Detection Length ------------------------------------------*/
#define USART_LINBreakDetectLength_10b      ((u16)0x0000) // 10位中断检测 ；
#define USART_LINBreakDetectLength_11b      ((u16)0x0020) // 11位中断检测 ；

#define IS_USART_LIN_BREAK_DETECT_LENGTH(LENGTH) \
                               (((LENGTH) == USART_LINBreakDetectLength_10b) || \
                                ((LENGTH) == USART_LINBreakDetectLength_11b))

/* USART IrDA Low Power ------------------------------------------------------*/
#define USART_IrDAMode_LowPower              ((u16)0x0004) // IrDA低功耗模式 ；
#define USART_IrDAMode_Normal                ((u16)0x0000) // IrDA正常模式 ；

#define IS_USART_IRDA_MODE(MODE) (((MODE) == USART_IrDAMode_LowPower) || \
                                  ((MODE) == USART_IrDAMode_Normal))

/* USART Flags ---------------------------------------------------------------*/
#define USART_FLAG_CTS                       ((u16)0x0200) // CTS标志位 ；
#define USART_FLAG_LBD                       ((u16)0x0100) // LIN中断检测标志位 ；
#define USART_FLAG_TXE                       ((u16)0x0080) // 发送数据寄存器空标志位 ；
#define USART_FLAG_TC                        ((u16)0x0040) // 发送完成标志位 ；
#define USART_FLAG_RXNE                      ((u16)0x0020) // 接收数据寄存器非空标志位 ；
#define USART_FLAG_IDLE                      ((u16)0x0010) // 空闲总线标志位 ；
#define USART_FLAG_ORE                       ((u16)0x0008) // 溢出错误标志位 ；
#define USART_FLAG_NE                        ((u16)0x0004) // 噪声错误标志位 ；
#define USART_FLAG_FE                        ((u16)0x0002) // 帧错误标志位 ；
#define USART_FLAG_PE                        ((u16)0x0001) // 奇偶错误标志位 ；

#define IS_USART_FLAG(FLAG) (((FLAG) == USART_FLAG_PE) || ((FLAG) == USART_FLAG_TXE) || \
                             ((FLAG) == USART_FLAG_TC) || ((FLAG) == USART_FLAG_RXNE) || \
                             ((FLAG) == USART_FLAG_IDLE) || ((FLAG) == USART_FLAG_LBD) || \
                             ((FLAG) == USART_FLAG_CTS) || ((FLAG) == USART_FLAG_ORE) || \
                             ((FLAG) == USART_FLAG_NE) || ((FLAG) == USART_FLAG_FE))
                              
#define IS_USART_CLEAR_FLAG(FLAG) ((((FLAG) & (u16)0xFC80) == 0x00) && ((FLAG) != (u16)0x00))

#define IS_USART_PERIPH_FLAG(PERIPH, USART_FLAG) ((((*(u32*)&(PERIPH)) != UART4_BASE) &&\
                                                  ((*(u32*)&(PERIPH)) != UART5_BASE)) \
                                                  || ((USART_FLAG) != USART_FLAG_CTS)) 

#define IS_USART_BAUDRATE(BAUDRATE) (((BAUDRATE) > 0) && ((BAUDRATE) < 0x0044AA21))
#define IS_USART_ADDRESS(ADDRESS) ((ADDRESS) <= 0xF)
#define IS_USART_DATA(DATA) ((DATA) <= 0x1FF)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void USART_DeInit(USART_TypeDef* USARTx);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_ITConfig(USART_TypeDef* USARTx, u16 USART_IT, FunctionalState NewState);
void USART_DMACmd(USART_TypeDef* USARTx, u16 USART_DMAReq, FunctionalState NewState);
void USART_SetAddress(USART_TypeDef* USARTx, u8 USART_Address);
void USART_WakeUpConfig(USART_TypeDef* USARTx, u16 USART_WakeUp);
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, u16 USART_LINBreakDetectLength);
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendData(USART_TypeDef* USARTx, u16 Data);
u16 USART_ReceiveData(USART_TypeDef* USARTx);
void USART_SendBreak(USART_TypeDef* USARTx);
void USART_SetGuardTime(USART_TypeDef* USARTx, u8 USART_GuardTime);
void USART_SetPrescaler(USART_TypeDef* USARTx, u8 USART_Prescaler);
void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_IrDAConfig(USART_TypeDef* USARTx, u16 USART_IrDAMode);
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, u16 USART_FLAG);
void USART_ClearFlag(USART_TypeDef* USARTx, u16 USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, u16 USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, u16 USART_IT);

#endif /* __STM32F10x_USART_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
