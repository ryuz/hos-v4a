/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ctxctlc
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"



static DWORD WINAPI		_kernel_ctx_ent(LPVOID param);					/* %jp{スレッドの開始関数} */
static void				_kernel_run_ctx(_KERNEL_T_CTXCB *pk_ctxcb);		/* %jp{スレッドの実行開始} */
static void				_kernel_wai_ctx(_KERNEL_T_CTXCB *pk_ctxcb);		/* %jp{スレッドの停止待ち} */


static CRITICAL_SECTION	_kernel_win32_CriticalSection;
static _KERNEL_T_CTXCB	*_kernel_win32_runctxcb        = NULL;		/**< %jp{実行中のコンテキスト} */
static _KERNEL_T_CTXCB	*_kernel_win32_intctxcb        = NULL;		/**< %jp{割込みからスイッチされたコンテキスト} */
static HANDLE			_kernel_win32_hSemDisInt       = NULL;		/**< %jp{システムの排他制御用セマフォ} */
static volatile BOOL	_kernel_win32_blIntCtx         = FALSE;		/**< %jp{割込み処理中フラグ} */
static volatile BOOL	_kernel_win32_blDisInt         = TRUE;		/**< %jp{割込み禁止フラグ} */
static volatile BOOL	_kernel_win32_blIntDsp         = FALSE;		/**< %jp{割込み時ディスパッチフラグ} */
static DWORD			_kernel_win32_hPrimaryThreadId = 0;			/**< %jp{プライマリスレッドID} */



/** %jp{システムの初期化} */
void _kernel_ini_prc(void)
{
	InitializeCriticalSection(&_kernel_win32_CriticalSection);

	/* %jp{プライマリスレッドIDの保存} */
	_kernel_win32_hPrimaryThreadId = GetCurrentThreadId();

	/* %jp{割り込み禁止に見立てるセマフォの作成} */
	_kernel_win32_hSemDisInt = CreateSemaphore(NULL, 0, 1, NULL);
}


/** %jp{割り込み禁止} */
void _kernel_dis_int(void)
{
	/* 割込みコンテキストから呼ばれたなら何もしない */
	if ( _kernel_win32_blIntCtx )
	{
		return;
	}

	/* 既に割込み禁止で無ければセマフォを取る */
	if ( !_kernel_win32_blDisInt )
	{
		WaitForSingleObject(_kernel_win32_hSemDisInt, INFINITE);
		_kernel_win32_blDisInt = TRUE;
	}
}


/** %jp{割り込み許可} */
void _kernel_ena_int(void)
{
	/* 割込みコンテキストから呼ばれたなら何もしない */
	if ( _kernel_win32_blIntCtx )
	{
		return;
	}
	
	/* 既に割込み禁止ならセマフォを返す */
	if ( _kernel_win32_blDisInt )
	{
		_kernel_win32_blDisInt = FALSE;
		ReleaseSemaphore(_kernel_win32_hSemDisInt, 1, NULL);
	}
}



/** %jp{実行コンテキストの作成} */
void _kernel_cre_ctx(
		_KERNEL_T_CTXCB *pk_ctxcb,		/* コンテキストを作成するアドレス */
		FP              entry,			/* コンテキストの実行開始番地 */
		VP_INT          exinf1,			/* コンテキストの実行時パラメータ1 */
		VP_INT          exinf2)			/* コンテキストの実行時パラメータ2 */
{
	pk_ctxcb->blIntSuspend = FALSE;

	/* %jp{起動情報を格納} */
	pk_ctxcb->entry  = entry;
	pk_ctxcb->exinf1 = exinf1;
	pk_ctxcb->exinf2 = exinf2;
	
	/* %jp{コンテキストスレッド生成} */
	pk_ctxcb->hEvent  = CreateEvent(NULL, FALSE, FALSE, NULL);
	pk_ctxcb->hThread = CreateThread(NULL, 0, _kernel_ctx_ent, (LPVOID)pk_ctxcb,
									0, &pk_ctxcb->dwThreadId);
}


/** %jp{スレッドの開始関数} */
DWORD WINAPI _kernel_ctx_ent(LPVOID param)
{
	_KERNEL_T_CTXCB *pk_ctxcb;

	/* %jp{コンテキスト情報取得} */
	pk_ctxcb = (_KERNEL_T_CTXCB *)param;

	/* %jp{開始待ち} */
	WaitForSingleObject(pk_ctxcb->hEvent, INFINITE);

	/* %jp{リスタート用setjmp} */
	setjmp(pk_ctxcb->jmpenv);

	/* 開始 */
	pk_ctxcb->entry(pk_ctxcb->exinf1, pk_ctxcb->exinf2);
	
	return 0;
}


/** %jp{実行コンテキストの削除} */
void _kernel_del_ctx(_KERNEL_T_CTXCB *pk_ctxcb)
{
	/* スレッド削除 */
	TerminateThread(pk_ctxcb->hThread, 0);
	CloseHandle(pk_ctxcb->hThread);
	CloseHandle(pk_ctxcb->hEvent);
}


/** %jp{実行コンテキストのリスタート} */
void _kernel_rst_ctx(_KERNEL_T_CTXCB *pk_ctxcb)
{
	longjmp(pk_ctxcb->jmpenv, 0);
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
	
	/* 割込み処理から呼ばれたら */
	if ( _kernel_win32_blIntCtx )
	{
		/* 切り替えを予約 */
		_kernel_win32_blIntDsp = TRUE;
		_kernel_win32_intctxcb = ctxcb_nxt;
	}
	else
	{
		/* 切り替え先スレッドの動作開始 */
		_kernel_run_ctx(ctxcb_nxt);
		
		/* %jp{再開待ち} */
		WaitForSingleObject(ctxcb_now->hEvent, INFINITE);
	}
}	


/** %jp{アイドル時の処理} */
void _kernel_wai_int(void)
{
	Sleep(10);
}


/** %jp{コンテキストの開始} */
void _kernel_sta_ctx(_KERNEL_T_CTXCB *pk_ctxcb)
{
	/* %jp{スレッドの実行開始} */
	_kernel_run_ctx(pk_ctxcb);

	if ( GetCurrentThreadId() == _kernel_win32_hPrimaryThreadId )
	{
		/* %jp{ダイアログを表示} */
		MessageBox(NULL, "Press OK, Exit a process", "Hyper Operationg System V4 Advance for Win32", MB_OK);

		/* %jp{終了} */
		ExitProcess(0);
	}
}


/** %jp{スレッドの実行開始} */
void _kernel_run_ctx(_KERNEL_T_CTXCB *pk_ctxcb)
{
	/* %jp{実行中コンテキストの登録} */
	_kernel_win32_runctxcb = pk_ctxcb;
	
	/* %jp{割り込みから中断されていた場合} */
	if ( pk_ctxcb->blIntSuspend )
	{
		/* %jp{割り込み用セマフォを返す} */
		_kernel_win32_blDisInt = FALSE;
		ReleaseSemaphore(_kernel_win32_hSemDisInt, 1, NULL);
		
		/* スレッド動作再開 */
		pk_ctxcb->blIntSuspend = FALSE;
		ResumeThread(pk_ctxcb->hThread);
	}
	else
	{
		/* %jp{スレッドを起こす} */
		SetEvent(pk_ctxcb->hEvent);
	}
}



/* %jp{割り込み用処理} */
void vsig_int(int inhno)
{
	EnterCriticalSection(&_kernel_win32_CriticalSection);

	/* %jp{割り込み用セマフォを取る} */
	WaitForSingleObject(_kernel_win32_hSemDisInt, INFINITE);
	_kernel_win32_blDisInt = TRUE;
	
	/* %jp{現在実行中のスレッドを止める} */
	SuspendThread(_kernel_win32_runctxcb->hThread);
	
	/* %jp{割り込み状態に設定} */
	_kernel_win32_blIntCtx = TRUE;
	_kernel_win32_blIntDsp = FALSE;
	
	/* %jp{割り込み処理} */
	_kernel_sta_inh();
	_kernel_exe_inh(inhno);
	_kernel_end_inh();

	/* %jp{割り込み状態を解除} */
	_kernel_win32_blIntCtx = FALSE;
	

	/* %jp{遅延ディスパッチ発生なら} */
	if ( _kernel_win32_blIntDsp )
	{
		/* 元のスレッドをサスペンドのままマーク */
		_kernel_win32_runctxcb->blIntSuspend = TRUE;
		
		/* 切り替え先スレッドの動作開始 */
		_kernel_run_ctx(_kernel_win32_intctxcb);
	}
	else
	{
		/* %jp{割り込み用セマフォを返す} */
		_kernel_win32_blDisInt = FALSE;
		ReleaseSemaphore(_kernel_win32_hSemDisInt, 1, NULL);
		
		/* %jp{現在実行中のスレッドを再開} */
		ResumeThread(_kernel_win32_runctxcb->hThread);
	}

	LeaveCriticalSection(&_kernel_win32_CriticalSection);
}



/* end of file */
