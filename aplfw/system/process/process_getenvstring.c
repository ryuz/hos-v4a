/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "process_local.h"


/** 環境変数取得 */
const char *Process_GetEnvString(HANDLE hProcess, const char *pszKey)
{
	const char	*pszValue = NULL;
	C_PROCESS	*self;
	HANDLE		hParent;
	
	/* 指定が無ければ現在のプロセスとする */
	if ( hProcess == HANDLE_NULL )
	{
		hProcess = Process_GetCurrentHandle();
	}
	
	/* ハンドルをキャスト */
	self = (C_PROCESS *)hProcess;
	
	if ( self->pEnv != NULL )
	{
		pszValue = Assoc_Get(self->pEnv, pszKey);
	}
	
	if ( pszValue == NULL )
	{
		if ( (hParent = Process_GetParentProcess(hProcess)) != HANDLE_NULL )
		{
			pszValue = Process_GetEnvString(hParent, hProcess);
		}
	}
	
	return pszValue;
}



/* end of file */
