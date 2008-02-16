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



/* ラインを置き換える */
void Shell_ReplaceLine(C_SHELL *self, const char *pszNewLine)
{
	int iOldLen;
	int i;
	
	/* 前回の長さを保存 */
	iOldLen = self->iCommandLen;
	
	/* 行先頭まで移動 */
	while ( self->iCurPos > 0 )
	{
		Shell_CurLeft(self);
		self->iCurPos--;
	}
	
	/* 新しい文字列を出力 */
	for ( i = 0; pszNewLine[i] != '\0'; i++ )
	{
		Shell_PutChar(self, pszNewLine[i]);
		self->pszCommanBuf[i] = pszNewLine[i];
		self->iCurPos++;
	}
	self->iCommandLen = i;
	
	/* 末尾削除 */
	for ( i = self->iCommandLen; i < iOldLen; i++ )
	{
		Shell_PutChar(self, ' ');
	}
	for ( i = self->iCommandLen; i < iOldLen; i++ )
	{
		Shell_CurLeft(self);
	}	
}


/* end of file */
