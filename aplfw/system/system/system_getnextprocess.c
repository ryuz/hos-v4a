/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/sysapi/sysapi.h"
#include "system/system/system_local.h"
#include "system/process/process_local.h"


/* 次のプロセスを取得 */
HANDLE System_GetNextProcess(HANDLE hProcess)
{
	C_PROCESS *pProcess;
		
	if ( hProcess == NULL )
	{
		return (HANDLE)g_System.pRunProcess;
	}

	pProcess = (C_PROCESS *)hProcess;
	if ( pProcess->pNext != g_System.pRunProcess )
	{
		return (HANDLE)pProcess->pNext;
	}
	
	return HANDLE_NULL;
}


/* プロセスの登録 */
void System_RegistryProcess(C_PROCESS *pProcess)
{
	if ( g_System.pRunProcess == NULL )
	{
		g_System.pRunProcess = pProcess;
		pProcess->pNext = pProcess;
		pProcess->pPrev = pProcess;
	}
	else
	{
		pProcess->pNext = g_System.pRunProcess;
		pProcess->pPrev = pProcess->pNext->pPrev;
		pProcess->pNext->pPrev = pProcess;
		pProcess->pPrev->pNext = pProcess;
	}
}


/* プロセスの登録解除 */
void System_UnregistryProcess(C_PROCESS *pProcess)
{
	if ( pProcess->pNext == pProcess )
	{	
		g_System.pRunProcess = NULL;
	}
	else
	{
		pProcess->pNext->pPrev = pProcess->pPrev;
		pProcess->pPrev->pNext = pProcess->pNext;
	}
}


/* end of file */
