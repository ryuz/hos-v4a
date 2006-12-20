/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  acre_mpf.c
 * @brief %jp{固定長メモリプールの生成}%en{}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mpfobj.h"


/* %jp{メモリ不足エラーチェックサポートの判定} */
#if (_KERNEL_SPT_CRE_MPF && _KERNEL_SPT_CRE_MPF_E_NOMEM) || (_KERNEL_SPT_ACRE_MPF && _KERNEL_SPT_ACRE_MPF_E_NOMEM)
#define _KERNEL_SPT_KCRE_MPF_E_NOMEM	TRUE
#else
#define _KERNEL_SPT_KCRE_MPF_E_NOMEM	FALSE
#endif


void _kernel_set_mpf(_KERNEL_T_MPFCB_PTR mpfcb, _KERNEL_MPF_T_BLKCNT blkcnt, _KERNEL_MPF_T_BLKSZ blksz, VP mpf);


/** %jp{固定長メモリプールの生成}%en{Create mpfaphore}
 * @param  mpfid	%jp{生成対象の固定長メモリプールのID番号}%en{ID number of the mpfaphore to be created}
 * @param  pk_ctsk	%jp{固定長メモリプール生成情報を入れたパケットへのポインタ}%en{Pointer to the packet containing the mpfaphore creation information}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_NOMEM  %jp{メモリ不足}%en{Insufficient memory}
 */
ER _kernel_cre_mpf(ID mpfid, const T_CMPF *pk_cmpf)
{
	_KERNEL_T_MPFCB    *mpfcb;
	_KERNEL_T_MPFCB_RO *mpfcb_ro;
	VP                 mpf;
	
	/* %jp{メモリ確保}%en{get memory} */
#if _KERNEL_MPFCB_ALGORITHM == _KERNEL_MPFCB_ALG_BLKARRAY
	{	/*  %jp{MPFCB領域がブロック管理の場合} */

		/* メモリ確保 */
		if ( pk_cmpf->mpf == NULL )
		{
			mpf = _KERNEL_SYS_ALC_HEP(TSZ_MPF(pk_cmpf->blkcnt, pk_cmpf->blksz));
		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_MPF_E_NOMEM
			if ( mpf == NULL )
			{
				return E_NOMEM;
			}
#endif
		}
		else
		{
			mpf = pk_cmpf->mpf;
		}
		mpfcb    = _KERNEL_MPF_ID2MPFCB(mpfid);
		mpfcb_ro = mpfcb;
	}
#elif _KERNEL_MPFCB_ALGORITHM == _KERNEL_MPFCB_ALG_PTRARRAY
#if _KERNEL_MPFCB_SPLIT_RO
	{	/* %jp{MPFCB領域がポインタ管理で、ROM/RAM分離の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz  = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MPFCB));
		memsz += _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MPFCB_ROM));
		if ( pk_cmpf->mpf == NULL )
		{
			memsz += TSZ_MPF(pk_cmpf->blkcnt, pk_cmpf->blksz);
		}

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_MPF_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif
		
		/* %jp{メモリ割り当て} */
		mpfcb    = (_KERNEL_T_MPFCB *)mem;
		mpfcb_ro = (_KERNEL_T_MPFCB_ROM *)((B *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MPFCB)));
		mpfcb->mpfcb_ro = mpfcb_ro;
		_KERNEL_TSK_ID2MPFCB(mpfid) = mpfcb;
		if ( pk_cmpf->mpf == NULL )
		{
			mpf = (_KERNEL_T_MPFCB_ROM *)((B *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MPFCB)) + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MPFCB_ROM)));
		}
		else
		{
			mpf = pk_cmpf->mpf;
		}
	}
#else
	{	/* %jp{MPFCB領域がポインタ管理で、ROM/RAM統合の場合} */
		VP   mem;
		SIZE memsz;

		/* %jp{メモリサイズ決定} */
		memsz = _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MPFCB));
		if ( pk_cmpf->mpf == NULL )
		{
			memsz += TSZ_MPF(pk_cmpf->blkcnt, pk_cmpf->blksz)
		}

		/* %jp{メモリ確保} */
		mem = _KERNEL_SYS_ALC_HEP(memsz);

		/* %jp{メモリ不足チェック} */
#if _KERNEL_SPT_KCRE_MPF_E_NOMEM
		if ( mem == NULL )
		{
			return E_NOMEM;
		}
#endif

		/* %jp{メモリ割り当て} */
		mpfcb    = (_KERNEL_T_MPFCB *)mem;
		mpfcb_ro = mpfcb;
		_KERNEL_MPF_ID2MPFCB(mpfid) = mpfcb;
		if ( pk_cmpf->mpf == NULL )
		{
			mpf = (_KERNEL_T_MPFCB_ROM *)((B *)mem + _KERNEL_SYS_ALG_HEP(sizeof(_KERNEL_T_MPFCB)));
		}
		else
		{
			mpf = pk_cmpf->mpf;
		}
	}
#endif
#endif
		
	/* %jp{メンバ初期化} */
	_KERNEL_MPF_SET_MPFATR(mpfcb_ro, pk_cmpf->mpfatr);
	_KERNEL_MPF_SET_BLKCNT(mpfcb_ro, pk_cmpf->blkcnt);
	_KERNEL_MPF_SET_BLKSZ(mpfcb_ro, _KERNEL_TSZ_ALIGNED(pk_cmpf->blksz));
	_KERNEL_MPF_SET_MPF(mpfcb_ro, mpf);
	_KERNEL_CRE_QUE(_KERNEL_MPF_GET_QUE(mpfcb));
	_kernel_set_mpf(mpfcb, pk_cmpf->blkcnt, pk_cmpf->blksz, mpf);

	return E_OK;
}


void _kernel_set_mpf(_KERNEL_T_MPFCB_PTR mpfcb, _KERNEL_MPF_T_BLKCNT blkcnt, _KERNEL_MPF_T_BLKSZ blksz, VP mpf)
{
	UINT i;

#if _KERNEL_MPF_ALGORITHM == _KERNEL_MPF_ALG_CHAIN_PTR		/* %jp{ポインタ管理} */
	{
		VB *ptr, *next;

		ptr = (VB *)mpf;
		_KERNEL_MPF_SET_FREBLK(mpfcb, ptr);
		for ( i = 0; i < blkcnt - 1; i++ )
		{
			next = ptr + blksz;
			*(_KERNEL_MPFCB_T_BLKHDL *)ptr = next;
			ptr = next;
		}
		*(_KERNEL_MPFCB_T_BLKHDL *)ptr = NULL;
	}
#elif  _KERNEL_MPF_ALGORITHM == _KERNEL_MPF_ALG_CHAIN_NUM	/* %jp{ブロック番号管理} */
	{
		VB *ptr;

		ptr = (VB *)mpf;
		_KERNEL_MPF_SET_FREBLK(mpfcb, 1);
		for ( i = 1; i < blkcnt - 1; i++ )
		{
			*(_KERNEL_MPFCB_T_BLKHDL *)ptr = (i + 1);
			ptr += blksz;
		}
		*(_KERNEL_MPFCB_T_BLKHDL *)ptr = 0;
	}
#endif
}




/* end of file */
