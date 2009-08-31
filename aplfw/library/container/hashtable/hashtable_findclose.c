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


/** イテレータの削除 */
void HashTable_FindClose(C_HASHTABLE *self, T_HASHTABLE_ITERATOR *pIterator)
{
	if ( pIterator->pNode != NULL )
	{
		if ( pIterator->pNext == pIterator )
		{
			pIterator->pNode->pIterator = NULL;
		}
		else
		{
			pIterator->pNext->pPrev = pIterator->pPrev;
			pIterator->pPrev->pNext = pIterator->pNext;
			if ( pIterator->pNode->pIterator == pIterator )
			{
				pIterator->pNode->pIterator = pIterator->pNext;
			}
		}
	}
	
	/* メモリ開放 */
	MemHeap_Free(self->pMemHeap, pIterator);
}


/* end of file */
