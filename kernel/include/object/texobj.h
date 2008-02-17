/**
 *  Hyper Operating System V4 Advance
 *
 * @file  texobj.h
 * @brief %jp{タスク例外処理オジェクトのヘッダファイル}%en{Task Exception Handling Routine object heder file}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__texobj_h__
#define _KERNEL__object__texobj_h__



/* ------------------------------------------ */
/*  Primitive type definition                 */
/* ------------------------------------------ */


/* %jp{タスク例外処理ルーチン属性用の型} */
#if _KERNEL_TEXCB_BITFIELD		/* %jp{TEXCBにビットフィールドを利用する場合} */

/* %jp{TA_HLNG と TA_ASM の判定に 2bit 必要} */
typedef unsigned int					_KERNEL_TEX_T_TEXATR;
typedef unsigned int					_KERNEL_TEXCB_T_TEXATR;
#define _KERNEL_TEXCB_TBITDEF_TEXATR	: 2

#else							/* %jp{TEXCBにビットフィールドを利用しない場合} */

typedef _KERNEL_T_FAST_UB				_KERNEL_TEX_T_TEXATR;
typedef _KERNEL_T_LEAST_UB				_KERNEL_TEXCB_T_TEXATR;
#define _KERNEL_TEXCB_TBITDEF_TEXATR

#endif


/* %jp{タスク例外処理ルーチンの起動番地の型} */
typedef FP								_KERNEL_TEX_T_TEXRTN;
typedef FP								_KERNEL_TEXCB_T_TEXRTN;
#define _KERNEL_TEXCB_TBITDEF_TEXRTN


/* %jp{タスク例外処理禁止状態の型} */
#if _KERNEL_TEXCB_BITFIELD		/* %jp{TEXCBにビットフィールドを利用する場合} */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_LEAST_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TEX_T_STATE;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef signed int						_KERNEL_TEXCB_T_STATE;			/**< %jp{イベントフラグ属性をTEXCBに格納するときの型} */
#define _KERNEL_TEXCB_TBITDEF_STATE		: 1 + 1							/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TEX_T_STATE;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef unsigned int					_KERNEL_TEXCB_T_STATE;			/**< %jp{イベントフラグ属性をTEXCBに格納するときの型} */
#define _KERNEL_TEXCB_TBITDEF_STATE		: 1								/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TEXCBにビットフィールドを利用しない場合} */

#if _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TEX_T_STATE;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TEXCB_T_STATE;			/**< %jp{イベントフラグ属性をTEXCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UB				_KERNEL_TEX_T_STATE;			/**< %jp{イベントフラグ属性を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TEXCB_T_STATE;			/**< %jp{イベントフラグ属性をTEXCBに格納するときの型} */
#endif

#define _KERNEL_TEXCB_TBITDEF_STATE										/**< %jp{イベントフラグ属性のビットフィールド宣言時の幅} */

#endif


/* %jp{例外要因パターン用の型} */
#if _KERNEL_TEXCB_BITFIELD		/* %jp{TEXCBにビットフィールドを利用する場合} */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef signed int						_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#define _KERNEL_TEXCB_TBITDEF_TEXPTN	: _KERNEL_TEX_TBIT_TEXPTN + 1	/**< %jp{例外要因パターンのビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef unsigned int					_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#define _KERNEL_TEXCB_TBITDEF_TEXPTN	: _KERNEL_TEX_TBIT_TEXPTN		/**< %jp{例外要因パターンのビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TEXCBにビットフィールドを利用しない場合} */

#if _KERNEL_TEX_TBIT_TEXPTN <= 7 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 8 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 15 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 16 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 31 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 32 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 63 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TEX_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TEXCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#endif

#define _KERNEL_TEXCB_TBITDEF_TEXPTN									/**< %jp{例外要因パターンのビットフィールド宣言時の幅} */

#endif



/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

#if _KERNEL_TEXCB_SPLIT_RO


/** %jp{タスク例外処理ルーチンコントロールブロック(リードオンリー部)}%en{Task Exception Handling Routine Control Block(read-only)} */
typedef struct _kernel_t_texcb_ro
{
#if _KERNEL_TEXCB_TEXATR
	_KERNEL_TEXCB_T_TEXATR	texatr		_KERNEL_TEXCB_TBITDEF_TEXATR;		/**< %jp{タスク例外処理ルーチン属性} */
#endif

#if _KERNEL_TEXCB_TEXRTN
	_KERNEL_TEXCB_T_TEXRTN	texrtn		_KERNEL_TEXCB_TBITDEF_TEXRTN;		/**< %jp{タスク例外処理ルーチンの起動番地} */
#endif
} _KERNEL_T_TEXCB_RO;

typedef const _KERNEL_T_TEXCB_RO	*_KERNEL_T_TEXCB_RO_PTR;


/** %jp{タスク例外処理ルーチンコントロールブロック}%en{Task Exception Handling Routine Control Block} */
typedef struct _kernel_t_texcb
{
#if _KERNEL_TEXCB_STATE
	_KERNEL_TEXCB_T_STATE	state		_KERNEL_TEXCB_TBITDEF_STATE;		/**< %jp{タスク例外処理禁止状態} */
#endif

#if _KERNEL_TEXCB_RASPTN
	_KERNEL_TEXCB_T_TEXPTN	rasptn		_KERNEL_TEXCB_TBITDEF_TEXPTN;		/**< %jp{タスク例外処理要因} */
#endif

#if _KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_PTRARRAY
	_KERNEL_T_TEXCB_RO_PTR	texcb_ro;										/**< %jp{タスク例外処理ルーチンコントロールブロックRO部へのポインタ} */
#endif
} _KERNEL_T_TEXCB;

typedef _KERNEL_T_TEXCB				*_KERNEL_T_TEXCB_PTR;


#else


/** %jp{タスク例外処理ルーチンコントロールブロック}%en{Task Exception Handling Routine Control Block} */
typedef struct _kernel_t_texcb
{
#if _KERNEL_TEXCB_STATE
	_KERNEL_TEXCB_T_STATE	state		_KERNEL_TEXCB_TBITDEF_STATE;		/**< %jp{タスク例外処理禁止状態} */
#endif

#if _KERNEL_TEXCB_RASPTN
	_KERNEL_TEXCB_T_TEXPTN	rasptn		_KERNEL_TEXCB_TBITDEF_TEXPTN;		/**< %jp{タスク例外処理要因} */
#endif


#if _KERNEL_TEXCB_TEXATR
	_KERNEL_TEXCB_T_TEXATR	texatr		_KERNEL_TEXCB_TBITDEF_TEXATR;		/**< %jp{タスク例外処理ルーチン属性} */
#endif

#if _KERNEL_TEXCB_TEXRTN
	_KERNEL_TEXCB_T_TEXRTN	texrtn		_KERNEL_TEXCB_TBITDEF_TEXRTN;		/**< %jp{タスク例外処理ルーチンの起動番地} */
#endif
} _KERNEL_T_TEXCB;

typedef _KERNEL_T_TEXCB				_KERNEL_T_TEXCB_RO;
typedef const _KERNEL_T_TEXCB_RO	*_KERNEL_T_TEXCB_RO_PTR;
typedef _KERNEL_T_TEXCB				*_KERNEL_T_TEXCB_PTR;


#endif



/* ------------------------------------------ */
/*  ID range                                  */
/* ------------------------------------------ */

#define _KERNEL_TEX_TMIN_ID				_KERNEL_TSK_TMIN_ID					/**< %jp{タスク例外処理ルーチンの最小値} */
#define _KERNEL_TEX_TMAX_ID				_KERNEL_TSK_TMAX_ID					/**< %jp{タスク例外処理ルーチンの最大値} */

#define _KERNEL_TEX_CHECK_TSKID(tskid)	((tskid) >= _KERNEL_TEX_TMIN_ID && (tskid) <= _KERNEL_TEX_TMAX_ID)
																			/**< %jp{ID範囲チェック} */


/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */

#if _KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_BLKARRAY
#if _KERNEL_TEXCB_SPLIT_RO

/* %jp{ブロック配列管理でRO分離の場合}%en{block array} */
extern  _KERNEL_T_TEXCB					_kernel_texcb_tbl[];									/**< %jp{タスク例外処理ルーチンコントロールブロックテーブル} */
extern const _KERNEL_T_TEXCB_RO			_kernel_texcb_ro_tbl[];									/**< %jp{タスク例外処理ルーチンコントロールブロック(リードオンリー部)テーブル} */
#define _KERNEL_TEX_ID2TEXCB(tskid)		(&_kernel_texcb_tbl[(tskid) - _KERNEL_TEX_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_TEX_CHECK_EXS(tskid)	(_kernel_texcb_ro_tbl[(tskid) - _KERNEL_TEX_TMIN_ID].texrtn != NULL )
																								/**< %jp{オブジェクトの存在チェック} */

#else

/* %jp{ブロック配列管理の場合}%en{block array} */
extern  _KERNEL_T_TEXCB					_kernel_texcb_tbl[];									/**< %jp{タスク例外処理ルーチンコントロールブロックテーブル} */
#define _KERNEL_TEX_ID2TEXCB(tskid)		(&_kernel_texcb_tbl[(tskid) - _KERNEL_TEX_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_TEX_CHECK_EXS(tskid)	(_kernel_texcb_tbl[(tskid) - _KERNEL_TEX_TMIN_ID].texrtn != NULL )			
																								/**< %jp{オブジェクトの存在チェック} */

#endif

#elif _KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_PTRARRAY

/* %jp{ポインタ配列管理の場合}%en{pointer array} */
extern  _KERNEL_T_TEXCB					*_kernel_texcb_tbl[];									/**< %jp{タスク例外処理ルーチンコントロールブロックテーブル} */
#define _KERNEL_TEX_ID2TEXCB(tskid)		(_kernel_texcb_tbl[(tskid) - _KERNEL_TEX_TMIN_ID])		/**< %jp{タスクIDからTEXCB アドレスを取得} */
#define _KERNEL_TEX_CHECK_EXS(tskid)	(_KERNEL_TEX_ID2TEXCB(tskid) != NULL)					/**< %jp{オブジェクトの存在チェック} */

#endif



/* ------------------------------------------ */
/*   Accessor for TEXCB                       */
/* ------------------------------------------ */

/* texcb_ro */
#if !_KERNEL_TEXCB_SPLIT_RO								
#define _KERNEL_TEX_GET_TEXCB_RO(tskid, texcb)	(texcb)
#else
#if _KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_BLKARRAY		/* %jp{TEXCBを単純配列で管理}%en{array of block} */
#define _KERNEL_TEX_GET_TEXCB_RO(tskid, texcb)	(&_kernel_texcb_ro_tbl[(tskid)])
#elif _KERNEL_TEXCB_ALGORITHM == _KERNEL_TEXCB_ALG_PTRARRAY		/* %jp{TEXCBをポインタ配列で管理}%en{array of pointer} */
#define _KERNEL_TEX_GET_TEXCB_RO(tskid, texcb)	((texcb)->texcb_ro)
#endif
#endif


/* texatr */
#if _KERNEL_TEXCB_STATE
#define _KERNEL_TEX_SET_STATE(texcb, x)			do { (texcb)->state = (_KERNEL_TEXCB_T_STATE)(x); } while (0)
#define _KERNEL_TEX_GET_STATE(texcb)			((_KERNEL_TEX_T_STATE)(texcb)->state)
#else
#define _KERNEL_TEX_SET_STATE(texcb, x)			do { } while (0)
#define _KERNEL_TEX_GET_STATE(texcb)			(0)
#endif


/* rasptn */
#if _KERNEL_TEXCB_TEXPTN
#define _KERNEL_TEX_SET_RASPTN(texcb, x)		do { (texcb)->rasptn = (_KERNEL_TEXCB_T_TEXPTN)(x); } while (0)
#define _KERNEL_TEX_GET_RASPTN(texcb)			((_KERNEL_TEX_T_TEXPTN)(texcb)->rasptn)
#else
#define _KERNEL_TEX_SET_RASPTN(texcb, x)		do { } while (0)
#define _KERNEL_TEX_GET_RASPTN(texcb)			(0)
#endif


/* texatr */
#if _KERNEL_TEXCB_TEXATR
#define _KERNEL_TEX_SET_TEXATR(texcb_ro, x)		do { (texcb_ro)->texatr = (_KERNEL_TEXCB_T_TEXATR)(x); } while (0)
#define _KERNEL_TEX_GET_TEXATR(texcb_ro)		((_KERNEL_TEX_T_TEXATR)(texcb_ro)->texatr)
#else
#define _KERNEL_TEX_SET_TEXATR(texcb_ro, x)		do { } while (0)
#define _KERNEL_TEX_GET_TEXATR(texcb_ro)		(_KERNEL_TMAX_TEXATR)
#endif

/* texrtn */
#if _KERNEL_TEXCB_TEXRTN
#define _KERNEL_TEX_SET_TEXRTN(texcb_ro, x)		do { (texcb_ro)->texrtn = (_KERNEL_TEXCB_T_TEXRTN)(x); } while (0)
#define _KERNEL_TEX_GET_TEXRTN(texcb_ro)		((_KERNEL_TEX_T_TEXRTN)(texcb_ro)->texrtn)
#else
#define _KERNEL_TEX_SET_TEXRTN(texcb_ro, x)		do { } while (0)
#define _KERNEL_TEX_GET_TEXRTN(texcb_ro)		(0)
#endif



/* ------------------------------------------ */
/*   Macro functions                          */
/* ------------------------------------------ */



/* ------------------------------------------ */
/*   Functions                                */
/* ------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__texobj_h__ */


/* end of file */
