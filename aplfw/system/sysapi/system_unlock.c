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


/* システム全体のロック解除 */
void System_Unlock(void)
{
	SysMtx_Unlock(System_hMtx);
}


/* end of file */
