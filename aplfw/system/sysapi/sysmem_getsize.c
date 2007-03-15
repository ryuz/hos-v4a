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
MEMSIZE SysMem_GetSize(void *pMem)
{
	MEMSIZE Size;
	SysMtx_Lock(SysMem_hMtx);
	Size = MemPol_GetSize(&SysMem_MemPol, pMem);
	SysMtx_Unlock(SysMem_hMtx);

	return Size;
}


/* end of file */
