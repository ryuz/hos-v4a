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



/* end of file */
