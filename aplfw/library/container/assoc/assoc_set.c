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
ASSOC_ERR Assoc_Set(C_ASSOC *self, const char *pszKey, const void *pData, long lSize)
{
	char			*pMem;
	T_ASSOC_NODE	*pNode;
	T_ASSOC_NODE	*pOldNode;
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
		if ( (pOldNode = Assoc_AddNode(self->pRoot, pNode)) != NULL )
		{
			/* 置き換える */
			pNode->pParent = pOldNode->pParent;
			pNode->pLeft   = pOldNode->pLeft;
			pNode->pRight  = pOldNode->pRight;
			if ( pNode->pParent != NULL )
			{
				if ( pNode->pParent->pLeft == pOldNode )
				{
					pNode->pParent->pLeft = pNode;
				}
				else
				{
					pNode->pParent->pRight = pNode;
				}
			}
			else
			{
				self->pRoot    = pNode;
			}
			if ( pNode->pLeft   != NULL ) { pNode->pLeft->pParent  = pNode; }
			if ( pNode->pRight  != NULL ) { pNode->pRight->pParent = pNode; }
			MemHeap_Free(self->pMemHeap, pOldNode);
		}
	}
	
	return ASSOC_ERR_OK;
}


/* end of file */
