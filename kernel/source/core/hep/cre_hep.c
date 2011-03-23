/**
 *  Hyper Operating System V4 Advance
 *
 * @file  hep.h
 * @brief %jp{メモリヒープ生成}%en{create memory heap}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/hep.h"



/** %jp{メモリヒープを生成} */
void _kernel_cre_hep(
		_KERNEL_T_HEPCB *pk_hepcb,
		SIZE           hepsz,
		VP             hep)
{
	_KERNEL_T_HEPBLK *blk_last;

	/* %jp{サイズのアライメントを調整} */
	hepsz &= ~(_KERNEL_HEP_MEMALIGN - 1);

	/* %jp{サイズチェック} */
	if ( hepsz <= sizeof(_KERNEL_T_HEPBLK) )
	{
		pk_hepcb->base = NULL;
		return;
	}

	/* %jp{設定保存} */
	pk_hepcb->base   = (_KERNEL_T_HEPBLK *)hep;
	pk_hepcb->heapsz = hepsz;

	/* %jp{終端位置に番人を設定} */
	blk_last = (_KERNEL_T_HEPBLK *)((UB *)hep + hepsz - _KERNEL_HEP_BLKSIZE);

	/* %jp{全体を空き領域に設定} */
	pk_hepcb->base->prev = NULL;
	pk_hepcb->base->size = hepsz - (_KERNEL_HEP_BLKSIZE * 2);
	pk_hepcb->base->flag = _KERNEL_HEP_FREE;

	/* %jp{終端の番人を利用中に設定} */
	blk_last->prev = NULL;
	blk_last->size = 0;
	blk_last->flag = _KERNEL_HEP_USING;
}



/* end of file */
