/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sci1.c
 * @brief %jp{SCI1への出力}%en{SCI1 device driver}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"



#define REG_SCI1_SMR		((volatile UB*)0xffffffb8)
#define REG_SCI1_BRR		((volatile UB*)0xffffffb9)
#define REG_SCI1_SCR		((volatile UB*)0xffffffba)
#define REG_SCI1_TDR		((volatile UB*)0xffffffbb)
#define REG_SCI1_SSR		((volatile UB*)0xffffffbc)
#define REG_SCI1_RDR		((volatile UB*)0xffffffbd)
#define REG_SCI1_SCMR		((volatile UB*)0xffffffbe)



/* %jp{SCI1 の初期化} */
void Sci1_Initialize(void)
{
	*REG_SCI1_SCR  = 0;
	*REG_SCI1_SMR  = 0;
	*REG_SCI1_BRR  = 15;		/* %jp{ボーレート設定(38400bps)} */
	*REG_SCI1_SCR |= 0x20;		/* %jp{送信許可} */
}

/* %jp{1文字出力} */
void Sci1_PutChar(int c)
{
/*	return;	*/
	
	while ( ((*REG_SCI1_SSR) & 0x80) != 0x80 )
		;
	
	*REG_SCI1_TDR = (UB)c;
	
	*REG_SCI1_SSR &= 0x7f;
}

/* %jp{文字列出力} */
void Sci1_PutString(const char *text)
{
	while ( *text != '\0' )
	{
		if ( *text == '\n' )
		{
			Sci1_PutChar('\r');
			Sci1_PutChar('\n');
		}
		else
		{
			Sci1_PutChar(*text);
		}
		
		text++;
	}
}




char Sci1_hex2asc(int a)
{
	if ( a < 10 )
	{
		return '0' + a;
	}
	return 'a' + a - 10;
}


void Sci1_PutHexByte(char c)
{
	Sci1_PutChar(Sci1_hex2asc((c >> 4) & 0xf));
	Sci1_PutChar(Sci1_hex2asc((c >> 0) & 0xf));
}

void Sci1_PutHexWord(int i)
{
	Sci1_PutHexByte((i >> 8) & 0xff);
	Sci1_PutHexByte((i >> 0) & 0xff);
}



/* end of file */
