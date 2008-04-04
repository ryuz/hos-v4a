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
#include <stdlib.h>
#include "shell_local.h"



/** メイン関数 */
int Shell_Main(int argc, char *argv[])
{
	C_SHELL *self;
	int		iCommandBufSize = SHELL_MAX_COMMAND;
	int 	iHistoryMax     = SHELL_MAX_HISTORY;
	int		iExecSimple     = 0;
	int		iExecTime       = 0;
	int		iInteractive    = 0;
	int		iExecString     = 0;
	char	*pszScript      = NULL;
	int     iExitCode       = 0;
	int		i;
	
	
	/* オプションを解析 */
	for ( i = 1; i < argc; i++ )
	{
		if ( argv[i][0] == '-' )
		{
			if ( strcmp(&argv[i][1], "i") == 0 )							/* インタラクティブモード */
			{
				iInteractive = 1;
			}
			else if ( strcmp(&argv[i][1], "exe") == 0 )						/* 単純実行 */
			{
				iExecSimple = 1;
			}
			else if ( strcmp(&argv[i][1], "time") == 0 )					/* 時間計測 */
			{
				iExecTime = 1;
			}
			else if ( strcmp(&argv[i][1], "s") == 0 && i+1 < argc )			/* 文字列実行 */
			{
				i++;
				iExecString = i;
			}
			else if ( strcmp(&argv[i][1], "buf") == 0 && i+1 < argc )		/* コマンドバッファ設定 */
			{
				i++;
				iCommandBufSize = strtol(argv[i], NULL, 0);
			}
			else if ( strcmp(&argv[i][1], "his") == 0 && i+1 < argc )		/* ヒストリ数設定 */
			{
				i++;
				iHistoryMax = strtol(argv[i], NULL, 0);
			}
		}
		else
		{
			pszScript = argv[i];
		}
	}
	
	
	/* オブジェクト生成 */
	if ( (self = Shell_Create(iCommandBufSize, iHistoryMax, iExecSimple, iExecTime)) == NULL )
	{
		return 1;
	}
	

	if ( iExecString > 0 )
	{
		/* 文字列実行 */
		self->pszCommanBuf[0] = '\0';
		for ( i = iExecString; i < argc; i++ )
		{
			strcat(self->pszCommanBuf, argv[i]);
			if ( i + 1 < argc )
			{
				strcat(self->pszCommanBuf, " ");
			}
		}
			
		/* 実行 */
		iExitCode = Shell_ExecuteCommand(self, self->pszCommanBuf);
	}
	else if ( pszScript != NULL )
	{
		/* スクリプト実行 */
		iExitCode = Shell_ExecuteScript(self, pszScript);
	}
	
	/* インタラクティブモード */
	if ( iInteractive )
	{
		iExitCode = Shell_Interactive(self);
	}
	
	/* オブジェクト削除 */
	Shell_Delete(self);
	
	return iExitCode;
}



/* end of file */
