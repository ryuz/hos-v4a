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
#include "regs_sh7144.h"


/* %jp{SCI1 の初期化} */
void Sci1_Initialize(void)
{
	*REG_STANDBY_MSTCR1 &= ~0x0002;	/* %jp{SCI1のスタンバイモードを解除} */
	*REG_SCI1_SCR    = 0;
	*REG_SCI1_SMR    = 0;
	*REG_SCI1_BRR    = 19;			/* %jp{ボーレート設定(38400bps)} */
	*REG_PFC_PACRL2 |= 0x0100;		/* %jp{端子設定} */
	*REG_SCI1_SCR   |= 0x20;		/* %jp{送信許可} */
}

/* %jp{1文字出力} */
void Sci1_PutChar(int c)
{
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


/* end of file */
