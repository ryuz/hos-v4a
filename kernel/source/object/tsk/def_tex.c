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


/* %jp{タスク例外処理ルーチンの定義} */
ER def_tex(ID tskid, T_DTEX *pk_dtex)
{
	_KERNEL_T_TCB		*tcb;
	_KERNEL_T_TCB_RO	*tcb_ro;
	
	
	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
		_KERNEL_T_TSKHDL	tskhdl;
		
#ifdef _KERNEL_SPT_DEF_TEX_E_ID
		if ( _KERNEL_SYS_SNS_CTX() )
		{
			return E_ID;			/* %jp{不正ID番号} */
		}
#endif
		
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();

		_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */

		tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);
		tcb_ro = _KERNEL_TSK_GET_TCB_RO(_KERNEL_TSK_TSKHDL2ID(tskhdl), tcb);

	}
	else
	{
		/* %jp{IDチェック} */
#if _KERNEL_SPT_DEF_TEX_E_ID
		if ( !_KERNEL_TSK_CHECK_TSKID(tskid) )
		{
			return E_ID;			/* %jp{不正ID番号} */
		}
#endif	

		_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
		/* %jp{タスク存在チェック} */
#if _KERNEL_SPT_DEF_TEX_E_NOEXS
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
			return E_NOEXS;
		}
#endif	
	
		/* コントロールブロック取得 */
		tcb    = _KERNEL_TSK_ID2TCB(tskid);
		tcb_ro = _KERNEL_TSK_GET_TCB_RO(tskid, tcb);
	}

	
	if ( pk_dtex != NULL )
	{
		/* 登録 */
		_KERNEL_TSK_SET_RASPTN(tcb, 0);
		_KERNEL_TSK_SET_TEXATR(tcb_ro, pk_dtex->texatr);
		_KERNEL_TSK_SET_TEXRTN(tcb_ro, pk_dtex->texrtn);
	}
	else
	{
		/* %jp{登録解除} */
		_KERNEL_TSK_SET_TEXSTAT(tcb, _KERNEL_TXS_DIS);
		_KERNEL_TSK_SET_TEXRTN(tcb_ro, NULL);
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */

	
	return E_OK;
}


/* end of file */
