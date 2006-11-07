/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  get_mpf.c
 * @brief %jp{固定長メモリプール資源の獲得}%en{Acquire Semaphore Resource}
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


ER rel_mpf(ID mpfid, VP blk)
{
	_KERNEL_T_MPFCB_PTR mpfcb;
	_KERNEL_T_TSKHDL    tskhdl;
	_KERNEL_T_TCB       *tcb;

	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_GET_MPF_E_CTX
	if ( _KERNEL_SYS_SNS_DPN() )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
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

	/* %jp{コントロールブロック取得} */
	mpfcb = _KERNEL_MPF_ID2MPFCB(mpfid);

	/* %jp{待ち行列先頭からタスク取り出し} */
	tskhdl = _KERNEL_MPF_RMH_QUE(mpfcb);
	if ( tskhdl != _KERNEL_TSKHDL_NULL )
	{
		VP *p_blk;

		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
		p_blk = (VP *)_KERNEL_TSK_GET_DATA(tcb);
		*p_blk = blk;
		_KERNEL_TSK_SET_ERCD(tcb, E_OK);			/* %jp{エラーコード設定} */
		_KERNEL_DSP_WUP_TSK(tskhdl);				/* %jp{タスクの待ち解除} */
		_KERNEL_MPF_RMV_TOQ(tskhdl);
		
		/* %jp{タスクディスパッチの実行} */
		_KERNEL_DSP_TSK();
	}
	else
	{
		/* %jp{プールに返却} */
		*(_KERNEL_MPF_T_BLKHDL *)blk = _KERNEL_MPF_GET_FREBLK(mpfcb);
		_KERNEL_MPF_SET_FREBLK(mpfcb, _KERNEL_MPF_PTR2BLKHDL(mpfcb, blk));
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;
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
