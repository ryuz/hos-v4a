/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  wup_tsk.c
 * @brief %jp{タスクの起床}%en{Wakeup Task}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



ER can_wup(
		ID tskid)
{
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;

	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
#if _KERNEL_SPT_CAN_WUP_E_ID
		if ( _KERNEL_SYS_SNS_CTX() )
		{
			return E_ID;		/* %jp{不正ID番号} */
		}
#endif	
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();

		_KERNEL_ENTER_SVC();		/* %jp{enter service-call}%jp{サービスコールに入る} */
	}
	else
	{
#if _KERNEL_SPT_CAN_WUP_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
		
		_KERNEL_ENTER_SVC();			/* %jp{enter service-call}%jp{サービスコールに入る} */
		
		/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_CAN_WUP_E_NOEXS
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
			return E_NOEXS;			/* %jp{オブジェクト未生成} */
		}
#endif
		/* ID番号指定時の変換 */
		tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	}
	
	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{待ちカウンタクリア} */
	_KERNEL_TSK_SET_WUPCNT(tcb, 0);


	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */

	return E_OK;
}


/* end of file */
