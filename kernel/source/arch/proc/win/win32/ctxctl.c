/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ctxctlc
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * @version $Id: ctxctl.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"



static DWORD WINAPI _kernel_ctx_ent(LPVOID param);					/* %jp{スレッドの開始関数} */
static void         _kernel_run_ctx(_KERNEL_T_CTXCB *pk_ctxcb);		/* %jp{スレッドの実行開始} */
static void         _kernel_wai_ctx(_KERNEL_T_CTXCB *pk_ctxcb);		/* %jp{スレッドの停止待ち} */


static _KERNEL_T_CTXCB *_kernel_win32_runctxcb        = NULL;		/**< %jp{実行中のコンテキスト} */
static _KERNEL_T_CTXCB *_kernel_win32_oldctxcb        = NULL;		/**< %jp{直前の実行コンテキスト} */
static HANDLE          _kernel_win32_hSemIntCtx       = NULL;		/**< %jp{割り込みの排他制御セマフォ} */
static HANDLE          _kernel_win32_hSemDisInt       = NULL;		/**< %jp{システムの排他制御用セマフォ} */
static volatile BOOL   _kernel_win32_blIntCtx         = FALSE;		/**< %jp{割り込み処理中フラグ} */
static volatile BOOL   _kernel_win32_blDisInt         = TRUE;		/**< %jp{割り込み禁止フラグ} */
static volatile BOOL   _kernel_win32_blDlyDsp         = FALSE;		/**< %jp{遅延ディスパッチフラグ} */
static DWORD           _kernel_win32_hPrimaryThreadId = 0;			/**< %jp{プライマリスレッドID} */



/** %jp{システムの初期化} */
void _kernel_ini_prc(void)
{
	/* %jp{プライマリスレッドIDの保存} */
	_kernel_win32_hPrimaryThreadId = GetCurrentThreadId();

	/* %jp{割り込み禁止に見立てるセマフォの作成} */
	_kernel_win32_hSemDisInt = CreateSemaphore(NULL, 0, 1, NULL);

	/* %jp{割り込みの排他制御セマフォの生成} */
	_kernel_win32_hSemIntCtx = CreateSemaphore(NULL, 1, 1, NULL);
}


/** %jp{割り込み許可} */
void _kernel_ena_int(void)
{
	if ( _kernel_win32_blIntCtx )
	{
		return;
	}

	if ( _kernel_win32_blDisInt )
	{
		_kernel_win32_blDisInt = FALSE;
		ReleaseSemaphore(_kernel_win32_hSemDisInt, 1, NULL);
	}
}


/** %jp{割り込み禁止} */
void _kernel_dis_int(void)
{
	if ( _kernel_win32_blIntCtx )
	{
		return;
	}

	if ( !_kernel_win32_blDisInt )
	{
		WaitForSingleObject(_kernel_win32_hSemDisInt, INFINITE);
		_kernel_win32_blDisInt = TRUE;
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
	
	/* %jp{コンテキストスレッド生成* */
	pk_ctxcb->hEvent  = CreateEvent(NULL, FALSE, FALSE, NULL);
#if 1
	pk_ctxcb->hThread = CreateThread(NULL, 0, _kernel_ctx_ent, (LPVOID)pk_ctxcb,
									0, &pk_ctxcb->dwThreadId);
#else
	pk_ctxcb->hThread = _beginthread(_kernel_ctx_ent, 0, (void *)pk_ctxcb);
#endif

	/* %jp{pk_ctxcb->hThreadの格納完了後に開始} */
	SetEvent(pk_ctxcb->hEvent);

	_kernel_wai_ctx(pk_ctxcb);
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

	/* %jp{自分自身をサスペンドさせる} */
	SuspendThread(pk_ctxcb->hThread);

	/* %jp{直前のコンテキストスレッドが確実にサスペンドするのを待つ} */
	_kernel_wai_ctx(_kernel_win32_oldctxcb);
	_kernel_win32_oldctxcb = NULL;

	pk_ctxcb->entry(pk_ctxcb->exinf1, pk_ctxcb->exinf2);
	
	return 0;
}


/** %jp{実行コンテキストの削除} */
void _kernel_del_ctx(_KERNEL_T_CTXCB *pk_ctxcb)
{
	/* スレッド削除 */
	CloseHandle(pk_ctxcb->hEvent);
	TerminateThread(pk_ctxcb->hThread, 0);
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
	
	/* %jp{割り込みの終わりで発生した場合} */
	if ( _kernel_win32_blIntCtx )
	{
		/* %jp{割り込み状態を解除} */
		_kernel_win32_blIntCtx = FALSE;

		/* 切り替え先のスレッドを起こす */
		_kernel_run_ctx(ctxcb_nxt);

		/* 遅延ディスパッチあり */
		_kernel_win32_blDlyDsp = TRUE;

		return;
	}
	else
	{
		/* %jp{切り替え先のスレッドを起こす} */
		_kernel_run_ctx(ctxcb_nxt);
		
		/* %jp{自分自身をサスペンドさせる} */
		SuspendThread(ctxcb_now->hThread);

		/* %jp{直前のタスクが確実にサスペンドするのを待つ} */
		_kernel_wai_ctx(_kernel_win32_oldctxcb);
		_kernel_win32_oldctxcb = NULL;
	}
}


/** %jp{スレッドの停止待ち} */
void _kernel_wai_ctx(_KERNEL_T_CTXCB *pk_ctxcb)
{
	if ( pk_ctxcb == NULL )
	{
		return;
	}

	while ( SuspendThread(pk_ctxcb->hThread) != 1 )
	{
		ResumeThread(pk_ctxcb->hThread);
		Sleep(1);
	}
	ResumeThread(pk_ctxcb->hThread);
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
	_kernel_win32_oldctxcb = _kernel_win32_runctxcb;
	_kernel_win32_runctxcb = pk_ctxcb;
	
	/* %jp{割り込みから中断されていた場合} */
	if ( pk_ctxcb->blIntSuspend )
	{
		pk_ctxcb->blIntSuspend = FALSE;

		_kernel_win32_blDisInt = FALSE;
		ReleaseSemaphore(_kernel_win32_hSemDisInt, 1, NULL);
	}
	
	/* %jp{スレッドを起こす} */
	ResumeThread(pk_ctxcb->hThread);
}



/* %jp{割り込み用処理} */
void vsig_int(int inhno)
{
	WaitForSingleObject(_kernel_win32_hSemIntCtx, INFINITE);

	/* %jp{割り込み用セマフォを取る} */
	WaitForSingleObject(_kernel_win32_hSemDisInt, INFINITE);
	_kernel_win32_blDisInt = TRUE;
	
	/* %jp{現在実行中のスレッドを止める} */
	SuspendThread(_kernel_win32_runctxcb->hThread);
	_kernel_win32_runctxcb->blIntSuspend = TRUE;
	
	/* %jp{割り込み状態に設定} */
	_kernel_win32_blIntCtx = TRUE;
	_kernel_win32_blDlyDsp = FALSE;
	
	/* %jp{割り込み処理} */
	_kernel_sta_inh();
	_kernel_exe_inh(inhno);
	_kernel_end_inh();
	
	/* %jp{遅延ディスパッチが発生しなければ復帰処理} */
	if ( !_kernel_win32_blDlyDsp )
	{
		/* %jp{割り込み状態を解除} */
		_kernel_win32_blIntCtx = FALSE;
		
		/* %jp{割り込み用セマフォを返す} */
		_kernel_win32_blDisInt = FALSE;
		ReleaseSemaphore(_kernel_win32_hSemDisInt, 1, NULL);
		
		/* %jp{現在実行中のスレッドを再開} */
		_kernel_win32_runctxcb->blIntSuspend = FALSE;
		ResumeThread(_kernel_win32_runctxcb->hThread);		
	}

	ReleaseSemaphore(_kernel_win32_hSemIntCtx, 1, NULL);		
}



/* end of file */
