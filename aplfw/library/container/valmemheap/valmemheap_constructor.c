/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  valmemheap_alloc.c
 * @brief %jp{可変サイズメモリヒープクラス}%en{variable size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "valmemheap_local.h"



/** %jp{MemHeapクラス 仮想関数テーブル}%en{MemHeap class virtual function table} */
const static T_MEMHEAP_METHODS ValMemHeap_Methods =
	{
		ValMemHeap_Alloc,			/**< メモリの割り当て */
		ValMemHeap_ReAlloc,			/**< メモリの再割り当て */
		ValMemHeap_Free,			/**< メモリの開放 */
		ValMemHeap_GetSize,			/**< メモリのサイズ取得 */
		ValMemHeap_GetAlign,		/**< メモリアライメントの取得 */
		ValMemHeap_AlignSize,		/**< サイズをアライメント単位に拡張 */
		ValMemHeap_IsMember,		/**< メモリがヒープに属しているかチェック */
	};



/** %jp{コンストラクタ} */
void ValMemHeap_Constructor(C_VALMEMHEAP *self, void *pMemBase, MEMSIZE MemSize, int AlignSize)
{
	T_VALMEMHEAP_MEMBLK *pBlkLast;
	MEMSIZE				MemBlockSize;
	
	
	/* %jp{親クラスコンストラクタ} */
	MemHeap_Constructor(&self->MemHeap, &ValMemHeap_Methods);

	/* %jp{サイズのアライメントを調整} */
	MemSize = MemSize & ~(AlignSize - 1);
	
	/* メンバ変数設定 */
	self->pMemBase  = (T_VALMEMHEAP_MEMBLK *)pMemBase;		/**< %jp{メモリ先頭ブロックのアドレス} */
	self->MemSize   = MemSize;								/**< %jp{メモリサイズ} */
	self->AlignMask = AlignSize - 1;						/**< %jp{メモリアライメントサイズ} */

	/* %jp{メモリブロックのサイズを調整} */
	MemBlockSize = ValMemHeap_GetMemBlockSize(self);

	/* %jp{サイズチェック} */
	if ( MemSize <= MemBlockSize * 2 )
	{
		self->pMemBase = NULL;
		return;
	}
	
	/* %jp{終端位置に番人を設定} */
	pBlkLast = (T_VALMEMHEAP_MEMBLK *)((char *)self->pMemBase + MemSize - MemBlockSize);
	
	/* %jp{全体を空き領域に設定} */
	self->pMemBase->pPrev = NULL;
	self->pMemBase->Size = MemSize - (MemBlockSize * 2);
	self->pMemBase->iFlag = VALMEMHEAP_FREE;
	
	/* %jp{終端の番人を利用中に設定} */
	pBlkLast->pPrev = NULL;
	pBlkLast->Size  = 0;
	pBlkLast->iFlag = VALMEMHEAP_USING;
}


/* end of file */
