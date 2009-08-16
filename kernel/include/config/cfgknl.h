/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cfgknl.h
 * @brief %jp{カーネル仕様のコンフィギュレーション用ヘッダファイル}%en{kernel configuration heder file}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


/*
%jp{
  本ファイルにて、カーネル内部のコンフィギュレーションを行う。
  本ファイルの変更後はカーネルのリビルドが必要である。
  また、本ファイルはセンブリ言語の前処理にも使う事を想定しているので、
C言語構文(例えばtypedefなど)はこの中には記載せず、マクロ定義などの
プリプロセッサディレクティブのみを記載する事とする。
}
*/



#ifndef _KERNEL__config__cfgknl_h__
#define _KERNEL__config__cfgknl_h__



/* ---------------------------------------------- */
/*  Optimize                                      */
/* ---------------------------------------------- */

/* %jp{数値の小さいものを優先して最適化する} */
#define _KERNEL_CFG_OPT_RW_SIZE			1					/**< %jp{リードライトデータサイズ(通常はRAM配置)の優先度} */
#define _KERNEL_CFG_OPT_RO_SIZE			2					/**< %jp{リードオンリーデータ(通常はROM配置)のサイズの優先度} */
#define _KERNEL_CFG_OPT_CODE_SIZE		2					/**< %jp{コードサイズ(通常はROM配置)の優先度} */
#define _KERNEL_CFG_OPT_SPEED			3					/**< %jp{実行速度の優先度} */
#define _KERNEL_CFG_OPT_POWER			3					/**< %jp{消費電力の優先度} */



/* ---------------------------------------------- */
/*  ID number                                     */
/* ---------------------------------------------- */

/* %jp{最大オブジェクトID値} */
#define _KERNEL_CFG_TMAX_TSKID			127					/**< %jp{タスクIDの最大値} */
#define _KERNEL_CFG_TMAX_SEMID			127					/**< %jp{セマフォIDの最大値} */
#define _KERNEL_CFG_TMAX_FLGID			127					/**< %jp{イベントフラグIDの最大値} */
#define _KERNEL_CFG_TMAX_DTQID			127					/**< %jp{データキューIDの最大値} */
#define _KERNEL_CFG_TMAX_MBXID			127					/**< %jp{メールボックスIDの最大値} */
#define _KERNEL_CFG_TMAX_MTXID			127					/**< %jp{ミューテックスIDの最大値} */
#define _KERNEL_CFG_TMAX_MBFID			127					/**< %jp{メッセージバッファIDの最大値} */
#define _KERNEL_CFG_TMAX_PORID			127					/**< %jp{ランデブーIDの最大値} */
#define _KERNEL_CFG_TMAX_MPFID			127					/**< %jp{固定長メモリプールIDの最大値} */
#define _KERNEL_CFG_TMAX_MPLID			127					/**< %jp{可変長メモリプールIDの最大値} */
#define _KERNEL_CFG_TMAX_CYCID			127					/**< %jp{周期ハンドラIDの最大値} */
#define _KERNEL_CFG_TMAX_ALMID			127					/**< %jp{アラームハンドラIDの最大値} */
#define _KERNEL_CFG_TMAX_OVRID			127					/**< %jp{オーバーランハンドラIDの最大値} */
#define _KERNEL_CFG_TMAX_ISRID			127					/**< %jp{割込みサービスルーチンIDの最大値} */

/* %jp{コンフィギュレータ未指定時デフォルト最大ID値} */
#define _KERNEL_CFG_DEF_TMAX_TSKID		15					/**< %jp{タスクIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_SEMID		15					/**< %jp{セマフォIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_FLGID		15					/**< %jp{イベントフラグIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_DTQID		15					/**< %jp{データキューIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_MBXID		15					/**< %jp{メールボックスIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_MTXID		15					/**< %jp{ミューテックスIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_MBFID		15					/**< %jp{メッセージバッファIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_PORID		15					/**< %jp{ランデブーIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_MPFID		15					/**< %jp{固定長メモリプールIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_MPLID		15					/**< %jp{可変長メモリプールIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_CYCID		15					/**< %jp{周期ハンドラIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_ALMID		15					/**< %jp{アラームハンドラIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_OVRID		15					/**< %jp{オーバーランハンドラIDの最大値} */
#define _KERNEL_CFG_DEF_TMAX_ISRID		15					/**< %jp{割込みサービスルーチンIDの最大値} */



/* ---------------------------------------------- */
/*  Kernel-internal                               */
/* ---------------------------------------------- */

/* %jp{遅延プロシージャーコール}%en{Deferred Procedure Call} */
#define _KERNEL_CFG_DPC					FALSE

/* %jp{対称型マルチプロセッサ対応[未実装]}{%en{Symmetric Multiple Processor[unsupported]} */
#define _KERNEL_CFG_SMP					FALSE

/* %jp{多重割込み対応}%en{Multiple interrupt} */
#define _KERNEL_CFG_MULTIPLE_INT		TRUE

/* %jp{システムタスクにTCBを割り当てる(高速化するがメモリがやや増える？) [未実装]} */
#define _KERNEL_CFG_SYSTSK_TCB			FALSE

/* %jp{実行時にタスクをレディーキューに繋げたままとする [未実装]} */
#define _KERNEL_CFG_RUNTSK_ON_RDQ		TRUE

/* %jp{サスペンド時にタスクをレディーキューに繋げたままとする [未実装]} */
#define _KERNEL_CFG_SUSTSK_ON_RDQ		FALSE


/* %jp{タスクハンドルをIDで管理(省メモリだが低速)にするかどうか} */
#define _KERNEL_CFG_TSKHDL_ID			TRUE

/* %jp{ミューテックスハンドルをIDで管理(省メモリだが低速)にするかどうか [未実装]} */
#define _KERNEL_CFG_MTXHDL_ID			TRUE

/* %jp{割込みサービスルーチンハンドルをIDで管理(省メモリだが低速)にするかどうか} */
#define _KERNEL_CFG_ISRHDL_ID			FALSE



/* ---------------------------------------------- */
/*  General task-queue                            */
/* ---------------------------------------------- */

/** %jp{キューのアルゴリズム} */
#define _KERNEL_CFG_QUE_ALGORITHM		_KERNEL_QUE_ALG_ONEWAYLIST

/* %jp{
   _KERNEL_QUE_ALG_ONEWAYLIST : 単方向キュー(省メモリだが取り外しが遅い)
   _KERNEL_QUE_ALG_TWOWAYLIST : 双方向キュー(取り外しが高速)
   _KERNEL_QUE_ALG_AUTO       : 自動選択(最適化指定から自動で選択する)
}%en{
   _KERNEL_QUE_ALG_ONEWAYLIST : small-memory
   _KERNEL_QUE_ALG_TWOWAYLIST : high-speed
   _KERNEL_QUE_ALG_AUTO       : auto select
}*/



/* ---------------------------------------------- */
/*  Ready-queue                                   */
/* ---------------------------------------------- */

/** %jp{レディーキューのアルゴリズム} */
#define _KERNEL_CFG_RDQ_ALGORITHM		_KERNEL_RDQ_ALG_SINGLE_QUE

/* %jp{
   _KERNEL_RDQ_ALG_SINGLE_QUE         : シングルキュー(省メモリだが、タスク数が増えると遅い)
   _KERNEL_RDQ_ALG_ARRAYED_QUE        : 優先度数だけキューを配列化(ある程度高速だが、優先度数でメモリ消費)
   _KERNEL_RDQ_ALG_BITMAP_ARRAYED_QUE : 配列化キューに探索ビットマップを備える(優先度数が少なければ高速)   [未実装]
   _KERNEL_RDQ_ALG_HEAP_QUE           : ヒープ木(優先度数が多くてもそこそこ裁ける)                         [未実装]
}%en{
   _KERNEL_RDQ_ALG_SINGLE_QUE         : 
   _KERNEL_RDQ_ALG_ARRAYED_QUE        : 
   _KERNEL_RDQ_ALG_BITMAP_ARRAYED_QUE : 
   _KERNEL_RDQ_ALG_HEAP_QUE           : 
}*/



/* ---------------------------------------------- */
/*  Tasks                                         */
/* ---------------------------------------------- */

/* Attribute */
#define _KERNEL_CFG_TSK_TA_ACT			TRUE				/**< %jp{TA_TACTに対応する} */


/** %jp{タスクコントロールブロックの管理アルゴリズム} */
#define _KERNEL_CFG_TCB_ALGORITHM		_KERNEL_TCB_ALG_PTRARRAY

/* %jp{
   _KERNEL_TCB_ALG_BLKARRAY	: TCBブロック自体を配列化して管理(予めブロックを確保)
   _KERNEL_TCB_ALG_PTRARRAY	: TCBを指すポインタを配列化して管理(ブロック本体は動的にメモリ確保)
}*/


#define _KERNEL_CFG_TCB_SPLIT_RO		FALSE				/**< %jp{TCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_TCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */
#define _KERNEL_CFG_TCB_TTW_PACK		TRUE				/**< %jp{待ち要因を圧縮して保持するか} */



/* ---------------------------------------------- */
/*  Task Exception Handling Routine               */
/* ---------------------------------------------- */

/** %jp{タスク例外処理ルーチンコントロールブロックの管理アルゴリズム} */
#define _KERNEL_CFG_TEXCB_ALGORITHM		_KERNEL_TEXCB_ALG_PTRARRAY

/* %jp{
   _KERNEL_TCB_ALG_BLKARRAY	: TCBブロック自体を配列化して管理(予めブロックを確保)
   _KERNEL_TCB_ALG_PTRARRAY	: TCBを指すポインタを配列化して管理(ブロック本体は動的にメモリ確保)
}*/

#define _KERNEL_CFG_TEXCB_SPLIT_RO		FALSE				/**< %jp{TEXCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_TEXCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTEXCBを圧縮するか} */



/* ---------------------------------------------- */
/*  Smaphores                                     */
/* ---------------------------------------------- */

/* Attribute */
#define _KERNEL_CFG_SEM_TA_TFIFO		TRUE				/**< %jp{TA_TFIFO属性に対応する} */
#define _KERNEL_CFG_SEM_TA_TPRI			TRUE				/**< %jp{TA_TPRI属性に対応する} */
#define _KERNEL_CFG_SEM_MAXSEM			TRUE				/**< %jp{maxsem(上限チェック)を使う} */

/* Control block */
#define _KERNEL_CFG_SEMCB_ALGORITHM		_KERNEL_SEMCB_ALG_PTRARRAY
#define _KERNEL_CFG_SEMCB_SPLIT_RO		FALSE				/**< %jp{TCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_SEMCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */



/* ---------------------------------------------- */
/*  Eventflags                                    */
/* ---------------------------------------------- */

/* Attribute */
#define _KERNEL_CFG_FLG_TA_TFIFO		TRUE				/**< %jp{TA_TFIFO属性に対応する} */
#define _KERNEL_CFG_FLG_TA_TPRI			TRUE				/**< %jp{TA_TPRI属性に対応する} */
#define _KERNEL_CFG_FLG_TA_WSGL			TRUE				/**< %jp{TA_WSGL属性に対応する} */
#define _KERNEL_CFG_FLG_TA_WMUL			TRUE				/**< %jp{TA_WMUL属性に対応する} */
#define _KERNEL_CFG_FLG_TA_CLR			TRUE				/**< %jp{TA_CLR属性に対応する} */

/* Control block */
#define _KERNEL_CFG_FLGCB_ALGORITHM		_KERNEL_FLGCB_ALG_PTRARRAY
#define _KERNEL_CFG_FLGCB_SPLIT_RO		FALSE				/**< %jp{TCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_FLGCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */


/* ---------------------------------------------- */
/*  Data queues                                   */
/* ---------------------------------------------- */

/* Configuration */
#define _KERNEL_CFG_DTQ_DTQCNT_ZERO		TRUE				/**< %jp{キューサイズ0に対応する} */
#define _KERNEL_CFG_DTQ_DTQCNT_NONZERO	TRUE				/**< %jp{キューサイズ非0に対応する} */

/* Attribute */
#define _KERNEL_CFG_DTQ_TA_TFIFO		TRUE				/**< %jp{TA_TFIFO属性に対応する} */
#define _KERNEL_CFG_DTQ_TA_TPRI			TRUE				/**< %jp{TA_TPRI属性に対応する} */

/* Control block */
#define _KERNEL_CFG_DTQCB_ALGORITHM		_KERNEL_DTQCB_ALG_PTRARRAY
#define _KERNEL_CFG_DTQCB_SPLIT_RO		FALSE				/**< %jp{TCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_DTQCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */


/* ---------------------------------------------- */
/*  Mailboxes                                     */
/* ---------------------------------------------- */

/* Attribute */
#define _KERNEL_CFG_MBX_TA_TFIFO		TRUE				/**< %jp{TA_TFIFO属性に対応する} */
#define _KERNEL_CFG_MBX_TA_TPRI			TRUE				/**< %jp{TA_TPRI属性に対応する} */
#define _KERNEL_CFG_MBX_TA_MFIFO		TRUE				/**< %jp{TA_MFIFO属性に対応する} */
#define _KERNEL_CFG_MBX_TA_MPRI			TRUE				/**< %jp{TA_MPRI属性に対応する} */


/* Algorithm */
#define _KERNEL_CFG_MBX_ALGORITHM		_KERNEL_MBX_ALG_ARRAYED_MQUE
/* %jp{
   _KERNEL_MBX_ALG_SINGLE_MQUE  : 一本のメッセージキューで構成する(優先度探索するので低速)          [未実装]
   _KERNEL_MBX_ALG_ARRAYED_MQUE : 優先度の数だけ配列状にキューを持つ(優先度数によってメモリを消費)
}*/


/* Control block */
#define _KERNEL_CFG_MBXCB_ALGORITHM		_KERNEL_MBXCB_ALG_PTRARRAY
#define _KERNEL_CFG_MBXCB_SPLIT_RO		FALSE				/**< %jp{TCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_MBXCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */



/* ---------------------------------------------- */
/*  Mutex                                         */
/* ---------------------------------------------- */

/* Attribute */
#define _KERNEL_CFG_MTX_TA_TFIFO		TRUE				/**< %jp{TA_TFIFO属性に対応する} */
#define _KERNEL_CFG_MTX_TA_TPRI			TRUE				/**< %jp{TA_TPRI属性に対応する} */
#define _KERNEL_CFG_MTX_TA_INHERIT		TRUE				/**< %jp{TA_INHERIT属性に対応する} */
#define _KERNEL_CFG_MTX_TA_CEILING		TRUE				/**< %jp{TA_CEILING属性に対応する} */

/* Control block */
#define _KERNEL_CFG_MTXCB_ALGORITHM		_KERNEL_MTXCB_ALG_PTRARRAY
#define _KERNEL_CFG_MTXCB_SPLIT_RO		FALSE				/**< %jp{TCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_MTXCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */



/* ---------------------------------------------- */
/*  Fixed-sized Memory Pools                      */
/* ---------------------------------------------- */

/* Attribute */
#define _KERNEL_CFG_MPF_TA_TFIFO		TRUE				/**< %jp{TA_TFIFO属性に対応する} */
#define _KERNEL_CFG_MPF_TA_TPRI			TRUE				/**< %jp{TA_TPRI属性に対応する} */

/* Value range */
#define _KERNEL_CFG_MPF_TMAX_BLKCNT		(-1)				/**< %jp{ブロック数の最大値} */
#define _KERNEL_CFG_MPF_TMAX_BLKSZ		(-1)				/**< %jp{ブロックサイズの最大値} */

/* Algorithm */
#define _KERNEL_CFG_MPF_ALGORITHM		_KERNEL_MPF_ALG_CHAIN_NUM
/* %jp{
   _KERNEL_MPF_ALG_CHAIN_PTR : 空きブロックをポインタでチェイン(乗算器の無いCPUでも高速)
   _KERNEL_MPF_ALG_CHAIN_NUM : 空きブロックをブロック番号でチェイン(メモリが削減できる場合あり)
}*/

/* Control block */
#define _KERNEL_CFG_MPFCB_ALGORITHM		_KERNEL_MPFCB_ALG_PTRARRAY
#define _KERNEL_CFG_MPFCB_SPLIT_RO		FALSE				/**< %jp{MPFCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_MPFCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */



/* ------------------------------------------------------------------ */
/*  System Time Management                                            */
/* ------------------------------------------------------------------ */

/* %jp{タイムティックの周期}%en{Time Tick Period} */
#define _KERNEL_CFG_FRACTIONAL_TIMTIC	TRUE				/**< %jp{コンフィギュレータでタイムティックの分数指定を許す} */
#define _KERNEL_CFG_TIC_NUME			1					/**< %jp{デフォルトのタイムティック周期の分子} */
#define _KERNEL_CFG_TIC_DENO			1					/**< %jp{デフォルトのタイムティック周期の分母} */



/* ------------------------------------------------------------------ */
/*  Cyclic Handlers                                                   */
/* ------------------------------------------------------------------ */

/* Attribute */
#define _KERNEL_CFG_CYC_TA_STA			TRUE				/**< %jp{TA_STA属性に対応する} */
#define _KERNEL_CFG_CYC_TA_PHS			TRUE				/**< %jp{TA_PHS属性に対応する} */

/* Control block */
#define _KERNEL_CFG_CYCCB_ALGORITHM		_KERNEL_CYCCB_ALG_PTRARRAY
#define _KERNEL_CFG_CYCCB_SPLIT_RO		FALSE				/**< %jp{CYCCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_CYCCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */



/* ---------------------------------------------- */
/*  Interrupt Service Routines                    */
/* ---------------------------------------------- */

/* Control block */
#define _KERNEL_CFG_ISRCB_ALGORITHM		_KERNEL_ISRCB_ALG_PTRARRAY
#define _KERNEL_CFG_ISRCB_SPLIT_RO		FALSE				/**< %jp{ISRCBの不変部を分割してROM部配置とするか} */
#define _KERNEL_CFG_ISRCB_BITFIELD		FALSE				/**< %jp{ビットフィールドを利用してTCBを圧縮するか} */





/* ---------------------------------------------- */
/*  Service call support                          */
/* ---------------------------------------------- */

/* Task management functions */
#define _KERNEL_CFG_CRE_TSK				TRUE				/* cre_tsk */
#define _KERNEL_CFG_ACRE_TSK			TRUE				/* acre_tsk */
#define _KERNEL_CFG_DEL_TSK				TRUE				/* del_tsk */
#define _KERNEL_CFG_ACT_TSK				TRUE				/* act_tsk */
#define _KERNEL_CFG_IACT_TSK			TRUE				/* iact_tsk */
#define _KERNEL_CFG_CAN_ACT 			TRUE				/* can_act */
#define _KERNEL_CFG_STA_TSK 			TRUE				/* sta_tsk */
#define _KERNEL_CFG_EXT_TSK 			TRUE				/* ext_tsk */
#define _KERNEL_CFG_EXD_TSK 			TRUE				/* exd_tsk */
#define _KERNEL_CFG_TER_TSK 			TRUE				/* ter_tsk */
#define _KERNEL_CFG_CHG_PRI 			TRUE				/* chg_pri */
#define _KERNEL_CFG_GET_PRI 			TRUE				/* get_pri */
#define _KERNEL_CFG_REF_TSK 			TRUE				/* ref_tsk */
#define _KERNEL_CFG_REF_TST 			TRUE				/* ref_tst */

/* Task dependent synchronization functions */
#define _KERNEL_CFG_SLP_TSK 			TRUE				/* slp_tsk */
#define _KERNEL_CFG_TSLP_TSK			TRUE				/* tslp_tsk */
#define _KERNEL_CFG_WUP_TSK 			TRUE				/* wup_tsk */
#define _KERNEL_CFG_IWUP_TSK			TRUE				/* iwup_tsk */
#define _KERNEL_CFG_CAN_WUP 			TRUE				/* can_wup */
#define _KERNEL_CFG_REL_WAI 			TRUE				/* rel_wai */
#define _KERNEL_CFG_IREL_WAI			TRUE				/* irel_wai */
#define _KERNEL_CFG_SUS_TSK 			TRUE				/* sus_tsk */
#define _KERNEL_CFG_RSM_TSK 			TRUE				/* rsm_tsk */
#define _KERNEL_CFG_FRSM_TSK			TRUE				/* frsm_tsk */
#define _KERNEL_CFG_DLY_TSK 			TRUE				/* dly_tsk */

/* Task exception handling functions */
#define _KERNEL_CFG_DEF_TEX 			TRUE				/* def_tex */
#define _KERNEL_CFG_RAS_TEX 			TRUE				/* ras_tex */
#define _KERNEL_CFG_IRAS_TEX			TRUE				/* iras_tex */
#define _KERNEL_CFG_DIS_TEX 			TRUE				/* dis_tex */
#define _KERNEL_CFG_ENA_TEX 			TRUE				/* ena_tex */
#define _KERNEL_CFG_SNS_TEX 			TRUE				/* sns_tex */
#define _KERNEL_CFG_REF_TEX 			TRUE				/* ref_tex */

/* Semaphores */
#define _KERNEL_CFG_CRE_SEM 			TRUE				/* cre_sem */
#define _KERNEL_CFG_ACRE_SEM			TRUE				/* acre_sem */
#define _KERNEL_CFG_DEL_SEM 			TRUE				/* del_sem */
#define _KERNEL_CFG_SIG_SEM 			TRUE				/* sig_sem */
#define _KERNEL_CFG_ISIG_SEM			TRUE				/* isig_sem */
#define _KERNEL_CFG_WAI_SEM 			TRUE				/* wai_sem */
#define _KERNEL_CFG_POL_SEM 			TRUE				/* pol_sem */
#define _KERNEL_CFG_TWAI_SEM			TRUE				/* twai_sem */
#define _KERNEL_CFG_REF_SEM 			TRUE				/* ref_sem */

/* Eventflags */
#define _KERNEL_CFG_CRE_FLG 			TRUE				/* cre_flg */
#define _KERNEL_CFG_ACRE_FLG			TRUE				/* acre_flg */
#define _KERNEL_CFG_DEL_FLG 			TRUE				/* del_flg */
#define _KERNEL_CFG_SET_FLG 			TRUE				/* set_flg */
#define _KERNEL_CFG_ISET_FLG			TRUE				/* iset_flg */
#define _KERNEL_CFG_CLR_FLG 			TRUE				/* clr_flg */
#define _KERNEL_CFG_WAI_FLG 			TRUE				/* wai_flg */
#define _KERNEL_CFG_POL_FLG 			TRUE				/* pol_flg */
#define _KERNEL_CFG_TWAI_FLG			TRUE				/* twai_flg */
#define _KERNEL_CFG_REF_FLG 			TRUE				/* ref_flg */

/* Data queues */
#define _KERNEL_CFG_CRE_DTQ 			TRUE				/* cre_dtq */
#define _KERNEL_CFG_ACRE_DTQ			TRUE				/* acre_dtq */
#define _KERNEL_CFG_DEL_DTQ 			TRUE				/* del_dtq */
#define _KERNEL_CFG_SND_DTQ 			TRUE				/* snd_dtq */
#define _KERNEL_CFG_PSND_DTQ			TRUE				/* psnd_dtq */
#define _KERNEL_CFG_IPSND_DTQ			TRUE				/* ipsnd_dtq */
#define _KERNEL_CFG_TSND_DTQ			TRUE				/* tsnd_dtq */
#define _KERNEL_CFG_FSND_DTQ			TRUE				/* fsnd_dtq */
#define _KERNEL_CFG_IFSND_DT			TRUE				/* ifsnd_dtq */
#define _KERNEL_CFG_RCV_DTQ 			TRUE				/* rcv_dtq */
#define _KERNEL_CFG_PRCV_DTQ			TRUE				/* prcv_dtq */
#define _KERNEL_CFG_TRCV_DTQ			TRUE				/* trcv_dtq */
#define _KERNEL_CFG_REF_DTQ 			TRUE				/* ref_dtq */

/* Mailboxes */
#define _KERNEL_CFG_CRE_MBX 			TRUE				/* cre_mbx */
#define _KERNEL_CFG_ACRE_MBX			TRUE				/* acre_mbx */
#define _KERNEL_CFG_DEL_MBX 			TRUE				/* del_mbx */
#define _KERNEL_CFG_SND_MBX 			TRUE				/* snd_mbx */
#define _KERNEL_CFG_RCV_MBX 			TRUE				/* rcv_mbx */
#define _KERNEL_CFG_PRCV_MBX			TRUE				/* prcv_mbx */
#define _KERNEL_CFG_TRCV_MBX			TRUE				/* trcv_mbx */
#define _KERNEL_CFG_REF_MBX 			TRUE				/* ref_mbx */

/* Mutexes */
#define _KERNEL_CFG_CRE_MTX 			TRUE				/* cre_mtx */
#define _KERNEL_CFG_ACRE_MTX			TRUE				/* acre_mtx */
#define _KERNEL_CFG_DEL_MTX 			TRUE				/* del_mtx */
#define _KERNEL_CFG_LOC_MTX 			TRUE				/* loc_mtx */
#define _KERNEL_CFG_PLOC_MTX			TRUE				/* ploc_mtx */
#define _KERNEL_CFG_TLOC_MTX			TRUE				/* tloc_mtx */
#define _KERNEL_CFG_UNL_MTX 			TRUE				/* unl_mtx */
#define _KERNEL_CFG_REF_MTX 			TRUE				/* ref_mtx */

/* Message buffers */
#define _KERNEL_CFG_CRE_MBF 			FALSE				/* cre_mbf */
#define _KERNEL_CFG_ACRE_MBF			FALSE				/* acre_mbf */
#define _KERNEL_CFG_DEL_MBF 			FALSE				/* del_mbf */
#define _KERNEL_CFG_SND_MBF 			FALSE				/* snd_mbf */
#define _KERNEL_CFG_PSND_MBF			FALSE				/* psnd_mbf */
#define _KERNEL_CFG_TSND_MBF			FALSE				/* tsnd_mbf */
#define _KERNEL_CFG_RCV_MBF 			FALSE				/* rcv_mbf */
#define _KERNEL_CFG_PRCV_MBF			FALSE				/* prcv_mbf */
#define _KERNEL_CFG_TRCV_MBF			FALSE				/* trcv_mbf */
#define _KERNEL_CFG_REF_MBF 			FALSE				/* ref_mbf */

/* Rendezvous */
#define _KERNEL_CFG_CRE_POR 			FALSE				/* cre_por */
#define _KERNEL_CFG_ACRE_POR			FALSE				/* acre_por */
#define _KERNEL_CFG_DEL_POR 			FALSE				/* del_por */
#define _KERNEL_CFG_CAL_POR 			FALSE				/* cal_por */
#define _KERNEL_CFG_TCAL_POR			FALSE				/* tcal_por */
#define _KERNEL_CFG_ACP_POR 			FALSE				/* acp_por */
#define _KERNEL_CFG_PACP_POR			FALSE				/* pacp_por */
#define _KERNEL_CFG_TACP_POR			FALSE				/* tacp_por */
#define _KERNEL_CFG_FWD_POR 			FALSE				/* fwd_por */
#define _KERNEL_CFG_RPL_RDV 			FALSE				/* rpl_rdv */
#define _KERNEL_CFG_REF_POR 			FALSE				/* ref_por */
#define _KERNEL_CFG_REF_RDV 			FALSE				/* ref_rdv */

/* Fixed-sized memory pools */
#define _KERNEL_CFG_CRE_MPF 			TRUE				/* cre_mpf */
#define _KERNEL_CFG_ACRE_MPF			TRUE				/* acre_mpf */
#define _KERNEL_CFG_DEL_MPF 			TRUE				/* del_mpf */
#define _KERNEL_CFG_GET_MPF 			TRUE				/* get_mpf */
#define _KERNEL_CFG_PGET_MPF			TRUE				/* pget_mpf */
#define _KERNEL_CFG_TGET_MPF			FALSE				/* tget_mpf */
#define _KERNEL_CFG_REL_MPF 			TRUE				/* rel_mpf */
#define _KERNEL_CFG_REF_MPF 			FALSE				/* ref_mpf */

/* Variable-sized memory pools */
#define _KERNEL_CFG_CRE_MPL 			FALSE				/* cre_mpl */
#define _KERNEL_CFG_ACRE_MPL			FALSE				/* acre_mpl */
#define _KERNEL_CFG_DEL_MPL 			FALSE				/* del_mpl */
#define _KERNEL_CFG_GET_MPL 			FALSE				/* get_mpl */
#define _KERNEL_CFG_PGET_MPL			FALSE				/* pget_mpl */
#define _KERNEL_CFG_TGET_MPL			FALSE				/* tget_mpl */
#define _KERNEL_CFG_REL_MPL 			FALSE				/* rel_mpl */
#define _KERNEL_CFG_REF_MPL 			FALSE				/* ref_mpl */

/* System time management */
#define _KERNEL_CFG_SET_TIM 			TRUE				/* set_tim */
#define _KERNEL_CFG_GET_TIM 			TRUE				/* get_tim */
#define _KERNEL_CFG_ISIG_TIM			TRUE				/* isig_tim */

/* Cyclic handlers */
#define _KERNEL_CFG_CRE_CYC 			TRUE				/* cre_cyc */
#define _KERNEL_CFG_ACRE_CYC			TRUE				/* acre_cyc */
#define _KERNEL_CFG_DEL_CYC 			TRUE				/* del_cyc */
#define _KERNEL_CFG_STA_CYC 			TRUE				/* sta_cyc */
#define _KERNEL_CFG_STP_CYC 			TRUE				/* stp_cyc */
#define _KERNEL_CFG_REF_CYC 			TRUE				/* ref_cyc */

/* Alarm handlers */
#define _KERNEL_CFG_CRE_ALM 			FALSE				/* cre_alm */
#define _KERNEL_CFG_ACRE_ALM			FALSE				/* acre_alm */
#define _KERNEL_CFG_DEL_ALM 			FALSE				/* del_alm */
#define _KERNEL_CFG_STA_ALM 			FALSE				/* sta_alm */
#define _KERNEL_CFG_STP_ALM 			FALSE				/* stp_alm */
#define _KERNEL_CFG_REF_ALM 			FALSE				/* ref_alm */

/* Overrun handlers */				
#define _KERNEL_CFG_DEF_OVR 			FALSE				/* def_ovr */
#define _KERNEL_CFG_STA_OVR 			FALSE				/* sta_ovr */
#define _KERNEL_CFG_STP_OVR 			FALSE				/* stp_ovr */
#define _KERNEL_CFG_REF_OVR 			FALSE				/* ref_ovr */

/* System management functions */
#define _KERNEL_CFG_ROT_RDQ 			FALSE				/* rot_rdq */
#define _KERNEL_CFG_IROT_RDQ			FALSE				/* irot_rdq */
#define _KERNEL_CFG_GET_TID 			FALSE				/* get_tid */
#define _KERNEL_CFG_IGET_TID			FALSE				/* iget_tid */
#define _KERNEL_CFG_LOC_CPU 			FALSE				/* loc_cpu */
#define _KERNEL_CFG_ILOC_CPU			FALSE				/* iloc_cpu */
#define _KERNEL_CFG_UNL_CPU 			FALSE				/* unl_cpu */
#define _KERNEL_CFG_ILNL_CPU			FALSE				/* ilnl_cpu */
#define _KERNEL_CFG_DIS_DSP 			FALSE				/* dis_dsp */
#define _KERNEL_CFG_ENA_DSP 			FALSE				/* ena_dsp */
#define _KERNEL_CFG_SNS_CTX 			FALSE				/* sns_ctx */
#define _KERNEL_CFG_SNS_LOC 			FALSE				/* sns_loc */
#define _KERNEL_CFG_SNS_DSP 			FALSE				/* sns_dsp */
#define _KERNEL_CFG_SNS_DPN 			FALSE				/* sns_dpn */
#define _KERNEL_CFG_REF_SYS 			FALSE				/* ref_sys */

/* Interrupt management functions */
#define _KERNEL_CFG_DEF_INH 			TRUE				/* def_inh */
#define _KERNEL_CFG_CRE_ISR 			TRUE				/* cre_isr */
#define _KERNEL_CFG_ACRE_ISR			TRUE				/* acre_isr */
#define _KERNEL_CFG_DEL_ISR 			FALSE				/* del_isr */
#define _KERNEL_CFG_REF_ISR 			FALSE				/* ref_isr */
#define _KERNEL_CFG_DIS_INT 			FALSE				/* dis_int */
#define _KERNEL_CFG_ENA_INT 			FALSE				/* ena_int */
#define _KERNEL_CFG_CHG_ILV 			FALSE				/* chg_ilv */
#define _KERNEL_CFG_GET_ILV 			FALSE				/* get_ilv */

/* Service call management functions */				
#define _KERNEL_CFG_DEF_SVC 			FALSE				/* def_svc */
#define _KERNEL_CFG_CAL_SVC 			FALSE				/* cal_svc */

/* System configulation management functions */
#define _KERNEL_CFG_DEF_EXC				FALSE				/* def_exc */
#define _KERNEL_CFG_REF_CFG	 			FALSE				/* ref_cfg */
#define _KERNEL_CFG_REF_VER	 			FALSE				/* ref_ver */

/* Static API */
#define _KERNEL_CFG_SCRE_TSK			TRUE				/* CRE_TSK */
#define _KERNEL_CFG_SDEF_TEX			FALSE				/* DEF_TEX */
#define _KERNEL_CFG_SCRE_SEM			TRUE				/* CRE_SEM */
#define _KERNEL_CFG_SCRE_FLG			TRUE				/* CRE_FLG */
#define _KERNEL_CFG_SCRE_DTQ			FALSE				/* CRE_DTQ */
#define _KERNEL_CFG_SCRE_MBX			FALSE				/* CRE_MBX */
#define _KERNEL_CFG_SCRE_MTX			FALSE				/* CRE_MTX */
#define _KERNEL_CFG_SCRE_MBF			FALSE				/* CRE_MBF */
#define _KERNEL_CFG_SCRE_POR			FALSE				/* CRE_POR */
#define _KERNEL_CFG_SCRE_MPF			FALSE				/* CRE_MPF */
#define _KERNEL_CFG_SCRE_MPL			FALSE				/* CRE_MPL */
#define _KERNEL_CFG_SCRE_CYC			FALSE				/* CRE_CYC */
#define _KERNEL_CFG_SCRE_ALM			FALSE				/* CRE_ALM */
#define _KERNEL_CFG_SDEF_OVR			FALSE				/* DEF_OVR */
#define _KERNEL_CFG_SDEF_INH			FALSE				/* DEF_INH */
#define _KERNEL_CFG_SCRE_ISR			FALSE				/* CRE_ISR */
#define _KERNEL_CFG_SDEF_SVC			FALSE				/* DEF_SVC */
#define _KERNEL_CFG_SDEF_EXC			FALSE				/* DEF_EXC */
#define _KERNEL_CFG_SATT_INI			TRUE				/* ATT_INI */
#define _KERNEL_CFG_SINCLUDE			TRUE				/* INCLUDE */



#endif	/* _KERNEL__config__cfgknl_h__ */



/* end of file */
