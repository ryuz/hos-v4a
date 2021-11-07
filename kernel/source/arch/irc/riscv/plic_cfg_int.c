/**
 *  Hyper Operating System V4 Advance
 *
 * @file plic_cfg_int.c
 * @brief RISC-V Platform-Level Interrupt Controller Configure Interrupt Ready Queue Line
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込み線の設定} */
ER _kernel_riscv_irc_plic_cfg_int(INTNO intno, T_CINT *pk_cint)
{

	/* %jp{設定不可能な割込み線を指定した} */
	if ( VALID_INTNO_CFGINT(intno) !=  E_OK )
	{
		return E_RSATR;
	}

	/* %jp{設定不可能な優先度を指定した} */
	if ( pk_cint->intpri < _KERNEL_IRCATR_PLIC_TMIN_PRIO ||
	    pk_cint->intpri > _KERNEL_IRCATR_PLIC_TMAX_PRIO )
	{
		return E_PAR;
	}

	/* %jp{エッジトリガ割込み指定にもかかわらず, レベルトリガのフラグが設定されている} */
	if ( ( pk_cint->intatr & TA_EDGE )
	    && ( pk_cint->intatr & ( TA_LOWLEVEL |TA_HIGHLEVEL ) ) )
	{
		return E_PAR;
	}

	/* %jp{レベルトリガ割込み指定にもかかわらず, レベルトリガのフラグが設定されていない} */
	if ( ( ( pk_cint->intatr & TA_EDGE ) == 0 )
	    && ( ( pk_cint->intatr & ( TA_LOWLEVEL |TA_HIGHLEVEL ) ) == 0 ) )
	{
		return E_PAR;
	}

	/* %jp{エッジトリガ割込み指定にもかかわらず, トリガ種別が設定されていない} */
	if ( ( pk_cint->intatr & TA_EDGE )
	    && ( ( pk_cint->intatr & ( TA_POSEDGE | TA_NEGEDGE )  ) == 0 ) )
	{
		return E_PAR;
	}


	/* %jp{対象IRQの割込み優先度レジスタに割込み優先度を設定} */
	*_KERNEL_RISCV_IRC_PLIC_PRIO_REG( _KERNEL_RISCV_IRC_PLIC_INTNO2IRQ(intno) )
		= -1 * pk_cint->intpri;

	/* %jp{割込み要求禁止フラグをクリア} */
	if ( pk_cint->intatr & TA_ENAINT )
        {
		return _kernel_riscv_irc_plic_ena_int(intno);
	}

	return E_OK;
}

/* end of file */
