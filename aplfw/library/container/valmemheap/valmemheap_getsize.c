/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  valmemheap_free.c
 * @brief %jp{可変サイズメモリヒープクラス}%en{variable size memory heap class}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "valmemheap_local.h"



/** メモリのサイズ取得 */
MEMSIZE	ValMemHeap_GetSize(void *pMemHeap, void *pMem)
{
	C_VALMEMHEAP		*self;
	T_VALMEMHEAP_MEMBLK *mblk;
	MEMSIZE				MemBlockSize;
	
	/* upper cast */
	self = (C_VALMEMHEAP *)pMemHeap;

	/* %jp{メモリブロックのサイズを調整} */
	MemBlockSize = ValMemHeap_GetMemBlockSize(self);

	/* %jp{ポインタ範囲チェック} */
	if ( pMem < (void *)self->pMemBase || pMem >= (void *)((char *)self->pMemBase + self->MemSize) )
	{
		return 0;	/* %jp{このメモリプールの所属でない} */
	}
	
	/* %jp{メモリブロック位置を取得} */
	mblk = (T_VALMEMHEAP_MEMBLK *)((char *)pMem - MemBlockSize);
	
	/* %jp{パラメーターチェック} */
	if ( mblk->iFlag != VALMEMHEAP_USING )	/* %jp{使用中で無ければ} */
	{
		return 0;	/* %jp{割り当ていない} */
	}
	
	/* %jp{サイズを返す} */
	return mblk->Size;
}


/* end of file */
