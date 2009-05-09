/**
 *  Hyper Operating System V4 Advance
 *
 * @file  dpc.h
 * @brief %jp{遅延プロシージャーコールヘッダファイル}%en{Deferred Procedure Call header file}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "core/dpc.h"


#if _KERNEL_SPT_DPC


/* %jp{サービスコール退出時の処理} */
void _kernel_exe_dpc(_KERNEL_T_DPCCB *dcpcb)
{
	volatile _KERNEL_T_DPCMSG	*msg;
	UINT						head;
	
	for ( ; ; )
	{
		/* %jp{キューチェック} */
		head = dcpcb->head;
		_KERNEL_SYS_LOC_DPC();
		if ( head == dcpcb->tail )
		{
			_KERNEL_SYS_CLR_SVC();
			_KERNEL_SYS_UNL_DPC();
			return;					/* %jp{キューが空}%en{empty} */
		}
		_KERNEL_SYS_UNL_DPC();
		
		do
		{
			/* %jp{メッセージ取り出し} */
			msg = &dcpcb->que[head];

			/* %jp{遅延プロシージャ呼び出し} */
			msg->svc(msg->id, msg->param);

			/* %jp{ポインタを進める} */
			head = head + 1;
			if ( head >= dcpcb->quecnt )
			{
				head = 0;
			}
			dcpcb->head = head;
		} while ( head != dcpcb->tail );
		
		_KERNEL_DSP_TSK();			/* %jp{タスクディスパッチの実行} */
	}
}


#endif	/* _KERNEL_SPT_DPC */


/* end of file */
