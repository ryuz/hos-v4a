/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  chg_pri.c
 * @brief %jp{タスク優先度の変更}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %jp{タスク優先度の参照} */
ER get_pri(ID tskid, PRI *p_tskpri)
{
	_KERNEL_T_TSKHDL   tskhdl;
	_KERNEL_T_TCB_PTR  tcb;

	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{

#if _KERNEL_SPT_REF_TSK_E_ID
		if ( _KERNEL_SYS_SNS_CTX() )
		{
			return E_ID;		/* %jp{不正ID番号} */
		}
#endif	
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();

		_KERNEL_ENTER_SVC();		/* %jp{enter service-call}%jp{サービスコールに入る} */

		/* %jp{TCBを取得} */
		tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	}
	else
	{
#if _KERNEL_SPT_REF_TSK_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
		
		_KERNEL_ENTER_SVC();			/* %jp{enter service-call}%jp{サービスコールに入る} */
		
		/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_REF_TSK_E_NOEXS
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
			return E_NOEXS;				/* %jp{オブジェクト未生成} */
		}
#endif
		/* ID番号指定時の変換 */
		tcb    = _KERNEL_TSK_ID2TCB(tskid);
		tskhdl = _KERNEL_TSK_GET_TSKHDL(tskid, tcb);
	}
	
	/* %jp{優先度取得} */
	*p_tskpri = _KERNEL_TSK_GET_TSKBPRI(tcb);

	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */

	return E_OK;
}


/* end of file */
