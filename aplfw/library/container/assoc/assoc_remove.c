/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  assoc_remove.c
 * @brief %jp{連想配列クラス データの削除}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "hosaplfw.h"
#include "assoc_local.h"



/** データの削除 */
ASSOC_ERR Assoc_Remove(C_ASSOC *self, const char *pszKey)
{
	T_ASSOC_NODE *pNode;
	
	if ( self->pRoot == NULL )
	{
		return ASSOC_ERR_NG;
	}
	
	/* ノード取得 */
	pNode = Assoc_GetNode(self, self->pRoot, pszKey);
	if ( pNode == NULL )
	{
		return ASSOC_ERR_NG;
	}
	
	/* ノード削除 */
	Assoc_RemoveNode(self, pNode);
	
	return 	ASSOC_ERR_OK;	
}


/* end of file */
