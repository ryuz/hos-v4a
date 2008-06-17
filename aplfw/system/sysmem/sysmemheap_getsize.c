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



/** メモリのサイズ取得 */
MEMSIZE	SysMemHeap_GetSize(void *pMemHeap, void *pMem)
{
	C_SYSMEMHEAP	*self;
	
	/* upper cast */
	self = (C_SYSMEMHEAP *)pMemHeap;
	
	return MemHeap_GetSize(self->pMemHeap, pMem);
}


/* end of file */
