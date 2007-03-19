/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  intc.h
 * @brief %jp{ADuC7019/20/21/22/24/25/26/27用割り込みコントローラ操作}%en{ADuC7019/20/21/22/24/25/26/27}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


#define IRQSTA		(*(volatile UW *)0xffff0000)
#define IRQSIG		(*(volatile UW *)0xffff0004)
#define IRQEN		(*(volatile UW *)0xffff0008)
#define IRQCLR		(*(volatile UW *)0xffff000c)

#define FIQSTA		(*(volatile UW *)0xffff0100)
#define FIQSIG		(*(volatile UW *)0xffff0104)
#define FIQEN		(*(volatile UW *)0xffff0108)
#define FIQCLR		(*(volatile UW *)0xffff010c)



void _kernel_arm_irq(void);
void _kernel_arm_fiq(void);


/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	IRQCLR = 0x00ffffff;
	FIQCLR = 0x00ffffff;
	
	_kernel_inh_tbl[_KERNEL_ARM_INHNO_IRQ].inthdr = (FP)_kernel_arm_irq;
	_kernel_inh_tbl[_KERNEL_ARM_INHNO_FIQ].inthdr = (FP)_kernel_arm_fiq;
}

void _kernel_exe_irc(INHNO inhno)
{
	switch ( inhno )
	{
	case _KERNEL_ARM_INHNO_IRQ:
		_kernel_arm_irq();
		break;

	case _KERNEL_ARM_INHNO_FIQ:
		_kernel_arm_fiq();
		break;
	}
}


/** %jp{IRQ割り込み処理開始} */
void _kernel_arm_irq(void)
{
	INTNO intno;
	UW    irqsta;
	
	irqsta = IRQSTA;
	
	/* 割り込み番号取得 */
	for ( intno = 0; intno <= 23; intno++ )
	{
		if ( irqsta & 1 )
		{
			/* 割込みサービスルーチン呼び出し */
			_kernel_exe_isr(intno);
		}
		
		irqsta >>= 1;
	}
}


/* FIQ割り込み処理開始 */
void _kernel_arm_fiq(void)
{
	INTNO intno;
	UW    fiqsta;
	
	fiqsta = FIQSTA;
	
	/* 割り込み番号取得 */
	for ( intno = 0; intno <= 23; intno++ )
	{
		if ( fiqsta & 1 )
		{
			/* 割込みサービスルーチン呼び出し */
			_kernel_exe_isr(intno);
		}
		
		fiqsta >>= 1;
	}
}


/* 割り込みの許可 */
ER ena_int(INTNO intno)
{
	IRQEN |= (1 << intno);
	
	return E_OK;
}


/* 割り込みの禁止 */
ER dis_int(INTNO intno)
{
	IRQCLR = (1 << intno);

	return E_OK;
}



/* end of file */
