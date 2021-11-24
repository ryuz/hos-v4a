/**
 *  Hyper Operating System V4 Advance
 *
 * @file clint_dis_int.c
 * @brief RISC-V Core-local Interruptor Disable Interrupt
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"



/* %jp{割込みの禁止} */
ER _kernel_riscv_irc_clint_dis_int(INTNO intno)
{

	if ( intno < _KERNEL_IRCATR_CLINT_TMIN_INTNO ||
	    intno > _KERNEL_IRCATR_CLINT_TMAX_INTNO )
	{
		return E_PAR;  /* %jp{有効な割込み番号の範囲外} */
	}


	/*
	  %jp{外部割込み以外の割込みマスクを操作し, 割込みをマスクする
	  外部割込みのマスク操作は, PLICで実施}
	 */
	if ( intno == _KERNEL_IRCATR_CLINT_MSOFT_INTNO ) /* %jp{ソフトウエア割り込み} */
		_kernel_riscv_irc_write_mie(
			_kernel_riscv_irc_read_mie()
			& ~( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MSIP_BIT ));
	else if ( intno == _KERNEL_IRCATR_CLINT_MTIMER_INTNO )  /* %jp{タイマ割り込み} */
		_kernel_riscv_irc_write_mie(
			_kernel_riscv_irc_read_mie()
			& ~( (UD)1 << _KERNEL_RISCV_IRC_CLINT_MTIP_BIT ));


	return E_OK;
}



/* end of file */
