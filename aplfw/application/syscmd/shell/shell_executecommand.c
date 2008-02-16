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


/* コマンド実行 */
int Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand)
{
	T_PROCESS_CREATE_INF Inf;
	HANDLE	hProcess;
	int 	iExitCode = 0;
	int		iBackGround = 0;
	int 	iLen;
	
	if ( self->iSimpleExec )
	{
		Command_Execute(pszCommand, &iExitCode);
	}
	else
	{
		iLen = strlen(pszCommand);
		if ( iLen > 1 && pszCommand[iLen - 1] == '&' )
		{
			((char *)pszCommand)[iLen - 1] = '\0';
			iBackGround = 1;
		}	
		
		/* プロセスの生成 */
		Inf.pszCommandLine = pszCommand;
		Inf.pszCurrentDir  = Process_GetCurrentDir(HANDLE_NULL);
		Inf.pfncEntry      = NULL;									/* 起動アドレス */
		Inf.Param          = 0;										/* ユーザーパラメータ */
		Inf.StackSize      = 2048;									/* スタックサイズ */
		Inf.Priority       = PROCESS_PRIORITY_NORMAL+1;				/* プロセス優先度 */
		Inf.hTerminal      = Process_GetTerminal(HANDLE_NULL);		/* ターミナル */
		Inf.hConsole       = Process_GetConsole(HANDLE_NULL);		/* コンソール */
		Inf.hStdIn         = Process_GetStdIn(HANDLE_NULL);			/* 標準入力 */
		Inf.hStdOut        = Process_GetStdOut(HANDLE_NULL);		/* 標準出力 */
		Inf.hStdErr        = Process_GetStdErr(HANDLE_NULL);		/* 標準エラー出力 */
		hProcess = Process_Create(&Inf);

		if ( iBackGround )
		{
			T_SHELL_BACKGROUND *pBg;
			
			/* バックグランドジョブをリストに登録 */
			pBg = (T_SHELL_BACKGROUND *)Memory_Alloc(sizeof(T_SHELL_BACKGROUND));
			pBg->hProcess = hProcess;
			if ( self->pBackGround == NULL )
			{
				self->pBackGround = pBg;
				pBg->pNext = pBg;
			}
			else
			{
				pBg->pNext = self->pBackGround->pNext;
				self->pBackGround->pNext = pBg;
			}
		}
		else
		{
			/* フォアグランドなら終わるまで待つ */
			Process_WaitExit(hProcess);
			Process_Delete(hProcess);
		}
	}
	
	return iExitCode;
}



/* end of file */
