/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  wintimer.c
 * @brief %jp{Windows用のタイマ}%en{Windows timer object}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


/** %jp{Windows ヘッダファイルの読みこみ} */
#define SIZE  WIN_SIZE
#include <windows.h>
#undef  SIZE

#include "kernel.h"
#include "wintimer.h"
#include "arch/proc/win/win32/proc.h"


static DWORD WINAPI WinTimer_Thread(LPVOID param);		/**< %jp{タイマ割込み用スレッド関数} */
static HANDLE hEventTimer;								/**< %jp{タイマハンドル} */


/** %jp{OS用タイマの初期化} */
void WinTimer_Start(INHNO inhno, int iInterval)
{
	DWORD dwThreadId;
		
	/* %jp{タイマ用イベントの作成} */
	hEventTimer = CreateEvent(NULL, FALSE, FALSE, NULL);
	
	/* %jp{マルチメディアタイマの開始} */
	timeSetEvent(iInterval, 1, (LPTIMECALLBACK)hEventTimer, 0, TIME_PERIODIC | TIME_CALLBACK_EVENT_PULSE);
	
	/* %jp{スレッド生成} */
	CreateThread(NULL, 0, WinTimer_Thread, (LPVOID)inhno, 0, &dwThreadId);
}


/** %jp{タイマ割込み用スレッド関数} */
DWORD WINAPI WinTimer_Thread(LPVOID param)
{
	INHNO inhno;
	
	inhno = (INHNO)param;

	for ( ; ; )
	{
		/* %jp{タイマイベントを待つ} */
		WaitForSingleObject(hEventTimer, INFINITE);

		/* %jp{割込みシグナルを入れる} */
		vsig_int(inhno);
	}
}


/* end of file */
