/**
 *  Hyper Operating System V4 Advance
 *
 * @file  kcre_flg.c
 * @brief %jp{イベントフラグの生成}%en{Create Eventflag}
 *
 * @version $Id: kcre_flg.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_FLG && _KERNEL_SPT_CRE_FLG_E_NOMEM) || (_KERNEL_SPT_AFLG_SEM && _KERNEL_SPT_ACRE_FLG_E_NOMEM)
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
	_KERNEL_T_FLGHDL flghdl;
	
	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_PTRARRAY
#if _KERNEL_FLGCB_ROM
	{
		/* %jp{TCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_MEM(sizeof(_KERNEL_T_FLGCB))
					+ _KERNEL_SYS_ALG_MEM(sizeof(_KERNEL_T_FLGCB_ROM));

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_MEM(memsz);

#if _KERNEL_SPT_KCRE_FLG_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		_KERNEL_TSK_ID2FLGCB(flgid)           = (_KERNEL_T_FLGCB *)mem;
		_KERNEL_TSK_ID2FLGCB(flgid)->flgcbrom = (_KERNEL_T_FLGCB_ROM *)((B *)mem + _KERNEL_SYS_ALG_MEM(sizeof(_KERNEL_T_FLGCB)));
	}
#else
	{
		VP   mem;
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_MEM(sizeof(_KERNEL_T_FLGCB));

#if _KERNEL_SPT_KCRE_FLG_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		_KERNEL_SEM_ID2FLGCB(flgid) = (_KERNEL_T_FLGCB *)mem;
	}
#endif
#endif

	/* %jp{オブジェクト生成} */
	flghdl = _KERNEL_FLG_ID2FLGHDL(flgid);
	_KERNEL_FLG_SET_FLGATR(flghdl, pk_cflg->flgatr | _KERNEL_FLG_TA_CRE);
	_KERNEL_CRE_QUE(_KERNEL_FLG_GET_QUE(flghdl));
	_KERNEL_FLG_SET_FLGPTN(flghdl, pk_cflg->iflgptn);

	return E_OK;
}


/* end of file */
