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


/** %jp{生成}%en{Create} */
C_HASHTABLE *HashTable_CreateEx(int iTableSize, C_MEMHEAP *pMemHeap)
{
	C_HASHTABLE	*self;

	/* メモリ確保 */
	if ( (self = (C_HASHTABLE *)MemHeap_Alloc(pMemHeap, sizeof(C_HASHTABLE))) == NULL )
	{
		return NULL;
	}
	
	/* コンストラクタ */
	HashTable_Constructor(self, iTableSize, pMemHeap);
	
	return self;
}


/* end of file */
