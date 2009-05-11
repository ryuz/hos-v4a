/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"


/* システム用ミューテックスロック解除*/
void SysMtx_Unlock(SYSMTX_HANDLE hMtx)
{
#ifdef _HOS_SYSPAI_USEMTX
	unl_mtx((ID)hMtx);
#else
	sig_sem((ID)hMtx);
#endif
}


/* end of file */
