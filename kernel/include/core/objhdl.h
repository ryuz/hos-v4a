/**
 *  Hyper Operating System V4 Advance
 *
 * @file  objid.h
 * @brief %jp{タスクブジェクトのID用の型定義}%en{define object ID type}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core__objhdl_h__
#define _KERNEL__core__objhdl_h__


/* ---------------------------------- */
/*          Task-Handle               */
/* ---------------------------------- */

#if _KERNEL_TSKHDL_ID		/* %jp{タスクハンドルにIDを使う}%en{_KERNEL_T_TSKHDL is ID} */

typedef _KERNEL_T_TSKID			_KERNEL_T_TSKHDL;
#define _KERNEL_TSKHDL_NULL		0
#define _KERNEL_TBIT_TSKHDL		_KERNEL_TBIT_TSKID

#else						/* %jp{タスクハンドルにTCBのアドレスを使う}%en{_KERNEL_T_TSKHDL is Pointer} */

struct _kernel_t_tcb;
typedef struct _kernel_t_tcb	*_KERNEL_T_TSKHDL;
#define _KERNEL_TSKHDL_NULL		NULL
#define _KERNEL_TBIT_TSKHDL		_KERNEL_TBIT_VP_INT

#endif


#endif	/* _KERNEL__core__objhdl_h__ */
