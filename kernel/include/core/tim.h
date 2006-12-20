/**
 *  Hyper Operating System V4 Advance
 *
 * @file  tim.h
 * @brief %jp{時間管理のヘッダファイル}%en{Time management heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__core__tim_h__
#define _KERNEL__core__tim_h__


/* ------------------------------------------ */
/*  Primitive type definition                 */
/* ------------------------------------------ */

/* %jp{タイムティックの除算結果} (TIC_NUME / TIC_DENO) */
typedef RELTIM							_KERNEL_TIMCB_T_TICDIV;
#define _KERNEL_TIMCB_TBITDEF_TICDIV

/* %jp{タイムティックの除算の余り結果} (TIC_NUME % TIC_DENO) */
typedef RELTIM							_KERNEL_TIMCB_T_TICMOD;
#define _KERNEL_TIMCB_TBITDEF_TICMOD

/* %jp{タイムティックの分母} (TIC_DENO) */
typedef RELTIM							_KERNEL_TIMCB_T_TICDENO;
#define _KERNEL_TIMCB_TBITDEF_TICDENO

/* %jp{分数繰上げ用のカウンタ} */
typedef UB							_KERNEL_TIMCB_T_TICCNT;
#define _KERNEL_TIMCB_TBITDEF_TICCNT



/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

/** %jp{時間管理コントロールブロック(リードオンリー部)}%en{Time-Manegement Control Block(read-only)} */
typedef struct _kernel_t_timcb_ro
{
#if _KERNEL_TIMCB_TICDIV
	_KERNEL_TIMCB_T_TICDIV	ticdiv		_KERNEL_TIMCB_TBITDEF_TICDIV;		/**< %jp{タイムティックの除算結果} (TIC_NUME / TIC_DENO) */
#endif

#if _KERNEL_TIMCB_TICMOD
	_KERNEL_TIMCB_T_TICMOD	ticmod		_KERNEL_TIMCB_TBITDEF_TICMOD;		/**< %jp{タイムティックの除算の余り結果} (TIC_NUME % TIC_DENO) */
#endif

#if _KERNEL_TIMCB_TICDENO
	_KERNEL_TIMCB_T_TICDENO	ticdeno		_KERNEL_TIMCB_TBITDEF_TICDENO;		/**< %jp{タイムティックの分母} (TIC_DENO) */
#endif
} _KERNEL_T_TIMCB_RO;

typedef const _KERNEL_T_TIMCB_RO*	_KERNEL_T_TIMCB_RO_PTR;


/** %jp{時間管理コントロールブロック}%en{Time-Manegement Control Block} */
typedef struct _kernel_t_timcb
{
#if _KERNEL_TIMCB_SYSTIM
	SYSTIM					systim;											/**< %jp{現在のシステム時刻} */
#endif

#if _KERNEL_TIMCB_TICCNT
	_KERNEL_TIMCB_T_TICCNT	ticcnt		_KERNEL_TIMCB_TBITDEF_TICCNT;		/**< %jp{分数繰上げ用のカウンタ} */
#endif

#if _KERNEL_TIMCB_TICCNT
	_KERNEL_TIMCB_T_TICCNT	ticnxt		_KERNEL_TIMCB_TBITDEF_TICCNT;		/**< %jp{次のティックカウンタ} */
#endif
} _KERNEL_T_TIMCB;

typedef _KERNEL_T_TIMCB*	_KERNEL_T_TIMCB_PTR;


/* ------------------------------------------ */
/*   Accessor for TIMCB                       */
/* ------------------------------------------ */

/* ticvid */
#if _KERNEL_TIMCB_TICDIV
#define _KERNEL_TIM_GET_TICDIV(timcb_ro)		((timcb_ro)->ticdiv)
#else
#define _KERNEL_TIM_GET_TICDIV(timcb_ro)		(1)
#endif

/* ticmod */
#if _KERNEL_TIMCB_TICMOD
#define _KERNEL_TIM_GET_TICMOD(timcb_ro)		((timcb_ro)->ticmod)
#else
#define _KERNEL_TIM_GET_TICMOD(timcb_ro)		(0)
#endif

/* ticdeno */
#if _KERNEL_TIMCB_TICDENO
#define _KERNEL_TIM_GET_TICDENO(timcb_ro)		((timcb_ro)->ticmod)
#else
#define _KERNEL_TIM_GET_TICDENO(timcb_ro)		(1)
#endif

/* systim */
#if _KERNEL_TIMCB_SYSTIM
#define _KERNEL_TIM_GET_SYSTIM(timcb)			(&(timcb)->systim)
#define _KERNEL_TIM_SET_SYSTIM(timcb, p_tim)	do { (timcb)->systim = *(p_tim); } while(0)
#define _KERNEL_TIM_ADD_SYSTIM(timcb, tic)		_KERNEL_SYSTIM_ADD(&(timcb)->systim, (tic))
#else
#define _KERNEL_TIM_GET_SYSTIM(timcb)			(NULL)
#define _KERNEL_TIM_SET_SYSTIM(timcb, p_tim)	do {} while(0)
#define _KERNEL_TIM_ADD_SYSTIM(timcb, tic)		do {} while(0)
#endif

/* ticcnt */
#if _KERNEL_TIMCB_TICCNT
#define _KERNEL_TIM_GET_TICCNT(timcb)			((timcb)->ticcnt)
#define _KERNEL_TIM_SET_TICCNT(timcb, cnt)		do { (timcb)->ticcnt = (cnt); } while (0)
#else
#define _KERNEL_TIM_GET_TICCNT()				(1)
#define _KERNEL_TIM_SET_TICCNT(cnt)				do {} while (0)
#endif

/* ticnxt */
#if _KERNEL_TIMCB_TICNXT
#define _KERNEL_TIM_GET_TICNXT(timcb)			((timcb)->ticnxt)
#define _KERNEL_TIM_SET_TICNXT(timcb, cnt)		do { (timcb)->ticnxt = (cnt); } while (0)
#else
#define _KERNEL_TIM_GET_TICNXT(timcb)			(1)
#define _KERNEL_TIM_SET_TICNXT(timcb, cnt)		do {} while (0)
#endif



#ifdef __cplusplus
extern "C" {
#endif

RELTIM _kernel_sig_tim(_KERNEL_T_TIMCB_PTR timcb, _KERNEL_T_TIMCB_RO_PTR timcb_ro);

#ifdef __cplusplus
}
#endif

#define _KERNEL_INI_TIM(timcb, timcb_ro)		_kernel_sig_tim((timcb), (timcb_ro))
#define _KERNEL_SIG_TIM(timcb, timcb_ro)		_kernel_sig_tim((timcb), (timcb_ro))
#define _KERNEL_GET_TIC(timcb, timcb_ro)		_KERNEL_TIM_GET_TICNXT(timcb)
#define _KERNEL_SET_TIM(timcb, p_tim)			_KERNEL_TIM_SET_SYSTIM((timcb), (p_tim))
#define _KERNEL_GET_TIM(timcb)					_KERNEL_TIM_GET_SYSTIM(timcb)


#endif	/* _KERNEL__core__tim_h__ */


/* end of file */
