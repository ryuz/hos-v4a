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



/** %jp{メモリの割り当て} */
void *ValMemHeap_Alloc(void *pMemHeap, MEMSIZE Size)
{
	C_VALMEMHEAP		*self;
	T_VALMEMHEAP_MEMBLK	*mblk;
	T_VALMEMHEAP_MEMBLK	*mblk_next;
	T_VALMEMHEAP_MEMBLK	*mblk_next2;
	MEMSIZE				MemBlockSize;
	
	
	/* upper cast */
	self = (C_VALMEMHEAP *)pMemHeap;
	
	/* %jp{ヒープの存在チェック} */
	if ( self->pMemBase == NULL )
	{
		return NULL;
	}
	
	/* %jp{サイズのアライメントを調整} */
	Size = ValMemHeap_AlignSize(self, Size);
	
	/* %jp{メモリブロックのサイズを調整} */
	MemBlockSize = ValMemHeap_GetMemBlockSize(self);
	
	/* %jp{空き領域を検索} */
	mblk = self->pMemBase;
	while ( mblk->Size != 0 )
	{
		if ( mblk->iFlag == VALMEMHEAP_FREE && mblk->Size >= Size )
		{
			/* 十分な容量があったら */
			if ( mblk->Size - Size > MemBlockSize + (self->AlignMask + 1) )
			{
				/* ブロックを分割する */
				mblk_next  = (T_VALMEMHEAP_MEMBLK *)((char *)mblk + MemBlockSize + Size);
				mblk_next2 = (T_VALMEMHEAP_MEMBLK *)((char *)mblk + MemBlockSize + mblk->Size);
				mblk_next->pPrev  = mblk;
				mblk_next->Size   = mblk->Size - Size - MemBlockSize;
				mblk_next->iFlag  = VALMEMHEAP_FREE;
				mblk_next2->pPrev = mblk_next;
				mblk->Size        = Size;
			}
			mblk->iFlag = VALMEMHEAP_USING;
			
			return (void *)((char *)mblk + MemBlockSize);
		}
		
		/* 次のブロックへ進む */
		mblk = (T_VALMEMHEAP_MEMBLK *)((char *)mblk + mblk->Size + MemBlockSize);
	}

	return NULL;	/* 空きが無い */
}

/* end of file */
