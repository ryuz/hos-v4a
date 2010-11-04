/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sci1.c
 * @brief %jp{SCI1への出力}%en{SCI1 device driver}
 *
 * Copyright (C) 1998-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "regs_sh7262.h"


/* %jp{SCI1 の初期化} */
void Sci1_Initialize(void)
{
}

/* %jp{1文字出力} */
void Sci1_PutChar(int c)
{
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
