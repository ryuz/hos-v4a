/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "sysapi_local.h"


/* I/O用メモリのの割り当て */
void *SysIo_AllocIoMem(MEMSIZE Size)
{
	void *pMem;

	/* 通常メモリと兼用 */
	if ( SysIo_pValMemHeap == NULL )
	{
		return SysMem_Alloc(Size);
	}
	
	/* I/O専用領域から割り当て */
	SysMtx_Lock(SysIo_hMtx);
	pMem = ValMemHeap_Alloc(SysIo_pValMemHeap, Size);
	SysMtx_Unlock(SysIo_hMtx);
	
	return pMem;
}


/* end of file */
