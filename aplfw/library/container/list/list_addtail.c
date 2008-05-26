/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  listbuf.h
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "list_local.h"


/* データの末尾追加 */
LIST_ERR List_AddTail(C_LIST *self, const void *pData, long lSize)
{
	T_LIST_OBJ *pHeadObj;
	T_LIST_OBJ *pListObj;
	void       *pMem;
	long       lObjSize;
	
	/* メモリ確保 */
	lObjSize = MemHeap_AlignSize(self->pMemHeap, sizeof(T_LIST_OBJ));
	pListObj = MemHeap_Alloc(self->pMemHeap, lObjSize + lSize);
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

