/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  slp_tsk.c
 * @brief %jp{タスクの起床待ち}%en{Sleep Task}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{タスクの起床待ち}%en{Sleep Task}
 * @retval E_OK  %jp{成功}
 */
ER slp_tsk(void)
{
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;
	ER               ercd;

	
	/* %jp{実行中タスクを取得} */
	tskhdl = _KERNEL_SYS_GET_RUNTSK();
	
	_KERNEL_ENTER_SVC();		/* %jp{enter service-call}%jp{サービスコールに入る} */

	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
#if _KERNEL_TCB_WUPCNT
	{
		_KERNEL_TSK_T_WUPCNT wupcnt;

		/* %jp{起床要求のキューイングをチェック} */
		wupcnt = _KERNEL_TSK_GET_WUPCNT(tcb);
		if ( wupcnt > 0 )
		{
			_KERNEL_TSK_SET_WUPCNT(tcb, wupcnt - 1);
			_KERNEL_LEAVE_SVC();
			return E_OK;		/* %jp{キューイングオーバーフロー} */
		}
	}
#endif
	
	/* %jp{タスクを待ち状態にする} */
	_KERNEL_TSK_SET_TSKSTAT(tcb, _KERNEL_TTS_WAI);
	_KERNEL_TSK_SET_TSKWAIT(tcb, _KERNEL_TTW_SLP);
	_KERNEL_DSP_WAI_TSK(tskhdl);
	
	/* %jp{タスクディスパッチの実行} */
	_KERNEL_DSP_TSK();
	
	/* %jp{エラーコードの取得} */
	ercd = _KERNEL_TSK_GET_ERCD(tcb);
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
	
	return ercd;
}


/* end of file */
