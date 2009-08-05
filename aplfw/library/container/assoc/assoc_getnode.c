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



T_ASSOC_NODE *Assoc_GetNode(C_ASSOC *self, T_ASSOC_NODE *pNode, const char *pszKey)
{
	char	*pszNodeKey;
	int		iCmp;
	
	pszNodeKey   = (char *)pNode + sizeof(T_ASSOC_NODE);
	iCmp = strcmp(pszNodeKey, pszKey);
	if ( iCmp == 0 )
	{
		return pNode;	/* ヒット */
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



/* end of file */
