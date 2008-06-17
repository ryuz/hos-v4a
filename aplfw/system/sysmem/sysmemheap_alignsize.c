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



/** サイズをアライメント単位に拡張 */
MEMSIZE SysMemHeap_AlignSize(void *pMemHeap, MEMSIZE Size)
{
	C_SYSMEMHEAP	*self;
	
	/* upper cast */
	self = (C_SYSMEMHEAP *)pMemHeap;
	
	return MemHeap_AlignSize(self->pMemHeap, Size);
}


/* end of file */
