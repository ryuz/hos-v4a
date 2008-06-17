/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"


/** プロセス開始 */
void SysPrc_Start(SYSPRC_HANDLE hPrc)
{
	act_tsk((ID)hPrc);
}


/* end of file */
