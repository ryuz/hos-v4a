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


/** 所属するヒープを検索 */
C_MEMHEAP *AutoMemHeap_SearchHeap(C_AUTOMEMHEAP *self, void *pMem)
{
	T_AUTOMEMHEAP_FIX	*pFixHeap;
	T_AUTOMEMHEAP_VAL	*pValHeap;
	
	/* 固定長メモリヒープに無いか探索 */
	for ( pFixHeap = self->pFixList; pFixHeap != NULL; pFixHeap = pFixHeap->pNext )
	{
		if ( FixMemHeap_IsMember(&pFixHeap->FixMemHeap, pMem) )
		{
			return &pFixHeap->FixMemHeap.MemHeap;
		}
	}
	
	/* 可変長メモリヒープに無いか探索 */
	for ( pValHeap = self->pValList; pValHeap != NULL; pValHeap = pValHeap->pNext )
	{
		if ( ValMemHeap_IsMember(&pValHeap->ValMemHeap, pMem) )
		{
			return &pValHeap->ValMemHeap.MemHeap;
		}
	}
	
	return NULL;
}


/* end of file */
