/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list.h
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__list_h__
#define __HOS__list_h__


#include "library/container/memheap/memheap.h"


#define LIST_ERR_OK			0
#define LIST_ERR_NG			(-1)
#define LIST_POS_NULL		0

typedef int		LIST_ERR;
typedef void*	LIST_POS;


/* ストリームバッファクラス */
typedef struct c_list
{
	C_MEMHEAP	*pMemHeap;		/* 利用するメモリI/F */
	void		*pHead;			/* 先頭要素へのポインタ */
} C_LIST;


#ifdef __cplusplus
extern "C" {
#endif

/* 生成／削除 */
void      List_Create(C_LIST *self);													/* リストの生成 */
void      List_CreateEx(C_LIST *self, C_MEMHEAP *pMemHeap);									/* リストの生成 */
void      List_Delete(C_LIST *self);													/* リストの削除 */

/* 操作 */
LIST_ERR  List_AddTail(C_LIST *self, const void *pData, long lSize);					/* データの末尾追加 */
LIST_ERR  List_Insert(C_LIST *self, LIST_POS Pos, const void *pData, long lSize);		/* データの挿入 */
LIST_ERR  List_Remove(C_LIST *self, LIST_POS Pos);										/* データの削除 */
void     *List_GetAt(C_LIST *self, LIST_POS Pos);										/* データの参照 */

LIST_POS  List_GetHeadPos(C_LIST *self);
LIST_POS  List_GetTailPos(C_LIST *self);
LIST_POS  List_GetNextPos(C_LIST *self, LIST_POS Pos);
LIST_POS  List_GetPrevPos(C_LIST *self, LIST_POS Pos);

#ifdef __cplusplus
}
#endif



#endif	/* __HOS__assocbuf_h__ */

