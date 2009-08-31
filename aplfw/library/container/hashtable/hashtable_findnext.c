/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  hashtable_findfirst.c
 * @brief %jp{ハッシュテーブルクラス}%en{hash table class}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "hashtable_local.h"


/** %jp{次を取得}%en{find next} */
const void *Hashtable_FindNext(C_HASHTABLE *self, T_HASHTABLE_ITERATOR *pIterator, const char **ppszKey)
{
	T_HASHTABLE_NODE	*pNode;
	int					iIndex;
	const char			*pszKey;
	const void			*pData;
	
	if ( pIterator == NULL )
	{
		return NULL;
	}
	
	/* 次を探索 */
	pNode  = pIterator->pNode;
	iIndex = pIterator->iIndex;
	
	if ( pNode != NULL )
	{
		/* リストから取り外し */
		if ( pIterator->pNext == pIterator )
		{
			pNode->pIterator = NULL;
		}
		else
		{
			pIterator->pNext->pPrev = pIterator->pPrev;
			pIterator->pPrev->pNext = pIterator->pNext;
			if ( pNode->pIterator == pIterator )
			{
				pNode->pIterator = pIterator->pNext;
			}
		}
		
		/* 次があれば進む */
		if ( (pNode = pNode->pNext) == NULL )
		{
			iIndex++;	/* 無ければ次の項 */
		}
	}
	
	if ( pNode == NULL )
	{
		for ( iIndex = pIterator->iIndex; iIndex < self->iTableSize; iIndex++ )
		{
			if ( (pNode = self->ppTable[iIndex]) != NULL )
			{
				break;
			}
		}
	}

	pIterator->pNode  = pNode;
	pIterator->iIndex = iIndex;

	if ( pNode == NULL )
	{
		*ppszKey = NULL;
		return NULL;
	}
	
	/* リスト接続 */
	if ( pNode->pIterator == NULL )
	{
		pNode->pIterator = pIterator;
		pIterator->pNext = pIterator;
		pIterator->pPrev = pIterator;
	}
	else
	{
		pIterator->pNext = pNode->pIterator;
		pIterator->pPrev = pIterator->pNext->pPrev;
		pIterator->pNext->pPrev = pIterator;
		pIterator->pPrev->pNext = pIterator;
	}
	
	/* データ取り出し */
	pszKey = (const char *)pNode + sizeof(T_HASHTABLE_NODE);
	pData  = (const void *)(pszKey + MemHeap_AlignSize(self->pMemHeap, strlen(pszKey)));
	
	/* データ部を返す */
	*ppszKey = pszKey;
	return pData;
}


/* end of file */
