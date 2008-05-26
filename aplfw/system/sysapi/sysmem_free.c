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


/* システムメモリの返却 */
void  SysMem_Free(void *pMem)
{
	SysMtx_Lock(SysMem_hMtx);
	ValMemHeap_Free(&SysMem_ValMemHeap, pMem);
	SysMtx_Unlock(SysMem_hMtx);
}



/* end of file */
