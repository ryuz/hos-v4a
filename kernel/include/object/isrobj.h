/**
 *  Hyper Operating System V4 Advance
 *
 * @file  int.h
 * @brief %jp{割り込み制御のヘッダファイル}%en{interrupt control heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__object__isrobj_h__
#define _KERNEL__object__isrobj_h__


typedef struct _kernel_t_isrcb*	_KERNEL_T_ISRHDL;


/* %jp{割込み情報} */
typedef struct _kernel_t_intinf
{
	_KERNEL_T_ISRHDL head;
} _KERNEL_T_INTINF;


/** %jp{割込み情報テーブル} */
#if _KERNEL_SPT_CRE_ISR || _KERNEL_SPT_ACRE_ISR
extern       _KERNEL_T_INTINF	_kernel_int_tbl[_KERNEL_IRCATR_TMAX_INHNO - _KERNEL_IRCATR_TMIN_INHNO + 1];
#else
extern const _KERNEL_T_INTINF	_kernel_int_tbl[_KERNEL_IRCATR_TMAX_INHNO - _KERNEL_IRCATR_TMIN_INHNO + 1];
#endif

#define _KERNEL_INT_GET_INTINF(intno)		(&_kernel_int_tbl[intno - _KERNEL_IRCATR_TMIN_INHNO])

#define _KERNEL_INT_GET_HEAD(intno)			(_KERNEL_INT_GET_INTINF(intno)->head)
#define _KERNEL_INT_SET_HEAD(intno, x)		do { _KERNEL_INT_GET_INTINF(intno)->head = (x); } while (0)



/* %jp{割込みサービスルーチン制御ブロック} */
typedef struct _kernel_t_isrcb
{
	VP_INT           exinf;						/**< %jp{割込みサービスルーチンの拡張情報} */
	FP               isr;						/**< %jp{割込みサービスルーチンの起動番地} */
	_KERNEL_T_ISRHDL next;
} _KERNEL_T_ISRCB;


/* 割り込みサービスルーチン */
extern _KERNEL_T_ISRCB  *_kernel_isrcb_tbl[];	/* 割込みサービスルーチンコントロールブロックテーブル */
extern const ID			_kernel_max_isrid;		/* 割込みサービスルーチンコントロールブロックの個数 */


#define _KERNEL_TMIN_ISR_ISRID					1
#define _KERNEL_TMAX_ISR_ISRID					(_kernel_max_isrid)


#define _KERNEL_ISR_ID2ISRCB(isrid)				(_kernel_isrcb_tbl[(isrid) - _KERNEL_TMIN_ISR_ISRID])
#define _KERNEL_ISR_ID2ISRHDL(isrid)			(_kernel_isrcb_tbl[(isrid) - _KERNEL_TMIN_ISR_ISRID])

#define _KERNEL_ISR_ISRPTR2ISRCB(isrhdl)		(isrhdl)
#define _KERNEL_ISR_CHECK_EXS(isrid)			(_kernel_isrcb_tbl[(isrid) - _KERNEL_TMIN_ISR_ISRID] != NULL)


#define _KERNEL_ISR_GET_EXINF(isrhdl)			(_KERNEL_ISR_ISRPTR2ISRCB(isrhdl)->exinf)
#define _KERNEL_ISR_SET_EXINF(isrhdl, x)		do { (_KERNEL_ISR_ISRPTR2ISRCB(isrhdl)->exinf) = (x); } while (0)

#define _KERNEL_ISR_GET_ISR(isrhdl)				(_KERNEL_ISR_ISRPTR2ISRCB(isrhdl)->isr)
#define _KERNEL_ISR_SET_ISR(isrhdl, x)			do { (_KERNEL_ISR_ISRPTR2ISRCB(isrhdl)->isr) = (x); } while (0)

#define _KERNEL_ISR_GET_NEXT(isrhdl)			(_KERNEL_ISR_ISRPTR2ISRCB(isrhdl)->next)
#define _KERNEL_ISR_SET_NEXT(isrhdl, x)			do { (_KERNEL_ISR_ISRPTR2ISRCB(isrhdl)->next) = (x); } while (0)




/* ------------------------------------------ */
/*                関数宣言                    */
/* ------------------------------------------ */


#ifdef __cplusplus
extern "C" {
#endif

ER   _kernel_cre_isr(ID isrid, const T_CISR *pk_cisr);
void _kernel_exe_isr(INTNO intno);

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__isrobj_h__ */



/* end of file */
