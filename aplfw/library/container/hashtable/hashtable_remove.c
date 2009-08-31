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
HASHTABLE_ERR HashTable_Remove(C_HASHTABLE *self, const char *pszKey)
{
	T_HASHTABLE_NODE		*pNode;
	T_HASHTABLE_NODE		*pNodePrev;
	T_HASHTABLE_ITERATOR	*pIterator;
	int						iIndex;
	
	/* 探索 */
	if ( (pNode = HashTable_SearchNode(self, pszKey, &pNodePrev, &iIndex)) == NULL )
	{
		return HASHTABLE_ERR_NG;
	}
	
	/* 指しているイテレータがあれば付け替え */
	if ( (pIterator = pNode->pIterator) != NULL )
	{
		if ( pNode->pNext != NULL )
		{
			pNode->pNext->pIterator = pIterator;
		}
		
		pNode->pIterator = pIterator;
		do
		{
			pIterator->pNode = pNode->pNext;
			pIterator = pIterator->pNext;
		} while ( pIterator != pNode->pIterator );
	}
	
	/* リストからはずす */
	if ( pNodePrev != NULL )
	{
		pNodePrev->pNext = pNode->pNext;
	}
	else
	{
		self->ppTable[iIndex] = pNode->pNext;
	}
	
	/* 削除 */
	HashTable_DeleteNode(self, pNode);
	self->iDataNum--;
	
	return HASHTABLE_ERR_OK;
}



/* end of file */
