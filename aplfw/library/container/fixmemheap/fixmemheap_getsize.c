/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fixmemheap_free.c
 * @brief %jp{固定サイズメモリヒープクラス}%en{fixed size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "fixmemheap_local.h"



/** メモリのサイズ取得 */
MEMSIZE	FixMemHeap_GetSize(void *pMemHeap, void *pMem)
{
	C_FIXMEMHEAP		*self;
	
	/* upper cast */
	self = (C_FIXMEMHEAP *)pMemHeap;

	return self->BlkSize;
}


/* end of file */
