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



/* データの参照 */
const void *Assoc_Get(C_ASSOC *self, const char *pszKey)
{
	T_ASSOC_NODE	*pNode;
	char			*pszNodeKey;
	int				iKeyLen;
	
	if ( self->pRoot == NULL )
	{
		return ASSOC_POS_NULL;
	}
	
	/* 探索 */
	pNode = Assoc_GetNode(self, self->pRoot, pszKey);
	if ( pNode == NULL )
	{
		return ASSOC_POS_NULL;
	}
	
	/* 値取り出し */
	pszNodeKey   = (char *)pNode + sizeof(T_ASSOC_NODE);
	iKeyLen = MemHeap_AlignSize(self->pMemHeap, strlen(pszKey) + 1);
	return (void *)(pszNodeKey + iKeyLen);
}



/* end of file */
