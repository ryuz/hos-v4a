/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  loc_mtx.c
 * @brief %jp{ミューテックスのロック}%en{Lock mutex}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"



#if _KERNEL_SPT_LOC_MTX


#if _KERNEL_SPT_KLOC_MTX && (_KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED)	/* %jp{コードサイズ優先で統合ありなら} */

/** %jp{ミューテックスのロック獲得} */
ER loc_mtx(ID mtxid)
{
	/* %jp{pol_mtxやtloc_mtxと共通処理とする} */
	return _kernel_loc_mtx(mtxid, TMO_FEVR);
}

#else

/** %jp{ミューテックスのロック獲得} */
ER loc_mtx(ID mtxid)
{
	_KERNEL_T_MTXCB_PTR    mtxcb;
	_KERNEL_T_MTXCB_RO_PTR mtxcb_ro;
	_KERNEL_T_TSKHDL       tskhdl;
	_KERNEL_T_TCB          *tcb;
	_KERNEL_T_TSKHDL       loc_tskhdl;
	ER                     ercd;
		
	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_LOC_MTX_E_CTX
	if ( _KERNEL_SYS_SNS_DPN() )
	{
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif

	/* %jp{ID のチェック} */
#if _KERNEL_SPT_LOC_MTX_E_ID
	if ( !_KERNEL_MTX_CHECK_MTXID(mtxid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_LOC_MTX_E_NOEXS
	if ( !_KERNEL_MTX_CHECK_EXS(mtxid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif

	/* %jp{ミューテックスコントロールブロック取得} */
	mtxcb    = _KERNEL_MTX_ID2MTXCB(mtxid);
	mtxcb_ro = _KERNEL_MTX_GET_MTXCB_RO(mtxid, mtxcb);

	/* %jp{実行中のタスクハンドルを取得} */
	tskhdl = _KERNEL_SYS_GET_RUNTSK();
	tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* ロック中のタスクハンドル取得 */
	loc_tskhdl = _KERNEL_MTX_GET_TSKHDL(mtxcb);

	if ( _KERNEL_MTX_GET_TSKHDL(mtxcb) == _KERNEL_TSKHDL_NULL )
	{
		/* %jp{所有タスクが居なければミューテックスをロック} */
		_KERNEL_MTX_SET_TSKHDL(mtxcb, tskhdl); 		/* %jp{ミューテックス資源の獲得} */

		/* %jp{ミューテックスをTCBに接続} */


#if _KERNEL_SPT_MTX_TA_CEILING
		/* %jp{タスクの優先度をシーリング値まで引き上げ} */
		if ( _KERNEL_TSK_GET_TSKPRI(tcb) < _KERNEL_MTX_GET_CEILPRI(mtxcb_ro) )
		{
			_KERNEL_TSK_SET_TSKPRI(tcb, _KERNEL_MTX_GET_CEILPRI(mtxcb_ro));
		}
#endif
		
		ercd = E_OK;
	}
	else
	{
		/* %jp{タスクを待ち状態にする} */
		_KERNEL_TSK_SET_TSKWAIT(tcb, _KERNEL_TTW_MTX);
		_KERNEL_TSK_SET_WOBJID(tcb, mtxid);
		_KERNEL_DSP_WAI_TSK(tskhdl);
		_KERNEL_MTX_ADD_QUE(mtxcb, _KERNEL_MTX_GET_MTXCB_RO(mtxid, mtxcb), tskhdl);			/* %jp{待ち行列に追加} */

#if _KERNEL_MTX_TA_INHERIT
		{
			_KERNEL_T_TSKHDL loc_tcb;

			/* %jp{ロック中タスクのTCB取得} */
			loc_tcb = _KERNEL_TSK_TSKHDL2TCB(loc_tskhdl);

			/* %jp{優先度継承} */
			if ( _KERNEL_TSK_GET_TSKPRI(loc_tcb) > _KERNEL_TSK_GET_TSKPRI(tcb) )
			{
				_KERNEL_TSK_SET_TSKPRI(loc_tcb, _KERNEL_TSK_GET_TSKPRI(tcb))
			}
		}
#endif

		/* %jp{タスクディスパッチの実行} */
		_KERNEL_DSP_TSK();

		/* %jp{エラーコードの取得} */
		ercd = _KERNEL_TSK_GET_ERCD(tcb);
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{オブジェクト未生成}%en{Non-existant object} */
	
	return ercd;
}

#endif


#else	/* _KERNEL_SPT_LOC_MTX */


#if _KERNEL_SPT_LOC_MTX_E_NOSPT

/** %jp{ミューテックス資源の獲得}%en{Acquire Mutex Resource}
 * @param  mtxid    %jp{資源獲得対象のミューテックスID番号}%en{ID number of the mutex from which resource is acquired}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER loc_mtx(ID mtxid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_LOC_MTX */



/* end of file */
