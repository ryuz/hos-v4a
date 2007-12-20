/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_mtx.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"


/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_MTX && _KERNEL_SPT_CRE_MTX_E_NOMEM) || (_KERNEL_SPT_ACRE_MTX && _KERNEL_SPT_ACRE_MTX_E_NOMEM)
#define _KERNEL_SPT_KCRE_MTX_E_NOMEM	TRUE
#else
#define _KERNEL_SPT_KCRE_MTX_E_NOMEM	FALSE
#endif



/** %jp{ミューテックスの生成}%en{Create mutex}
 * @param  mtxid	%jp{生成対象のミューテックスのID番号}%en{ID number of the mutex to be created}
 * @param  pk_ctsk	%jp{ミューテックス生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the mutex creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_NOMEM  %jp{メモリ不足}%en{Insufficient memory}
 */
ER _kernel_cre_mtx(ID mtxid, const T_CMTX *pk_cmtx)
{
	_KERNEL_T_MTXCB		*mtxcb;
	_KERNEL_T_MTXCB_RO	*mtxcb_ro;
	
	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_BLKARRAY
	{
		mtxcb    = _KERNEL_MTX_ID2MTXCB(mtxid);
		mtxcb_ro = mtxcb;
	}
#elif _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_PTRARRAY
#if _KERNEL_MTXCB_SPLIT_RO
	{
		/* %jp{MTXCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MTXCB))
					+ _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MTXCB_RO));

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_MTX_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif
		
		/* %jp{メモリ割り当て} */
		mtxcb    = (_KERNEL_T_MTXCB *)mem;
		mtxcb_ro = (_KERNEL_T_MTXCB_RO *)((VB *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MTXCB)));
		_KERNEL_MTX_ID2MTXCB(mtxid)           = mtxcb;
		_KERNEL_MTX_ID2MTXCB(mtxid)->mtxcb_ro = (const _KERNEL_T_MTXCB_RO *)mtxcb_ro;
	}
#else
	{
		VP   mem;
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(sizeof(_KERNEL_T_MTXCB));

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_MTX_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		mtxcb    = (_KERNEL_T_MTXCB *)mem;
		mtxcb_ro = (_KERNEL_T_MTXCB_RO *)mem;
		_KERNEL_MTX_ID2MTXCB(mtxid) = mtxcb;
	}
#endif
#endif
	
	/* %jp{メンバ初期化} */
	_KERNEL_CRE_QUE(_KERNEL_MTX_GET_QUE(mtxcb));
	_KERNEL_MTX_SET_TSKHDL(mtxcb, _KERNEL_TSKHDL_NULL);
	_KERNEL_MTX_SET_MTXATR(mtxcb_ro, pk_cmtx->mtxatr);
	_KERNEL_MTX_SET_CEILPRI(mtxcb_ro, pk_cmtx->ceilpri);
	
	return E_OK;
}


/* end of file */
