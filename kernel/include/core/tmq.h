/**
 *  Hyper Operating System V4 Advance
 *
 * @file  toq.h
 * @brief %jp{タイムアウトキューのヘッダファイル}%en{time-out queue heder file}
 *
 * @version $Id: tmq.h,v 1.2 2006-09-10 14:54:26 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core__tmq_h__
#define _KERNEL__core__tmq_h__



/** %jp{タイマオブジェクト構造体} */
typedef struct _kernel_t_timobj
{
	struct _kernel_t_timobj	*next;		/**< %jp{次のオブジェクト} */
	struct _kernel_t_timobj	*prev;		/**< %jp{前のオブジェクト} */
	RELTIM                  lefttim;	/**< %jp{残時間} */
	FP						timhdr;		/**< %jp{タイマハンドラ} */
} _KERNEL_T_TIMOBJ;


/** %jp{タイマキュー} */
typedef struct _kernel_t_tmq
{
	_KERNEL_T_TIMOBJ		*head;
	_KERNEL_T_TIMOBJ		*next;
} _KERNEL_T_TMQ;


#ifdef __cplusplus
extern "C" {
#endif

void _kernel_add_tmq(_KERNEL_T_TMQ *pk_tmq, _KERNEL_T_TIMOBJ *pk_timobj);
void _kernel_rmv_tmq(_KERNEL_T_TMQ *pk_tmq, _KERNEL_T_TIMOBJ *pk_timobj);
void _kernel_tic_tmq(_KERNEL_T_TMQ *pk_tmq, RELTIM tictim);

#ifdef __cplusplus
}
#endif


#define _KERNEL_TIMOBJ_CRE_TIMOBJ(pk_timobj)		do { (pk_timobj)->next = NULL; } while (0)
#define _KERNEL_TIMOBJ_DEL_TIMOBJ(pk_timobj)		do { } while (0)
#define _KERNEL_TIMOBJ_SET_LEFTTIM(pk_timobj, x)	do { (pk_timobj)->lefttim = (x); } while (0)
#define _KERNEL_TIMOBJ_GET_LEFTTIM(pk_timobj)		((pk_timobj)->lefttim)
#define _KERNEL_TIMOBJ_SET_TIMHDR(pk_timobj, x)		do { (pk_timobj)->timhdr = (x); } while (0)
#define _KERNEL_TIMOBJ_GET_TIMHDR(pk_timobj)		((pk_timobj)->timhdr)

#define _KERNEL_TMQ_ADD_TMQ(pk_tmq, pk_timobj)		_kernel_add_tmq((pk_tmq), (pk_timobj));
#define _KERNEL_TMQ_RMV_TMQ(pk_tmq, pk_timobj)		_kernel_rmv_tmq((pk_tmq), (pk_timobj));
#define _KERNEL_TMQ_TIC_TMQ(pk_tmq, tictim)			_kernel_tic_tmq((pk_tmq), (tictim));


#define _KERNEL_ADD_TMQ(pk_timobj)					_KERNEL_TMQ_ADD_TMQ(_KERNEL_SYS_GET_TMQ(), (pk_timobj));
#define _KERNEL_RMV_TMQ(pk_timobj)					_KERNEL_TMQ_RMV_TMQ(_KERNEL_SYS_GET_TMQ(), (pk_timobj));
#define _KERNEL_TIC_TMQ(tictim)						_KERNEL_TMQ_TIC_TMQ(_KERNEL_SYS_GET_TMQ(), (tictim));



#endif	/* _KERNEL__core__tmq_h__ */



/* end of file */
