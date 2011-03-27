/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sys.h
 * @brief %en{system heder file}%jp{システム制御のヘッダファイル}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core_sys_h__
#define _KERNEL__core_sys_h__


#include "core/hep.h"
#include "core/tim.h"
#include "core/toq.h"
#include "core/tmq.h"
#include "core/dpc.h"


/* %jp{システムの状態} */
#define _KERNEL_TSS_TSK			0x00		/**< %jp{タスク部実行中} */
#define _KERNEL_TSS_LOC			0x01		/**< %jp{割込み禁止(loc_cpu 有効)} */
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
	SIZE				intstksz;			/**< %jp{割込みコンテキストのスタックサイズ} */
	VP					intstk;				/**< %jp{割込みコンテキストのスタック} */
} _KERNEL_T_PROCCB;


/** %jp{システム制御情報}%en{system control block} */
typedef struct _kernel_t_syscb
{
	_KERNEL_T_RDQCB		rdqcb;				/**< %jp{レディーキュー}%en{ready-queue} */

	_KERNEL_T_TIMCB		timcb;

#if _KERNEL_SPT_TOQ
	_KERNEL_T_TOQCB		toqcb;				/**< %jp{タイムアウトキュー}%en{timeout-queue} */
#endif

#if _KERNEL_SPT_TMQ
	_KERNEL_T_TMQCB		tmqcb;				/**< %jp{タイマキュー}%en{timer-queue} */
#endif

#if _KERNEL_SPT_HEP
	_KERNEL_T_HEPCB		hepcb;				/**< %jp{カーネルメモリヒープ}%en{kernel heap-memory control block} */
#endif

#if _KERNEL_SPT_DPC
	_KERNEL_T_DPCCB		dpccb;				/**< %jp{遅延プロシージャコール用メッセージキュー} */
#endif

	_KERNEL_T_PROCCB	proccb[1];			/**< %jp{プロセッサ制御情報}%en{processor control block} */
} _KERNEL_T_SYSCB;


/** %jp{システム制御情報(リードオンリー)}%en{system control block(read only)} */
typedef struct _kernel_t_syscb_ro
{
	_KERNEL_T_TIMCB_RO timcb_ro;
} _KERNEL_T_SYSCB_RO;


/** %jp{システム制御情報}%en{system control block} */
extern       _KERNEL_T_SYSCB		_kernel_syscb;
extern const _KERNEL_T_SYSCB_RO		_kernel_syscb_ro;

/* system */
#define _KERNEL_SYS_INI_SYS()				do {} while (0)														/**< %jp{システムの初期化} */
#define _KERNEL_SYS_GET_PRC()				(0)																	/**< %jp{プロセッサ番号取得} */
#define _KERNEL_SYS_GET_PRCCB()				(&_kernel_syscb.proccb[_KERNEL_SYS_GET_PRC()])						/**< %jp{プロセッサ制御ブロックの取得} */

/* ready queue */
#define _KERNEL_SYS_GET_RDQ()				(&_kernel_syscb.rdqcb)												/**< %jp{レディーキューの取得} */
#define _KERNEL_SYS_CRE_RDQ()				_KERNEL_CRE_RDQ(_KERNEL_SYS_GET_RDQ())								/**< %en{create ready-queue}%jp{レディーキューの生成} */
#define _KERNEL_SYS_DEL_RDQ()				_KERNEL_DEL_RDQ(_KERNEL_SYS_GET_RDQ())								/**< %en{delete ready-queue}%jp{レディーキューの削除} */
#define _KERNEL_SYS_ADD_RDQ(tskhdl)			_KERNEL_ADD_RDQ(_KERNEL_SYS_GET_RDQ(), (tskhdl))					/**< %jp{タスクをレディーキューに追加} */
#define _KERNEL_SYS_RMV_RDQ(tskhdl)			_KERNEL_RMV_RDQ(_KERNEL_SYS_GET_RDQ(), (tskhdl))					/**< %jp{タスクをレディーから取り外し} */
#define _KERNEL_SYS_RMH_RDQ()				_KERNEL_RMH_RDQ(_KERNEL_SYS_GET_RDQ())								/**< %jp{キューの先頭タスクの取り外し} */
#define _KERNEL_SYS_REF_RDQ()				_KERNEL_REF_RDQ(_KERNEL_SYS_GET_RDQ())								/**< %jp{キューの先頭タスクの参照} */
#define _KERNEL_SYS_ROT_RDQ(tskpri)			_KERNEL_ROT_RDQ(_KERNEL_SYS_GET_RDQ(), (tskpri))					/**< %jp{レディーキューの回転} */

/* time */
#define _KERNEL_SYS_GET_TIMCB()				(&_kernel_syscb.timcb)
#define _KERNEL_SYS_GET_TIMCB_RO()			(&_kernel_syscb_ro.timcb_ro)
#define	_KERNEL_SYS_INI_TIM()				_KERNEL_INI_TIM(_KERNEL_SYS_GET_TIMCB(), _KERNEL_SYS_GET_TIMCB_RO())
#define	_KERNEL_SYS_SIG_TIM()				_KERNEL_SIG_TIM(_KERNEL_SYS_GET_TIMCB(), _KERNEL_SYS_GET_TIMCB_RO())
#define	_KERNEL_SYS_GET_TIC()				_KERNEL_GET_TIC(_KERNEL_SYS_GET_TIMCB(), _KERNEL_SYS_GET_TIMCB_RO())
#define	_KERNEL_SYS_SET_TIM(p_tim)			_KERNEL_SET_TIM(_KERNEL_SYS_GET_TIMCB(), (p_tim))
#define	_KERNEL_SYS_GET_TIM()				_KERNEL_GET_TIM(_KERNEL_SYS_GET_TIMCB())

/* timeout queue */
#define _KERNEL_SYS_GET_TOQCB()				(&_kernel_syscb.toqcb)												/**< %jp{タイムアウトキューの取得} */
#define _KERNEL_SYS_ADD_TOQ(tskhdl, tmout)	_KERNEL_ADD_TOQ(_KERNEL_SYS_GET_TOQCB(), (tskhdl), (tmout))
#define _KERNEL_SYS_RMV_TOQ(tskhd)			_KERNEL_RMV_TOQ(_KERNEL_SYS_GET_TOQCB(), (tskhd))
#define _KERNEL_SYS_SIG_TOQ(tictim)			_KERNEL_SIG_TOQ(_KERNEL_SYS_GET_TOQCB(), (tictim))

/* timer queue */
#define _KERNEL_SYS_GET_TMQ()				(&_kernel_syscb.tmqcb)												/**< %jp{タイマキューの取得} */
#define _KERNEL_SYS_ADD_TMQ(pk_timobj)		_KERNEL_ADD_TMQ(_KERNEL_SYS_GET_TMQ(), (pk_timobj))
#define _KERNEL_SYS_RMV_TMQ(pk_timobj)		_KERNEL_RMV_TMQ(_KERNEL_SYS_GET_TMQ(), (pk_timobj))
#define _KERNEL_SYS_BSY_TMQ(pk_timobj)		_KERNEL_BSY_TMQ(_KERNEL_SYS_GET_TMQ(), (pk_timobj))
#define _KERNEL_SYS_SIG_TMQ(tictim)			_KERNEL_SIG_TMQ(_KERNEL_SYS_GET_TMQ(), (tictim))

/* kernel memory heap */
#define _KERNEL_SYS_GET_HEP()				(&_kernel_syscb.hepcb)												/**< %jp{タイマキューの取得} */
#define _KERNEL_SYS_INI_HEP(hepsz, hep)		_KERNEL_CRE_HEP(_KERNEL_SYS_GET_HEP(), (hepsz), (hep))				/**< %jp{カーネルメモリヒープの初期化} */
#define _KERNEL_SYS_ALC_HEP(size)			_KERNEL_ALC_HEP(_KERNEL_SYS_GET_HEP(), (size))						/**< %jp{カーネルメモリの割当て} */
#define _KERNEL_SYS_FRE_HEP(ptr)			_KERNEL_FRE_HEP(_KERNEL_SYS_GET_HEP(), (ptr))						/**< %jp{カーネルメモリの開放} */
#define _KERNEL_SYS_ALG_HEP(size)			_KERNEL_ALG_HEP(_KERNEL_SYS_GET_HEP(), (size))						/**< %jp{カーネルメモリのサイズアライメント} */

/* kernel dpc queue */
#if _KERNEL_SPT_DPC
#define _KERNEL_SYS_GET_DPC()				(&_kernel_syscb.dpccb)												/**< %jp{DPCキューの取得} */
#define _KERNEL_SYS_INI_DPC(que, quecnt)	_KERNEL_INI_DPC(_KERNEL_SYS_GET_DPC(), (que), (quecnt))				/**< %jp{DPCキューの初期化} */
#define _KERNEL_SYS_REQ_DPC(svc, id, param)	_KERNEL_REQ_DPC(_KERNEL_SYS_GET_DPC(), (svc), (id), (param))		/**< %jp{DPCキューへ実行リクエスト} */
#define _KERNEL_SYS_EXE_DPC()				_KERNEL_EXE_DPC(_KERNEL_SYS_GET_DPC())								/**< %jp{DPCキューの実行} */
#else
#define _KERNEL_SYS_GET_DPC()				NULL																/**< %jp{DPCキューの取得} */
#define _KERNEL_SYS_INI_DPC(que, quecnt)	do {} while (0)														/**< %jp{DPCキューの初期化} */
#define _KERNEL_SYS_REQ_DPC(svc, id, param)	E_NOMEM																/**< %jp{DPCキューへ実行リクエスト} */
#define _KERNEL_SYS_EXE_DPC()				do {} while (0)														/**< %jp{DPCキューの実行} */
#endif



#define _KERNEL_SYS_INI_SYSSTK(stksz, stk)	do { _KERNEL_SYS_GET_PRCCB()->sysstksz = (stksz); _KERNEL_SYS_GET_PRCCB()->sysstk = (stk); } while(0)
																												/**< %jp{システムスタックの初期化} */
#define _KERNEL_SYS_INI_INTSTK(stksz, stk)	_KERNEL_INI_INT((stksz), (stk))										/**< %jp{割込みスタックの初期化} */

#define _KERNEL_SYS_GET_STST()				(_KERNEL_SYS_GET_PRCCB()->stat)										/**< %jp{カレントプロセッサ状態の取得} */
#define _KERNEL_SYS_SET_STST(x)				do { _KERNEL_SYS_GET_PRCCB()->stat = (x); } while (0)				/**< %jp{カレントプロセッサ状態の設定} */
#define _KERNEL_SYS_GET_RUNTSK()			(_KERNEL_SYS_GET_PRCCB()->tskhdl_run)								/**< %jp{カレントプロセッサの実行中タスク取得} */
#define _KERNEL_SYS_SET_RUNTSK(x)			do { _KERNEL_SYS_GET_PRCCB()->tskhdl_run = (x); } while (0)			/**< %jp{カレントプロセッサの実行中タスク設定} */
#define _KERNEL_SYS_GET_SYSCTXCB()			(&_KERNEL_SYS_GET_PRCCB()->sysctxcb)								/**< %jp{カレントプロセッサのシステムコンテキスト取得} */
#define _KERNEL_SYS_GET_SYSSTKSZ()			(_KERNEL_SYS_GET_PRCCB()->sysstksz)									/**< %jp{カレントプロセッサのシステムコンテキストの初期スタックサイズ取得} */
#define _KERNEL_SYS_GET_SYSSTK()			(_KERNEL_SYS_GET_PRCCB()->sysstk)									/**< %jp{カレントプロセッサのシステムコンテキストの初期スタックアドレス取得} */
#define _KERNEL_SYS_GET_SYSISP()			((VP)((UB *)_KERNEL_SYS_GET_SYSSTK() + _KERNEL_SYS_GET_SYSSTKSZ()))	/**< %jp{カレントプロセッサのシステムコンテキストの初期スタックポインタ取得} */


#if _KERNEL_PROCATR_SYS_CTX
#define _KERNEL_SYS_SET_CTX()				_KERNEL_PROC_SET_CTX()												/**< %jp{非タスクコンテキストに設定} */
#define _KERNEL_SYS_CLR_CTX()				_KERNEL_PROC_CLR_CTX()												/**< %jp{非タスクコンテキストを解除} */
#define _KERNEL_SYS_SNS_CTX()				_KERNEL_PROC_SNS_CTX()												/**< %jp{コンテキスト状態を参照} */
#else
#define _KERNEL_SYS_SET_CTX()				do { _KERNEL_SYS_GET_PRCCB()->stat |= _KERNEL_TSS_CTX; } while (0)	/**< %jp{非タスクコンテキストに設定} */
#define _KERNEL_SYS_CLR_CTX()				do { _KERNEL_SYS_GET_PRCCB()->stat &= ~_KERNEL_TSS_CTX; } while (0)	/**< %jp{非タスクコンテキストを解除} */
#define _KERNEL_SYS_SNS_CTX()				((_KERNEL_SYS_GET_PRCCB()->stat & _KERNEL_TSS_CTX) ? TRUE : FALSE)	/**< %jp{コンテキスト状態を参照} */
#endif

#if _KERNEL_PROCATR_SYS_LOC
#define _KERNEL_SYS_SET_LOC()				_KERNEL_PROC_SET_CTX()												/**< %jp{ロック状態を設定} */
#define _KERNEL_SYS_CLR_LOC()				_KERNEL_PROC_CLR_CTX()												/**< %jp{ロック状態を解除} */
#define _KERNEL_SYS_SNS_LOC()				_KERNEL_PROC_SNS_CTX()												/**< %jp{ロック状態を参照} */
#else
#define _KERNEL_SYS_SET_LOC()				do { _KERNEL_SYS_GET_PRCCB()->stat |= _KERNEL_TSS_LOC; } while (0)	/**< %jp{ロック状態を設定} */
#define _KERNEL_SYS_CLR_LOC()				do { _KERNEL_SYS_GET_PRCCB()->stat &= ~_KERNEL_TSS_LOC; } while (0)	/**< %jp{ロック状態を解除} */
#define _KERNEL_SYS_SNS_LOC()				((_KERNEL_SYS_GET_STST() & _KERNEL_TSS_LOC) ? TRUE : FALSE)			/**< %jp{ロック状態を参照} */
#endif

#if _KERNEL_PROCATR_SYS_DSP
#define _KERNEL_SYS_SET_DSP()				_KERNEL_PROC_SET_DSP()												/**< %jp{ディスパッチ禁止状態を設定} */
#define _KERNEL_SYS_CLR_DSP()				_KERNEL_PROC_CLR_DSP()												/**< %jp{ディスパッチ禁止状態を解除} */
#define _KERNEL_SYS_SNS_DSP()				_KERNEL_PROC_SNS_DSP()												/**< %jp{ディスパッチ禁止状態を参照} */
#else
#define _KERNEL_SYS_SET_DSP()				do { _KERNEL_SYS_GET_PRCCB()->stat |= _KERNEL_TSS_DSP; } while (0)	/**< %jp{ディスパッチ禁止状態を設定} */
#define _KERNEL_SYS_CLR_DSP()				do { _KERNEL_SYS_GET_PRCCB()->stat &= ~_KERNEL_TSS_DSP; } while (0)	/**< %jp{ディスパッチ禁止状態を解除} */
#define _KERNEL_SYS_SNS_DSP()				((_KERNEL_SYS_GET_PRCCB()->stat & _KERNEL_TSS_DSP) ? TRUE : FALSE)	/**< %jp{ディスパッチ禁止状態を参照} */
#endif

#if _KERNEL_PROCATR_SYS_SYS
#define _KERNEL_SYS_SET_SYS()				_KERNEL_PROC_SET_SYS()												/**< %jp{ディスパッチ禁止状態を設定} */
#define _KERNEL_SYS_CLR_SYS()				_KERNEL_PROC_CLR_SYS()												/**< %jp{ディスパッチ禁止状態を解除} */
#define _KERNEL_SYS_SNS_SYS()				_KERNEL_PROC_SNS_SYS()												/**< %jp{ディスパッチ禁止状態を参照} */
#else
#define _KERNEL_SYS_SET_SYS()				do { _KERNEL_SYS_GET_PRCCB()->stat |= _KERNEL_TSS_SYS; } while (0)	/**< %jp{システム状態を設定} */
#define _KERNEL_SYS_CLR_SYS()				do { _KERNEL_SYS_GET_PRCCB()->stat &= ~_KERNEL_TSS_SYS; } while (0)	/**< %jp{システム状態を解除} */
#define _KERNEL_SYS_SNS_SYS()				((_KERNEL_SYS_GET_PRCCB()->stat & _KERNEL_TSS_SYS) ? TRUE : FALSE)	/**< %jp{システム状態を参照} */
#endif

#if _KERNEL_PROCATR_SYS_DLY
#define _KERNEL_SYS_SET_DLY()				_KERNEL_PROC_SET_DLY()												/**< %jp{ディスパッチ禁止状態を設定} */
#define _KERNEL_SYS_CLR_DLY()				_KERNEL_PROC_CLR_DLY()												/**< %jp{ディスパッチ禁止状態を解除} */
#define _KERNEL_SYS_SNS_DLY()				_KERNEL_PROC_SNS_DLY()												/**< %jp{ディスパッチ禁止状態を参照} */
#else
#define _KERNEL_SYS_SET_DLY()				do { _KERNEL_SYS_GET_PRCCB()->dlydsp = TRUE;} while (0)				/**< %jp{ディスパッチ遅延中を設定} */
#define _KERNEL_SYS_CLR_DLY()				do { _KERNEL_SYS_GET_PRCCB()->dlydsp = FALSE;} while (0)			/**< %jp{ディスパッチ遅延中を解除} */
#define _KERNEL_SYS_SNS_DLY()				(_KERNEL_SYS_GET_PRCCB()->dlydsp)									/**< %jp{ディスパッチ遅延中を参照} */
#endif

#if !_KERNEL_PROCATR_SYS_CTX && !_KERNEL_PROCATR_SYS_LOC && !_KERNEL_PROCATR_SYS_DSP &&  !_KERNEL_PROCATR_SYS_SYS &&  !_KERNEL_PROCATR_SYS_DLY
#define _KERNEL_SYS_SNS_DPN()				((_KERNEL_SYS_GET_PRCCB()->stat != _KERNEL_TSS_TSK) ? TRUE : FALSE)	/**< %jp{ディスパッチ不能を参照} */
#else
#define _KERNEL_SYS_SNS_DPN()				(_KERNEL_SYS_SNS_CTX() || _KERNEL_SYS_SNS_LOC() || _KERNEL_SYS_SNS_DSP() || _KERNEL_SYS_SNS_SYS())
#endif


#if _KERNEL_SPT_DPC		/* %jp{遅延プロシージャコールの場合} */

#define _KERNEL_SYS_SET_SVC()				do { _KERNEL_SYS_GET_PRCCB()->svcent = TRUE; } while (0)
#define _KERNEL_SYS_CLR_SVC()				do { _KERNEL_SYS_GET_PRCCB()->svcent = FALSE; } while (0)
#define _KERNEL_SYS_SNS_SVC()				(_KERNEL_SYS_GET_PRCCB()->svcent)

#define _KERNEL_ENTER_SVC()					do { _KERNEL_SYS_SET_SVC(); } while (0)
#define _KERNEL_LEAVE_SVC()					do { _KERNEL_SYS_EXE_DPC(); } while (0)

#define _KERNEL_SYS_LOC_DPC()				do { _KERNEL_DIS_INT(); } while (0)
#define _KERNEL_SYS_UNL_DPC()				do { if (!(_KERNEL_SYS_GET_STST() & _KERNEL_TSS_LOC)){ _KERNEL_ENA_INT(); } } while (0)
#define _KERNEL_SYS_SND_DPC(msg)			_KERNEL_DPC_SND_MSG(&_kernel_syscb.dpccb, (msg))
#define _KERNEL_SYS_RCV_DPC()				_KERNEL_DPC_RCV_MSG(&_kernel_syscb.dpccb)
#define _KERNEL_SYS_RDT_DPC()				_KERNEL_DPC_REF_DAT(&_kernel_syscb.dpccb)
#define _KERNEL_SYS_RFR_DPC()				_KERNEL_DPC_REF_FRE(&_kernel_syscb.dpccb)

#else					/* %jp{バズロック型の場合} */

#define _KERNEL_ENTER_SVC()					do { _KERNEL_DIS_INT(); } while (0)
#if _KERNEL_PROCATR_SPT_MULTINT
#define _KERNEL_LEAVE_SVC()					do { if (!(_KERNEL_SYS_GET_STST() & (_KERNEL_TSS_LOC | _KERNEL_TSS_SYS))){ _KERNEL_ENA_INT(); } } while (0)
#else
#define _KERNEL_LEAVE_SVC()					do { if (!(_KERNEL_SYS_GET_STST() & (_KERNEL_TSS_LOC | _KERNEL_TSS_SYS | _KERNEL_TSS_CTX))){ _KERNEL_ENA_INT(); } } while (0)
#endif

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


#endif	/* _KERNEL__core_sys_h__ */




/* end of file */
