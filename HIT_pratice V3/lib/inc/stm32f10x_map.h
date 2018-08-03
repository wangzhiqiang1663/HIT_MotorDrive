/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_map.h
* Author             : MCD Application Team
* Version            : V2.0
* Date               : 05/23/2008
* Description        : This file contains all the peripheral register's definitions
*                      and memory mapping.
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
#ifndef __STM32F10x_MAP_H
#define __STM32F10x_MAP_H

#ifndef EXT
  #define EXT extern
#endif /* EXT */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_conf.h"
#include "stm32f10x_type.h"
#include "cortexm3_macro.h"

/* Exported types ------------------------------------------------------------*/
/******************************************************************************/
/*                         Peripheral registers structures                    */
/******************************************************************************/

/*------------------------ Analog to Digital Converter -----------------------*/
typedef struct
{
  vu32 SR;	  // ADC状态寄存器 ；
  vu32 CR1;	  // ADC控制寄存器1 ；
  vu32 CR2;	  // ADC控制寄存器2 ；
  vu32 SMPR1; // ADC采样时间寄存器1 ；
  vu32 SMPR2; // ADC采样时间寄存器2 ；
  vu32 JOFR1; // ADC注入通道偏移寄存器1 ；
  vu32 JOFR2; // ADC注入通道偏移寄存器2 ；
  vu32 JOFR3; // ADC注入通道偏移寄存器3 ；
  vu32 JOFR4; // ADC注入通道偏移寄存器4 ；
  vu32 HTR;	 // ADC看门狗高阈值寄存器 ；
  vu32 LTR;	 // ADC看门狗低阈值寄存器 ；
  vu32 SQR1; // ADC规则序列寄存器1 ；
  vu32 SQR2; // ADC规则序列寄存器2 ；
  vu32 SQR3; // ADC规则序列寄存器3 ；
  vu32 JSQR; // ADC注入序列寄存器 ；
  vu32 JDR1; // ADC规则数据寄存器1 ；
  vu32 JDR2; // ADC规则数据寄存器2 ；
  vu32 JDR3; // ADC规则数据寄存器3 ；
  vu32 JDR4; // ADC规则数据寄存器4 ；
  vu32 DR;	 // 规则数据寄存器 ;
} ADC_TypeDef;

/*------------------------ Backup Registers ----------------------------------*/
typedef struct
{
  u32  RESERVED0;
  vu16 DR1;		   // 数据后备寄存器 1 ； 
  u16  RESERVED1;
  vu16 DR2;		   // 数据后备寄存器 2 ；
  u16  RESERVED2;
  vu16 DR3;		   // 数据后备寄存器 3 ；
  u16  RESERVED3;
  vu16 DR4;		   // 数据后备寄存器 4 ；
  u16  RESERVED4;
  vu16 DR5;		   // 数据后备寄存器 5 ；
  u16  RESERVED5;
  vu16 DR6;		   // 数据后备寄存器 6 ；
  u16  RESERVED6;
  vu16 DR7;		   // 数据后备寄存器 7 ；
  u16  RESERVED7;
  vu16 DR8;		   // 数据后备寄存器 8 ；
  u16  RESERVED8;
  vu16 DR9;		   // 数据后备寄存器 9 ；
  u16  RESERVED9;
  vu16 DR10;	   // 数据后备寄存器 10 ；
  u16  RESERVED10; 
  vu16 RTCCR;	   // RTC时钟校准寄存器 ；
  u16  RESERVED11;
  vu16 CR;		   // 后备控制寄存器 ；
  u16  RESERVED12;
  vu16 CSR;		   // 后备控制状态寄存器 ；
  u16  RESERVED13[5];
  vu16 DR11;
  u16  RESERVED14;
  vu16 DR12;
  u16  RESERVED15;
  vu16 DR13;
  u16  RESERVED16;
  vu16 DR14;
  u16  RESERVED17;
  vu16 DR15;
  u16  RESERVED18;
  vu16 DR16;
  u16  RESERVED19;
  vu16 DR17;
  u16  RESERVED20;
  vu16 DR18;
  u16  RESERVED21;
  vu16 DR19;
  u16  RESERVED22;
  vu16 DR20;				  
  u16  RESERVED23;
  vu16 DR21;
  u16  RESERVED24;
  vu16 DR22;
  u16  RESERVED25;
  vu16 DR23;
  u16  RESERVED26;
  vu16 DR24;
  u16  RESERVED27;
  vu16 DR25;
  u16  RESERVED28;
  vu16 DR26;
  u16  RESERVED29;
  vu16 DR27;
  u16  RESERVED30;
  vu16 DR28;
  u16  RESERVED31;
  vu16 DR29;
  u16  RESERVED32;
  vu16 DR30;
  u16  RESERVED33; 
  vu16 DR31;
  u16  RESERVED34;
  vu16 DR32;
  u16  RESERVED35;
  vu16 DR33;
  u16  RESERVED36;
  vu16 DR34;
  u16  RESERVED37;
  vu16 DR35;
  u16  RESERVED38;
  vu16 DR36;
  u16  RESERVED39;
  vu16 DR37;
  u16  RESERVED40;
  vu16 DR38;
  u16  RESERVED41;
  vu16 DR39;
  u16  RESERVED42;
  vu16 DR40;
  u16  RESERVED43;
  vu16 DR41;
  u16  RESERVED44;
  vu16 DR42;
  u16  RESERVED45;    
} BKP_TypeDef;

/*------------------------ Controller Area Network ---------------------------*/
typedef struct
{
  vu32 TIR;
  vu32 TDTR;
  vu32 TDLR;
  vu32 TDHR;
} CAN_TxMailBox_TypeDef;

typedef struct
{
  vu32 RIR;
  vu32 RDTR;
  vu32 RDLR;
  vu32 RDHR;
} CAN_FIFOMailBox_TypeDef;

typedef struct
{
  vu32 FR1;
  vu32 FR2;
} CAN_FilterRegister_TypeDef;

typedef struct
{
  vu32 MCR;
  vu32 MSR;
  vu32 TSR;
  vu32 RF0R;
  vu32 RF1R;
  vu32 IER;
  vu32 ESR;
  vu32 BTR;
  u32  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  u32  RESERVED1[12];
  vu32 FMR;
  vu32 FM1R;
  u32  RESERVED2;
  vu32 FS1R;
  u32  RESERVED3;
  vu32 FFA1R;
  u32  RESERVED4;
  vu32 FA1R;
  u32  RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;

/*------------------------ CRC calculation unit ------------------------------*/
typedef struct
{
  vu32 DR;
  vu8  IDR;
  u8   RESERVED0;
  u16  RESERVED1;
  vu32 CR;
} CRC_TypeDef;


/*------------------------ Digital to Analog Converter -----------------------*/
typedef struct
{
  vu32 CR;
  vu32 SWTRIGR;
  vu32 DHR12R1;
  vu32 DHR12L1;
  vu32 DHR8R1;
  vu32 DHR12R2;
  vu32 DHR12L2;
  vu32 DHR8R2;
  vu32 DHR12RD;
  vu32 DHR12LD;
  vu32 DHR8RD;
  vu32 DOR1;
  vu32 DOR2;
} DAC_TypeDef;

/*------------------------ Debug MCU -----------------------------------------*/
typedef struct
{
  vu32 IDCODE;
  vu32 CR;	
}DBGMCU_TypeDef;

/*------------------------ DMA Controller ------------------------------------*/
typedef struct
{
  vu32 CCR;	   // DMA通道X设置寄存器 ；
  vu32 CNDTR;  // DMA通道X待传输数据数目寄存器 ；
  vu32 CPAR;   // DMA通道X外设地址寄存器 ；
  vu32 CMAR;   // DMA通道X内存地址寄存器 ；
} DMA_Channel_TypeDef;

typedef struct
{
  vu32 ISR;	   // DMA中断状态寄存器 ；
  vu32 IFCR;   // DMA中断标志位清除寄存器 ；
} DMA_TypeDef;

/*------------------------ External Interrupt/Event Controller ---------------*/
typedef struct
{
  vu32 IMR;	  // 中断屏蔽寄存器 ；
  vu32 EMR;	  // 事件屏蔽寄存器 ；
  vu32 RTSR;  // 上升沿触发选择寄存器 ；
  vu32 FTSR;  // 下降沿触发选择寄存器 ；
  vu32 SWIER; // 软件中断事件寄存器 ；
  vu32 PR;	  // 挂起寄存器 ；
} EXTI_TypeDef;

/*------------------------ FLASH and Option Bytes Registers ------------------*/
typedef struct
{
  vu32 ACR;	    // FLASH访问控制寄存器 ；
  vu32 KEYR;    // FPEC密钥寄存器 ；
  vu32 OPTKEYR;	// 选择字节密钥寄存器 ；
  vu32 SR;		// FLASH状态寄存器 ；
  vu32 CR;		// FLASH控制寄存器 ；
  vu32 AR;		// FLASH地址寄存器 ；
  vu32 RESERVED; //
  vu32 OBR;		// 选择字节和状态寄存器 ；
  vu32 WRPR;	// 选择字节写保护寄存器 ；
} FLASH_TypeDef;

typedef struct
{
  vu16 RDP;	  // 读出选择字节 ；
  vu16 USER;  // 用户选择字节 ；
  vu16 Data0; // Data0选择字节 ；
  vu16 Data1; // Data1选择字节 ；
  vu16 WRP0;  // 写保护0选择字节 ；
  vu16 WRP1;  // 写保护1选择字节
  vu16 WRP2;  // 写保护2选择字节
  vu16 WRP3;  // 写保护3选择字节
} OB_TypeDef;

/*------------------------ Flexible Static Memory Controller -----------------*/
typedef struct
{
  vu32 BTCR[8];   
} FSMC_Bank1_TypeDef; 

typedef struct
{
  vu32 BWTR[7];
} FSMC_Bank1E_TypeDef;

typedef struct
{
  vu32 PCR2;
  vu32 SR2;
  vu32 PMEM2;
  vu32 PATT2;
  u32  RESERVED0;   
  vu32 ECCR2; 
} FSMC_Bank2_TypeDef;  

typedef struct
{
  vu32 PCR3;
  vu32 SR3;
  vu32 PMEM3;
  vu32 PATT3;
  u32  RESERVED0;   
  vu32 ECCR3; 
} FSMC_Bank3_TypeDef; 

typedef struct
{
  vu32 PCR4;
  vu32 SR4;
  vu32 PMEM4;
  vu32 PATT4;
  vu32 PIO4; 
} FSMC_Bank4_TypeDef; 

/*------------------------ General Purpose and Alternate Function IO ---------*/
typedef struct
{
  vu32 CRL;	  // 端口配置低寄存器 ；
  vu32 CRH;	  // 端口配置高寄存器 ；
  vu32 IDR;	  // 端口输入数据寄存器 ；
  vu32 ODR;	  // 端口输出数据寄存器 ；
  vu32 BSRR;  // 端口位设置/复位寄存器 ；
  vu32 BRR;	  // 端口位复位寄存器 ；
  vu32 LCKR;  // 端口配置锁定寄存器 ；
} GPIO_TypeDef;

typedef struct
{
  vu32 EVCR;     // 事件控制寄存器 ；
  vu32 MAPR;	 // 复用重映射和调试I/O配置寄存器 ；
  vu32 EXTICR[4];// 外部中断线路0-15配置寄存器 ；
} AFIO_TypeDef;

/*------------------------ Inter-integrated Circuit Interface ----------------*/
typedef struct
{
  vu16 CR1;
  u16  RESERVED0;
  vu16 CR2;
  u16  RESERVED1;
  vu16 OAR1;
  u16  RESERVED2;
  vu16 OAR2;
  u16  RESERVED3;
  vu16 DR;
  u16  RESERVED4;
  vu16 SR1;
  u16  RESERVED5;
  vu16 SR2;
  u16  RESERVED6;
  vu16 CCR;
  u16  RESERVED7;
  vu16 TRISE;
  u16  RESERVED8;
} I2C_TypeDef;

/*------------------------ Independent WATCHDOG ------------------------------*/
typedef struct
{
  vu32 KR;	// IWDG键值寄存器 ；
  vu32 PR;	// IWDG预分频寄存器 ；
  vu32 RLR;	// IWDG重装载寄存器 ；
  vu32 SR;	// IWDG状态寄存器 ；
} IWDG_TypeDef;

/*------------------------ Nested Vectored Interrupt Controller --------------*/
typedef struct
{
  vu32 ISER[2];		  //
  u32  RESERVED0[30]; //
  vu32 ICER[2];		  //
  u32  RSERVED1[30];  //
  vu32 ISPR[2];		  //
  u32  RESERVED2[30];
  vu32 ICPR[2];
  u32  RESERVED3[30];
  vu32 IABR[2];
  u32  RESERVED4[62];
  vu32 IPR[15];
} NVIC_TypeDef;

typedef struct
{
  vuc32 CPUID;	 // CPU ID 基寄存器 ;
  vu32 ICSR;	 //
  vu32 VTOR;	 //
  vu32 AIRCR;	 //
  vu32 SCR;
  vu32 CCR;
  vu32 SHPR[3];
  vu32 SHCSR;
  vu32 CFSR;
  vu32 HFSR;
  vu32 DFSR;
  vu32 MMFAR;
  vu32 BFAR;
  vu32 AFSR;
} SCB_TypeDef;

/*------------------------ Power Control -------------------------------------*/
typedef struct
{
  vu32 CR;
  vu32 CSR;
} PWR_TypeDef;

/*------------------------ Reset and Clock Control ---------------------------*/
typedef struct
{
  vu32 CR;	     // 时钟控制寄存器 ；
  vu32 CFGR;	 // 时钟配置寄存器 ；
  vu32 CIR;		 // 时钟中断寄存器 ；
  vu32 APB2RSTR; // APB2外设复位寄存器 ；
  vu32 APB1RSTR; // APB1外设复位寄存器 ；
  vu32 AHBENR;	 // AHB外设时钟使能寄存器 ；
  vu32 APB2ENR;	 // APB2外设时钟使能寄存器 ；
  vu32 APB1ENR;	 // APB1外设时钟使能寄存器 ；
  vu32 BDCR;	 // 备份域控制寄存器 ；
  vu32 CSR;		 // 控制/状态寄存器 ；
} RCC_TypeDef;

/*------------------------ Real-Time Clock -----------------------------------*/
typedef struct
{
  vu16 CRH;	      // 控制寄存器高位 ；
  u16  RESERVED0; //
  vu16 CRL;		  // 控制寄存器低位 ；
  u16  RESERVED1; //
  vu16 PRLH;	  // 预分频装载寄存器高位 ；
  u16  RESERVED2; //
  vu16 PRLL;	  // 预分频装载寄存器低位 ；
  u16  RESERVED3; //
  vu16 DIVH;	  // 预分频分频因子寄存器高位 ；
  u16  RESERVED4; //
  vu16 DIVL;	  // 预分频分频因子寄存器低位 ；
  u16  RESERVED5; //
  vu16 CNTH;	  // 计数器寄存器高位 ；
  u16  RESERVED6; //
  vu16 CNTL;	  // 计数器寄存器低位 ；
  u16  RESERVED7; //
  vu16 ALRH;	  // 闹钟寄存器高位 ；
  u16  RESERVED8; //
  vu16 ALRL;	  // 闹钟寄存器低位 ；
  u16  RESERVED9; //
} RTC_TypeDef;

/*------------------------ SD host Interface ---------------------------------*/
typedef struct
{
  vu32 POWER;
  vu32 CLKCR;
  vu32 ARG;
  vu32 CMD;
  vuc32 RESPCMD;
  vuc32 RESP1;
  vuc32 RESP2;
  vuc32 RESP3;
  vuc32 RESP4;
  vu32 DTIMER;
  vu32 DLEN;
  vu32 DCTRL;
  vuc32 DCOUNT;
  vuc32 STA;
  vu32 ICR;
  vu32 MASK;
  u32  RESERVED0[2];
  vuc32 FIFOCNT;
  u32  RESERVED1[13];
  vu32 FIFO;
} SDIO_TypeDef;

/*------------------------ Serial Peripheral Interface -----------------------*/
typedef struct
{
  vu16 CR1;	      // SPI控制寄存器1 ；
  u16  RESERVED0;
  vu16 CR2;		  // SPI控制寄存器2 ；
  u16  RESERVED1;
  vu16 SR;		  // SPI状态寄存器 ；
  u16  RESERVED2;
  vu16 DR;		  // SPI数据寄存器 ；
  u16  RESERVED3;
  vu16 CRCPR;	  // SPI CRC多项式寄存器 ；
  u16  RESERVED4;
  vu16 RXCRCR;	  // SPI接收CRC寄存器 ；
  u16  RESERVED5;
  vu16 TXCRCR;	  // SPI发送CRC寄存器 ；
  u16  RESERVED6;
  vu16 I2SCFGR;
  u16  RESERVED7;
  vu16 I2SPR;
  u16  RESERVED8;  
} SPI_TypeDef;

/*------------------------ SystemTick ----------------------------------------*/
typedef struct
{
  vu32 CTRL;   // SysTick控制和状态寄存器 ；
  vu32 LOAD;   // SysTick重装载值寄存器 ；
  vu32 VAL;	   // SysTick当前值寄存器 ；
  vuc32 CALIB; // SysTick校准值寄存器 ；
} SysTick_TypeDef;

/*------------------------ Advanced Control Timer ----------------------------*/
typedef struct
{
  vu16 CR1;		  // 控制寄存器1 ；
  u16  RESERVED0; 
  vu16 CR2;		  // 控制寄存器2 ；
  u16  RESERVED1; 
  vu16 SMCR;	  // 从模式控制寄存器 ；
  u16  RESERVED2;
  vu16 DIER;	  // DMA/中断使能寄存器 ；
  u16  RESERVED3;
  vu16 SR;		  // 状态寄存器 ；
  u16  RESERVED4;
  vu16 EGR;		  // 事件产生寄存器 ；
  u16  RESERVED5;
  vu16 CCMR1;	  // 捕获/比较模式寄存器1 ；
  u16  RESERVED6;
  vu16 CCMR2;	  // 捕获/比较模式寄存器2 ；
  u16  RESERVED7;
  vu16 CCER;	  // 捕获/比较使能寄存器 ；
  u16  RESERVED8;
  vu16 CNT;		  // 计数器寄存器 ；
  u16  RESERVED9;
  vu16 PSC;		  // 预分频寄存器 ；
  u16  RESERVED10;
  vu16 ARR;		  // 自动重装载寄存器 ；
  u16  RESERVED11;
  vu16 RCR;		  // 周期计数寄存器 ；
  u16  RESERVED12;
  vu16 CCR1;	  // 捕获/比较寄存器1 ；
  u16  RESERVED13;
  vu16 CCR2;	  // 捕获/比较寄存器2 ；
  u16  RESERVED14;
  vu16 CCR3;	  // 捕获/比较寄存器3 ；
  u16  RESERVED15;
  vu16 CCR4;	  // 捕获/比较寄存器4 ；
  u16  RESERVED16;
  vu16 BDTR;	  // 刹车和死区寄存器 ；
  u16  RESERVED17;
  vu16 DCR;		  // DMA控制寄存器 ；
  u16  RESERVED18;
  vu16 DMAR;	  // 连续模式的DMA地址寄存器 ；
  u16  RESERVED19;
} TIM1_TypeDef;

/*------------------------ TIM -----------------------------------------------*/
typedef struct
{
  vu16 CR1;		// 控制寄存器1 ；
  u16 RESERVED0;
  vu16 CR2;	   // 控制寄存器2 ；
  u16 RESERVED1;
  vu16 SMCR;   // 从模式控制寄存器 ；
  u16 RESERVED2;
  vu16 DIER;   // DMA/中断使能寄存器 ；
  u16 RESERVED3;
  vu16 SR;		// 状态寄存器 ；
  u16 RESERVED4;
  vu16 EGR;		// 事件产生寄存器 ；
  u16 RESERVED5;
  vu16 CCMR1;  // 捕获/比较模式寄存器1 ；
  u16 RESERVED6;
  vu16 CCMR2;  // 捕获/比较模式寄存器2 ；
  u16 RESERVED7;
  vu16 CCER;  // 捕获/比较使能寄存器 ；
  u16 RESERVED8;
  vu16 CNT;	  // 计数器寄存器 ；
  u16 RESERVED9;
  vu16 PSC;	  // 预分频寄存器 ；
  u16 RESERVED10;
  vu16 ARR;	  // 自动重装载寄存器 ；
  u16 RESERVED11[3];
  vu16 CCR1;  // 捕获/比较寄存器1 ；
  u16 RESERVED12;
  vu16 CCR2;  // 捕获/比较寄存器2 ；
  u16 RESERVED13;
  vu16 CCR3;  // 捕获/比较寄存器3 ；
  u16 RESERVED14;
  vu16 CCR4;  // 捕获/比较寄存器4 ；
  u16 RESERVED15[3];
  vu16 DCR;	  // DMA控制寄存器 ；
  u16 RESERVED16;
  vu16 DMAR;  // 连续模式的DMA地址寄存器 ；
  u16 RESERVED17; 
 
  vu16 RCR;		  // 周期计数寄存器 ；
  vu16 BDTR;	  // 刹车和死区寄存器 ；
} TIM_TypeDef;

/*----------------- Universal Synchronous Asynchronous Receiver Transmitter --*/
typedef struct
{
  vu16 SR;		 // USART状态寄存器 ；
  u16  RESERVED0;
  vu16 DR;		 // USART数据寄存器 ；
  u16  RESERVED1;
  vu16 BRR;		 // USART波特率寄存器 ；
  u16  RESERVED2;
  vu16 CR1;		 // USART控制寄存器1 ；
  u16  RESERVED3;
  vu16 CR2;		 // USART控制寄存器2 ；
  u16  RESERVED4;
  vu16 CR3;		 // USART控制寄存器3 ；
  u16  RESERVED5;
  vu16 GTPR;	 // USART保护时间和预分频寄存器 ；
  u16  RESERVED6;
} USART_TypeDef;

/*------------------------ Window WATCHDOG -----------------------------------*/
typedef struct
{
  vu32 CR;	// WWDG控制寄存器 ；
  vu32 CFR;	// WWDG设置寄存器 ；
  vu32 SR;  // WWDG状态寄存器 ；
} WWDG_TypeDef;

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Peripheral and SRAM base address in the alias region */
#define PERIPH_BB_BASE        ((u32)0x42000000)
#define SRAM_BB_BASE          ((u32)0x22000000)

/* Peripheral and SRAM base address in the bit-band region */
#define SRAM_BASE             ((u32)0x20000000)
#define PERIPH_BASE           ((u32)0x40000000)

/* FSMC registers base address */
#define FSMC_R_BASE           ((u32)0xA0000000)

/* Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define CAN_BASE              (APB1PERIPH_BASE + 0x6400)
#define BKP_BASE              (APB1PERIPH_BASE + 0x6C00)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400)

#define AFIO_BASE             (APB2PERIPH_BASE + 0x0000)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2400)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2800)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x3400)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x3C00)

#define SDIO_BASE             (PERIPH_BASE + 0x18000)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x0000)
#define DMA1_Channel1_BASE    (AHBPERIPH_BASE + 0x0008)
#define DMA1_Channel2_BASE    (AHBPERIPH_BASE + 0x001C)
#define DMA1_Channel3_BASE    (AHBPERIPH_BASE + 0x0030)
#define DMA1_Channel4_BASE    (AHBPERIPH_BASE + 0x0044)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x0058)
#define DMA1_Channel6_BASE    (AHBPERIPH_BASE + 0x006C)
#define DMA1_Channel7_BASE    (AHBPERIPH_BASE + 0x0080)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x0400)
#define DMA2_Channel1_BASE    (AHBPERIPH_BASE + 0x0408)
#define DMA2_Channel2_BASE    (AHBPERIPH_BASE + 0x041C)
#define DMA2_Channel3_BASE    (AHBPERIPH_BASE + 0x0430)
#define DMA2_Channel4_BASE    (AHBPERIPH_BASE + 0x0444)
#define DMA2_Channel5_BASE    (AHBPERIPH_BASE + 0x0458)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define CRC_BASE              (AHBPERIPH_BASE + 0x3000)

/* Flash registers base address */
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000)
/* Flash Option Bytes base address */
#define OB_BASE               ((u32)0x1FFFF800)

/* FSMC Bankx registers base address */
#define FSMC_Bank1_R_BASE     (FSMC_R_BASE + 0x0000)
#define FSMC_Bank1E_R_BASE    (FSMC_R_BASE + 0x0104)
#define FSMC_Bank2_R_BASE     (FSMC_R_BASE + 0x0060)
#define FSMC_Bank3_R_BASE     (FSMC_R_BASE + 0x0080)
#define FSMC_Bank4_R_BASE     (FSMC_R_BASE + 0x00A0)

/* Debug MCU registers base address */
#define DBGMCU_BASE          ((u32)0xE0042000)

/* System Control Space memory map */
#define SCS_BASE              ((u32)0xE000E000)

#define SysTick_BASE          (SCS_BASE + 0x0010)
#define NVIC_BASE             (SCS_BASE + 0x0100)
#define SCB_BASE              (SCS_BASE + 0x0D00)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/

/*------------------------ Non Debug Mode ------------------------------------*/
#ifndef DEBUG
#ifdef _TIM2
  #define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#endif /*_TIM2 */

#ifdef _TIM3
  #define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#endif /*_TIM3 */

#ifdef _TIM4
  #define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#endif /*_TIM4 */

#ifdef _TIM5
  #define TIM5                ((TIM_TypeDef *) TIM5_BASE)
#endif /*_TIM5 */

#ifdef _TIM6
  #define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#endif /*_TIM6 */

#ifdef _TIM7
  #define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#endif /*_TIM7 */

#ifdef _RTC
  #define RTC                 ((RTC_TypeDef *) RTC_BASE)
#endif /*_RTC */

#ifdef _WWDG
  #define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#endif /*_WWDG */

#ifdef _IWDG
  #define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#endif /*_IWDG */

#ifdef _SPI2
  #define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#endif /*_SPI2 */

#ifdef _SPI3
  #define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#endif /*_SPI3 */

#ifdef _USART2
  #define USART2              ((USART_TypeDef *) USART2_BASE)
#endif /*_USART2 */

#ifdef _USART3
  #define USART3              ((USART_TypeDef *) USART3_BASE)
#endif /*_USART3 */

#ifdef _UART4
  #define UART4              ((USART_TypeDef *) UART4_BASE)
#endif /*_UART4 */

#ifdef _UART5
  #define UART5              ((USART_TypeDef *) UART5_BASE)
#endif /*_USART5 */

#ifdef _I2C1
  #define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#endif /*_I2C1 */

#ifdef _I2C2
  #define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#endif /*_I2C2 */

#ifdef _CAN
  #define CAN                 ((CAN_TypeDef *) CAN_BASE)
#endif /*_CAN */

#ifdef _BKP
  #define BKP                 ((BKP_TypeDef *) BKP_BASE)
#endif /*_BKP */

#ifdef _PWR
  #define PWR                 ((PWR_TypeDef *) PWR_BASE)
#endif /*_PWR */

#ifdef _DAC
  #define DAC                 ((DAC_TypeDef *) DAC_BASE)
#endif /*_DAC */

#ifdef _AFIO
  #define AFIO                ((AFIO_TypeDef *) AFIO_BASE)
#endif /*_AFIO */

#ifdef _EXTI
  #define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#endif /*_EXTI */

#ifdef _GPIOA
  #define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#endif /*_GPIOA */

#ifdef _GPIOB
  #define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#endif /*_GPIOB */

#ifdef _GPIOC
  #define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#endif /*_GPIOC */

#ifdef _GPIOD
  #define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#endif /*_GPIOD */

#ifdef _GPIOE
  #define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#endif /*_GPIOE */

#ifdef _GPIOF
  #define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#endif /*_GPIOF */

#ifdef _GPIOG
  #define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#endif /*_GPIOG */

#ifdef _ADC1
  #define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#endif /*_ADC1 */

#ifdef _ADC2
  #define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#endif /*_ADC2 */

#ifdef _TIM1
  #define TIM1                ((TIM1_TypeDef *) TIM1_BASE)
#endif /*_TIM1 */

#ifdef _SPI1
  #define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#endif /*_SPI1 */

#ifdef _TIM8
  #define TIM8                ((TIM_TypeDef *) TIM8_BASE)
#endif /*_TIM8 */

#ifdef _USART1
  #define USART1              ((USART_TypeDef *) USART1_BASE)
#endif /*_USART1 */

#ifdef _ADC3
  #define ADC3                ((ADC_TypeDef *) ADC3_BASE)
#endif /*_ADC3 */

#ifdef _SDIO
  #define SDIO                ((SDIO_TypeDef *) SDIO_BASE)
#endif /*_SDIO */

#ifdef _DMA
  #define DMA1                ((DMA_TypeDef *) DMA1_BASE)
  #define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#endif /*_DMA */

#ifdef _DMA1_Channel1
  #define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#endif /*_DMA1_Channel1 */

#ifdef _DMA1_Channel2
  #define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#endif /*_DMA1_Channel2 */

#ifdef _DMA1_Channel3
  #define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#endif /*_DMA1_Channel3 */

#ifdef _DMA1_Channel4
  #define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#endif /*_DMA1_Channel4 */

#ifdef _DMA1_Channel5
  #define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#endif /*_DMA1_Channel5 */

#ifdef _DMA1_Channel6
  #define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#endif /*_DMA1_Channel6 */

#ifdef _DMA1_Channel7
  #define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#endif /*_DMA1_Channel7 */

#ifdef _DMA2_Channel1
  #define DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
#endif /*_DMA2_Channel1 */

#ifdef _DMA2_Channel2
  #define DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
#endif /*_DMA2_Channel2 */

#ifdef _DMA2_Channel3
  #define DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
#endif /*_DMA2_Channel3 */

#ifdef _DMA2_Channel4
  #define DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
#endif /*_DMA2_Channel4 */

#ifdef _DMA2_Channel5
  #define DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)
#endif /*_DMA2_Channel5 */

#ifdef _RCC
  #define RCC                 ((RCC_TypeDef *) RCC_BASE)
#endif /*_RCC */

#ifdef _CRC
  #define CRC                 ((CRC_TypeDef *) CRC_BASE)
#endif /*_CRC */

#ifdef _FLASH
  #define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
  #define OB                  ((OB_TypeDef *) OB_BASE) 
#endif /*_FLASH */

#ifdef _FSMC
  #define FSMC_Bank1          ((FSMC_Bank1_TypeDef *) FSMC_Bank1_R_BASE)
  #define FSMC_Bank1E         ((FSMC_Bank1E_TypeDef *) FSMC_Bank1E_R_BASE)
  #define FSMC_Bank2          ((FSMC_Bank2_TypeDef *) FSMC_Bank2_R_BASE)
  #define FSMC_Bank3          ((FSMC_Bank3_TypeDef *) FSMC_Bank3_R_BASE)
  #define FSMC_Bank4          ((FSMC_Bank4_TypeDef *) FSMC_Bank4_R_BASE)
#endif /*_FSMC */

#ifdef _DBGMCU
  #define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#endif /*_DBGMCU */

#ifdef _SysTick
  #define SysTick             ((SysTick_TypeDef *) SysTick_BASE)
#endif /*_SysTick */

#ifdef _NVIC
  #define NVIC                ((NVIC_TypeDef *) NVIC_BASE)
  #define SCB                 ((SCB_TypeDef *) SCB_BASE)  
#endif /*_NVIC */

/*------------------------ Debug Mode ----------------------------------------*/
#else   /* DEBUG */
#ifdef _TIM2
  EXT TIM_TypeDef             *TIM2;
#endif /*_TIM2 */

#ifdef _TIM3
  EXT TIM_TypeDef             *TIM3;
#endif /*_TIM3 */

#ifdef _TIM4
  EXT TIM_TypeDef             *TIM4;
#endif /*_TIM4 */

#ifdef _TIM5
  EXT TIM_TypeDef             *TIM5;
#endif /*_TIM5 */

#ifdef _TIM6
  EXT TIM_TypeDef             *TIM6;
#endif /*_TIM6 */

#ifdef _TIM7
  EXT TIM_TypeDef             *TIM7;
#endif /*_TIM7 */

#ifdef _RTC
  EXT RTC_TypeDef             *RTC;
#endif /*_RTC */

#ifdef _WWDG
  EXT WWDG_TypeDef            *WWDG;
#endif /*_WWDG */

#ifdef _IWDG
  EXT IWDG_TypeDef            *IWDG;
#endif /*_IWDG */

#ifdef _SPI2
  EXT SPI_TypeDef             *SPI2;
#endif /*_SPI2 */

#ifdef _SPI3
  EXT SPI_TypeDef             *SPI3;
#endif /*_SPI3 */

#ifdef _USART2
  EXT USART_TypeDef           *USART2;
#endif /*_USART2 */

#ifdef _USART3
  EXT USART_TypeDef           *USART3;
#endif /*_USART3 */

#ifdef _UART4
  EXT USART_TypeDef           *UART4;
#endif /*_UART4 */

#ifdef _UART5
  EXT USART_TypeDef           *UART5;
#endif /*_UART5 */

#ifdef _I2C1
  EXT I2C_TypeDef             *I2C1;
#endif /*_I2C1 */

#ifdef _I2C2
  EXT I2C_TypeDef             *I2C2;
#endif /*_I2C2 */

#ifdef _CAN
  EXT CAN_TypeDef             *CAN;
#endif /*_CAN */

#ifdef _BKP
  EXT BKP_TypeDef             *BKP;
#endif /*_BKP */

#ifdef _PWR
  EXT PWR_TypeDef             *PWR;
#endif /*_PWR */

#ifdef _DAC
  EXT DAC_TypeDef             *DAC;
#endif /*_DAC */

#ifdef _AFIO
  EXT AFIO_TypeDef            *AFIO;
#endif /*_AFIO */

#ifdef _EXTI
  EXT EXTI_TypeDef            *EXTI;
#endif /*_EXTI */

#ifdef _GPIOA
  EXT GPIO_TypeDef            *GPIOA;
#endif /*_GPIOA */

#ifdef _GPIOB
  EXT GPIO_TypeDef            *GPIOB;
#endif /*_GPIOB */

#ifdef _GPIOC
  EXT GPIO_TypeDef            *GPIOC;
#endif /*_GPIOC */

#ifdef _GPIOD
  EXT GPIO_TypeDef            *GPIOD;
#endif /*_GPIOD */

#ifdef _GPIOE
  EXT GPIO_TypeDef            *GPIOE;
#endif /*_GPIOE */

#ifdef _GPIOF
  EXT GPIO_TypeDef            *GPIOF;
#endif /*_GPIOF */

#ifdef _GPIOG
  EXT GPIO_TypeDef            *GPIOG;
#endif /*_GPIOG */

#ifdef _ADC1
  EXT ADC_TypeDef             *ADC1;
#endif /*_ADC1 */

#ifdef _ADC2
  EXT ADC_TypeDef             *ADC2;
#endif /*_ADC2 */

#ifdef _TIM1
  EXT TIM_TypeDef             *TIM1;
#endif /*_TIM1 */

#ifdef _SPI1
  EXT SPI_TypeDef             *SPI1;
#endif /*_SPI1 */

#ifdef _TIM8
  EXT TIM_TypeDef             *TIM8;
#endif /*_TIM8 */

#ifdef _USART1
  EXT USART_TypeDef           *USART1;
#endif /*_USART1 */

#ifdef _ADC3
  EXT ADC_TypeDef             *ADC3;
#endif /*_ADC3 */

#ifdef _SDIO
  EXT SDIO_TypeDef            *SDIO;
#endif /*_SDIO */

#ifdef _DMA
  EXT DMA_TypeDef             *DMA1;
  EXT DMA_TypeDef             *DMA2;
#endif /*_DMA */

#ifdef _DMA1_Channel1
  EXT DMA_Channel_TypeDef     *DMA1_Channel1;
#endif /*_DMA1_Channel1 */

#ifdef _DMA1_Channel2
  EXT DMA_Channel_TypeDef     *DMA1_Channel2;
#endif /*_DMA1_Channel2 */

#ifdef _DMA1_Channel3
  EXT DMA_Channel_TypeDef     *DMA1_Channel3;
#endif /*_DMA1_Channel3 */

#ifdef _DMA1_Channel4
  EXT DMA_Channel_TypeDef     *DMA1_Channel4;
#endif /*_DMA1_Channel4 */

#ifdef _DMA1_Channel5
  EXT DMA_Channel_TypeDef     *DMA1_Channel5;
#endif /*_DMA1_Channel5 */

#ifdef _DMA1_Channel6
  EXT DMA_Channel_TypeDef     *DMA1_Channel6;
#endif /*_DMA1_Channel6 */

#ifdef _DMA1_Channel7
  EXT DMA_Channel_TypeDef     *DMA1_Channel7;
#endif /*_DMA1_Channel7 */

#ifdef _DMA2_Channel1
  EXT DMA_Channel_TypeDef     *DMA2_Channel1;
#endif /*_DMA2_Channel1 */

#ifdef _DMA2_Channel2
  EXT DMA_Channel_TypeDef     *DMA2_Channel2;
#endif /*_DMA2_Channel2 */

#ifdef _DMA2_Channel3
  EXT DMA_Channel_TypeDef     *DMA2_Channel3;
#endif /*_DMA2_Channel3 */

#ifdef _DMA2_Channel4
  EXT DMA_Channel_TypeDef     *DMA2_Channel4;
#endif /*_DMA2_Channel4 */

#ifdef _DMA2_Channel5
  EXT DMA_Channel_TypeDef     *DMA2_Channel5;
#endif /*_DMA2_Channel5 */

#ifdef _RCC
  EXT RCC_TypeDef             *RCC;
#endif /*_RCC */

#ifdef _CRC
  EXT CRC_TypeDef             *CRC;
#endif /*_CRC */

#ifdef _FLASH
  EXT FLASH_TypeDef            *FLASH;
  EXT OB_TypeDef               *OB;  
#endif /*_FLASH */

#ifdef _FSMC
  EXT FSMC_Bank1_TypeDef      *FSMC_Bank1;
  EXT FSMC_Bank1E_TypeDef     *FSMC_Bank1E;
  EXT FSMC_Bank2_TypeDef      *FSMC_Bank2;
  EXT FSMC_Bank3_TypeDef      *FSMC_Bank3;
  EXT FSMC_Bank4_TypeDef      *FSMC_Bank4;
#endif /*_FSMC */

#ifdef _DBGMCU
  EXT DBGMCU_TypeDef          *DBGMCU;
#endif /*_DBGMCU */

#ifdef _SysTick
  EXT SysTick_TypeDef         *SysTick;
#endif /*_SysTick */

#ifdef _NVIC
  EXT NVIC_TypeDef            *NVIC;
  EXT SCB_TypeDef             *SCB;
#endif /*_NVIC */

#endif  /* DEBUG */

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __STM32F10x_MAP_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
