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


/* ノードの探索 */
T_HASHTABLE_NODE *HashTable_SearchNode(C_HASHTABLE *self, const char *pszKey, T_HASHTABLE_NODE **ppNodePrev, int *piIndex)
{
	T_HASHTABLE_NODE	*pNode;
	T_HASHTABLE_NODE	*pNodePrev;
	const char			*pszNodeKey;
	const char			*pszPtr;
	int					iIndex;
	int					c;
	
	/* ハッシュ計算 */
	iIndex = 0; 
	for ( pszPtr = pszKey; (c = *pszPtr) != '\0'; pszPtr++ )
	{
		iIndex += c;
	}
	*piIndex = iIndex = iIndex % self->iTableSize;
	
	
	/* 探索 */
	pNodePrev = NULL;
	for ( pNode = self->ppTable[iIndex]; pNode != NULL; pNode = pNode->pNext )
	{
		pszNodeKey = (const char *)pNode + sizeof(T_HASHTABLE_NODE);
		if ( strcmp(pszNodeKey, pszKey) == 0 )
		{
			*ppNodePrev = pNodePrev;
			return pNode;
		}
		pNodePrev = pNode;
	}
	
	*ppNodePrev = NULL;
	
	return NULL;
}

/* end of file */
