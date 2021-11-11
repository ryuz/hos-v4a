/**
 *  Hyper Operating System V4 Advance
 *
 * @file  excobj.h
 * @brief %jp{CPU例外ハンドラのヘッダファイル}%en{CPU exception handler heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__object__excobj_h__
#define _KERNEL__object__excobj_h__

/* %jp{拡張情報の型} */
typedef VP_INT                 _KERNEL_EXC_T_EXINF;
/* %jp{CPU例外ハンドラの型} */
typedef void (*_KERNEL_EXC_T_EXCHDR)(void *exinf);

/* %jp{CPU例外ハンドラ情報} */
typedef struct _kernel_t_excinf
{
	FP exchdr;
} _KERNEL_T_EXCINF;


/** %jp{CPU例外ハンドラ情報テーブル} */
#if _KERNEL_SPT_DEF_EXC
extern       _KERNEL_T_EXCINF  _kernel_exc_tbl[_KERNEL_TMAX_EXC_EXCNO - _KERNEL_TMIN_EXC_EXCNO + 1];
#else
extern const _KERNEL_T_EXCINF  _kernel_exc_tbl[_KERNEL_TMAX_EXC_EXCNO - _KERNEL_TMIN_EXC_EXCNO + 1];
#endif

#define _KERNEL_EXC_GET_EXCINF(excno)		(&_kernel_exc_tbl[excno - _KERNEL_TMIN_EXC_EXCNO])

#define _KERNEL_EXC_GET_EXCHDR(excno)		((_KERNEL_EXC_T_EXCHDR)_KERNEL_EXC_GET_EXCINF(excno)->exchdr)
#define _KERNEL_EXC_SET_EXCHDR(excno, x)	do { _KERNEL_EXC_GET_EXCINF(excno)->exchdr = (x); } while(0)

#ifdef __cplusplus
extern "C" {
#endif

void _kernel_exe_exh(EXCNO excno, _KERNEL_EXC_T_EXINF exinf);
#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__excobj_h__ */



/* end of file */
