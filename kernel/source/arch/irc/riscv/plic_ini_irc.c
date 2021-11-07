/**
 *  Hyper Operating System V4 Advance
 *
 * @file  plic_ini_irc.c
 * @brief RISC-V Platform-Level Interrupt Controller Initialization
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"

extern _KERNEL_T_INTINF _kernel_int_tbl[];

/** %jp{割込みコントローラの初期化} */
void _kernel_riscv_irc_plic_ini_irc(void)
{
	int                    i;
	INTNO                irq;
	_KERNEL_T_ISRHDL  isrhdl;
	UD               curhart;

	curhart = _kernel_riscv_get_hartid();  /* %jp{自コアのhartid獲得} */

	for( i = _KERNEL_IRCATR_PLIC_TMIN_INTNO;
	     _KERNEL_IRCATR_PLIC_TMAX_INTNO > i;
	     ++i){

		isrhdl = _KERNEL_INT_GET_HEAD(i);   /* %jp{ISRハンドラ参照} */

		/* %jp{割込み番号をIRQ番号に変換} */
		irq = i - _KERNEL_IRCATR_PLIC_TMIN_INTNO;

		/* %jp{ISR未登録な割込みをマスクし, ISR登録済み割込みのマスクを解放} */
		if ( isrhdl == _KERNEL_ISRHDL_NULL )
			*_KERNEL_RISCV_IRC_PLIC_MENABLE_REG(curhart, irq)
				&= ~(1 << (irq % 32));  /* %jp{割込みをマスク} */
		else
			*_KERNEL_RISCV_IRC_PLIC_MENABLE_REG(curhart, irq)
				|= (1 << (irq % 32));  /* %jp{割込みをアンマスク} */

	}

	*_KERNEL_RISCV_IRC_PLIC_MPRIO_REG(curhart) = 0;  /* 優先度を0に設定 */
}

/* end of file */
