/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  assoc.c
 * @brief %jp{連想配列クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include <string.h>
#include "assoc.h"


/* 連想バッファの生成 */
void Assoc_Create(C_ASSOC *self)
{
}

/* 連想バッファの生成 */
void Assoc_CreateEx(C_ASSOC *self, C_MEMHEAP *pMemHeap)
{
	self->pMemHeap = pMemHeap;
	List_CreateEx(&self->List, pMemHeap);
}

/* 連想バッファの削除 */
void Assoc_Delete(C_ASSOC *self)
{
}


/* データの登録 */
ASSOC_ERR Assoc_Add(C_ASSOC *self, const char *pszKey, const void *pData, long lSize)
{
	ASSOC_ERR err;
	int  iKeyLen;
	void *pMem;
	
	iKeyLen = MemHeap_AlignSize(self->pMemHeap, strlen(pszKey) + 1);
	if ( (pMem = MemHeap_Alloc(self->pMemHeap, iKeyLen + lSize)) == NULL )
	{
		return ASSOC_ERR_NG;
	}
	
	strcpy((char *)pMem, pszKey);
	memcpy((char *)pMem + iKeyLen, pData, lSize);
	err = List_AddTail(&self->List, pMem, iKeyLen + lSize);
	
	MemHeap_Free(self->pMemHeap, pMem);

	return err;
}


/* データの参照 */
const void *Assoc_Get(C_ASSOC *self, const char *pszKey)
{
	LIST_POS Pos;
	char *pDataKey;

	Pos = List_GetHeadPos(&self->List);
	while ( Pos != LIST_POS_NULL )
	{
		pDataKey = List_GetAt(&self->List, Pos);
		if ( strcmp(pDataKey, pszKey) == 0 )
		{
			return (void *)(pDataKey + MemHeap_AlignSize(self->pMemHeap, strlen(pszKey) + 1));
		}
		Pos = List_GetNextPos(&self->List, Pos);
	}
	
	return NULL;
}


ASSOC_POS Assoc_GetFirst(C_ASSOC *self)
{
	return (ASSOC_POS)List_GetHeadPos(&self->List);
}


ASSOC_POS Assoc_GetNext(C_ASSOC *self, ASSOC_POS *Pos)
{
	return (ASSOC_POS)List_GetNextPos(&self->List, (LIST_POS)Pos);
}


const void *Assoc_GetAt(C_ASSOC *self, ASSOC_POS *Pos, const char **ppszKey)
{
	char *pDataKey;

	pDataKey = List_GetAt(&self->List, Pos);
	*ppszKey = pDataKey;
	
	return (void *)(pDataKey + MemHeap_AlignSize(self->pMemHeap, strlen(pDataKey) + 1));
}

