/**
 *  Hyper Operating System V4 Advance
 *
 * @file clint_clr_int.c
 * @brief RISC-V Core-local Interruptor Clear Interrupt Request
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みの許可} */
ER _kernel_riscv_irc_clint_clr_int(INTNO intno)
{

	if ( intno < _KERNEL_IRCATR_CLINT_TMIN_INTNO ||
	    intno > _KERNEL_IRCATR_CLINT_TMAX_INTNO )
	{
		return E_PAR;  /* %jp{有効な割込み番号の範囲外} */
	}


	/*
	  %jp{タイマ割込みで無ければ割込みペンディングビットをクリア
	  MIPのタイマ割込みビットは, 読み取り専用ビットであるため書き換えない
	  (CLICのTIMECMPレジスタへの書込みによりビットクリアされる)}
	 */
	if ( intno != _KERNEL_IRCATR_CLINT_MTIMER_INTNO )
		_kernel_riscv_irc_write_mip(_kernel_riscv_irc_read_mip()
		    & ~( (UD)1 << intno ));

	return E_OK;
}


/* end of file */
