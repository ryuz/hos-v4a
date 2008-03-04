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


/* %jp{タスク例外処理の要求} */
ER ras_tex(ID tskid, TEXPTN rasptn)
{
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TCB_RO_PTR	tcb_ro;
	_KERNEL_T_TSKHDL		tskhdl;
	
	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
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
		tskhdl = _KERNEL_TSK_GET_TSKHDL(tskid, tcb);
	}

#if _KERNEL_SPT_RAS_TEX_E_OBJ
	if ( _KERNEL_TSK_GET_TSKSTAT(tcb) == _KERNEL_TTS_DMT )		/* %jp{オブジェクト状態判定} */
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;
	}
#endif
	
	
	/* 例外要因設定 */
	rasptn |= _KERNEL_TSK_GET_RASPTN(tcb);
	_KERNEL_TSK_SET_RASPTN(tcb, rasptn);
	if ( tskhdl == _KERNEL_SYS_GET_RUNTSK() )
	{
		if ( _KERNEL_TSK_GET_TEXSTAT(tcb) == _KERNEL_TXS_ENA )
		{
			_KERNEL_TSK_T_TEXRTN	texrtn;
			_KERNEL_TSK_T_EXINF		exinf;

			do
			{
				_KERNEL_TSK_SET_TEXSTAT(tcb, _KERNEL_TXS_DIS);
				_KERNEL_TSK_SET_RASPTN(tcb, 0);
				
				tcb_ro = _KERNEL_TSK_GET_TCB_RO(_KERNEL_TSK_TSKHDL2ID(tskhdl_run), tcb);
				texrtn = _KERNEL_TSK_GET_TEXRTN(tcb_ro);
				exinf  = _KERNEL_TSK_GET_EXINF(tcb_ro);
				
				_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */

				/* %jp{タスク例外処理呼び出し} */
				texrtn((TEXPTN)rasptn, (VP_INT)exinf);

				_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
				
			} while ( (rasptn = _KERNEL_TSK_GET_RASPTN(tcb)) != 0 );
		}
	}
	
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	
	return E_OK;
}


/* end of file */
