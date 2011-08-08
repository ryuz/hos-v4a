/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.h
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "process_local.h"


/* プロセスを閉じる */
void Process_Close(HANDLE handle)
{
	/* 自プロセスなら無視 */
	if ( handle == (HANDLE)Process_GetCurrentProcessObj() )
	{
		return;
	}
	
	/* 閉じる */
	Handle_Close(handle);
}


/* end of file */
