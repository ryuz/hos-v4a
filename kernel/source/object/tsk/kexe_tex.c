/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  def_tex.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


/* %jp{タスク例外処理の実行} */
void _kernel_exe_tex(_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TCB_RO_PTR	tcb_ro;
	_KERNEL_TSK_T_TEXPTN	rasptn;
	_KERNEL_TSK_T_TEXRTN	texrtn;
	_KERNEL_TSK_T_EXINF		exinf;
	
	
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
	
	/* %jp{タスク例外処理禁止なら何もしない} */
	if ( _KERNEL_TSK_GET_TEXSTAT(tcb) != _KERNEL_TXS_ENA )
	{
		return;
	}
	
	/* %jp{タスク例外要因がなければ何もしない} */
	if ( (rasptn = _KERNEL_TSK_GET_RASPTN(tcb)) == 0 )
	{
		return;
	}
	
	tcb_ro = _KERNEL_TSK_GET_TCB_RO(_KERNEL_TSK_TSKHDL2ID(tskhdl_run), tcb);
	exinf  = _KERNEL_TSK_GET_EXINF(tcb_ro);
	
	/* %jp{例外要因が無くなるまで実行} */
	do
	{
		_KERNEL_TSK_SET_TEXSTAT(tcb, _KERNEL_TXS_DIS);
		_KERNEL_TSK_SET_RASPTN(tcb, 0);
				
		texrtn = _KERNEL_TSK_GET_TEXRTN(tcb_ro);
				
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */

		/* %jp{タスク例外処理呼び出し} */
		texrtn((TEXPTN)rasptn, (VP_INT)exinf);

		_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	} while ( (rasptn = _KERNEL_TSK_GET_RASPTN(tcb)) != 0 );

	_KERNEL_TSK_SET_TEXSTAT(tcb, _KERNEL_TXS_ENA);
}


/* end of file */
