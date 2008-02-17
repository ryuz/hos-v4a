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
#include "object/texobj.h"


/* %jp{タスク例外処理の要求} */
ER ras_tex(ID tskid, TEXPTN rasptn)
{
	_KERNEL_T_TSKHDL		tskhdl;
	_KERNEL_T_TEXCB_PTR		texcb;
	_KERNEL_T_TEXCB_RO_PTR	texcb_ro;
	_KERNEL_T_TCB_PTR		tcb;
	_KERNEL_T_TCB_RO_PTR	tcb_ro;
	
	
	if ( tskid == TSK_SELF )		/* %jp{自タスク指定時の変換} */
	{
#ifdef _KERNEL_SPT_RAS_TEX_E_ID
		if ( _KERNEL_SYS_SNS_CTX() )
		{
			return E_ID;			/* %jp{不正ID番号} */
		}
#endif
		
		/* %jp{実行中タスクを取得} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();
		tskid  = _KERNEL_TSK_TSKHDL2ID(tskhdl);
	}
	else
	{
#if _KERNEL_SPT_RAS_TEX_E_ID
		if ( !_KERNEL_TEX_CHECK_TSKID(tskid) )
		{
			return E_ID;	/* %jp{不正ID番号} */
		}
#endif
	}
	
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{タスク存在チェック} */
#if _KERNEL_SPT_RAS_TEX_E_NOEXS
	if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOEXS;
	}
#endif	
	

#if _KERNEL_SPT_RAS_TEX_E_OBJ
	if ( !_KERNEL_TEX_CHECK_EXS(tskid)		/* 未登録 */
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;
	}
#endif
	
	/* TCB取得 */
	tcb = _KERNEL_TSK_ID2TCB(tskid);
	

#if _KERNEL_SPT_RAS_TEX_E_OBJ
	if ( _KERNEL_TSK_GET_TSKSTAT(tcb) == _KERNEL_TTS_DMT )		/* %jp{オブジェクト状態判定} */
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;
	}
#endif	
	
	/* 例外要因設定 */
	rasptn |= _KERNEL_TEX_GET_RASPTN(texcb);
	_KERNEL_TEX_SET_RASPTN(texcb, rasptn);
	
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	
	return E_OK;
}


/* end of file */
