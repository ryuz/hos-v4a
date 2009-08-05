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



/* ノード追加 */
T_ASSOC_NODE *Assoc_AddNode(T_ASSOC_NODE *pParent, T_ASSOC_NODE *pNode)
{
	char	*pszParentKey;
	char	*pszNodeKey;
	int		iCmp;

	pszParentKey = (char *)pParent + sizeof(T_ASSOC_NODE);
	pszNodeKey   = (char *)pNode   + sizeof(T_ASSOC_NODE);
	iCmp = strcmp(pszParentKey, pszNodeKey);
	if ( iCmp == 0 )
	{
		return pParent;	/* 既に存在する */
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
	
	return NULL;	/* 追加成功 */
}


/* end of file */
