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



/* 連想バッファのコンストラクタ */
void Assoc_Constructor(C_ASSOC *self, C_MEMHEAP *pMemHeap)
{
	self->pMemHeap = pMemHeap;
	self->pRoot    = NULL;
}



/* end of file */
