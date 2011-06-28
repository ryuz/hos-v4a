/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  uart.c
 * @brief %jp{UARTへの出力}%en{UART device driver}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"


#define REG_UART_BASE		0x80000000
#define REG_UART_RBR		((volatile unsigned long *)(REG_UART_BASE + 0x1000))
#define REG_UART_THR		((volatile unsigned long *)(REG_UART_BASE + 0x1000))
#define REG_UART_IER		((volatile unsigned long *)(REG_UART_BASE + 0x1004))
#define REG_UART_IIR		((volatile unsigned long *)(REG_UART_BASE + 0x1008))
#define REG_UART_LCR		((volatile unsigned long *)(REG_UART_BASE + 0x100c))
#define REG_UART_MCR		((volatile unsigned long *)(REG_UART_BASE + 0x1010))
#define REG_UART_LSR		((volatile unsigned long *)(REG_UART_BASE + 0x1014))
#define REG_UART_MSR		((volatile unsigned long *)(REG_UART_BASE + 0x1018))
#define REG_UART_SCR		((volatile unsigned long *)(REG_UART_BASE + 0x101c))
#define REG_UART_DLL		((volatile unsigned long *)(REG_UART_BASE + 0x1000))
#define REG_UART_DLM		((volatile unsigned long *)(REG_UART_BASE + 0x1004))


/* %jp{UARTの初期化} */
void Uart_Initialize(void)
{
	*REG_UART_IER  = 0x00;
	*REG_UART_LCR  = 0x03;
	*REG_UART_MCR  = 0x03;
	*REG_UART_LCR |= 0x80;
	*REG_UART_DLL  = 80; /* 50000000 / 38400 / 16 - 1 */
	*REG_UART_DLM  = 0x00;
	*REG_UART_LCR &= 0x7f;
}


/* %jp{1文字入力} */
char Uart_GetChar(void)
{
	return 0;
}


/* %jp{1文字出力} */
void Uart_PutChar(int c)
{
	while ( !(*REG_UART_LSR & 0x20) )
		;
	
	*REG_UART_THR = c;
}


/* %jp{文字列出力} */
void Uart_PutString(const char *text)
{
	while ( *text != '\0' )
	{
		if ( *text == '\n' )
		{
			Uart_PutChar('\r');
			Uart_PutChar('\n');
		}
		else
		{
			Uart_PutChar(*text);
		}
		
		text++;
	}
}


char Uart_hex2asc(int a)
{
	if ( a < 10 )
	{
		return '0' + a;
	}
	return 'a' + a - 10;
}


void Uart_PutHexByte(char c)
{
	Uart_PutChar(Uart_hex2asc((c >> 4) & 0xf));
	Uart_PutChar(Uart_hex2asc((c >> 0) & 0xf));
}


void Uart_PutHexHalfWord(unsigned short h)
{
	Uart_PutHexByte((h >> 8) & 0xff);
	Uart_PutHexByte((h >> 0) & 0xff);
}

void Uart_PutHexWord(unsigned long w)
{
	Uart_PutHexHalfWord((w >> 16) & 0xffff);
	Uart_PutHexHalfWord((w >>  0) & 0xffff);
}



/* end of file */
