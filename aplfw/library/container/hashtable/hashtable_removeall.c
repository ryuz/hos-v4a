/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  hashtable_get.c
 * @brief %jp{ハッシュテーブルクラス}%en{hash table class}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "hashtable_local.h"



/** データの削除 */
void HashTable_RemoveAll(C_HASHTABLE *self)
{
	T_HASHTABLE_NODE		*pNode;
	T_HASHTABLE_NODE		*pNodeNext;
	T_HASHTABLE_ITERATOR	*pIterator;
	int						iIndex;
	
	for ( iIndex = 0; iIndex < self->iTableSize; iIndex++ )
	{
		if ( (pNode = self->ppTable[iIndex]) != NULL )
		{
			do
			{
				/* 指しているイテレータがあれば外す */
				if ( (pIterator = pNode->pIterator) != NULL )
				{
					do
					{
						pIterator->iIndex = self->iTableSize;
						pIterator->pNode  = NULL;
						pIterator = pIterator->pNext;
					} while ( pIterator != pNode->pIterator );
				}

				/* ノード削除 */
				pNodeNext = pNode->pNext;
				HashTable_DeleteNode(self, pNode);
				self->iDataNum--;

				pNode = pNodeNext;
			} while ( pNode != NULL );			
			
			self->ppTable[iIndex] = NULL;
		}
	}
}



/* end of file */
