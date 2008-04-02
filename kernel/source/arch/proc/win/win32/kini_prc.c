/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kini_prc.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/** %jp{システムの初期化} */
void _kernel_ini_prc(void)
{
	/* %jp{システム変数初期化} */
	_kernel_ictxcb.runctxcb = NULL;		/* %jp{実行中のコンテキスト} */
	_kernel_ictxcb.inhno    = 0;		/* %jp{割込み番号} */
	_kernel_ictxcb.blDisInt = TRUE;		/* %jp{割込み禁止フラグ} */
	_kernel_ictxcb.blIntCtx = FALSE;	/* %jp{割込み時ディスパッチフラグ} */

	/* %jp{クリティカルセクションの生成} */
	InitializeCriticalSection(&_kernel_ictxcb.CriticalSection);

	/* %jp{プライマリスレッドIDの保存} */
	_kernel_ictxcb.dwPrimaryThreadId = GetCurrentThreadId();
	
	/* %jp{割込みロック用のセマフォの作成} */
	_kernel_ictxcb.hSemIntLock = CreateSemaphore(NULL, 0, 1, NULL);
}



/* end of file */
