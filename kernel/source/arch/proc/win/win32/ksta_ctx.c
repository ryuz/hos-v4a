/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ksta_ctx.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{コンテキストの開始} */
void _kernel_sta_ctx(_KERNEL_T_CTXCB *ctxcb)
{
	/* %jp{実行中コンテキストの登録} */
	_kernel_ictxcb.runctxcb = ctxcb;

	/* %jp{スレッドの実行開始} */
	SetEvent(ctxcb->hEvent);
	
	if ( GetCurrentThreadId() == _kernel_ictxcb.dwPrimaryThreadId )
	{
		/* %jp{ダイアログを表示} */
		MessageBox(NULL, _T("Press OK, Exit a process"), _T("Hyper Operationg System V4 Advance for Win32"), MB_OK);
		
		/* %jp{終了} */
		ExitProcess(0);
	}
}


/* end of file */
