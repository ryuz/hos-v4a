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



/* システム用ミューテックス削除 */
void SysMtx_Delete(SYSMTX_HANDLE hMtx)
{
	del_sem((ID)hMtx);
}


/* end of file */
