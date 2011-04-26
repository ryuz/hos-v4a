/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  unl_mtx.c
 * @brief %jp{ミューテックスのロック解除}%en{Unlock mutex}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"



#if _KERNEL_SPT_UNL_MTX


/** %jp{ミューテックスのロック解除}%en{Unlock Mutex}
 * @param  mtxid    %jp{ロック解除対象のミューテックスID番号}%en{ID number of the mutex to be unlocked}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(mtxidが不正あるいは使用できない)}%en{Invalid ID number(mtxid is invalid or unusable)}
 * @retval E_CTX    %jp{コンテキストエラー}%en{Context error}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象ミューテックスが未登録)}%en{Non-existant object(specified mutex is not registerd)}
 * @retval E_ILUSE  %jp{サービスコール不正使用(対象ミューテックスをロックしていない)}%en{Illegal service call use(the invoking task does not have the specified mutex locked)}
 */
ER unl_mtx(ID mtxid)
{
	_KERNEL_T_MTXCB_PTR		mtxcb;
	_KERNEL_T_MTXHDL		mtxhdl;
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TSKHDL		tskhdl;
		
	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_UNL_MTX_E_CTX
	if ( _KERNEL_SYS_SNS_CTX() )
	{
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_UNL_MTX_E_ID
	if ( !_KERNEL_MTX_CHECK_MTXID(mtxid) )
	{
		return E_ID;			/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_UNL_MTX_E_NOEXS
	if ( !_KERNEL_MTX_CHECK_EXS(mtxid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif
	
	/* %jp{ミューテックスコントロールブロック取得} */
	mtxcb = _KERNEL_MTX_ID2MTXCB(mtxid);

	/* %jp{実行中のタスクハンドルを取得} */
	tskhdl = _KERNEL_SYS_GET_RUNTSK();
		
	/* %jp{自分が所有しているかチェック} */
#if _KERNEL_SPT_UNL_MTX_E_ILUSE
	if ( tskhdl != _KERNEL_MTX_GET_TSKHDL(mtxcb) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_ILUSE;			/* %jp{サービスコール不正使用}%en{Illegal service call use} */
	}
#endif
	
	tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	mtxhdl = _KERNEL_MTX_GET_MTXHDL(mtxid, mtxcb);
	
	/* %jp{ミューテックを取り外し} */
	_kernel_rmv_mtx(mtxhdl, tskhdl);
	
	/* %jp{所有ミューテックスが無くなったら} */
	if ( _KERNEL_TSK_GET_MTXHDL(tcb) == _KERNEL_MTXHDL_NULL )
	{
		/* %jp{優先度を元に戻す} */
		_KERNEL_TSK_SET_TSKPRI(tcb, _KERNEL_TSK_GET_TSKBPRI(tcb));		
		_KERNEL_SYS_RMV_RDQ(tskhdl);
		_KERNEL_SYS_ADD_RDQ(tskhdl);
	}
	
	/* %jp{タスクディスパッチの実行} */
	_KERNEL_DSP_TSK();

	_KERNEL_LEAVE_SVC();	/* %jp{オブジェクト未生成}%en{Non-existant object} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_UNL_MTX */


#if _KERNEL_SPT_UNL_MTX_E_NOSPT

/** %jp{ミューテックスのロック解除}%en{Unlock Mutex}
 * @param  mtxid    %jp{ロック解除対象のミューテックスID番号}%en{ID number of the mutex to be unlocked}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER unl_mtx(ID mtxid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_LOC_MTX */



/* end of file */
