/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  hashtable_findopen.c
 * @brief %jp{ハッシュテーブルクラス}%en{hash table class}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "hashtable_local.h"


/** %jp{イテレータの生成}%en{create iterator} */
T_HASHTABLE_ITERATOR *HashTable_FindOpen(C_HASHTABLE *self)
{
	T_HASHTABLE_ITERATOR	*pIterator;
	
	/* 生成 */
	if ( (pIterator = MemHeap_Alloc(self->pMemHeap, sizeof(T_HASHTABLE_ITERATOR))) == NULL )
	{
		return NULL;
	}
	
	/* 初期化 */
	pIterator->pNode  = NULL;
	pIterator->iIndex = 0;

	return pIterator;
}


/* end of file */
