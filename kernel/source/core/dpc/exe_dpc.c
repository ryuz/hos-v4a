/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dpc.h
 * @brief %jp{遅延プロシージャーコールヘッダファイル}%en{Deferred Procedure Call header file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "core/dpc.h"


#if _KERNEL_SPT_DPC


/* サービスコール退出時の処理 */
void _kernel_exe_dpc(_KERNEL_T_DPCCB *dcpcb)
{
	_KERNEL_T_DPCMSG	msg;
	UINT				head;
	
	for ( ; ; )
	{
		/* %jp{キューチェック} */
		_KERNEL_SYS_LOC_DPC();		/* %jp{ロックをかける} */
		head = dcpcb->head;
		if ( head == dcpcb->tail )
		{
			_KERNEL_SYS_CLR_SVC();	/* サービスコール実行中フラグを倒す */
			_KERNEL_DSP_TSK();		/* %jp{タスクディスパッチの実行} */		
			_KERNEL_SYS_UNL_DPC();	/* %jp{ロック解除} */
			return;
		}
		_KERNEL_SYS_UNL_DPC();	/* %jp{ロック解除} */
		
		/* メッセージ取り出し */
		msg = dcpcb->que[head];
		
		/* ポインタを進める */
		head = head + 1;
		if ( head >= dcpcb->quecnt )
		{
			head = 0;
		}
		dcpcb->head = head;
		
		/* 遅延プロシージャ呼び出し */
		msg.svc(msg.id, msg.param);
	}
}


#endif	/* _KERNEL_SPT_DPC */


/* end of file */
