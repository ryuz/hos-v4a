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



/* 最小値探索 */
T_ASSOC_NODE *Assoc_GetMinNode(T_ASSOC_NODE *pNode)
{
	if ( pNode->pLeft == NULL )
	{
		return pNode;
	}
	
	return Assoc_GetMinNode(pNode->pLeft);
}


/* end of file */
