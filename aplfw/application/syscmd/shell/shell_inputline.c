/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  shell_main.c
 * @brief %jp{シェル}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "shell_local.h"


/* １行入力 */
int Shell_InputLine(C_SHELL *self, char *pszBuf, int  iBufSize)
{
	int  iHistoryPos = -1;
	int  i;
	int  c;


	/* プロンプトを出す */
	StdCon_PutString("\r% ");
	self->iCurScreenX = 2;
	
	self->iCommandLen = 0;
	self->iCurPos     = 0;
	
	for ( ; ; )
	{
		c = StdCon_GetCh();
		
		switch ( c )
		{
		case '\n':		/* 改行なら入力完了 */
			pszBuf[self->iCommandLen] = '\0';
			StdCon_PutString("\r\n");
			return self->iCommandLen;
		
		
		case CONSOLE_KEY_BACKSPACE:	/* バックスペースなら */
			if ( self->iCurPos > 0 )
			{
				memmove(&pszBuf[self->iCurPos - 1], &pszBuf[self->iCurPos], self->iCommandLen - self->iCurPos);
				self->iCurPos--;
				self->iCommandLen--;
				Shell_CurLeft(self);
				for ( i = 0; i < self->iCommandLen - self->iCurPos; i++ )
				{
					Shell_PutChar(self, pszBuf[self->iCurPos + i]);
				}
				Shell_PutChar(self, ' ');
				for ( i = 0; i < self->iCommandLen - self->iCurPos + 1; i++ )
				{
					Shell_CurLeft(self);
				}
			}
			break;

		case CONSOLE_KEY_UP:	/* 上 */
			if ( iHistoryPos + 1 < self->iHistoryMax && self->ppszHistory[iHistoryPos + 1] != NULL )
			{
				iHistoryPos++;
				Shell_ReplaceLine(self, self->ppszHistory[iHistoryPos]);
			}
			break;

		case CONSOLE_KEY_DOWN:	/* 下 */
			if ( iHistoryPos > 0 )
			{
				iHistoryPos--;
				Shell_ReplaceLine(self, self->ppszHistory[iHistoryPos]);
			}
			break;
		
		case CONSOLE_KEY_RIGHT:	/* 右 */
			if ( self->iCurPos < self->iCommandLen )
			{
				Shell_CurRight(self);
				self->iCurPos++;
			}
			break;
		
		case CONSOLE_KEY_LEFT:	/* 左 */
			if ( self->iCurPos > 0 )
			{
				Shell_CurLeft(self);
				self->iCurPos--;
			}
			break;

		case '\t':				/* TAB */
			break;

		default:		/* カーソル位置に文字設定 */
			if ( c >= 0x20 && c <= 255 )
			{
				if ( self->iCurPos < iBufSize - 1 )
				{
					memmove(&pszBuf[self->iCurPos + 1], &pszBuf[self->iCurPos], self->iCommandLen - self->iCurPos);
					pszBuf[self->iCurPos++] = (char)c;
					self->iCommandLen++;
					for ( i = 0; i < self->iCommandLen - self->iCurPos + 1; i++ )
					{
						Shell_PutChar(self, pszBuf[self->iCurPos + i - 1]);
					}
					for ( i = 0; i < self->iCommandLen - self->iCurPos; i++ )
					{
						Shell_CurLeft(self);
					}
				}
				else
				{
					StdCon_PutChar('\a');
				}
			}
			break;
		}
	}
}



/* end of file */
