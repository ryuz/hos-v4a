/**
 *  Hyper Operating System V4 Advance
 *
 * @file  alc_hep.c
 * @brief %jp{メモリヒープのからメモリ割当て}%en{allocate memory}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/hep.h"


/** %jp{メモリの割り当て} */
VP _kernel_alc_hep(
		_KERNEL_T_HEPCB *pk_hepcb,
		SIZE           size)
{
	_KERNEL_T_HEPBLK *mblk;
	_KERNEL_T_HEPBLK *mblk_next;
	_KERNEL_T_HEPBLK *mblk_next2;
	
	/* %jp{ヒープの存在チェック} */
	if ( pk_hepcb->base == NULL )
	{
		return NULL;
	}
	
	/* %jp{サイズのアライメントを調整} */
	size = _KERNEL_HEP_ALIGNED(size);
	
	/* %jp{空き領域を検索} */
	mblk = pk_hepcb->base;
	while ( mblk->size != 0 )
	{
		if ( mblk->flag == _KERNEL_HEP_FREE && mblk->size >= size )
		{
			/* 十分な容量があったら */
			if ( mblk->size - size > _KERNEL_HEP_BLKSIZE + _KERNEL_HEP_MEMALIGN )
			{
				/* ブロックを分割する */
				mblk_next  = (_KERNEL_T_HEPBLK *)((UB *)mblk + _KERNEL_HEP_BLKSIZE + size);
				mblk_next2 = (_KERNEL_T_HEPBLK *)((UB *)mblk + _KERNEL_HEP_BLKSIZE + mblk->size);
				mblk_next->prev  = mblk;
				mblk_next->size  = mblk->size - size - _KERNEL_HEP_BLKSIZE;
				mblk_next->flag  = _KERNEL_HEP_FREE;
				mblk_next2->prev = mblk_next;
				mblk->size       = size;
			}
			mblk->flag = _KERNEL_HEP_USING;
			
			return (VP)((UB *)mblk + _KERNEL_HEP_BLKSIZE);
		}
		
		/* 次のブロックへ進む */
		mblk = (_KERNEL_T_HEPBLK *)((UB *)mblk + mblk->size + _KERNEL_HEP_BLKSIZE);
	}

	return NULL;	/* 空きが無い */
}


/* end of file */
