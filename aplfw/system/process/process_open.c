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


/* プロセスオープン */
HANDLE Process_Open(unsigned long ulProcessId)
{
	C_PROCESSOBJ	*pObj;
	C_PROCESSPTR	*pPtr;
	
	/* オブジェクト取得 */
	if ( (pObj = System_GetProcessObj(ulProcessId)) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* ポインタ生成 */
	if ( (pPtr = (C_PROCESSPTR *)ProcessPtr_Create(pObj)) == NULL )
	{
		return HANDLE_NULL;
	}
	
	return (HANDLE)pPtr;
}


/* end of file */
