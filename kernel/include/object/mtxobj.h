/**
 *  Hyper Operating System V4 Advance
 *
 * @file  mtxobj.h
 * @brief %jp{ミューテックスオジェクトのヘッダファイル}%en{Mutex object heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__mtxobj_h__
#define _KERNEL__object__mtxobj_h__



/* ------------------------------------------ */
/*  Primitive type definition                 */
/* ------------------------------------------ */


/* %jp{ミューテックス所持タスクハンドル用の型} */
typedef _KERNEL_T_TSKHDL				_KERNEL_MTX_T_TSKHDL;			/**< %jp{ミューテックス所持タスクハンドルを演算操作するときの型} */
typedef _KERNEL_T_TSKHDL				_KERNEL_MTXCB_T_TSKHDL;			/**< %jp{ミューテックス所持タスクハンドルをMTXCBに格納するときの型} */
#define _KERNEL_MTXCB_TBITDEF_TSKHDL

/* %jp{ミューテックスハンドル用の型} */
typedef _KERNEL_T_MTXHDL				_KERNEL_MTX_T_MTXHDL;			/**< %jp{ミューテックス所持タスクハンドルを演算操作するときの型} */
typedef _KERNEL_T_MTXHDL				_KERNEL_MTXCB_T_MTXHDL;			/**< %jp{ミューテックス所持タスクハンドルをMTXCBに格納するときの型} */
#define _KERNEL_MTXCB_TBITDEF_MTXHDL


/* %jp{ミューテックスの上限優先度型} */
typedef PRI								_KERNEL_MTX_T_CEILPRI;			/**< %jp{ミューテックスの上限優先度を演算操作するときの型} */
typedef PRI								_KERNEL_MTXCB_T_CEILPRI;		/**< %jp{ミューテックスの上限優先度をMTXCBに格納するときの型} */
#define _KERNEL_MTXCB_TBITDEF_CEILPRI


/* %jp{ミューテックス属性用の型} */
#if _KERNEL_MTXCB_BITFIELD		/* %jp{MTXCBにビットフィールドを利用する場合} */

typedef unsigned int					_KERNEL_MTX_T_MTXATR;
typedef unsigned int					_KERNEL_MTXCB_T_MTXATR;
#define _KERNEL_MTXCB_TBITDEF_MTXATR	: 3

#else							/* %jp{MTXCBにビットフィールドを利用しない場合} */

typedef _KERNEL_T_FAST_UB				_KERNEL_MTX_T_MTXATR;
typedef _KERNEL_T_LEAST_UB				_KERNEL_MTXCB_T_MTXATR;
#define _KERNEL_MTXCB_TBITDEF_MTXATR

#endif



/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

#if _KERNEL_MTXCB_SPLIT_RO


/** %jp{ミューテックスコントロールブロック(リードオンリー部)}%en{Mutex Control Block(read-only)} */
typedef struct _kernel_t_mtxcb_ro
{
#if _KERNEL_MTXCB_MTXATR
	_KERNEL_MTXCB_T_MTXATR	mtxatr		_KERNEL_MTXCB_TBITDEF_MTXATR;		/**< %jp{ミューテックス属性} */
#endif

#if _KERNEL_MTXCB_CEILPRI
	_KERNEL_MTXCB_T_CEILPRI	ceilpri		KERNEL_MTXCB_TBITDEF_CEILPRI;		/**< %jp{ミューテックスの上限優先度} */
#endif
} _KERNEL_T_MTXCB_RO;

typedef const _KERNEL_T_MTXCB_RO	*_KERNEL_T_MTXCB_RO_PTR;


/** %jp{ミューテックスコントロールブロック}%en{Mutex Control Block} */
typedef struct _kernel_t_mtxcb
{
#if _KERNEL_MTXCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{ミューテックス待ちタスクキュー} */
#endif

#if _KERNEL_MTXCB_TSKHDL
	_KERNEL_MTXCB_T_TSKHDL	tskhdl		_KERNEL_MTXCB_TBITDEF_TSKHDL;		/**< %jp{ミューテックスを所持するタスクのハンドル} */
#endif

#if _KERNEL_MTXCB_NEXT
	_KERNEL_T_MTXHDL		next;											/**< %jp{次のミューテックスハンドル} */
#endif

#if _KERNEL_MTXCB_PREV
	_KERNEL_T_MTXHDL		prev;											/**< %jp{前のミューテックスハンドル} */
#endif

#if _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_PTRARRAY
	_KERNEL_T_MTXCB_RO_PTR	mtxcb_ro;										/**< %jp{ミューテックスコントロールブロックRO部へのポインタ} */
#endif
} _KERNEL_T_MTXCB;

typedef _KERNEL_T_MTXCB				*_KERNEL_T_MTXCB_PTR;


#else


/** %jp{ミューテックスコントロールブロック}%en{Mutex Control Block} */
typedef struct _kernel_t_mtxcb
{
#if _KERNEL_MTXCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{ミューテックス待ちタスクキュー} */
#endif

#if _KERNEL_MTXCB_TSKHDL
	_KERNEL_MTXCB_T_TSKHDL	tskhdl		_KERNEL_MTXCB_TBITDEF_TSKHDL;		/**< %jp{ミューテックスを所持するタスクのハンドル} */
#endif

#if _KERNEL_MTXCB_NEXT
	_KERNEL_T_MTXHDL		next;											/**< %jp{次のミューテックスハンドル} */
#endif

#if _KERNEL_MTXCB_PREV
	_KERNEL_T_MTXHDL		prev;											/**< %jp{前のミューテックスハンドル} */
#endif

#if _KERNEL_MTXCB_MTXATR
	_KERNEL_MTXCB_T_MTXATR	mtxatr		_KERNEL_MTXCB_TBITDEF_MTXATR;		/**< %jp{ミューテックス属性} */
#endif

#if _KERNEL_MTXCB_CEILPRI
	_KERNEL_MTXCB_T_CEILPRI	ceilpri		_KERNEL_MTXCB_TBITDEF_CEILPRI;		/**< %jp{ミューテックスの上限優先度} */
#endif
} _KERNEL_T_MTXCB;

typedef _KERNEL_T_MTXCB				_KERNEL_T_MTXCB_RO;
typedef const _KERNEL_T_MTXCB_RO	*_KERNEL_T_MTXCB_RO_PTR;
typedef _KERNEL_T_MTXCB				*_KERNEL_T_MTXCB_PTR;


#endif



/* ------------------------------------------ */
/*  ID range                                  */
/* ------------------------------------------ */

extern const ID							_kernel_max_mtxid;										/**< %jp{ミューテックスIDの最大値} */

#define _KERNEL_MTX_TMIN_ID				1														/**< %jp{ミューテックスIDの最小値} */
#define _KERNEL_MTX_TMAX_ID				(_kernel_max_mtxid)										/**< %jp{ミューテックスIDの最大値} */

#define _KERNEL_MTX_CHECK_MTXID(mtxid)	((mtxid) >= _KERNEL_MTX_TMIN_ID && (mtxid) <= _KERNEL_MTX_TMAX_ID)
																								/**< %jp{ID範囲チェック} */


/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */

#if _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_BLKARRAY
#if _KERNEL_MTXCB_SPLIT_RO

/* %jp{ブロック配列管理でRO分離の場合}%en{block array} */
extern  _KERNEL_T_MTXCB					_kernel_mtxcb_tbl[];									/**< %jp{ミューテックスコントロールブロックテーブル} */
extern const _KERNEL_T_MTXCB_RO			_kernel_mtxcb_ro_tbl[];									/**< %jp{ミューテックスコントロールブロック(リードオンリー部)テーブル} */
#define _KERNEL_MTX_ID2MTXCB(mtxid)		(&_kernel_mtxcb_tbl[(mtxid) - _KERNEL_MTX_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_MTX_CHECK_EXS(mtxid)	(_kernel_mtxcb_ro_tbl[(mtxid) - _KERNEL_MTX_TMIN_ID].mtxatr != 0)
																								/**< %jp{オブジェクトの存在チェック} */

#else

/* %jp{ブロック配列管理の場合}%en{block array} */
extern  _KERNEL_T_MTXCB					_kernel_mtxcb_tbl[];									/**< %jp{ミューテックスコントロールブロックテーブル} */
#define _KERNEL_MTX_ID2MTXCB(mtxid)		(&_kernel_mtxcb_tbl[(mtxid) - _KERNEL_MTX_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_MTX_CHECK_EXS(mtxid)	(_kernel_mtxcb_tbl[(mtxid) - _KERNEL_MTX_TMIN_ID].mtxatr != 0)			
																								/**< %jp{オブジェクトの存在チェック} */

#endif

#elif _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_PTRARRAY

/* %jp{ポインタ配列管理の場合}%en{pointer array} */
extern  _KERNEL_T_MTXCB					*_kernel_mtxcb_tbl[];									/**< %jp{ミューテックスコントロールブロックテーブル} */
#define _KERNEL_MTX_ID2MTXCB(mtxid)		(_kernel_mtxcb_tbl[(mtxid) - _KERNEL_MTX_TMIN_ID])		/**< %jp{ミューテックスIDからMTXCB アドレスを取得} */
#define _KERNEL_MTX_CHECK_EXS(mtxid)	(_KERNEL_MTX_ID2MTXCB(mtxid) != NULL)					/**< %jp{オブジェクトの存在チェック} */

#endif



/* ------------------------------------------ */
/*  Convert Handle                            */
/* ------------------------------------------ */

#if _KERNEL_MTXHDL_ID		/* %jp{ミューテックスハンドルにIDを使う}%en{MTXHDL is ID} */

#define _KERNEL_MTX_ID2MTXHDL(mtxid)			(mtxid)
#define _KERNEL_MTX_MTXHDL2ID(mtxhdl)			(mtxhdl)
#define _KERNEL_MTX_MTXCB2MTXHDL(mtxcb)			_KERNEL_MTX_MTXCB2ID(mtxcb)
#define _KERNEL_MTX_MTXHDL2MTXCB(mtxhdl)		_KERNEL_MTX_ID2MTXCB(mtxhdl)
#define _KERNEL_MTX_GET_MTXHDL(mtxid, mtxcb)	(mtxid)

#else						/* %jp{ミューテックスハンドルにMTXCBのアドレスを使う}%en{TSKHDL is Address of MTXCB} */

#define _KERNEL_MTX_ID2MTXHDL(mtxid)			_KERNEL_MTX_ID2MTXCB(mtxid)
#define _KERNEL_MTX_MTXHDL2ID(mtxhdl)			_KERNEL_MTX_MTXCB2ID(mtxhdl)
#define _KERNEL_MTX_MTXCB2MTXHDL(mtxcb)			(mtxhdl)
#define _KERNEL_MTX_MTXHDL2MTXCB(mtxhdl)		(mtxhdl)
#define _KERNEL_MTX_GET_MTXHDL(mtxid, mtxcb)	(mtxcb)

#endif



/* ------------------------------------------ */
/*   Accessor for MTXCB                       */
/* ------------------------------------------ */

/* mtxcb_ro */
#if !_KERNEL_MTXCB_SPLIT_RO								
#define _KERNEL_MTX_GET_MTXCB_RO(mtxid, mtxcb)	(mtxcb)
#else
#if _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_BLKARRAY		/* %jp{MTXCBを単純配列で管理}%en{array of block} */
#define _KERNEL_MTX_GET_MTXCB_RO(mtxid, mtxcb)	(&_kernel_mtxcb_ro_tbl[(mtxid)])
#elif _KERNEL_MTXCB_ALGORITHM == _KERNEL_MTXCB_ALG_PTRARRAY		/* %jp{MTXCBをポインタ配列で管理}%en{array of pointer} */
#define _KERNEL_MTX_GET_MTXCB_RO(mtxid, mtxcb)	((mtxcb)->mtxcb_ro)
#endif
#endif


/* que */
#define _KERNEL_MTX_GET_QUE(mtxcb)				(&(mtxcb)->que)


/* tskhdl */
#if _KERNEL_MTXCB_TSKHDL
#define _KERNEL_MTX_SET_TSKHDL(mtxcb, x)		do { (mtxcb)->tskhdl = (_KERNEL_MTXCB_T_TSKHDL)(x); } while (0)
#define _KERNEL_MTX_GET_TSKHDL(mtxcb)			((_KERNEL_MTX_T_TSKHDL)(mtxcb)->tskhdl)
#else
#define _KERNEL_MTX_SET_TSKHDL(mtxcb, x)		do { } while (0)
#define _KERNEL_MTX_GET_TSKHDL(mtxcb)			(0)
#endif


/* next */
#if _KERNEL_MTXCB_NEXT
#define _KERNEL_MTX_SET_NEXT(mtxcb, x)			do { (mtxcb)->next = (_KERNEL_MTXCB_T_MTXHDL)(x); } while (0)
#define _KERNEL_MTX_GET_NEXT(mtxcb)				((_KERNEL_MTX_T_MTXHDL)(mtxcb)->next)
#else
#define _KERNEL_MTX_SET_NEXT(mtxcb, x)			do { } while (0)
#define _KERNEL_MTX_GET_NEXT(mtxcb)				(0)
#endif


/* prev */
#if _KERNEL_MTXCB_PREV
#define _KERNEL_MTX_SET_PREV(mtxcb, x)			do { (mtxcb)->prev = (_KERNEL_MTXCB_T_MTXHDL)(x); } while (0)
#define _KERNEL_MTX_GET_PREV(mtxcb)				((_KERNEL_MTX_T_MTXHDL)(mtxcb)->prev)
#else
#define _KERNEL_MTX_SET_PREV(mtxcb, x)			do { } while (0)
#define _KERNEL_MTX_GET_PREV(mtxcb)				(0)
#endif



/* mtxatr */
#if _KERNEL_MTXCB_MTXATR
#define _KERNEL_MTX_SET_MTXATR(mtxcb_ro, x)		do { (mtxcb_ro)->mtxatr = (_KERNEL_MTXCB_T_MTXATR)(x); } while (0)
#define _KERNEL_MTX_GET_MTXATR(mtxcb_ro)		((_KERNEL_MTX_T_MTXATR)(mtxcb_ro)->mtxatr)
#else
#define _KERNEL_MTX_SET_MTXATR(mtxcb_ro, x)		do { } while (0)
#if _KERNEL_SPT_MTX_TA_CEILING
#define _KERNEL_MTX_GET_MTXATR(mtxcb_ro)		(TA_CEILING)
#else
#define _KERNEL_MTX_GET_MTXATR(mtxcb_ro)		(TA_INHERIT)
#endif
#endif


/* ceilpri */
#if _KERNEL_MTXCB_CEILPRI
#define _KERNEL_MTX_SET_CEILPRI(mtxcb_ro, x)	do { (mtxcb_ro)->ceilpri = (_KERNEL_MTXCB_T_CEILPRI)(x); } while (0)
#define _KERNEL_MTX_GET_CEILPRI(mtxcb_ro)		((_KERNEL_MTX_T_CEILPRI)(mtxcb_ro)->ceilpri)
#else
#define _KERNEL_MTX_SET_CEILPRI(mtxcb_ro, x)	do { } while (0)
#define _KERNEL_MTX_GET_CEILPRI(mtxcb_ro)		(1)
#endif



/* ------------------------------------------ */
/*   Macro functions                          */
/* ------------------------------------------ */

/* %jp{キュー接続} */
#if _KERNEL_SPT_MTX_TA_TFIFO && _KERNEL_SPT_MTX_TA_TPRI		/* %jp{TA_TFIFO と TA_TPRI の混在 } */
#define _KERNEL_MTX_ADD_QUE(mtxcb, mtxcb_ro, tskhdl)	_KERNEL_ADD_QUE(_KERNEL_MTX_GET_QUE(mtxcb), tskhdl, _KERNEL_MTX_GET_MTXATR(mtxcb_ro))
#elif _KERNEL_SPT_MTX_TA_TFIFO && !_KERNEL_SPT_SE_TA_TPRI	/* %jp{TA_TFIFO のみ利用 } */
#define _KERNEL_MTX_ADD_QUE(mtxcb, mtxcb_ro, tskhdl)	_KERNEL_ADF_QUE(_KERNEL_MTX_GET_QUE(mtxcb), tskhdl)
#elif !_KERNEL_SPT_MTX_TA_TFIFO && _KERNEL_SPT_MTX_TA_TPRI	/* %jp{TA_TPRI のみ利用 } */
#define _KERNEL_MTX_ADD_QUE(mtxcb, mtxcb_ro, tskhdl)	_KERNEL_ADP_QUE(_KERNEL_MTX_GET_QUE(mtxcb), tskhdl)
#else
#error error:_KERNEL_SPT_MTX_TA_TPRI and _KERNEL_SPT_MTX_TA_TFIFO
#endif

/* %jp{キュー取り外し} */
#define _KERNEL_MTX_RMV_QUE(mtxcb, tskhdl)	_KERNEL_RMV_QUE(_KERNEL_MTX_GET_QUE(mtxcb), tskhdl)

/* %jp{キュー先頭取り出し} */
#define _KERNEL_MTX_RMH_QUE(mtxcb)			_KERNEL_RMH_QUE(_KERNEL_MTX_GET_QUE(mtxcb))


/* %jp{タイムアウトキュー接続} */
#if _KERNEL_SPT_TLOC_MTX	/* %jp{tloc_mtxサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_MTX_ADD_TOQ(tskhdl, tmout)	_KERNEL_SYS_ADD_TOQ(tskhdl, tmout)
#else
#define _KERNEL_MTX_ADD_TOQ(tskhdl)			do { } while (0)
#endif

/* %jp{タイムアウトキュー取り外し} */
#if _KERNEL_SPT_TLOC_MTX	/* %jp{tloc_mtxサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_MTX_RMV_TOQ(tskhdl)			_KERNEL_SYS_RMV_TOQ(tskhdl)
#else
#define _KERNEL_MTX_RMV_TOQ(tskhdl)			do { } while (0)
#endif



/* ------------------------------------------ */
/*   Functions                                */
/* ------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

ER   _kernel_cre_mtx(ID mtxid, const T_CMTX *pk_cmtx);					/**< %jp{ミューテックス生成}%en{Create Mutex} */
ER   _kernel_loc_mtx(ID mtxid, TMO tmout);								/**< %jp{ミューテックスのロック(統合版)} */
void _kernel_add_mtx(_KERNEL_T_MTXHDL mtxhdl, _KERNEL_T_TSKHDL tskhdl);	/**< %jp{タスクにミューテックスを接続} */
void _kernel_rmv_mtx(_KERNEL_T_MTXHDL mtxhdl, _KERNEL_T_TSKHDL tskhdl);	/**< %jp{タスクからミューテックスを取り外し} */


#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__mtxobj_h__ */


/* end of file */
