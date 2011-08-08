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
#include "system/system/system_local.h"



/* 現在のプロセス取得 */
C_PROCESSOBJ *Process_GetProcessObj(HANDLE handle)
{
	C_PROCESSOBJ	*pProcessObj;
	C_PROCESSPTR	*pProcessPtr;
	
	/* カレントプロセスを例外的に扱う */
	pProcessObj = Process_GetCurrentProcessObj();
	if ( handle == (HANDLE)pProcessObj )
	{
		return pProcessObj;
	}
	
	/* ポインタ変換 */
	pProcessPtr = (C_PROCESSPTR	*)handle;
	PROCESSPTR_CHECK_HANDLE(pProcessPtr);
	
	return ProcessPtr_GetProcessObj(pProcessPtr);
}


/* end of file */
