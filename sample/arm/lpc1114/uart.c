/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  uart.c
 * @brief %jp{UARTへの出力}%en{UART device driver}
 *
 * Copyright (C) 1998-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"


#define REG_IOCON_PIO1_6		((volatile UW *)0x400440A4)
#define REG_IOCON_PIO1_7		((volatile UW *)0x400440A8)

#define REG_U0RBR				((volatile UW *)0x40008000)		/* UART Receiver Buffer Register */
#define REG_U0THR				((volatile UW *)0x40008000)		/* UART Transmitter Holding Register */
#define REG_U0DLL				((volatile UW *)0x40008000)		/* UART Divisor Latch LSB and MSB Registers  */
#define REG_U0DLM				((volatile UW *)0x40008004)		/*  */
#define REG_U0IER				((volatile UW *)0x40008004)		/* UART Interrupt Enable Register  */
#define REG_U0IIR				((volatile UW *)0x40048008)		/* UART Interrupt Identification Register  */
#define REG_U0FCR				((volatile UW *)0x40008008)		/* UART FIFO Control Register */
#define REG_U0LCR				((volatile UW *)0x4000800C)		/* UART Line Control Register */
#define REG_U0MCR				((volatile UW *)0x40008010)		/* UART0 Modem Control Register */
#define REG_U0LSR				((volatile UW *)0x40008014)		/* UART Line Status Register */


/* %jp{UARTの初期化} */
void Uart_Initialize(void)
{
	/* UART */
	*REG_IOCON_PIO1_6 = ((*REG_IOCON_PIO1_6 & 0xfffffff8) | 0x00000001);
	*REG_IOCON_PIO1_7 = ((*REG_IOCON_PIO1_6 & 0xfffffff8) | 0x00000001);
	
	*REG_U0LCR = 0x83;
	*REG_U0DLL = (12000000 * 4) / 16 / 115200;
	*REG_U0DLM = 0;
	*REG_U0LCR = 0x03;		/* 8bit nonparity */
	*REG_U0FCR = 0x07;		/* FIFO reset & enable */
}


/* %jp{1文字出力} */
void Uart_PutChar(int c)
{
	while ( !(*REG_U0LSR & 0x40) )
		;

	*REG_U0THR = c;
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
