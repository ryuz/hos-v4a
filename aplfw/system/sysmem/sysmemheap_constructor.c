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



/** %jp{MemHeapクラス 仮想関数テーブル}%en{MemHeap class virtual function table} */
const static T_MEMHEAP_METHODS SysMemHeap_Methods =
	{
		SysMemHeap_Alloc,			/**< メモリの割り当て */
		SysMemHeap_ReAlloc,			/**< メモリの再割り当て */
		SysMemHeap_Free,			/**< メモリの開放 */
		SysMemHeap_GetSize,			/**< メモリのサイズ取得 */
		SysMemHeap_GetAlign,		/**< メモリアライメントの取得 */
		SysMemHeap_AlignSize,		/**< サイズをアライメント単位に拡張 */
	};



/** %jp{コンストラクタ} */
void SysMemHeap_Constructor(C_SYSMEMHEAP *self, C_MEMHEAP *pMemHeap)
{
	self->hMtx     = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	self->pMemHeap = pMemHeap;
	
	/* %jp{親クラスコンストラクタ} */
	MemHeap_Constructor(&self->MemHeap, &SysMemHeap_Methods);
}


/* end of file */
