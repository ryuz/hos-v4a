/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_cyc.c
 * @brief %jp{周期ハンドラの生成}%en{Create cyclic handler}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/cycobj.h"


/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_CYC && _KERNEL_SPT_CRE_CYC_E_NOMEM) || (_KERNEL_SPT_ACRE_CYC && _KERNEL_SPT_ACRE_CYC_E_NOMEM)
#define _KERNEL_SPT_KCRE_CYC_E_NOMEM	TRUE
#else
#define _KERNEL_SPT_KCRE_CYC_E_NOMEM	FALSE
#endif



/** %jp{周期ハンドラの生成}%en{Create cyclic handler}
 * @param  cycid	%jp{生成対象の周期ハンドラのID番号}%en{ID number of the cyclic handler to be created}
 * @param  pk_ctsk	%jp{周期ハンドラ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the cyclic handler creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_NOMEM  %jp{メモリ不足}%en{Insufficient memory}
 */
ER _kernel_cre_cyc(ID cycid, const T_CCYC *pk_ccyc)
{
	_KERNEL_T_CYCCB    *cyccb;
	_KERNEL_T_CYCCB_RO *cyccb_ro;
	_KERNEL_T_TIMOBJ   *pk_timobj;
	
	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_BLKARRAY
	{
		cyccb    = _KERNEL_CYC_ID2CYCCB(cycid);
		cyccb_ro = cyccb;
	}
#elif _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_PTRARRAY
#if _KERNEL_CYCCB_SPLIT_RO
	{
		/* %jp{CYCCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_CYCCB))
					+ _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_CYCCB_RO));

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_CYC_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif
		
		/* %jp{メモリ割り当て} */
		cyccb    = (_KERNEL_T_CYCCB *)mem;
		cyccb_ro = (_KERNEL_T_CYCCB_RO *)((VB *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_CYCCB)));
		_KERNEL_CYC_ID2CYCCB(cycid)           = cyccb;
		_KERNEL_CYC_ID2CYCCB(cycid)->cyccb_ro = (const _KERNEL_T_CYCCB_RO *)cyccb_ro;
	}
#else
	{
		VP   mem;
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(sizeof(_KERNEL_T_CYCCB));

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_CYC_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		cyccb    = (_KERNEL_T_CYCCB *)mem;
		cyccb_ro = (_KERNEL_T_CYCCB_RO *)mem;
		_KERNEL_CYC_ID2CYCCB(cycid) = cyccb;
	}
#endif
#endif

	/* %jp{メンバ初期化} */
	pk_timobj = _KERNEL_CYC_GET_TIMOBJ(cyccb);
	_KERNEL_TIMOBJ_CRE_TIMOBJ(pk_timobj);
	_KERNEL_TIMOBJ_SET_TIMHDR(pk_timobj, _kernel_cyc_hdr);
	_KERNEL_CYC_SET_CYCATR(cyccb_ro, pk_ccyc->cycatr);
	_KERNEL_CYC_SET_EXINF(cyccb_ro, pk_ccyc->exinf);
	_KERNEL_CYC_SET_CYCHDR(cyccb_ro, pk_ccyc->cychdr);
	_KERNEL_CYC_SET_CYCTIM(cyccb_ro, pk_ccyc->cyctim);
	_KERNEL_CYC_SET_CYCPHS(cyccb_ro, pk_ccyc->cycphs);
	
#if _KERNEL_SPT_CYC_TA_STA
	if ( pk_ccyc->cycatr & TA_STA )
	{
		if ( pk_ccyc->cycatr & TA_PHS )
		{
			_KERNEL_TIMOBJ_SET_LEFTTIM(pk_timobj, pk_ccyc->cycphs);
		}
		else
		{
			_KERNEL_TIMOBJ_SET_LEFTTIM(pk_timobj, pk_ccyc->cyctim);
		}
		_KERNEL_SYS_ADD_TMQ(pk_timobj);

	}
#endif

	return E_OK;
}


/* end of file */
