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
#include "uart.h"

#define REG_TTC0_BASE					0xf8001000
#define REG_TTC1_BASE					0xf8002000

#define REG_TTC_BASE					REG_TTC0_BASE

#define REG_TTC_Clock_Control_1			((volatile UW*)(REG_TTC_BASE + 0x00000000))
#define REG_TTC_Clock_Control_2			((volatile UW*)(REG_TTC_BASE + 0x00000004))
#define REG_TTC_Clock_Control_3			((volatile UW*)(REG_TTC_BASE + 0x00000008))
#define REG_TTC_Counter_Control_1		((volatile UW*)(REG_TTC_BASE + 0x0000000C))
#define REG_TTC_Counter_Control_2		((volatile UW*)(REG_TTC_BASE + 0x00000010))
#define REG_TTC_Counter_Control_3		((volatile UW*)(REG_TTC_BASE + 0x00000014))
#define REG_TTC_Counter_Value_1			((volatile UW*)(REG_TTC_BASE + 0x00000018))
#define REG_TTC_Counter_Value_2			((volatile UW*)(REG_TTC_BASE + 0x0000001C))
#define REG_TTC_Counter_Value_3			((volatile UW*)(REG_TTC_BASE + 0x00000020))
#define REG_TTC_Interval_Counter_1		((volatile UW*)(REG_TTC_BASE + 0x00000024))
#define REG_TTC_Interval_Counter_2		((volatile UW*)(REG_TTC_BASE + 0x00000028))
#define REG_TTC_Interval_Counter_3		((volatile UW*)(REG_TTC_BASE + 0x0000002C))
#define REG_TTC_Match_1_Counter_1		((volatile UW*)(REG_TTC_BASE + 0x00000030))
#define REG_TTC_Match_1_Counter_2		((volatile UW*)(REG_TTC_BASE + 0x00000034))
#define REG_TTC_Match_1_Counter_3		((volatile UW*)(REG_TTC_BASE + 0x00000038))
#define REG_TTC_Match_2_Counter_1		((volatile UW*)(REG_TTC_BASE + 0x0000003C))
#define REG_TTC_Match_2_Counter_2		((volatile UW*)(REG_TTC_BASE + 0x00000040))
#define REG_TTC_Match_2_Counter_3		((volatile UW*)(REG_TTC_BASE + 0x00000044))
#define REG_TTC_Match_3_Counter_1		((volatile UW*)(REG_TTC_BASE + 0x00000048))
#define REG_TTC_Match_3_Counter_2		((volatile UW*)(REG_TTC_BASE + 0x0000004C))
#define REG_TTC_Match_3_Counter_3		((volatile UW*)(REG_TTC_BASE + 0x00000050))
#define REG_TTC_Interrupt_Register_1	((volatile UW*)(REG_TTC_BASE + 0x00000054))
#define REG_TTC_Interrupt_Register_2	((volatile UW*)(REG_TTC_BASE + 0x00000058))
#define REG_TTC_Interrupt_Register_3	((volatile UW*)(REG_TTC_BASE + 0x0000005C))
#define REG_TTC_Interrupt_Enable_1		((volatile UW*)(REG_TTC_BASE + 0x00000060))
#define REG_TTC_Interrupt_Enable_2		((volatile UW*)(REG_TTC_BASE + 0x00000064))
#define REG_TTC_Interrupt_Enable_3		((volatile UW*)(REG_TTC_BASE + 0x00000068))
#define REG_TTC_Event_Control_Timer_1	((volatile UW*)(REG_TTC_BASE + 0x0000006C))
#define REG_TTC_Event_Control_Timer_2	((volatile UW*)(REG_TTC_BASE + 0x00000070))
#define REG_TTC_Event_Control_Timer_3	((volatile UW*)(REG_TTC_BASE + 0x00000074))
#define REG_TTC_Event_Register_1		((volatile UW*)(REG_TTC_BASE + 0x00000078))
#define REG_TTC_Event_Register_2		((volatile UW*)(REG_TTC_BASE + 0x0000007C))
#define REG_TTC_Event_Register_3		((volatile UW*)(REG_TTC_BASE + 0x00000080))


static void OsTimer_Isr(VP_INT exinf);	/**< %jp{タイマ割込みサービスルーチン} */


#define USE_TTC0			1	/* TTC0 を使う */

#if USE_TTC0
#define OS_TIMER_INTNO		42  /* TTC0-1 */
#else
#define OS_TIMER_INTNO		61  /* 周期トリガが来るようにPLを設計  */
#endif


/** %jp{OS用タイマ初期化ルーチン} */
void OsTimer_Initialize(VP_INT exinf)
{
	T_CISR cisr;
	
	/* %jp{割込みサービスルーチン生成} */
	cisr.isratr = TA_HLNG;
	cisr.exinf  = 0;
	cisr.intno  = OS_TIMER_INTNO;
	cisr.isr    = (FP)OsTimer_Isr;
	acre_isr(&cisr);

	vchg_ilv(OS_TIMER_INTNO, 0xa0);
	ena_int(OS_TIMER_INTNO);

#if USE_TTC0
	/* %jp{タイマ動作開始} */
	*REG_TTC_Counter_Control_1 = 0x31;		/* stop and reset */
	*REG_TTC_Counter_Control_1 = 0x21;		/* stop */

	*REG_TTC_Clock_Control_1    = 0x03;		/* PS_VAL:1, PS_EN:1 */
	*REG_TTC_Interval_Counter_1 = 33333-1;	/* 1kHz (CPU_1x:133.333MHz) */

	*REG_TTC_Interrupt_Register_1 = 0x01;	/* Interrupt : Interval */
	*REG_TTC_Interrupt_Enable_1 = 0x01;		/* Interrupt enable */

	*REG_TTC_Counter_Control_1  = 0x22;		/* start */
#endif
}


/** %jp{タイマ割込みハンドラ} */
void OsTimer_Isr(VP_INT exinf)
{
	/* %jp{割込み要因クリア} */
#if USE_TTC0
	volatile UW dummy;
	dummy = *REG_TTC_Interrupt_Register_1;	/* 読み出すとクリア */
	(void)dummy;
#endif

//	vclr_int(OS_TIMER_INTNO);
	
	/* %jp{タイムティック供給} */
	isig_tim();
}


/* end of file */
