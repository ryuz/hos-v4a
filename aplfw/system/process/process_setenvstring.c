/** 
 *  Hyper Operating System  Application Framework
 *
 * @file process_setenvstring.c
 * @brief %jp{環境変数設定}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "process_local.h"



/** 環境変数設定 */
void Process_SetEnvString(HANDLE hProcess, const char *pszKey, const char *pszValue)
{
	C_PROCESS *self;
	
	/* 指定が無ければ現在のプロセスとする */
	if ( hProcess == HANDLE_NULL )
	{
		hProcess = Process_GetCurrentHandle();
	}
	
	/* ハンドルをキャスト */
	self = (C_PROCESS *)hProcess;
	
	/* 領域が無ければ生成 */
	if ( self->pEnv == NULL )
	{
		self->pEnv = Assoc_CreateEx(SysMem_GetMemHeap());
		if ( self->pEnv == NULL )
		{
			return;
		}
	}
	
	/* パラメータを設定 */
	Assoc_Set(self->pEnv, pszKey, pszValue, strlen(pszValue)+1);
}


/* end of file */
