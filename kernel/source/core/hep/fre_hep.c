/**
 *  Hyper Operating System V4 Advance
 *
 * @file  alc_hep.c
 * @brief %jp{メモリヒープへメモリ返却}%en{memory free}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/hep.h"



/** %jp{メモリの解放} */
void _kernel_fre_hep(
		_KERNEL_T_HEPCB *pk_hepcb,
		VP             ptr)
{
	_KERNEL_T_HEPBLK *mblk;
	_KERNEL_T_HEPBLK *mblktmp;
	_KERNEL_T_HEPBLK *mblknext;

	/* %jp{ポインタ範囲チェック} */
	if ( ptr < (VP)pk_hepcb->base || ptr >= (VP)((UB*)pk_hepcb->base + pk_hepcb->heapsz) )
	{
		return;
	}

	/* %jp{メモリブロック位置を取得} */
	mblk = (_KERNEL_T_HEPBLK *)((UB *)ptr - _KERNEL_HEP_BLKSIZE);

	/* %jp{パラメーターチェック} */
	if ( mblk->flag != _KERNEL_HEP_USING )	/* %jp{使用中で無ければ} */
	{
		return;
	}

	/* %jp{フラグを未使用に設定} */
	mblk->flag = _KERNEL_HEP_FREE;
	
	/* %jp{次のブロックをチェック} */
	mblktmp = (_KERNEL_T_HEPBLK *)((UB *)ptr + mblk->size);
	if ( mblktmp->flag == _KERNEL_HEP_FREE )
	{
		/* %jp{次のブロックが未使用なら結合する} */
		mblknext = (_KERNEL_T_HEPBLK *)((UB *)mblktmp + mblktmp->size + _KERNEL_HEP_BLKSIZE);
		mblknext->prev = mblk;
		mblk->size += mblktmp->size + _KERNEL_HEP_BLKSIZE;
	}

	/* %jp{前のブロックをチェック} */
	if ( mblk->prev != NULL )
	{
		mblktmp = mblk->prev;
		if ( mblktmp->flag == _KERNEL_HEP_FREE )
		{
			/* %jp{前のブロックが未使用なら結合する} */
			mblknext = (_KERNEL_T_HEPBLK *)((UB *)mblk + mblk->size + _KERNEL_HEP_BLKSIZE);
			mblknext->prev = mblktmp;
			mblktmp->size += mblk->size + _KERNEL_HEP_BLKSIZE;
		}
	}
}



/* end of file */
