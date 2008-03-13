/**
 *  Hyper Operating System V4 Advance
 *
 * @file  objhdl.h
 * @brief %jp{オブジェクトハンドルの型定義}%en{define object handle}
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



/* ---------------------------------- */
/*         Mutex-Handle               */
/* ---------------------------------- */

#if _KERNEL_MTXHDL_ID		/* %jp{ミューテックスハンドルにIDを使う}%en{_KERNEL_T_MTXHDL is ID} */

typedef _KERNEL_T_MTXID			_KERNEL_T_MTXHDL;
#define _KERNEL_MTXHDL_NULL		0
#define _KERNEL_TBIT_MTXHDL		_KERNEL_TBIT_MTXID

#else						/* %jp{ミューテックスにMTXCBのアドレスを使う}%en{_KERNEL_T_MTXHDL is Pointer} */

struct _kernel_t_mtxcb;
typedef struct _kernel_t_mtxcb	*_KERNEL_T_MTXHDL;
#define _KERNEL_MTXHDL_NULL		NULL
#define _KERNEL_TBIT_MTXHDL		_KERNEL_TBIT_VP_INT

#endif


/* ---------------------------------- */
/*           Isr-Handle               */
/* ---------------------------------- */

#if _KERNEL_ISRHDL_ID		/* %jp{ISRハンドルにIDを使う}%en{_KERNEL_T_ISRHDL is ID} */

typedef _KERNEL_T_ISRID			_KERNEL_T_ISRHDL;
#define _KERNEL_ISRHDL_NULL		0
#define _KERNEL_TBIT_ISRHDL		_KERNEL_TBIT_ISRID

#else

struct _kernel_t_isrcb;
typedef struct _kernel_t_isrcb	*_KERNEL_T_ISRHDL;
#define _KERNEL_ISRHDL_NULL		0
#define _KERNEL_TBIT_ISRHDL		_KERNEL_TBIT_VP_INT

#endif


#endif	/* _KERNEL__core__objhdl_h__ */
