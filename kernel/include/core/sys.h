/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  knl_sys.h
 * @brief %en{system heder file}%jp{システム制御のヘッダファイル}
 *
 * @version $Id: sys.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS_V4a__knl_sys_h__
#define __HOS_V4a__knl_sys_h__


#include "core/hep.h"


/* %jp{システムの状態} */
#define _KERNEL_TSS_TSK			0x00		/**< %jp{タスク部実行中} */
#define _KERNEL_TSS_DINT		0x01		/**< %jp{割り込み禁止(loc_cpu 有効)} */
#define _KERNEL_TSS_DDSP		0x02		/**< %jp{ディスパッチ禁止 (dis_dsp 有効)} */
#define _KERNEL_TSS_INDP		0x04		/**< %jp{タスク独立部実行中} */
#define _KERNEL_TSS_DDLY		0x08		/**< %jp{ディスパッチ遅延中} */


/** %jp{プロセッサ制御情報}%en{Processor control block} */
typedef struct _kernel_t_proccb
{
	STAT				stat;				/**< %jp{システムのコンテキスト状態}%en{system state} */
	_KERNEL_T_TSKHDL	tskhdl_run;			/**< %jp{実行中タスク} */
	_KERNEL_T_CTXCB		sysctxcb;			/**< %jp{システムコンテキスト(アイドル実行等)のコンテキスト} */
	SIZE				sysstksz;			/**< %jp{システムコンテキストのスタックサイズ} */
	VP					sysstk;				/**< %jp{システムコンテキストのスタック} */
	SIZE				intstksz;			/**< %jp{割り込みコンテキストのスタックサイズ} */
	VP					intstk;				/**< %jp{割り込みコンテキストのスタック} */
} _KERNEL_T_PROCCB;


/** %jp{システム制御情報}%en{system control block} */
typedef struct _kernel_t_syscb
{
	_KERNEL_T_RDQ		rdq;				/**< %jp{レディーキュー}%en{ready-queue} */
	_KERNEL_T_TOQ		toq;				/**< %jp{タイムアウトキュー}%en{timeout-queue} */
	_KERNEL_T_HEPCB		memhep;				/**< %jp{カーネルメモリヒープ}%en{kernel heap-memory control block} */
	_KERNEL_T_PROCCB	proccb[1];			/**< %jp{プロセッサ制御情報}%en{processor control block} */
} _KERNEL_T_SYSCB;


/** %jp{システム制御情報}%en{system control block} */
extern _KERNEL_T_SYSCB _kernel_syscb;



#define _KERNEL_SYS_INI_SYS()				do {} while (0)

#define _KERNEL_SYS_GET_RDQ()				(&_kernel_syscb.rdq)
#define _KERNEL_SYS_GET_TOQ()				(&_kernel_syscb.toq)

#define _KERNEL_SYS_INI_MEM(p_base, size)	_kernel_cre_hep(&_kernel_syscb.memhep, (p_base), (size))
#define _KERNEL_SYS_ALC_MEM(size)			_kernel_alc_hep(&_kernel_syscb.memhep, (size))
#define _KERNEL_SYS_FRE_MEM(ptr)			_kernel_fre_hep(&_kernel_syscb.memhep, (ptr))
#define _KERNEL_SYS_ALG_MEM(size)			_kernel_alg_hep(size)

#define _KERNEL_SYS_GET_STST()				(_kernel_syscb.proccb[0].stat)
#define _KERNEL_SYS_SET_STST(x)				do { _kernel_syscb.proccb[0].stat = (x); } while (0)
#define _KERNEL_SYS_GET_RUNTSK()			(_kernel_syscb.proccb[0].tskhdl_run)
#define _KERNEL_SYS_SET_RUNTSK(x)			do { _kernel_syscb.proccb[0].tskhdl_run = (x); } while (0)
#define _KERNEL_SYS_GET_SYSCTXCB()			(&_kernel_syscb.proccb[0].sysctxcb)
#define _KERNEL_SYS_GET_SYSSTKSZ()			(_kernel_syscb.proccb[0].sysstksz)
#define _KERNEL_SYS_GET_SYSSTK()			(_kernel_syscb.proccb[0].sysstk)
#define _KERNEL_SYS_GET_SYSISP()			((VP)((UB *)_KERNEL_SYS_GET_SYSSTK() + _KERNEL_SYS_GET_SYSSTKSZ()))


#define _KERNEL_SYS_SET_CTX()				do { _kernel_syscb.proccb[0].stat |= _KERNEL_TSS_INDP; } while (0)
#define _KERNEL_SYS_CLR_CTX()				do { _kernel_syscb.proccb[0].stat &= ~_KERNEL_TSS_INDP; } while (0)
#define _KERNEL_SYS_SNS_CTX()				((_kernel_syscb.proccb[0].stat & _KERNEL_TSS_INDP) ? TRUE : FALSE)

#define _KERNEL_SYS_SET_LOC()				do { _kernel_syscb.proccb[0].stat |= _KERNEL_TSS_DINT; } while (0)
#define _KERNEL_SYS_CLR_LOC()				do { _kernel_syscb.proccb[0].stat &= ~_KERNEL_TSS_DINT; } while (0)
#define _KERNEL_SYS_SNS_LOC()				((_KERNEL_SYS_GET_STST() & _KERNEL_TSS_DINT) ? TRUE : FALSE)

#define _KERNEL_SYS_SET_DSP()				do { _kernel_syscb.proccb[0].stat |= _KERNEL_TSS_DDSP; } while (0)
#define _KERNEL_SYS_CLR_DSP()				do { _kernel_syscb.proccb[0].stat &= ~_KERNEL_TSS_DDSP; } while (0)
#define _KERNEL_SYS_SNS_DSP()				((_kernel_syscb.proccb[0].stat & _KERNEL_TSS_DDSP) ? TRUE : FALSE)

#define _KERNEL_SYS_SET_DLY()				do { _kernel_syscb.proccb[0].stat |= _KERNEL_TSS_DDLY; } while (0)
#define _KERNEL_SYS_CLR_DLY()				do { _kernel_syscb.proccb[0].stat &= ~_KERNEL_TSS_DDLY; } while (0)
#define _KERNEL_SYS_SNS_DLY()				((_kernel_syscb.proccb[0].stat & _KERNEL_TSS_DDLY) ? TRUE : FALSE)

#define _KERNEL_SYS_SNS_DPN()				((_kernel_syscb.proccb[0].stat != _KERNEL_TSS_TSK) ? TRUE : FALSE)


#define _KERNEL_ENTER_SVC()					do { _kernel_dis_int(); } while (0)
#define _KERNEL_LEAVE_SVC()					do { if (!(_KERNEL_SYS_GET_STST() & _KERNEL_TSS_DINT)){ _kernel_ena_int(); } } while (0)


#ifdef __cplusplus
extern "C" {
#endif

void _kernel_cfg_ini(void);
void _kernel_cfg_sta(void);
void _kernel_idl_lop(void);				/**< %jp{アイドルループ}%en{idle loop} */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS_V4__knl_sys_h__ */




/* end of file */
