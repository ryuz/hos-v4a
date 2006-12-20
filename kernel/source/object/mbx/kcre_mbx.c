/**
 *  Hyper Operating System V4 Advance
 *
 * @file  kcre_mbx.c
 * @brief %jp{メールボックスの生成}%en{Create Eventflag}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"



/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_MBX && _KERNEL_SPT_CRE_MBX_E_NOMEM) || (_KERNEL_SPT_ACRE_MBX && _KERNEL_SPT_ACRE_MBX_E_NOMEM)
#define _KERNEL_SPT_KCRE_MBX_E_NOMEM	TRUE
#else
#define _KERNEL_SPT_KCRE_MBX_E_NOMEM	FALSE
#endif



/** %jp{メールボックスの生成}%en{Create Eventflag}
 * @param  mbxid    %jp{生成対象のメールボックスのID番号}%en{ID number of the eventflag to be created}
 * @param  pk_cmbx	%jp{メールボックス生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the eventflag creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_NOMEM  %jp{メモリ不足}%en{Insufficient memory}
 */
ER _kernel_cre_mbx(ID mbxid, const T_CMBX *pk_cmbx)
{
	_KERNEL_T_MBXCB    *mbxcb;
	_KERNEL_T_MBXCB_RO *mbxcb_ro;
	VP                 mprihd;

	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_PTRARRAY
#if _KERNEL_MBXCB_SPLIT_RO
	{
		/* %jp{MBXCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz  = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MBXCB));			/* %jp{コントロールブロックのサイズ} */
		memsz += _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MBXCB_RO));		/* %jp{コントロールブロック(RO部)のサイズ} */
		if ( (pk_cmbx->mbxatr & TA_MPRI) && pk_cmbx->mprihd == NULL )
		{
			memsz += _KERNEL_SYS_ALG_HEP(TSZ_MPRIHD(pk_cmbx->maxmpri));
		}

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);

#if _KERNEL_SPT_KCRE_MBX_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif
		/* %jp{メモリ割り当て} */
		mbxcb    = (_KERNEL_T_MBXCB *)mem;
		mbxcb_ro = (_KERNEL_T_MBXCB_RO *)((B *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MBXCB)));
		if ( pk_cmbx->mprihd == NULL )
		{
			mprihd = (VP)((B *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MBXCB)) + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MBXCB_RO)));
		}
		else
		{
			mprihd = pk_cmbx->mprihd;
		}
		mbxcb->mbxcb_ro = mbxcb_ro;
		_KERNEL_MBX_ID2MBXCB(mbxid) = mbxcb;
	}
#else
	{
		/* %jp{MBXCB領域がポインタ管理で、ROM/RAM統合の場合} */
		VP   mem;
		SIZE memsz;
		
		/* %jp{メモリサイズ決定} */
		memsz  = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MBXCB));			/* %jp{コントロールブロックのサイズ} */
		if ( (pk_cmbx->mbxatr & TA_MPRI) && pk_cmbx->mprihd == NULL )
		{
			memsz += _KERNEL_SYS_ALG_HEP(TSZ_MPRIHD(pk_cmbx->maxmpri));
		}

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);

#if _KERNEL_SPT_KCRE_MBX_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		mbxcb  = (_KERNEL_T_MBXCB *)mem;
		if ( pk_cmbx->mprihd == NULL )
		{
			mprihd = (VP)((B *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MBXCB)));
		}
		else
		{
			mprihd = pk_cmbx->mprihd;
		}
		mbxcb_ro = mbxcb;
		_KERNEL_MBX_ID2MBXCB(mbxid) = (_KERNEL_T_MBXCB *)mem;
	}
#endif
#else
	{	/* %jp{MBXCB領域がブロック配列管理の場合} */

		if ( (pk_cmbx->mbxatr & TA_MPRI) && pk_cmbx->mprihd == NULL )
		{
			mprihd = _KERNEL_SYS_ALC_HEP(TSZ_MPRIHD(pk_cmbx->maxmpri));
		}
		else
		{
			mprihd = pk_cmbx->mprihd;
		}

		mbxcb    = _KERNEL_MBX_ID2MBXCB(mbxid);
		mbxcb_ro = mbxcb;
	}
#endif

	/* %jp{オブジェクト生成} */
	_KERNEL_MBX_SET_MBXATR(mbxcb_ro, pk_cmbx->mbxatr | _KERNEL_MBX_TA_CRE);
	_KERNEL_MBX_SET_MAXMPRI(mbxcb_ro, pk_cmbx->maxmpri);
	_KERNEL_CRE_QUE(_KERNEL_MBX_GET_QUE(mbxcb));
	if ( pk_cmbx->mbxatr & TA_MPRI )
	{
		int i;
		_KERNEL_MBX_SET_MSGQUE(mbxcb, mprihd);
		for ( i = 0; i < pk_cmbx->maxmpri; i++ )
		{
			((VP *)mprihd)[i] = NULL;
		}
	}
	else
	{
		_KERNEL_MBX_SET_MSGQUE(mbxcb, NULL);
	}

	return E_OK;
}


/* end of file */
