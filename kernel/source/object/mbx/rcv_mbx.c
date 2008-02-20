/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_mbx.c
 * @brief %jp{メールボックス資源の返却}%en{Release Semaphore Resource}
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
	_KERNEL_T_MBXCB_PTR mbxcb;
	_KERNEL_T_TSKHDL    tskhdl;
	_KERNEL_T_TCB       *tcb;
	T_MSG               *pk_msg;
	ER                  ercd;

	/* %jp{ID のチェック} */
#if _KERNEL_SPT_RCV_MBX_E_ID
	if ( !_KERNEL_MBX_CHECK_MBXID(mbxid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_RCV_MBX_E_NOEXS
	if ( !_KERNEL_MBX_CHECK_EXS(mbxid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{コントロールブロック取得} */
	mbxcb = _KERNEL_MBX_ID2MBXCB(mbxid);
	
	/* %jp{メッセージキューから取り出し} */
	pk_msg = _KERNEL_MBX_RMV_MSG(mbxcb, _KERNEL_MBX_GET_MBXCB_RO(mbxid, mbxcb));

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
		_KERNEL_MBX_ADD_QUE(mbxcb, _KERNEL_MBX_GET_MBXCB_RO(flgid, mbxcb), tskhdl);		/* %jp{待ち行列に追加} */
		
		/* %jp{タスクディスパッチの実行} */
		_KERNEL_DSP_TSK();

		/* %jp{エラーコードの取得} */
		ercd = _KERNEL_TSK_GET_ERCD(tcb);
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;
}


#else	/* _KERNEL_SPT_RCV_MBX */


#if _KERNEL_SPT_RCV_MBX_E_NOSPT


ER rcv_mbx(ID mbxid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_RCV_MBX */



/* end of file */
