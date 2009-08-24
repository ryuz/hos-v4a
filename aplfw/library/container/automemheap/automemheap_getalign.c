/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  automemheap_free.c
 * @brief %jp{メモリヒープクラス}%en{auto size memory heap class}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "automemheap_local.h"


/** メモリアライメントの取得 */
MEMSIZE	AutoMemHeap_GetAlign(void *pMemHeap)
{
	C_AUTOMEMHEAP	*self;
	
	/* upper cast */
	self = (C_AUTOMEMHEAP *)pMemHeap;

	return MemHeap_GetAlign(self->pMemHeap);
}


/* end of file */
