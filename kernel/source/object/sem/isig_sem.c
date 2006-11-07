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
 * @retval E_NOMEM  %jp{遅延実行用のキューイングメモリ不足}%en{Insufficient memory to store a service call for delayed execution}
 */
ER isig_sem(ID semid)
{
	ER ercd;

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
	ID semid;
	
	/* %jp{パラメータ取り出し} */
	semid = (ID)_KERNEL_SYS_RCV_DPC();
	
	/* %jp{遅延実行} */
	sig_sem(semid);
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
