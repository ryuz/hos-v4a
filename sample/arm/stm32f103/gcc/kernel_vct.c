/* ------------------------------------------------------------------------ */
/*  HOS-V4a  kernel configuration                                           */
/*                                                                          */
/* ------------------------------------------------------------------------ */


#include "kernel.h"
#include "arch/proc/arm/cortex_m3/procatr.h"
#include "arch/proc/arm/cortex_m3/proc.h"
#include "arch/irc/none/ircatr.h"
#include "arch/irc/none/irc.h"
#include "config/cfgknl.h"
#include "parser/parsknl.h"
#include "core/objid.h"
#include "core/objhdl.h"
#include "object/tskobj.h"
#include "object/semobj.h"
#include "object/flgobj.h"
#include "object/dtqobj.h"
#include "object/mbxobj.h"
#include "object/mtxobj.h"
#include "object/mpfobj.h"
#include "object/inhobj.h"
#include "object/isrobj.h"
#include "object/cycobj.h"
#include "kernel_id.h"

#include "ostimer.h"
#include "sample.h"



/* ------------------------------------------ */
/*        define interrupt handler            */
/* ------------------------------------------ */

extern VP       _kernel_int_stkblk[((512) + sizeof(VP) - 1) / sizeof(VP)];


_KERNEL_T_INHINF _kernel_inh_tbl[65] =
	{
		{(FP)(_kernel_reset_handler)},		/* reset handler */
		{(FP)(&_kernel_int_stkblk[((512) + sizeof(VP) - 1) / sizeof(VP)])},		/* stack pointer */
		{(FP)(_kernel_nmi_handler)},		/* non maskable intterupt handler */
		{(FP)(_kernel_hw_fault_handler)},		/* hard fault handler */
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
		{(FP)NULL},
	};



/* ------------------------------------------------------------------------ */
/*  End of file                                                             */
/* ------------------------------------------------------------------------ */
