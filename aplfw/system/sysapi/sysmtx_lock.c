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


/* システム用ミューテックスロック*/
void SysMtx_Lock(SYSMTX_HANDLE hMtx)
{
	wai_sem((ID)hMtx);
}


/* end of file */
