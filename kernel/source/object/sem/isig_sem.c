/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  isig_sem.c
 * @brief %jp{セマフォ資源の返却}%en{Release Semaphore Resource}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/semobj.h"



#if _KERNEL_SPT_ISIG_SEM

#if _KERNEL_SPT_DPC

static void _kernel_dpc_sig_sem(void);

/** %jp{セマフォ資源の返却}%en{Release Semaphore Resource}
 * @param  semid    %jp{セマフォ資源返却対象のセマフォのID番号}%en{ID number of the semaphore to which resource is released}
 * @retval E_OK     %jp{正常終了}%en{Normal completion}
 * @retval E_ID     %jp{不正ID番号(semidが不正あるいは使用できない)}%en{Invalid ID number(semid is invalid or unusable)}
 * @retval E_NOMEM  %jp{遅延実行用のキューイングメモリ不足}%en{Insufficient memory to store a service call for delayed execution}
 */
ER isig_sem(ID semid)
{
	ER ercd;

	/* %jp{ID のチェック} */
#ifdef _KERNEL_SPT_ISIG_SEM_E_ID
	if ( !_KERNEL_SEM_CHECK_SEMID(semid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif

	_KERNEL_SYS_LOC_DPC();	/* %jp{多重割り込み対策でロックをかける} */

	if ( _KERNEL_SYS_RFR_DPC() >= 2 )
	{
		_KERNEL_SYS_SND_DPC((VP_INT)_kernel_dpc_sig_sem);
		_KERNEL_SYS_SND_DPC((VP_INT)semid);
		ercd = E_OK;		/* %jp{正常終了}%en{Normal completion} */
	}
	else
	{
		ercd = E_NOMEM;		/* %jp{遅延実行用のキューイングメモリ不足}%en{Insufficient memory to store a service call for delayed execution} */
	}

	_KERNEL_SYS_UNL_DPC();	/* jp{ロック解除} */
		
	return ercd;
}

/** %jp{sig_semの遅延実行}%en{service call for delayed execution(sig_sem)} */
void _kernel_dpc_sig_sem(void)
{
	_KERNEL_T_SEMCB_PTR  semcb;
	_KERNEL_T_TSKHDL     tskhdl;
	_KERNEL_T_TCB        *tcb;
	_KERNEL_SEM_T_SEMCNT semcnt;
	ID                   semid;
	
	/* %jp{パラメータ取り出し} */
	semid = (ID)_KERNEL_SYS_RCV_DPC();

	/* %jp{オブジェクト存在チェック} */
#ifdef _KERNEL_SPT_ISIG_SEM_E_NOEXS
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

		/* %jp{待ち解除発生をマーク} */
		_KERNEL_SYS_SET_DLY();		
	}
	else
	{
		/* %jp{セマフォカウンタ取得} */
		semcnt = _KERNEL_SEM_GET_SEMCNT(semcb);

		/* %jp{キューイングオーバーフローチェック} */
#ifdef _KERNEL_SPT_SIG_SEM_E_QOVR
		{
			_KERNEL_T_SEMCB_RO_PTR semcb_ro;

			semcb_ro = _KERNEL_SEM_GET_SEMCB_RO(semid, semcb);
			if ( semcnt >= _KERNEL_SEM_GET_MAXSEM(semcb_ro) )
			{
				return;		/* %jp{キューイングオーバーフロー}%en{Queue overflow} */
			}
		}
#endif
		
		/* %jp{セマフォ資源返却} */
		_KERNEL_SEM_SET_SEMCNT(semcb, semcnt + 1);
	}
}

#else	/* _KERNEL_SPT_DPC */

/** %jp{セマフォ資源の返却}%en{Release Semaphore Resource}
 * @param  semid    %jp{セマフォ資源返却対象のセマフォのID番号}%en{ID number of the semaphore to which resource is released}
 */
ER isig_sem(ID semid)
{
	return sig_sem(semid);
}

#endif	/* _KERNEL_SPT_DPC */


#else	/* _KERNEL_SPT_SIG_SEM */


#if _KERNEL_SPT_SIG_ISEM_E_NOSPT

/** %jp{セマフォ資源の返却}%en{Release Semaphore Resource}
 * @param  semid    %jp{セマフォ資源返却対象のセマフォのID番号}%en{ID number of the semaphore to which resource is released}
 * @retval E_NOSPT  %jp{未サポート機能}%en{Unsupported function}
 */
ER isig_sem(ID semid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_SIG_SEM */



/* end of file */
