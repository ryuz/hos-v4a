/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  del_mtx.c
 * @brief %jp{ミューテックスの削除}%en{Delete Mutex}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/mtxobj.h"



#if _KERNEL_SPT_DEL_MTX


/** %jp{ミューテックスの削除}%en{Delete Mutex}
 * @param  mtxid    %jp{削除対象のミューテックスのID番号}%en{ID number of the mutex to be deleted}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(mtxidが不正あるいは使用できない)}%en{Invalid ID number(mtxid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象ミューテックスが未登録)}%en{Non-existant object(specified mutex is not registerd)}
 */
ER del_mtx(ID mtxid)
{
	_KERNEL_T_MTXCB  *mtxcb;
	_KERNEL_T_QUE    *pk_que;
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;

	/* %jp{IDチェック}%en{check ID} */
#if _KERNEL_SPT_DEL_MTX_E_ID
	if ( !_KERNEL_MTX_CHECK_MTXID(mtxid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}	
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{存在チェック}%en{check object} */
#if _KERNEL_SPT_DEL_MTX_E_NOEXS
	if ( !_KERNEL_MTX_CHECK_EXS(mtxid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			
	}
#endif
	
	/* %jp{ミューテックスコントロールブロック取得} */
	mtxcb = _KERNEL_MTX_ID2MTXCB(mtxid);
	
	/* %jp{待ち行列取得} */
	pk_que = _KERNEL_MTX_GET_QUE(mtxcb);
	
	/* %jp{待ち行列のタスクを全て起床} */
	while ( (tskhdl = _KERNEL_RMH_QUE(pk_que)) != _KERNEL_TSKHDL_NULL )
	{
		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
		_KERNEL_TSK_SET_ERCD(tcb, E_DLT);			/* %jp{エラーコード設定} */
		_KERNEL_MTX_RMV_TOQ(tskhdl);				/* %jp{タイムアウトキューから外す} */
		_KERNEL_DSP_WUP_TSK(tskhdl);				/* %jp{タスクの待ち解除} */	
	}
	
	/* %jp{オブジェクト削除} */
#if _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_PTRARRAY
	_KERNEL_SYS_FRE_HEP(mtxcb);						/* %jp{メモリ開放} */
	_KERNEL_MTX_ID2MTXCB(mtxid) = NULL;
#elif _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_BLKARRAY
	_KERNEL_MTX_SET_MTXATR(mtxcb, 0);
#endif

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_DEL_MTX */


#if _KERNEL_SPT_DEL_MTX_E_NOSPT

/** %jp{ミューテックスの削除}%en{Delete Mutex}
 * @param  mtxid    %jp{削除対象のミューテックスのID番号}%en{ID number of the mutex to be deleted}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER del_mtx(ID mtxid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_DEL_MTX */



/* end of file */
