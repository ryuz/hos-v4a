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


void SysPrc_Resume(SYSPRC_HANDLE hPrc)
{
	rsm_tsk((ID)hPrc);
}


/* end of file */
