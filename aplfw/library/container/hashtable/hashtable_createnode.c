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


/* ノードの作成 */
T_HASHTABLE_NODE *HashTable_CreateNode(C_HASHTABLE *self, const char *pszKey, const void *pData, MEMSIZE Size)
{
	T_HASHTABLE_NODE	*pNode;
	MEMSIZE				KeySize;
	char				*pszNodeKey;
	void				*pNodeData;
	
	/* メモリ確保 */
	KeySize  = MemHeap_AlignSize(self->pMemHeap, strlen(pszKey));
	pNode = MemHeap_Alloc(self->pMemHeap, sizeof(T_HASHTABLE_NODE) + KeySize + Size);
	if ( pNode == NULL )
	{
		return NULL;
	}
	
	/* データ格納 */
	pszNodeKey = (char *)pNode + sizeof(T_HASHTABLE_NODE);
	pNodeData  = pszNodeKey + Size;
	strcpy(pszNodeKey, pszKey);
	memcpy(pNodeData, pData, Size);
	pNode->pIterator = NULL;
	
	return pNode;
}


/* end of file */
