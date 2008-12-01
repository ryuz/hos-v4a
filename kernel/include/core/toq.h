/**
 *  Hyper Operating System V4 Advance
 *
 * @file  toq.h
 * @brief %jp{タイムアウトキューのヘッダファイル}%en{time-out queue heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS_V4a__core__toq_h__
#define __HOS_V4a__core__toq_h__


/** %jp{タイムアウトキュー} */
typedef struct _kernel_t_toqcb
{
	_KERNEL_T_TSKHDL	head;
} _KERNEL_T_TOQCB;


#define _KERNEL_TOQ_SET_HEAD(toqcb, x)		do { ((toqcb)->head) = (x); } while (0) 
#define _KERNEL_TOQ_GET_HEAD(toqcb)			((toqcb)->head)



/** %jp{タイムアウトキュー接続用オブジェクト} */
#define _KERNEL_TOQOBJ															\
	_KERNEL_TCB_T_TSKHDL	 toqobj_next		_KERNEL_TCB_TBITDEF_TSKHDL;		\
	_KERNEL_TCB_T_TSKHDL	 toqobj_prev		_KERNEL_TCB_TBITDEF_TSKHDL;		\
	_KERNEL_TCB_T_RELTIM	 toqobj_diftim		_KERNEL_TCB_TBITDEF_RELTIM;


#define _KERNEL_CRE_TOQOBJ(tcb)					do { (tcb)->toqobj_prev = _KERNEL_TSKHDL_NULL; } while (0)
#define _KERNEL_DEL_TOQOBJ(tcb)					do { } while (0)


#define _KERNEL_TSK_SET_TOQNEXT(tcb, x)			do { (tcb)->toqobj_next = (x); } while (0)
#define _KERNEL_TSK_GET_TOQNEXT(tcb)			((tcb)->toqobj_next)
#define _KERNEL_TSK_SET_TOQPREV(tcb, x)			do { (tcb)->toqobj_prev = (x); } while (0)
#define _KERNEL_TSK_GET_TOQPREV(tcb)			((tcb)->toqobj_prev)
#define _KERNEL_TSK_SET_TOQDIFTIM(tcb, x)		do { (tcb)->toqobj_diftim = (x); } while (0)
#define _KERNEL_TSK_GET_TOQDIFTIM(tcb)			((tcb)->toqobj_diftim)



#ifdef __cplusplus
extern "C" {
#endif

void _kernel_add_toq(_KERNEL_T_TOQCB *toqcb, _KERNEL_T_TSKHDL tskhdl, RELTIM tmout);
void _kernel_rmv_toq(_KERNEL_T_TOQCB *toqcb, _KERNEL_T_TSKHDL tskhdl);
void _kernel_sig_toq(_KERNEL_T_TOQCB *toqcb, RELTIM tictim);

#ifdef __cplusplus
}
#endif

#define _KERNEL_ADD_TOQ(toqcb, tskhdl, tmout)	_kernel_add_toq(toqcb, tskhdl, tmout)				
#define _KERNEL_RMV_TOQ(toqcb, tskhd)			_kernel_rmv_toq(toqcb, tskhd)				
#define _KERNEL_SIG_TOQ(toqcb, tictim)			_kernel_sig_toq(toqcb, tictim)					



#endif	/* __HOS_V4a__core__toq_h__ */



/* end of file */
