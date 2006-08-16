/**
 *  Hyper Operating System V4 Advance
 *
 * @file  mbxobj.h
 * @brief %jp{メールボックスオジェクトのヘッダファイル}%en{Mailbox object heder file}
 *
 * @version $Id: mbxobj.h,v 1.2 2006-08-16 18:31:05 ryuz Exp $
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
#if _KERNEL_MBXCB_BITFIELD		/* %jp{MBXCBにビットフィールドを利用する場合 */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_MBX_T_MBXATR;			/**< %jp{メールボックス属性を演算操作するときの型} */
typedef signed int						_KERNEL_MBXCB_T_MBXATR;			/**< %jp{メールボックス属性をMBXCBに格納するときの型} */
#define _KERNEL_TBITDEF_MBXCB_MBXATR	: 3 + 1							/**< %jp{メールボックス属性のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_MBX_T_MBXATR;			/**< %jp{メールボックス属性を演算操作するときの型} */
typedef unsigned int					_KERNEL_MBXCB_T_MBXATR;			/**< %jp{メールボックス属性をMBXCBに格納するときの型} */
#define _KERNEL_TBITDEF_MBXCB_MBXATR	: 3								/**< %jp{メールボックス属性のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{MBXCBにビットフィールドを利用しない場合 */

#if _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_MBX_T_MBXATR;			/**< %jp{メールボックス属性を演算操作するときの型} */
typedef _KERNEL_T_OPT_B					_KERNEL_MBXCB_T_MBXATR;			/**< %jp{メールボックス属性をMBXCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UB				_KERNEL_MBX_T_MBXATR;			/**< %jp{メールボックス属性を演算操作するときの型} */
typedef _KERNEL_T_OPT_UB				_KERNEL_MBXCB_T_MBXATR;			/**< %jp{メールボックス属性をMBXCBに格納するときの型} */
#endif

#define _KERNEL_MBXCB_TBITDEF_MBXATR									/**< %jp{メールボックス属性のビットフィールド宣言時の幅} */

#endif


typedef	PRI		_KERNEL_MBX_T_MPRI;
typedef	PRI		_KERNEL_MBXCB_T_MPRI;
#define _KERNEL_MBXCB_TBITDEF_MPRI



/* ------------------------------------------ */
/*  Eventflag control block                   */
/* ------------------------------------------ */

#if _KERNEL_MBXCB_ROM

/** %jp{メールボックスコントロールブロック(ROM部)} */
typedef struct _kernel_t_mbxcb_rom
{
#if _KERNEL_MBXCB_MBXATR
	_KERNEL_MBXCB_T_MBXATR	mbxatr		_KERNEL_TBITDEF_MBXCB_MBXPTN;		/**< %jp{メールボックス属性} */
#endif

#if _KERNEL_MBXCB_MAXMPRI
	_KERNEL_MBXCB_T_MAXMPRI	maxmpri		_KERNEL_TBITDEF_MBXCB_MAXMPRI;		/**< %jp{送信されるメッセージの優先度の最大値} */
#endif

} _KERNEL_MBXCB_T_ROM;


/** %jp{メールボックスコントロールブロック(RAM部)} */
typedef struct _kernel_t_mbxcb
{
#if _KERNEL_MBXCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{タスクの待ち行列} */
#endif

#if _KERNEL_MBXCB_MSGQUE
	VP						msgque;											/**< %jp{メッセージキュー} */
#endif
} _KERNEL_T_MBXCB;


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

#endif



/* Eventflag handle */
typedef _KERNEL_T_MBXCB*				_KERNEL_T_MBXHDL;



#if _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_BLKARRAY			/* block array */

extern const ID							_kernel_max_mbxid;					/** %jp{メールボックスコントロールブロック個数} */
extern       _KERNEL_T_MBXCB			_kernel_mbxcb_tbl[];				/** %jp{メールボックスコントロールブロックテーブル} */

#define _KERNEL_MBX_ID2MBXCB(mbxid)		(&_kernel_mbxcb_tbl[(mbxid) - _KERNEL_TMIN_MBX_ID])
#define _KERNEL_MBX_ID2MBXHDL(mbxid)	_KERNEL_MBX_ID2MBXCB(mbxid)


/* %jp{オブジェクトの存在チェック} */
#define _KERNEL_MBX_CHECK_EXS(mbxid)	(_KERNEL_MBX_ID2MBXCB(mbxid)->mbxatr & _KERNEL_MBX_TA_CRE)
#define _KERNEL_MBX_TA_CRE				0x08


#elif _KERNEL_MBXCB_ALGORITHM == _KERNEL_MBXCB_ALG_PTRARRAY		/* pointer array */

extern const ID							_kernel_max_mbxid;					/** %jp{メールボックスコントロールブロック個数} */
extern       _KERNEL_T_MBXCB			*_kernel_mbxcb_tbl[];				/** %jp{メールボックスコントロールブロックテーブル} */

#define _KERNEL_MBX_ID2MBXCB(mbxid)		(_kernel_mbxcb_tbl[(mbxid) - _KERNEL_TMIN_MBX_ID])
#define _KERNEL_MBX_ID2MBXHDL(mbxid)	_KERNEL_MBX_ID2MBXCB(mbxid)
																	/** %jp{セマフォIDからMBXCB アドレスを取得} */

/* %jp{オブジェクトの存在チェック} */
#define _KERNEL_MBX_CHECK_EXS(mbxid)	(_KERNEL_MBX_ID2MBXCB(mbxid) != NULL)
#define _KERNEL_MBX_TA_CRE				0

#endif


/* %jp{ID範囲定義} */
#define _KERNEL_TMIN_MBX_ID				1
#define _KERNEL_TMAX_MBX_ID				(_kernel_max_mbxid)


/* %jp{ID範囲チェック} */
#define _KERNEL_MBX_CHECK_MBXID(mbxid)	((mbxid) >= _KERNEL_TMIN_MBX_ID && (mbxid) <= _KERNEL_TMAX_MBX_ID)




/* ------------------------------------------ */
/*   Accessor for MBXCB                       */
/* ------------------------------------------ */

/* que */
#define _KERNEL_MBX_GET_QUE(mbxhdl)			(&(mbxhdl)->que)

/* mbxptn */
#if _KERNEL_MBXCB_MSGQUE
#define _KERNEL_MBX_SET_MSGQUE(mbxhdl, x)	do { (mbxhdl)->msgque = (VP)(x); } while (0)
#define _KERNEL_MBX_GET_MSGQUE(mbxhdl)		((VP)&(mbxhdl)->msgque)
#else
#define _KERNEL_MBX_SET_MSGQUE(mbxhdl, x)	do { } while (0)
#define _KERNEL_MBX_GET_MSGQUE(mbxhdl)		(0)
#endif

/* mbxatr */
#if _KERNEL_MBXCB_MBXATR
#define _KERNEL_MBX_SET_MBXATR(mbxhdl, x)	do { (mbxhdl)->mbxatr = (_KERNEL_MBXCB_T_MBXATR)(x); } while (0)
#define _KERNEL_MBX_GET_MBXATR(mbxhdl)		((_KERNEL_MBX_T_MBXATR)(mbxhdl)->mbxatr)
#else
#define _KERNEL_MBX_SET_MBXATR(mbxhdl, x)	do { } while (0)
#if _KERNEL_SPT_MBX_TA_TFIFO
#define _KERNEL_MBX_GET_MBXATR(mbxhdl)		(TA_TFIFO)
#else
#define _KERNEL_MBX_GET_MBXATR(mbxhdl)		(TA_TPRI)
#endif
#endif

#if _KERNEL_MBXCB_MAXMPRI
#define _KERNEL_MBX_SET_MAXMPRI(mbxhdl, x)	do { (mbxhdl)->maxmpri = (_KERNEL_MBXCB_T_MPRI)(x); } while (0)
#define _KERNEL_MBX_GET_MAXMPRI(mbxhdl)		((_KERNEL_MBX_T_MPRI)(mbxhdl)->maxmpri)
#else
#define _KERNEL_MBX_SET_MAXMPRI(mbxhdl, x)	do { } while (0)
#define _KERNEL_MBX_GET_MAXMPRI(mbxhdl)		(1)
#endif



/* %jp{キュー接続} */
#if _KERNEL_SPT_MBX_TA_TFIFO && _KERNEL_SPT_MBX_TA_TPRI		/* %jp{TA_TFIFO と TA_TPRI の混在 } */
#define _KERNEL_MBX_ADD_QUE(mbxhdl, tskhdl)		_kernel_add_que(_KERNEL_MBX_GET_QUE(mbxhdl), tskhdl, _KERNEL_MBX_GET_MBXATR(mbxhdl))
#elif _KERNEL_SPT_MBX_TA_TFIFO && !_KERNEL_SPT_MBX_TA_TPRI	/* %jp{TA_TFIFO のみ利用 } */
#define _KERNEL_MBX_ADD_QUE(mbxhdl, tskhdl)		_kernel_adf_que(_KERNEL_MBX_GET_QUE(mbxhdl), tskhdl)
#elif !_KERNEL_SPT_MBX_TA_TFIFO && _KERNEL_SPT_MBX_TA_TPRI	/* %jp{TA_TPRI のみ利用 } */
#define _KERNEL_MBX_ADD_QUE(mbxhdl, tskhdl)		_kernel_adp_que(_KERNEL_MBX_GET_QUE(mbxhdl), tskhdl)
#else
#error error:_KERNEL_SPT_MBX_TA_TPRI and _KERNEL_SPT_MBX_TA_TFIFO
#endif

/* %jp{タイムアウトキュー解除} */
#if _KERNEL_SPT_TRCV_MBX	/* %jp{twai_semサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_MBX_RMV_TOQ(tskhdl)			_KERNEL_RMV_TOQ(tskhdl)
#else
#define _KERNEL_MBX_RMV_TOQ(tskhdl)			do { } while (0)
#endif



#ifdef __cplusplus
extern "C" {
#endif

ER     _kernel_cre_mbx(ID mbxid, const T_CMBX *pk_cmbx);
void   _kernel_add_msg(_KERNEL_T_MBXHDL mbxhdl, T_MSG *pk_msg);
T_MSG *_kernel_rmv_msg(_KERNEL_T_MBXHDL mbxhdl);

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__mbxobj_h__ */



/* end of file */
