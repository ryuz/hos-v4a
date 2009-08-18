/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  assoc.h
 * @brief %jp{連想配列クラス}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__assoc_h__
#define __HOS__assoc_h__


#include "library/container/memheap/memheap.h"


#define ASSOC_ERR_OK		0
#define ASSOC_ERR_NG		(-1)
#define ASSOC_POS_NULL		(0)

typedef void*	ASSOC_POS;
typedef int     ASSOC_ERR;


/** ノード格納用構造体 */
typedef struct t_assoc_node
{
	struct t_assoc_node	*pLeft;
	struct t_assoc_node	*pRight;
	struct t_assoc_node	*pParent;
} T_ASSOC_NODE;


/** 連想配列クラス */
typedef struct c_assoc
{
	T_ASSOC_NODE	*pRoot;
	C_MEMHEAP		*pMemHeap;
} C_ASSOC;



#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
C_ASSOC	   *Assoc_Create(void);																/* 連想バッファの生成 */
C_ASSOC	   *Assoc_CreateEx(C_MEMHEAP *pMemHeap);											/* 連想バッファの生成 */
void        Assoc_Delete(C_ASSOC *self);													/* 連想バッファの削除 */
void        Assoc_Constructor(C_ASSOC *self, C_MEMHEAP *pMemHeap);							/* 連想バッファのコンストラクタ */
void        Assoc_Destructor(C_ASSOC *self);												/* 連想バッファのデストラクタ */

/* 操作 */
ASSOC_ERR   Assoc_Add(C_ASSOC *self, const char *pszKey, const void *pData, long lSize);	/* データの追加 */
ASSOC_ERR   Assoc_Set(C_ASSOC *self, const char *pszKey, const void *pData, long lSize);	/* データの設定 */
const void *Assoc_Get(C_ASSOC *self, const char *pszKey);									/* データの参照 */
ASSOC_ERR   Assoc_Remove(C_ASSOC *self, const char *pszKey);								/* データの削除 */

/* イテレータ操作 */
ASSOC_POS   Assoc_GetFirst(C_ASSOC *self);
ASSOC_POS   Assoc_GetPos(C_ASSOC *self, const char *pszKey);
ASSOC_POS   Assoc_GetNext(C_ASSOC *self, ASSOC_POS *Pos);
const void *Assoc_GetAt(C_ASSOC *self, ASSOC_POS *Pos, const char **ppszKey);

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__assoc_h__ */


/* end of file */
