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


/** メモリがヒープに属しているかチェック */
int ValMemHeap_IsMember(void *pMemHeap, void *pMem)
{
	C_VALMEMHEAP	*self;
	
	/* upper cast */
	self = (C_VALMEMHEAP *)pMemHeap;

	/* %jp{ポインタ範囲チェック} */
	if ( pMem < (void *)self->pMemBase || pMem >= (void *)((char *)self->pMemBase + self->MemSize) )
	{
		return 0;
	}
	
	return 1;
}


/* end of file */
