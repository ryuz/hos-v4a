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


SYSPRC_HANDLE SysPrc_GetCurrentHandle(void)
{
	ID tskid;
	if ( get_tid(&tskid) != E_OK )
	{
		return SYSPRC_HANDLE_NULL;
	}

	return (SYSPRC_HANDLE)tskid;
}


/* end of file */
