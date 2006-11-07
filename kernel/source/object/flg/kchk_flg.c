/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_sem.c
 * @brief %jp{セマフォ資源の返却}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



/* %jp{フラグが起床条件を満たしているかチェック} */
BOOL _kernel_chk_flg(
		_KERNEL_T_FLGCB  *flgcb,		/* %jp{コントロールブロック} */
		_KERNEL_T_FLGINF *pk_flginf)	/* %jp{待ちフラグ情報パケットの先頭番地} */
{
	if ( pk_flginf->wfmode == TWF_ANDW )
	{
		/* %jp{AND待ち判定} */
		return ((_KERNEL_FLG_GET_FLGPTN(flgcb) & pk_flginf->waiptn) == pk_flginf->waiptn);
	}
	else
	{
		/* %jp{OR待ち判定} */
		return ((_KERNEL_FLG_GET_FLGPTN(flgcb) & pk_flginf->waiptn) != 0);
	}
}


/* end of file */
