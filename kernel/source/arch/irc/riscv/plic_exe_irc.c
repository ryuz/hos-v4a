/**
 *  Hyper Operating System V4 Advance
 *
 * @file  plic_exe_irc.c
 * @brief RISC-V Platform-Level Interrupt Controller Initialization
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"

/** %jp{割込みコントローラの割込み処理} */
void _kernel_riscv_irc_plic_exe_irc(INHNO inhno)
{
	INTNO              irq;
	UW                mask;
	UW                prio;

	/* %jp{処理対象の割込みのIRQ番号を取得} */
	irq = *_KERNEL_RISCV_IRC_PLIC_MCLAIM_REG(_kernel_riscv_get_hartid());

	/* %jp{前処理} */
	/* %jp{処理対象の割込みのIRQからの割込み受付けをマスク} */
	*_KERNEL_RISCV_IRC_PLIC_MENABLE_REG(_kernel_riscv_get_hartid(), irq)
		&= ~_KERNEL_RISCV_IRC_PLIC_IRQBITMASK(irq);

	/* %jp{現在の割込み優先度マスク値をスタック上に保存} */
	mask = *_KERNEL_RISCV_IRC_PLIC_MPRIO_REG(_kernel_riscv_get_hartid());
	/* %jp{処理対象の割込みの割込み優先度を取得} */
	prio = *_KERNEL_RISCV_IRC_PLIC_PRIO_REG(irq);
	/* %jp{割込み優先度マスクを更新} */
	*_KERNEL_RISCV_IRC_PLIC_MPRIO_REG(_kernel_riscv_get_hartid()) = prio;

	/* %jp{割込みACKを送信} */
	if ( *_KERNEL_RISCV_IRC_PLIC_PEND_REG(irq) &
	    ( 1 << ( irq % ( _KERNEL_RISCV_IRC_PLIC_REGSIZE * 8 ) ) ) )
		*_KERNEL_RISCV_IRC_PLIC_PEND_REG(irq)
			&= ~_KERNEL_RISCV_IRC_PLIC_IRQBITMASK(irq);

	/* %jp{割込みサービスルーチン呼び出し} */
	_kernel_exe_isr(irq + _KERNEL_IRCATR_PLIC_TMIN_INTNO);

	/* %jp{割込み終了} */
	/* %jp{割込み優先度マスクを復元} */
	*_KERNEL_RISCV_IRC_PLIC_MPRIO_REG(_kernel_riscv_get_hartid()) = mask;
	/* %jp{処理対象の割込みのIRQからの割込み受付けを再開} */
	*_KERNEL_RISCV_IRC_PLIC_MENABLE_REG(_kernel_riscv_get_hartid(), irq)
		|= _KERNEL_RISCV_IRC_PLIC_IRQBITMASK(irq);
}


/* end of file */
