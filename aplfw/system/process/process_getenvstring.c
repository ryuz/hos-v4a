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
const char *Process_GetEnvString(const char *pszKey)
{
	const char		*pszValue = NULL;
	C_PROCESSOBJ	*self;
	
	/* オブジェクトを取得 */
	self = Process_GetCurrentProcessObj();
	
	if ( self->pEnv != NULL )
	{
		pszValue = Assoc_Get(self->pEnv, pszKey);
	}
	
	return pszValue;
}



/* end of file */
