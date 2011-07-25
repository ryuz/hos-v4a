/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "process_local.h"



/* プロセス生成 */
HANDLE Process_Create(const char *pszCommand, MEMSIZE StackSize, int Priority)
{
	T_PROCESS_CREATE_INF Inf;
	
	/* デフォルト値 */
	if ( StackSize == 0 )
	{
		StackSize = 4096;
	}
	if ( Priority == 0 )
	{
		Priority = PROCESS_PRIORITY_NORMAL;
	}
	
	Inf.pszCommandLine = pszCommand;							/**< コマンドライン */
	Inf.pszCurrentDir  = Process_GetCurrentDir(HANDLE_NULL);	/**< 起動ディレクトリ */
	Inf.pfncEntry      = NULL;									/**< 起動アドレス */
	Inf.Param          = 0;										/**< ユーザーパラメータ */
	Inf.StackSize      = StackSize;								/**< スタックサイズ */
	Inf.Priority       = Priority;								/**< プロセス優先度 */
	Inf.hTerminal      = Process_GetTerminal();			/**< ターミナル */
	Inf.hConsole       = Process_GetConsole();			/**< コンソール入力 */
	Inf.hStdIn         = Process_GetStdIn();			/**< 標準入力 */
	Inf.hStdOut        = Process_GetStdOut();			/**< 標準出力 */
	Inf.hStdErr        = Process_GetStdErr();			/**< 標準エラー出力 */
	
	return Process_CreateEx(&Inf);
}
	


/* end of file */
