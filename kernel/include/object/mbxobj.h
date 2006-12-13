/**
 *  Hyper Operating System V4 Advance
 *
 * @file  mbxobj.h
 * @brief %jp{メールボックスオジェクトのヘッダファイル}%en{Mailbox object heder file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__mbxobj_h__
#define _KERNEL__object__mbxobj_h__



/* ------------------------------------------ */
/*  type definition                           */
/* ------------------------------------------ */

/* %jp{メールボックス属性用の型(4bit必要)} */
#if _KERNEL_MBXCB_BITFIELD		/* %jp{MBXCBにビットフィールドを利用する場合} */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_LEAST_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_MBX_T_MBXATR;			/**< %jp{メールボックス属性を演算操作するときの型} */
typedef signed int						_KERNEL_MBXCB_T_MBXATR;			/**< %jp{メールボックス属性をMBXCBに格納するときの型} */
#define _KERNEL_MBXCB_TBITDEF_MBXATR	: 3 + 1							/**< %jp{メールボックス属性のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_MBX_T_MBXATR;			/**< %jp{メールボックス属性を演算操作するときの型} */
typedef unsigned int					_KERNEL_MBXCB_T_MBXATR;			/**< %jp{メールボックス属性をMBXCBに格納するときの型} */
#define _KERNEL_MBXCB_TBITDEF_MBXATR	: 3								/**< %jp{メールボックス属性のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{MBXCBにビットフィールドを利用しない場合} */

#if _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_MBX_T_MBXATR;			/**< %jp{メールボックス属性を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_MBXCB_T_MBXATR;			/**< %jp{メールボックス属性をMBXCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UB				_KERNEL_MBX_T_MBXATR;			/**< %jp{メールボックス属性を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_MBXCB_T_MBXATR;			/**< %jp{メールボックス属性をMBXCBに格納するときの型} */
#endif

#define _KERNEL_MBXCB_TBITDEF_MBXATR									/**< %jp{メールボックス属性のビットフィールド宣言時の幅} */

#endif


typedef	PRI		_KERNEL_MBX_T_MPRI;
typedef	PRI		_KERNEL_MBXCB_T_MPRI;
#define _KERNEL_MBXCB_TBITDEF_MPRI



/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

#if _KERNEL_MBXCB_SPLIT_RO

/** %jp{メールボックスコントロールブロック(リードオンリー部)} */
typedef struct _kernel_t_mbxcb_rom
{
#if _KERNEL_MBXCB_MBXATR
	_KERNEL_MBXCB_T_MBXATR	mbxatr		_KERNEL_MBXCB_TBITDEF_MBXATR;		/**< %jp{メールボックス属性} */
#endif

#if _KERNEL_MBXCB_MAXMPRI
	_KERNEL_MBXCB_T_MPRI	maxmpri		_KERNEL_MBXCB_TBITDEF_MPRI;			/**< %jp{送信されるメッセージの優先度の最大値} */
#endif
} _KERNEL_T_MBXCB_RO;

typedef const _KERNEL_T_MBXCB_RO	*_KERNEL_T_MBXCB_RO_PTR;


/** %jp{メールボックスコントロールブロック} */
typedef struct _kernel_t_mbxcb
{
#if _KERNEL_MBXCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{タスクの待ち行列} */
#endif

#if _KERNEL_MBXCB_MSGQUE
	VP						msgque;											/**< %jp{メッセージキュー} */
#endif

#if _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_PTRARRAY
	_KERNEL_T_MBXCB_RO_PTR	mbxcb_ro;										/**< %jp{コントロールブロックRO部へのポインタ} */
#endif
} _KERNEL_T_MBXCB;

typedef _KERNEL_T_MBXCB				*_KERNEL_T_MBXCB_PTR;


#else


/** %jp{メールボックスコントロールブロック} */
typedef struct _kernel_t_mbxcb
{
#if _KERNEL_MBXCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{タスクの待ち行列} */
#endif

#if _KERNEL_MBXCB_MSGQUE
	VP						msgque;											/**< %jp{メッセージキュー} */
#endif

#if _KERNEL_MBXCB_MBXATR
	_KERNEL_MBXCB_T_MBXATR	mbxatr		_KERNEL_MBXCB_TBITDEF_MBXATR;		/**< %jp{メールボックス属性} */
#endif

#if _KERNEL_MBXCB_MAXMPRI
	_KERNEL_MBXCB_T_MPRI	maxmpri		_KERNEL_MBXCB_TBITDEF_MPRI;			/**< %jp{送信されるメッセージの優先度の最大値} */
#endif
} _KERNEL_T_MBXCB;

typedef	_KERNEL_T_MBXCB				_KERNEL_T_MBXCB_RO;
typedef const _KERNEL_T_MBXCB_RO	*_KERNEL_T_MBXCB_RO_PTR;
typedef	_KERNEL_T_MBXCB				*_KERNEL_T_MBXCB_PTR;


#endif



/* ------------------------------------------ */
/*  ID range                                  */
/* ------------------------------------------ */

extern const ID							_kernel_max_mbxid;										/**< %jp{メールボックスIDの最大値} */

#define _KERNEL_MBX_TMIN_ID				1														/**< %jp{メールボックスIDの最小値} */
#define _KERNEL_MBX_TMAX_ID				(_kernel_max_mbxid)										/**< %jp{メールボックスIDの最大値} */

#define _KERNEL_MBX_CHECK_MBXID(mbxid)	((mbxid) >= _KERNEL_MBX_TMIN_ID && (mbxid) <= _KERNEL_MBX_TMAX_ID)



/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */

#if _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_BLKARRAY
#if _KERNEL_MBXCB_SPLIT_RO

/* %jp{ブロック配列管理でRO分離の場合}%en{block array} */
extern  _KERNEL_T_MBXCB					_kernel_mbxcb_tbl[];									/**< %jp{メールボックスコントロールブロックテーブル} */
extern const _KERNEL_T_MBXCB_RO			_kernel_mbxcb_ro_tbl[];									/**< %jp{メールボックスコントロールブロック(リードオンリー部)テーブル} */
#define _KERNEL_MBX_ID2MBXCB(mbxid)		(&_kernel_mbxcb_tbl[(mbxid) - _KERNEL_MBX_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_MBX_CHECK_EXS(mbxid)	(_kernel_mbxcb_ro_tbl[(mbxid) - _KERNEL_MBX_TMIN_ID].mbxatr & _KERNEL_MBX_TA_CRE)
																								/**< %jp{オブジェクトの存在チェック} */
#define _KERNEL_MBX_TA_CRE				0x08													/**< %jp{mbxatrのビットに生成済みbitを割り当て} */

#else

/* %jp{ブロック配列管理の場合}%en{block array} */
extern  _KERNEL_T_MBXCB					_kernel_mbxcb_tbl[];									/**< %jp{メールボックスコントロールブロックテーブル} */
#define _KERNEL_MBX_ID2MBXCB(mbxid)		(&_kernel_mbxcb_tbl[(mbxid) - _KERNEL_MBX_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_MBX_CHECK_EXS(mbxid)	(_kernel_mbxcb_tbl[(mbxid) - _KERNEL_MBX_TMIN_ID].mbxatr & _KERNEL_MBX_TA_CRE)
																								/**< %jp{オブジェクトの存在チェック} */
#define _KERNEL_MBX_TA_CRE				0x08													/**< %jp{mbxatrのビットに生成済みbitを割り当て} */

#endif

#elif _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_PTRARRAY

/* %jp{ポインタ配列管理の場合}%en{pointer array} */
extern  _KERNEL_T_MBXCB					*_kernel_mbxcb_tbl[];									/**< %jp{メールボックスコントロールブロックテーブル} */
#define _KERNEL_MBX_ID2MBXCB(mbxid)		(_kernel_mbxcb_tbl[(mbxid) - _KERNEL_MBX_TMIN_ID])		/**< %jp{メールボックスIDからMBXCB アドレスを取得} */
#define _KERNEL_MBX_CHECK_EXS(mbxid)	(_KERNEL_MBX_ID2MBXCB(mbxid) != NULL)					/**< %jp{オブジェクトの存在チェック} */
#define _KERNEL_MBX_TA_CRE				0

#else

#error error: _KERNEL_MBXCB_ALGORITHM

#endif



/* ------------------------------------------ */
/*   Accessor for MBXCB                       */
/* ------------------------------------------ */

/* mbxcb_ro */
#if !_KERNEL_MBXCB_SPLIT_RO								
#define _KERNEL_MBX_GET_MBXCB_RO(mbxid, mbxcb)	(mbxcb)
#else
#if _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_BLKARRAY		/* %jp{MBXCBを単純配列で管理}%en{array of block} */
#define _KERNEL_MBX_GET_MBXCB_RO(mbxid, mbxcb)	(&_kernel_mbxcb_ro_tbl[(mbxid)])
#elif _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_PTRARRAY		/* %jp{MBXCBをポインタ配列で管理}%en{array of pointer} */
#define _KERNEL_MBX_GET_MBXCB_RO(mbxid, mbxcb)	((mbxcb)->mbxcb_ro)
#endif
#endif


/* que */
#define _KERNEL_MBX_GET_QUE(mbxcb)				(&(mbxcb)->que)

/* mbxptn */
#if _KERNEL_MBXCB_MSGQUE
#define _KERNEL_MBX_SET_MSGQUE(mbxcb, x)		do { (mbxcb)->msgque = (VP)(x); } while (0)
#define _KERNEL_MBX_GET_MSGQUE(mbxcb)			((VP)&(mbxcb)->msgque)
#else
#define _KERNEL_MBX_SET_MSGQUE(mbxcb, x)		do { } while (0)
#define _KERNEL_MBX_GET_MSGQUE(mbxcb)			(0)
#endif


/* mbxatr */
#if _KERNEL_MBXCB_MBXATR
#define _KERNEL_MBX_SET_MBXATR(mbxcb_ro, x)		do { (mbxcb_ro)->mbxatr = (_KERNEL_MBXCB_T_MBXATR)(x); } while (0)
#define _KERNEL_MBX_GET_MBXATR(mbxcb_ro)		((_KERNEL_MBX_T_MBXATR)(mbxcb_ro)->mbxatr)
#else
#define _KERNEL_MBX_SET_MBXATR(mbxcb_ro, x)		do { } while (0)
#if _KERNEL_SPT_MBX_TA_TFIFO && _KERNEL_SPT_MBX_TA_MFIFO
#define _KERNEL_MBX_GET_MBXATR(mbxcb_ro)		(TA_TFIFO | TA_MFIFO)
#elif _KERNEL_SPT_MBX_TA_TFIFO && _KERNEL_SPT_MBX_TA_MPRI
#define _KERNEL_MBX_GET_MBXATR(mbxcb_ro)		(TA_TFIFO | TA_MPRI)
#elif _KERNEL_SPT_MBX_TA_MPRI && _KERNEL_SPT_MBX_TA_MFIFO
#define _KERNEL_MBX_GET_MBXATR(mbxcb_ro)		(TA_TFIFO | TA_FIFO)
#else
#define _KERNEL_MBX_GET_MBXATR(mbxcb_ro)		(TA_TPRI | TA_MPRI)
#endif
#endif

/* maxmpri */
#if _KERNEL_MBXCB_MAXMPRI
#define _KERNEL_MBX_SET_MAXMPRI(mbxcb_ro, x)	do { (mbxcb_ro)->maxmpri = (_KERNEL_MBXCB_T_MPRI)(x); } while (0)
#define _KERNEL_MBX_GET_MAXMPRI(mbxcb_ro)		((_KERNEL_MBX_T_MPRI)(mbxcb_ro)->maxmpri)
#else
#define _KERNEL_MBX_SET_MAXMPRI(mbxcb_ro, x)	do { } while (0)
#define _KERNEL_MBX_GET_MAXMPRI(mbxcb_ro)		(1)
#endif




/* ------------------------------------------ */
/*   Macro functions                          */
/* ------------------------------------------ */

/* %jp{キュー接続} */
#if _KERNEL_SPT_MBX_TA_TFIFO && _KERNEL_SPT_MBX_TA_TPRI		/* %jp{TA_TFIFOとTA_TPRI両方対応(属性で判定)} */
#define _KERNEL_MBX_ADD_QUE(mbxcb, mbxcb_ro, tskhdl)	_KERNEL_ADD_QUE(_KERNEL_MBX_GET_QUE(mbxcb), tskhdl, _KERNEL_MBX_GET_MBXATR(mbxcb_ro))
#elif _KERNEL_SPT_MBX_TA_TFIFO && !_KERNEL_SPT_SE_TA_TPRI	/* %jp{TA_TFIFO のみ利用 } */
#define _KERNEL_MBX_ADD_QUE(mbxcb, mbxcb_ro, tskhdl)	_KERNEL_ADF_QUE(_KERNEL_MBX_GET_QUE(mbxcb), tskhdl)
#elif !_KERNEL_SPT_MBX_TA_TFIFO && _KERNEL_SPT_MBX_TA_TPRI	/* %jp{TA_TPRI のみ利用 } */
#define _KERNEL_MBX_ADD_QUE(mbxcb, mbxcb_ro, tskhdl)	_KERNEL_ADP_QUE(_KERNEL_MBX_GET_QUE(mbxcb), tskhdl)
#else
#error error:_KERNEL_SPT_MBX_TA_TPRI and _KERNEL_SPT_MBX_TA_TFIFO
#endif

/* %jp{キュー取り外し} */
#define _KERNEL_MBX_RMV_QUE(mbxcb, tskhdl)	_KERNEL_RMV_QUE(_KERNEL_MBX_GET_QUE(mbxcb), tskhdl)

/* %jp{キュー先頭取り出し} */
#define _KERNEL_MBX_RMH_QUE(mbxcb)			_KERNEL_RMH_QUE(_KERNEL_MBX_GET_QUE(mbxcb))


/* %jp{タイムアウトキュー操作} */
#if _KERNEL_SPT_TRCV_MBX	/* %jp{trcv_mbxサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_MBX_ADD_TOQ(tskhdl, tmout)	_KERNEL_SYS_ADD_TOQ(tskhdl, tmout)
#define _KERNEL_MBX_RMV_TOQ(tskhdl)			_KERNEL_SYS_RMV_TOQ(tskhdl)
#else
#define _KERNEL_MBX_ADD_TOQ(tskhdl)			do { } while (0)
#define _KERNEL_MBX_RMV_TOQ(tskhdl)			do { } while (0)
#endif


/* %jp{メッセージキュー操作} */
#if _KERNEL_SPT_MBX_TA_MFIFO && _KERNEL_SPT_MBX_TA_MPRI		/* %jp{TA_MFIFOとTA_MPRI両方対応(属性で判定)} */
#define _KERNEL_MBX_ADD_MSG(mbxcb, mbxcb_ro, pk_msg)	do { if ( _KERNEL_MBX_GET_MBXATR(mbxcb_ro) & TA_MPRI ) { _kernel_adp_msg((mbxcb), (pk_msg)); } else { _kernel_adf_msg((mbxcb), (pk_msg)); }} while(0)
#define _KERNEL_MBX_RMV_MSG(mbxcb, mbxcb_ro)			(_KERNEL_MBX_GET_MBXATR(mbxcb_ro) & TA_MPRI ? _kernel_rmp_msg((mbxcb), _KERNEL_MBX_GET_MAXMPRI(mbxcb_ro)) : _kernel_rmf_msg(mbxcb))
#elif _KERNEL_SPT_MBX_TA_MFIFO && !_KERNEL_SPT_MBX_TA_MPRI	/* %jp{TA_MFIFO のみ利用 } */
#define _KERNEL_MBX_ADD_MSG(mbxcb, mbxcb_ro, pk_msg)	_kernel_adf_msg((mbxcb), (pk_msg))
#define _KERNEL_MBX_RMV_MSG(mbxcb, mbxcb_ro)			_kernel_rmf_msg(mbxcb)
#elif !_KERNEL_SPT_MBX_TA_MFIFO && _KERNEL_SPT_MBX_TA_MPRI	/* %jp{TA_MPRI のみ利用 } */
#define _KERNEL_MBX_ADD_MSG(mbxcb, mbxcb_ro, pk_msg)	_kernel_adp_msg((mbxcb), (pk_msg))
#define _KERNEL_MBX_RMV_MSG(mbxcb, mbxcb_ro)			_kernel_rmp_msg((mbxcb), _KERNEL_MBX_GET_MAXMPRI(mbxcb_ro))
#else
#error error:_KERNEL_SPT_MBX_TA_MPRI and _KERNEL_SPT_MBX_TA_MFIFO
#endif

#ifdef __cplusplus
extern "C" {
#endif

ER     _kernel_cre_mbx(ID mbxid, const T_CMBX *pk_cmbx);							/**< %jp{メールボックスを生成} */
void   _kernel_adf_msg(_KERNEL_T_MBXCB_PTR mbxcb, T_MSG *pk_msg);					/**< %jp{FIFOキューにメッセージを追加} */
void   _kernel_adp_msg(_KERNEL_T_MBXCB_PTR mbxcb, T_MSG *pk_msg);					/**< %jp{優先度キューにメッセージを追加} */
void   _kernel_add_msq(T_MSG **ppk_msgque, T_MSG *pk_msg);							/**< %jp{メッセージキューへのメッセージ追加} */
T_MSG *_kernel_rmf_msg(_KERNEL_T_MBXCB_PTR mbxcb);									/**< %jp{FIFOキューからメッセージを取り出し} */
T_MSG *_kernel_rmp_msg(_KERNEL_T_MBXCB_PTR mbxcb, _KERNEL_MBXCB_T_MPRI maxmpri);	/**< %jp{優先度キューからメッセージを取り出し} */
T_MSG *_kernel_rmv_msq(T_MSG **ppk_msgque);											/**< %jp{メッセージキューからメッセージ取り出し} */

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__mbxobj_h__ */



/* end of file */
