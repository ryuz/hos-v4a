/**
 *  Hyper Operating System V4 Advance
 *
 * @file  dtqobj.h
 * @brief %jp{データキュージェクトのヘッダファイル}%en{Data queue object heder file}
 *
 * Copyright (C) 1998-2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__dtqobj_h__
#define _KERNEL__object__dtqobj_h__



/* ------------------------------------------ */
/*  Primitive type definition                 */
/* ------------------------------------------ */

/* %jp{データキューカウンタ値用の型} */
#if _KERNEL_DTQCB_BITFIELD		/* %jp{DTQCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef signed int						_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#define _KERNEL_DTQCB_TBITDEF_DTQCNT	: (_KERNEL_DTQ_TBIT_DTQCNT+1)	/**< %jp{データキューカウンタのビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef unsigned int					_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#define _KERNEL_DTQCB_TBITDEF_DTQCNT	: _KERNEL_DTQ_TBIT_DTQCNT		/**< %jp{データキューカウンタのビットフィールド宣言時の幅} */
#endif

#else							/* %jp{DTQCBにビットフィールドを利用しない場合} */

#if (_KERNEL_DTQ_TMAX_DTQCNT <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#elif (_KERNEL_DTQ_TMAX_DTQCNT <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#elif (_KERNEL_DTQ_TMAX_DTQCNT <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#elif (_KERNEL_DTQ_TMAX_DTQCNT <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#elif (_KERNEL_DTQ_TMAX_DTQCNT <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#elif (_KERNEL_DTQ_TMAX_DTQCNT <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#elif (_KERNEL_DTQ_TMAX_DTQCNT <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_DTQ_T_DTQCNT;			/**< %jp{データキューカウンタを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_DTQCB_T_DTQCNT;			/**< %jp{データキューカウンタをDTQCBに格納するときの型} */
#endif
#define _KERNEL_DTQCB_TBITDEF_DTQCNT									/**< %jp{データキューカウンタのビットフィールド宣言時の幅} */

#endif


/* %jp{データキュー属性用の型} */
#if _KERNEL_DTQCB_BITFIELD		/* %jp{DTQCBにビットフィールドを利用する場合} */

/* %jp{TA_TFIFO と TA_TPRI の判定に 1bit 必要} */
typedef unsigned int					_KERNEL_DTQ_T_DTQATR;
typedef unsigned int					_KERNEL_DTQCB_T_DTQATR;
#define _KERNEL_DTQCB_TBITDEF_DTQATR	: 1

#else							/* %jp{DTQCBにビットフィールドを利用しない場合} */

typedef _KERNEL_T_FAST_UB				_KERNEL_DTQ_T_DTQATR;
typedef _KERNEL_T_LEAST_UB				_KERNEL_DTQCB_T_DTQATR;
#define _KERNEL_DTQCB_TBITDEF_DTQATR

#endif


/* %jp{データキュー領域の先頭番地用の型} */
typedef VP_INT*							_KERNEL_DTQ_T_DTQ;
typedef VP_INT*							_KERNEL_DTQCB_T_DTQ;
#define _KERNEL_DTQCB_TBITDEF_DTQ



/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

#if _KERNEL_DTQCB_SPLIT_RO

/** %jp{データキューコントロールブロック(リードオンリー部)}%en{Data queue Control Block(read-only)} */
typedef struct _kernel_t_dtqcb_ro
{
#if _KERNEL_DTQCB_DTQATR
	_KERNEL_DTQCB_T_DTQATR	dtqatr		_KERNEL_DTQCB_TBITDEF_DTQATR;		/**< %jp{データキュー属性}%en{Data queue attribute} */
#endif

#if _KERNEL_DTQCB_DTQCNT
	_KERNEL_DTQCB_T_DTQCNT	dtqcnt		_KERNEL_DTQCB_TBITDEF_DTQCNT;		/**< %jp{データキュー領域の容量(データの個数)}%en{Capacity of the data queue area(the number of data elements)} */
#endif

#if _KERNEL_DTQCB_DTQ
	_KERNEL_DTQCB_T_DTQ		dtq			_KERNEL_DTQCB_TBITDEF_DTQ;			/**< %jp{データキュー領域の先頭番地}%en{Start address of the data queue area} */
#endif
} _KERNEL_T_DTQCB_RO;

/** %jp{データキューコントロールブロック}%en{Data queue Control Block} */
typedef struct _kernel_t_dtqcb
{
#if _KERNEL_DTQCB_SQUE
	_KERNEL_T_QUE			sque;											/**< %jp{データキュー送信待ちタスクキュー} */
#endif

#if _KERNEL_DTQCB_RQUE
	_KERNEL_T_QUE			rque;											/**< %jp{データキュー受信待ちタスクキュー} */
#endif

#if _KERNEL_DTQCB_SDTQCNT
	_KERNEL_DTQCB_T_DTQCNT	sdtqcnt		_KERNEL_DTQCB_TBITDEF_DTQCNT;		/**< %jp{データキューに入っているデータの数}%en{The number of data elemnts int the data queue} */
#endif

#if _KERNEL_DTQCB_HEAD
	_KERNEL_DTQCB_T_DTQCNT	head		_KERNEL_DTQCB_TBITDEF_DTQCNT;		/**< %jp{データキューのデータ先頭位置} */
#endif


#if _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_PTRARRAY
	const _KERNEL_T_SEMCB_RO	*dtqcb_ro;									/**< %jp{データキューコントロールブロックRO部へのポインタ} */
#endif
} _KERNEL_T_DTQCB;


#else


/** %jp{データキューコントロールブロック}%en{Data queue Control Block} */
typedef struct _kernel_t_dtqcb
{
#if _KERNEL_DTQCB_SQUE
	_KERNEL_T_QUE			sque;											/**< %jp{データキュー送信待ちタスクキュー} */
#endif

#if _KERNEL_DTQCB_RQUE
	_KERNEL_T_QUE			rque;											/**< %jp{データキュー受信待ちタスクキュー} */
#endif

#if _KERNEL_DTQCB_SDTQCNT
	_KERNEL_DTQCB_T_DTQCNT	sdtqcnt		_KERNEL_DTQCB_TBITDEF_DTQCNT;		/**< %jp{データキューに入っているデータの数}%en{The number of data elemnts int the data queue} */
#endif

#if _KERNEL_DTQCB_HEAD
	_KERNEL_DTQCB_T_DTQCNT	head		_KERNEL_DTQCB_TBITDEF_DTQCNT;		/**< %jp{データキューのデータ先頭位置} */
#endif


#if _KERNEL_DTQCB_DTQATR
	_KERNEL_DTQCB_T_DTQATR	dtqatr		_KERNEL_DTQCB_TBITDEF_DTQATR;		/**< %jp{データキュー属性}%en{Data queue attribute} */
#endif

#if _KERNEL_DTQCB_DTQCNT
	_KERNEL_DTQCB_T_DTQCNT	dtqcnt		_KERNEL_DTQCB_TBITDEF_DTQCNT;		/**< %jp{データキュー領域の容量(データの個数)}%en{Capacity of the data queue area(the number of data elements)} */
#endif

#if _KERNEL_DTQCB_DTQ
	_KERNEL_DTQCB_T_DTQ		dtq			_KERNEL_DTQCB_TBITDEF_DTQ;			/**< %jp{データキュー領域の先頭番地}%en{Start address of the data queue area} */
#endif
} _KERNEL_T_DTQCB;

typedef _KERNEL_T_DTQCB		_KERNEL_T_DTQCB_RO;


#endif



/* ------------------------------------------ */
/*  ID range                                  */
/* ------------------------------------------ */

extern const ID							_kernel_max_dtqid;										/**< %jp{データキューIDの最大値} */

#define _KERNEL_DTQ_TMIN_ID				1														/**< %jp{データキューIDの最小値} */
#define _KERNEL_DTQ_TMAX_ID				(_kernel_max_dtqid)										/**< %jp{データキューIDの最大値} */

#define _KERNEL_DTQ_CHECK_DTQID(dtqid)	((dtqid) >= _KERNEL_DTQ_TMIN_ID && (dtqid) <= _KERNEL_DTQ_TMAX_ID)
																								/**< %jp{ID範囲チェック} */


/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */

#if _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_BLKARRAY
#if _KERNEL_DTQCB_SPLIT_RO

/* %jp{ブロック配列管理でRO分離の場合}%en{block array} */
extern  _KERNEL_T_DTQCB					_kernel_dtqcb_tbl[];									/**< %jp{データキューコントロールブロックテーブル} */
extern const _KERNEL_T_DTQCB_RO			_kernel_dtqcb_ro_tbl[];									/**< %jp{データキューコントロールブロック(リードオンリー部)テーブル} */
#define _KERNEL_DTQ_ID2DTQCB(dtqid)		(&_kernel_dtqcb_tbl[(dtqid) - _KERNEL_DTQ_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_DTQ_CHECK_EXS(dtqid)	(_kernel_dtqcb_ro_tbl[(dtqid) - _KERNEL_DTQ_TMIN_ID].dtq != NULL)
																								/**< %jp{オブジェクトの存在チェック} */

#else

/* %jp{ブロック配列管理の場合}%en{block array} */
extern  _KERNEL_T_DTQCB					_kernel_dtqcb_tbl[];									/**< %jp{データキューコントロールブロックテーブル} */
#define _KERNEL_DTQ_ID2DTQCB(dtqid)		(&_kernel_dtqcb_tbl[(dtqid) - _KERNEL_DTQ_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_DTQ_CHECK_EXS(dtqid)	(_kernel_dtqcb_tbl[(dtqid) - _KERNEL_DTQ_TMIN_ID].dtq != NULL)
																								/**< %jp{オブジェクトの存在チェック} */

#endif

#elif _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_PTRARRAY

/* %jp{ポインタ配列管理の場合}%en{pointer array} */
extern  _KERNEL_T_DTQCB					*_kernel_dtqcb_tbl[];									/**< %jp{データキューコントロールブロックテーブル} */
#define _KERNEL_DTQ_ID2DTQCB(dtqid)		(_kernel_dtqcb_tbl[(dtqid) - _KERNEL_DTQ_TMIN_ID])		/**< %jp{データキューIDからDTQCB アドレスを取得} */
#define _KERNEL_DTQ_CHECK_EXS(dtqid)	(_KERNEL_DTQ_ID2DTQCB(dtqid) != NULL)					/**< %jp{オブジェクトの存在チェック} */

#endif



/* ------------------------------------------ */
/*   Accessor for DTQCB                       */
/* ------------------------------------------ */

/* dtqcb_ro */
#if !_KERNEL_DTQCB_SPLIT_RO								
#define _KERNEL_DTQ_GET_DTQCB_RO(dtqid, dtqcb)	(dtqcb)
#else
#if _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_BLKARRAY		/* %jp{DTQCBを単純配列で管理}%en{array of block} */
#define _KERNEL_DTQ_GET_DTQCB_RO(dtqid, dtqcb)	(&_kernel_dtqcb_ro_tbl[(dtqid)])
#elif _KERNEL_DTQCB_ALGORITHM == _KERNEL_DTQCB_ALG_PTRARRAY		/* %jp{DTQCBをポインタ配列で管理}%en{array of pointer} */
#define _KERNEL_DTQ_GET_DTQCB_RO(dtqid, dtqcb)	((dtqcb)->dtqcb_ro)
#endif
#endif


/* sque */
#define _KERNEL_DTQ_GET_SQUE(dtqcb)			(&(dtqcb)->sque)


/* rque */
#define _KERNEL_DTQ_GET_RQUE(dtqcb)			(&(dtqcb)->rque)


/* sdtqcnt */
#if _KERNEL_DTQCB_SDTQCNT
#define _KERNEL_DTQ_SET_SDTQCNT(dtqcb, x)	do { (dtqcb)->sdtqcnt = (_KERNEL_DTQCB_T_DTQCNT)(x); } while (0)
#define _KERNEL_DTQ_GET_SDTQCNT(dtqcb)		((_KERNEL_DTQ_T_DTQCNT)(dtqcb)->sdtqcnt)
#else
#define _KERNEL_DTQ_SET_SDTQCNT(dtqcb, x)	do { } while (0)
#define _KERNEL_DTQ_GET_SDTQCNT(dtqcb)		(0)
#endif


/* head */
#if _KERNEL_DTQCB_HEAD
#define _KERNEL_DTQ_SET_HEAD(dtqcb, x)		do { (dtqcb)->head = (_KERNEL_DTQCB_T_DTQCNT)(x); } while (0)
#define _KERNEL_DTQ_GET_HEAD(dtqcb)			((_KERNEL_DTQ_T_DTQCNT)(dtqcb)->head)
#else
#define _KERNEL_DTQ_SET_HEAD(dtqcb, x)		do { } while (0)
#define _KERNEL_DTQ_GET_HEAD(dtqcb)			(0)
#endif


/* dtqatr */
#if _KERNEL_DTQCB_DTQATR
#define _KERNEL_DTQ_SET_DTQATR(dtqcb, x)	do { (dtqcb)->dtqatr = (_KERNEL_DTQCB_T_DTQATR)(x); } while (0)
#define _KERNEL_DTQ_GET_DTQATR(dtqcb)		((_KERNEL_DTQ_T_DTQATR)(dtqcb)->dtqatr)
#else
#define _KERNEL_DTQ_SET_DTQATR(dtqcb, x)	do { } while (0)
#if _KERNEL_SPT_DTQ_TA_TFIFO
#define _KERNEL_DTQ_GET_DTQATR(dtqcb)		(TA_TFIFO)
#else
#define _KERNEL_DTQ_GET_DTQATR(dtqcb)		(TA_TPRI)
#endif
#endif


/* dtqcnt */
#if _KERNEL_DTQCB_DTQCNT
#define _KERNEL_DTQ_SET_DTQCNT(dtqcb_ro, x)	do { (dtqcb_ro)->dtqcnt = (_KERNEL_DTQCB_T_DTQCNT)(x); } while (0)
#define _KERNEL_DTQ_GET_DTQCNT(dtqcb_ro)	((_KERNEL_DTQ_T_DTQCNT)(dtqcb_ro)->dtqcnt)
#else
#define _KERNEL_DTQ_SET_DTQCNT(dtqcb_ro, x)	do { } while (0)
#define _KERNEL_DTQ_GET_DTQCNT(dtqcb_ro)	(0)
#endif


/* dtq */
#if _KERNEL_DTQCB_DTQ
#define _KERNEL_DTQ_SET_DTQ(dtqcb_ro, x)	do { (dtqcb_ro)->dtq = (VP_INT *)(x); } while (0)
#define _KERNEL_DTQ_GET_DTQ(dtqcb_ro)		((VP_INT *)(dtqcb_ro)->dtq)
#else
#define _KERNEL_DTQ_SET_DTQ(dtqcb_ro, x)	do { } while (0)
#define _KERNEL_DTQ_GET_DTQ(dtqcb_ro)		(0)
#endif



/* ------------------------------------------ */
/*   Macro functions                          */
/* ------------------------------------------ */

/* %jp{キュー接続} */
#if _KERNEL_SPT_DTQ_TA_TFIFO && _KERNEL_SPT_DTQ_TA_TPRI		/* %jp{TA_TFIFO と TA_TPRI の混在 } */
#define _KERNEL_DTQ_ADD_SQUE(dtqcb, dtqcb_ro, tskhdl)	_KERNEL_ADD_QUE(_KERNEL_DTQ_GET_SQUE(dtqcb), tskhdl, _KERNEL_DTQ_GET_DTQATR(dtqcb_ro))
#define _KERNEL_DTQ_ADD_RQUE(dtqcb, dtqcb_ro, tskhdl)	_KERNEL_ADD_QUE(_KERNEL_DTQ_GET_RQUE(dtqcb), tskhdl, _KERNEL_DTQ_GET_DTQATR(dtqcb_ro))
#elif _KERNEL_SPT_DTQ_TA_TFIFO && !_KERNEL_SPT_SE_TA_TPRI	/* %jp{TA_TFIFO のみ利用 } */
#define _KERNEL_DTQ_ADD_SQUE(dtqcb, dtqcb_ro, tskhdl)	_KERNEL_ADF_QUE(_KERNEL_DTQ_GET_SQUE(dtqcb), tskhdl)
#define _KERNEL_DTQ_ADD_RQUE(dtqcb, dtqcb_ro, tskhdl)	_KERNEL_ADF_QUE(_KERNEL_DTQ_GET_RQUE(dtqcb), tskhdl)
#elif !_KERNEL_SPT_DTQ_TA_TFIFO && _KERNEL_SPT_DTQ_TA_TPRI	/* %jp{TA_TPRI のみ利用 } */
#define _KERNEL_DTQ_ADD_SQUE(dtqcb, dtqcb_ro, tskhdl)	_KERNEL_ADP_QUE(_KERNEL_DTQ_GET_SQUE(dtqcb), tskhdl)
#define _KERNEL_DTQ_ADD_RQUE(dtqcb, dtqcb_ro, tskhdl)	_KERNEL_ADP_QUE(_KERNEL_DTQ_GET_RQUE(dtqcb), tskhdl)
#else
#error error:_KERNEL_SPT_DTQ_TA_TPRI and _KERNEL_SPT_DTQ_TA_TFIFO
#endif

/* %jp{キュー取り外し} */
#define _KERNEL_DTQ_RMV_SQUE(dtqcb, tskhdl)		_KERNEL_RMV_QUE(_KERNEL_DTQ_GET_SQUE(dtqcb), tskhdl)
#define _KERNEL_DTQ_RMV_RQUE(dtqcb, tskhdl)		_KERNEL_RMV_QUE(_KERNEL_DTQ_GET_RQUE(dtqcb), tskhdl)

/* %jp{キュー先頭取り出し} */
#define _KERNEL_DTQ_RMH_SQUE(dtqcb)				_KERNEL_RMH_QUE(_KERNEL_DTQ_GET_SQUE(dtqcb))
#define _KERNEL_DTQ_RMH_RQUE(dtqcb)				_KERNEL_RMH_QUE(_KERNEL_DTQ_GET_RQUE(dtqcb))


/* %jp{タイムアウトキュー操作} */
#if _KERNEL_SPT_TSND_DTQ	/* %jp{tsnd_dtqサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_DTQ_ADD_STOQ(tskhdl, tmout)		_KERNEL_SYS_ADD_TOQ(tskhdl, tmout)
#define _KERNEL_DTQ_RMV_STOQ(tskhdl)			_KERNEL_SYS_RMV_TOQ(tskhdl)
#else
#define _KERNEL_DTQ_ADD_STOQ(tskhdl)			do { } while (0)
#define _KERNEL_DTQ_RMV_STOQ(tskhdl)			do { } while (0)
#endif

#if _KERNEL_SPT_TRCV_DTQ	/* %jp{trcv_dtqサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_DTQ_ADD_RTOQ(tskhdl, tmout)		_KERNEL_SYS_ADD_TOQ(tskhdl, tmout)
#define _KERNEL_DTQ_RMV_RTOQ(tskhdl)			_KERNEL_SYS_RMV_TOQ(tskhdl)
#else
#define _KERNEL_DTQ_ADD_RTOQ(tskhdl)			do { } while (0)
#define _KERNEL_DTQ_RMV_RTOQ(tskhdl)			do { } while (0)
#endif



/* ------------------------------------------ */
/*   Functions                                */
/* ------------------------------------------ */

#ifdef __cplusplus
extern "C" {
#endif

ER _kernel_cre_dtq(ID dtqid, const T_CDTQ *pk_cdtq);		/**< %jp{データキュー生成}%en{Create Data queue} */
ER _kernel_snd_dtq(ID dtqid, VP_INT data, TMO tmout);		/**< %jp{データキューへの送信(統合版)}%en{Send Data Queue} */
ER _kernel_rcv_dtq(ID dtqid, VP_INT *p_data, TMO tmout);	/**< %jp{データキューから受信(統合版)}%en{Receive from Data Queue} */

#ifdef __cplusplus
}
#endif




#endif	/* _KERNEL__object__dtqobj_h__ */


/* end of file */
