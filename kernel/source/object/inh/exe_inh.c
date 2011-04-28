/**
 *  Hyper Operating System V4 Advance
 *
 * @file  exe_inh.c
 * @brief %jp{割込みハンドラの処理}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"


/* %jp{割込みハンドラの処理} */
void _kernel_exe_inh(INHNO inhno)
{
	/* %jp{割込みハンドラの処理} */
#if _KERNEL_SPT_INH
	{
		const _KERNEL_T_INHINF *pk_inhinf;
	
		pk_inhinf = _KERNEL_INT_GET_INHINF(inhno);
	
		if ( pk_inhinf->inthdr != NULL )
		{
#if _KERNEL_PROCATR_SPT_MULTINT
			_KERNEL_ENA_INT();			/* %jp{多重割込み許可} */
#endif
			pk_inhinf->inthdr();		/* %jp{割込みハンドラの処理} */
#if _KERNEL_PROCATR_SPT_MULTINT
			_KERNEL_DIS_INT();			/* %jp{割込み禁止} */
#endif
		}
	}
#endif
	
	/* %jp{割込みコントローラの処理} */
#if _KERNEL_SPT_ISR
	_KERNEL_EXE_IRC(inhno);
#endif

}


/* end of file */
