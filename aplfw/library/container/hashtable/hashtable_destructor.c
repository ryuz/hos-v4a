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



/**< %jp{デストラクタ}%en{Destructor} */
void HashTable_Destructor(C_HASHTABLE *self)
{
	/* 全削除 */
	HashTable_RemoveAll(self);
	
	/* メモリ開放 */
	MemHeap_Free(self->pMemHeap, self->ppTable);
}


/* end of file */
