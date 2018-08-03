//GPIO define
//Design by :Tan/yicheng 

#include <stm32f10x_lib.h>              /* STM32F10x Library Definitions      */


/* Enable GPIO   Port    CLOCK                  */
#define GPIOA_ENABLE            RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
#define GPIOB_ENABLE            RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOB, ENABLE);
#define GPIOC_ENABLE            RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE);
#define GPIOD_ENABLE            RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOD, ENABLE);
#define GPIOE_ENABLE            RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOE, ENABLE);
/*Disable   Port         CLOCK                        */                        
#define GPIOA_DISABLE           RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, DISABLE);
#define GPIOB_DISABLE           RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOB, DISABLE);
#define GPIOC_DISABLE           RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, DISABLE);
#define GPIOD_DISABLE           RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOD, DISABLE);
#define GPIOE_DISABLE           RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOE, DISABLE);
//Syststick enable
#define SysTick_Eanble						SysTick_CounterCmd(SysTick_Counter_Enable);
/*DEFINE DIFFERENT  GPIO PORTS ·À,IN ORDR TO EASY SETTING PIN TO 0 OR 1			BY BIT	 */
#define GPIO_A0(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_0)  	| (x ? GPIO_Pin_0 : 0)
#define GPIO_A1(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_1) 	| (x ? GPIO_Pin_1 : 0)
#define GPIO_A2(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_2)  	| (x ? GPIO_Pin_2 : 0)
#define GPIO_A3(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_3)  	| (x ? GPIO_Pin_3 : 0)
#define GPIO_A4(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_4)  	| (x ? GPIO_Pin_4 : 0)
#define GPIO_A5(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_5)  	| (x ? GPIO_Pin_5 : 0)
#define GPIO_A6(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_6)  	| (x ? GPIO_Pin_6 : 0)
#define GPIO_A7(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_7)  	| (x ? GPIO_Pin_7 : 0)
#define GPIO_A8(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_8)  	| (x ? GPIO_Pin_8 : 0)
#define GPIO_A9(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_9)  	| (x ? GPIO_Pin_9 : 0)
#define GPIO_A10(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_10)  | (x ? GPIO_Pin_10 : 0)
#define GPIO_A11(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_11)  | (x ? GPIO_Pin_11 : 0)
#define GPIO_A12(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_12)  | (x ? GPIO_Pin_12 : 0)
#define GPIO_A13(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_13)  | (x ? GPIO_Pin_13 : 0)
#define GPIO_A14(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_14)  | (x ? GPIO_Pin_14 : 0)
#define GPIO_A15(x)        	  GPIOA->ODR=(GPIOA->ODR&~GPIO_Pin_15)  | (x ? GPIO_Pin_15 : 0)

#define GPIO_B0(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_0)  	| (x ? GPIO_Pin_0 : 0)
#define GPIO_B1(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_1) 	| (x ? GPIO_Pin_1 : 0)
#define GPIO_B2(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_2)  	| (x ? GPIO_Pin_2 : 0)
#define GPIO_B3(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_3)  	| (x ? GPIO_Pin_3 : 0)
#define GPIO_B4(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_4)  	| (x ? GPIO_Pin_4 : 0)
#define GPIO_B5(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_5)  	| (x ? GPIO_Pin_5 : 0)
#define GPIO_B6(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_6)  	| (x ? GPIO_Pin_6 : 0)
#define GPIO_B7(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_7)  	| (x ? GPIO_Pin_7 : 0)
#define GPIO_B8(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_8)  	| (x ? GPIO_Pin_8 : 0)
#define GPIO_B9(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_9)  	| (x ? GPIO_Pin_9 : 0)
#define GPIO_B10(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_10)  | (x ? GPIO_Pin_10 : 0)
#define GPIO_B11(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_11)  | (x ? GPIO_Pin_11 : 0)
#define GPIO_B12(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_12)  | (x ? GPIO_Pin_12 : 0)
#define GPIO_B13(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_13)  | (x ? GPIO_Pin_13 : 0)
#define GPIO_B14(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_14)  | (x ? GPIO_Pin_14 : 0)
#define GPIO_B15(x)        	  GPIOB->ODR=(GPIOB->ODR&~GPIO_Pin_15)  | (x ? GPIO_Pin_15 : 0)

#define GPIO_C0(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_0)  	| (x ? GPIO_Pin_0 : 0)
#define GPIO_C1(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_1) 	| (x ? GPIO_Pin_1 : 0)
#define GPIO_C2(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_2)  	| (x ? GPIO_Pin_2 : 0)
#define GPIO_C3(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_3)  	| (x ? GPIO_Pin_3 : 0)
#define GPIO_C4(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_4)  	| (x ? GPIO_Pin_4 : 0)
#define GPIO_C5(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_5)  	| (x ? GPIO_Pin_5 : 0)
#define GPIO_C6(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_6)  	| (x ? GPIO_Pin_6 : 0)
#define GPIO_C7(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_7)  	| (x ? GPIO_Pin_7 : 0)
#define GPIO_C8(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_8)  	| (x ? GPIO_Pin_8 : 0)
#define GPIO_C9(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_9)  	| (x ? GPIO_Pin_9 : 0)
#define GPIO_C10(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_10)  | (x ? GPIO_Pin_10 : 0)
#define GPIO_C11(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_11)  | (x ? GPIO_Pin_11 : 0)
#define GPIO_C12(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_12)  | (x ? GPIO_Pin_12 : 0)
#define GPIO_C13(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_13)  | (x ? GPIO_Pin_13 : 0)
#define GPIO_C14(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_14)  | (x ? GPIO_Pin_14 : 0)
#define GPIO_C15(x)        	  GPIOC->ODR=(GPIOC->ODR&~GPIO_Pin_15)  | (x ? GPIO_Pin_15 : 0)

#define GPIO_D0(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_0)  	| (x ? GPIO_Pin_0 : 0)
#define GPIO_D1(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_1) 	| (x ? GPIO_Pin_1 : 0)
#define GPIO_D2(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_2)  	| (x ? GPIO_Pin_2 : 0)
#define GPIO_D3(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_3)  	| (x ? GPIO_Pin_3 : 0)
#define GPIO_D4(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_4)  	| (x ? GPIO_Pin_4 : 0)
#define GPIO_D5(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_5)  	| (x ? GPIO_Pin_5 : 0)
#define GPIO_D6(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_6)  	| (x ? GPIO_Pin_6 : 0)
#define GPIO_D7(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_7)  	| (x ? GPIO_Pin_7 : 0)
#define GPIO_D8(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_8)  	| (x ? GPIO_Pin_8 : 0)
#define GPIO_D9(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_9)  	| (x ? GPIO_Pin_9 : 0)
#define GPIO_D10(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_10)  | (x ? GPIO_Pin_10 : 0)
#define GPIO_D11(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_11)  | (x ? GPIO_Pin_11 : 0)
#define GPIO_D12(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_12)  | (x ? GPIO_Pin_12 : 0)
#define GPIO_D13(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_13)  | (x ? GPIO_Pin_13 : 0)
#define GPIO_D14(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_14)  | (x ? GPIO_Pin_14 : 0)
#define GPIO_D15(x)        	  GPIOD->ODR=(GPIOD->ODR&~GPIO_Pin_15)  | (x ? GPIO_Pin_15 : 0)


#define GPIO_E0(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_0)  	| (x ? GPIO_Pin_0 : 0)
#define GPIO_E1(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_1) 	| (x ? GPIO_Pin_1 : 0)
#define GPIO_E2(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_2)  	| (x ? GPIO_Pin_2 : 0)
#define GPIO_E3(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_3)  	| (x ? GPIO_Pin_3 : 0)
#define GPIO_E4(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_4)  	| (x ? GPIO_Pin_4 : 0)
#define GPIO_E5(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_5)  	| (x ? GPIO_Pin_5 : 0)
#define GPIO_E6(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_6)  	| (x ? GPIO_Pin_6 : 0)
#define GPIO_E7(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_7)  	| (x ? GPIO_Pin_7 : 0)
#define GPIO_E8(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_8)  	| (x ? GPIO_Pin_8 : 0)
#define GPIO_E9(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_9)  	| (x ? GPIO_Pin_9 : 0)
#define GPIO_E10(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_10)  | (x ? GPIO_Pin_10 : 0)
#define GPIO_E11(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_11)  | (x ? GPIO_Pin_11 : 0)
#define GPIO_E12(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_12)  | (x ? GPIO_Pin_12 : 0)
#define GPIO_E13(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_13)  | (x ? GPIO_Pin_13 : 0)
#define GPIO_E14(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_14)  | (x ? GPIO_Pin_14 : 0)
#define GPIO_E15(x)        	  GPIOE->ODR=(GPIOE->ODR&~GPIO_Pin_15)  | (x ? GPIO_Pin_15 : 0)

/* DEFINE DIFFERENT  GPIO PORTS ·À,IN ORDR TO EASY SETTING PIN TO 0 OR 1	BY WORD 			 */

//#define GPIOB_HIGH          GPIOB->ODR=(GPIOB->ODR&~0XFF00)        |     


 

/*Setting  pins to General purpose output push-pull mode max speed at 50MHz  (CNFx=00,MODEx=11)                                         */
 //GPIOC
#define GPIO_C0_DIR_OUT        GPIOC->CRL = (GPIOC->CRL&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_C1_DIR_OUT        GPIOC->CRL = (GPIOC->CRL&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_C2_DIR_OUT        GPIOC->CRL = (GPIOC->CRL&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_C3_DIR_OUT        GPIOC->CRL = (GPIOC->CRL&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_C4_DIR_OUT        GPIOC->CRL = (GPIOC->CRL&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_C5_DIR_OUT        GPIOC->CRL = (GPIOC->CRL&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_C6_DIR_OUT        GPIOC->CRL = (GPIOC->CRL&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_C7_DIR_OUT        GPIOC->CRL = (GPIOC->CRL&  0x0FFFFFFF)  | 0x30000000;
#define GPIO_C8_DIR_OUT        GPIOC->CRH = (GPIOC->CRH&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_C9_DIR_OUT        GPIOC->CRH =(GPIOC->CRH&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_C10_DIR_OUT       GPIOC->CRH = (GPIOC->CRH&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_C11_DIR_OUT       GPIOC->CRH = (GPIOC->CRH&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_C12_DIR_OUT       GPIOC->CRH = (GPIOC->CRH&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_C13_DIR_OUT       GPIOC->CRH = (GPIOC->CRH&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_C14_DIR_OUT       GPIOC->CRH = (GPIOC->CRH&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_C15_DIR_OUT       GPIOC->CRH = (GPIOC->CRH&  0x0FFFFFFF)  | 0x30000000; 
 //GPI0B
#define GPIO_B0_DIR_OUT        GPIOB->CRL = (GPIOB->CRL&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_B1_DIR_OUT        GPIOB->CRL = (GPIOB->CRL&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_B2_DIR_OUT        GPIOB->CRL = (GPIOB->CRL&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_B3_DIR_OUT        GPIOB->CRL = (GPIOB->CRL&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_B4_DIR_OUT        GPIOB->CRL = (GPIOB->CRL&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_B5_DIR_OUT        GPIOB->CRL = (GPIOB->CRL&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_B6_DIR_OUT        GPIOB->CRL = (GPIOB->CRL&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_B7_DIR_OUT        GPIOB->CRL = (GPIOB->CRL&  0x0FFFFFFF)  | 0x30000000;
#define GPIO_B8_DIR_OUT        GPIOB->CRH = (GPIOB->CRH&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_B9_DIR_OUT        GPIOB->CRH =(GPIOB->CRH&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_B10_DIR_OUT       GPIOB->CRH = (GPIOB->CRH&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_B11_DIR_OUT       GPIOB->CRH = (GPIOB->CRH&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_B12_DIR_OUT       GPIOB->CRH = (GPIOB->CRH&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_B13_DIR_OUT       GPIOB->CRH = (GPIOB->CRH&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_B14_DIR_OUT       GPIOB->CRH = (GPIOB->CRH&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_B15_DIR_OUT       GPIOB->CRH = (GPIOB->CRH&  0x0FFFFFFF)  | 0x30000000;
//GPIOA

#define GPIO_A0_DIR_OUT        GPIOA->CRL = (GPIOA->CRL&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_A1_DIR_OUT        GPIOA->CRL = (GPIOA->CRL&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_A2_DIR_OUT        GPIOA->CRL = (GPIOA->CRL&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_A3_DIR_OUT        GPIOA->CRL = (GPIOA->CRL&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_A4_DIR_OUT        GPIOA->CRL = (GPIOA->CRL&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_A5_DIR_OUT        GPIOA->CRL = (GPIOA->CRL&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_A6_DIR_OUT        GPIOA->CRL = (GPIOA->CRL&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_A7_DIR_OUT        GPIOA->CRL = (GPIOA->CRL&  0x0FFFFFFF)  | 0x30000000;
#define GPIO_A8_DIR_OUT        GPIOA->CRH = (GPIOA->CRH&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_A9_DIR_OUT        GPIOA->CRH =(GPIOA->CRH&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_A10_DIR_OUT       GPIOA->CRH = (GPIOA->CRH&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_A11_DIR_OUT       GPIOA->CRH = (GPIOA->CRH&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_A12_DIR_OUT       GPIOA->CRH = (GPIOA->CRH&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_A13_DIR_OUT       GPIOA->CRH = (GPIOA->CRH&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_A14_DIR_OUT       GPIOA->CRH = (GPIOA->CRH&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_A15_DIR_OUT       GPIOA->CRH = (GPIOA->CRH&  0x0FFFFFFF)  | 0x30000000;

//GPIOD

#define GPIO_D0_DIR_OUT        GPIOD->CRL = (GPIOD->CRL&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_D1_DIR_OUT        GPIOD->CRL = (GPIOD->CRL&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_D2_DIR_OUT        GPIOD->CRL = (GPIOD->CRL&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_D3_DIR_OUT        GPIOD->CRL = (GPIOD->CRL&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_D4_DIR_OUT        GPIOD->CRL = (GPIOD->CRL&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_D5_DIR_OUT        GPIOD->CRL = (GPIOD->CRL&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_D6_DIR_OUT        GPIOD->CRL = (GPIOD->CRL&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_D7_DIR_OUT        GPIOD->CRL = (GPIOD->CRL&  0x0FFFFFFF)  | 0x30000000;
#define GPIO_D8_DIR_OUT        GPIOD->CRH = (GPIOD->CRH&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_D9_DIR_OUT        GPIOD->CRH =(GPIOD->CRH&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_D10_DIR_OUT       GPIOD->CRH = (GPIOD->CRH&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_D11_DIR_OUT       GPIOD->CRH = (GPIOD->CRH&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_D12_DIR_OUT       GPIOD->CRH = (GPIOD->CRH&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_D13_DIR_OUT       GPIOD->CRH = (GPIOD->CRH&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_D14_DIR_OUT       GPIOD->CRH = (GPIOD->CRH&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_D15_DIR_OUT       GPIOD->CRH = (GPIOD->CRH&  0x0FFFFFFF)  | 0x30000000;

//GPIOE

#define GPIO_E0_DIR_OUT        GPIOE->CRL = (GPIOE->CRL&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_E1_DIR_OUT        GPIOE->CRL = (GPIOE->CRL&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_E2_DIR_OUT        GPIOE->CRL = (GPIOE->CRL&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_E3_DIR_OUT        GPIOE->CRL = (GPIOE->CRL&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_E4_DIR_OUT        GPIOE->CRL = (GPIOE->CRL&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_E5_DIR_OUT        GPIOE->CRL = (GPIOE->CRL&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_E6_DIR_OUT        GPIOE->CRL = (GPIOE->CRL&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_E7_DIR_OUT        GPIOE->CRL = (GPIOE->CRL&  0x0FFFFFFF)  | 0x30000000;
#define GPIO_E8_DIR_OUT        GPIOE->CRH = (GPIOE->CRH&  0xFFFFFFF0)  | 0x00000003;
#define GPIO_E9_DIR_OUT        GPIOE->CRH =(GPIOE->CRH&  0xFFFFFF0F)  | 0x00000030;
#define GPIO_E10_DIR_OUT       GPIOE->CRH = (GPIOE->CRH&  0xFFFFF0FF)  | 0x00000300;
#define GPIO_E11_DIR_OUT       GPIOE->CRH = (GPIOE->CRH&  0xFFFF0FFF)  | 0x00003000;
#define GPIO_E12_DIR_OUT       GPIOE->CRH = (GPIOE->CRH&  0xFFF0FFFF)  | 0x00030000;
#define GPIO_E13_DIR_OUT       GPIOE->CRH = (GPIOE->CRH&  0xFF0FFFFF)  | 0x00300000;
#define GPIO_E14_DIR_OUT       GPIOE->CRH = (GPIOE->CRH&  0xF0FFFFFF)  | 0x03000000;
#define GPIO_E15_DIR_OUT       GPIOE->CRH = (GPIOE->CRH&  0x0FFFFFFF)  | 0x30000000;

 /*SET THE GPIP PORT TO FLOATING INPUT MODE ,CNFx=01B,MODEx=00B;		  */


#define  GPIO_C0_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_C1_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_C2_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_C3_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_C4_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_C5_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_C6_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_C7_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0x0FFFFFFF)  | 0x40000000;
#define  GPIO_C8_DIR_IN       GPIOC->CRL = (GPIOC->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_C9_DIR_IN       GPIOC->CRH = (GPIOC->CRH&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_C10_DIR_IN      GPIOC->CRH = (GPIOC->CRH&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_C11_DIR_IN      GPIOC->CRH = (GPIOC->CRH&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_C12_DIR_IN      GPIOC->CRH = (GPIOC->CRH&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_C13_DIR_IN      GPIOC->CRH = (GPIOC->CRH&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_C14_DIR_IN      GPIOC->CRH = (GPIOC->CRH&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_C15_DIR_IN      GPIOC->CRH = (GPIOC->CRH&   0x0FFFFFFF)  | 0x40000000;

#define  GPIO_A0_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_A1_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_A2_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_A3_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_A4_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_A5_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_A6_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_A7_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0x0FFFFFFF)  | 0x40000000;
#define  GPIO_A8_DIR_IN       GPIOA->CRL = (GPIOA->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_A9_DIR_IN       GPIOA->CRH = (GPIOA->CRH&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_A10_DIR_IN      GPIOA->CRH = (GPIOA->CRH&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_A11_DIR_IN      GPIOA->CRH = (GPIOA->CRH&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_A12_DIR_IN      GPIOA->CRH = (GPIOA->CRH&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_A13_DIR_IN      GPIOA->CRH = (GPIOA->CRH&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_A14_DIR_IN      GPIOA->CRH = (GPIOA->CRH&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_A15_DIR_IN      GPIOA->CRH = (GPIOA->CRH&   0x0FFFFFFF)  | 0x40000000;

#define  GPIO_B0_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_B1_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_B2_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_B3_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_B4_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_B5_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_B6_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_B7_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0x0FFFFFFF)  | 0x40000000;
#define  GPIO_B8_DIR_IN       GPIOB->CRL = (GPIOB->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_B9_DIR_IN       GPIOB->CRH = (GPIOB->CRH&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_B10_DIR_IN      GPIOB->CRH = (GPIOB->CRH&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_B11_DIR_IN      GPIOB->CRH = (GPIOB->CRH&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_B12_DIR_IN      GPIOB->CRH = (GPIOB->CRH&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_B13_DIR_IN      GPIOB->CRH = (GPIOB->CRH&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_B14_DIR_IN      GPIOB->CRH = (GPIOB->CRH&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_B15_DIR_IN      GPIOB->CRH = (GPIOB->CRH&   0x0FFFFFFF)  | 0x40000000;

#define  GPIO_D0_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_D1_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_D2_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_D3_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_D4_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_D5_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_D6_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_D7_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0x0FFFFFFF)  | 0x40000000;
#define  GPIO_D8_DIR_IN       GPIOD->CRL = (GPIOD->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_D9_DIR_IN       GPIOD->CRH = (GPIOD->CRH&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_D10_DIR_IN      GPIOD->CRH = (GPIOD->CRH&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_D11_DIR_IN      GPIOD->CRH = (GPIOD->CRH&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_D12_DIR_IN      GPIOD->CRH = (GPIOD->CRH&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_D13_DIR_IN      GPIOD->CRH = (GPIOD->CRH&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_D14_DIR_IN      GPIOD->CRH = (GPIOD->CRH&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_D15_DIR_IN      GPIOD->CRH = (GPIOD->CRH&   0x0FFFFFFF)  | 0x40000000;

#define  GPIO_E0_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_E1_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_E2_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_E3_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_E4_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_E5_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_E6_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_E7_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0x0FFFFFFF)  | 0x40000000;
#define  GPIO_E8_DIR_IN       GPIOE->CRL = (GPIOE->CRL&   0xFFFFFFF0)  | 0x00000004;
#define  GPIO_E9_DIR_IN       GPIOE->CRH = (GPIOE->CRH&   0xFFFFFF0F)  | 0x00000040;
#define  GPIO_E10_DIR_IN      GPIOE->CRH = (GPIOE->CRH&   0xFFFFF0FF)  | 0x00000400;
#define  GPIO_E11_DIR_IN      GPIOE->CRH = (GPIOE->CRH&   0xFFFF0FFF)  | 0x00004000;
#define  GPIO_E12_DIR_IN      GPIOE->CRH = (GPIOE->CRH&   0xFFF0FFFF)  | 0x00040000;
#define  GPIO_E13_DIR_IN      GPIOE->CRH = (GPIOE->CRH&   0xFF0FFFFF)  | 0x00400000;
#define  GPIO_E14_DIR_IN      GPIOE->CRH = (GPIOE->CRH&   0xF0FFFFFF)  | 0x04000000;
#define  GPIO_E15_DIR_IN      GPIOE->CRH = (GPIOE->CRH&   0x0FFFFFFF)  | 0x40000000;




#define LCD_DATA_DIR_OUT      GPIOC->CRL = (GPIOC->CRL & 0xFFFF0000) | 0x00003333;


