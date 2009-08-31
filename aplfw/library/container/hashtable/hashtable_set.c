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


/* データの設定 */
HASHTABLE_ERR HashTable_Set(C_HASHTABLE *self, const char *pszKey, const void *pData, MEMSIZE Size)
{
	T_HASHTABLE_NODE		*pNode;
	T_HASHTABLE_NODE		*pNodeOld;
	T_HASHTABLE_NODE		*pNodePrev;
	T_HASHTABLE_ITERATOR	*pIterator;
	int						iIndex;
	
	/* ノード生成 */
	if ( (pNode = HashTable_CreateNode(self, pszKey, pData, Size)) == NULL )
	{
		return HASHTABLE_ERR_NG;
	}

	/* 既に無いか探索 */
	pNodeOld = HashTable_SearchNode(self, pszKey, &pNodePrev, &iIndex);
	
	/* 既にあれば更新 */
	if ( pNodeOld != NULL )
	{
		/* 指しているイテレータがあれば付け替え */
		if ( (pIterator = pNodeOld->pIterator) != NULL )
		{
			pNode->pIterator = pIterator;
			do
			{
				pIterator->pNode = pNode;
				pIterator = pIterator->pNext;
			} while ( pIterator != pNodeOld->pIterator );
		}
		
		/* リストから取り外し */
		if ( pNodePrev != NULL )
		{
			pNodePrev->pNext = pNodeOld->pNext;
		}
		{
			self->ppTable[iIndex] = pNodeOld->pNext;
		}

		/* 削除 */
		HashTable_DeleteNode(self, pNodeOld);
	}
	else
	{
		self->iDataNum++;
	}
	
	/* 新ノード設定 */
	pNode->pNext          = self->ppTable[iIndex];
	self->ppTable[iIndex] = pNode;
	
	return HASHTABLE_ERR_OK;
}


/* end of file */
