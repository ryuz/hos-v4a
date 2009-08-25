/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  hashtable.h
 * @brief %jp{ハッシュテーブル}%en{Hash table}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__hashtable_h__
#define __HOS__hashtable_h__


#include "library/container/memheap/memheap.h"


#define HASHTABLE_ERR_OK		0
#define HASHTABLE_ERR_NG		(-1)
#define HASHTABLE_POS_NULL		(0)

typedef int     HASHTABLE_ERR;


struct c_hashtableiterator;
struct c_hashtable;


/** %jp{ノード格納用構造体}%en{node} */
typedef struct t_hashtable_node
{
	int							iIndex;
	struct t_hashtable_node		*pNext;
	struct c_hashtableiterator	*pIterator;
} T_HASHTABLE_NODE;


/** %jp{ハッシュ用イテレータクラス}%en{Iterator class} */
typedef struct c_hashtableiterator
{
	struct c_hashtable			*pHashTable;
	struct c_hashtableiterator	*pNext;
	struct c_hashtableiterator	*pPrev;
	
	struct t_hashtable_node		*pNode;
} C_HASHTABLEITERATOR;


/** %jp{ハッシュテーブルクラス}%en{Hash table class} */
typedef struct c_hashtable
{
	T_HASHTABLE_NODE	**ppTable;
	C_MEMHEAP			*pMemHeap;
	int					iTableNum;
} C_HASHTABLE;


#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
C_HASHTABLE         *HashTable_Create(void);																/* %jp{生成}%en{Create} */
C_HASHTABLE         *HashTable_CreateEx(C_MEMHEAP *pMemHeap);												/* %jp{生成}%en{Create} */
void                HashTable_Delete(C_HASHTABLE *self);													/* %jp{削除}%en{Delete} */
void                HashTable_Constructor(C_HASHTABLE *self, C_MEMHEAP *pMemHeap);							/* %jp{コンストラクタ}%en{Constructor} */
void                HashTable_Destructor(C_HASHTABLE *self);												/* %jp{デストラクタ}%en{Destructor} */

/* 操作 */
HASHTABLE_ERR       HashTable_Add(C_HASHTABLE *self, const char *pszKey, const void *pData, MEMSIZE Size);	/* データの追加 */
HASHTABLE_ERR       HashTable_Set(C_HASHTABLE *self, const char *pszKey, const void *pData, MEMSIZE Size);	/* データの設定 */
const void         *HashTable_Get(C_HASHTABLE *self, const char *pszKey);									/* データの参照 */
HASHTABLE_ERR       HashTable_Remove(C_HASHTABLE *self, const char *pszKey);								/* データの削除 */

/* イテレータ */
C_HASHTABLEITERATOR *HashTableIterator_Create(C_HASHTABLE *pHashTable);										/* イテレータの生成 */
void                HashTableIterator_Delete(C_HASHTABLEITERATOR *self, C_HASHTABLEITERATOR *pIterator);	/* イテレータの削除 */
const void          *HashtableIterator_FindNext(C_HASHTABLEITERATOR *self, const char **ppszKey);			/**/

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__assoc_h__ */


/* end of file */
