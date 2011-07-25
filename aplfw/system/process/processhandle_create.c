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


static const T_PROCESSHANDLE_METHODS ProcessHandle_ObjMethods =
	{
		{
			"ProcessHandle",
			ProcessHandle_Delete,		/* 削除 */
		}
	};


/* プロセス生成 */
HANDLE ProcessHandle_Create(struct c_process *pProcess)
{
	C_PROCESSHANDLE *self;
	
	/* メモリ確保 */
	if ( (self = (C_PROCESSHANDLE *)SysMem_Alloc(sizeof(C_PROCESSHANDLE))) == NULL )
	{
		return HANDLE_NULL;
	}

	/* 親クラスコンストラクタ */
	HandleObj_Constructor(&self->HandleObj, &ProcessHandle_ObjMethods.HandlObjMethods, NULL);
	
	/* 紐付け */
	self->pProcess = pProcess;
	pProcess->uiOpenCounter++;

	return (HANDLE)self;
}

/* end of file */
