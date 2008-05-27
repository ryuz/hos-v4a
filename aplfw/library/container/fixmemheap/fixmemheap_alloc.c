/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fixmemheap_alloc.c
 * @brief %jp{固定サイズメモリヒープクラス}%en{fixed size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "fixmemheap_local.h"



/** %jp{メモリの割り当て} */
void *FixMemHeap_Alloc(void *pMemHeap, MEMSIZE Size)
{
	C_FIXMEMHEAP	*self;
	void			*pMem;
	
	/* upper cast */
	self = (C_FIXMEMHEAP *)pMemHeap;
	
	/* %jp{ヒープの存在チェック} */
	if ( self->pMemBase == NULL )
	{
		return NULL;
	}
	
	/* サイズチェック */	
	if ( Size > self->BlkSize )
	{
		return NULL;
	}
	
	/* %jp{空きチェック} */
	if ( self->ppFree == NULL )
	{
		return NULL;		
	}
	
	/* リスト繋ぎ変え */
	pMem = self->ppFree;
	self->ppFree = *self->ppFree;
	
	return pMem;
}

/* end of file */
