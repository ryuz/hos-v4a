/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include <string.h>
#include "process_local.h"

#if 0

HANDLE Process_GetParentProcess(HANDLE hProcess)
{
	C_PROCESS *self;
	
	/* 指定が無ければ現在のプロセスとする */
	if ( hProcess == HANDLE_NULL )
	{
		hProcess = Process_GetCurrentHandle();
	}
	
	/* ハンドルをキャスト */
	self = (C_PROCESS *)hProcess;
	
	return (HANDLE)self->PointerObj.pParent;
}

#endif

/* end of file */
