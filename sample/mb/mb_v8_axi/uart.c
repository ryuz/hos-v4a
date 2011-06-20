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


#define REG_UART_BASE		0x40600000
#define REG_UART_RX			((volatile unsigned long *)(REG_UART_BASE + 0x0))
#define REG_UART_TX			((volatile unsigned long *)(REG_UART_BASE + 0x4))
#define REG_UART_STAT		((volatile unsigned long *)(REG_UART_BASE + 0x8))
#define REG_UART_CTRL		((volatile unsigned long *)(REG_UART_BASE + 0xc))


/* %jp{UARTの初期化} */
void Uart_Initialize(void)
{
}


/* %jp{1文字入力} */
char Uart_GetChar(void)
{
	return 0;
}


/* %jp{1文字出力} */
void Uart_PutChar(int c)
{
	while ( *REG_UART_STAT & 0x08 )
		;
	
	*REG_UART_TX = c;
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
