/** 
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  ostimer.c
 * @brief %jp{OSタイマ}%en{OS timer}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "hosaplfw.h"
#include "system/sysapi/sysapi.h"
#include "ostimer.h"


#define TC1_CCR		((volatile unsigned long *)0xfffd0000)		/* Channel Control Register */
#define TC1_CMR		((volatile unsigned long *)0xfffd0004)		/* Channel Mode Register */
#define TC1_CV		((volatile unsigned long *)0xfffd0010)		/* Counter Value */
#define TC1_RA		((volatile unsigned long *)0xfffd0014)		/* Register A */
#define TC1_RB		((volatile unsigned long *)0xfffd0018)		/* Register B */
#define TC1_RC		((volatile unsigned long *)0xfffd001c)		/* Register C */
#define TC1_SR		((volatile unsigned long *)0xfffd0020)		/* Status Register */
#define TC1_IER		((volatile unsigned long *)0xfffd0024)		/* Interrupt Enable Register */
#define TC1_IDR		((volatile unsigned long *)0xfffd0028)		/* Interrupt Disable Register */
#define TC1_IMR		((volatile unsigned long *)0xfffd002c)		/* Interrupt Mask Register */
#define TC_BCR		((volatile unsigned long *)0xfffd00c0)		/* TC Block Control Register */
#define TC_BMR		((volatile unsigned long *)0xfffd00c4)		/* TC Block Mode Register */


static void OsTimer_Isr(VPARAM Param);	/**< %jp{タイマ割込みサービスルーチン} */


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(void)
{
	*(volatile unsigned long *)0xfffff018 = 0x0025;

	*TC_BMR  = 0x00000000; 
	
	*TC1_CCR = 0x00000002;
	*TC1_IDR = 0x000000ff;
	
	*TC1_RC  = 9999;
	*TC1_CMR = 0x00004002;
	*TC1_IER = 0x00000010;
	
	*TC1_CCR = 0x00000001;
	*TC1_CCR = 0x00000004;
	
	
	SysIsr_Create(6, OsTimer_Isr, 0);
	SysInt_Enable(6);
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Isr(VPARAM Param)
{
	SysInt_Clear(6);
	
	if ( *TC1_SR & 0x00000010 )
	{
		/* %jp{タイムティック供給} */
		SysTim_Signal(1000000);
	}
}


/* end of file */
