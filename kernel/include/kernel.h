/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kernel.h
 * @brief %jp{カーネルヘッダファイル}%en{uITRON4.0 kernel header file}
 *
 * @version $Id: kernel.h,v 1.6 2006-08-20 15:19:30 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__kernel_h__
#define _KERNEL__kernel_h__


#include "itron.h"


/** %jp{バージョン情報} */
#define TKERNEL_MAKER				0x0008					/**< %jp{メーカーコード(個人)} */
#define TKERNEL_PRID				0x0000					/**< %jp{カーネルの識別番号(未定)} */
#define TKERNEL_SPVER				0x5402					/**< %jp{ITRON仕様のバージョン(μITRON Ver 4.02)} */
#define TKERNEL_PRVER				0x0000					/**< %jp{カーネルのバージョン番号(HOS-V4a Ver 0.00)} */


#define TMAX_ACTCNT					_KERNEL_TMAX_ACTCNT		/**< %jp{タスクの起動要求キューイング数の最大値} */
#define TMAX_WUPCNT					_KERNEL_TMAX_WUPCNT		/**< %jp{タスクの起床要求キューイング数の最大値} */
#define TMAX_SUSCNT					_KERNEL_TMAX_SUSCNT		/**< %jp{タスクの強制待ちネスト数の最大値} */

#define TMAX_MAXSEM					_KERNEL_TMAX_MAXSEM		/**< %jp{セマフォ資源数の最大値} */


#define _KERNEL_TSZ_ALIGNED(size)	(((size) + _KERNEL_MEM_ALIGN - 1) & ~(_KERNEL_MEM_ALIGN - 1))

/** %jp{データキューの領域のサイズ} */
#define TSZ_DTQ(dtqcnt)				((SIZE)(dtqcnt) * (SIZE)sizeof(VP_INT))

/** %jp{メッセージキューヘッダ領域のサイズ} */
#define TSZ_MPRIHD(maxmpri)			((SIZE)(maxmpri) * (SIZE)sizeof(T_MSG_PRI *))

/** %jp{メモリプール領域のサイズ} */
#define TSZ_MPF(blkcnt, blksz)		((SIZE)(blkcnt) * (SIZE)_KERNEL_TSZ_ALIGNED(blksz))

#define TSZ_MBF(msgcnt, msgsz)		((SIZE)(msgcnt) * (SIZE)((msgsz) + sizeof(UINT)))

#define TSZ_MPL(blkcnt, blksz)		((SIZE)(blkcnt) * ((SIZE)_KERNEL_TSZ_ALIGNED(blksz) + (SZIE)))



/** %jp{バージョン情報} */
typedef struct t_rver
{
	UH      maker;			/**< %jp{カーネルのメーカーコード} */
	UH      prid;			/**< %jp{カーネルの識別番号} */
	UH      spver;			/**< %jp{ITRON仕様のバージョン情報} */
	UH      prver;			/**< %jp{カーネルのバージョン番号} */
	UH      prno[4];		/**< %jp{カーネル製品の管理情報} */
} T_RVER;


/** %jp{タスク生成情報} */
typedef struct t_ctsk
{
	ATR     tskatr;			/**< %jp{タスク属性} */
	VP_INT  exinf;			/**< %jp{タスクの拡張情報} */
	FP      task;			/**< %jp{タスクの起動番地} */
	PRI     itskpri;		/**< %jp{タスクの起動時優先度} */
	SIZE    stksz;			/**< %jp{スタック領域のサイズ(バイト数)} */
	VP      stk;			/**< %jp{スタック領域の先頭番地} */
} T_CTSK;

/** %jp{タスク状態} */
typedef struct t_rtsk
{
	STAT    tskstat;		/**< %jp{タスク状態} */
	PRI     tskpri;			/**< %jp{タスクの現在優先度} */
	PRI	    tskbpri;		/**< %jp{タスクのベース優先度} */
	STAT    tskwait;		/**< %jp{待ち要因} */
	ID      wobjid;			/**< %jp{待ち対象のオブジェクトのID番号} */
	TMO     lefttmo;		/**< %jp{タイムアウトするまでの時間} */
	UINT    actcnt;			/**< %jp{起動要求キューイング回数} */
	UINT    wupcnt;			/**< %jp{起床要求キューイング回数} */
	UINT    suscnt;			/**< %jp{強制待ち要求ネスト回数} */

	/* %jp{以下、独自実装} */
#if _KERNEL_CFG_RTSK_EXINF
	VP_INT  exinf;			/* タスクの拡張情報 */
#endif
} T_RTSK;

/* タスク状態(簡易版) */
typedef struct t_rtst
{
	STAT    tskstat;		/* タスク状態 */
	STAT    tskwait;		/* 待ち要因 */

	/* %jp{以下、独自実装} */
#if _KERNEL_CFG_RTST_EXINF
	VP_INT  exinf;			/* タスクの拡張情報 */
#endif
} T_RTST;


/** %jp{セマフォ生成情報}%en{Semaphore creation information packet} */
typedef struct t_csem
{
	ATR		sematr;			/**< %jp{セマフォ属性}%en{Semaphoer attribute} */
	UINT	isemcnt;		/**< %jp{セマフォ資源数の初期値}%en{Initial semaphoer resource count} */
	UINT	maxsem;			/**< %jp{セマフォの最大資源数}%en{Maximum semaphoer resource count} */
} T_CSEM;

/** %jp{セマフォ状態情報}%en{Semaphore state packet} */
typedef struct t_rsem
{
	ID		wtskid;			/**< %jp{セマフォの待ち行列の先頭のタスクのID番号}%en{ID number of the task at the head of the semaphore's wait queue} */
	UINT	semcnt;			/**< %jp{セマフォの現在の資源数}%en{Current semaphore resource count} */
} T_RSEM;


/** %jp{イベントフラグ生成情報}%en{Eventflag creation information packet} */
typedef struct t_cflg
{
	ATR		flgatr;			/**< %jp{イベントフラグ属性}%en{Eventflag attribute} */
	FLGPTN	iflgptn;		/**< %jp{イベントフラグのビットパターンの初期値}%en{Initial value of eventflag bit pattern} */
} T_CFLG;

/** %jp{イベントフラグ状態}%en{Eventflag state packet} */
typedef struct t_rflg
{
	ID		wtskid;			/**< %jp{イベントフラグの待ち行列の先頭のタスクのID番号}%en{ID number of the task at the head of the eventflag's wait queue} */
	FLGPTN	flgptn;			/**< %jp{イベントフラグの現在のビットパターン}%en{Eventflag's vurrent bit pattern} */
} T_RFLG;


/** %jp{データキュー生成情報}%en{Data queue creation information packet} */
typedef struct t_cdtq
{
	ATR  dtqatr;			/**< %jp{データキュー属性}%en{Data queue attribute} */
	UINT dtqcnt;			/**< %jp{データキュー領域の容量(データの個数)}%en{Capacity of the data queue area(the number of data elements)} */
	VP   dtq;				/**< %jp{データキュー領域の先頭番地}%en{Start address of the data queue area} */
} T_CDTQ;

/** %jp{データキュー状態}%en{Data queue state packet} */
typedef struct t_rdtq
{
	ID   stskid;			/**< %jp{データキューの送信待ち行列の先頭のタスクのID番号}%en{ID number of the task at the head of the send-wait queue} */
	ID   rtskid;			/**< %jp{データキューの受信待ち行列の先頭のタスクのID番号}%en{ID number of the task at the head of the receive-wait queue} */
	UINT sdtqcnt;			/**< %jp{データキューに入っているデータの数}%en{The number of data elemnts int the data queue} */
} T_RDTQ;


/** %jp{メールボックス生成情報} */
typedef struct t_cmbx
{
	ATR		mbxatr;			/**< %jp{メールボックス属性} */
	PRI		maxmpri;		/**< %jp{送信されるメッセージの優先度の最大値} */
	VP		mprihd;			/**< %jp{優先度別のメッセージキューヘッダ領域の先頭番地} */
} T_CMBX;

/** %jp{メールボックス状態} */
typedef struct t_rmbx
{
	ID		wtskid;			/**< %jp{メールボックスの待ち行列の先頭のタスクのID番号} */
	T_MSG	*pk_msg;		/**< %jp{メッセージキューの先頭のメッセージパケットの先頭番地} */
} T_RMBX;



/* ミューテックス生成情報 */
typedef struct t_cmtx
{
	ATR		mtxatr;			/* ミューテックス属性 */
	PRI		ceilpri;		/* ミューテックスの上限優先度 */
} T_CMTX;


/* メッセージバッファ状態情報 */
typedef struct t_rmbf
{
	ID		stskid;			/* メッセージバッファの送信待ち行列の先頭のタスクのID番号 */
	ID		rtskid;			/* メッセージバッファの受信待ち行列の先頭のタスクのID番号 */
	UINT	smsgcnt;		/* メッセージバッファに入っているメッセージの数 */
	SIZE	fmbfsz;			/* メッセージバッファ領域の空き領域のサイズ(バイト数、最低限の管理領域を除く) */
} T_RMBF;


/** %jp{固定長メモリプール生成情報} */
typedef struct t_cmpf
{
	ATR		mpfatr;			/**< %jp{固定長メモリプール属性} */
	UINT	blkcnt;			/**< %jp{獲得できるメモリブロック数(個数)} */
	UINT	blksz;			/**< %jp{メモリブロックのサイズ(バイト数)} */
	VP		mpf;			/**< %jp{固定長メモリプール領域の先頭番地} */
} T_CMPF;


/** %jp{固定長メモリプール状態} */
typedef struct t_rmpf
{
	ID		wtskid;			/**< %jp{固定長メモリプールの待ち行列の先頭のタスクのID番号} */
	UINT	fblkcnt;		/**< %jp{固定長メモリプールの空きメモリブロック数(個数)} */
} T_RMPF;



/* 割込みハンドラの定義用 */
typedef struct t_dinh
{
	ATR		inhatr;			/* 割込みハンドラ属性 */
	FP		inthdr;			/* 割込みハンドラの起動番地 */
} T_DINH;


/* 割込みサービスルーチン生成情報 */
typedef struct t_cisr
{
	ATR    isratr;			/* 割込みサービスルーチン属性 */
	VP_INT exinf;			/* 割込みサービスルーチンの拡張情報 */
	INTNO  intno;			/* 割込みサービスルーチンを付加する割込み番号 */
	FP     isr;				/* 割込みサービスルーチンの起動番地 */
} T_CISR;



#ifdef __cplusplus
extern "C" {
#endif

/* OSの起動 */
ER      vsta_knl(void);										/* カーネルの開始(独自サービスコール) */

/* タスク管理機能 */
ER      cre_tsk(ID tskid, const T_CTSK *pk_ctsk);			/* タスクの生成 */
ER_ID   acre_tsk(const T_CTSK *pk_ctsk);					/* タスクの生成(ID番号自動割付け) */
ER      del_tsk(ID tskid);									/* タスクの削除 */
ER      act_tsk(ID tskid);									/* タスクの起動 */
ER_UINT can_act(ID tskid);									/* タスク起動要求のキャンセル */
ER      sta_tsk(ID tskid, VP_INT stacd);					/* タスクの起動(起動コード指定) */
void    ext_tsk(void);										/* 自タスクの終了 */
void    exd_tsk(void);										/* 自タスクの終了と削除 */
ER      ter_tsk(ID tskid);									/* タスクの強制終了 */
ER      chg_pri(ID tskid, PRI tskpri);						/* タスク優先度の変更 */
ER      get_pri(ID tskid, PRI *p_tskpri);					/* タスク優先度の参照 */
ER      ref_tsk(ID tskid, T_RTSK *p_rtsk);					/* タスクの状態参照 */
ER      ref_tst(ID tskid, T_RTST *p_rtst);					/* タスクの状態参照(簡易版) */

/* タスク付属同期機能 */
ER      slp_tsk(void);										/* タスクの起床待ち */
ER      tslp_tsk(TMO tmout);								/* タスクの起床待ち(タイムアウトあり) */
ER      wup_tsk(ID tskid);									/* タスクの起床 */
#define iwup_tsk		wup_tsk
ER_UINT can_wup(ID tskid);									/* タスク起床要求のキャンセル */
ER      rel_wai(ID tskid);									/* 待ち状態の強制解除 */
#define irel_wai		rel_wai
ER      sus_tsk(ID tskid);									/* 強制待ち状態への移行 */
ER      rsm_tsk(ID tskid);									/* 強制待ち状態からの再開 */
ER      frsm_tsk(ID tskid);									/* 強制待ち状態からの強制再開 */
ER      dly_tsk(RELTIM dlytim);								/* 自タスクの遅延 */

/* タスク例外処理機能 */
ER      ras_tex(ID tskid, TEXPTN rasptn);					/* タスク例外処理の要求 */
ER      dis_tex(void);										/* タスク例外処理の禁止 */
ER      ena_tex(void);										/* タスク例外処理の禁止 */
BOOL    sns_tex(void);										/* タスク例外処理禁止状態の参照 */

/* %jp{セマフォ}%en{Semphores} */
ER      cre_sem(ID semid, const T_CSEM *pk_csem);			/**< %jp{セマフォの生成}%en{Create Semaphore} */
ER_ID   acre_sem(const T_CSEM *pk_csem);					/**< %jp{セマフォの生成(ID番号自動割付け)}%en{Create Semaphore(ID Number Automatic Assignment)} */
ER      del_sem(ID semid);									/**< %jp{セマフォの削除}%en{Delete Semaphore} */
ER      sig_sem(ID semid);									/**< %jp{セマフォ資源の返却}%en{Release Semaphore Resource} */
#define isig_sem sig_sem									/**< %jp{セマフォ資源の返却(非タスクコンテキスト用)}%en{Release Semaphore Resource} */
ER      wai_sem(ID semid);									/**< %jp{セマフォ資源の獲得}%en{Acquire Semaphore Resource} */
ER      pol_sem(ID semid);									/**< %jp{セマフォ資源の獲得(ポーリング)}%en{Acquire Semaphore Resource(Polling)} */
ER      twai_sem(ID semid, TMO tmout);						/**< %jp{セマフォ資源の獲得(タイムアウトあり)}%en{Acquire Semaphore Resource(with Timeout)} */
ER      ref_sem(ID semid, T_RSEM *pk_rsem);					/**< %jp{セマフォの状態参照}%en{Reference Semaphore State} */

/* %jp{イベントフラグ}%en{Eventflags} */
ER      cre_flg(ID flgid, const T_CFLG *pk_cflg);			/**< %jp{イベントフラグの生成}%en{Create Eventflag} */
ER_ID   acre_flg(const T_CFLG *pk_cflg);					/**< %jp{イベントフラグの生成(ID番号自動割付)}%en{Create Eventflag(ID Number Automatic Assignment)} */
ER      del_flg(ID flgid);									/**< %jp{イベントフラグの削除}%en{Delete Eventflag} */
ER      set_flg(ID flgid, FLGPTN setptn);					/**< %jp{イベントフラグのセット}%en{Set Eventflag} */
#define iset_flg	set_flg									/**< %jp{イベントフラグのセット(非タスクコンテキスト用)}%en{Set Eventflag} */
ER      clr_flg(ID flgid, FLGPTN clrptn);					/**< %jp{イベントフラグのクリア}%en{Clear Eventflag} */
ER      wai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn);
															/**< %jp{イベントフラグ待ち}%en{Wait for Eventflag} */
ER      pol_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn);
															/**< %jp{イベントフラグ待ち(ポーリング)}%en{Wait for Eventflag(Polling)} */
ER      twai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn, TMO tmout);
															/**< %jp{イベントフラグ待ち(タイムアウトあり)}%en{Wait for Eventflag(with Timeout)} */
ER      ref_flg(ID flgid, T_RFLG *pk_rflg);					/**< %jp{イベントフラグの状態参照}%en{Reference Eventflag State} */

/* %jp{データキュー}%en{Data queue} */
#define _kernel_ini_dtq()									/**< %jp{データキューの初期化} */
ER      cre_dtq(ID dtqid, const T_CDTQ *pk_cdtq);			/**< %jp{データキューの生成} */
ER_ID   acre_dtq(const T_CDTQ *pk_cdtq);					/**< %jp{データキューの生成(ID番号自動割付け)} */
ER      kernel_cre_dtq(ID dtqid, const T_CDTQ *pk_cdtq);	/**< %jp{データキューの生成(カーネル内部関数)} */
ER      del_dtq(ID dtqid);									/**< %jp{データキューの削除} */
ER      snd_dtq(ID dtqid, VP_INT data);						/**< %jp{データキューへの送信} */
ER      psnd_dtq(ID dtqid, VP_INT data);					/**< %jp{データキューへの送信(ポーリング)} */
#define ipsnd_dtq	psnd_dtq								/**< %jp{データキューへの送信(ポーリング 非タスクコンテキスト用マクロ)} */
ER      tsnd_dtq(ID dtqid, VP_INT data, TMO tmout);			/**< %jp{データキューへの送信(タイムアウトあり)} */
ER      fsnd_dtq(ID dtqid, VP_INT data);					/**< %jp{データキューへの強制送信} */
#define ifsnd_dtq	fsnd_dtq								/**< %jp{データキューへの強制送信(非タスクコンテキスト用マクロ)} */
ER      rcv_dtq(ID dtqid, VP_INT *p_data);					/**< %jp{データキューからの受信} */
ER      prcv_dtq(ID dtqid, VP_INT *p_data);					/**< %jp{データキューからの受信(ポーリング)} */
ER      trcv_dtq(ID dtqid, VP_INT *p_data, TMO tmout);		/**< %jp{データキューからの受信(タイムアウトあり)} */
ER      ref_dtq(ID dtqid, T_RDTQ *pk_rdtq);					/**< %jp{データキューの状態参照} */

/* %jp{メールボックス}%en{Mailboxes} */
ER      cre_mbx(ID semid, const T_CMBX *pk_cmbx);			/**< %jp{メールボックスの生成} */
ER_ID   acre_mbx(const T_CMBX *pk_cmbx);					/**< %jp{メールボックスの生成(ID番号自動割付け)} */
ER      del_mbx(ID semid);									/**< %jp{メールボックスの削除} */
ER      snd_mbx(ID mbxid, T_MSG *pk_msg);					/**< %jp{メールボックスへの送信} */
ER      rcv_mbx(ID mbxid, T_MSG **ppk_msg);					/**< %jp{メールボックスからの受信} */
ER      prcv_mbx(ID mbxid, T_MSG **ppk_msg);				/**< %jp{メールボックスからの受信(ポーリング)} */
ER      trcv_mbx(ID mbxid, T_MSG **ppk_msg, TMO tmout);		/**< %jp{メールボックスからの受信(タイムアウトあり)} */
ER      ref_mbx(ID mbxid, T_RMBX *pk_rmbx);					/**< %jp{メールボックスの状態参照} */

/* %jp{固定長メモリプール} */
ER      cre_mpf(ID mpfid, const T_CMPF *pk_cmpf);			/**< %jp{固定長メモリプールの生成} */
ER_ID   acre_mpf(const T_CMPF *pk_cmpf);					/**< %jp{固定長メモリプールの生成(ID番号自動割付け)} */
ER      del_mpf(ID mpfid);									/**< %jp{固定長メモリプールの削除} */
ER      get_mpf(ID mpfid, VP *p_blk);						/**< %jp{固定長メモリブロックの獲得} */
ER      pget_mpf(ID mpfid, VP *p_blk);						/**< %jp{固定長メモリブロックの獲得(ポーリング)} */
ER      tget_mpf(ID mpfid, VP *p_blk, TMO tmout);			/**< %jp{固定長メモリブロックの獲得(タイムアウトあり)} */
ER      rel_mpf(ID mpfid, VP blk);							/**< %jp{固定長メモリブロックの返却} */
ER      ref_mpf(ID mpfid, T_RMPF *pk_rmpf);					/**< %jp{固定長メモリブロックの状態参照} */


/* %jp{システム時間管理機能}%en{System Time Management} */
ER      set_tim(const SYSTIM *p_system);					/**< %jp{システム時刻の設定}%en{Set System Time} */
ER      get_tim(SYSTIM *p_system);							/**< %jp{システム時刻の参照}%en{Reference System Time} */
ER      isig_tim(void);										/**< %jp{タイムティックの供給}%en{Supply Time Tick} */


/* システム状態管理機能 */
ER      rot_rdq(PRI tskpri);								/* タスク優先順位の回転 */
ER      get_tid(ID *p_tskid);								/* 実行状態タスクIDの参照 */
ER      loc_cpu(void);										/* CPUロック状態への移行 */
ER      unl_cpu(void);										/* CPUロック状態の解除 */
ER      dis_dsp(void);										/* ディスパッチの禁止 */
ER      ena_dsp(void);										/* ディスパッチの許可 */
BOOL    sns_ctx(void);										/* コンテキストの参照 */
BOOL    sns_loc(void);										/* CPUロック状態の参照 */
BOOL    sns_dsp(void);										/* ディスパッチ禁止状態の参照 */
BOOL    sns_dpn(void);										/* ディスパッチ保留状態の参照 */


ER      def_inh(INHNO inhno, const T_DINH *pk_dinh);

ER      dis_int(INTNO intno);								/* 割り込みの禁止 */
ER      ena_int(INTNO intno);								/* 割り込みの許可 */

/* システム構成管理機能 */
ER      ref_ver(T_RVER *pk_rver);							/* バージョン番号の参照 */


#ifdef __cplusplus
}
#endif


#endif /* _KERNEL__kernel_h__ */



/* end of file */
