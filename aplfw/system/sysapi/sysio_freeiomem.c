/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"


/* I/O用メモリの返却 */
void SysIo_FreeIoMem(void *pMem)
{
	/* 通常メモリと兼用 */
	if ( SysIo_pValMemHeap == NULL )
	{
		SysMem_Free(pMem);
		return;
	}
	
	/* I/O専用領域を返却 */
	SysMtx_Lock(SysIo_hMtx);
	ValMemHeap_Free(SysIo_pValMemHeap, pMem);
	SysMtx_Unlock(SysIo_hMtx);
}



/* end of file */
