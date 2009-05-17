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
#include "system/sysapi/sysapi.h"


#define OSTIMER_TIMER_INHNO		1			/**< %jp{割込みハンドラ番号} */


static void OsTimer_IrqHandler(VP_INT exinf);		/**< %jp{タイマ割込みハンドラ} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
#if 0
	T_DINH dfinh;
	
	/* %jp{割込みハンドラ定義} */
	dfinh.inthdr = (FP)OsTimer_IrqHandler;
	def_inh(OSTIMER_TIMER_INHNO, &dfinh);
#else
	T_CISR cisr;
	cisr.isratr = TA_HLNG;
	cisr.intno  = OSTIMER_TIMER_INHNO;
	cisr.isr    = (FP)OsTimer_IrqHandler;
	cisr.exinf  = (VP_INT)0x1234;
	acre_isr(&cisr);
#endif
	return;
	
	/* %jp{タイマ動作開始} */
	WinTimer_Start(OSTIMER_TIMER_INHNO, 10);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_IrqHandler(VP_INT exinf)
{
	isig_tim();
}


/* end of file */
