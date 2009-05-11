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
#ifdef _HOS_SYSPAI_USEMTX
	del_mtx((ID)hMtx);
#else
	del_sem((ID)hMtx);
#endif
}


/* end of file */
