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


#define INTNO_TIMER			0

#define REG_TIMER_BASE		0x41c00000
#define REG_TIMER_TCSR0		((volatile unsigned long *)(REG_TIMER_BASE + 0x00))
#define REG_TIMER_TLR0		((volatile unsigned long *)(REG_TIMER_BASE + 0x04))
#define REG_TIMER_TCR0		((volatile unsigned long *)(REG_TIMER_BASE + 0x08))
#define REG_TIMER_TCSR1		((volatile unsigned long *)(REG_TIMER_BASE + 0x10))
#define REG_TIMER_TLR1		((volatile unsigned long *)(REG_TIMER_BASE + 0x14))
#define REG_TIMER_TCR1		((volatile unsigned long *)(REG_TIMER_BASE + 0x18))


static void OsTimer_Isr(VP_INT exinf);		/**< %jp{タイマ割込みサービスルーチン} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_CISR cisr;
	
	/* %jp{割込みサービスルーチン生成} */
	cisr.isratr = TA_HLNG;
	cisr.exinf  = 0;
	cisr.intno  = INTNO_TIMER;
	cisr.isr    = (FP)OsTimer_Isr;
	acre_isr(&cisr);
	
	/* 開始 */
	*REG_TIMER_TLR0  = 100000 - 1;		/* 1ms 100MHz */
	*REG_TIMER_TCSR0 = 0x0132;			/* clear int, load counter */
	*REG_TIMER_TCSR0 = 0x00d2;			/* start */
	
	/* 割込み許可 */
	ena_int(INTNO_TIMER);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Isr(VP_INT exinf)
{
	*REG_TIMER_TCSR0 |= 0x0100;			/* clear int */
	vclr_int(INTNO_TIMER);
	
	/* %jp{タイムティック供給} */
	isig_tim();
}



/* end of file */
