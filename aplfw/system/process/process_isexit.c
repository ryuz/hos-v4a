/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "process_local.h"



/** プロセスの終了を確認 */
int Process_IsExit(HANDLE hProcess)
{
	C_PROCESSOBJ *self;
	
	/* ハンドルからオブジェクト本体を取得 */
	self = ProcessPtr_GetProcessObj(hProcess);
	
	return self->Exit;
}


/* end of file */
