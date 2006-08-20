/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  get_mpf.c
 * @brief %jp{固定長メモリプール資源の獲得}%en{Acquire Semaphore Resource}
 *
 * @version $Id: get_mpf.c,v 1.2 2006-08-20 09:02:30 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mpfobj.h"



#if _KERNEL_SPT_GET_MPF


#if _KERNEL_SPT_TGET_MPF && (_KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED)	/* %jp{tget_mpfありで、サイズ優先なら} */


ER get_mpf(ID mpfid, VP *p_blk)
{
	/* %jp{tget_mpfで代替する} */
	return tget_mpf(mpfid, p_blk, TMO_FEVR);
}

#else


ER get_mpf(ID mpfid, VP *p_blk)
{
	_KERNEL_T_MPFHDL     mpfhdl;
	_KERNEL_T_TSKHDL     tskhdl;
	_KERNEL_T_TCB        *tcb;
	_KERNEL_MPF_T_BLKHDL blkhdl;
	VP                   blkptr;
	ER                   ercd;
	
	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_GET_MPF_E_CTX
	if ( _KERNEL_SYS_SNS_DPN() )
	{
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_GET_MPF_E_ID
	if ( !_KERNEL_MPF_CHECK_MPFID(mpfid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_GET_MPF_E_NOEXS
	if ( !_KERNEL_MPF_CHECK_EXS(mpfid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif

	/* %jp{固定長メモリプールハンドル取得} */
	mpfhdl = _KERNEL_MPF_ID2MPFHDL(mpfid);
	
	/* %jp{固定長メモリプールカウンタ取得} */
	blkhdl = _KERNEL_MPF_GET_FREBLK(mpfhdl);
	
	if ( blkhdl != _KERNEL_MPF_BLKHDL_NULL )
	{
		/* %jp{固定長メモリプール資源が獲得できれば成功} */
		blkptr = _KERNEL_MPF_BLKHDL2PTR(mpfhdl, blkhdl);
		*p_blk = blkptr;
		_KERNEL_MPF_SET_FREBLK(mpfhdl, *(_KERNEL_MPF_T_BLKHDL *)blkptr);
		_KERNEL_MPF_SET_FBLKCNT(mpfhdl, _KERNEL_MPF_GET_FBLKCNT(mpfhdl) - 1);
		ercd = E_OK;
	}
	else
	{
		/* %jp{タスクを待ち状態にする} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);				/* %jp{TCB取得} */
		_KERNEL_TSK_SET_TSKWAIT(tcb, _KERNEL_TTW_MPF);
		_KERNEL_TSK_SET_WOBJID(tcb, mpfid);
		_KERNEL_TSK_SET_DATA(tcb, (VP_INT)p_blk);

		_KERNEL_DSP_WAI_TSK(tskhdl);
		_KERNEL_MPF_ADD_QUE(mpfhdl, tskhdl);				/* %jp{待ち行列に追加} */

		/* %jp{タスクディスパッチの実行} */
		_KERNEL_DSP_TSK();

		/* %jp{エラーコードの取得} */
		ercd = _KERNEL_TSK_GET_ERCD(tcb);
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{オブジェクト未生成}%en{Non-existant object} */
	
	return ercd;
}

#endif


#else	/* _KERNEL_SPT_GET_MPF */


#if _KERNEL_SPT_GET_MPF_E_NOSPT


ER get_mpf(ID mpfid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_GET_MPF */



/* end of file */
