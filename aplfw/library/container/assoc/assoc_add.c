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
#include "assoc.h"



/* ノード追加 */
static ASSOC_ERR Assoc_AddNode(T_ASSOC_NODE *pParent, T_ASSOC_NODE *pNode)
{
	char	*pszParentKey;
	char	*pszNodeKey;
	int		iCmp;

	pszParentKey = (char *)pParent + sizeof(T_ASSOC_NODE);
	pszNodeKey   = (char *)pNode   + sizeof(T_ASSOC_NODE);
	iCmp = strcmp(pszParentKey, pszNodeKey);
	if ( iCmp == 0 )
	{
		return ASSOC_ERR_NG;	/* 既に存在する */
	}
	
	if ( iCmp > 0 )
	{
		if ( pParent->pLeft != NULL )
		{
			return Assoc_AddNode(pParent->pLeft, pNode);
		}
		pParent->pLeft = pNode;
		pNode->pParent = pParent;
	}
	else
	{
		if ( pParent->pRight != NULL )
		{
			return Assoc_AddNode(pParent->pRight, pNode);
		}
		pParent->pRight = pNode;
		pNode->pParent = pParent;
	}
	
	return ASSOC_ERR_OK;
}


/* データの登録 */
ASSOC_ERR Assoc_Add(C_ASSOC *self, const char *pszKey, const void *pData, long lSize)
{
	char			*pMem;
	T_ASSOC_NODE	*pNode;
	int				iKeyLen;
	ASSOC_ERR		ErrCode;
	
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
	pNode->pLeft   = NULL;
	pNode->pRight  = NULL;
	if ( self->pRoot == NULL )
	{
		pNode->pParent = NULL;
		self->pRoot    = pNode;
		ErrCode = ASSOC_ERR_OK;
	}
	else
	{
		ErrCode = Assoc_AddNode(self->pRoot, pNode);
		if ( ErrCode != ASSOC_ERR_OK )
		{
			MemHeap_Free(self->pMemHeap, pNode);
		}
	}
	
	return ErrCode;
}


/* end of file */
