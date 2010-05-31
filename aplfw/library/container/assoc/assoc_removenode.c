/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  assoc_removenode.c
 * @brief %jp{連想配列クラス}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdio.h>
#include <string.h>
#include "hosaplfw.h"
#include "assoc_local.h"



/* 親ノードの接続書き換え */
static void Assoc_SetParentLink(C_ASSOC *self, T_ASSOC_NODE *pNode, T_ASSOC_NODE *pNewNode)
{
	if ( pNode->pParent == NULL )
	{
		self->pRoot = pNewNode;
	}
	else
	{
		if ( pNode->pParent->pLeft == pNode )
		{
			pNode->pParent->pLeft  = pNewNode;
		}
		else
		{
			pNode->pParent->pRight = pNewNode;
		}
		if ( pNewNode != NULL )
		{
			pNewNode->pParent = pNode->pParent;
		}
	}
}

/* ノード削除 */
void Assoc_RemoveNode(C_ASSOC *self, T_ASSOC_NODE *pNode)
{
	T_ASSOC_NODE *pReplaceNode;
	
	
	if ( pNode->pLeft != NULL && pNode->pRight != NULL )	/* 両方あり */
	{
		/* 両方あり */
		pReplaceNode = Assoc_GetMinNode(pNode->pRight);
		Assoc_SetParentLink(self, pReplaceNode, NULL);
		pReplaceNode->pParent = pNode->pParent;
		pReplaceNode->pLeft   = pNode->pLeft;
		pReplaceNode->pRight  = pNode->pRight;
		Assoc_SetParentLink(self, pReplaceNode, pReplaceNode);
		if ( pReplaceNode->pLeft  != NULL ) { pReplaceNode->pLeft->pParent  = pReplaceNode; }
		if ( pReplaceNode->pRight != NULL ) { pReplaceNode->pRight->pParent = pReplaceNode; }
	}
	else if ( pNode->pLeft != NULL )
	{
		/* 左のみ */
		Assoc_SetParentLink(self, pNode, pNode->pLeft);
	}
	else if ( pNode->pRight != NULL )
	{
		/* 右のみ */
		Assoc_SetParentLink(self, pNode, pNode->pRight);
	}
	else
	{
		/* 子無し */
		Assoc_SetParentLink(self, pNode, NULL);
	}
	
	/* メモリ開放 */
	MemHeap_Free(self->pMemHeap, pNode);
}


/* end of file */
