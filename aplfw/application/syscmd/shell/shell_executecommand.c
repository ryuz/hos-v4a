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
	
	if ( self->ExecSimple )
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
		Inf.hConIn         = Process_GetConIn(HANDLE_NULL);			/* コンソール */
		Inf.hConOut        = Process_GetConIn(HANDLE_NULL);			/* コンソール出力 */
		Inf.hStdIn         = Process_GetStdIn(HANDLE_NULL);			/* 標準入力 */
		Inf.hStdOut        = Process_GetStdOut(HANDLE_NULL);		/* 標準出力 */
		Inf.hStdErr        = Process_GetStdErr(HANDLE_NULL);		/* 標準エラー出力 */
		hProcess = Process_CreateEx(&Inf);

		if ( iBackGround )
		{
			T_SHELL_BACKGROUND *pBg;
	
			/* バックグランドプロセスをリストに登録 */
			pBg = (T_SHELL_BACKGROUND *)Memory_Alloc(sizeof(T_SHELL_BACKGROUND));
			pBg->hProcess = hProcess;
			if ( self->pBackGround == NULL )
			{
				self->pBackGround = pBg;
				pBg->pNext        = NULL;
			}
			else
			{
				pBg->pNext               = self->pBackGround->pNext;
				self->pBackGround->pNext = pBg;
			}
		}
		else
		{
			/* フォアグランドなら終わるまで待つ */
			Process_WaitExit(hProcess);
			Process_Delete(hProcess);
		}
		
		/* バックグランドプロセスで終わったものが無いかチェック */
		Shell_CheckBackGround(self);
	}	
	
	return iExitCode;
}



/* バックグランドジョブで終わったものが無いかチェック */
void Shell_CheckBackGround(C_SHELL *self)
{
	T_SHELL_BACKGROUND *pBg;
	T_SHELL_BACKGROUND *pBgPrev;

	/* バックグランドジョブで終わったものが無いかチェック */
	pBg     = self->pBackGround;
	pBgPrev = NULL;
	while ( pBg != NULL )
	{
		if ( Process_IsExit(pBg->hProcess) )
		{
			/* 終了通知 */
			StdIo_PrintFormat("[exit(%d)] %s\n", 
					Process_GetExitCode(pBg->hProcess),
					Process_GetCommandLine(pBg->hProcess));
			
			if ( self->ExecTime )
			{
				unsigned long ulCpuSecond;
				unsigned long ulCpuNanosecond;
				ulCpuSecond = Process_GetExecutionTime(pBg->hProcess, &ulCpuNanosecond);
				StdIo_PrintFormat("cpu time: %lu[s] + %lu[ns]\n", ulCpuSecond, ulCpuNanosecond);
			}
			
			/* 閉じる */
			Process_Delete(pBg->hProcess);
			
			/* リストからはずす */
			if ( pBgPrev == NULL )
			{
				self->pBackGround = pBg->pNext;
			}
			else
			{
				pBgPrev->pNext = pBg->pNext;
			}
			pBg = pBg->pNext;
			
			/* メモリ開放 */
			Memory_Free(pBg);
		}
		else
		{
			pBgPrev = pBg;
			pBg     = pBg->pNext; 
		}
	}
}


/* end of file */
