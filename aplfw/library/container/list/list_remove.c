/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  list_remove.c
 * @brief %jp{リストクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "list_local.h"


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
	MemHeap_Free(self->pMemHeap, pListObj);

	return LIST_ERR_OK;
}


/* end of file */
