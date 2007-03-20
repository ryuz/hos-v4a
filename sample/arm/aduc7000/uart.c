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


#define GP1CON		((volatile UB *)0xfffff404)
#define COMTX		((volatile UB *)0xffff0700)
#define COMDIV0		((volatile UB *)0xffff0700)
#define COMDIV1		((volatile UB *)0xffff0704)
#define COMCON0		((volatile UB *)0xffff070c)
#define COMSTA0		((volatile UB *)0xffff0714)


/* %jp{UARTの初期化} */
void Uart_Initialize(void)
{
	*GP1CON  = 0x11;

	*COMCON0 = 0x80;
	*COMDIV0 = 0x22;	/* 38400bps */
	*COMDIV1 = 0x00;
	*COMCON0 = 0x03;
}


/* %jp{1文字出力} */
void Uart_PutChar(int c)
{
	while ( !(*COMSTA0 & 0x20) )
		;

	*COMTX = c;
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
