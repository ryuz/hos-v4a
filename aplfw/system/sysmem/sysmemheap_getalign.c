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


/** メモリアライメントの取得 */
MEMSIZE	SysMemHeap_GetAlign(void *pMemHeap)
{
	C_SYSMEMHEAP	*self;
	
	/* upper cast */
	self = (C_SYSMEMHEAP *)pMemHeap;
	
	return MemHeap_GetAlign(self->pMemHeap);
}


/* end of file */
