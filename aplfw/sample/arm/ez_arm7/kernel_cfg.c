/* ------------------------------------------------------------------------ */
/*  HOS-V4a  kernel configuration                                           */
/*    kernel object create and initialize                                   */
/*                                                                          */
/* ------------------------------------------------------------------------ */


#include "kernel.h"
#include "arch/proc/arm/arm_v4t/procatr.h"
#include "arch/proc/arm/arm_v4t/proc.h"
#include "arch/irc/arm/lpc2000/ircatr.h"
#include "arch/irc/arm/lpc2000/irc.h"
#include "config/cfgknl.h"
#include "parser/parsknl.h"
#include "core/objid.h"
#include "core/objhdl.h"
#include "object/tskobj.h"
#include "object/semobj.h"
#include "object/flgobj.h"
#include "object/mbxobj.h"
#include "object/mpfobj.h"
#include "object/inhobj.h"
#include "object/isrobj.h"
#include "object/cycobj.h"
#include "kernel_id.h"

#include "ostimer.h"
#include "sample.h"



/* ------------------------------------------ */
/*                kernel heap                 */
/* ------------------------------------------ */

VP_INT _kernel_hep_memblk[((4096) + sizeof(VP_INT) - 1) / sizeof(VP_INT)];



/* ------------------------------------------ */
/*               system stack                 */
/* ------------------------------------------ */

VP         _kernel_sys_stkblk[((256) + sizeof(VP) - 1) / sizeof(VP)];	/* system stack block*/




/* ------------------------------------------ */
/*             interrupt stack                */
/* ------------------------------------------ */

VP       _kernel_int_stkblk[((512) + sizeof(VP) - 1) / sizeof(VP)];
const VP _kernel_int_isp = &_kernel_int_stkblk[((512) + sizeof(VP) - 1) / sizeof(VP)];



/* ------------------------------------------ */
/*          create task objects               */
/* ------------------------------------------ */

static VP _kernel_tsk1_stk[((1024) + sizeof(VP) - 1) / sizeof(VP)];

_KERNEL_T_TCB _kernel_tcb_tbl[32] =
	{
		{{0}, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (_KERNEL_TSK_T_EXINF)(0), (Sample_Task), (2), ((VB*)_kernel_tsk1_stk + sizeof(_kernel_tsk1_stk)), },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
	};

const ID	_kernel_max_tskid = 32;



/* ------------------------------------------ */
/*         create semaphore objects           */
/* ------------------------------------------ */

_KERNEL_T_SEMCB _kernel_semcb_tbl[32] =
	{
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
	};

const ID	_kernel_max_semid = 32;



/* ------------------------------------------ */
/*        create eventflag objects            */
/* ------------------------------------------ */

_KERNEL_T_FLGCB _kernel_flgcb_tbl[32] =
	{
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
		{0},
	};

const ID	_kernel_max_flgid = 32;



/* ------------------------------------------ */
/*         create mailbox objects             */
/* ------------------------------------------ */

_KERNEL_T_MBXCB _kernel_mbxcb_tbl[32] =
	{
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
	};

const ID	_kernel_max_mbxid = 32;



/* ------------------------------------------ */
/*   create fixed size memory-pool objects    */
/* ------------------------------------------ */

_KERNEL_T_MPFCB _kernel_mpfcb_tbl[32] =
	{
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
		{{0}, },
	};

const ID	_kernel_max_mpfid = 32;



/* ------------------------------------------ */
/*                 system                     */
/* ------------------------------------------ */

const _KERNEL_T_SYSCB_RO _kernel_syscb_ro =
	{
		{
			TIC_NUME / TIC_DENO,
			TIC_NUME % TIC_DENO,
			TIC_DENO,
		},
	};

_KERNEL_T_SYSCB _kernel_syscb;




/* ------------------------------------------ */
/*       create cyclic handler objects        */
/* ------------------------------------------ */

const ID	_kernel_max_cycid = 0;



/* ------------------------------------------ */
/*        define interrupt handler            */
/* ------------------------------------------ */


_KERNEL_T_INHINF _kernel_inh_tbl[2] =
	{
		{(FP)NULL},
		{(FP)NULL},
	};




/* ------------------------------------------ */
/*        interrupt control objects           */
/* ------------------------------------------ */

const INTNO _kernel_min_intno = 0;
const INTNO _kernel_max_intno = 31;

_KERNEL_T_INTINF _kernel_int_tbl[32];


_KERNEL_T_ISRCB *_kernel_isrcb_tbl[32];
const ID        _kernel_max_isrid = 32;



/* ------------------------------------------ */
/*          initialize functions              */
/* ------------------------------------------ */

/* object initialize */
void _kernel_cfg_ini(void)
{
	_KERNEL_SYS_INI_HEP(sizeof(_kernel_hep_memblk), _kernel_hep_memblk);
	_KERNEL_SYS_INI_SYSSTK((SIZE)sizeof(_kernel_sys_stkblk), (VP)(_kernel_sys_stkblk));
	_KERNEL_SYS_INI_INTSTK((SIZE)sizeof(_kernel_int_stkblk), (VP)(_kernel_int_stkblk));
}

/* start up */
void _kernel_cfg_sta(void)
{
	act_tsk(TSKID_SAMPLE);

	/* call initialize routine*/
	((FP)(OsTimer_Initialize))((VP_INT)(0));
}


/* ------------------------------------------------------------------------ */
/*  End of file                                                             */
/* ------------------------------------------------------------------------ */
