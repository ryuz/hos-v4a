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
#include "kernel.h"


/* システム全体のロック */
void SysLoc_Lock(void)
{
	loc_cpu();
}


/* end of file */
