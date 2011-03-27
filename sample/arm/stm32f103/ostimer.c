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


#define REG_SCSR		((volatile UW *)0xE000E010)		/* SysTick Control and Status Register */
#define REG_SRVR		((volatile UW *)0xE000E014)		/* SysTick Reload Value Register */
#define REG_SCUVR		((volatile UW *)0xE000E018)		/* SysTick Current Value Register */
#define REG_SCAVR		((volatile UW *)0xE000E01c)		/* SysTick Calibration Value Register */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	/* %jp{タイマ動作開始} */
	*REG_SRVR  = 1000000;
	*REG_SCUVR = 0;
	*REG_SCSR  = 0x00000007;

	ena_int(15);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Isr(void)
{
	/* %jp{割込み要因クリア} */
	vclr_int(15);

	/* %jp{タイムティック供給} */
	isig_tim();
}


/* end of file */
