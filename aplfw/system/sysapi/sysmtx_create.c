/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"



/* システム用ミューテックス生成 */
SYSMTX_HANDLE SysMtx_Create(void)
{
	T_CSEM csem;
	ER_ID  erid;

	/* ロック用セマフォ生成 */
	csem.sematr  = TA_TFIFO;
	csem.isemcnt = 1;
	csem.maxsem  = 1;
	erid = acre_sem(&csem);
	if ( erid < 0 )
	{
		return SYSMTX_HANDLE_NULL;
	}

	return (SYSMTX_HANDLE)erid;
}


/* end of file */
