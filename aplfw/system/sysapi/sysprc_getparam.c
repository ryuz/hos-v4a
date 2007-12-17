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
	T_RTST	rtst;
	
	ref_tst((ID)hPrc, &rtst);
	
	return (VPARAM)rtst.exinf;
}


/* end of file */
