/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kswi_ctx.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{実行コンテキストの切替} */
void _kernel_swi_ctx(
		_KERNEL_T_CTXCB *ctxcb_now,		/* 現在のコンテキストの保存先 */
		_KERNEL_T_CTXCB *ctxcb_nxt)		/* 新たに実行するコンテキスト */
{
	/* %jp{切り替え無しならそのまま} */
	if ( ctxcb_now == ctxcb_nxt )
	{
		return;
	}
	
	/* %jp{クリティカルセクションに入る} */
	EnterCriticalSection(&_kernel_ictxcb.CriticalSection);
	
	/* %jp{実行中コンテキストの登録} */
	_kernel_ictxcb.runctxcb = ctxcb_nxt;
	
	/* 切り替え先コンテキストの開始 */
	if ( ctxcb_nxt->blInterrupt )
	{
		SetEvent(ctxcb_nxt->hIntEvent);
	}
	else
	{
		SetEvent(ctxcb_nxt->hEvent);
	}
	
	/* 切り替え元を待ちに入れる */
	if ( ctxcb_now->blInterrupt )
	{
		/* %jp{クリティカルセクションを出る} */
		LeaveCriticalSection(&_kernel_ictxcb.CriticalSection);

		WaitForSingleObject(ctxcb_now->hIntEvent, INFINITE);
	}
	else
	{
		/* %jp{クリティカルセクションを出る} */
		LeaveCriticalSection(&_kernel_ictxcb.CriticalSection);

		WaitForSingleObject(ctxcb_now->hEvent, INFINITE);
	}
}	



/* end of file */
