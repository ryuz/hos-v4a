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
#include "fixmemheap_local.h"



/** %jp{MemHeapクラス 仮想関数テーブル}%en{MemHeap class virtual function table} */
const static T_MEMHEAP_METHODS FixMemHeap_Methods =
	{
		FixMemHeap_Alloc,			/**< メモリの割り当て */
		FixMemHeap_ReAlloc,			/**< メモリの再割り当て */
		FixMemHeap_Free,			/**< メモリの開放 */
		FixMemHeap_GetSize,			/**< メモリのサイズ取得 */
		FixMemHeap_GetAlign,		/**< メモリアライメントの取得 */
		FixMemHeap_AlignSize,		/**< サイズをアライメント単位に拡張 */
		FixMemHeap_IsMember,		/**< メモリがヒープに属しているかチェック */
	};



/** %jp{コンストラクタ} */
void FixMemHeap_Constructor(C_FIXMEMHEAP *self, void *pMemBase, MEMSIZE BlkSize,  MEMSIZE BlkNum)
{
	void	**ppBlk;
	void	**ppBlkNext;
	MEMSIZE i;

	/* %jp{親クラスコンストラクタ} */
	MemHeap_Constructor(&self->MemHeap, &FixMemHeap_Methods);
	
	/* メンバ変数設定 */
	self->pMemBase  = pMemBase;				/**< %jp{メモリ先頭ブロックのアドレス} */
	self->BlkSize   = BlkSize;				/**< %jp{ブロックサイズ} */
	self->BlkNum    = BlkNum;				/**< %jp{ブロック個数} */
	
	/* メモリ初期化 */
	ppBlk = (void **)self->pMemBase;
	for ( i = 0; i < BlkNum - 1; i++ )
	{
		ppBlkNext = (void **)((char *)ppBlk + BlkSize);
		*ppBlk    = (void *)ppBlkNext;
		ppBlk     = ppBlkNext;
	}
	*ppBlk = NULL;
	
	self->ppFree = (void **)self->pMemBase;
}


/* end of file */
