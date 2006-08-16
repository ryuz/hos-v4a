/**
 *  Hyper Operating System V4 Advance
 *
 * @file  kcre_mbx.c
 * @brief %jp{メールボックスの生成}%en{Create Eventflag}
 *
 * @version $Id: kcre_mbx.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"



/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_MBX && _KERNEL_SPT_CRE_MBX_E_NOMEM) || (_KERNEL_SPT_AMBX_SEM && _KERNEL_SPT_ACRE_MBX_E_NOMEM)
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
	_KERNEL_T_MBXHDL mbxhdl;
	
	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_PTRARRAY
#if _KERNEL_MBXCB_ROM
	{
		/* %jp{TCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_MEM(sizeof(_KERNEL_T_MBXCB))
					+ _KERNEL_SYS_ALG_MEM(sizeof(_KERNEL_T_MBXCB_ROM));

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_MEM(memsz);

#if _KERNEL_SPT_KCRE_MBX_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		_KERNEL_TSK_ID2MBXCB(mbxid)           = (_KERNEL_T_MBXCB *)mem;
		_KERNEL_TSK_ID2MBXCB(mbxid)->mbxcbrom = (_KERNEL_T_MBXCB_ROM *)((B *)mem + _KERNEL_SYS_ALG_MEM(sizeof(_KERNEL_T_MBXCB)));
	}
#else
	{
		VP   mem;
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_MEM(sizeof(_KERNEL_T_MBXCB));

#if _KERNEL_SPT_KCRE_MBX_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		_KERNEL_SEM_ID2MBXCB(mbxid) = (_KERNEL_T_MBXCB *)mem;
	}
#endif
#endif

	/* %jp{オブジェクト生成} */
	mbxhdl = _KERNEL_MBX_ID2MBXHDL(mbxid);
	_KERNEL_MBX_SET_MBXATR(mbxhdl, pk_cmbx->mbxatr | _KERNEL_MBX_TA_CRE);
	_KERNEL_CRE_QUE(_KERNEL_MBX_GET_QUE(mbxhdl));
	if ( pk_cmbx->mbxatr & TA_MPRI)
	{
	}
	else
	{
		_KERNEL_MBX_SET_MSGQUE(mbxhdl, NULL);
	}

	return E_OK;
}


/* end of file */
