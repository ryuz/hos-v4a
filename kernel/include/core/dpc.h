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


#ifdef __cplusplus
extern "C" {
#endif

void   _kernel_dpc_snd_msg(_KERNEL_T_DPCCB *dcpcb, VP_INT msg);
VP_INT _kernel_dpc_rcv_msg(_KERNEL_T_DPCCB *dcpcb);
UINT   _kernel_dpc_ref_dat(_KERNEL_T_DPCCB *dcpcb);
UINT   _kernel_dpc_ref_fre(_KERNEL_T_DPCCB *dcpcb);
void   _kernel_dpc_lev_svc(void);

#ifdef __cplusplus
}
#endif

#define _KERNEL_DPC_SND_MSG(dcpcb, msg)			_kernel_dpc_snd_msg((dcpcb), (msg))
#define _KERNEL_DPC_RCV_MSG(dcpcb)				_kernel_dpc_rcv_msg((dcpcb))
#define _KERNEL_DPC_REF_DAT(dcpcb)				_kernel_dpc_ref_dat((dcpcb))			/* データ数参照 */
#define _KERNEL_DPC_REF_FRE(dcpcb)				_kernel_dpc_ref_fre((dcpcb))			/* 空き領域参照 */


#endif	/* _KERNEL__core__dpc_h__ */


/* end of file */
