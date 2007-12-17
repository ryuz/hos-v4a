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


/** プロセス終了(システム用) */
void SysPrc_Terminate(SYSPRC_HANDLE hPrc)		
{
	if ( hPrc == SysPrc_GetCurrentHandle() )
	{
		ext_tsk();
	}
	else
	{
		ter_tsk((ID)hPrc);
	}
}



/* end of file */
