/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fixmemheap_ismember.c
 * @brief %jp{固定サイズメモリヒープクラス}%en{fixed size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "fixmemheap_local.h"


/** メモリがヒープに属しているかチェック */
int FixMemHeap_IsMember(void *pMemHeap, void *pMem)
{
	C_FIXMEMHEAP		*self;

	/* upper cast */
	self = (C_FIXMEMHEAP *)pMemHeap;
	
	/* %jp{ポインタ範囲チェック} */
	if ( pMem < (void *)self->pMemBase || pMem >= (void *)((char *)self->pMemBase + (self->BlkSize * self->BlkNum)) )
	{
		return 0;
	}
	
	return 1;
}


/* end of file */
