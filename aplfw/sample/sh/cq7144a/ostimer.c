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
#include "regs_sh7144.h"
#include "system/sysapi/sysapi.h"


#define PERIPHERAL_CLOCK		(24000000UL)				/**< %jp{ペリフェラルクロック(24MHz)} */


static void OsTimer_Isr(VPARAM Param);				/**< %jp{タイマ割込みハンドラ} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(void)
{
	/* %jp{割込みサービスルーチン登録} */
	SysIsr_Create(144, OsTimer_Isr, (VPARAM)0);
	
	/* %jp{タイマ動作開始} */
	*REG_STANDBY_MSTCR2 &= 0xefff;
	*REG_CMT_CMSTR  &= 0xfffe;								/* %jp{動作停止} */
	*REG_CMT0_CMCNT  = 0x0000;								/* %jp{カウンタクリア} */
	*REG_CMT0_CMCOR  = (PERIPHERAL_CLOCK / 128) / 1000;		/* %jp{1msに設定} */
	*REG_CMT0_CMCSR  = 0x0042;								/* %jp{128分周に設定} */
	*REG_CMT_CMSTR  |= 0x0001;								/* %jp{動作開始} */
	
	/* %jp{割込み許可} */
	*REG_INTC_IPRG = ((*REG_INTC_IPRG & 0xff0f) | 0x0010);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Isr(VPARAM Param)
{
	*REG_CMT0_CMCSR &= 0xff7f;
	
	SysTim_Signal(1000000UL);
}


/* end of file */
