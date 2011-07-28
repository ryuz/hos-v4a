/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  processhandle_create.c
 * @brief %jp{プロセスハンドル生成}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "process_local.h"
#include "processhandle.h"


/* プロセス削除 */
void ProcessHandle_Delete(HANDLE Handle)
{
	C_PROCESSHANDLE *self;
	C_PROCESS		*pProcess;
	
	self = (C_PROCESSHANDLE *)Handle;
	
	pProcess = self->pProcess;

	/* 自身を削除 */
	PointerObj_Destructor(&self->PointerObj);
	SysMem_Free(self);
	
	/* 最後の参照ならプロセスを閉じる */
	if ( --pProcess->uiOpenCounter == 0 )
	{
		Process_Delete(pProcess);
	}
}


/* end of file */
