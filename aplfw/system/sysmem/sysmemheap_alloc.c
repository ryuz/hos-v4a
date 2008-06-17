/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysmemheap_alloc.c
 * @brief %jp{システムメモリヒープクラス}%en{system memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "sysmemheap_local.h"



/** %jp{メモリの割り当て} */
void *SysMemHeap_Alloc(void *pMemHeap, MEMSIZE Size)
{
	C_SYSMEMHEAP	*self;
	void			*pMem;	
	
	/* upper cast */
	self = (C_SYSMEMHEAP *)pMemHeap;
	
	SysMtx_Lock(self->hMtx);
	pMem = MemHeap_Alloc(self->pMemHeap, Size);
	SysMtx_Unlock(self->hMtx);
	
	return pMem;
}

/* end of file */
