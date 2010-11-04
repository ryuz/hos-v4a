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
#include "regs_sh7262.h"




static void OsTimer_IrqHandler(void);						/**< %jp{タイマ割込みハンドラ} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_DINH dfinh;
	
	/* %jp{割込みハンドラ定義} */
	dfinh.inthdr = (FP)OsTimer_IrqHandler;
/*	def_inh(INHNO_OSTIMER, &dfinh);	*/
	
	/* %jp{タイマ動作開始} */
	
	/* %jp{割込み許可} */
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_IrqHandler(void)
{
	
	isig_tim();
}


/* end of file */
