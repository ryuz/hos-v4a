/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  automemheap_free.c
 * @brief %jp{メモリヒープクラス}%en{auto size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "automemheap_local.h"



/** サイズをアライメント単位に拡張 */
MEMSIZE AutoMemHeap_AlignSize(void *pMemHeap, MEMSIZE Size)
{
	C_AUTOMEMHEAP	*self;
	
	/* upper cast */
	self = (C_AUTOMEMHEAP *)pMemHeap;
	
	return MemHeap_AlignSize(self->pMemHeap, Size);
}


/* end of file */
