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



const void *Assoc_GetAt(C_ASSOC *self, ASSOC_POS *Pos, const char **ppszKey)
{
	T_ASSOC_NODE *pNode;
	char	*pszNodeKey;
	int		iKeyLen;

	pNode = (T_ASSOC_NODE *)Pos;
	
	pszNodeKey = (char *)pNode + sizeof(T_ASSOC_NODE);
	*ppszKey   = pszNodeKey;
	iKeyLen    = MemHeap_AlignSize(self->pMemHeap, strlen(pszNodeKey) + 1);
	
	return (void *)(pszNodeKey + iKeyLen);
}



/* end of file */
