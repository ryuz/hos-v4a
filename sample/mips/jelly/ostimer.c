/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  ostimer.c
 * @brief %jp{OSタイマ}%en{OS timer}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "ostimer.h"


#define INTNO_TIMER0	0


static void OsTimer_Inh(void);		/**< %jp{タイマ割込みサービスルーチン} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_DINH dinh;
	
	dinh.inhatr = TA_HLNG;
	dinh.inthdr = (FP)OsTimer_Inh;
	def_inh(INTNO_TIMER0, &dinh);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Inh(void)
{
	/* %jp{タイムティック供給} */
	isig_tim();
}



/* end of file */
