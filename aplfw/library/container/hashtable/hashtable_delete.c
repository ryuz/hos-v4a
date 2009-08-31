/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  hashtable_get.c
 * @brief %jp{ハッシュテーブルクラス}%en{hash table class}
 *
 * Copyright (C) 2006-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "hashtable_local.h"


/** %jp{削除}%en{Delete} */
void HashTable_Delete(C_HASHTABLE *self)
{
	C_MEMHEAP	*pMemHeap;
	
	pMemHeap = self->pMemHeap;

	/* デストラクタ */
	HashTable_Destructor(self);
	
	/* メモリ開放 */
	MemHeap_Free(pMemHeap, self);
}


/* end of file */
