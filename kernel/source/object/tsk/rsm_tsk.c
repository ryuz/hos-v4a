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


#if _KERNEL_SPT_RSM_TSK


ER rsm_tsk(
		ID tskid)
{
	_KERNEL_T_TSKHDL      tskhdl;
	_KERNEL_T_TCB         *tcb;
	_KERNEL_TSK_T_TSKSTAT tskstat;
	_KERNEL_TSK_T_SUSCNT  suscnt;


#if _KERNEL_SPT_SUS_TSK_E_ID
	if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
	{
		return E_ID;	/* %jp{不正ID番号} */
	}
#endif
	
	_KERNEL_ENTER_SVC();			/* %jp{enter service-call}%jp{サービスコールに入る} */
		
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_SUS_TSK_E_NOEXS
	if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
		return E_NOEXS;				/* %jp{オブジェクト未生成} */
	}
#endif

	/* ID番号指定時の変換 */
	tskhdl = _KERNEL_TSK_ID2TSKHDL(tskid);
	
	/* %jp{コントロールブロック取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/* %jp{タスク状態取得} */
	tskstat = _KERNEL_TSK_GET_TSKSTAT(tcb);
	if ( !(tskstat & _KERNEL_TTS_SUS) )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{leave service-call}%jp{サービスコールを出る} */
		return E_OBJ;				
	}

	suscnt = _KERNEL_TSK_GET_SUSCNT(tcb);
	if ( suscnt > 0 )
	{
		_KERNEL_TSK_SET_SUSCNT(tcb, suscnt - 1);
	}
	else
	{
		_KERNEL_DSP_RSM_TSK(tskhdl);			/* %jp{タスクの強制待ち解除} */

		_KERNEL_DSP_TSK();
	}

	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */

	return E_OK;
}


#else	/* _KERNEL_SPT_RSM_TSK */


#if _KERNEL_SPT_RSM_TSK_E_NOSPT

ER rsm_tsk(
		ID tskid)
{
	return E_NOSPT;
}

#endif


#endif


/* end of file */
