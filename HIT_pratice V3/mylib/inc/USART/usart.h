#ifndef __USART__H
#define __USART__H

#include "stm32f10x_lib.h"

void Usart_Configuration(void);
void UART_Send_Byte(char c);
void UART_Send_Enter(void);

void UART_Send_Str(char *s);

void UART_Put_Num(unsigned long dat);
void UART_Put_Inf(char *inf,unsigned long dat);

void u32tostr(unsigned long dat,char *str);
unsigned long strtou32(char *str) ;
void USART1_Puts( char * str);
void USART1_Putc(unsigned char c);
void usart1_niming_report(u8 fun,u8*data,u8 len);
void debug_send_data(float pitch,float roll);
#endif

