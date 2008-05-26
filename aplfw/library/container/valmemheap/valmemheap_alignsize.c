/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  valmemheap_free.c
 * @brief %jp{可変サイズメモリヒープクラス}%en{variable size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "valmemheap_local.h"



/** サイズをアライメント単位に拡張 */
MEMSIZE ValMemHeap_AlignSize(void *pMemHeap, MEMSIZE Size)
{
	C_VALMEMHEAP	*self;

	/* upper cast */
	self = (C_VALMEMHEAP *)pMemHeap;
	
	return (Size + self->AlignMask) & ~self->AlignMask;
}


/* end of file */
