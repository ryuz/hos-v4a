/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dpc.h
 * @brief %jp{遅延プロシージャーコールヘッダファイル}%en{Deferred Procedure Call header file}
 *
 * @version $Id: dpc.h,v 1.1 2006-10-15 13:37:44 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__core__dpc_h__
#define _KERNEL__core__dpc_h__


typedef _kernel_t_dpccb
{
	VP_INT			*msgq;
	UINT			msgqsz;
	volatile UINT	head;
	volatile UINT	tail;
} _KERNEL_T_DPCCB;


#define _KERNEL_DPC_SET_MSGQ(dcpcb, x)		do { (dcpcb)->msgq = (x); } while (0)
#define _KERNEL_DPC_GET_MSGQ(dcpcb)			((dcpcb)->msgq)
#define _KERNEL_DPC_SET_MSGQSZ(dcpcb, x)	do { (dcpcb)->msgqsz = (x); } while (0)
#define _KERNEL_DPC_GET_MSGQSZ(dcpcb)		((dcpcb)->msgqsz)
#define _KERNEL_DPC_SET_HEAD(dcpcb, x)		do { (dcpcb)->msgqsz = (x); } while (0)
#define _KERNEL_DPC_GET_HEAD(dcpcb)			((dcpcb)->msgqsz)
#define _KERNEL_DPC_SET_TAIL(dcpcb, x)		do { (dcpcb)->msgqsz = (x); } while (0)
#define _KERNEL_DPC_GET_HEAD(dcpcb)			((dcpcb)->msgqsz)



#ifdef __cplusplus
extern "C" {
#endif

void _kernel_dpc_snd_msg(_KERNEL_T_DPCCB *dcpcb, VP_INT msg);
BOOL _kernel_dpc_rcv_msg(_KERNEL_T_DPCCB *dcpcb, VP_INT *p_msg);

#ifdef __cplusplus
}
#endif




#endif	/* _KERNEL__core__dpc_h__ */


/* end of file */
