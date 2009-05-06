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



ASSOC_POS Assoc_GetFirst(C_ASSOC *self)
{
	T_ASSOC_NODE *pNode;

	if ( self->pRoot == NULL )
	{
		return ASSOC_POS_NULL;
	}
	
	pNode = self->pRoot;
	while ( pNode->pLeft != NULL )
	{
		pNode = pNode->pLeft;
	}

	return (ASSOC_POS)pNode;
}



/* end of file */
