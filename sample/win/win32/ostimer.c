/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  ostimer.c
 * @brief %jp{OSタイマ}%en{OS timer}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "ostimer.h"
#include "wintimer.h"


#define OSTIMER_TIMER_INHNO		1			/**< %jp{割込みハンドラ番号} */


static void OsTimer_IrqHandler(void);		/**< %jp{タイマ割込みハンドラ} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_DINH dfinh;
	
	/* %jp{割込みハンドラ定義} */
	dfinh.inthdr = (FP)OsTimer_IrqHandler;
	def_inh(OSTIMER_TIMER_INHNO, &dfinh);
	
	/* %jp{タイマ動作開始} */
	WinTimer_Start(OSTIMER_TIMER_INHNO, 10);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_IrqHandler(void)
{
	isig_tim();
}


/* end of file */
