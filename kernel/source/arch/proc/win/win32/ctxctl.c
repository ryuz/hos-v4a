/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ctxctlc
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <process.h>
#include "core/core.h"
#include "object/inhobj.h"

static unsigned __stdcall	_kernel_ctx_ent(void *param);					/**< %jp{コンテキストのスレッドエントリー関数} */
static unsigned __stdcall	_kernel_ctx_int(void *param);					/**< %jp{コンテキストの割込み処理スレッド} */

static void					_kernel_wai_ctx(_KERNEL_T_CTXCB *ctxcb);		/**< %jp{スレッドの停止待ち} */

static CRITICAL_SECTION		_kernel_win32_CriticalSection;
static _KERNEL_T_CTXCB		*_kernel_win32_runctxcb        = NULL;			/**< %jp{実行中のコンテキスト} */
static INHNO				_kernel_win32_inhno;

static HANDLE				_kernel_win32_hSemIntLock      = NULL;			/**< %jp{システムの排他制御用セマフォ} */

static volatile BOOL		_kernel_win32_blDisInt         = TRUE;			/**< %jp{割込み禁止フラグ} */
static volatile BOOL		_kernel_win32_blIntDsp         = FALSE;			/**< %jp{割込み時ディスパッチフラグ} */
static DWORD				_kernel_win32_dwPrimaryThreadId = 0;			/**< %jp{プライマリスレッドID} */



/** %jp{システムの初期化} */
void _kernel_ini_prc(void)
{
	/* %jp{クリティカルセクションの生成} */
	InitializeCriticalSection(&_kernel_win32_CriticalSection);

	/* %jp{プライマリスレッドIDの保存} */
	_kernel_win32_dwPrimaryThreadId = GetCurrentThreadId();
	
	/* %jp{割込みロック用のセマフォの作成} */
	_kernel_win32_hSemIntLock = CreateSemaphore(NULL, 0, 1, NULL);
}


/** %jp{割り込み禁止} */
void _kernel_dis_int(void)
{
	/* 既に割込み禁止で無ければセマフォを取る */
	if ( !_kernel_win32_blDisInt )
	{
		WaitForSingleObject(_kernel_win32_hSemIntLock, INFINITE);
		_kernel_win32_blDisInt = TRUE;
	}
}


/** %jp{割り込み許可} */
void _kernel_ena_int(void)
{
	/* 割込みコンテキストから呼ばれたなら何もしない */
//	if ( _kernel_win32_blIntCtx )
//	{
//		return;
//	}
	
	/* 既に割込み禁止ならセマフォを返す */
	if ( _kernel_win32_blDisInt )
	{
		_kernel_win32_blDisInt = FALSE;
		ReleaseSemaphore(_kernel_win32_hSemIntLock, 1, NULL);
	}
}


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

		_kernel_win32_blDisInt = TRUE;

		/* %jp{割り込み処理} */
		_kernel_sta_inh();
		_kernel_exe_inh(_kernel_win32_inhno);
		_kernel_end_inh();
		
		/* コンテキスト復帰 */
		ctxcb->blInterrupt     = FALSE;
		_kernel_win32_blDisInt = FALSE;
		ResumeThread(ctxcb->hThread);							/* %jp{スレッド復帰} */
		ReleaseSemaphore(_kernel_win32_hSemIntLock, 1, NULL);	/* %jp{割込みロックを解除} */
	}
	
	return 0;
}



/** %jp{実行コンテキストの削除} */
void _kernel_del_ctx(_KERNEL_T_CTXCB *ctxcb)
{
	TerminateThread(ctxcb->hThread, 0);
	CloseHandle(ctxcb->hThread);
	CloseHandle(ctxcb->hEvent);

	TerminateThread(ctxcb->hIntThread, 0);
	CloseHandle(ctxcb->hIntThread);
	CloseHandle(ctxcb->hIntEvent);
}


/** %jp{実行コンテキストのリスタート} */
void _kernel_rst_ctx(_KERNEL_T_CTXCB *ctxcb)
{
	longjmp(ctxcb->jmpenv, 0);
}


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
	EnterCriticalSection(&_kernel_win32_CriticalSection);
	
	/* %jp{実行中コンテキストの登録} */
	_kernel_win32_runctxcb = ctxcb_nxt;
	
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
		LeaveCriticalSection(&_kernel_win32_CriticalSection);

		WaitForSingleObject(ctxcb_now->hIntEvent, INFINITE);
	}
	else
	{
		/* %jp{クリティカルセクションを出る} */
		LeaveCriticalSection(&_kernel_win32_CriticalSection);

		WaitForSingleObject(ctxcb_now->hEvent, INFINITE);
	}
}	


/** %jp{アイドル時の処理} */
void _kernel_wai_int(void)
{
	Sleep(1);
}


/** %jp{コンテキストの開始} */
void _kernel_sta_ctx(_KERNEL_T_CTXCB *ctxcb)
{
	/* %jp{実行中コンテキストの登録} */
	_kernel_win32_runctxcb = ctxcb;

	/* %jp{スレッドの実行開始} */
	SetEvent(ctxcb->hEvent);
	
	if ( GetCurrentThreadId() == _kernel_win32_dwPrimaryThreadId )
	{
		/* %jp{ダイアログを表示} */
		MessageBox(NULL, "Press OK, Exit a process", "Hyper Operationg System V4 Advance for Win32", MB_OK);

		/* %jp{終了} */
		ExitProcess(0);
	}
}


/* %jp{割り込み用処理} */
void vsig_int(int inhno)
{
	/* %jp{割り込み用セマフォを取る} */
	WaitForSingleObject(_kernel_win32_hSemIntLock, INFINITE);
	
	/* %jp{クリティカルセクションに入る} */
	EnterCriticalSection(&_kernel_win32_CriticalSection);

	/* %jp{割り込み状態に設定} */
	_kernel_win32_inhno    = inhno;

	/* %jp{現在実行中のコンテキストを割込みモードに移行} */
	SuspendThread(_kernel_win32_runctxcb->hThread);
	_kernel_win32_runctxcb->blInterrupt = TRUE;
	SetEvent(_kernel_win32_runctxcb->hIntEvent);
	
	/* %jp{クリティカルセクションを出る} */
	LeaveCriticalSection(&_kernel_win32_CriticalSection);
}



/* end of file */
