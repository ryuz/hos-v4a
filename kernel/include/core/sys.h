/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  knl_sys.h
 * @brief %en{system heder file}%jp{システム制御のヘッダファイル}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef __HOS_V4a__knl_sys_h__
#define __HOS_V4a__knl_sys_h__


#include "core/hep.h"
#include "core/toq.h"
#include "core/tmq.h"
#include "core/dpc.h"


/* %jp{システムの状態} */
#define _KERNEL_TSS_TSK			0x00		/**< %jp{タスク部実行中} */
#define _KERNEL_TSS_LOC			0x01		/**< %jp{割り込み禁止(loc_cpu 有効)} */
#define _KERNEL_TSS_DSP			0x02		/**< %jp{ディスパッチ禁止 (dis_dsp 有効)} */
#define _KERNEL_TSS_CTX			0x04		/**< %jp{タスク独立部実行中} */
#define _KERNEL_TSS_SYS			0x08		/**< %jp{システムモード} */


/** %jp{プロセッサ制御情報}%en{Processor control block} */
typedef struct _kernel_t_proccb
{
	STAT				stat;				/**< %jp{システムのコンテキスト状態}%en{system state} */
	UB                  dlydsp;				/**< %jp{ディスパッチのディレイ管理} */
#if _KERNEL_SPT_DPC
	UB                  svcent;				/**< %jp{サービスコール実行中管理} */
#endif

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
	_KERNEL_T_TMQ		tmq;				/**< %jp{タイマキュー}%en{timer-queue} */
	_KERNEL_T_HEPCB		memhep;				/**< %jp{カーネルメモリヒープ}%en{kernel heap-memory control block} */

#if _KERNEL_SPT_DPC
	_KERNEL_T_DPCCB		dpccb;				/**< %jp{遅延プロシージャコール用メッセージキュー} */
#endif

	_KERNEL_T_PROCCB	proccb[1];			/**< %jp{プロセッサ制御情報}%en{processor control block} */
} _KERNEL_T_SYSCB;


/** %jp{システム制御情報}%en{system control block} */
extern _KERNEL_T_SYSCB _kernel_syscb;


#define _KERNEL_SYS_INI_SYS()				do {} while (0)														/**< %jp{システムの初期化} */
#define _KERNEL_SYS_GET_PRC()				(0)																	/**< %jp{プロセッサ番号取得} */
#define _KERNEL_SYS_GET_PRCCB()				(&_kernel_syscb.proccb[_KERNEL_SYS_GET_PRC()])						/**< %jp{プロセッサ制御ブロックの取得} */

#define _KERNEL_SYS_GET_RDQ()				(&_kernel_syscb.rdq)												/**< %jp{レディーキューの取得} */
#define _KERNEL_SYS_GET_TOQ()				(&_kernel_syscb.toq)												/**< %jp{タイムアウトキューの取得} */
#define _KERNEL_SYS_GET_TMQ()				(&_kernel_syscb.tmq)												/**< %jp{タイマキューの取得} */

#define _KERNEL_SYS_INI_MEM(p_base, size)	_kernel_cre_hep(&_kernel_syscb.memhep, (p_base), (size))			/**< %jp{カーネルメモリヒープの初期化} */
#define _KERNEL_SYS_ALC_MEM(size)			_kernel_alc_hep(&_kernel_syscb.memhep, (size))						/**< %jp{カーネルメモリの割当て} */
#define _KERNEL_SYS_FRE_MEM(ptr)			_kernel_fre_hep(&_kernel_syscb.memhep, (ptr))						/**< %jp{カーネルメモリの開放} */
#define _KERNEL_SYS_ALG_MEM(size)			_kernel_alg_hep(size)												/**< %jp{カーネルメモリのサイズアライメント} */

#define _KERNEL_SYS_INI_SYSSTK(stk, stksz)	do { _kernel_syscb.proccb[0].sysstk = (stk); _kernel_syscb.proccb[0].sysstksz = (stksz); } while(0)
																												/**< %jp{システムスタックの初期化} */

#define _KERNEL_SYS_GET_STST()				(_KERNEL_SYS_GET_PRCCB()->stat)										/**< %jp{カレントプロセッサ状態の取得} */
#define _KERNEL_SYS_SET_STST(x)				do { _KERNEL_SYS_GET_PRCCB()->stat = (x); } while (0)				/**< %jp{カレントプロセッサ状態の設定} */
#define _KERNEL_SYS_GET_RUNTSK()			(_KERNEL_SYS_GET_PRCCB()->tskhdl_run)								/**< %jp{カレントプロセッサの実行中タスク取得} */
#define _KERNEL_SYS_SET_RUNTSK(x)			do { _KERNEL_SYS_GET_PRCCB()->tskhdl_run = (x); } while (0)			/**< %jp{カレントプロセッサの実行中タスク設定} */
#define _KERNEL_SYS_GET_SYSCTXCB()			(&_KERNEL_SYS_GET_PRCCB()->sysctxcb)								/**< %jp{カレントプロセッサのシステムコンテキスト取得} */
#define _KERNEL_SYS_GET_SYSSTKSZ()			(_KERNEL_SYS_GET_PRCCB()->sysstksz)									/**< %jp{カレントプロセッサのシステムコンテキストの初期スタックサイズ取得} */
#define _KERNEL_SYS_GET_SYSSTK()			(_KERNEL_SYS_GET_PRCCB()->sysstk)									/**< %jp{カレントプロセッサのシステムコンテキストの初期スタックアドレス取得} */
#define _KERNEL_SYS_GET_SYSISP()			((VP)((UB *)_KERNEL_SYS_GET_SYSSTK() + _KERNEL_SYS_GET_SYSSTKSZ()))	/**< %jp{カレントプロセッサのシステムコンテキストの初期スタックポインタ取得} */


#define _KERNEL_SYS_SET_CTX()				do { _KERNEL_SYS_GET_PRCCB()->stat |= _KERNEL_TSS_CTX; } while (0)	/**< %jp{非タスクコンテキストに設定} */
#define _KERNEL_SYS_CLR_CTX()				do { _KERNEL_SYS_GET_PRCCB()->stat &= ~_KERNEL_TSS_CTX; } while (0)	/**< %jp{非タスクコンテキストを解除} */
#define _KERNEL_SYS_SNS_CTX()				((_KERNEL_SYS_GET_PRCCB()->stat & _KERNEL_TSS_CTX) ? TRUE : FALSE)	/**< %jp{コンテキスト状態を参照} */

#define _KERNEL_SYS_SET_LOC()				do { _KERNEL_SYS_GET_PRCCB()->stat |= _KERNEL_TSS_LOC; } while (0)	/**< %jp{ロック状態を設定} */
#define _KERNEL_SYS_CLR_LOC()				do { _KERNEL_SYS_GET_PRCCB()->stat &= ~_KERNEL_TSS_LOC; } while (0)	/**< %jp{ロック状態を解除} */
#define _KERNEL_SYS_SNS_LOC()				((_KERNEL_SYS_GET_STST() & _KERNEL_TSS_LOC) ? TRUE : FALSE)			/**< %jp{ロック状態を参照} */

#define _KERNEL_SYS_SET_DSP()				do { _KERNEL_SYS_GET_PRCCB()->stat |= _KERNEL_TSS_DSP; } while (0)	/**< %jp{ディスパッチ禁止状態を設定} */
#define _KERNEL_SYS_CLR_DSP()				do { _KERNEL_SYS_GET_PRCCB()->stat &= ~_KERNEL_TSS_DSP; } while (0)	/**< %jp{ディスパッチ禁止状態を解除} */
#define _KERNEL_SYS_SNS_DSP()				((_KERNEL_SYS_GET_PRCCB()->stat & _KERNEL_TSS_DSP) ? TRUE : FALSE)	/**< %jp{ディスパッチ禁止状態を参照} */

#define _KERNEL_SYS_SET_SYS()				do { _KERNEL_SYS_GET_PRCCB()->stat |= _KERNEL_TSS_SYS; } while (0)	/**< %jp{システム状態を設定} */
#define _KERNEL_SYS_CLR_SYS()				do { _KERNEL_SYS_GET_PRCCB()->stat &= ~_KERNEL_TSS_SYS; } while (0)	/**< %jp{システム状態を解除} */
#define _KERNEL_SYS_SNS_SYS()				((_KERNEL_SYS_GET_PRCCB()->stat & _KERNEL_TSS_SYS) ? TRUE : FALSE)	/**< %jp{システム状態を参照} */

#define _KERNEL_SYS_SET_DLY()				do { _KERNEL_SYS_GET_PRCCB()->dlydsp = TRUE;} while (0)				/**< %jp{ディスパッチ遅延中を設定} */
#define _KERNEL_SYS_CLR_DLY()				do { _KERNEL_SYS_GET_PRCCB()->dlydsp = FALSE;} while (0)			/**< %jp{ディスパッチ遅延中を解除} */
#define _KERNEL_SYS_SNS_DLY()				(_KERNEL_SYS_GET_PRCCB()->dlydsp)									/**< %jp{ディスパッチ遅延中を参照} */

#define _KERNEL_SYS_SNS_DPN()				((_KERNEL_SYS_GET_PRCCB()->stat != _KERNEL_TSS_TSK) ? TRUE : FALSE)	/**< %jp{ディスパッチ不能を参照} */



#if _KERNEL_SPT_DPC		/* %jp{遅延プロシージャコールの場合} */

#define _KERNEL_SYS_SET_SVC()				do { _kernel_syscb.proccb[0].svcent = TRUE; } while (0)
#define _KERNEL_SYS_CLR_SVC()				do { _kernel_syscb.proccb[0].svcent = FALSE; } while (0)
#define _KERNEL_SYS_SNS_SVC()				(_kernel_syscb.proccb[0].svcent)

#define _KERNEL_ENTER_SVC()					do { _KERNEL_SYS_SET_SVC(); } while (0)
#define _KERNEL_LEAVE_SVC()					do { _KERNEL_DPC_EXE_DPC(); _KERNEL_SYS_CLR_SVC(); } while (0)

#define _KERNEL_SYS_INI_DPC(que, quecnt)	_KERNEL_DPC_INI_DPC(&_kernel_syscb.dpccb, (que), (quecnt))								/**< %jp{SPCの初期化} */
#define _KERNEL_SYS_LOC_DPC()				do { _KERNEL_DIS_INT(); } while (0)
#define _KERNEL_SYS_UNL_DPC()				do { if (!(_KERNEL_SYS_GET_STST() & _KERNEL_TSS_LOC)){ _KERNEL_ENA_INT(); } } while (0)
#define _KERNEL_SYS_SND_DPC(msg)			_KERNEL_DPC_SND_MSG(&_kernel_syscb.dpccb, (msg))
#define _KERNEL_SYS_RCV_DPC()				_KERNEL_DPC_RCV_MSG(&_kernel_syscb.dpccb)
#define _KERNEL_SYS_RDT_DPC()				_KERNEL_DPC_REF_DAT(&_kernel_syscb.dpccb)
#define _KERNEL_SYS_RFR_DPC()				_KERNEL_DPC_REF_FRE(&_kernel_syscb.dpccb)

#else					/* %jp{バズロック型の場合} */

#define _KERNEL_ENTER_SVC()					do { _KERNEL_DIS_INT(); } while (0)
#define _KERNEL_LEAVE_SVC()					do { if (!(_KERNEL_SYS_GET_STST() & (_KERNEL_TSS_LOC | _KERNEL_TSS_SYS))){ _KERNEL_ENA_INT(); } } while (0)

#endif


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
