/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  hashtable_local.h
 * @brief %jp{ハッシュテーブル}%en{Hash table}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__hashtable_local_h__
#define __HOS__hashtable_local_h__

#include "hashtable.h"


#ifdef __cplusplus
extern "C" {
#endif

T_HASHTABLE_NODE *HashTable_CreateNode(C_HASHTABLE *self, const char *pszKey, const void *pData, MEMSIZE Size);				/* ノードの作成 */
#define           HashTable_DeleteNode(self, pNode)		do { MemHeap_Free((self)->pMemHeap, (pNode)); } while (0)			/* ノードの削除 */
T_HASHTABLE_NODE *HashTable_SearchNode(C_HASHTABLE *self, const char *pszKey, T_HASHTABLE_NODE **ppNodePrev, int *piIndex);	/* ノードの探索 */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__assoc_local_h__ */

