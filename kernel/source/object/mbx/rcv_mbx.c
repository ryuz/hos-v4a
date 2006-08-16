/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_mbx.c
 * @brief %jp{メールボックス資源の返却}%en{Release Semaphore Resource}
 *
 * @version $Id: rcv_mbx.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"



#if _KERNEL_SPT_RCV_MBX


/**< %jp{メールボックスへの送信} */
ER rcv_mbx(ID mbxid, T_MSG **ppk_msg)
{
	_KERNEL_T_MBXHDL mbxhdl;
	_KERNEL_T_TSKHDL tskhdl;
	_KERNEL_T_TCB    *tcb;
	T_MSG            *pk_msg;
	ER               ercd;

	/* %jp{ID のチェック} */
#ifdef _KERNEL_SPT_SIG_MBX_E_ID
	if ( !_KERNEL_MBX_CHECK_MBXID(mbxid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#ifdef _KERNEL_SPT_SIG_MBX_E_NOEXS
	if ( !_KERNEL_MBX_CHECK_EXS(mbxid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{メールボックスハンドル取得} */
	mbxhdl = _KERNEL_MBX_ID2MBXHDL(mbxid);
	
	/* %jp{メッセージキューから取り出し} */
	pk_msg = _kernel_rmv_msg(mbxhdl);

	if ( pk_msg != NULL )
	{
		*ppk_msg = pk_msg;
		ercd     = E_OK;
	}
	else
	{
		/* %jp{タスクを待ち状態にする} */
		tskhdl = _KERNEL_SYS_GET_RUNTSK();
		tcb    = _KERNEL_TSK_TSKHDL2TCB(tskhdl);			/* %jp{TCB取得} */

		_KERNEL_TSK_SET_TSKWAIT(tcb, _KERNEL_TTW_SEM);
		_KERNEL_TSK_SET_WOBJID(tcb, mbxid);
		_KERNEL_TSK_SET_DATA(tcb, (VP_INT)ppk_msg);
		
		_KERNEL_DSP_WAI_TSK(tskhdl);
		_KERNEL_MBX_ADD_QUE(mbxhdl, tskhdl);				/* %jp{待ち行列に追加} */
		
		/* %jp{タスクディスパッチの実行} */
		_KERNEL_DSP_TSK();

		/* %jp{エラーコードの取得} */
		ercd = _KERNEL_TSK_GET_ERCD(tcb);
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;	/* %jp{正常終了}%en{Normal completion} */
}


#else	/* _KERNEL_SPT_RCV_MBX */


#if _KERNEL_SPT_RCV_MBX_E_NOSPT


ER snd_mbx(ID mbxid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_RCV_MBX */



/* end of file */
