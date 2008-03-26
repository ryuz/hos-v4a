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


void SysPrc_Delete(SYSPRC_HANDLE hPrc)
{
	SysPrc_InfTbl[(ID)hPrc].Param = 0;
	ter_tsk((ID)hPrc);
	del_tsk((ID)hPrc);
}



/* end of file */
