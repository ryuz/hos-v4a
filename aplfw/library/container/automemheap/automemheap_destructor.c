/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  automemheap_free.c
 * @brief %jp{固定サイズメモリヒープクラス}%en{fixed size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "automemheap_local.h"


/** デストラクタ */
void AutoMemHeap_Destructor(C_AUTOMEMHEAP *self)							
{
	T_AUTOMEMHEAP_FIX	*pFixHeap;
	T_AUTOMEMHEAP_FIX	*pFixHeapNext;
	T_AUTOMEMHEAP_VAL	*pValHeap;
	T_AUTOMEMHEAP_VAL	*pValHeapNext;
	T_AUTOMEMHEAP_MEM	*pMemHeap;
	T_AUTOMEMHEAP_MEM	*pMemHeapNext;
	
	
	/* 固定長メモリヒープ開放 */
	for ( pFixHeap = self->pFixList; pFixHeap != NULL; pFixHeap = pFixHeapNext )
	{
		pFixHeapNext = pFixHeap->pNext;
		MemHeap_Free(self->pMemHeap, pFixHeap);
	}
	
	/* 可変長メモリヒープに無いか探索 */
	for ( pValHeap = self->pValList; pValHeap != NULL; pValHeap = pValHeapNext )
	{
		pValHeapNext = pValHeap->pNext;
		MemHeap_Free(self->pMemHeap, pValHeap);
	}
	
	/* 基底ヒープに開放 */
	for ( pMemHeap = self->pMemList; pMemHeap != NULL; pMemHeap = pMemHeapNext )
	{
		pMemHeapNext = pMemHeap->pNext;
		MemHeap_Free(self->pMemHeap, pMemHeap);
	}
}


/* end of file */
