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



#if _KERNEL_SPT_SND_MBX


/**< %jp{メールボックスへの送信} */
ER snd_mbx(ID mbxid, T_MSG *pk_msg)
{
	_KERNEL_T_MBXCB_PTR mbxcb;
	_KERNEL_T_TSKHDL    tskhdl;
	_KERNEL_T_TCB       *tcb;
	
	/* %jp{ID のチェック} */
#if _KERNEL_SPT_SND_MBX_E_ID
	if ( !_KERNEL_MBX_CHECK_MBXID(mbxid) )
	{
		return E_ID;	/* %jp{不正ID番号}%en{Invalid ID number} */
	}
#endif
	
	_KERNEL_ENTER_SVC();	/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{オブジェクト存在チェック} */
#if _KERNEL_SPT_SND_MBX_E_NOEXS
	if ( !_KERNEL_MBX_CHECK_EXS(mbxid) )
	{
		_KERNEL_LEAVE_SVC();	/* %jp{サービスコール終了} */
		return E_NOEXS;			/* %jp{オブジェクト未生成} */
	}
#endif
	
	/* %jp{コントロールブロック取得} */
	mbxcb = _KERNEL_MBX_ID2MBXCB(mbxid);
	
	/* %jp{待ち行列先頭からタスク取り出し} */
	tskhdl = _kernel_rmh_que(_KERNEL_MBX_GET_QUE(mbxcb));
	if ( tskhdl != _KERNEL_TSKHDL_NULL )
	{
		T_MSG **ppk_msg;

		/* %jp{待ちタスクがあれば待ち解除} */
		tcb     = _KERNEL_TSK_TSKHDL2TCB(tskhdl);			/* %jp{TCB取得} */
		ppk_msg = (T_MSG **)_KERNEL_TSK_GET_DATA(tcb);
		*ppk_msg = pk_msg;
		_KERNEL_TSK_SET_ERCD(tcb, E_OK);				/* %jp{エラーコード設定} */
		_KERNEL_DSP_WUP_TSK(tskhdl);					/* %jp{タスクの待ち解除} */
		_KERNEL_MBX_RMV_TOQ(tskhdl);					/* %jp{タイムアウトの解除} */
		
		/* %jp{タスクディスパッチの実行} */
		_KERNEL_DSP_TSK();
	}
	else
	{
		/* %jp{メールボックに追加} */
		_KERNEL_MBX_ADD_MSG(mbxcb, _KERNEL_MBX_GET_MBXCB_RO(mbxid, mbxcb), pk_msg);
	}
	
	_KERNEL_LEAVE_SVC();	/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return E_OK;	/* %jp{正常終了}%en{Normal completion} */
}


#else	/* _KERNEL_SPT_SND_MBX */


#if _KERNEL_SPT_SND_MBX_E_NOSPT


ER snd_mbx(ID mbxid)
{
	return E_NOSPT;
}

#endif


#endif	/* _KERNEL_SPT_SND_MBX */



/* end of file */
