/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_nvic.h
* Author             : MCD Application Team
* Version            : V2.0
* Date               : 05/23/2008
* Description        : This file contains all the functions prototypes for the
*                      NVIC firmware library.
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
#ifndef __STM32F10x_NVIC_H
#define __STM32F10x_NVIC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_map.h"

/* Exported types ------------------------------------------------------------*/
/* NVIC Init Structure definition */
typedef struct
{
  u8 NVIC_IRQChannel;  // 用以使能或者失能指定的IRQ通道 ；
  u8 NVIC_IRQChannelPreemptionPriority;	 // 设置了成员NVIC_IRQChannel中的先占优先级 ；
  u8 NVIC_IRQChannelSubPriority;   // 设置了成员NVIC_IRQChannel中的从优先级 ；
  FunctionalState NVIC_IRQChannelCmd; // 指定了在成员NVIC_IRQChannel中定义的IRQ通道被使能还是失能 ；
} NVIC_InitTypeDef;

/* Exported constants --------------------------------------------------------*/
/* IRQ Channels --------------------------------------------------------------*/
#define WWDG_IRQChannel              ((u8)0x00)  /* 窗口看门狗中断 */
#define PVD_IRQChannel               ((u8)0x01)  /* PVD通过EXTI探测中断 */
#define TAMPER_IRQChannel            ((u8)0x02)  /* 篡改中断 */
#define RTC_IRQChannel               ((u8)0x03)  /* RTC全局中断 */
#define FLASH_IRQChannel             ((u8)0x04)  /* FLASH全局中断 */
#define RCC_IRQChannel               ((u8)0x05)  /* RCC全局中断 */
#define EXTI0_IRQChannel             ((u8)0x06)  /* 外部中断线0中断 */
#define EXTI1_IRQChannel             ((u8)0x07)  /* 外部中断线1中断 */
#define EXTI2_IRQChannel             ((u8)0x08)  /* 外部中断线2中断 */
#define EXTI3_IRQChannel             ((u8)0x09)  /* 外部中断线3中断 */
#define EXTI4_IRQChannel             ((u8)0x0A)  /* 外部中断线4中断 */
#define DMA1_Channel1_IRQChannel     ((u8)0x0B)  /* DMA通道1中断 */
#define DMA1_Channel2_IRQChannel     ((u8)0x0C)  /* DMA通道2中断 */
#define DMA1_Channel3_IRQChannel     ((u8)0x0D)  /* DMA通道3中断 */
#define DMA1_Channel4_IRQChannel     ((u8)0x0E)  /* DMA通道4中断 */
#define DMA1_Channel5_IRQChannel     ((u8)0x0F)  /* DMA通道5中断 */
#define DMA1_Channel6_IRQChannel     ((u8)0x10)  /* DMA通道6中断 */
#define DMA1_Channel7_IRQChannel     ((u8)0x11)  /* DMA通道7中断 */
#define ADC1_2_IRQChannel            ((u8)0x12)  /* ADC全局中断 */
#define USB_HP_CAN_TX_IRQChannel     ((u8)0x13)  /* USB高优先级或者CAN发送中断 */
#define USB_LP_CAN_RX0_IRQChannel    ((u8)0x14)  /* USB低优先级或者CAN接收0中断 */
#define CAN_RX1_IRQChannel           ((u8)0x15)  /* CAN接收1中断 */
#define CAN_SCE_IRQChannel           ((u8)0x16)  /* CAN SCE中断 */
#define EXTI9_5_IRQChannel           ((u8)0x17)  /* 外部中断线9-5中断 */
#define TIM1_BRK_IRQChannel          ((u8)0x18)  /* TIM1 暂停中断 */
#define TIM1_UP_IRQChannel           ((u8)0x19)  /* TIM1 刷新中断 */
#define TIM1_TRG_COM_IRQChannel      ((u8)0x1A)  /* TIM1 触发和通讯中断 */
#define TIM1_CC_IRQChannel           ((u8)0x1B)  /* TIM1 捕获比较中断 */
#define TIM2_IRQChannel              ((u8)0x1C)  /* TIM2 全局中断 */
#define TIM3_IRQChannel              ((u8)0x1D)  /* TIM3 全局中断 */
#define TIM4_IRQChannel              ((u8)0x1E)  /* TIM4 全局中断 */
#define I2C1_EV_IRQChannel           ((u8)0x1F)  /* I2C1 事件中断 */
#define I2C1_ER_IRQChannel           ((u8)0x20)  /* I2C1 错误中断 */
#define I2C2_EV_IRQChannel           ((u8)0x21)  /* I2C2 事件中断 */
#define I2C2_ER_IRQChannel           ((u8)0x22)  /* I2C2 错误中断 */
#define SPI1_IRQChannel              ((u8)0x23)  /* SPI1 全局中断 */
#define SPI2_IRQChannel              ((u8)0x24)  /* SPI2 全局中断 */
#define USART1_IRQChannel            ((u8)0x25)  /* USART1 全局中断 */
#define USART2_IRQChannel            ((u8)0x26)  /* USART2 全局中断 */
#define USART3_IRQChannel            ((u8)0x27)  /* USART3 全局中断 */
#define EXTI15_10_IRQChannel         ((u8)0x28)  /* 外部中断线15-10中断 */
#define RTCAlarm_IRQChannel          ((u8)0x29)  /* RTC闹钟通过EXTI线中断 */
#define USBWakeUp_IRQChannel         ((u8)0x2A)  /* USB通过EXTI线从悬挂唤醒中断 */
#define TIM8_BRK_IRQChannel          ((u8)0x2B)  /* TIM8 Break Interrupt */
#define TIM8_UP_IRQChannel           ((u8)0x2C)  /* TIM8 Update Interrupt */
#define TIM8_TRG_COM_IRQChannel      ((u8)0x2D)  /* TIM8 Trigger and Commutation Interrupt */
#define TIM8_CC_IRQChannel           ((u8)0x2E)  /* TIM8 Capture Compare Interrupt */
#define ADC3_IRQChannel              ((u8)0x2F)  /* ADC3 global Interrupt */
#define FSMC_IRQChannel              ((u8)0x30)  /* FSMC global Interrupt */
#define SDIO_IRQChannel              ((u8)0x31)  /* SDIO global Interrupt */
#define TIM5_IRQChannel              ((u8)0x32)  /* TIM5 global Interrupt */
#define SPI3_IRQChannel              ((u8)0x33)  /* SPI3 global Interrupt */
#define UART4_IRQChannel             ((u8)0x34)  /* UART4 global Interrupt */
#define UART5_IRQChannel             ((u8)0x35)  /* UART5 global Interrupt */
#define TIM6_IRQChannel              ((u8)0x36)  /* TIM6 global Interrupt */
#define TIM7_IRQChannel              ((u8)0x37)  /* TIM7 global Interrupt */
#define DMA2_Channel1_IRQChannel     ((u8)0x38)  /* DMA2 Channel 1 global Interrupt */
#define DMA2_Channel2_IRQChannel     ((u8)0x39)  /* DMA2 Channel 2 global Interrupt */
#define DMA2_Channel3_IRQChannel     ((u8)0x3A)  /* DMA2 Channel 3 global Interrupt */
#define DMA2_Channel4_5_IRQChannel   ((u8)0x3B)  /* DMA2 Channel 4 and DMA2 Channel 5 global Interrupt */


#define IS_NVIC_IRQ_CHANNEL(CHANNEL) (((CHANNEL) == WWDG_IRQChannel) || \
                                      ((CHANNEL) == PVD_IRQChannel) || \
                                      ((CHANNEL) == TAMPER_IRQChannel) || \
                                      ((CHANNEL) == RTC_IRQChannel) || \
                                      ((CHANNEL) == FLASH_IRQChannel) || \
                                      ((CHANNEL) == RCC_IRQChannel) || \
                                      ((CHANNEL) == EXTI0_IRQChannel) || \
                                      ((CHANNEL) == EXTI1_IRQChannel) || \
                                      ((CHANNEL) == EXTI2_IRQChannel) || \
                                      ((CHANNEL) == EXTI3_IRQChannel) || \
                                      ((CHANNEL) == EXTI4_IRQChannel) || \
                                      ((CHANNEL) == DMA1_Channel1_IRQChannel) || \
                                      ((CHANNEL) == DMA1_Channel2_IRQChannel) || \
                                      ((CHANNEL) == DMA1_Channel3_IRQChannel) || \
                                      ((CHANNEL) == DMA1_Channel4_IRQChannel) || \
                                      ((CHANNEL) == DMA1_Channel5_IRQChannel) || \
                                      ((CHANNEL) == DMA1_Channel6_IRQChannel) || \
                                      ((CHANNEL) == DMA1_Channel7_IRQChannel) || \
                                      ((CHANNEL) == ADC1_2_IRQChannel) || \
                                      ((CHANNEL) == USB_HP_CAN_TX_IRQChannel) || \
                                      ((CHANNEL) == USB_LP_CAN_RX0_IRQChannel) || \
                                      ((CHANNEL) == CAN_RX1_IRQChannel) || \
                                      ((CHANNEL) == CAN_SCE_IRQChannel) || \
                                      ((CHANNEL) == EXTI9_5_IRQChannel) || \
                                      ((CHANNEL) == TIM1_BRK_IRQChannel) || \
                                      ((CHANNEL) == TIM1_UP_IRQChannel) || \
                                      ((CHANNEL) == TIM1_TRG_COM_IRQChannel) || \
                                      ((CHANNEL) == TIM1_CC_IRQChannel) || \
                                      ((CHANNEL) == TIM2_IRQChannel) || \
                                      ((CHANNEL) == TIM3_IRQChannel) || \
                                      ((CHANNEL) == TIM4_IRQChannel) || \
                                      ((CHANNEL) == I2C1_EV_IRQChannel) || \
                                      ((CHANNEL) == I2C1_ER_IRQChannel) || \
                                      ((CHANNEL) == I2C2_EV_IRQChannel) || \
                                      ((CHANNEL) == I2C2_ER_IRQChannel) || \
                                      ((CHANNEL) == SPI1_IRQChannel) || \
                                      ((CHANNEL) == SPI2_IRQChannel) || \
                                      ((CHANNEL) == USART1_IRQChannel) || \
                                      ((CHANNEL) == USART2_IRQChannel) || \
                                      ((CHANNEL) == USART3_IRQChannel) || \
                                      ((CHANNEL) == EXTI15_10_IRQChannel) || \
                                      ((CHANNEL) == RTCAlarm_IRQChannel) || \
                                      ((CHANNEL) == USBWakeUp_IRQChannel) || \
                                      ((CHANNEL) == TIM8_BRK_IRQChannel) || \
                                      ((CHANNEL) == TIM8_UP_IRQChannel) || \
                                      ((CHANNEL) == TIM8_TRG_COM_IRQChannel) || \
                                      ((CHANNEL) == TIM8_CC_IRQChannel) || \
                                      ((CHANNEL) == ADC3_IRQChannel) || \
                                      ((CHANNEL) == FSMC_IRQChannel) || \
                                      ((CHANNEL) == SDIO_IRQChannel) || \
                                      ((CHANNEL) == TIM5_IRQChannel) || \
                                      ((CHANNEL) == SPI3_IRQChannel) || \
                                      ((CHANNEL) == UART4_IRQChannel) || \
                                      ((CHANNEL) == UART5_IRQChannel) || \
                                      ((CHANNEL) == TIM6_IRQChannel) || \
                                      ((CHANNEL) == TIM7_IRQChannel) || \
                                      ((CHANNEL) == DMA2_Channel1_IRQChannel) || \
                                      ((CHANNEL) == DMA2_Channel2_IRQChannel) || \
                                      ((CHANNEL) == DMA2_Channel3_IRQChannel) || \
                                      ((CHANNEL) == DMA2_Channel4_5_IRQChannel))


/* System Handlers -----------------------------------------------------------*/
#define SystemHandler_NMI            ((u32)0x00001F) /* NMI Handler */
#define SystemHandler_HardFault      ((u32)0x000000) /* 硬件错误Handler */
#define SystemHandler_MemoryManage   ((u32)0x043430) /* 存储器管理Handler */
#define SystemHandler_BusFault       ((u32)0x547931) /* 总线错误Handler */
#define SystemHandler_UsageFault     ((u32)0x24C232) /* 使用错误Handler */
#define SystemHandler_SVCall         ((u32)0x01FF40) /* SVCall Handler */
#define SystemHandler_DebugMonitor   ((u32)0x0A0080) /* 除错监控Handler */
#define SystemHandler_PSV            ((u32)0x02829C) /* PSV Handler */
#define SystemHandler_SysTick        ((u32)0x02C39A) /* 系统滴答定时器Handler */

#define IS_CONFIG_SYSTEM_HANDLER(HANDLER) (((HANDLER) == SystemHandler_MemoryManage) || \
                                           ((HANDLER) == SystemHandler_BusFault) || \
                                           ((HANDLER) == SystemHandler_UsageFault))

#define IS_PRIORITY_SYSTEM_HANDLER(HANDLER) (((HANDLER) == SystemHandler_MemoryManage) || \
                                             ((HANDLER) == SystemHandler_BusFault) || \
                                             ((HANDLER) == SystemHandler_UsageFault) || \
                                             ((HANDLER) == SystemHandler_SVCall) || \
                                             ((HANDLER) == SystemHandler_DebugMonitor) || \
                                             ((HANDLER) == SystemHandler_PSV) || \
                                             ((HANDLER) == SystemHandler_SysTick))

#define IS_GET_PENDING_SYSTEM_HANDLER(HANDLER) (((HANDLER) == SystemHandler_MemoryManage) || \
                                                ((HANDLER) == SystemHandler_BusFault) || \
                                                ((HANDLER) == SystemHandler_SVCall))

#define IS_SET_PENDING_SYSTEM_HANDLER(HANDLER) (((HANDLER) == SystemHandler_NMI) || \
                                                ((HANDLER) == SystemHandler_PSV) || \
                                                ((HANDLER) == SystemHandler_SysTick))

#define IS_CLEAR_SYSTEM_HANDLER(HANDLER) (((HANDLER) == SystemHandler_PSV) || \
                                          ((HANDLER) == SystemHandler_SysTick))

#define IS_GET_ACTIVE_SYSTEM_HANDLER(HANDLER) (((HANDLER) == SystemHandler_MemoryManage) || \
                                               ((HANDLER) == SystemHandler_BusFault) || \
                                               ((HANDLER) == SystemHandler_UsageFault) || \
                                               ((HANDLER) == SystemHandler_SVCall) || \
                                               ((HANDLER) == SystemHandler_DebugMonitor) || \
                                               ((HANDLER) == SystemHandler_PSV) || \
                                               ((HANDLER) == SystemHandler_SysTick))

#define IS_FAULT_SOURCE_SYSTEM_HANDLER(HANDLER) (((HANDLER) == SystemHandler_HardFault) || \
                                                 ((HANDLER) == SystemHandler_MemoryManage) || \
                                                 ((HANDLER) == SystemHandler_BusFault) || \
                                                 ((HANDLER) == SystemHandler_UsageFault) || \
                                                 ((HANDLER) == SystemHandler_DebugMonitor)) 

#define IS_FAULT_ADDRESS_SYSTEM_HANDLER(HANDLER) (((HANDLER) == SystemHandler_MemoryManage) || \
                                                  ((HANDLER) == SystemHandler_BusFault))


/* Vector Table Base ---------------------------------------------------------*/
#define NVIC_VectTab_RAM             ((u32)0x20000000) // 向量表位于RAM	；
#define NVIC_VectTab_FLASH           ((u32)0x08000000) // 向量表位于FLASH ；

#define IS_NVIC_VECTTAB(VECTTAB) (((VECTTAB) == NVIC_VectTab_RAM) || \
                                  ((VECTTAB) == NVIC_VectTab_FLASH))

/* System Low Power ----------------------------------------------------------*/
#define NVIC_LP_SEVONPEND            ((u8)0x10)	 // 根据待处理请求唤醒 ；
#define NVIC_LP_SLEEPDEEP            ((u8)0x04)	 // 深度睡眠使能 ；
#define NVIC_LP_SLEEPONEXIT          ((u8)0x02)	 // 退出ISR后睡眠 ；

#define IS_NVIC_LP(LP) (((LP) == NVIC_LP_SEVONPEND) || \
                        ((LP) == NVIC_LP_SLEEPDEEP) || \
                        ((LP) == NVIC_LP_SLEEPONEXIT))

/* Preemption Priority Group -------------------------------------------------*/
#define NVIC_PriorityGroup_0         ((u32)0x700) /* 先占优先级0位，从优先级4位 */
#define NVIC_PriorityGroup_1         ((u32)0x600) /* 先占优先级1位，从优先级3位 */
#define NVIC_PriorityGroup_2         ((u32)0x500) /* 先占优先级2位，从优先级2位 */
#define NVIC_PriorityGroup_3         ((u32)0x400) /* 先占优先级3位，从优先级1位 */
#define NVIC_PriorityGroup_4         ((u32)0x300) /* 先占优先级4位，从优先级0位 */

#define IS_NVIC_PRIORITY_GROUP(GROUP) (((GROUP) == NVIC_PriorityGroup_0) || \
                                       ((GROUP) == NVIC_PriorityGroup_1) || \
                                       ((GROUP) == NVIC_PriorityGroup_2) || \
                                       ((GROUP) == NVIC_PriorityGroup_3) || \
                                       ((GROUP) == NVIC_PriorityGroup_4))

#define IS_NVIC_PREEMPTION_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10)
#define IS_NVIC_SUB_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10)
#define IS_NVIC_OFFSET(OFFSET)  ((OFFSET) < 0x0007FFFF)
#define IS_NVIC_BASE_PRI(PRI)   ((PRI) < 0x10)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void NVIC_DeInit(void);
void NVIC_SCBDeInit(void);
void NVIC_PriorityGroupConfig(u32 NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_StructInit(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SETPRIMASK(void);
void NVIC_RESETPRIMASK(void);
void NVIC_SETFAULTMASK(void);
void NVIC_RESETFAULTMASK(void);
void NVIC_BASEPRICONFIG(u32 NewPriority);
u32 NVIC_GetBASEPRI(void);
u16 NVIC_GetCurrentPendingIRQChannel(void);
ITStatus NVIC_GetIRQChannelPendingBitStatus(u8 NVIC_IRQChannel);
void NVIC_SetIRQChannelPendingBit(u8 NVIC_IRQChannel);
void NVIC_ClearIRQChannelPendingBit(u8 NVIC_IRQChannel);
u16 NVIC_GetCurrentActiveHandler(void);
ITStatus NVIC_GetIRQChannelActiveBitStatus(u8 NVIC_IRQChannel);
u32 NVIC_GetCPUID(void);
void NVIC_SetVectorTable(u32 NVIC_VectTab, u32 Offset);
void NVIC_GenerateSystemReset(void);
void NVIC_GenerateCoreReset(void);
void NVIC_SystemLPConfig(u8 LowPowerMode, FunctionalState NewState);
void NVIC_SystemHandlerConfig(u32 SystemHandler, FunctionalState NewState);
void NVIC_SystemHandlerPriorityConfig(u32 SystemHandler, u8 SystemHandlerPreemptionPriority,
                                      u8 SystemHandlerSubPriority);
ITStatus NVIC_GetSystemHandlerPendingBitStatus(u32 SystemHandler);
void NVIC_SetSystemHandlerPendingBit(u32 SystemHandler);
void NVIC_ClearSystemHandlerPendingBit(u32 SystemHandler);
ITStatus NVIC_GetSystemHandlerActiveBitStatus(u32 SystemHandler);
u32 NVIC_GetFaultHandlerSources(u32 SystemHandler);
u32 NVIC_GetFaultAddress(u32 SystemHandler);

#endif /* __STM32F10x_NVIC_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
