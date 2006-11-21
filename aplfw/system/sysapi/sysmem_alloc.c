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


/* システムメモリの割り当て */
void *SysMem_Alloc(MEMSIZE Size)
{
	void *pMem;
	
	SysMtx_Lock(SysMem_hMtx);
	pMem = MemPol_Alloc(&SysMem_MemPol, Size);
	SysMtx_Unlock(SysMem_hMtx);

	return pMem;
}


/* end of file */
