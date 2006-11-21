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


/* システムメモリの再割り当て */
void *SysMem_ReAlloc(void *pMem, MEMSIZE Size)
{
	SysMtx_Lock(SysMem_hMtx);
	pMem = MemPol_ReAlloc(&SysMem_MemPol, pMem, Size);
	SysMtx_Unlock(SysMem_hMtx);

	return pMem;
}



/* end of file */
