/**
 *  Hyper Operating System V4 Advance
 *
 * @file  flgobj.h
 * @brief %jp{イベントフラグオジェクトのヘッダファイル}%en{Eventflag object heder file}
 *
 * @version $Id: flgobj.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
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
#if _KERNEL_FLGCB_BITFIELD		/* %jp{FLGCBにビットフィールドを利用する場合 */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef signed int						_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#define _KERNEL_FLGCB_TBITDEF_FLGPTN	: _KERNEL_FLGCB_TBIT_FLGPTN + 1	/**< %jp{フラグパターンのビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef unsigned int					_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#define _KERNEL_FLGCB_TBITDEF_FLGPTN	: _KERNEL_FLGCB_TBIT_FLGPTN		/**< %jp{フラグパターンのビットフィールド宣言時の幅} */
#endif

#else							/* %jp{FLGCBにビットフィールドを利用しない場合 */

#if _KERNEL_FLG_TBIT_FLGPTN <= 7 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_OPT_B					_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 8 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_OPT_UB				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 15 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_OPT_H					_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 16 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_OPT_UH				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 31 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_OPT_W					_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 32 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_OPT_UW				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#elif _KERNEL_FLG_TBIT_FLGPTN <= 63 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_OPT_D					_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_FLG_T_FLGPTN;			/**< %jp{フラグパターンを演算操作するときの型} */
typedef _KERNEL_T_OPT_UD				_KERNEL_FLGCB_T_FLGPTN;			/**< %jp{フラグパターンをFLGCBに格納するときの型} */
#endif

#define _KERNEL_FLGCB_TBITDEF_FLGPTN									/**< %jp{フラグパターンのビットフィールド宣言時の幅} */

#endif


/* %jp{イベントフラグ属性用の型(4bit必要)} */
#if _KERNEL_FLGCB_BITFIELD		/* %jp{FLGCBにビットフィールドを利用する場合 */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_FLG_T_FLGATR;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef signed int						_KERNEL_FLGCB_T_FLGATR;			/**< %jp{イベントフラグ属性をFLGCBに格納するときの型} */
#define _KERNEL_FLGCB_TBITDEF_FLGATR	: 4 + 1							/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_FLG_T_FLGATR;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef unsigned int					_KERNEL_FLGCB_T_FLGATR;			/**< %jp{イベントフラグ属性をFLGCBに格納するときの型} */
#define _KERNEL_FLGCB_TBITDEF_FLGATR	: 4								/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{FLGCBにビットフィールドを利用しない場合 */

#if _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_FLG_T_FLGATR;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef _KERNEL_T_OPT_B					_KERNEL_FLGCB_T_FLGATR;			/**< %jp{イベントフラグ属性をFLGCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UB				_KERNEL_FLG_T_FLGATR;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef _KERNEL_T_OPT_UB				_KERNEL_FLGCB_T_FLGATR;			/**< %jp{イベントフラグ属性をFLGCBに格納するときの型} */
#endif

#define _KERNEL_FLGCB_TBITDEF_FLGATR									/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */

#endif



/* ------------------------------------------ */
/*  Eventflag control block                   */
/* ------------------------------------------ */

#if _KERNEL_FLGCB_ROM

/** %jp{イベントフラグコントロールブロック(ROM部)} */
typedef struct _kernel_t_flgcb_rom
{
#if _KERNEL_FLGCB_FLGATR
	_KERNEL_FLGCB_T_FLGATR	flgatr		_KERNEL_FLGCB_TBITDEF_FLGPTN;		/**< %jp{イベントフラグ属性} */
#endif
} _KERNEL_FLGCB_T_ROM;


/** %jp{イベントフラグコントロールブロック(RAM部)} */
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

#endif


/** %jp{待ちフラグ情報構造体} */
typedef struct _kernel_t_flginf
{
	MODE   wfmode;		/**< %jp{待ちモード} */
	FLGPTN waiptn;		/**< %jp{待ちビットパターン（解除時パターンと兼用)} */
} _KERNEL_T_FLGINF;


/* Eventflag handle */
typedef _KERNEL_T_FLGCB*				_KERNEL_T_FLGHDL;



#if _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_BLKARRAY			/* block array */

extern const ID							_kernel_max_flgid;					/** %jp{イベントフラグコントロールブロック個数} */
extern       _KERNEL_T_FLGCB			_kernel_flgcb_tbl[];				/** %jp{イベントフラグコントロールブロックテーブル} */

#define _KERNEL_FLG_ID2FLGCB(flgid)		(&_kernel_flgcb_tbl[(flgid) - _KERNEL_TMIN_FLG_ID])
#define _KERNEL_FLG_ID2FLGHDL(flgid)	_KERNEL_FLG_ID2FLGCB(flgid)


/* %jp{オブジェクトの存在チェック} */
#define _KERNEL_FLG_CHECK_EXS(flgid)	(_KERNEL_FLG_ID2FLGCB(flgid)->flgatr & _KERNEL_FLG_TA_CRE)
#define _KERNEL_FLG_TA_CRE				0x08


#elif _KERNEL_FLGCB_ALGORITHM == _KERNEL_FLGCB_ALG_PTRARRAY		/* pointer array */

extern const ID					_kernel_max_flgid;					/** %jp{イベントフラグコントロールブロック個数} */
extern       _KERNEL_T_FLGCB	*_kernel_flgcb_tbl[];				/** %jp{イベントフラグコントロールブロックテーブル} */

#define _KERNEL_FLG_ID2FLGCB(flgid)		(_kernel_flgcb_tbl[(flgid) - _KERNEL_TMIN_FLG_ID])
#define _KERNEL_FLG_ID2FLGHDL(flgid)	_KERNEL_FLG_ID2FLGCB(flgid)
																	/** %jp{イベントフラグIDからFLGCB アドレスを取得} */

/* %jp{オブジェクトの存在チェック} */
#define _KERNEL_FLG_CHECK_EXS(flgid)	(_KERNEL_FLG_ID2FLGCB(flgid) != NULL)
#define _KERNEL_FLG_TA_CRE				0

#endif


/* %jp{ID範囲定義} */
#define _KERNEL_TMIN_FLG_ID				1
#define _KERNEL_TMAX_FLG_ID				(_kernel_max_flgid)


/* %jp{ID範囲チェック} */
#define _KERNEL_FLG_CHECK_FLGID(flgid)	((flgid) >= _KERNEL_TMIN_FLG_ID && (flgid) <= _KERNEL_TMAX_FLG_ID)




/* ------------------------------------------ */
/*   Accessor for FLGCB                       */
/* ------------------------------------------ */

/* que */
#define _KERNEL_FLG_GET_QUE(flghdl)			(&(flghdl)->que)

/* flgptn */
#if _KERNEL_FLGCB_FLGPTN
#define _KERNEL_FLG_SET_FLGPTN(flghdl, x)	do { (flghdl)->flgptn = (_KERNEL_FLGCB_T_FLGPTN)(x); } while (0)
#define _KERNEL_FLG_GET_FLGPTN(flghdl)		((_KERNEL_FLG_T_FLGPTN)(flghdl)->flgptn)
#else
#define _KERNEL_FLG_SET_FLGPTN(flghdl, x)	do { } while (0)
#define _KERNEL_FLG_GET_FLGPTN(flghdl)		(0)
#endif

/* flgatr */
#if _KERNEL_FLGCB_FLGATR
#define _KERNEL_FLG_SET_FLGATR(flghdl, x)	do { (flghdl)->flgatr = (_KERNEL_FLGCB_T_FLGATR)(x); } while (0)
#define _KERNEL_FLG_GET_FLGATR(flghdl)		((_KERNEL_FLG_T_FLGATR)(flghdl)->flgatr)
#else
#define _KERNEL_FLG_SET_FLGATR(flghdl, x)	do { } while (0)
#if _KERNEL_SPT_FLG_TA_TFIFO
#define _KERNEL_FLG_GET_FLGATR(flghdl)		(TA_TFIFO)
#else
#define _KERNEL_FLG_GET_FLGATR(flghdl)		(TA_TPRI)
#endif
#endif


/* %jp{キュー接続} */
#if _KERNEL_SPT_FLG_TA_TFIFO && _KERNEL_SPT_FLG_TA_TPRI		/* %jp{TA_TFIFO と TA_TPRI の混在 } */
#define _KERNEL_FLG_ADD_QUE(flghdl, tskhdl)		_kernel_add_que(_KERNEL_FLG_GET_QUE(flghdl), tskhdl, _KERNEL_FLG_GET_FLGATR(flghdl))
#elif _KERNEL_SPT_FLG_TA_TFIFO && !_KERNEL_SPT_FLG_TA_TPRI	/* %jp{TA_TFIFO のみ利用 } */
#define _KERNEL_FLG_ADD_QUE(flghdl, tskhdl)		_kernel_adf_que(_KERNEL_FLG_GET_QUE(flghdl), tskhdl)
#elif !_KERNEL_SPT_FLG_TA_TFIFO && _KERNEL_SPT_FLG_TA_TPRI	/* %jp{TA_TPRI のみ利用 } */
#define _KERNEL_FLG_ADD_QUE(flghdl, tskhdl)		_kernel_adp_que(_KERNEL_FLG_GET_QUE(flghdl), tskhdl)
#else
#error error:_KERNEL_SPT_FLG_TA_TPRI and _KERNEL_SPT_FLG_TA_TFIFO
#endif

/* %jp{タイムアウトキュー解除} */
#if _KERNEL_SPT_TWAI_FLG	/* %jp{twai_semサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_FLG_RMV_TOQ(tskhdl)			_KERNEL_RMV_TOQ(tskhdl)
#else
#define _KERNEL_FLG_RMV_TOQ(tskhdl)			do { } while (0)
#endif



#ifdef __cplusplus
extern "C" {
#endif

ER   _kernel_cre_flg(ID flgid, const T_CFLG *pk_cflg);
BOOL _kernel_chk_flg(_KERNEL_T_FLGHDL flghdl, _KERNEL_T_FLGINF *pk_flginf);

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__flgobj_h__ */



/* end of file */
