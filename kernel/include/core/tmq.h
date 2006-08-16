/**
 *  Hyper Operating System V4 Advance
 *
 * @file  toq.h
 * @brief %jp{タイムアウトキューのヘッダファイル}%en{time-out queue heder file}
 *
 * @version $Id: tmq.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core__tmq_h__
#define _KERNEL__core__tmq_h__


/** %jp{タイムアウトキューオブジェクト} */
typedef _KERNEL_T_TSKHDL				_KERNEL_T_TOQ;


#define _KERNEL_TOQ_GET_HED_TSK()		(*_KERNEL_SYS_GET_TOQ())
#define _KERNEL_TOQ_SET_HED_TSK(x)		do { (*_KERNEL_SYS_GET_TOQ()) = x; } while (0) 


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



#endif	/* _KERNEL__core__tmq_h__ */



/* end of file */
