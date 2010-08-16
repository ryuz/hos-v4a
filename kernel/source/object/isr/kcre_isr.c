/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_sem.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/isrobj.h"




ER _kernel_cre_isr(ID isrid, const T_CISR *pk_cisr)
{
	_KERNEL_T_ISRCB    *isrcb;
	_KERNEL_T_ISRCB_RO *isrcb_ro;
	
	if ( pk_cisr->intno < _KERNEL_INT_TMIN_INTNO || pk_cisr->intno > _KERNEL_INT_TMAX_INTNO )
	{
		return E_PAR;
	}

	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_ISRCB_ALGORITHM == _KERNEL_ISRCB_ALG_BLKARRAY
	{
		isrcb    = _KERNEL_ISR_ID2ISRCB(isrid);
		isrcb_ro = isrcb;
	}
#elif _KERNEL_ISRCB_ALGORITHM == _KERNEL_ISRCB_ALG_PTRARRAY
#if _KERNEL_ISRCB_SPLIT_RO
	{
		/* %jp{ISRCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;
		
		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_ISRCB))
					+ _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_ISRCB_RO));
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);
		
		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_ISR_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif
		
		/* %jp{メモリ割り当て} */
		isrcb    = (_KERNEL_T_ISRCB *)mem;
		isrcb_ro = (_KERNEL_T_ISRCB_RO *)((VB *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_ISRCB)));
		_KERNEL_ISR_ID2ISRCB(isrid)           = isrcb;
		_KERNEL_ISR_ID2ISRCB(isrid)->isrcb_ro = (const _KERNEL_T_ISRCB_RO *)isrcb_ro;
	}
#else
	{
		VP   mem;
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(sizeof(_KERNEL_T_ISRCB));

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_ISR_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif
		
		/* %jp{メモリ割り当て} */
		isrcb    = (_KERNEL_T_ISRCB *)mem;
		isrcb_ro = (_KERNEL_T_ISRCB_RO *)mem;
		_KERNEL_ISR_ID2ISRCB(isrid) = isrcb;
	}
#endif
#endif
	
	/* %jp{メンバ初期化} */
	_KERNEL_ISR_SET_EXINF(isrcb_ro, pk_cisr->exinf);
	_KERNEL_ISR_SET_ISR(isrcb_ro, pk_cisr->isr);


#if _KERNEL_SPT_DPC
	_KERNEL_DIS_INT();										/* %jp{割込み禁止} */
#endif

	/* %jp{割込みリストの先頭に繋ぐ} */
	_KERNEL_ISR_SET_NEXT(isrcb, _KERNEL_INT_GET_HEAD(pk_cisr->intno));
	_KERNEL_INT_SET_HEAD(pk_cisr->intno, _KERNEL_ISR_GET_ISRHDL(isrid, isrcb));
	
#if _KERNEL_SPT_DPC
	if ( !_KERNEL_SYS_SNS_LOC() ) { _KERNEL_ENA_INT(); }	/* %jp{割込み許可} */
#endif
	
	return E_OK;
}



/* end of file */
