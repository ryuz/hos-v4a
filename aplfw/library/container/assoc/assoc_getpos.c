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



/* データの位置取得 */
ASSOC_POS Assoc_GetPos(C_ASSOC *self, const char *pszKey)
{
	T_ASSOC_NODE	*pNode;
	
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
	
	/* 位置を返す */
	return (ASSOC_POS)pNode;
}


/* end of file */
