/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rsm_tsk.c
 * @brief 
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


#if _KERNEL_SPT_ENA_TEX


/* %jp{タスク例外処理の禁止} */
ER ena_tex(void)
{
	_KERNEL_T_TSKHDL      tskhdl;
	_KERNEL_T_TCB         *tcb;

#if _KERNEL_SPT_ENA_TSK_E_CTX
	if ( _KERNEL_SYS_SNS_CTX() )
	{
		return E_CTX;
	}
#endif
	
	_KERNEL_ENTER_SVC();			/* %jp{enter service-call}%jp{サービスコールに入る} */
		

	/* %jp{実行中タスクを取得} */
	tskhdl = _KERNEL_SYS_GET_RUNTSK();
	
	/* %jp{コントロールブロック取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	_KERNEL_TSK_SET_TEXSTAT(tcb, _KERNEL_TXS_ENA);
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */

	return E_OK;
}


#else	/* _KERNEL_SPT_ENA_TEX */


#if _KERNEL_SPT_ENA_TEX_E_NOSPT

ER ena_tex(void)
{
	return E_NOSPT;
}

#endif


#endif


/* end of file */
