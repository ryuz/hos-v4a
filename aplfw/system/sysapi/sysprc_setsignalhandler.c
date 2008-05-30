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


void SysPrc_SetSignalHandler(SYSPRC_HANDLE hPrc, void (*pfncSinalProc)(void))
{
	T_DTEX	dtex;
	
	dtex.texatr = TA_HLNG;
	dtex.texrtn = (FP)pfncSinalProc;
	def_tex((ID)hPrc, &dtex);
	ena_tex();
}


/* end of file */
