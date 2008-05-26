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


/** メモリアライメントの取得 */
MEMSIZE	ValMemHeap_GetAlign(void *pMemHeap)
{
	C_VALMEMHEAP	*self;
	
	/* upper cast */
	self = (C_VALMEMHEAP *)pMemHeap;

	return self->AlignMask + 1;
}


/* end of file */
