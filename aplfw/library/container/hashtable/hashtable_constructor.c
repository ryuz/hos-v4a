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



/**< %jp{コンストラクタ}%en{Constructor} */
HASHTABLE_ERR HashTable_Constructor(C_HASHTABLE *self, int iTableSize, C_MEMHEAP *pMemHeap)
{
	T_HASHTABLE_NODE	**ppTable;
	int					i;

	/* メモリ確保 */
	if ( (ppTable = (T_HASHTABLE_NODE **)MemHeap_Alloc(pMemHeap, sizeof(T_HASHTABLE_NODE *) * iTableSize)) == NULL )
	{
		return HASHTABLE_ERR_NG;
	}

	/* 初期化 */
	for ( i = 0; i < iTableSize; i++ )
	{
		ppTable[i] = NULL;
	}

	/* 値設定 */
	self->pMemHeap   = pMemHeap;
	self->ppTable    = ppTable;
	self->iTableSize = iTableSize;
	self->iDataNum   = 0;
	
	return HASHTABLE_ERR_OK;
}


/* end of file */
