/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  automemheap_delete.c
 * @brief %jp{メモリヒープクラス}%en{auto size memory heap class}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "hosaplfw.h"
#include "automemheap_local.h"



/** 削除 */
void AutoMemHeap_Delete(C_AUTOMEMHEAP *self)
{
	/* デストラクタ呼び出し */
	AutoMemHeap_Destructor(self);
	
	/* メモリ削除 */
	Memory_Free(self);
}


/* end of file */
