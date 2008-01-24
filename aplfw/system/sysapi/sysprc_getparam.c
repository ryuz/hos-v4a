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



/** プロセスのパラメータ取得(システム用) */
VPARAM SysPrc_GetParam(SYSPRC_HANDLE hPrc)
{
	return SysPrc_InfTbl[(ID)hPrc].Param;
}


/* end of file */
