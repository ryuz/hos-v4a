/**
 *  Hyper Operating System V4 Advance
 *
 * @file  mpfobj.h
 * @brief %en{Semaphore object heder file}%jp{固定長メモリプールオジェクトのヘッダファイル}
 *
 * @version $Id: mpfobj.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__object__mpfobj_h__
#define _KERNEL__object__mpfobj_h__



/* ------------------------------------------ */
/*  type definition                           */
/* ------------------------------------------ */

/* %jp{固定長メモリプールブロック数の型} */
#if _KERNEL_MPFCB_BITFIELD		/* %jp{MPFCBにビットフィールドを利用する場合 */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef signed int						_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#define _KERNEL_MPFCB_TBITDEF_BLKCNT	: _KERNEL_MPF_TBIT_BLKCNT + 1	/**< %jp{固定長メモリプールブロック数のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef unsigned int					_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#define _KERNEL_MPFCB_TBITDEF_BLKCNT	: _KERNEL_MPF_TBIT_BLKCNT		/**< %jp{固定長メモリプールブロック数のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{MPFCBにビットフィールドを利用しない場合 */

#if (_KERNEL_MPF_TMAX_BLKCNT <= _KERNEL_TMAX_B) && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef _KERNEL_T_OPT_B					_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKCNT <= _KERNEL_TMAX_UB) && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef _KERNEL_T_OPT_UB				_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKCNT <= _KERNEL_TMAX_H) && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef _KERNEL_T_OPT_H					_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKCNT <= _KERNEL_TMAX_UH) && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef _KERNEL_T_OPT_UH				_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKCNT <= _KERNEL_TMAX_W) && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef _KERNEL_T_OPT_W					_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKCNT <= _KERNEL_TMAX_UW) && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef _KERNEL_T_OPT_UW				_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKCNT <= _KERNEL_TMAX_D) && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef _KERNEL_T_OPT_D					_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_MPF_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数を演算操作するときの型} */
typedef _KERNEL_T_OPT_UD				_KERNEL_MPFCB_T_BLKCNT;			/**< %jp{固定長メモリプールブロック数をMPFCBに格納するときの型} */
#endif

#define _KERNEL_MPFCB_TBITDEF_BLKCNT									/**< %jp{固定長メモリプールブロック数のビットフィールド宣言時の幅} */

#endif


/* %jp{固定長メモリプールブロックサイズの型} */
#if _KERNEL_MPFCB_BITFIELD		/* %jp{MPFCBにビットフィールドを利用する場合 */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef signed int						_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#define _KERNEL_MPFCB_TBITDEF_BLKSZ	: _KERNEL_MPF_TBIT_BLKSZ + 1		/**< %jp{固定長メモリプールブロックサイズのビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef unsigned int					_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#define _KERNEL_MPFCB_TBITDEF_BLKSZ	: _KERNEL_MPF_TBIT_BLKSZ			/**< %jp{固定長メモリプールブロックサイズのビットフィールド宣言時の幅} */
#endif

#else							/* %jp{MPFCBにビットフィールドを利用しない場合 */

#if (_KERNEL_MPF_TMAX_BLKSZ <= _KERNEL_TMAX_B) && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef _KERNEL_T_OPT_B					_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKSZ <= _KERNEL_TMAX_UB) && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef _KERNEL_T_OPT_UB				_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKSZ <= _KERNEL_TMAX_H) && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef _KERNEL_T_OPT_H					_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKSZ <= _KERNEL_TMAX_UH) && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef _KERNEL_T_OPT_UH				_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKSZ <= _KERNEL_TMAX_W) && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef _KERNEL_T_OPT_W					_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKSZ <= _KERNEL_TMAX_UW) && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef _KERNEL_T_OPT_UW				_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#elif (_KERNEL_MPF_TMAX_BLKSZ <= _KERNEL_TMAX_D) && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef _KERNEL_T_OPT_D					_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_MPF_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズを演算操作するときの型} */
typedef _KERNEL_T_OPT_UD				_KERNEL_MPFCB_T_BLKSZ;			/**< %jp{固定長メモリプールブロックサイズをMPFCBに格納するときの型} */
#endif

#define _KERNEL_MPFCB_TBITDEF_BLKSZ										/**< %jp{固定長メモリプールブロックサイズのビットフィールド宣言時の幅} */

#endif


/* %jp{固定長メモリプール属性用の型} */
#if _KERNEL_MPFCB_BITFIELD		/* %jp{MPFCBにビットフィールドを利用する場合 */

/* %jp{TA_TFIFO と TA_TPRI の判定に 1bit 必要} */
typedef unsigned int					_KERNEL_MPF_T_MPFATR;
typedef unsigned int					_KERNEL_MPFCB_T_MPFATR;
#define _KERNEL_MPFCB_TBITDEF_MPFATR	: 1

#else							/* %jp{MPFCBにビットフィールドを利用しない場合 */

typedef _KERNEL_T_FAST_UB				_KERNEL_MPF_T_MPFATR;
typedef _KERNEL_T_OPT_UB				_KERNEL_MPFCB_T_MPFATR;
#define _KERNEL_MPFCB_TBITDEF_MPFATR

#endif

typedef VP								_KERNEL_MPF_T_MPF;
typedef VP								_KERNEL_MPFCB_T_MPF;
#define _KERNEL_MPFCB_TBITDEF_MPF		


/* %jp{メモリブロックのハンドル} */
#if _KERNEL_MPF_ALGORITHM == _KERNEL_MPF_ALG_CHAIN_PTR		/* %jp{ポインタ管理} */

typedef VP								_KERNEL_MPF_T_BLKHDL;
typedef VP								_KERNEL_MPFCB_T_BLKHDL;
#define _KERNEL_MPFCB_TBITDEF_BLKHDL
#define _KERNEL_MPF_BLKHDL_NULL			NULL
#define _KERNEL_MPF_BLKHDL2PTR(mpfhdl, blkhdl)		(blkhdl)
#define _KERNEL_MPF_PTR2BLKHDL(mpfhdl, blkptr)		(blkptr)

#elif _KERNEL_MPF_ALGORITHM == _KERNEL_MPF_ALG_CHAIN_NUM	/* %jp{ブロック番号管理} */

typedef _KERNEL_MPF_T_BLKCNT			_KERNEL_MPF_T_BLKHDL;
typedef _KERNEL_MPFCB_T_BLKCNT			_KERNEL_MPFCB_T_BLKHDL;
#define _KERNEL_MPFCB_TBITDEF_BLKHDL	_KERNEL_MPFCB_TBITDEF_BLKCNT
#define _KERNEL_MPF_BLKHDL_NULL			0
#define _KERNEL_MPF_BLKHDL2PTR(mpfhdl, blkhdl)		((VP)((VB *)_KERNEL_MPF_GET_MPF(mpfhdl) + ((SIZE)((blkhdl) - 1) * (SIZE)_KERNEL_MPF_GET_BLKSZ(mpfhdl))))
#define _KERNEL_MPF_PTR2BLKHDL(mpfhdl, blkptr)		(((VB *)(blkptr) - (VB *)_KERNEL_MPF_GET_MPF(mpfhdl)) / _KERNEL_MPF_GET_BLKSZ(mpfhdl) + 1)

#endif


/* ------------------------------------------ */
/*  Control block                             */
/* ------------------------------------------ */

#if _KERNEL_MPFCB_ROM


/** %jp{固定長メモリプールコントロールブロック(ROM部)} */
typedef struct _kernel_t_mpfcb_rom
{
#if _KERNEL_MPFCB_MPFATR
	_KERNEL_MPFCB_T_MPFATR	mpfatr		_KERNEL_MPFCB_TBITDEF_MPFATR;		/**< %jp{固定長メモリプール属性} */
#endif

#if _KERNEL_MPFCB_BLKCNT
	_KERNEL_MPFCB_T_BLKCNT	blkcnt		_KERNEL_MPFCB_TBITDEF_BLKCNT;		/**< %jp{獲得できるメモリブロック数(個数)} */
#endif

#if _KERNEL_MPFCB_BLKSZ
	_KERNEL_MPFCB_T_BLKCNT	blksz		_KERNEL_MPFCB_TBITDEF_BLKSZ;		/**< %jp{メモリブロックのサイズ(バイト数)} */
#endif

#if _KERNEL_MPFCB_MPF
	_KERNEL_MPFCB_T_MPF		mpf			_KERNEL_MPFCB_TBITDEF_MPF;			/**< %jp{固定長メモリプール領域の先頭番地} */
#endif
} _KERNEL_MPFCB_T_ROM;

/** %jp{固定長メモリプールコントロールブロック(RAM部)} */
typedef struct _kernel_t_mpfcb
{
#if _KERNEL_MPFCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{固定長メモリプール待ちタスクキュー} */
#endif

#if _KERNEL_MPFCB_FREBLK
	_KERNEL_MPFCB_T_BLKHDL	freblk		_KERNEL_MPFCB_TBITDEF_BLKHDL;		/**< %jp{最初のメモリプールの空きメモリブロック位置} */
#endif

#if _KERNEL_MPFCB_FBLKCNT
	_KERNEL_MPFCB_T_BLKCNT	fblkcnt		_KERNEL_MPFCB_TBITDEF_BLKCNT;		/**< %jp{固定長メモリプールの空きメモリブロック数(個数)} */
#endif

#if _KERNEL_MPFCB_ALGORITHM == _KERNEL_MPFCB_ALG_PTRARRAY
	_KERNEL_MPFCB_T_ROM		*mpfcb_rom;										/**< %jp{固定長メモリプールコントロールブロックROM部へのポインタ} */
#endif
} _KERNEL_T_MPFCB;


#else


/** %jp{固定長メモリプールコントロールブロック} */
typedef struct _kernel_t_mpfcb
{
#if _KERNEL_MPFCB_QUE
	_KERNEL_T_QUE			que;											/**< %jp{固定長メモリプール待ちタスクキュー} */
#endif

#if _KERNEL_MPFCB_FREBLK
	_KERNEL_MPFCB_T_BLKHDL	freblk		_KERNEL_MPFCB_TBITDEF_BLKHDL;		/**< %jp{最初のメモリプールの空きメモリブロック位置} */
#endif

#if _KERNEL_MPFCB_FBLKCNT
	_KERNEL_MPFCB_T_BLKCNT	fblkcnt		_KERNEL_MPFCB_TBITDEF_BLKCNT;		/**< %jp{固定長メモリプールの空きメモリブロック数(個数)} */
#endif

#if _KERNEL_MPFCB_MPFATR
	_KERNEL_MPFCB_T_MPFATR	mpfatr		_KERNEL_MPFCB_TBITDEF_MPFATR;		/**< %jp{固定長メモリプール属性} */
#endif

#if _KERNEL_MPFCB_BLKCNT
	_KERNEL_MPFCB_T_BLKCNT	blkcnt		_KERNEL_MPFCB_TBITDEF_BLKCNT;		/**< %jp{獲得できるメモリブロック数(個数)} */
#endif

#if _KERNEL_MPFCB_BLKSZ
	_KERNEL_MPFCB_T_BLKSZ	blksz		_KERNEL_MPFCB_TBITDEF_BLKSZ;		/**< %jp{メモリブロックのサイズ(バイト数)} */
#endif

#if _KERNEL_MPFCB_MPF
	_KERNEL_MPFCB_T_MPF		mpf			_KERNEL_MPFCB_TBITDEF_MPF;			/**< %jp{固定長メモリプール領域の先頭番地} */
#endif
} _KERNEL_T_MPFCB;

#endif



/* Fixed memory pool handle */
typedef _KERNEL_T_MPFCB*				_KERNEL_T_MPFHDL;



#if _KERNEL_MPFCB_ALGORITHM == _KERNEL_MPFCB_ALG_BLKARRAY			/* block array */

extern       _KERNEL_T_MPFCB			_kernel_mpfcb_tbl[];			/** %jp{固定長メモリプールコントロールブロックテーブル} */
extern const ID							_kernel_max_mpfid;				/** %jp{固定長メモリプールコントロールブロック個数} */

#define _KERNEL_MPF_ID2MPFCB(mpfid)		(&_kernel_mpfcb_tbl[(mpfid) - _KERNEL_MPF_TMIN_ID])			/** %jp{固定長メモリプールIDからMPFCB アドレスを取得} */
#define _KERNEL_MPF_ID2MPFHDL(mpfid)	(&_kernel_mpfcb_tbl[(mpfid) - _KERNEL_MPF_TMIN_ID])

#define _KERNEL_MPF_MPFHDL2MPFCB(mpfhdl)	(mpfhdl)
#define _KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)	(mpfhdl)



/* %jp{オブジェクトの存在チェック} */
#define _KERNEL_MPF_CHECK_EXS(mpfid)	(_KERNEL_MPF_ID2MPFHDL(mpfid)->mpf != NULL)



#elif _KERNEL_MPFCB_ALGORITHM == _KERNEL_MPFCB_ALG_PTRARRAY		/* pointer array */

extern       _KERNEL_T_MPFCB			*_kernel_mpfcb_tbl[];			/**< %jp{固定長メモリプールコントロールブロックテーブル} */
extern const ID							_kernel_max_mpfid;				/**< %jp{固定長メモリプールコントロールブロック個数} */

#define _KERNEL_MPF_ID2MPFCB(mpfid)		(_kernel_mpfcb_tbl[(mpfid) - _KERNEL_MPF_TMIN_ID])
																		/**< %jp{固定長メモリプールIDからMPFCB アドレスを取得} */
#define _KERNEL_MPF_ID2MPFHDL(mpfid)	(_kernel_mpfcb_tbl[(mpfid) - _KERNEL_MPF_TMIN_ID])
																		/**< %jp{固定長メモリプールIDからMPFハンドルを取得} */

/* %jp{オブジェクトの存在チェック} */
#define _KERNEL_MPF_CHECK_EXS(mpfid)	(_KERNEL_MPF_ID2MPFHDL(mpfid) != NULL)

#endif



/* %jp{ID範囲定義} */
#define _KERNEL_MPF_TMIN_ID				1
#define _KERNEL_MPF_TMAX_ID				(_kernel_max_mpfid)

/* %jp{ID範囲チェック} */
#define _KERNEL_MPF_CHECK_MPFID(mpfid)	((mpfid) >= _KERNEL_MPF_TMIN_ID && (mpfid) <= _KERNEL_MPF_TMAX_ID)




/* ------------------------------------------ */
/*   Accessor for MPFCB                       */
/* ------------------------------------------ */

/* que */
#define _KERNEL_MPF_GET_QUE(mpfhdl)			(&(mpfhdl)->que)


/* freblk */
#if _KERNEL_MPFCB_FREBLK
#define _KERNEL_MPF_SET_FREBLK(mpfhdl, x)	do { _KERNEL_MPF_MPFHDL2MPFCB(mpfhdl)->freblk = (_KERNEL_MPFCB_T_BLKHDL)(x); } while (0)
#define _KERNEL_MPF_GET_FREBLK(mpfhdl)		((_KERNEL_MPF_T_BLKHDL)_KERNEL_MPF_MPFHDL2MPFCB(mpfhdl)->freblk)
#else
#define _KERNEL_MPF_SET_FREBLK(mpfhdl, x)	do { } while (0)
#define _KERNEL_MPF_GET_FREBLK(mpfhdl)		(0)
#endif

/* fblkcnt */
#if _KERNEL_MPFCB_FBLKCNT
#define _KERNEL_MPF_SET_FBLKCNT(mpfhdl, x)	do { _KERNEL_MPF_MPFHDL2MPFCB(mpfhdl)->fblkcnt = (_KERNEL_MPFCB_T_BLKCNT)(x); } while (0)
#define _KERNEL_MPF_GET_FBLKCNT(mpfhdl)		((_KERNEL_MPF_T_BLKCNT)_KERNEL_MPF_MPFHDL2MPFCB(mpfhdl)->fblkcnt)
#else
#define _KERNEL_MPF_SET_FBLKCNT(mpfhdl, x)	do { } while (0)
#define _KERNEL_MPF_GET_FBLKCNT(mpfhdl)		(0)
#endif


/* mpfatr */
#if _KERNEL_MPFCB_MPFATR
#define _KERNEL_MPF_SET_MPFATR(mpfhdl, x)	do { _KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)->mpfatr = (_KERNEL_MPFCB_T_MPFATR)(x); } while (0)
#define _KERNEL_MPF_GET_MPFATR(mpfhdl)		((_KERNEL_MPF_T_MPFATR)_KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)->mpfatr)
#else
#define _KERNEL_MPF_SET_MPFATR(mpfhdl, x)	do { } while (0)
#if _KERNEL_SPT_MPF_TA_TFIFO
#define _KERNEL_MPF_GET_MPFATR(mpfhdl)		(TA_TFIFO)
#else
#define _KERNEL_MPF_GET_MPFATR(mpfhdl)		(TA_TPRI)
#endif
#endif

/* blkcnt */
#if _KERNEL_MPFCB_BLKCNT
#define _KERNEL_MPF_SET_BLKCNT(mpfhdl, x)	do { _KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)->blkcnt = (_KERNEL_MPFCB_T_BLKCNT)(x); } while (0)
#define _KERNEL_MPF_GET_BLKCNT(mpfhdl)		((_KERNEL_MPF_T_BLKCNT)_KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)->blkcnt)
#else
#define _KERNEL_MPF_SET_BLKCNT(mpfhdl, x)	do { } while (0)
#define _KERNEL_MPF_GET_BLKCNT(mpfhdl)		(0)
#endif

/* blksz */
#if _KERNEL_MPFCB_BLKSZ
#define _KERNEL_MPF_SET_BLKSZ(mpfhdl, x)	do { _KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)->blksz = (_KERNEL_MPFCB_T_BLKCNT)(x); } while (0)
#define _KERNEL_MPF_GET_BLKSZ(mpfhdl)		((_KERNEL_MPF_T_BLKCNT)_KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)->blksz)
#else
#define _KERNEL_MPF_SET_BLKSZ(mpfhdl, x)	do { } while (0)
#define _KERNEL_MPF_GET_BLKSZ(mpfhdl)		(_KERNEL_TMAX_BLKCNT)
#endif

/* mpf */
#if _KERNEL_MPFCB_MPF
#define _KERNEL_MPF_SET_MPF(mpfhdl, x)		do { _KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)->mpf = (_KERNEL_MPFCB_T_MPF)(x); } while (0)
#define _KERNEL_MPF_GET_MPF(mpfhdl)			((_KERNEL_MPF_T_MPF)_KERNEL_MPF_MPFHDL2MPFCBROM(mpfhdl)->mpf)
#else
#define _KERNEL_MPF_SET_MPF(mpfhdl, x)		do { } while (0)
#define _KERNEL_MPF_GET_MPF(mpfhdl)			(_KERNEL_TMAX_BLKCNT)
#endif




/* %jp{キュー接続} */
#if _KERNEL_SPT_MPF_TA_TFIFO && _KERNEL_SPT_MPF_TA_TPRI		/* %jp{TA_TFIFO と TA_TPRI の混在 } */
#define _KERNEL_MPF_ADD_QUE(semhdl, tskhdl)	_KERNEL_ADD_QUE(_KERNEL_MPF_GET_QUE(semhdl), tskhdl, _KERNEL_MPF_GET_MPFATR(semhdl))
#elif _KERNEL_SPT_MPF_TA_TFIFO && !_KERNEL_SPT_SE_TA_TPRI	/* %jp{TA_TFIFO のみ利用 } */
#define _KERNEL_MPF_ADD_QUE(semhdl, tskhdl)	_KERNEL_ADF_QUE(_KERNEL_MPF_GET_QUE(semhdl), tskhdl)
#elif !_KERNEL_SPT_MPF_TA_TFIFO && _KERNEL_SPT_MPF_TA_TPRI	/* %jp{TA_TPRI のみ利用 } */
#define _KERNEL_MPF_ADD_QUE(semhdl, tskhdl)	_KERNEL_ADP_QUE(_KERNEL_MPF_GET_QUE(semhdl), tskhdl)
#else
#error error:_KERNEL_SPT_MPF_TA_TPRI and _KERNEL_SPT_MPF_TA_TFIFO
#endif

/* %jp{キュー取り外し} */
#define _KERNEL_MPF_RMV_QUE(semhdl, tskhdl)	_KERNEL_RMV_QUE(semhdl, tskhdl)

/* %jp{キュー先頭取り出し} */
#define _KERNEL_MPF_RMH_QUE(semhdl)			_KERNEL_RMH_QUE(semhdl)


/* %jp{タイムアウトキュー接続} */
#if _KERNEL_SPT_TGET_MPF	/* %jp{twai_semサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_MPF_ADD_TOQ(tskhdl, tmout)	_KERNEL_ADD_TOQ(tskhdl, tmout)
#else
#define _KERNEL_MPF_ADD_TOQ(tskhdl)			do { } while (0)
#endif

/* %jp{タイムアウトキュー取り外し} */
#if _KERNEL_SPT_TGET_MPF	/* %jp{twai_semサポート時はタイムアウトキューも考慮する} */
#define _KERNEL_MPF_RMV_TOQ(tskhdl)			_KERNEL_RMV_TOQ(tskhdl)
#else
#define _KERNEL_MPF_RMV_TOQ(tskhdl)			do { } while (0)
#endif



#ifdef __cplusplus
extern "C" {
#endif

ER _kernel_cre_mpf(ID mpfid, const T_CMPF *pk_cmpf);	/**< %jp{固定長メモリプール生成} */

#ifdef __cplusplus
}
#endif




#endif	/* _KERNEL__object__mpfobj_h__ */


/* end of file */
