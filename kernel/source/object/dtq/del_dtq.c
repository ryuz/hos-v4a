/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  del_que.c
 * @brief %jp{データキューの削除}%en{Delete Data queue}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/dtqobj.h"



#if _KERNEL_SPT_DEL_DTQ


/** %jp{セマフォの削除}%en{Delete Data queue}
 * @param  dtqid    %jp{削除対象のセマフォのID番号}%en{ID number of the data queue to be deleted}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(dtqidが不正あるいは使用できない)}%en{Invalid ID number(dtqid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象セマフォが未登録)}%en{Non-existant object(specified data queue is not registerd)}
 */
ER del_dtq(ID dtqid)
{
	_KERNEL_T_DTQCB		*dtqcb;
	_KERNEL_T_QUE		*que;
	_KERNEL_T_TSKHDL	tskhdl;
	_KERNEL_T_TCB		*tcb;
	
	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_DEL_DTQ_E_ID
	if ( !_KERNEL_DTQ_CHECK_DTQID(dtqid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_DEL_DTQ_E_NOEXS
	if ( !_KERNEL_DTQ_CHECK_EXS(dtqid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;
	}
#endif
	
	/* %jp{セマフォコントロールブロック取得} */
	dtqcb = _KERNEL_DTQ_ID2DTQCB(dtqid);
	
	/* %jp{送信待ち行列のタスクを全て起床} */
	que = _KERNEL_DTQ_GET_SQUE(dtqcb);
	while ( (tskhdl = _KERNEL_RMH_QUE(que)) != _KERNEL_TSKHDL_NULL )
	{
		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
		_KERNEL_TSK_SET_ERCD(tcb, E_DLT);			/* %jp{エラーコード設定} */
		_KERNEL_DTQ_RMV_STOQ(tskhdl);				/* %jp{タイムアウトキューから外す} */
		_KERNEL_DSP_WUP_TSK(tskhdl);				/* %jp{タスクの待ち解除} */	
	}
	
	/* %jp{受信待ち行列のタスクを全て起床} */
	que = _KERNEL_DTQ_GET_RQUE(dtqcb);
	while ( (tskhdl = _KERNEL_RMH_QUE(que)) != _KERNEL_TSKHDL_NULL )
	{
		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
		_KERNEL_TSK_SET_ERCD(tcb, E_DLT);			/* %jp{エラーコード設定} */
		_KERNEL_DTQ_RMV_RTOQ(tskhdl);				/* %jp{タイムアウトキューから外す} */
		_KERNEL_DSP_WUP_TSK(tskhdl);				/* %jp{タスクの待ち解除} */	
	}
	
	/* %jp{オブジェクト削除} */
#if _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_PTRARRAY
	_KERNEL_SYS_FRE_HEP(dtqcb);						/* %jp{メモリ開放} */
	_KERNEL_DTQ_ID2DTQCB(dtqid) = NULL;
#elif _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_BLKARRAY
	_KERNEL_DTQ_SET_MAXDTQ(dtqcb, 0);
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_DEL_DTQ */


#if _KERNEL_SPT_DEL_DTQ_E_NOSPT

/** %jp{セマフォの削除}%en{Delete Data queue}
 * @param  dtqid    %jp{削除対象のセマフォのID番号}%en{ID number of the data queue to be deleted}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER del_dtq(ID dtqid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_DEL_DTQ */



/* end of file */
