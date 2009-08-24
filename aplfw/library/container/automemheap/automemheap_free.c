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



/** %jp{メモリの解放} */
void AutoMemHeap_Free(void *pMemHeap, void *pMem)
{
	C_AUTOMEMHEAP	*self;
	C_MEMHEAP		*pHeap;

	/* upper cast */
	self = (C_AUTOMEMHEAP *)pMemHeap;
	
	if ( (pHeap = AutoMemHeap_SearchHeap(self, pMem)) != NULL )
	{
		MemHeap_Free(pHeap, pMem);
	}
	else
	{
		MemHeap_Free(self->pMemHeap, (void *)((char *)pMem - MemHeap_AlignSize(self->pMemHeap, sizeof(T_AUTOMEMHEAP_MEM))));
	}
}


/* end of file */
