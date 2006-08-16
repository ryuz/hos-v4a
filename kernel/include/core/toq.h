/**
 *  Hyper Operating System V4 Advance
 *
 * @file  toq.h
 * @brief %jp{タイムアウトキューのヘッダファイル}%en{time-out queue heder file}
 *
 * @version $Id: toq.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS_V4a__core__toq_h__
#define __HOS_V4a__core__toq_h__


/** %jp{タイムアウトキューオブジェクト} */
typedef _KERNEL_T_TSKHDL						_KERNEL_T_TOQ;


#define _KERNEL_TOQ_GET_HED_TSK()				(*_KERNEL_SYS_GET_TOQ())
#define _KERNEL_TOQ_SET_HED_TSK(x)				do { (*_KERNEL_SYS_GET_TOQ()) = x; } while (0) 


/** %jp{タイムアウトキュー接続用オブジェクト} */
#define _KERNEL_TOQOBJ															\
	_KERNEL_TCB_T_TSKHDL	 toqobj_next		_KERNEL_TCB_TBITDEF_TSKHDL;		\
	_KERNEL_TCB_T_TSKHDL	 toqobj_prev		_KERNEL_TCB_TBITDEF_TSKHDL;		\
	_KERNEL_TCB_T_RELTIM	 toqobj_diftim		_KERNEL_TCB_TBITDEF_RELTIM;


#define _KERNEL_TSK_SET_TOQNEXT(tcb, x)			do { (tcb)->toqobj_next = (x); } while (0)
#define _KERNEL_TSK_GET_TOQNEXT(tcb)			((tcb)->toqobj_next)
#define _KERNEL_TSK_SET_TOQPREV(tcb, x)			do { (tcb)->toqobj_prev = (x); } while (0)
#define _KERNEL_TSK_GET_TOQPREV(tcb)			((tcb)->toqobj_prev)
#define _KERNEL_TSK_SET_TOQDIFTIM(tcb, x)		do { (tcb)->toqobj_diftim = (x); } while (0)
#define _KERNEL_TSK_GET_TOQDIFTIM(tcbl)			((tcb)->toqobj_diftim)



#ifdef __cplusplus
extern "C" {
#endif

void _kernel_add_toq(_KERNEL_T_TSKHDL tskhdl, RELTIM tmout);
void _kernel_rmv_toq(_KERNEL_T_TSKHDL tskhdl);
void _kernel_sig_toq(RELTIM tictim);

#ifdef __cplusplus
}
#endif

#define _KERNEL_ADD_TOQ		_kernel_add_toq					
#define _KERNEL_RMV_TOQ		_kernel_rmv_toq					
#define _KERNEL_SIG_TOQ		_kernel_sig_toq					



#endif	/* __HOS_V4a__core__toq_h__ */



/* end of file */
