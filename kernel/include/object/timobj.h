/**
 *  Hyper Operating System V4 Advance
 *
 * @file  timobj.h
 * @brief %jp{時間管理オジェクトのヘッダファイル}%en{Time object heder file}
 *
 * @version $Id: timobj.h,v 1.1 2006-08-18 09:21:59 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__timobj_h__
#define _KERNEL__object__timobj_h__



/* ------------------------------------------ */
/*  Primitive type definition                 */
/* ------------------------------------------ */

/* %jp{タイムティックの除算結果} (TIC_NUME / TIC_DENO) */
typedef RELTIM				_KERNEL_TIMCB_T_TICDIV;
#define _KERNEL_TIMCB_TBITDEF_TICDIV

/* %jp{タイムティックの除算の余り結果} (TIC_NUME % TIC_DENO) */
typedef RELTIM				_KERNEL_TIMCB_T_TICDIV;
#define _KERNEL_TIMCB_TBITDEF_TICDIV

/* %jp{タイムティックの分母} (TIC_DENO) */
typedef RELTIM				_KERNEL_TIMCB_T_TICDENO;
#define _KERNEL_TIMCB_TBITDEF_TICDENO

/* %jp{分数繰上げ用のカウンタ} */
typedef RELTIM				_KERNEL_TIMCB_T_TICCNT;
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


/** %jp{時間管理コントロールブロック}%en{Time-Manegement Control Block} */
typedef struct _kernel_t_timcb
{
#if _KERNEL_SEMCB_SEMCNT
	SYSTIM					systim;											/**< %jp{現在のシステム時刻} */
#endif

#if _KERNEL_TIMCB_SEMCNT
	_KERNEL_TIMCB_T_TICCNT	ticcnt		_KERNEL_TIMCB_TBITDEF_TICCNT;		/**< %jp{分数繰上げ用のカウンタ} */
} _KERNEL_T_TIMCB;



/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */

const _KERNEL_T_TIMCB_RO	_kernel_timcb_ro;
_KERNEL_T_TIMCB_RO			_kernel_timcb;



/* ------------------------------------------ */
/*   Accessor for TIMCB                       */
/* ------------------------------------------ */

/* ticvid */
#if _KERNEL_TIMCB_TICDIV
#define _KERNEL_TIM_GET_TICDIV()			(_kernel_timcb_ro.ticdiv)
#else
#define _KERNEL_TIM_GET_TICDIV()			(1)
#endif

/* ticmod */
#if _KERNEL_TIMCB_TICMOD
#define _KERNEL_TIM_GET_TICMOD()			(_kernel_timcb_ro.ticmod)
#else
#define _KERNEL_TIM_GET_TICMOD()			(0)
#endif

/* ticdeno */
#if _KERNEL_TIMCB_TICDENO
#define _KERNEL_TIM_GET_TICDENO()			(_kernel_timcb_ro.ticmod)
#else
#define _KERNEL_TIM_GET_TICDENO()			(1)
#endif

/* systim */
#if _KERNEL_TIMCB_SYSTIM
#define _KERNEL_TIM_GET_SYSTIM()			(&_kernel_timcb.systim)
#define _KERNEL_TIM_ADD_SYSTIM(tic)			_KERNEL_SYSTIM_ADD(&_kernel_timcb.systim, (tic))
#else
#define _KERNEL_TIM_GET_SYSTIM()			(NULL)
#define _KERNEL_TIM_ADD_SYSTIM(tic)			do {} while(0)
#endif

/* ticcnt */
#if _KERNEL_TIMCB_TICCNT
#define _KERNEL_TIM_GET_TICCNT()			(_kernel_timcb.ticcnt)
#define _KERNEL_TIM_SET_TICCNT(cnt)			do { _kernel_timcb.ticcnt = (cnt); } while (0)
#else
#define _KERNEL_TIM_GET_TICCNT()			(1)
#define _KERNEL_TIM_SET_TICCNT(cnt)			do {} while (0)
#endif



#endif	/* _KERNEL__object__timobj_h__ */


/* end of file */
