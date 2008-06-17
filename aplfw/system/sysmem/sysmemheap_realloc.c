/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysmemheap_alloc.c
 * @brief %jp{システムメモリヒープクラス}%en{system memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysmemheap_local.h"



/** %jp{メモリの再割り当て} */
void *SysMemHeap_ReAlloc(void *pMemHeap, void *pMem, MEMSIZE Size)
{
	C_SYSMEMHEAP	*self;
	
	/* upper cast */
	self = (C_SYSMEMHEAP *)pMemHeap;
	
	SysMtx_Lock(self->hMtx);
	pMem = MemHeap_ReAlloc(self->pMemHeap, pMem, Size);
	SysMtx_Unlock(self->hMtx);
	
	return pMem;
}


/* end of file */
