/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_spi.h
* Author             : MCD Application Team
* Version            : V2.0
* Date               : 05/23/2008
* Description        : This file contains all the functions prototypes for the
*                      SPI firmware library.
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
#ifndef __STM32F10x_SPI_H
#define __STM32F10x_SPI_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_map.h"

/* Exported types ------------------------------------------------------------*/
/* SPI Init structure definition */
typedef struct
{
  u16 SPI_Direction; // 设置了SPI单向或者双向的数据模式 ；
  u16 SPI_Mode;		 // 设置了SPI工作模式 ；
  u16 SPI_DataSize;	// 设置了SPI的数据大小 ；
  u16 SPI_CPOL;	 // 选择了串行时钟的稳态 ；
  u16 SPI_CPHA;	 // 设置了位捕获的时钟活动沿 ；
  u16 SPI_NSS;	 // 指定了NSS信号由硬件（NSS管脚）还是软件（使用SSI位）管理
  u16 SPI_BaudRatePrescaler; // 用来定义波特率预分频的值 ；
  u16 SPI_FirstBit;	  // 指定了数据传输从MSB位还是LSB位开始 ；
  u16 SPI_CRCPolynomial; // 定义了用于CRC值计算的多项式。
}SPI_InitTypeDef;

/* I2S Init structure definition */
typedef struct
{
  u16 I2S_Mode;
  u16 I2S_Standard;
  u16 I2S_DataFormat;
  u16 I2S_MCLKOutput;
  u16 I2S_AudioFreq;
  u16 I2S_CPOL;
}I2S_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

#define IS_SPI_ALL_PERIPH(PERIPH) (((*(u32*)&(PERIPH)) == SPI1_BASE) || \
                                   ((*(u32*)&(PERIPH)) == SPI2_BASE) || \
                                   ((*(u32*)&(PERIPH)) == SPI3_BASE))

#define IS_SPI_23_PERIPH(PERIPH) (((*(u32*)&(PERIPH)) == SPI2_BASE) || \
                                  ((*(u32*)&(PERIPH)) == SPI3_BASE))

/* SPI data direction mode */
#define SPI_Direction_2Lines_FullDuplex ((u16)0x0000) // SPI设置为双线双向全双工 ；
#define SPI_Direction_2Lines_RxOnly     ((u16)0x0400) // SPI设置为双线单向接收 ；
#define SPI_Direction_1Line_Rx          ((u16)0x8000) // SPI设置为单线双向接收 ；
#define SPI_Direction_1Line_Tx          ((u16)0xC000) // SPI设置为单线双向发送 ；

#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_Direction_2Lines_FullDuplex) || \
                                     ((MODE) == SPI_Direction_2Lines_RxOnly) || \
                                     ((MODE) == SPI_Direction_1Line_Rx) || \
                                     ((MODE) == SPI_Direction_1Line_Tx))

/* SPI master/slave mode */
#define SPI_Mode_Master                 ((u16)0x0104) // 设置为主SPI ；
#define SPI_Mode_Slave                  ((u16)0x0000) // 设置为从SPI ；

#define IS_SPI_MODE(MODE) (((MODE) == SPI_Mode_Master) || \
                           ((MODE) == SPI_Mode_Slave))

/* SPI data size */
#define SPI_DataSize_16b                ((u16)0x0800) // SPI发送接收16位帧结构 ；
#define SPI_DataSize_8b                 ((u16)0x0000) // SPI发送接收8位帧结构 ；

#define IS_SPI_DATASIZE(DATASIZE) (((DATASIZE) == SPI_DataSize_16b) || \
                                   ((DATASIZE) == SPI_DataSize_8b))

/* SPI Clock Polarity */
#define SPI_CPOL_Low                    ((u16)0x0000) // 时钟悬空低 ；
#define SPI_CPOL_High                   ((u16)0x0002) // 时钟悬空高 ；

#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_CPOL_Low) || \
                           ((CPOL) == SPI_CPOL_High))

/* SPI Clock Phase */
#define SPI_CPHA_1Edge                  ((u16)0x0000) // 数据捕获于第一个时钟沿 ；
#define SPI_CPHA_2Edge                  ((u16)0x0001) // 数据捕获于第二个时钟沿 ；

#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_CPHA_1Edge) || \
                           ((CPHA) == SPI_CPHA_2Edge))

/* SPI Slave Select management */
#define SPI_NSS_Soft                    ((u16)0x0200) // 内部NSS信号有SSI位控制
#define SPI_NSS_Hard                    ((u16)0x0000) // NSS由外部管脚管理 ；

#define IS_SPI_NSS(NSS) (((NSS) == SPI_NSS_Soft) || \
                         ((NSS) == SPI_NSS_Hard))                         

/* SPI BaudRate Prescaler  */
#define SPI_BaudRatePrescaler_2         ((u16)0x0000) // 波特率预分频值为2 ；
#define SPI_BaudRatePrescaler_4         ((u16)0x0008) // 波特率预分频值为4 ；
#define SPI_BaudRatePrescaler_8         ((u16)0x0010) // 波特率预分频值为8 ；
#define SPI_BaudRatePrescaler_16        ((u16)0x0018) // 波特率预分频值为16 ；
#define SPI_BaudRatePrescaler_32        ((u16)0x0020) // 波特率预分频值为32 ；
#define SPI_BaudRatePrescaler_64        ((u16)0x0028) // 波特率预分频值为64 ；
#define SPI_BaudRatePrescaler_128       ((u16)0x0030) // 波特率预分频值为128 ；
#define SPI_BaudRatePrescaler_256       ((u16)0x0038) // 波特率预分频值为256 ；

#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) (((PRESCALER) == SPI_BaudRatePrescaler_2) || \
                                              ((PRESCALER) == SPI_BaudRatePrescaler_4) || \
                                              ((PRESCALER) == SPI_BaudRatePrescaler_8) || \
                                              ((PRESCALER) == SPI_BaudRatePrescaler_16) || \
                                              ((PRESCALER) == SPI_BaudRatePrescaler_32) || \
                                              ((PRESCALER) == SPI_BaudRatePrescaler_64) || \
                                              ((PRESCALER) == SPI_BaudRatePrescaler_128) || \
                                              ((PRESCALER) == SPI_BaudRatePrescaler_256))

/* SPI MSB/LSB transmission */
#define SPI_FirstBit_MSB                ((u16)0x0000) // 数据传输从MSB位开始 ；
#define SPI_FirstBit_LSB                ((u16)0x0080) // 数据传输从LSB位开始 ；

#define IS_SPI_FIRST_BIT(BIT) (((BIT) == SPI_FirstBit_MSB) || \
                               ((BIT) == SPI_FirstBit_LSB))

/* I2S Mode */
#define I2S_Mode_SlaveTx                ((u16)0x0000)
#define I2S_Mode_SlaveRx                ((u16)0x0100)
#define I2S_Mode_MasterTx               ((u16)0x0200)
#define I2S_Mode_MasterRx               ((u16)0x0300)

#define IS_I2S_MODE(MODE) (((MODE) == I2S_Mode_SlaveTx) || \
                           ((MODE) == I2S_Mode_SlaveRx) || \
                           ((MODE) == I2S_Mode_MasterTx) || \
                           ((MODE) == I2S_Mode_MasterRx) )

/* I2S Standard */
#define I2S_Standard_Phillips           ((u16)0x0000)
#define I2S_Standard_MSB                ((u16)0x0010)
#define I2S_Standard_LSB                ((u16)0x0020)
#define I2S_Standard_PCMShort           ((u16)0x0030)
#define I2S_Standard_PCMLong            ((u16)0x00B0)

#define IS_I2S_STANDARD(STANDARD) (((STANDARD) == I2S_Standard_Phillips) || \
                                   ((STANDARD) == I2S_Standard_MSB) || \
                                   ((STANDARD) == I2S_Standard_LSB) || \
                                   ((STANDARD) == I2S_Standard_PCMShort) || \
                                   ((STANDARD) == I2S_Standard_PCMLong))

/* I2S Data Format */
#define I2S_DataFormat_16b              ((u16)0x0000)
#define I2S_DataFormat_16bextended      ((u16)0x0001)
#define I2S_DataFormat_24b              ((u16)0x0003)
#define I2S_DataFormat_32b              ((u16)0x0005)

#define IS_I2S_DATA_FORMAT(FORMAT) (((FORMAT) == I2S_DataFormat_16b) || \
                                    ((FORMAT) == I2S_DataFormat_16bextended) || \
                                    ((FORMAT) == I2S_DataFormat_24b) || \
                                    ((FORMAT) == I2S_DataFormat_32b))

/* I2S MCLK Output */ 
#define I2S_MCLKOutput_Enable           ((u16)0x0200)
#define I2S_MCLKOutput_Disable          ((u16)0x0000)

#define IS_I2S_MCLK_OUTPUT(OUTPUT) (((OUTPUT) == I2S_MCLKOutput_Enable) || \
                                    ((OUTPUT) == I2S_MCLKOutput_Disable))

/* I2S Audio Frequency */
#define I2S_AudioFreq_48k                ((u16)48000)
#define I2S_AudioFreq_44k                ((u16)44100)
#define I2S_AudioFreq_22k                ((u16)22050)
#define I2S_AudioFreq_16k                ((u16)16000)
#define I2S_AudioFreq_8k                 ((u16)8000)
#define I2S_AudioFreq_Default            ((u16)2)

#define IS_I2S_AUDIO_FREQ(FREQ) (((FREQ) == I2S_AudioFreq_48k) || \
                                 ((FREQ) == I2S_AudioFreq_44k) || \
                                 ((FREQ) == I2S_AudioFreq_22k) || \
                                 ((FREQ) == I2S_AudioFreq_16k) || \
                                 ((FREQ) == I2S_AudioFreq_8k)  || \
                                 ((FREQ) == I2S_AudioFreq_Default))

/* I2S Clock Polarity */
#define I2S_CPOL_Low                    ((u16)0x0000)
#define I2S_CPOL_High                   ((u16)0x0008)

#define IS_I2S_CPOL(CPOL) (((CPOL) == I2S_CPOL_Low) || \
                           ((CPOL) == I2S_CPOL_High))

/* SPI_I2S DMA transfer requests */
#define SPI_I2S_DMAReq_Tx               ((u16)0x0002) // 选择Tx缓存DMA传输请求 ；
#define SPI_I2S_DMAReq_Rx               ((u16)0x0001) // 选择Rx缓存DMA传输请求 ；

#define IS_SPI_I2S_DMAREQ(DMAREQ) ((((DMAREQ) & (u16)0xFFFC) == 0x00) && ((DMAREQ) != 0x00))

/* SPI NSS internal software mangement */
#define SPI_NSSInternalSoft_Set         ((u16)0x0100) // 内部设置NSS管脚 ；
#define SPI_NSSInternalSoft_Reset       ((u16)0xFEFF) // 内部重置NSS管脚 ；

#define IS_SPI_NSS_INTERNAL(INTERNAL) (((INTERNAL) == SPI_NSSInternalSoft_Set) || \
                                       ((INTERNAL) == SPI_NSSInternalSoft_Reset))

/* SPI CRC Transmit/Receive */
#define SPI_CRC_Tx                      ((u8)0x00)	// 选择Tx CRC寄存器 ；
#define SPI_CRC_Rx                      ((u8)0x01)	// 选择Rx CRC寄存器 ；

#define IS_SPI_CRC(CRC) (((CRC) == SPI_CRC_Tx) || ((CRC) == SPI_CRC_Rx))

/* SPI direction transmit/receive */
#define SPI_Direction_Rx                ((u16)0xBFFF) // 选择Rx接受方向 ；
#define SPI_Direction_Tx                ((u16)0x4000) // 选择Tx发送方向 ；

#define IS_SPI_DIRECTION(DIRECTION) (((DIRECTION) == SPI_Direction_Rx) || \
                                     ((DIRECTION) == SPI_Direction_Tx))

/* SPI_I2S interrupts definition */
#define SPI_I2S_IT_TXE                  ((u8)0x71) // 发送缓存空中断屏蔽 ；
#define SPI_I2S_IT_RXNE                 ((u8)0x60) // 接收缓存非空中断屏蔽 ；
#define SPI_I2S_IT_ERR                  ((u8)0x50) // 错误中断屏蔽 ；

#define IS_SPI_I2S_CONFIG_IT(IT) (((IT) == SPI_I2S_IT_TXE) || \
                                 ((IT) == SPI_I2S_IT_RXNE) || \
                                 ((IT) == SPI_I2S_IT_ERR))

#define SPI_I2S_IT_OVR                  ((u8)0x56) // 超出中断标志位 ；
#define SPI_IT_MODF                     ((u8)0x55) // 模式错误标志位 ；
#define SPI_IT_CRCERR                   ((u8)0x54) // CRC错误标志位 ；
#define I2S_IT_UDR                      ((u8)0x53)

#define IS_SPI_I2S_CLEAR_IT(IT) (((IT) == SPI_I2S_IT_OVR) || \
                                 ((IT) == SPI_IT_MODF) || \
                                 ((IT) == SPI_IT_CRCERR) || \
                                 ((IT) == I2S_IT_UDR))

#define IS_SPI_I2S_GET_IT(IT) (((IT) == SPI_I2S_IT_RXNE) || ((IT) == SPI_I2S_IT_TXE) || \
                               ((IT) == I2S_IT_UDR) || ((IT) == SPI_IT_CRCERR) || \
                               ((IT) == SPI_IT_MODF) || ((IT) == SPI_I2S_IT_OVR))

/* SPI_I2S flags definition */
#define SPI_I2S_FLAG_RXNE               ((u16)0x0001) // 接受缓存非空标志位 ；
#define SPI_I2S_FLAG_TXE                ((u16)0x0002) // 发送缓存空标志位 ；
#define I2S_FLAG_CHSIDE                 ((u16)0x0004) //
#define I2S_FLAG_UDR                    ((u16)0x0008) //
#define SPI_FLAG_CRCERR                 ((u16)0x0010) // CRC错误标志位 ；
#define SPI_FLAG_MODF                   ((u16)0x0020) // 模式错位标志位 ；
#define SPI_I2S_FLAG_OVR                ((u16)0x0040) // 超出标志位 ；
#define SPI_I2S_FLAG_BSY                ((u16)0x0080) // 忙标志位 ；

#define IS_SPI_I2S_CLEAR_FLAG(FLAG) (((FLAG) == SPI_I2S_FLAG_OVR) || ((FLAG) == SPI_FLAG_MODF) || \
                                     ((FLAG) == SPI_FLAG_CRCERR) || ((FLAG) == I2S_FLAG_UDR))
#define IS_SPI_I2S_GET_FLAG(FLAG) (((FLAG) == SPI_I2S_FLAG_BSY) || ((FLAG) == SPI_I2S_FLAG_OVR) || \
                                   ((FLAG) == SPI_FLAG_MODF) || ((FLAG) == SPI_FLAG_CRCERR) || \
                                   ((FLAG) == I2S_FLAG_UDR) || ((FLAG) == I2S_FLAG_CHSIDE) || \
                                   ((FLAG) == SPI_I2S_FLAG_TXE) || ((FLAG) == SPI_I2S_FLAG_RXNE))

/* SPI CRC polynomial --------------------------------------------------------*/
#define IS_SPI_CRC_POLYNOMIAL(POLYNOMIAL) ((POLYNOMIAL) >= 0x1)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void SPI_I2S_DeInit(SPI_TypeDef* SPIx);
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct);
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void I2S_StructInit(I2S_InitTypeDef* I2S_InitStruct);
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, u8 SPI_I2S_IT, FunctionalState NewState);
void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, u16 SPI_I2S_DMAReq, FunctionalState NewState);
void SPI_I2S_SendData(SPI_TypeDef* SPIx, u16 Data);
u16 SPI_I2S_ReceiveData(SPI_TypeDef* SPIx);
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, u16 SPI_NSSInternalSoft);
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, u16 SPI_DataSize);
void SPI_TransmitCRC(SPI_TypeDef* SPIx);
void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState);
u16 SPI_GetCRC(SPI_TypeDef* SPIx, u8 SPI_CRC);
u16 SPI_GetCRCPolynomial(SPI_TypeDef* SPIx);
void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, u16 SPI_Direction);
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, u16 SPI_I2S_FLAG);
void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, u16 SPI_I2S_FLAG);
ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, u8 SPI_I2S_IT);
void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, u8 SPI_I2S_IT);

#endif /*__STM32F10x_SPI_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
