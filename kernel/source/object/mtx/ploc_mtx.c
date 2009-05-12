/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ploc_mtx.c
 * @brief %jp{ミューテックスのロック獲得(ポーリング)}%en{Lock Mutex(Polling)}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mtxobj.h"



#if _KERNEL_SPT_PLOC_MTX


#if _KERNEL_SPT_KLOC_MTX && (_KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED)	/* %jp{コードサイズ優先で統合ありなら} */

/** %jp{ミューテックスのロック獲得}%en{Lock Mutex}
 * @param  mtxid    %jp{ロック対象のミューテックスID番号}%en{ID number of the mutex to be locked}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(mtxidが不正あるいは使用できない)}%en{Invalid ID number(mtxid is invalid or unusable)}
 * @retval E_CTX    %jp{コンテキストエラー}%en{Context error}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象ミューテックスが未登録)}%en{Non-existant object(specified mutex is not registerd)}
 * @retval E_ILUSE  %jp{サービスコール不正使用(ミューテックスの多重ロック，上限優先度の違反)}%en{Illegal service call use(multiple locking of a mutex, ceiling priority violation)}
 * @retval E_TMOUT  %jp{タイムアウト}%en{Timeout}
 */
ER ploc_mtx(ID mtxid)
{
	/* %jp{pol_mtxやtloc_mtxと共通処理とする} */
	return _kernel_loc_mtx(mtxid, TMO_POL);
}

#else

/** %jp{ミューテックスのロック獲得}%en{Lock Mutex}
 * @param  mtxid    %jp{ロック対象のミューテックスID番号}%en{ID number of the mutex to be locked}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(mtxidが不正あるいは使用できない)}%en{Invalid ID number(mtxid is invalid or unusable)}
 * @retval E_CTX    %jp{コンテキストエラー}%en{Context error}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象ミューテックスが未登録)}%en{Non-existant object(specified mutex is not registerd)}
 * @retval E_ILUSE  %jp{サービスコール不正使用(ミューテックスの多重ロック，上限優先度の違反)}%en{Illegal service call use(multiple locking of a mutex, ceiling priority violation)}
 * @retval E_TMOUT  %jp{タイムアウト}%en{Timeout}
 */
ER ploc_mtx(ID mtxid)
{
	_KERNEL_T_MTXCB_RO_PTR	mtxcb_ro;
	_KERNEL_T_MTXCB_PTR		mtxcb;
	_KERNEL_T_MTXHDL		mtxhdl;
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TSKHDL		tskhdl;
	_KERNEL_T_TSKHDL		tskhdl_lock;
	ER						ercd;
	
	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_LOC_MTX_E_CTX
	if ( _KERNEL_SYS_SNS_DPN() )
	{
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_PLOC_MTX_E_ID
	if ( !_KERNEL_MTX_CHECK_MTXID(mtxid) )
	{
		return E_ID;			/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_PLOC_MTX_E_NOEXS
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
	
	/* %jp{ロック中のタスクハンドル取得} */
	tskhdl_lock = _KERNEL_MTX_GET_TSKHDL(mtxcb);

	if ( _KERNEL_MTX_GET_TSKHDL(mtxcb) == _KERNEL_TSKHDL_NULL )
	{
		/* %jp{所有タスクが居なければミューテックスをロック} */
		_KERNEL_MTX_SET_TSKHDL(mtxcb, tskhdl); 		/* %jp{ミューテックス資源の獲得} */

		/* %jp{ミューテックスをTCBに接続} */
		mtxhdl = _KERNEL_MTX_GET_MTXHDL(mtxid, mtxcb);
		_kernel_add_mtx(mtxhdl, tskhdl);
		
#if _KERNEL_SPT_MTX_TA_CEILING
		if ( _KERNEL_MTX_GET_MTXATR(mtxcb_ro) == TA_CEILING )
		{
			/* %jp{タスクの優先度をシーリング値まで引き上げ} */
			if ( _KERNEL_TSK_GET_TSKPRI(tcb) < _KERNEL_MTX_GET_CEILPRI(mtxcb_ro) )
			{
				_KERNEL_TSK_SET_TSKPRI(tcb, _KERNEL_MTX_GET_CEILPRI(mtxcb_ro));
			}
		}
#endif
		
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


#else	/* _KERNEL_SPT_PLOC_MTX */


#if _KERNEL_SPT_PLOC_MTX_E_NOSPT

/** %jp{ミューテックスのロック獲得}%en{Lock Mutex}
 * @param  mtxid    %jp{ロック対象のミューテックスID番号}%en{ID number of the mutex to be locked}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER ploc_mtx(ID mtxid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_PLOC_MTX */



/* end of file */
