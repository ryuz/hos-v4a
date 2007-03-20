/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  aduc7000.h
 * @brief %jp{ADuC7000シリーズ用割込みコントローラ操作}%en{ADuC7000 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _kernel__aduc7000_h__
#define _kernel__aduc7000_h__


#define IRQSTA		(*(volatile UW *)0xffff0000)
#define IRQSIG		(*(volatile UW *)0xffff0004)
#define IRQEN		(*(volatile UW *)0xffff0008)
#define IRQCLR		(*(volatile UW *)0xffff000c)

#define FIQSTA		(*(volatile UW *)0xffff0100)
#define FIQSIG		(*(volatile UW *)0xffff0104)
#define FIQEN		(*(volatile UW *)0xffff0108)
#define FIQCLR		(*(volatile UW *)0xffff010c)


#ifdef __cplusplus
extern "C" {
#endif

void _kernel_arm_irq(void);
void _kernel_arm_fiq(void);

#ifdef __cplusplus
}
#endif


#endif	/*  _kernel__aduc7000_h__ */


/* end of file */
