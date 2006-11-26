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


#include "core/adtq.h"


typedef struct _kernel_t_dpccb
{
	_KERNEL_T_ADTQCB	adtq;					/**< 遅延プロシージャコール用非同期メッセージキュー */
} _KERNEL_T_DPCCB;


#ifdef __cplusplus
extern "C" {
#endif

void   _kernel_exe_dpc(void);

#ifdef __cplusplus
}
#endif

#define _KERNEL_DPC_INI_DPC(dcpcb, que, quecnt)		_KERNEL_ADTQ_INI_QUE(&(dcpcb)->adtq, que, quecnt)
#define _KERNEL_DPC_EXE_DPC()						_kernel_exe_dpc()
#define _KERNEL_DPC_SND_MSG(dcpcb, msg)				_KERNEL_ADTQ_FSND_DAT(&(dcpcb)->adtq, (msg))
#define _KERNEL_DPC_RCV_MSG(dcpcb)					_KERNEL_ADTQ_FRCV_DAT(&(dcpcb)->adtq)
#define _KERNEL_DPC_REF_DAT(dcpcb)					_KERNEL_ADTQ_REF_SDTQNT(&(dcpcb)->adtq)			/* データ数参照 */
#define _KERNEL_DPC_REF_FRE(dcpcb)					_KERNEL_ADTQ_REF_FDTQNT(&(dcpcb)->adtq)			/* 空き領域参照 */


#endif	/* _KERNEL__core__dpc_h__ */


/* end of file */
