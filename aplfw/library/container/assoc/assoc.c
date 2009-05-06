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


C_ASSOC *Assoc_Create(void)
{
	return NULL;
}


C_ASSOC *Assoc_CreateEx(C_MEMHEAP *pMemHeap)
{
	return NULL;
}


/* 連想バッファのコンストラクタ */
void Assoc_Constructor(C_ASSOC *self, C_MEMHEAP *pMemHeap)
{
	self->pMemHeap = pMemHeap;
	self->pRoot    = NULL;
}


/* 連想バッファのデストラクタ */
void Assoc_Delete(C_ASSOC *self)
{
}



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



static void *Assoc_GetNode(C_ASSOC *self, T_ASSOC_NODE *pNode, const char *pszKey)
{
	char	*pszNodeKey;
	int		iCmp;
	int		iKeyLen;
	
	pszNodeKey   = (char *)pNode + sizeof(T_ASSOC_NODE);
	iCmp = strcmp(pszNodeKey, pszKey);
	if ( iCmp == 0 )
	{
		iKeyLen = MemHeap_AlignSize(self->pMemHeap, strlen(pszKey) + 1);
		return (void *)(pszNodeKey + iKeyLen);	/* ヒット */
	}
	
	if ( iCmp > 0 )
	{
		if ( pNode->pLeft == NULL )
		{
			return NULL;
		}
		return Assoc_GetNode(self, pNode->pLeft, pszKey);
	}
	else
	{
		if ( pNode->pRight == NULL )
		{
			return NULL;
		}
		return Assoc_GetNode(self, pNode->pRight, pszKey);
	}
}


/* データの参照 */
const void *Assoc_Get(C_ASSOC *self, const char *pszKey)
{
	ASSOC_POS	Pos;
	char		*pDataKey;
	
	if ( self->pRoot == NULL )
	{
		return ASSOC_POS_NULL;
	}
	
	return Assoc_GetNode(self, self->pRoot, pszKey);
}



ASSOC_POS Assoc_GetFirst(C_ASSOC *self)
{
	T_ASSOC_NODE *pNode;

	if ( self->pRoot == NULL )
	{
		return ASSOC_POS_NULL;
	}
	
	pNode = self->pRoot;
	while ( pNode->pLeft != NULL )
	{
		pNode = pNode->pLeft;
	}

	return (ASSOC_POS)pNode;
}


ASSOC_POS Assoc_GetNext(C_ASSOC *self, ASSOC_POS *Pos)
{
	T_ASSOC_NODE *pNode;
	
	pNode = (T_ASSOC_NODE *)Pos;
	
	/* 右に枝が残っているなら探す */
	if ( pNode->pRight != NULL )
	{
		pNode = pNode->pRight;
		while ( pNode->pLeft != NULL )
		{
			pNode = pNode->pLeft;
		}
		return (ASSOC_POS)pNode;
	}
	
	/* 終了 */
	if ( pNode->pParent == NULL )
	{
		return ASSOC_POS_NULL;
	}

	/* 左の葉の場合 */
	if ( pNode->pParent->pLeft == pNode )
	{
		return (ASSOC_POS)pNode->pParent;
	}
	
	/* 右の葉の場合 */
	do
	{
		pNode = pNode->pParent;
		if ( pNode->pParent == NULL )
		{
			return ASSOC_POS_NULL;
		}
	} while ( pNode->pParent->pRight == pNode );
	pNode = pNode->pParent;
	
	return (ASSOC_POS)pNode;
}


const void *Assoc_GetAt(C_ASSOC *self, ASSOC_POS *Pos, const char **ppszKey)
{
	T_ASSOC_NODE *pNode;
	char	*pszNodeKey;
	int		iCmp;
	int		iKeyLen;

	pNode = (T_ASSOC_NODE *)Pos;
	
	pszNodeKey = (char *)pNode + sizeof(T_ASSOC_NODE);
	*ppszKey   = pszNodeKey;
	iKeyLen    = MemHeap_AlignSize(self->pMemHeap, strlen(pszNodeKey) + 1);
	
	return (void *)(pszNodeKey + iKeyLen);
}


/* end of file */
