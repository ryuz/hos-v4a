/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dly_tsk.c
 * @brief %jp{自タスクの遅延}%en{Delay Task}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{自タスクの遅延}%en{Delay Task}
 * @retval E_OK  %jp{成功}
 */
ER dly_tsk(RELTIM dlytim)
{
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;
	ER               ercd;
	
	/* %jp{実行中タスクを取得} */
	tskhdl = _KERNEL_SYS_GET_RUNTSK();
	
	_KERNEL_ENTER_SVC();		/* %jp{enter service-call}%jp{サービスコールに入る} */
		
	/* %jp{コンテキストチェック} */
#if _KERNEL_SPT_DLY_TSK_E_CTX
	if ( _KERNEL_SYS_SNS_DPN() )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_CTX;			/* %jp{コンテキストエラー}%en{Context error} */
	}
#endif

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{タスクを待ち状態にする} */
	_KERNEL_DSP_WAI_TSK(tskhdl);
	_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_WAI);
	_KERNEL_TSK_SET_TSKWAIT(tcb, _KERNEL_TTW_DLY);

	/* %jp{タイムアウトキューに繋ぐ} */
	_KERNEL_SYS_ADD_TOQ(tskhdl, dlytim);
	
	/* %jp{タスクディスパッチの実行} */
	_KERNEL_DSP_TSK();
	
	/* %jp{エラーコードの取得} */
	ercd = _KERNEL_TSK_GET_ERCD(tcb);
	if ( ercd == E_TMOUT )
	{
		ercd = E_OK;
	}

	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
	
	return ercd;
}


/* end of file */
