/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "process_local.h"



/* 現在のプロセスを終了させる */
void Process_Exit(int iExitCode)
{
	C_PROCESSOBJ *pProcessObj;
	
	/* 現在のオブジェクト取得 */
	pProcessObj = Process_GetCurrentProcessObj();
	
	/* 終了コード設定 */
	pProcessObj->iExitCode = iExitCode;
	
	/* 終了を通知 */
	pProcessObj->Exit = 1;
	SysEvt_Set(pProcessObj->hEvt);
	
	/* オブジェクト削除 */
	ProcessObj_Delete(pProcessObj);
	
	/* 終了 */
	SysPrc_Exit();
}


/* end of file */
