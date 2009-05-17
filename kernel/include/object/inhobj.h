/**
 *  Hyper Operating System V4 Advance
 *
 * @file  inhobj.h
 * @brief %jp{割込み制御のヘッダファイル}%en{interrupt control heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__object__inhobj_h__
#define _KERNEL__object__inhobj_h__


/* %jp{割込みハンドラ情報} */
typedef struct _kernel_t_inhinf
{
	FP inthdr;
} _KERNEL_T_INHINF;


/** %jp{割込みハンドラ情報テーブル} */
#if _KERNEL_SPT_DEF_INH
extern       _KERNEL_T_INHINF  _kernel_inh_tbl[_KERNEL_TMAX_INH_INHNO - _KERNEL_TMIN_INH_INHNO + 1];
#else
extern const _KERNEL_T_INHINF  _kernel_inh_tbl[_KERNEL_TMAX_INH_INHNO - _KERNEL_TMIN_INH_INHNO + 1];
#endif

#define _KERNEL_INT_GET_INHINF(inhno)		(&_kernel_inh_tbl[inhno - _KERNEL_TMIN_INH_INHNO])

#define _KERNEL_INH_GET_INTHDR(inhno)		(_KERNEL_INT_GET_INHINF(inhno)->inthdr);
#define _KERNEL_INH_SET_INTHDR(inhno, x)	do { _KERNEL_INT_GET_INHINF(inhno)->inthdr = (x); } while(0)


#ifdef __cplusplus
extern "C" {
#endif

void _kernel_sta_inh(void);
void _kernel_exe_inh(INHNO inhno);
void _kernel_end_inh(void);

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__core__inh_h__ */



/* end of file */
