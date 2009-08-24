/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  automemheap_alloc.c
 * @brief %jp{メモリヒープクラス}%en{auto size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "hosaplfw.h"
#include "automemheap_local.h"



/** 生成 */
C_AUTOMEMHEAP *AutoMemHeap_Create(C_MEMHEAP *pMemHeap)
{
	C_AUTOMEMHEAP	*self;
	
	/* メモリ確保 */
	if ( (self = (C_AUTOMEMHEAP *)MemHeap_Alloc(pMemHeap, sizeof(C_AUTOMEMHEAP))) == NULL )
	{
		return NULL;
	}
	
	/* コンストラクタ呼び出し */
	AutoMemHeap_Constructor(self, pMemHeap);
	
	return (HANDLE)self;
}


/* end of file */
