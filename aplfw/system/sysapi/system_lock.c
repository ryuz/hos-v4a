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


/* システム全体のロック */
void System_Lock(void)
{
	SysMtx_Lock(System_hMtx);
}


/* end of file */
