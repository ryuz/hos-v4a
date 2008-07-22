/**
 *  Hyper Operating System V4 Advance
 *
 * @file  flgobj.h
 * @brief %jp{イベントフラグオジェクトのヘッダファイル}%en{Eventflag object heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__flgobj_h__
#define _KERNEL__object__flgobj_h__



/* ------------------------------------------ */
/*  type definition                           */
/* ------------------------------------------ */

/* %jp{フラグパターン用の型} */
#if _KERNEL_FLGCB_BITFIELD		/* %jp{FLGCBにビットフィールドを利用する場合} */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef signed int						_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#define _KERNEL_FLGCB_TBITDEF_FLGPTN	: _KERNEL_FLG_TBIT_FLGPTN + 1	/**< %jp{フラグパターンのビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef unsigned int					_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#define _KERNEL_FLGCB_TBITDEF_FLGPTN	: _KERNEL_FLG_TBIT_FLGPTN		/**< %jp{フラグパターンのビットフィールド宣言時の幅} */
#endif

#else							/* %jp{FLGCBにビットフィールドを利用しない場合} */

#if _KERNEL_FLG_TBIT_FLGPTN <= 7 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 8 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 15 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 16 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 31 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 32 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 63 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#endif

#define _KERNEL_FLGCB_TBITDEF_FLGPTN									/**< %jp{フラグパターンのビットフィールド宣言時の幅} */

#endif


/* %jp{イベントフラグ属性用の型(4bit必要)} */
#if _KERNEL_FLGCB_BITFIELD		/* %jp{FLGCBにビットフィールドを利用する場合} */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_LEAST_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_FLG_T_FLGATR;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef signed int						_KERNEL_FLGCB_T_FLGATR;			/**< %jp{イベントフラグ属性をFLGCBに格納するときの型} */
#define _KERNEL_FLGCB_TBITDEF_FLGATR	: 4 + 1							/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_FLG_T_FLGATR;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef unsigned int					_KERNEL_FLGCB_T_FLGATR;			/**< %jp{イベントフラグ属性をFLGCBに格納するときの型} */
#define _KERNEL_FLGCB_TBITDEF_FLGATR	: 4								/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{FLGCBにビットフィールドを利用しない場合} */

#if _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_FLG_T_FLGATR;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_FLGCB_T_FLGATR;			/**< %jp{イベントフラグ属性をFLGCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UB				_KERNEL_FLG_T_FLGATR;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_FLGCB_T_FLGATR;			/**< %jp{イベントフラグ属性をFLGCBに格納するときの型} */
#endif

#define _KERNEL_FLGCB_TBITDEF_FLGATR									/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */

#endif


/** %jp{待ちフラグ情報構造体} */
typedef struct _kernel_t_flginf
{
	MODE   wfmode;		/**< %jp{待ちモード} */
	FLGPTN waiptn;		/**< %jp{待ちビットパターン（解除時パターンと兼用)} */
} _KERNEL_T_FLGINF;



/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

#if _KERNEL_FLGCB_SPLIT_RO


/** %jp{イベントフラグコントロールブロック(リードオンリー部)}%en{Eventflag Control Block(read-only)} */
typedef struct _kernel_t_flgcb_ro
{
#if _KERNEL_FLGCB_FLGATR
	_KERNEL_FLGCB_T_FLGATR	flgatr		_KERNEL_FLGCB_TBITDEF_FLGPTN;		/**< %jp{イベントフラグ属性} */
#endif
} _KERNEL_FLGCB_T_RO;

/** %jp{イベントフラグコントロールブロック}%en{Eventflag Control Block} */
typedef struct _kernel_t_flgcb
{
#if _KERNEL_FLGCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{タスクの待ち行列} */
#endif

#if _KERNEL_FLGCB_FLGPTN
	_KERNEL_FLGCB_T_FLGPTN	flgptn		_KERNEL_FLGCB_TBITDEF_FLGPTN;		/**< %jp{イベントフラグのビットパターン} */
#endif
} _KERNEL_T_FLGCB;


#else


/** %jp{イベントフラグコントロールブロック} */
typedef struct _kernel_t_flgcb
{
#if _KERNEL_FLGCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{タスクの待ち行列} */
#endif

#if _KERNEL_FLGCB_FLGPTN
	_KERNEL_FLGCB_T_FLGPTN	flgptn		_KERNEL_FLGCB_TBITDEF_FLGPTN;		/**< %jp{イベントフラグのビットパターン} */
#endif

#if _KERNEL_FLGCB_FLGATR
	_KERNEL_FLGCB_T_FLGATR	flgatr		_KERNEL_FLGCB_TBITDEF_FLGPTN;		/**< %jp{イベントフラグ属性} */
#endif
} _KERNEL_T_FLGCB;

typedef _KERNEL_T_FLGCB		_KERNEL_T_FLGCB_RO;


#endif



/* ------------------------------------------ */
/*  ID range                                  */
/* ------------------------------------------ */

extern const ID							_kernel_max_flgid;										/**< %jp{イベントフラグIDの最大値} */

#define _KERNEL_FLG_TMIN_ID				1														/**< %jp{イベントフラグIDの最小値} */
#define _KERNEL_FLG_TMAX_ID				(_kernel_max_flgid)										/**< %jp{イベントフラグIDの最大値} */

#define _KERNEL_FLG_CHECK_FLGID(flgid)	((flgid) >= _KERNEL_FLG_TMIN_ID && (flgid) <= _KERNEL_FLG_TMAX_ID)



/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */


#if _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_BLKARRAY
#if _KERNEL_FLGCB_SPLIT_RO

/* %jp{ブロック配列管理でRO分離の場合}%en{block array} */
extern  _KERNEL_T_FLGCB					_kernel_flgcb_tbl[];									/**< %jp{イベントフラグコントロールブロックテーブル} */
extern const _KERNEL_T_FLGCB_RO			_kernel_flgcb_ro_tbl[];									/**< %jp{イベントフラグコントロールブロック(リードオンリー部)テーブル} */
#define _KERNEL_FLG_ID2FLGCB(flgid)		(&_kernel_flgcb_tbl[(flgid) - _KERNEL_FLG_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_FLG_CHECK_EXS(flgid)	(_kernel_flgcb_ro_tbl[(flgid) - _KERNEL_FLG_TMIN_ID].flgatr & _KERNEL_FLG_TA_CRE)
																								/**< %jp{オブジェクトの存在チェック} */
#define _KERNEL_FLG_TA_CRE				0x08													/**< %jp{flgatrのビットに生成済みbitを割り当て} */

#else

/* %jp{ブロック配列管理の場合}%en{block array} */
extern  _KERNEL_T_FLGCB					_kernel_flgcb_tbl[];									/**< %jp{イベントフラグコントロールブロックテーブル} */
#define _KERNEL_FLG_ID2FLGCB(flgid)		(&_kernel_flgcb_tbl[(flgid) - _KERNEL_FLG_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_FLG_CHECK_EXS(flgid)	(_kernel_flgcb_tbl[(flgid) - _KERNEL_FLG_TMIN_ID].flgatr & _KERNEL_FLG_TA_CRE)
																								/**< %jp{オブジェクトの存在チェック} */
#define _KERNEL_FLG_TA_CRE				0x08													/**< %jp{flgatrのビットに生成済みbitを割り当て} */

#endif

#elif _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_PTRARRAY

/* %jp{ポインタ配列管理の場合}%en{pointer array} */
extern  _KERNEL_T_FLGCB					*_kernel_flgcb_tbl[];									/**< %jp{イベントフラグコントロールブロックテーブル} */
#define _KERNEL_FLG_ID2FLGCB(flgid)		(_kernel_flgcb_tbl[(flgid) - _KERNEL_FLG_TMIN_ID])		/**< %jp{イベントフラグIDからFLGCB アドレスを取得} */
#define _KERNEL_FLG_CHECK_EXS(flgid)	(_KERNEL_FLG_ID2FLGCB(flgid) != NULL)					/**< %jp{オブジェクトの存在チェック} */
#define _KERNEL_FLG_TA_CRE				0

#endif



/* ------------------------------------------ */
/*   Accessor for FLGCB                       */
/* ------------------------------------------ */

/* flgcb_ro */
#if !_KERNEL_FLGCB_SPLIT_RO								
#define _KERNEL_FLG_GET_FLGCB_RO(flgid, flgcb)	(flgcb)
#else
#if _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_BLKARRAY		/* %jp{FLGCBを単純配列で管理}%en{array of block} */
#define _KERNEL_FLG_GET_FLGCB_RO(flgid, flgcb)	(&_kernel_flgcb_ro_tbl[(flgid)])
#elif _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_PTRARRAY		/* %jp{FLGCBをポインタ配列で管理}%en{array of pointer} */
#define _KERNEL_FLG_GET_FLGCB_RO(flgid, flgcb)	((flgcb)->flgcb_ro)
#endif
#endif


/* que */
#define _KERNEL_FLG_GET_QUE(flgcb)				(&(flgcb)->que)

/* flgptn */
#if _KERNEL_FLGCB_FLGPTN
#define _KERNEL_FLG_SET_FLGPTN(flgcb, x)		do { (flgcb)->flgptn = (_KERNEL_FLGCB_T_FLGPTN)(x); } while (0)
#define _KERNEL_FLG_GET_FLGPTN(flgcb)			((_KERNEL_FLG_T_FLGPTN)(flgcb)->flgptn)
#else
#define _KERNEL_FLG_SET_FLGPTN(flgcb, x)		do { } while (0)
#define _KERNEL_FLG_GET_FLGPTN(flgcb)			(0)
#endif

/* flgatr */
#if _KERNEL_FLGCB_FLGATR
#define _KERNEL_FLG_SET_FLGATR(flgcb_ro, x)		do { (flgcb_ro)->flgatr = (_KERNEL_FLGCB_T_FLGATR)(x); } while (0)
#define _KERNEL_FLG_GET_FLGATR(flgcb_ro)		((_KERNEL_FLG_T_FLGATR)(flgcb_ro)->flgatr)
#else
#define _KERNEL_FLG_SET_FLGATR(flgcb_ro, x)		do { } while (0)
#if _KERNEL_SPT_FLG_TA_TFIFO
#define _KERNEL_FLG_GET_FLGATR(flgcb_ro)		(TA_TFIFO)
#else
#define _KERNEL_FLG_GET_FLGATR(flgcb_ro)		(TA_TPRI)
#endif
#endif



/* ------------------------------------------ */
/*   Macro functions                          */
/* ------------------------------------------ */

/* %jp{キュー接続} */
#if _KERNEL_SPT_FLG_TA_TFIFO && _KERNEL_SPT_FLG_TA_TPRI		/* %jp{TA_TFIFO と TA_TPRI の混在 } */
#define _KERNEL_FLG_ADD_QUE(flgcb, flgcb_ro, tskhdl)	_KERNEL_ADD_QUE(_KERNEL_FLG_GET_QUE(flgcb), tskhdl, _KERNEL_FLG_GET_FLGATR(flgcb_ro))
#elif _KERNEL_SPT_FLG_TA_TFIFO && !_KERNEL_SPT_SE_TA_TPRI	/* %jp{TA_TFIFO のみ利用 } */
#define _KERNEL_FLG_ADD_QUE(flgcb, flgcb_ro, tskhdl)	_KERNEL_ADF_QUE(_KERNEL_FLG_GET_QUE(flgcb), tskhdl)
#elif !_KERNEL_SPT_FLG_TA_TFIFO && _KERNEL_SPT_FLG_TA_TPRI	/* %jp{TA_TPRI のみ利用 } */
#define _KERNEL_FLG_ADD_QUE(flgcb, flgcb_ro, tskhdl)	_KERNEL_ADP_QUE(_KERNEL_FLG_GET_QUE(flgcb), tskhdl)
#else
#error error:_KERNEL_SPT_FLG_TA_TPRI and _KERNEL_SPT_FLG_TA_TFIFO
#endif

/* %jp{キュー取り外し} */
#define _KERNEL_FLG_RMV_QUE(flgcb, tskhdl)	_KERNEL_RMV_QUE(_KERNEL_FLG_GET_QUE(flgcb), tskhdl)

/* %jp{キュー先頭取り出し} */
#define _KERNEL_FLG_RMH_QUE(flgcb)			_KERNEL_RMH_QUE(_KERNEL_FLG_GET_QUE(flgcb))

/* %jp{タイムアウトキュー接続} */
#if _KERNEL_SPT_TWAI_FLG	/* %jp{twai_semサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_FLG_ADD_TOQ(tskhdl, tmout)	_KERNEL_SYS_ADD_TOQ(tskhdl, tmout)
#else
#define _KERNEL_FLG_ADD_TOQ(tskhdl)			do { } while (0)
#endif

/* %jp{タイムアウトキュー解除} */
#if _KERNEL_SPT_TWAI_FLG	/* %jp{twai_flgサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_FLG_RMV_TOQ(tskhdl)			_KERNEL_SYS_RMV_TOQ(tskhdl)
#else
#define _KERNEL_FLG_RMV_TOQ(tskhdl)			do { } while (0)
#endif



/* ------------------------------------------ */
/*   Functions                                */
/* ------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

ER   _kernel_cre_flg(ID flgid, const T_CFLG *pk_cflg);
ER   _kernel_wai_flg(ID flgid, FLGPTN waiptn, MODE wfmode, FLGPTN *p_flgptn, TMO tmout);
BOOL _kernel_chk_flg(_KERNEL_T_FLGCB *flgcb, _KERNEL_T_FLGINF *pk_flginf);

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__flgobj_h__ */



/* end of file */
