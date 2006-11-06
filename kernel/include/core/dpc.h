/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dpc.h
 * @brief %jp{遅延プロシージャーコールヘッダファイル}%en{Deferred Procedure Call header file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__core__dpc_h__
#define _KERNEL__core__dpc_h__


typedef struct _kernel_t_dpccb
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

BOOL _kernel_dpc_snd_msg(_KERNEL_T_DPCCB *dcpcb, VP_INT msg);
BOOL _kernel_dpc_rcv_msg(_KERNEL_T_DPCCB *dcpcb, VP_INT *p_msg);
UINT _kernel_dpc_ref_fre(_KERNEL_T_DPCCB *dcpcb);
void _kernel_dpc_lev_svc(void);

#ifdef __cplusplus
}
#endif

#define _KERNEL_DPC_SND_MSG(dcpcb, msg)			_kernel_dpc_snd_msg((dcpcb), (msg))
#define _KERNEL_DPC_RCV_MSG(dcpcb, p_msg)		_kernel_dpc_rcv_msg((dcpcb), (p_msg))
#define _KERNEL_DPC_REF_FRE(dcpcb)				_kernel_dpc_ref_fre((dcpcb))


#endif	/* _KERNEL__core__dpc_h__ */


/* end of file */
