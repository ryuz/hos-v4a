/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_sem.c
 * @brief %jp{セマフォ資源の返却}%en{Release Semaphore Resource}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/semobj.h"



#if _KERNEL_SPT_SIG_SEM


/** %jp{セマフォ資源の返却}%en{Release Semaphore Resource}
 * @param  semid    %jp{セマフォ資源返却対象のセマフォのID番号}%en{ID number of the semaphore to which resource is released}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(semid is invalid or unusable)}
 * @retval E_NOEXS  %jp{オブジェクト未生成(対象セマフォが未登録)}%en{Non-existant object(specified semaphore is not registerd)}
 * @retval E_QOVR   %jp{キューイングオーバーフロー(最大資源数を越える返却)}%en{Queue overflow(release will exceed maximum resource count)}
 */
ER sig_sem(ID semid)
{
	_KERNEL_T_SEMCB_PTR  semcb;
	_KERNEL_T_TSKHDL     tskhdl;
	_KERNEL_T_TCB        *tcb;
	_KERNEL_SEM_T_SEMCNT semcnt;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_SIG_SEM_E_ID
	if ( !_KERNEL_SEM_CHECK_SEMID(semid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_SIG_SEM_E_NOEXS
	if ( !_KERNEL_SEM_CHECK_EXS(semid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{セマフォコントロールブロック取得} */
	semcb = _KERNEL_SEM_ID2SEMCB(semid);
	
	/* %jp{待ち行列先頭からタスク取り出し} */
	tskhdl = _KERNEL_SEM_RMH_QUE(semcb);
	if ( tskhdl != _KERNEL_TSKHDL_NULL )
	{
		/* %jp{待ちタスクがあれば待ち解除} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);		/* %jp{TCB取得} */
		_KERNEL_TSK_SET_ERCD(tcb, E_OK);			/* %jp{エラーコード設定} */
		_KERNEL_DSP_WUP_TSK(tskhdl);				/* %jp{タスクの待ち解除} */
		_KERNEL_SEM_RMV_TOQ(tskhdl);
		
		/* %jp{タスクディスパッチの実行} */
		_KERNEL_DSP_TSK();
	}
	else
	{
		/* %jp{セマフォカウンタ取得} */
		semcnt = _KERNEL_SEM_GET_SEMCNT(semcb);

		/* %jp{キューイングオーバーフローチェック} */
#if _KERNEL_SPT_SIG_SEM_E_QOVR
		{
			_KERNEL_T_SEMCB_RO_PTR semcb_ro;

			semcb_ro = _KERNEL_SEM_GET_SEMCB_RO(semid, semcb);
			if ( semcnt >= _KERNEL_SEM_GET_MAXSEM(semcb_ro) )
			{
				_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
				return E_QOVR;			/* %jp{キューイングオーバーフロー}%en{Queue overflow} */
			}
		}
#endif
		
		/* %jp{セマフォ資源返却} */
		_KERNEL_SEM_SET_SEMCNT(semcb, semcnt + 1);
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;	/* %jp{正常終了}%en{Normal completion} */
}


#else	/* _KERNEL_SPT_SIG_SEM */


#if _KERNEL_SPT_SIG_SEM_E_NOSPT

/** %jp{セマフォ資源の返却}%en{Release Semaphore Resource}
 * @param  semid    %jp{セマフォ資源返却対象のセマフォのID番号}%en{ID number of the semaphore to which resource is released}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER sig_sem(ID semid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_SIG_SEM */



/* end of file */
