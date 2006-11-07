/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ref_flg.c
 * @brief %jp{イベントフラグの状態参照}%en{Reference Semaphore State}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/flgobj.h"



#if _KERNEL_SPT_REF_FLG


/** %jp{イベントフラグの状態参照}%en{Reference Semaphore State}
 * @param  flgid    %jp{資源獲得対象のイベントフラグID番号}%en{ID number of the flgaphore from which resource is acquired}
 * @param  pk_rflg  %jp{イベントフラグ状態を返すパケットへのポインタ}%en{Pointer to the packet returning the flgaphore state}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(flgidが不正あるいは使用できない)}%en{Invalid ID number(flgid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象イベントフラグが未登録)}%en{Non-existant object(specified flgaphore is not registerd)}
 * @retval E_PAR    %jp{パラメータエラー(pk_rflgが不正)}%en{Parameter error(pk_rflg is invalid)}
 */
ER ref_flg(ID flgid, T_RFLG *pk_rflg)
{
	_KERNEL_T_FLGCB *flgcb;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_REF_FLG_E_ID
	if ( !_KERNEL_FLG_CHECK_FLGID(flgid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
#if _KERNEL_SPT_REF_FLG_E_PAR
	if ( pk_rflg == NULL )
	{
		return E_PAR;	/* %jp{パラメータエラー}%en{Parameter error} */
	}
#endif
		
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_REF_FLG_E_NOEXS
	if ( !_KERNEL_FLG_CHECK_EXS(flgid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif

	/* %jp{コントロールブロック取得} */
	flgcb = _KERNEL_FLG_ID2FLGCB(flgid);
	
	/* %jp{情報取得} */
	pk_rflg->wtskid = _KERNEL_TSK_GET_TSKID(_KERNEL_REF_QUE(_KERNEL_FLG_GET_QUE(flgcb)));
	pk_rflg->flgptn = _KERNEL_FLG_GET_FLGPTN(flgcb);
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;
}


#else	/* _KERNEL_SPT_REF_FLG */


#if _KERNEL_SPT_REF_FLG_E_NOSPT

/** %jp{イベントフラグ資源の獲得(ポーリング)}%en{Acquire Semaphore Resource(Polling)}
 * @param  flgid    %jp{資源獲得対象のイベントフラグID番号}%en{ID number of the flgaphore from which resource is acquired}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER ref_flg(ID flgid, T_RFLG *pk_rflg)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_REF_FLG */



/* end of file */
