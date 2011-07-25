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
#include "processhandle.h"



/* プロセス生成 */
HANDLE Process_CreateEx(const T_PROCESS_CREATE_INF *pInf)
{
	C_PROCESS		*self;
	C_PROCESSHANDLE	*pHandle;

	/* メモリ確保 */
	if ( (self = (C_PROCESS *)SysMem_Alloc(sizeof(C_PROCESS))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( Process_Constructor(self, NULL, pInf) != PROCESS_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}

	pHandle = ProcessHandle_Create(self);
	if ( pHandle == NULL )
	{
		Process_Destructor(self);
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	self->hProcess = (HANDLE)pHandle;

	return (HANDLE)pHandle;
}


/* end of file */
