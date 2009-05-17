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



static void OsTimer_IrqHandler(void);						/**< %jp{タイマ割込みハンドラ} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_IrqHandler(void)
{
	isig_tim();
}


/* end of file */
