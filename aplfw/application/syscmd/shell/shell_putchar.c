/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  shell_main.c
 * @brief %jp{シェル}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "shell_local.h"


/* スクリーンに１文字出力 */
void Shell_PutChar(C_SHELL *self, int c)
{
	StdCon_PutChar(c);	
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		StdCon_PutString("\n");
	}	
}


/* end of file */
