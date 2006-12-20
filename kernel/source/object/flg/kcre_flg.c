/**
 *  Hyper Operating System V4 Advance
 *
 * @file  kcre_flg.c
 * @brief %jp{イベントフラグの生成}%en{Create Eventflag}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_FLG && _KERNEL_SPT_CRE_FLG_E_NOMEM) || (_KERNEL_SPT_ACRE_FLG && _KERNEL_SPT_ACRE_FLG_E_NOMEM)
#define _KERNEL_SPT_KCRE_FLG_E_NOMEM	TRUE
#else
#define _KERNEL_SPT_KCRE_FLG_E_NOMEM	FALSE
#endif



/** %jp{イベントフラグの生成}%en{Create Eventflag}
 * @param  flgid    %jp{生成対象のイベントフラグのID番号}%en{ID number of the eventflag to be created}
 * @param  pk_cflg	%jp{イベントフラグ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the eventflag creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_NOMEM  %jp{メモリ不足}%en{Insufficient memory}
 */
ER _kernel_cre_flg(ID flgid, const T_CFLG *pk_cflg)
{
	_KERNEL_T_FLGCB    *flgcb;
	
	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_PTRARRAY
	{
		VP   mem;
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(sizeof(_KERNEL_T_FLGCB));

#if _KERNEL_SPT_KCRE_FLG_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		flgcb = (_KERNEL_T_FLGCB *)mem;
		_KERNEL_FLG_ID2FLGCB(flgid) = flgcb;
	}
#else
	{
		flgcb = _KERNEL_FLG_ID2FLGCB(flgid);
	}
#endif

	/* %jp{オブジェクト生成} */
	_KERNEL_FLG_SET_FLGATR(flgcb, pk_cflg->flgatr | _KERNEL_FLG_TA_CRE);
	_KERNEL_CRE_QUE(_KERNEL_FLG_GET_QUE(flgcb));
	_KERNEL_FLG_SET_FLGPTN(flgcb, pk_cflg->iflgptn);

	return E_OK;
}


/* end of file */
