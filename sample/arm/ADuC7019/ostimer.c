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


static void OsTimer_IrqHandler(void);		/**< %jp{タイマ割り込みハンドラ} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_DINH dfinh;
	
	/* %jp{割り込みハンドラ定義} */
	dfinh.inthdr = (FP)OsTimer_IrqHandler;
	def_inh(1, &dfinh);
	
	/* %jp{タイマ動作開始} */
}


/** %jp{タイマ割り込みハンドラ} */
void OsTimer_IrqHandler(void)
{
	/* 割り込み要因クリア */
	isig_tim();
}


/* end of file */
