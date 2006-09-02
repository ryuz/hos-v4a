/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  get_mpf.c
 * @brief %jp{固定長メモリプール資源の獲得}%en{Acquire Semaphore Resource}
 *
 * @version $Id: pget_mpf.c,v 1.2 2006-09-02 15:08:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mpfobj.h"



#if _KERNEL_SPT_PGET_MPF


#if _KERNEL_SPT_TGET_MPF && (_KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED)	/* %jp{tget_mpfありで、サイズ優先なら} */


ER pget_mpf(ID mpfid, VP *p_blk)
{
	/* %jp{tget_mpfで代替する} */
	return tget_mpf(mpfid, p_blk, TMO_POL);
}

#else


ER pget_mpf(ID mpfid, VP *p_blk)
{
	_KERNEL_T_MPFCB_PTR  mpfcb;
	_KERNEL_MPF_T_BLKHDL blkhdl;
	VP                   blkptr;
	ER                   ercd;
	
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_PGET_MPF_E_ID
	if ( !_KERNEL_MPF_CHECK_MPFID(mpfid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_PGET_MPF_E_NOEXS
	if ( !_KERNEL_MPF_CHECK_EXS(mpfid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif

	/* %jp{コントロールブロック取得} */
	mpfcb = _KERNEL_MPF_ID2MPFCB(mpfid);
	
	/* %jp{固定長メモリプールカウンタ取得} */
	blkhdl = _KERNEL_MPF_GET_FREBLK(mpfcb);
	
	if ( blkhdl != _KERNEL_MPF_BLKHDL_NULL )
	{
		/* %jp{固定長メモリプール資源が獲得できれば成功} */
		blkptr = _KERNEL_MPF_BLKHDL2PTR(mpfcb, blkhdl);
		*p_blk = blkptr;
		_KERNEL_MPF_SET_FREBLK(mpfcb, *(_KERNEL_MPF_T_BLKHDL *)blkptr);
		_KERNEL_MPF_SET_FBLKCNT(mpfcb, _KERNEL_MPF_GET_FBLKCNT(mpfhdl) - 1);
		ercd = E_OK;
	}
	else
	{
		ercd = E_TMOUT;
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{オブジェクト未生成}%en{Non-existant object} */
	
	return ercd;
}

#endif


#else	/* _KERNEL_SPT_GET_MPF */


#if _KERNEL_SPT_GET_MPF_E_NOSPT


ER pget_mpf(ID mpfid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_GET_MPF */



/* end of file */
