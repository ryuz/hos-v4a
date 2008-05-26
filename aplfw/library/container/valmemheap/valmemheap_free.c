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



/** %jp{メモリの解放} */
void ValMemHeap_Free(void *pMemHeap, void *pMem)
{
	C_VALMEMHEAP		*self;
	T_VALMEMHEAP_MEMBLK *mblk;
	T_VALMEMHEAP_MEMBLK *mblktmp;
	T_VALMEMHEAP_MEMBLK *mblknext;
	MEMSIZE				MemBlockSize;


	/* upper cast */
	self = (C_VALMEMHEAP *)pMemHeap;
	
	/* %jp{ポインタ範囲チェック} */
	if ( pMem < (void *)self->pMemBase || pMem >= (void *)((char *)self->pMemBase + self->MemSize) )
	{
		return;
	}

	/* %jp{メモリブロックのサイズを調整} */
	MemBlockSize = ValMemHeap_GetMemBlockSize(self);

	/* %jp{メモリブロック位置を取得} */
	mblk = (T_VALMEMHEAP_MEMBLK *)((char *)pMem - MemBlockSize);

	/* %jp{パラメーターチェック} */
	if ( mblk->iFlag != VALMEMHEAP_USING )	/* %jp{使用中で無ければ} */
	{
		return;
	}

	/* %jp{フラグを未使用に設定} */
	mblk->iFlag = VALMEMHEAP_FREE;
	
	/* %jp{次のブロックをチェック} */
	mblktmp = (T_VALMEMHEAP_MEMBLK *)((char *)pMem + mblk->Size);
	if ( mblktmp->iFlag == VALMEMHEAP_FREE )
	{
		/* %jp{次のブロックが未使用なら結合する} */
		mblknext = (T_VALMEMHEAP_MEMBLK *)((char *)mblktmp + mblktmp->Size + MemBlockSize);
		mblknext->pPrev = mblk;
		mblk->Size += mblktmp->Size + MemBlockSize;
	}
	
	/* %jp{前のブロックをチェック} */
	if ( mblk->pPrev != NULL )
	{
		mblktmp = mblk->pPrev;
		if ( mblktmp->iFlag == VALMEMHEAP_FREE )
		{
			/* %jp{前のブロックが未使用なら結合する} */
			mblknext = (T_VALMEMHEAP_MEMBLK *)((char *)mblk + mblk->Size + MemBlockSize);
			mblknext->pPrev = mblktmp;
			mblktmp->Size += mblk->Size + MemBlockSize;
		}
	}
}


/* end of file */
