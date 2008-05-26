/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fixmemheap_alloc.c
 * @brief %jp{固定サイズメモリヒープクラス}%en{fixed size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "hosaplfw.h"
#include "fixmemheap_local.h"



/** 生成 */
C_FIXMEMHEAP *FixMemHeap_Create(void *pMemBase, MEMSIZE BlkSize,  MEMSIZE BlkNum)
{
	C_FIXMEMHEAP	*self;
	
	/* メモリ確保 */
	if ( (self = (C_FIXMEMHEAP *)Memory_Alloc(sizeof(C_FIXMEMHEAP))) == NULL )
	{
		return NULL;
	}
	
	/* コンストラクタ呼び出し */
	FixMemHeap_Constructor(self, pMemBase, BlkSize, BlkNum);
	
	return (HANDLE)self;
}


/* end of file */
