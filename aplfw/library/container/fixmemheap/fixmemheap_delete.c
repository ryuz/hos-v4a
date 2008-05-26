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



/** 削除 */
void FixMemHeap_Delete(C_FIXMEMHEAP *self)
{
	/* デストラクタ呼び出し */
	FixMemHeap_Destructor(self);
	
	/* メモリ削除 */
	Memory_Free(self);
}


/* end of file */
