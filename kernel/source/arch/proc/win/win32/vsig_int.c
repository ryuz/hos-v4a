/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  vsig_int.c
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/* %jp{割込み用処理} */
void vsig_int(int inhno)
{
	/* %jp{割込み用セマフォを取る} */
	WaitForSingleObject(_kernel_ictxcb.hSemIntLock, INFINITE);
	
	/* %jp{クリティカルセクションに入る} */
	EnterCriticalSection(&_kernel_ictxcb.CriticalSection);

	/* %jp{割込み状態に設定} */
	_kernel_ictxcb.inhno = inhno;

	/* %jp{現在実行中のコンテキストを割込みモードに移行} */
	SuspendThread(_kernel_ictxcb.runctxcb->hThread);
	_kernel_ictxcb.runctxcb->blInterrupt = TRUE;
	SetEvent(_kernel_ictxcb.runctxcb->hIntEvent);
	
	/* %jp{クリティカルセクションを出る} */
	LeaveCriticalSection(&_kernel_ictxcb.CriticalSection);
}



/* end of file */
