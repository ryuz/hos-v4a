/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  del_flg.c
 * @brief %jp{イベントフラグの削除}%en{Delete Eventflag}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/flgobj.h"



#if _KERNEL_SPT_DEL_FLG


/** %jp{イベントフラグの削除}%en{Delete Eventflag}
 * @param  flgid    %jp{削除対象のイベントフラグのID番号}%en{ID number of the eventflag to be deleted}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象イベントフラグが未登録)}%en{Non-existant object(specified eventflag is not registerd)}
 */
ER del_flg(ID flgid)
{
	_KERNEL_T_FLGCB  *flgcb;
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;
	_KERNEL_T_QUE    *pk_que;;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_DEL_FLG_E_ID
	if ( !_KERNEL_FLG_CHECK_FLGID(flgid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_DEL_FLG_E_NOEXS
	if ( !_KERNEL_FLG_CHECK_EXS(flgid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;	
	}
#endif
	
	/* %jp{コントロールブロック取得} */
	flgcb = _KERNEL_FLG_ID2FLGCB(flgid);
	
	/* %jp{待ち行列取得} */
	pk_que = _KERNEL_FLG_GET_QUE(flgcb);
	
	/* %jp{待ち行列のタスクを全て起床} */
	while ( (tskhdl = _KERNEL_RMH_QUE(pk_que)) != _KERNEL_TSKHDL_NULL )
	{
		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);	/* %jp{TCB取得} */
		_KERNEL_TSK_SET_ERCD(tcb, E_DLT);		/* %jp{エラーコード設定} */
		_KERNEL_FLG_RMV_TOQ(tskhdl);			/* %jp{タイムアウトキューから外す} */
		_KERNEL_DSP_WUP_TSK(tskhdl);			/* %jp{タスクの待ち解除} */	
	}
	
	/* %jp{オブジェクト削除} */
#if _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_PTRARRAY
	_KERNEL_SYS_FRE_HEP(_KERNEL_FLG_ID2FLGCB(flgid));	/* %jp{メモリ開放} */
	_KERNEL_FLG_ID2FLGCB(flgid) = NULL;
#elif _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_BLKARRAY
	_KERNEL_FLG_SET_FLGATR(flgcb, 0);					/* %jp{削除をマーク} */
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_DEL_FLG */


#if _KERNEL_SPT_DEL_FLG_E_NOSPT

/** %jp{イベントフラグの削除}%en{Delete Eventflag}
 * @param  flgid    %jp{削除対象のイベントフラグのID番号}%en{ID number of the eventflag to be deleted}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER del_flg(ID flgid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_DEL_FLG */



/* end of file */
