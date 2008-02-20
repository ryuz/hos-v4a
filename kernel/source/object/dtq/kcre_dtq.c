/**
 *  Hyper Operating System V4 Advance
 *
 * @file  kcre_dtq.c
 * @brief %jp{データキューの生成}%en{Create Data queue}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/dtqobj.h"



/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_DTQ && _KERNEL_SPT_CRE_DTQ_E_NOMEM) || (_KERNEL_SPT_ACRE_DTQ && _KERNEL_SPT_ACRE_DTQ_E_NOMEM)
#define _KERNEL_SPT_KCRE_DTQ_E_NOMEM	TRUE
#else
#define _KERNEL_SPT_KCRE_DTQ_E_NOMEM	FALSE
#endif



/** %jp{データキューの生成}%en{Create Data queue}
 * @param  dtqid	%jp{生成対象のデータキューのID番号}%en{ID number of the data queue to be created}
 * @param  pk_ctsk	%jp{データキュー生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the data queue creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_NOMEM  %jp{メモリ不足}%en{Insufficient memory}
 */
ER _kernel_cre_dtq(ID dtqid, const T_CDTQ *pk_cdtq)
{
	_KERNEL_T_DTQCB    *dtqcb;
	_KERNEL_T_DTQCB_RO *dtqcb_ro;
	
	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_BLKARRAY
	{
		dtqcb    = _KERNEL_DTQ_ID2DTQCB(dtqid);
		dtqcb_ro = dtqcb;
	}
#elif _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_PTRARRAY
#if _KERNEL_DTQCB_SPLIT_RO
	{
		/* %jp{DTQCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_DTQCB))
					+ _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_DTQCB_RO));

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_DTQ_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif
		
		/* %jp{メモリ割り当て} */
		dtqcb    = (_KERNEL_T_DTQCB *)mem;
		dtqcb_ro = (_KERNEL_T_DTQCB_RO *)((VB *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_DTQCB)));
		_KERNEL_DTQ_ID2DTQCB(dtqid)           = dtqcb;
		_KERNEL_DTQ_ID2DTQCB(dtqid)->dtqcb_ro = (const _KERNEL_T_DTQCB_RO *)dtqcb_ro;
	}
#else
	{
		VP   mem;
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(sizeof(_KERNEL_T_DTQCB));

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_DTQ_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		dtqcb    = (_KERNEL_T_DTQCB *)mem;
		dtqcb_ro = (_KERNEL_T_DTQCB_RO *)mem;
		_KERNEL_DTQ_ID2DTQCB(dtqid) = dtqcb;
	}
#endif
#endif

	/* %jp{メンバ初期化} */
	_KERNEL_DTQ_SET_DTQATR(dtqcb_ro, pk_cdtq->dtqatr);
	_KERNEL_DTQ_SET_DTQCNT(dtqcb_ro, pk_cdtq->dtqcnt);
	_KERNEL_DTQ_SET_DTQ(dtqcb_ro, pk_cdtq->dtq);
	_KERNEL_CRE_QUE(_KERNEL_DTQ_GET_SQUE(dtqcb));
	_KERNEL_CRE_QUE(_KERNEL_DTQ_GET_RQUE(dtqcb));
	_KERNEL_DTQ_SET_SDTQCNT(dtqcb, 0);
	_KERNEL_DTQ_SET_HEAD(dtqcb, 0);
	
	return E_OK;
}


/* end of file */
