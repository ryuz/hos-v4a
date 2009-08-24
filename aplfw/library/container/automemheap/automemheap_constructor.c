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
#include "automemheap_local.h"



/** %jp{MemHeapクラス 仮想関数テーブル}%en{MemHeap class virtual function table} */
const static T_MEMHEAP_METHODS AutoMemHeap_Methods =
	{
		AutoMemHeap_Alloc,			/**< メモリの割り当て */
		AutoMemHeap_ReAlloc,		/**< メモリの再割り当て */
		AutoMemHeap_Free,			/**< メモリの開放 */
		AutoMemHeap_GetSize,		/**< メモリのサイズ取得 */
		AutoMemHeap_GetAlign,		/**< メモリアライメントの取得 */
		AutoMemHeap_AlignSize,		/**< サイズをアライメント単位に拡張 */
	};



/** %jp{コンストラクタ} */
void AutoMemHeap_Constructor(C_AUTOMEMHEAP *self, C_MEMHEAP *pMemHeap)
{
	/* %jp{親クラスコンストラクタ} */
	MemHeap_Constructor(&self->MemHeap, &AutoMemHeap_Methods);
	
	/* メンバ変数設定 */
	self->pValList = NULL;
	self->pFixList = NULL;
	self->pMemList = NULL;
	
	self->ValSize = 4096;
	self->FixSize = MemHeap_AlignSize(&self->MemHeap, 16);
	self->FixNum  = 4096 / self->FixSize;
	self->iValMax = 16;
	self->iFixMax = 16;
}


/* end of file */
