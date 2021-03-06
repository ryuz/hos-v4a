/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  ostimer.c
 * @brief %jp{OSタイマ}%en{OS timer}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "hosaplfw.h"
#include "system/sysapi/sysapi.h"

#include "kernel.h"
#include "ostimer.h"


#define T0IR		((volatile UW *)0xe0004000)
#define T0TCR		((volatile UW *)0xe0004004)
#define T0TC		((volatile UW *)0xe0004008)
#define T0PR		((volatile UW *)0xe000400c)
#define T0PC		((volatile UW *)0xe0004010)
#define T0MCR		((volatile UW *)0xe0004014)
#define T0MR0		((volatile UW *)0xe0004018)
#define T0MR1		((volatile UW *)0xe000401c)
#define T0MR2		((volatile UW *)0xe0004020)
#define T0MR3		((volatile UW *)0xe0004024)
#define T0CCR		((volatile UW *)0xe0004028)
#define T0CR0		((volatile UW *)0xe000402c)
#define T0CR1		((volatile UW *)0xe0004030)
#define T0CR2		((volatile UW *)0xe0004034)
#define T0CR3		((volatile UW *)0xe0004038)
#define T0EMR		((volatile UW *)0xe000403c)

#define INTNO_TIMER0	4


static void OsTimer_Isr(VPARAM Param);		/**< %jp{タイマ割込みサービスルーチン} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(void)
{
	SysIsr_Create(INTNO_TIMER0, OsTimer_Isr, (VPARAM)0);
	SysInt_Enable(INTNO_TIMER0);
	
	/* %jp{タイマ動作開始} */
	*T0MR0 = 142000 / 4;
	*T0MCR = 0x0003;
	*T0TCR = 1;
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Isr(VPARAM Param)
{
	/* %jp{割込み要因クリア} */
	*T0IR= 1; 
	
	/* %jp{タイムティック供給} */
	SysTim_Signal(10000000);	/* 10ms */
}


/* end of file */
