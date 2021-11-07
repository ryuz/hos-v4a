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
#include "arch/irc/riscv/irc.h"

#define INTNO_TIMER0	1

static void OsTimer_Isr(VP_INT exinf);		/**< %jp{タイマ割込みサービスルーチン} */

UD _kernel_riscv_get_hartid(void);

/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_CISR    cisr;
	UD timeval;

	/* %jp{割込みサービスルーチン生成} */
	cisr.isratr = TA_HLNG;
	cisr.exinf  = 0;
	cisr.intno  = INTNO_TIMER0;
	cisr.isr    = (FP)OsTimer_Isr;
	acre_isr(&cisr);

	do{
		timeval = _riscv_get_time();
		/* %jp{タイマ値設定} */
		*_KERNEL_RISCV_IRC_CLINT_MTIMECMP_ADDR(_kernel_riscv_get_hartid())
			= timeval + _KERNEL_RISCV_IRC_CLINT_MTIME_INTERVAL;
		timeval = _riscv_get_time();
	}while(*_KERNEL_RISCV_IRC_CLINT_MTIMECMP_ADDR(_kernel_riscv_get_hartid()) < timeval);

	/* 割込み許可 */
	ena_int(INTNO_TIMER0);
}


/** %jp{タイマ割込みサービスルーチン} */
void OsTimer_Isr(VP_INT exinf)
{
	UD timeval;

	/* %jp{要因クリア} */
	vclr_int(INTNO_TIMER0);

	do{
		timeval = _riscv_get_time();
		/* %jp{タイマ値設定} */
		*_KERNEL_RISCV_IRC_CLINT_MTIMECMP_ADDR(_kernel_riscv_get_hartid())
			= timeval + _KERNEL_RISCV_IRC_CLINT_MTIME_INTERVAL;
		timeval = _riscv_get_time();
	}while(*_KERNEL_RISCV_IRC_CLINT_MTIMECMP_ADDR(_kernel_riscv_get_hartid()) < timeval);

	/* %jp{タイムティック供給} */
	isig_tim();
}



/* end of file */
