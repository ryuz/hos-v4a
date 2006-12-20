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
#include "object/semobj.h"


/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_SEM && _KERNEL_SPT_CRE_SEM_E_NOMEM) || (_KERNEL_SPT_ACRE_SEM && _KERNEL_SPT_ACRE_SEM_E_NOMEM)
#define _KERNEL_SPT_KCRE_SEM_E_NOMEM	TRUE
#else
#define _KERNEL_SPT_KCRE_SEM_E_NOMEM	FALSE
#endif



/** %jp{セマフォの生成}%en{Create semaphore}
 * @param  semid	%jp{生成対象のセマフォのID番号}%en{ID number of the semaphore to be created}
 * @param  pk_ctsk	%jp{セマフォ生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the semaphore creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_NOMEM  %jp{メモリ不足}%en{Insufficient memory}
 */
ER _kernel_cre_sem(ID semid, const T_CSEM *pk_csem)
{
	_KERNEL_T_SEMCB    *semcb;
	_KERNEL_T_SEMCB_RO *semcb_ro;
	
	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_BLKARRAY
	{
		semcb    = _KERNEL_SEM_ID2SEMCB(semid);
		semcb_ro = semcb;
	}
#elif _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_PTRARRAY
#if _KERNEL_SEMCB_SPLIT_RO
	{
		/* %jp{SEMCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_SEMCB))
					+ _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_SEMCB_RO));

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_SEM_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif
		
		/* %jp{メモリ割り当て} */
		semcb    = (_KERNEL_T_SEMCB *)mem;
		semcb_ro = (_KERNEL_T_SEMCB_RO *)((VB *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_SEMCB)));
		_KERNEL_SEM_ID2SEMCB(semid)           = semcb;
		_KERNEL_SEM_ID2SEMCB(semid)->semcb_ro = (const _KERNEL_T_SEMCB_RO *)semcb_ro;
	}
#else
	{
		VP   mem;
		
		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(sizeof(_KERNEL_T_SEMCB));

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_SEM_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		semcb    = (_KERNEL_T_SEMCB *)mem;
		semcb_ro = (_KERNEL_T_SEMCB_RO *)mem;
		_KERNEL_SEM_ID2SEMCB(semid) = semcb;
	}
#endif
#endif

	/* %jp{メンバ初期化} */
	_KERNEL_CRE_QUE(_KERNEL_SEM_GET_QUE(semcb));
	_KERNEL_SEM_SET_SEMCNT(semcb, pk_csem->isemcnt);
	_KERNEL_SEM_SET_SEMATR(semcb_ro, pk_csem->sematr);
	_KERNEL_SEM_SET_MAXSEM(semcb_ro, pk_csem->maxsem);
	
	return E_OK;
}


/* end of file */
