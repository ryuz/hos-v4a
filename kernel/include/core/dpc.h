/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dpc.h
 * @brief %jp{遅延プロシージャーコールヘッダファイル}%en{Deferred Procedure Call header file}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__core__dpc_h__
#define _KERNEL__core__dpc_h__



typedef struct _kernel_t_dpcmsg
{
	void				(*svc)(ID id, VP_INT param);
	ID					id;
	VP_INT				param;
} _KERNEL_T_DPCMSG;


typedef struct _kernel_t_dpccb
{
	volatile _KERNEL_T_DPCMSG	*que;
	UB							quecnt;
	volatile UB					head;
	volatile UB					tail;
} _KERNEL_T_DPCCB;


#ifdef __cplusplus
extern "C" {
#endif

void _kernel_ini_dpc(_KERNEL_T_DPCCB *dcpcb, _KERNEL_T_DPCMSG *que, INT quecnt);
ER   _kernel_req_dpc(_KERNEL_T_DPCCB *dcpcb, void (*svc)(ID id, VP_INT param), ID id, VP_INT param);
void _kernel_exe_dpc(_KERNEL_T_DPCCB *dcpcb);

#ifdef __cplusplus
}
#endif

#define _KERNEL_INI_DPC(dcpcb, que, quecnt)			_kernel_ini_dpc(dcpcb, que, quecnt)			/**< %jp{DPCキューの初期化} */
#define _KERNEL_REQ_DPC(dcpcb, svc, id, param)		_kernel_req_dpc(dcpcb, svc, id, param)		/**< %jp{DPCキューへ実行リクエスト} */
#define _KERNEL_EXE_DPC(dcpcb)						_kernel_exe_dpc(dcpcb)						/**< %jp{DPCキューの実行} */


#endif	/* _KERNEL__core__dpc_h__ */


/* end of file */
