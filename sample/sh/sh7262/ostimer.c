/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  ostimer.c
 * @brief %jp{OSタイマ}%en{OS timer}
 *
 * Copyright (C) 1998-2010 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"
#include "ostimer.h"
#include "regs_sh7262.h"


#define INHNO_OSTIMER			175							/**< %jp{割込みハンドラ番号} */
#define PERIPHERAL_CLOCK		(24000000UL)				/**< %jp{ペリフェラルクロック(24MHz)} */


static void OsTimer_IrqHandler(void);						/**< %jp{タイマ割込みハンドラ} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_DINH dfinh;
	
	/* %jp{割込みハンドラ定義} */
	dfinh.inthdr = (FP)OsTimer_IrqHandler;
	def_inh(INHNO_OSTIMER, &dfinh);
	
	/* %jp{タイマ動作開始} */
	*REG_STBCR7     &= 0xfffb;								/* %jp{クロック供給} */
	*REG_CMT_CMSTR  &= 0xfffe;								/* %jp{動作停止} */
	*REG_CMT0_CMCNT  = 0x0000;								/* %jp{カウンタクリア} */
	*REG_CMT0_CMCOR  = (PERIPHERAL_CLOCK / 128) / 1000;		/* %jp{1msに設定} */
	*REG_CMT0_CMCSR  = 0x0042;								/* %jp{128分周に設定} */
	*REG_CMT_CMSTR  |= 0x0001;								/* %jp{動作開始} */
	
	/* %jp{割込み許可} */
	*REG_INTC_IPR10 = ((*REG_INTC_IPR10 & 0xff0f) | 0x0010);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_IrqHandler(void)
{
	/* %jp{フラグクリア}%en{flag clear} */
	*REG_CMT0_CMCSR &= 0xff7f;
	
	isig_tim();
}


/* end of file */
