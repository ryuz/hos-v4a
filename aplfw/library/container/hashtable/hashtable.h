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


struct t_hashtable_iterator;
struct c_hashtable;


/** %jp{ノード格納用構造体}%en{node} */
typedef struct t_hashtable_node
{
	struct t_hashtable_node		*pNext;
	struct t_hashtable_iterator	*pIterator;
} T_HASHTABLE_NODE;


/** %jp{ハッシュ用イテレータ}%en{Iterator} */
typedef struct t_hashtable_iterator
{
	struct t_hashtable_node		*pNode;
	int							iIndex;
	
	struct t_hashtable_iterator	*pNext;
	struct t_hashtable_iterator	*pPrev;
} T_HASHTABLE_ITERATOR;



/** %jp{ハッシュテーブルクラス}%en{Hash table class} */
typedef struct c_hashtable
{
	T_HASHTABLE_NODE	**ppTable;
	C_MEMHEAP			*pMemHeap;
	int					iTableSize;
	int					iDataNum;
} C_HASHTABLE;


#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
C_HASHTABLE          *HashTable_Create(int iTableSize);																	/**< %jp{生成}%en{Create} */
C_HASHTABLE          *HashTable_CreateEx(int iTableSize, C_MEMHEAP *pMemHeap);											/**< %jp{生成}%en{Create} */
void                  HashTable_Delete(C_HASHTABLE *self);																/**< %jp{削除}%en{Delete} */
HASHTABLE_ERR         HashTable_Constructor(C_HASHTABLE *self, int iTableSize, C_MEMHEAP *pMemHeap);					/**< %jp{コンストラクタ}%en{Constructor} */
void                  HashTable_Destructor(C_HASHTABLE *self);															/**< %jp{デストラクタ}%en{Destructor} */

/* 操作 */
HASHTABLE_ERR         HashTable_Add(C_HASHTABLE *self, const char *pszKey, const void *pData, MEMSIZE Size);			/**< データの追加 */
HASHTABLE_ERR         HashTable_Set(C_HASHTABLE *self, const char *pszKey, const void *pData, MEMSIZE Size);			/**< データの設定 */
const void           *HashTable_Get(C_HASHTABLE *self, const char *pszKey);												/**< データの参照 */
HASHTABLE_ERR         HashTable_Remove(C_HASHTABLE *self, const char *pszKey);											/**< データの削除 */
void                  HashTable_RemoveAll(C_HASHTABLE *self);															/**< データの全削除 */

/* イテレータ */
T_HASHTABLE_ITERATOR *HashTable_FindOpen(C_HASHTABLE *self);															/**< イテレータの生成 */
void                 HashTable_FindClose(C_HASHTABLE *self, T_HASHTABLE_ITERATOR *pIterator);							/**< イテレータの削除 */
const void           *Hashtable_FindNext(C_HASHTABLE *self, T_HASHTABLE_ITERATOR *pIterator, const char **ppszKey);		/**< 次を取得 */

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__hashtable_h__ */


/* end of file */
