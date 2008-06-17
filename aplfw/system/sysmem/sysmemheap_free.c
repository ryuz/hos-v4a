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



/** %jp{メモリの解放} */
void SysMemHeap_Free(void *pMemHeap, void *pMem)
{
	C_SYSMEMHEAP	*self;
	
	/* upper cast */
	self = (C_SYSMEMHEAP *)pMemHeap;
	
	SysMtx_Lock(self->hMtx);
	MemHeap_Free(self->pMemHeap, pMem);
	SysMtx_Unlock(self->hMtx);
}



/* end of file */
