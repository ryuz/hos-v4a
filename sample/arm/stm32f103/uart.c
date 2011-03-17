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

#define PINSEL0		((volatile UW *)0xe002c000)

#define U0RBR		((volatile UB *)0xe000c000)
#define U0THR		((volatile UB *)0xe000c000)
#define U0LCR		((volatile UB *)0xe000c00c)
#define U0LSR		((volatile UB *)0xe000c014)
#define U0DLL		((volatile UB *)0xe000c000)
#define U0DLM		((volatile UB *)0xe000c004)


#define VPB_CLK		(14700000/4)
#define UART_BPS	38400


/* %jp{UARTの初期化} */
void Uart_Initialize(void)
{
	*PINSEL0 = (*PINSEL0 & 0xfffffff0) | 0x05;

	*U0LCR = 0x80;
	*U0DLL = (VPB_CLK / 16.0) / UART_BPS + 0.5;
	*U0DLM = 0x00;
	*U0LCR = 0x03;
}


/* %jp{1文字出力} */
void Uart_PutChar(int c)
{
	while ( !(*U0LSR & 0x20) )
		;

	*U0THR = c;
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

void Uart_PutHexWord(int i)
{
	Uart_PutHexByte((i >> 8) & 0xff);
	Uart_PutHexByte((i >> 0) & 0xff);
}



/* end of file */
