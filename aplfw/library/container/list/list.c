/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  listbuf.h
 * @brief %jp{リストバッファクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "list.h"


typedef struct t_list_obj
{
	struct t_list_obj *pPrev;
	struct t_list_obj *pNext;
} T_LIST_OBJ;



/* コンストラクタ */
void List_CreateEx(C_LIST *self, const T_MEMIF *pMemIf)
{
	self->pMemIf = pMemIf;
	self->pHead  = NULL;
}

/* デストラクタ */
void List_Delete(C_LIST *self)
{
}

/* データの末尾追加 */
LIST_ERR List_AddTail(C_LIST *self, const void *pData, long lSize)
{
	T_LIST_OBJ *pHeadObj;
	T_LIST_OBJ *pListObj;
	void       *pMem;
	long       lObjSize;
	
	/* メモリ確保 */
	lObjSize = MemIf_AlignSize(self->pMemIf, sizeof(T_LIST_OBJ));
	pListObj = MemIf_Alloc(self->pMemIf, lObjSize + lSize);
	if ( pListObj == NULL )
	{
		return LIST_ERR_OK;
	}
	pMem = (void *)((char *)pListObj + lObjSize);
	
	/* データコピー */
	memcpy(pMem, pData, lSize);
	
	/* リスト接続 */
	pHeadObj = (T_LIST_OBJ *)self->pHead;
	if ( pHeadObj == NULL )
	{
		self->pHead     = pListObj;
		pListObj->pNext = pListObj;
		pListObj->pPrev = pListObj;
	}
	else
	{
		pListObj->pNext = pHeadObj;
		pListObj->pPrev = pHeadObj->pPrev;
		pListObj->pNext->pPrev = pListObj;
		pListObj->pPrev->pNext = pListObj;
	}
	
	return LIST_ERR_OK;
}


/* データの削除 */
LIST_ERR List_Remove(C_LIST *self, LIST_POS Pos)
{
	T_LIST_OBJ *pListObj;

	pListObj = (T_LIST_OBJ *)Pos;
	
	if ( pListObj->pNext == pListObj )
	{
		self->pHead = NULL;
	}
	else
	{
		pListObj->pNext->pPrev = pListObj->pPrev;
		pListObj->pPrev->pNext = pListObj->pNext;
		if ( self->pHead == pListObj )
		{
			self->pHead = pListObj->pNext;
		}
	}
	MemIf_Free(self->pMemIf, pListObj);

	return LIST_ERR_OK;
}


/* データの参照 */
void *List_GetAt(C_LIST *self, LIST_POS Pos)
{
	T_LIST_OBJ *pListObj;
	long       lObjSize;

	pListObj = (T_LIST_OBJ *)Pos;
	lObjSize = MemIf_AlignSize(self->pMemIf, sizeof(T_LIST_OBJ));

	return (void *)((char *)pListObj + lObjSize);
}


LIST_POS List_GetHeadPos(C_LIST *self)
{
	return self->pHead;
}

LIST_POS List_GetTailPos(C_LIST *self)
{
	T_LIST_OBJ *pHeadObj;

	pHeadObj = (T_LIST_OBJ *)self->pHead;
	if ( pHeadObj == NULL )
	{
		return NULL;
	}

	return pHeadObj->pPrev;
}


LIST_POS List_GetNextPos(C_LIST *self, LIST_POS Pos)
{
	T_LIST_OBJ *pListObj;

	pListObj = (T_LIST_OBJ *)Pos;

	pListObj = pListObj->pNext;
	if ( pListObj == self->pHead )
	{
		return LIST_POS_NULL;
	}

	return (LIST_POS)pListObj;
}


LIST_POS List_GetPrevPos(C_LIST *self, LIST_POS Pos)
{
	T_LIST_OBJ *pListObj;

	pListObj = (T_LIST_OBJ *)Pos;

	if ( pListObj == self->pHead )
	{
		return LIST_POS_NULL;
	}
	pListObj = pListObj->pPrev;

	return (LIST_POS)pListObj;
}

