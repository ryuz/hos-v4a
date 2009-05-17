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



void OsTimer_Isr(VP_INT exinf);	/**< %jp{タイマ割込みサービスルーチン} */

extern VP _kernel_inh_tbl[224];

/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_CISR cisr;
	
	/* %jp{割込みサービスルーチン生成} */
	cisr.isratr = TA_HLNG;
	cisr.exinf  = 0;
	cisr.intno  = 0;
	cisr.isr    = (FP)OsTimer_Isr;
	acre_isr(&cisr);
	
	/* %jp{タイマ動作開始} */
	_kernel_outpb(0x43, 0x34);
	_kernel_outpb(0x40, 0x9c);	/* 11932 = 0x2e9c */
	_kernel_outpb(0x40, 0x2e);
	
	/* %jp{割込み許可} */
	ena_int(0);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Isr(VP_INT exinf)
{
	/* %jp{タイムティック供給} */
	isig_tim();
}


/* end of file */
