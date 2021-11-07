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

#include "uart.h"

/* %jp{UARTレジスタ} */
#define RISCV64_VIRT_UART0_PADDR     ((volatile UB *)(0x10000000))

/* %jp{UARTの初期化} */
void Uart_Initialize(void)
{
	/* %jp{割込み通知を無効化} */
	RISCV_VIRT_UART_WRITE_REG(RISCV64_VIRT_UART0_PADDR, UART_INTR, UART_INTR_DIS);

	/* %jp{baud rateの設定} */
	RISCV_VIRT_UART_WRITE_REG(RISCV64_VIRT_UART0_PADDR, UART_LCTRL, 0x80);

	/* %jp{38.4K baud rateに設定} */
	RISCV_VIRT_UART_WRITE_REG(RISCV64_VIRT_UART0_PADDR, 0, 0x03);  /* LSB */
	RISCV_VIRT_UART_WRITE_REG(RISCV64_VIRT_UART0_PADDR, 1, 0x00);  /* MSB */

	/* %jp{8bit パリティなしに設定し回線速度設定モードを抜ける} */
	RISCV_VIRT_UART_WRITE_REG(RISCV64_VIRT_UART0_PADDR, UART_LCTRL, 0x03);

	/* %jp{FIFOを有効化する} */
	RISCV_VIRT_UART_WRITE_REG(RISCV64_VIRT_UART0_PADDR, UART_FIFO, 0x07);
}


/* %jp{1文字入力} */
char Uart_GetChar(void)
{
	/* %jp{受信可能になるのを待ち合わせる} */
	while( (RISCV_VIRT_UART_READ_REG(RISCV64_VIRT_UART0_PADDR, UART_LSR) &
		 UART_LSR_RXRDY) == 0 )
		;

	/* %jp{1バイト受信} */
	return RISCV_VIRT_UART_READ_REG(RISCV64_VIRT_UART0_PADDR, UART_RHR);
}


/* %jp{1文字出力} */
void Uart_PutChar(int c)
{
	/* %jp{送信可能になるのを待ち合わせる} */
	while( (RISCV_VIRT_UART_READ_REG(RISCV64_VIRT_UART0_PADDR, UART_LSR) &
		UART_LSR_TXHOLD) == 0 )
		;

	/* %jp{1バイト送信} */
	RISCV_VIRT_UART_WRITE_REG(RISCV64_VIRT_UART0_PADDR, UART_THR, c);
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
