/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  assoc.c
 * @brief %jp{連想配列クラス}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include <string.h>
#include "hosaplfw.h"
#include "assoc_local.h"



/* データの登録 */
ASSOC_ERR Assoc_Add(C_ASSOC *self, const char *pszKey, const void *pData, long lSize)
{
	char			*pMem;
	T_ASSOC_NODE	*pNode;
	int				iKeyLen;
	
	/* ノード生成 */
	iKeyLen = MemHeap_AlignSize(self->pMemHeap, strlen(pszKey) + 1);
	if ( (pMem = MemHeap_Alloc(self->pMemHeap, sizeof(T_ASSOC_NODE) + iKeyLen + lSize)) == NULL )
	{
		return ASSOC_ERR_NG;
	}
	pNode = (T_ASSOC_NODE *)pMem;
	pMem += sizeof(T_ASSOC_NODE);
	strcpy(pMem, pszKey);
	pMem += iKeyLen;
	memcpy(pMem, pData, lSize);
	
	/* 追加 */
	pNode->pLeft  = NULL;
	pNode->pRight = NULL;
	if ( self->pRoot == NULL )
	{
		/* 最初の１個 */
		pNode->pParent = NULL;
		self->pRoot    = pNode;
	}
	else
	{
		if ( Assoc_AddNode(self->pRoot, pNode) != NULL )
		{
			MemHeap_Free(self->pMemHeap, pNode);
			return ASSOC_ERR_NG;
		}
	}
	
	return ASSOC_ERR_OK;
}


/* end of file */
