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


#define T0LD	((volatile UH *)0xffff0300)
#define T0VAL	((volatile UH *)0xffff0304)
#define T0CON	((volatile UW *)0xffff0308)
#define T0CLRI	((volatile UB *)0xffff030C)


static void OsTimer_Isr(VP_INT exinf);	/**< %jp{タイマ割込みサービスルーチン} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_CISR cisr;
	
	/* %jp{割込みサービスルーチン生成} */
	cisr.isratr = TA_HLNG;
	cisr.exinf  = 0;
	cisr.intno  = 2;
	cisr.isr    = (FP)OsTimer_Isr;
	acre_isr(&cisr);
	ena_int(2);
	
	/* %jp{タイマ動作開始} */
	*T0LD  = 41779 - 1;		/* 41.7792MHz / 41779 = 1ms */
	*T0CON = 0xc0;
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Isr(VP_INT exinf)
{
	/* %jp{割込み要因クリア} */
	*T0CLRI = 0;
	
	/* %jp{タイムティック供給} */
	isig_tim();
}


/* end of file */
