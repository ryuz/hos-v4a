/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  twai_sem.c
 * @brief %jp{セマフォ資源の獲得(統合版)}%en{Acquire Semaphore Resource}
 *
 * @version $Id: kwai_sem.c,v 1.1 2006-08-16 16:27:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/semobj.h"




/** %jp{セマフォ資源の獲得(統合版)}%en{Acquire Semaphore Resource}
 * @param  semid    %jp{資源獲得対象のセマフォID番号}%en{ID number of the semaphore from which resource is acquired}
 * @param  tmout    %jp{タイムアウト指定}%en{Specified timeout}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(semid is invalid or unusable)}
 * @retval E_CTX    %jp{コンテキストエラー}%en{Context error}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象セマフォが未登録)}%en{Non-existant object(specified semaphore is not registerd)}
 * @retval E_RLWAI  %jp{待ち状態の強制解除(待ち状態の間にrel_waiを受付)}%en{Forced release from waiting(accept rel_wai while waiting)}
 * @retval E_TMOUT  %jp{タイムアウト}%en{Timeout}
 * @retval E_DLT    %jp{待ちオブジェクトの削除(待ち状態の間に対象セマフォが削除)}%en{Waiting object deleted(semaphore is deleted waiting)}
 */
ER _kernel_wai_sem(ID semid, TMO tmout)
{
	_KERNEL_T_SEMHDL     semhdl;
	_KERNEL_T_TSKHDL     tskhdl;
	_KERNEL_SEM_T_SEMCNT semcnt;
	ER                   ercd;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_KWAI_SEM_E_ID
	if ( !_KERNEL_SEM_CHECK_SEMID(semid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_KWAI_SEM_E_CTX
	if ( tmout != TMO_POL && _KERNEL_SYS_SNS_DPN() )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif
	
	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_KWAI_SEM_E_NOEXS
	if ( !_KERNEL_SEM_CHECK_EXS(semid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;			/* %jp{オブジェクト未生成}%en{Non-existant object} */
	}
#endif

	/* %jp{セマフォハンドル取得} */
	semhdl = _KERNEL_SEM_ID2SEMHDL(semid);
	
	/* %jp{セマフォカウンタ取得} */
	semcnt = _KERNEL_SEM_GET_SEMCNT(semhdl);
	
	if ( semcnt > 0 )
	{
		/* %jp{セマフォ資源が獲得できれば成功} */
		_KERNEL_SEM_SET_SEMCNT(semhdl, semcnt - 1); 		/* %jp{セマフォ資源の獲得} */
		ercd = E_OK;
	}
	else
	{
#if _KERNEL_SPT_TWAI_SEM || _KERNEL_SPT_POL_SEM
		if ( tmout == TMO_POL )
		{
			ercd = E_TMOUT;  /* %jp{タイムアウト}%en{Timeout} */
		}
		else
#endif
		{
			/* %jp{タスクを待ち状態にする} */
			tskhdl = _KERNEL_SYS_GET_RUNTSK();
			_KERNEL_DSP_WAI_TSK(tskhdl);
			_KERNEL_TSK_SET_TSKWAIT(tskhdl, _KERNEL_TTW_SEM);
			_KERNEL_TSK_SET_WOBJID(tskhdl, semid);
			_KERNEL_SEM_ADD_QUE(semhdl, tskhdl);				/* %jp{待ち行列に追加} */
			
#if _KERNEL_SPT_TWAI_SEM
			if ( tmout != TMO_FEVR )
			{
				_KERNEL_SEM_ADD_TOQ(tskhdl, tmout);				/* %jp{タイムアウトキューに追加} */
			}
#endif

			/* %jp{タスクディスパッチの実行} */
			_KERNEL_DSP_TSK();

			/* %jp{エラーコードの取得} */
			ercd = _KERNEL_TSK_GET_ERCD(tskhdl);
		}
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{オブジェクト未生成}%en{Non-existant object} */
	
	return ercd;
}


/* end of file */
