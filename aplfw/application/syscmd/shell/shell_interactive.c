/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  shell_create.c
 * @brief %jp{シェル}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "shell_local.h"



/* インタラクティブモード */
int Shell_Interactive(C_SHELL *self)
{
	char				*pszHisBuf;
	int 				i;
	int					j;

	for ( ; ; )
	{
		/* コマンド入力 */
		Shell_InputLine(self, self->pszCommanBuf, self->iCommandBufSize - 1);

		/* 終了ジョブが無いかチェック */
		Shell_CheckBackGround(self);

		/* exit なら抜ける */
		if ( strcmp(self->pszCommanBuf, "exit") == 0 )
		{
			break;
		}

		/* 空行またはコメントなら無視 */
		if ( self->pszCommanBuf[0] == '\0' || self->pszCommanBuf[0] == '#' )
		{
			continue;
		}


		/* ヒストリ記憶 */
		if ( self->ppszHistory != NULL )
		{
			if ( (pszHisBuf = Memory_Alloc(strlen(self->pszCommanBuf) + 1)) != NULL )
			{
				strcpy(pszHisBuf, self->pszCommanBuf);

				/* ヒストリ重複削除 */
				for ( i = 0; i < self->iHistoryMax; i++ )
				{
					if ( self->ppszHistory[i] != NULL && strcmp(self->ppszHistory[i], self->pszCommanBuf) == 0 )
					{
						Memory_Free(self->ppszHistory[i]);
						for ( j = i; j+1 < self->iHistoryMax; j++ )
						{
							self->ppszHistory[j] = 	self->ppszHistory[j+1];
						}
						self->ppszHistory[self->iHistoryMax-1] = NULL;
						break;
					}
				}
				
				/* 古いものを削除 */
				if ( self->ppszHistory[self->iHistoryMax-1] != NULL )
				{
					Memory_Free(self->ppszHistory[self->iHistoryMax-1]);
				}
				for ( i = self->iHistoryMax-1; i > 0; i-- )
				{
					self->ppszHistory[i] = self->ppszHistory[i-1];
				}
				
				/* 追加 */
				self->ppszHistory[0] = pszHisBuf;
			}
		}

		/* コマンド実行 */
		Shell_ExecuteCommand(self, self->pszCommanBuf);
	}
	
	return 0;
}


/* end of file */
