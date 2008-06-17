/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  sysmemheap_alloc.c
 * @brief %jp{システムメモリヒープクラス}%en{system memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "sysmemheap_local.h"



/** %jp{デストラクタ} */
void SysMemHeap_Destructor(C_SYSMEMHEAP *self)
{
	SysMtx_Delete(self->hMtx);
	
	/* %jp{親クラスデストラクタ} */
	MemHeap_Destructor(&self->MemHeap);
}


/* end of file */
