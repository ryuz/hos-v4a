/**
 *  Hyper Operating System V4 Advance
 *
 * @file  semobj.h
 * @brief %jp{セマフォオジェクトのヘッダファイル}%en{Semaphore object heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__semobj_h__
#define _KERNEL__object__semobj_h__



/* ------------------------------------------ */
/*  Primitive type definition                 */
/* ------------------------------------------ */

/* %jp{セマフォカウンタ値用の型} */
#if _KERNEL_SEMCB_BITFIELD		/* %jp{SEMCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef signed int						_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#define _KERNEL_SEMCB_TBITDEF_SEMCNT	: (_KERNEL_SEM_TBIT_SEMCNT+1)	/**< %jp{セマフォカウンタのビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef unsigned int					_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#define _KERNEL_SEMCB_TBITDEF_SEMCNT	: _KERNEL_SEM_TBIT_SEMCNT		/**< %jp{セマフォカウンタのビットフィールド宣言時の幅} */
#endif

#else							/* %jp{SEMCBにビットフィールドを利用しない場合} */

#if (_KERNEL_SEM_TMAX_SEMCNT <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#elif (_KERNEL_SEM_TMAX_SEMCNT <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#elif (_KERNEL_SEM_TMAX_SEMCNT <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#elif (_KERNEL_SEM_TMAX_SEMCNT <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#elif (_KERNEL_SEM_TMAX_SEMCNT <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#elif (_KERNEL_SEM_TMAX_SEMCNT <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#elif (_KERNEL_SEM_TMAX_SEMCNT <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_SEM_T_SEMCNT;			/**< %jp{セマフォカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_SEMCB_T_SEMCNT;			/**< %jp{セマフォカウンタをSEMCBに格納するときの型} */
#endif
#define _KERNEL_SEMCB_TBITDEF_SEMCNT									/**< %jp{セマフォカウンタのビットフィールド宣言時の幅} */

#endif


/* %jp{セマフォ属性用の型} */
#if _KERNEL_SEMCB_BITFIELD		/* %jp{SEMCBにビットフィールドを利用する場合} */

/* %jp{TA_TFIFO と TA_TPRI の判定に 1bit 必要} */
typedef unsigned int					_KERNEL_SEM_T_SEMATR;
typedef unsigned int					_KERNEL_SEMCB_T_SEMATR;
#define _KERNEL_SEMCB_TBITDEF_SEMATR	: 1

#else							/* %jp{SEMCBにビットフィールドを利用しない場合} */

typedef _KERNEL_T_FAST_UB				_KERNEL_SEM_T_SEMATR;
typedef _KERNEL_T_LEAST_UB				_KERNEL_SEMCB_T_SEMATR;
#define _KERNEL_SEMCB_TBITDEF_SEMATR

#endif



/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

#if _KERNEL_SEMCB_SPLIT_RO


/** %jp{セマフォコントロールブロック(リードオンリー部)}%en{Semaphore Control Block(read-only)} */
typedef struct _kernel_t_semcb_ro
{
#if _KERNEL_SEMCB_SEMATR
	_KERNEL_SEMCB_T_SEMATR	sematr		_KERNEL_SEMCB_TBITDEF_SEMATR;		/**< %jp{セマフォ属性} */
#endif

#if _KERNEL_SEMCB_MAXSEM
	_KERNEL_SEMCB_T_SEMCNT	maxsem		_KERNEL_SEMCB_TBITDEF_SEMCNT;		/**< %jp{セマフォの最大資源数} */
#endif
} _KERNEL_T_SEMCB_RO;

typedef const _KERNEL_T_SEMCB_RO	*_KERNEL_T_SEMCB_RO_PTR;


/** %jp{セマフォコントロールブロック}%en{Semaphore Control Block} */
typedef struct _kernel_t_semcb
{
#if _KERNEL_SEMCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{セマフォ待ちタスクキュー} */
#endif

#if _KERNEL_SEMCB_SEMCNT
	_KERNEL_SEMCB_T_SEMCNT	semcnt		_KERNEL_SEMCB_TBITDEF_SEMCNT;		/**< %jp{セマフォの資源数} */
#endif


#if _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_PTRARRAY
	_KERNEL_T_SEMCB_RO_PTR	semcb_ro;										/**< %jp{セマフォコントロールブロックRO部へのポインタ} */
#endif
} _KERNEL_T_SEMCB;

typedef _KERNEL_T_SEMCB				*_KERNEL_T_SEMCB_PTR;


#else


/** %jp{セマフォコントロールブロック}%en{Semaphore Control Block} */
typedef struct _kernel_t_semcb
{
#if _KERNEL_SEMCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{セマフォ待ちタスクキュー} */
#endif

#if _KERNEL_SEMCB_SEMCNT
	_KERNEL_SEMCB_T_SEMCNT	semcnt		_KERNEL_SEMCB_TBITDEF_SEMCNT;		/**< %jp{セマフォの資源数} */
#endif

#if _KERNEL_SEMCB_SEMATR
	_KERNEL_SEMCB_T_SEMATR	sematr		_KERNEL_SEMCB_TBITDEF_SEMATR;		/**< %jp{セマフォ属性} */
#endif

#if _KERNEL_SEMCB_MAXSEM
	_KERNEL_SEMCB_T_SEMCNT	maxsem		_KERNEL_SEMCB_TBITDEF_SEMCNT;		/**< %jp{セマフォの最大資源数} */
#endif
} _KERNEL_T_SEMCB;

typedef _KERNEL_T_SEMCB				_KERNEL_T_SEMCB_RO;
typedef const _KERNEL_T_SEMCB_RO	*_KERNEL_T_SEMCB_RO_PTR;
typedef _KERNEL_T_SEMCB				*_KERNEL_T_SEMCB_PTR;


#endif



/* ------------------------------------------ */
/*  ID range                                  */
/* ------------------------------------------ */

extern const ID							_kernel_max_semid;										/**< %jp{セマフォIDの最大値} */

#define _KERNEL_SEM_TMIN_ID				1														/**< %jp{セマフォIDの最小値} */
#define _KERNEL_SEM_TMAX_ID				(_kernel_max_semid)										/**< %jp{セマフォIDの最大値} */

#define _KERNEL_SEM_CHECK_SEMID(semid)	((semid) >= _KERNEL_SEM_TMIN_ID && (semid) <= _KERNEL_SEM_TMAX_ID)
																								/**< %jp{ID範囲チェック} */


/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */

#if _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_BLKARRAY
#if _KERNEL_SEMCB_SPLIT_RO

/* %jp{ブロック配列管理でRO分離の場合}%en{block array} */
extern  _KERNEL_T_SEMCB					_kernel_semcb_tbl[];									/**< %jp{セマフォコントロールブロックテーブル} */
extern const _KERNEL_T_SEMCB_RO			_kernel_semcb_ro_tbl[];									/**< %jp{セマフォコントロールブロック(リードオンリー部)テーブル} */
#define _KERNEL_SEM_ID2SEMCB(semid)		(&_kernel_semcb_tbl[(semid) - _KERNEL_SEM_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_SEM_CHECK_EXS(semid)	(_kernel_semcb_ro_tbl[(semid) - _KERNEL_SEM_TMIN_ID].maxsem > 0)				
																								/**< %jp{オブジェクトの存在チェック} */

#else

/* %jp{ブロック配列管理の場合}%en{block array} */
extern  _KERNEL_T_SEMCB					_kernel_semcb_tbl[];									/**< %jp{セマフォコントロールブロックテーブル} */
#define _KERNEL_SEM_ID2SEMCB(semid)		(&_kernel_semcb_tbl[(semid) - _KERNEL_SEM_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_SEM_CHECK_EXS(semid)	(_kernel_semcb_tbl[(semid) - _KERNEL_SEM_TMIN_ID].maxsem > 0)				
																								/**< %jp{オブジェクトの存在チェック} */

#endif

#elif _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_PTRARRAY

/* %jp{ポインタ配列管理の場合}%en{pointer array} */
extern  _KERNEL_T_SEMCB					*_kernel_semcb_tbl[];									/**< %jp{セマフォコントロールブロックテーブル} */
#define _KERNEL_SEM_ID2SEMCB(semid)		(_kernel_semcb_tbl[(semid) - _KERNEL_SEM_TMIN_ID])		/**< %jp{セマフォIDからSEMCB アドレスを取得} */
#define _KERNEL_SEM_CHECK_EXS(semid)	(_KERNEL_SEM_ID2SEMCB(semid) != NULL)					/**< %jp{オブジェクトの存在チェック} */

#endif



/* ------------------------------------------ */
/*   Accessor for SEMCB                       */
/* ------------------------------------------ */

/* semcb_ro */
#if !_KERNEL_SEMCB_SPLIT_RO								
#define _KERNEL_SEM_GET_SEMCB_RO(semid, semcb)	(semcb)
#else
#if _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_BLKARRAY		/* %jp{SEMCBを単純配列で管理}%en{array of block} */
#define _KERNEL_SEM_GET_SEMCB_RO(semid, semcb)	(&_kernel_semcb_ro_tbl[(semid)])
#elif _KERNEL_SEMCB_ALGORITHM == _KERNEL_SEMCB_ALG_PTRARRAY		/* %jp{SEMCBをポインタ配列で管理}%en{array of pointer} */
#define _KERNEL_SEM_GET_SEMCB_RO(semid, semcb)	((semcb)->semcb_ro)
#endif
#endif


/* que */
#define _KERNEL_SEM_GET_QUE(semcb)			(&(semcb)->que)


/* semcnt */
#if _KERNEL_SEMCB_SEMCNT
#define _KERNEL_SEM_SET_SEMCNT(semcb, x)	do { (semcb)->semcnt = (_KERNEL_SEMCB_T_SEMCNT)(x); } while (0)
#define _KERNEL_SEM_GET_SEMCNT(semcb)		((_KERNEL_SEM_T_SEMCNT)(semcb)->semcnt)
#else
#define _KERNEL_SEM_SET_SEMCNT(semcb, x)	do { } while (0)
#define _KERNEL_SEM_GET_SEMCNT(semcb)		(0)
#endif


/* sematr */
#if _KERNEL_SEMCB_SEMATR
#define _KERNEL_SEM_SET_SEMATR(semcb, x)	do { (semcb)->sematr = (_KERNEL_SEMCB_T_SEMATR)(x); } while (0)
#define _KERNEL_SEM_GET_SEMATR(semcb)		((_KERNEL_SEM_T_SEMATR)(semcb)->sematr)
#else
#define _KERNEL_SEM_SET_SEMATR(semcb, x)	do { } while (0)
#if _KERNEL_SPT_SEM_TA_TFIFO
#define _KERNEL_SEM_GET_SEMATR(semcb)		(TA_TFIFO)
#else
#define _KERNEL_SEM_GET_SEMATR(semcb)		(TA_TPRI)
#endif
#endif


/* maxsem */
#if _KERNEL_SEMCB_MAXSEM
#define _KERNEL_SEM_SET_MAXSEM(semcb_ro, x)	do { (semcb_ro)->maxsem = (_KERNEL_SEMCB_T_SEMCNT)(x); } while (0)
#define _KERNEL_SEM_GET_MAXSEM(semcb_ro)	((_KERNEL_SEM_T_SEMCNT)(semcb_ro)->maxsem)
#else
#define _KERNEL_SEM_SET_MAXSEM(semcb_ro, x)	do { } while (0)
#define _KERNEL_SEM_GET_MAXSEM(semcb_ro)	(_KERNEL_TMAX_MAXSEM)
#endif



/* ------------------------------------------ */
/*   Macro functions                          */
/* ------------------------------------------ */

/* %jp{キュー接続} */
#if _KERNEL_SPT_SEM_TA_TFIFO && _KERNEL_SPT_SEM_TA_TPRI		/* %jp{TA_TFIFO と TA_TPRI の混在 } */
#define _KERNEL_SEM_ADD_QUE(semcb, semcb_ro, tskhdl)	_KERNEL_ADD_QUE(_KERNEL_SEM_GET_QUE(semcb), tskhdl, _KERNEL_SEM_GET_SEMATR(semcb_ro))
#elif _KERNEL_SPT_SEM_TA_TFIFO && !_KERNEL_SPT_SE_TA_TPRI	/* %jp{TA_TFIFO のみ利用 } */
#define _KERNEL_SEM_ADD_QUE(semcb, semcb_ro, tskhdl)	_KERNEL_ADF_QUE(_KERNEL_SEM_GET_QUE(semcb), tskhdl)
#elif !_KERNEL_SPT_SEM_TA_TFIFO && _KERNEL_SPT_SEM_TA_TPRI	/* %jp{TA_TPRI のみ利用 } */
#define _KERNEL_SEM_ADD_QUE(semcb, semcb_ro, tskhdl)	_KERNEL_ADP_QUE(_KERNEL_SEM_GET_QUE(semcb), tskhdl)
#else
#error error:_KERNEL_SPT_SEM_TA_TPRI and _KERNEL_SPT_SEM_TA_TFIFO
#endif

/* %jp{キュー取り外し} */
#define _KERNEL_SEM_RMV_QUE(semcb, tskhdl)	_KERNEL_RMV_QUE(_KERNEL_SEM_GET_QUE(semcb), tskhdl)

/* %jp{キュー先頭取り出し} */
#define _KERNEL_SEM_RMH_QUE(semcb)			_KERNEL_RMH_QUE(_KERNEL_SEM_GET_QUE(semcb))


/* %jp{タイムアウトキュー接続} */
#if _KERNEL_SPT_TWAI_SEM	/* %jp{twai_semサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_SEM_ADD_TOQ(tskhdl, tmout)	_KERNEL_SYS_ADD_TOQ(tskhdl, tmout)
#else
#define _KERNEL_SEM_ADD_TOQ(tskhdl)			do { } while (0)
#endif

/* %jp{タイムアウトキュー取り外し} */
#if _KERNEL_SPT_TWAI_SEM	/* %jp{twai_semサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_SEM_RMV_TOQ(tskhdl)			_KERNEL_SYS_RMV_TOQ(tskhdl)
#else
#define _KERNEL_SEM_RMV_TOQ(tskhdl)			do { } while (0)
#endif



/* ------------------------------------------ */
/*   Functions                                */
/* ------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

ER _kernel_cre_sem(ID semid, const T_CSEM *pk_csem);	/**< %jp{セマフォ生成}%en{Create Semaphore} */
ER _kernel_wai_sem(ID semid, TMO tmout);				/**< %jp{セマフォ資源の獲得(統合版)}%en{Acquire Semaphore Resource} */

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__semobj_h__ */


/* end of file */
