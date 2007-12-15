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



/** %jp{タスク優先度の変更} */
ER chg_pri(ID tskid, PRI tskpri)
{
	_KERNEL_T_TSKHDL   tskhdl;
	_KERNEL_T_TCB_PTR  tcb;
	_KERNEL_TSK_T_TPRI tskpri_old;

	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
#if _KERNEL_SPT_CHG_PRI_E_ID
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
#if _KERNEL_SPT_CHG_PRI_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
		
		_KERNEL_ENTER_SVC();			/* %jp{サービスコールに入る}%en{enter service-call} */
		
		/* %jp{オブジェクト存在チェック} */
#ifdef _KERNEL_SPT_CHG_PRI_E_NOEXS
		if ( _KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();		/* %jp{サービスコールを出る}%en{leave service-call} */
			return E_NOEXS;				/* %jp{オブジェクト未生成} */
		}
#endif
		/* ID番号指定時の変換 */
		tcb    = _KERNEL_TSK_ID2TCB(tskid);
		tskhdl = _KERNEL_TSK_GET_TSKHDL(tskid, tcb);
	}
	

#ifdef _KERNEL_SPT_CHG_TPRI_INI
	if ( tskpri == TPRI_INI )
	{
		_KERNEL_T_TCB_RO_PTR tcb_ro;
		tcb_ro = _KERNEL_TSK_GET_TCB_RO(tskid, tcb);
		tskpri = _KERNEL_TSK_GET_ITSKPRI(tcb_ro);
	}
#endif
	
	
	/* %jp{ベース優先度変更} */
	_KERNEL_TSK_SET_TSKBPRI(tcb, tskpri);
	
	/* %jp{現在のタスク優先度を取得} */
	tskpri_old = _KERNEL_TSK_GET_TSKPRI(tcb);
	
	/* %jp{優先度が上がるか、ミューテックス不所持なら優先度変更} */
	if ( tskpri < (PRI)tskpri_old || _KERNEL_TSK_GET_MTXHDL(tcb) == _KERNEL_MTXHDL_NULL )
	{
		/* %jp{現在のタスク優先度を変更} */
		_kernel_chg_pri(tskhdl, tskpri);
		
		/* %jp{タスクディスパッチ} */
		_KERNEL_DSP_STA_TSK(tskhdl);
	}
	
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
	
	return E_OK;
}


/* end of file */
