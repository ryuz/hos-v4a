/**
 *  Hyper Operating System V4 Advance
 *
 * @file  cycobj.h
 * @brief %jp{周期ハンドラオジェクトのヘッダファイル}%en{Cyclic Handler object heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__cycobj_h__
#define _KERNEL__object__cycobj_h__

#include "core/tmq.h"


/* ------------------------------------------ */
/*  Primitive type definition                 */
/* ------------------------------------------ */

/* %jp{周期ハンドラ属性用の型} */
#if _KERNEL_CYCCB_BITFIELD		/* %jp{CYCCBにビットフィールドを利用する場合} */

typedef unsigned int					_KERNEL_CYC_T_CYCATR;
typedef unsigned int					_KERNEL_CYCCB_T_CYCATR;
#define _KERNEL_CYCCB_TBITDEF_CYCATR	: 3

#else							/* %jp{CYCCBにビットフィールドを利用しない場合} */

typedef _KERNEL_T_FAST_UB				_KERNEL_CYC_T_CYCATR;
typedef _KERNEL_T_LEAST_UB				_KERNEL_CYCCB_T_CYCATR;
#define _KERNEL_CYCCB_TBITDEF_CYCATR

#endif

typedef RELTIM							_KERNEL_CYC_T_RELTIM;
typedef RELTIM							_KERNEL_CYCCB_T_RELTIM;
#define _KERNEL_CYCCB_TBITDEF_RELTIM

typedef VP_INT							_KERNEL_CYC_T_EXINF;
typedef VP_INT							_KERNEL_CYCCB_T_EXINF;
#define _KERNEL_CYCCB_TBITDEF_EXINF

typedef void (*_KERNEL_CYC_T_CYCHDR)(VP_INT exinf);
typedef void (*_KERNEL_CYCCB_T_CYCHDR)(VP_INT exinf);
#define _KERNEL_CYCCB_TBITDEF_CYCHDR



/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

#if _KERNEL_CYCCB_SPLIT_RO


/** %jp{周期ハンドラコントロールブロック(リードオンリー部)}%en{Cyclic Handler Control Block(read-only)} */
typedef struct _kernel_t_cyccb_ro
{
#if _KERNEL_CYCCB_CYCATR
	_KERNEL_CYCCB_T_CYCATR	cycatr		_KERNEL_CYCCB_TBITDEF_CYCATR;		/**< %jp{周期ハンドラ属性} */
#endif

#if _KERNEL_CYCCB_EXINF
	_KERNEL_CYCCB_T_EXINF	exinf		_KERNEL_CYCCB_TBITDEF_EXINF;		/**< %jp{周期ハンドラの拡張情報} */
#endif

#if _KERNEL_CYCCB_CYCHDR
	_KERNEL_CYCCB_T_CYCHDR	cychdr		_KERNEL_CYCCB_TBITDEF_CYCHDR;		/**< %jp{周期ハンドラの起動周期} */
#endif

#if _KERNEL_CYCCB_CYCTIM
	_KERNEL_CYCCB_T_RELTIM	cyctim		_KERNEL_CYCCB_TBITDEF_RELTIM;		/**< %jp{周期ハンドラの起動周期} */
#endif

#if _KERNEL_CYCCB_CYCPHS
	_KERNEL_CYCCB_T_RELTIM	cycphs		_KERNEL_CYCCB_TBITDEF_RELTIM;		/**< %jp{周期ハンドラの起動位相} */
#endif
} _KERNEL_T_CYCCB_RO;

typedef const _KERNEL_T_CYCCB_RO	*_KERNEL_T_CYCCB_RO_PTR;


/** %jp{周期ハンドラコントロールブロック}%en{Cyclic Handler Control Block} */
typedef struct _kernel_t_cyccb
{
#if _KERNEL_CYCCB_TIMOBJ
	_KERNEL_T_TIMOBJ		timobj;											/**< %jp{タイマオブジェクトを継承} */
#endif


#if _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_PTRARRAY
	_KERNEL_T_CYCCB_RO_PTR	cyccb_ro;										/**< %jp{周期ハンドラコントロールブロックRO部へのポインタ} */
#endif
} _KERNEL_T_CYCCB;

typedef _KERNEL_T_CYCCB				*_KERNEL_T_CYCCB_PTR;


#else


/** %jp{周期ハンドラコントロールブロック}%en{Cyclic Handler Control Block} */
typedef struct _kernel_t_cyccb
{
#if _KERNEL_CYCCB_TIMOBJ
	_KERNEL_T_TIMOBJ		timobj;											/**< %jp{タイマオブジェクトを継承} */
#endif


#if _KERNEL_CYCCB_CYCATR
	_KERNEL_CYCCB_T_CYCATR	cycatr		_KERNEL_CYCCB_TBITDEF_CYCATR;		/**< %jp{周期ハンドラ属性} */
#endif

#if _KERNEL_CYCCB_EXINF
	_KERNEL_CYCCB_T_EXINF	exinf		_KERNEL_CYCCB_TBITDEF_EXINF;		/**< %jp{周期ハンドラの拡張情報} */
#endif

#if _KERNEL_CYCCB_CYCHDR
	_KERNEL_CYCCB_T_CYCHDR	cychdr		_KERNEL_CYCCB_TBITDEF_CYCHDR;		/**< %jp{周期ハンドラの起動周期} */
#endif

#if _KERNEL_CYCCB_CYCTIM
	_KERNEL_CYCCB_T_RELTIM	cyctim		_KERNEL_CYCCB_TBITDEF_RELTIM;		/**< %jp{周期ハンドラの起動周期} */
#endif

#if _KERNEL_CYCCB_CYCPHS
	_KERNEL_CYCCB_T_RELTIM	cycphs		_KERNEL_CYCCB_TBITDEF_RELTIM;		/**< %jp{周期ハンドラの起動位相} */
#endif

} _KERNEL_T_CYCCB;

typedef _KERNEL_T_CYCCB				_KERNEL_T_CYCCB_RO;
typedef const _KERNEL_T_CYCCB_RO	*_KERNEL_T_CYCCB_RO_PTR;
typedef _KERNEL_T_CYCCB				*_KERNEL_T_CYCCB_PTR;


#endif



/* ------------------------------------------ */
/*  ID range                                  */
/* ------------------------------------------ */

extern const ID							_kernel_max_cycid;										/**< %jp{周期ハンドラIDの最大値} */

#define _KERNEL_CYC_TMIN_ID				1														/**< %jp{周期ハンドラIDの最小値} */
#define _KERNEL_CYC_TMAX_ID				(_kernel_max_cycid)										/**< %jp{周期ハンドラIDの最大値} */

#define _KERNEL_CYC_CHECK_CYCID(cycid)	((cycid) >= _KERNEL_CYC_TMIN_ID && (cycid) <= _KERNEL_CYC_TMAX_ID)
																								/**< %jp{ID範囲チェック} */


/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */

#if _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_BLKARRAY
#if _KERNEL_CYCCB_SPLIT_RO

/* %jp{ブロック配列管理でRO分離の場合}%en{block array} */
extern  _KERNEL_T_CYCCB					_kernel_cyccb_tbl[];									/**< %jp{周期ハンドラコントロールブロックテーブル} */
extern const _KERNEL_T_CYCCB_RO			_kernel_cyccb_ro_tbl[];									/**< %jp{周期ハンドラコントロールブロック(リードオンリー部)テーブル} */
#define _KERNEL_CYC_ID2CYCCB(cycid)		(&_kernel_cyccb_tbl[(cycid) - _KERNEL_CYC_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_CYC_CYCCB2ID(cyccb)		(((cyccb) - &_kernel_cyccb_tbl[0]) + _KERNEL_CYC_TMIN_ID])	/**< %jp{IDの取得} */
#define _KERNEL_CYC_CHECK_EXS(cycid)	(_kernel_cyccb_ro_tbl[(cycid) - _KERNEL_CYC_TMIN_ID].cychdr != NULL)				
																								/**< %jp{オブジェクトの存在チェック} */

#else

/* %jp{ブロック配列管理の場合}%en{block array} */
extern  _KERNEL_T_CYCCB					_kernel_cyccb_tbl[];									/**< %jp{周期ハンドラコントロールブロックテーブル} */
#define _KERNEL_CYC_ID2CYCCB(cycid)		(&_kernel_cyccb_tbl[(cycid) - _KERNEL_CYC_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_CYC_CYCCB2ID(cyccb)		_kernel_cyccb2id(cyccb)									/**< %jp{IDの取得} */
#define _KERNEL_CYC_CHECK_EXS(cycid)	(_kernel_cyccb_tbl[(cycid) - _KERNEL_CYC_TMIN_ID].cychdr != NULL)				
																								/**< %jp{オブジェクトの存在チェック} */

#endif

#elif _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_PTRARRAY

/* %jp{ポインタ配列管理の場合}%en{pointer array} */
extern  _KERNEL_T_CYCCB					*_kernel_cyccb_tbl[];									/**< %jp{周期ハンドラコントロールブロックテーブル} */
#define _KERNEL_CYC_ID2CYCCB(cycid)		(_kernel_cyccb_tbl[(cycid) - _KERNEL_CYC_TMIN_ID])		/**< %jp{周期ハンドラIDからCYCCB アドレスを取得} */
#define _KERNEL_CYC_CHECK_EXS(cycid)	(_KERNEL_CYC_ID2CYCCB(cycid) != NULL)					/**< %jp{オブジェクトの存在チェック} */

#endif



/* ------------------------------------------ */
/*   Accessor for CYCCB                       */
/* ------------------------------------------ */

/* cyccb_ro */
#if !_KERNEL_CYCCB_SPLIT_RO								
#define _KERNEL_CYC_GET_CYCCB_RO(cycid, cyccb)	(cyccb)
#else
#if _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_BLKARRAY		/* %jp{CYCCBを単純配列で管理}%en{array of block} */
#define _KERNEL_CYC_GET_CYCCB_RO(cycid, cyccb)	(&_kernel_cyccb_ro_tbl[(cycid)])
#elif _KERNEL_CYCCB_ALGORITHM == _KERNEL_CYCCB_ALG_PTRARRAY		/* %jp{CYCCBをポインタ配列で管理}%en{array of pointer} */
#define _KERNEL_CYC_GET_CYCCB_RO(cycid, cyccb)	((cyccb)->cyccb_ro)
#endif
#endif


/* timobj */
#define _KERNEL_CYC_GET_TIMOBJ(cyccb)			(&(cyccb)->timobj)


/* cycatr */
#if _KERNEL_CYCCB_CYCATR
#define _KERNEL_CYC_SET_CYCATR(cyccb_ro, x)	do { (cyccb_ro)->cycatr = (_KERNEL_CYCCB_T_CYCATR)(x); } while (0)
#define _KERNEL_CYC_GET_CYCATR(cyccb_ro)		((_KERNEL_CYC_T_CYCATR)(cyccb_ro)->cycatr)
#else
#define _KERNEL_CYC_SET_CYCATR(cyccb_ro, x)	do { } while (0)
#define _KERNEL_CYC_GET_CYCATR(cyccb_ro)		(0)
#endif

/* exinf */
#if _KERNEL_CYCCB_EXINF
#define _KERNEL_CYC_SET_EXINF(cyccb_ro, x)	do { (cyccb_ro)->exinf = (_KERNEL_CYCCB_T_EXINF)(x); } while (0)
#define _KERNEL_CYC_GET_EXINF(cyccb_ro)		((_KERNEL_CYC_T_EXINF)(cyccb_ro)->exinf)
#else
#define _KERNEL_CYC_SET_EXINF(cyccb_ro, x)	do { } while (0)
#define _KERNEL_CYC_GET_EXINF(cyccb_ro)		(0)
#endif

/* cychdr */
#if _KERNEL_CYCCB_CYCHDR
#define _KERNEL_CYC_SET_CYCHDR(cyccb_ro, x)	do { (cyccb_ro)->cychdr = (_KERNEL_CYCCB_T_CYCHDR)(x); } while (0)
#define _KERNEL_CYC_GET_CYCHDR(cyccb_ro)	((_KERNEL_CYC_T_CYCHDR)(cyccb_ro)->cychdr)
#else
#define _KERNEL_CYC_SET_CYCHDR(cyccb_ro, x)	do { } while (0)
#define _KERNEL_CYC_GET_CYCHDR(cyccb_ro)	(0)
#endif

/* cyctim */
#if _KERNEL_CYCCB_CYCTIM
#define _KERNEL_CYC_SET_CYCTIM(cyccb_ro, x)		do { (cyccb_ro)->cyctim = (_KERNEL_CYCCB_T_RELTIM)(x); } while (0)
#define _KERNEL_CYC_GET_CYCTIM(cyccb_ro)		((_KERNEL_CYC_T_RELTIM)(cyccb_ro)->cyctim)
#else
#define _KERNEL_CYC_SET_CYCTIM(cyccb_ro, x)		do { } while (0)
#define _KERNEL_CYC_GET_CYCTIM(cyccb_ro)		(0)
#endif

/* cycphs */
#if _KERNEL_CYCCB_CYCPHS
#define _KERNEL_CYC_SET_CYCPHS(cyccb_ro, x)		do { (cyccb_ro)->cycphs = (_KERNEL_CYCCB_T_RELTIM)(x); } while (0)
#define _KERNEL_CYC_GET_CYCPHS(cyccb_ro)		((_KERNEL_CYC_T_RELTIM)(cyccb_ro)->cycphs)
#else
#define _KERNEL_CYC_SET_CYCPHS(cyccb_ro, x)		do { } while (0)
#define _KERNEL_CYC_GET_CYCPHS(cyccb_ro)		(0)
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

ER   _kernel_cre_cyc(ID cycid, const T_CCYC *pk_ccyc);					/**< %jp{周期ハンドラ生成}%en{Create Cyclic Handler} */
void _kernel_cyc_hdr(_KERNEL_T_TIMOBJ *pk_timobj, RELTIM ovrtim);		/**< %jp{周期ハンドラ}%en{Cyclic Handler} */

#ifdef __cplusplus
}
#endif




#endif	/* _KERNEL__object__cycobj_h__ */


/* end of file */
