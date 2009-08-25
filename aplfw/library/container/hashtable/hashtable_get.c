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


/* データの参照 */
const void *HashTable_Get(C_HASHTABLE *self, const char *pszKey)
{
	T_HASHTABLE_NODE	*pNode;
	T_HASHTABLE_NODE	*pNodePrev;
	int					iIndex;
	
	/* 探索 */
	if ( (pNode = HashTable_SearchNode(self, pszKey, &pNodePrev, &iIndex)) == NULL )
	{
		return NULL;
	}
	
	/* データ部を返す */
	return (const void *)((char *)pNode + sizeof(T_HASHTABLE_NODE) + MemHeap_AlignSize(self->pMemHeap, strlen(pszKey)));
}


/* end of file */
