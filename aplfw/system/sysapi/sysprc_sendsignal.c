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


void SysPrc_SendSignal(SYSPRC_HANDLE hPrc)
{
	ras_tex((ID)hPrc, 1);
}


/* end of file */
