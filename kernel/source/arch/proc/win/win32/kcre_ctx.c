/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kcre_ctx.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <process.h>
#include "core/core.h"
#include "object/inhobj.h"


static unsigned __stdcall	_kernel_ctx_ent(void *param);		/**< %jp{コンテキストのスレッドエントリー関数} */
static unsigned __stdcall	_kernel_ctx_int(void *param);		/**< %jp{コンテキストの割込み処理スレッド} */


/** %jp{実行コンテキストの作成} */
void _kernel_cre_ctx(
		_KERNEL_T_CTXCB	*ctxcb,		/* コンテキストを作成するアドレス */
		FP              entry,			/* コンテキストの実行開始番地 */
		VP_INT          exinf1,			/* コンテキストの実行時パラメータ1 */
		VP_INT          exinf2)			/* コンテキストの実行時パラメータ2 */
{
	ctxcb->blInterrupt = FALSE;

	/* %jp{起動情報を格納} */
	ctxcb->entry  = entry;
	ctxcb->exinf1 = exinf1;
	ctxcb->exinf2 = exinf2;
	
	/* %jp{コンテキストスレッド生成} */
	ctxcb->hEvent     = CreateEvent(NULL, FALSE, FALSE, NULL);
	ctxcb->hIntEvent  = CreateEvent(NULL, FALSE, FALSE, NULL);

#if defined(_MSC_VER)	/* Visual-C++ の場合 */
	ctxcb->hThread    = (HANDLE)_beginthreadex(NULL, 0, _kernel_ctx_ent, (void *)ctxcb, 0, &ctxcb->dwThreadId);
	ctxcb->hIntThread = (HANDLE)_beginthreadex(NULL, 0, _kernel_ctx_int, (void *)ctxcb, 0, &ctxcb->dwIntThreadId);
#else					/* Visual-C++ 以外 */
	ctxcb->hThread    = CreateThread(NULL, 0, _kernel_ctx_ent, (LPVOID)ctxcb, 0, &ctxcb->dwThreadId);
	ctxcb->hIntThread = CreateThread(NULL, 0, _kernel_ctx_int, (LPVOID)ctxcb, 0, &ctxcb->dwIntThreadId);
#endif
}


/** %jp{コンテキストのスレッドエントリー関数} */
unsigned __stdcall _kernel_ctx_ent(void *param)
{
	_KERNEL_T_CTXCB *ctxcb;

	/* %jp{コンテキスト情報取得} */
	ctxcb = (_KERNEL_T_CTXCB *)param;

	/* %jp{開始待ち} */
	WaitForSingleObject(ctxcb->hEvent, INFINITE);

	/* %jp{リスタート用setjmp} */
	setjmp(ctxcb->jmpenv);

	/* 開始 */
	ctxcb->entry(ctxcb->exinf1, ctxcb->exinf2);
	
	return 0;
}


/** %jp{割込みハンドラ処理} */
unsigned __stdcall _kernel_ctx_int(void *param)
{
	_KERNEL_T_CTXCB *ctxcb;

	/* %jp{コンテキスト情報取得} */
	ctxcb = (_KERNEL_T_CTXCB *)param;
	
	for ( ; ; )
	{
		/* %jp{開始待ち} */
		WaitForSingleObject(ctxcb->hIntEvent, INFINITE);

		_kernel_ictxcb.blDisInt = TRUE;

		/* %jp{割込み処理} */
		_kernel_sta_inh();
		_kernel_ictxcb.blIntCtx = TRUE;
		_kernel_exe_inh(_kernel_ictxcb.inhno);
		_kernel_ictxcb.blIntCtx = FALSE;
		_kernel_end_inh();
		
		/* コンテキスト復帰 */
		ctxcb->blInterrupt      = FALSE;
		_kernel_ictxcb.blDisInt = FALSE;
		ResumeThread(ctxcb->hThread);							/* %jp{スレッド復帰} */
		ReleaseSemaphore(_kernel_ictxcb.hSemIntLock, 1, NULL);	/* %jp{割込みロックを解除} */
	}
	
	return 0;
}



/* end of file */
