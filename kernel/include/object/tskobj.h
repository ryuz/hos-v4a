/**
 *  Hyper Operating System V4 Advance
 *
 * @file  tskobj.h
 * @brief %jp{タスクブジェクトのヘッダファイル}%en{task object heder file}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__object__tskobj_h__
#define _KERNEL__object__tskobj_h__



/* ------------------------------------------ */
/*  Primitive type definition                 */
/* ------------------------------------------ */

/* %jp{タスクハンドルの型}%en{Task-handle} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */
typedef int								_KERNEL_TCB_T_TSKHDL;			/**< %jp{タスクハンドルをTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TSKHDL		: _KERNEL_TBIT_TSKHDL			/**< %jp{タスクハンドルのビットフィールド宣言時の幅} */
#else
typedef _KERNEL_T_TSKHDL				_KERNEL_TCB_T_TSKHDL;			/**< %jp{タスクハンドルをTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TSKHDL										/**< %jp{タスクハンドルのビットフィールド宣言時の幅} */
#endif


/* %jp{タスク状態の型}%en{Task-state} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_TSKSTAT;			/**< %jp{タスク状態を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_TSKSTAT;			/**< %jp{タスク状態をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TSKSTAT		: (_KERNEL_TSK_TBIT_TSKSTAT+1)	/**< %jp{タスク状態のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_TSKSTAT;			/**< %jp{タスク状態を演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_TSKSTAT;			/**< %jp{タスク状態をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TSKSTAT		: _KERNEL_TSK_TBIT_TSKSTAT		/**< %jp{タスク状態のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TCBにビットフィールドを利用しない場合} */

#if _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_TSKSTAT;			/**< %jp{タスク状態を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_TSKSTAT;			/**< %jp{タスク状態をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_TSKSTAT;			/**< %jp{タスク状態を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_TSKSTAT;			/**< %jp{タスク状態をTCBに格納するときの型} */
#endif
#define _KERNEL_TCB_TBITDEF_TSKSTAT										/**< %jp{タスク状態のビットフィールド宣言時の幅} */

#endif


/* %jp{タスク優先度の型}%en{Task priopity} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TPRI		: (_KERNEL_TSK_TBIT_TPRI+1)		/**< %jp{タスク優先度のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TPRI		: _KERNEL_TSK_TBIT_TPRI			/**< %jp{タスク優先度のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TCBにビットフィールドを利用しない場合} */

#if (_KERNEL_TSK_TMAX_TPRI <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TPRI <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TPRI <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TPRI <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TPRI <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TPRI <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TPRI <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TSK_T_TPRI;				/**< %jp{タスク優先度を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TCB_T_TPRI;				/**< %jp{タスク優先度をTCBに格納するときの型} */
#endif
#define _KERNEL_TCB_TBITDEF_TPRI										/**< %jp{タスク優先度のビットフィールド宣言時の幅} */

#endif


/* %jp{タスク待ち要因}%en{Task wait} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TSKWAIT		: (_KERNEL_TSK_TBIT_TSKWAIT+1)	/**< %jp{タスク待ち要因のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TSKWAIT		: _KERNEL_TSK_TBIT_TSKWAIT		/**< %jp{タスク待ち要因のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TCBにビットフィールドを利用しない場合} */

#if (_KERNEL_TSK_TMAX_TSKWAIT <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TSKWAIT <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TSKWAIT <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TSKWAIT <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TSKWAIT <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TSKWAIT <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_TSKWAIT <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TSK_T_TSKWAIT;			/**< %jp{タスク待ち要因を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TCB_T_TSKWAIT;			/**< %jp{タスク待ち要因をTCBに格納するときの型} */
#endif
#define _KERNEL_TCB_TBITDEF_TSKWAIT										/**< %jp{タスク待ち要因のビットフィールド宣言時の幅} */

#endif


/* %jp{待ち対象のオブジェクトのID番号}%jp{Waitbject-ID} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_WOBJID		: (_KERNEL_TSK_TBIT_WOBJID+1)	/**< %jp{待ち対象のオブジェクトのID番号のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_WOBJID		: _KERNEL_TSK_TBIT_WOBJID		/**< %jp{待ち対象のオブジェクトのID番号のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TCBにビットフィールドを利用しない場合} */

#if (_KERNEL_TSK_TMAX_WOBJID <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WOBJID <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WOBJID <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WOBJID <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WOBJID <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WOBJID <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WOBJID <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TSK_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TCB_T_WOBJID;			/**< %jp{待ち対象のオブジェクトのID番号をTCBに格納するときの型} */
#endif
#define _KERNEL_TCB_TBITDEF_WOBJID										/**< %jp{待ち対象のオブジェクトのID番号のビットフィールド宣言時の幅} */

#endif


/* %jp{起動要求キューイング数}%en{Activate queuing count} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_ACTCNT		: (_KERNEL_TSK_TBIT_ACTCNT+1)	/**< %jp{起動要求キューイング数のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_ACTCNT		: _KERNEL_TSK_TBIT_ACTCNT		/**< %jp{起動要求キューイング数のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TCBにビットフィールドを利用しない場合} */

#if (_KERNEL_TSK_TMAX_ACTCNT <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_ACTCNT <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_ACTCNT <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_ACTCNT <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_ACTCNT <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_ACTCNT <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_ACTCNT <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TSK_T_ACTCNT;			/**< %jp{起動要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TCB_T_ACTCNT;			/**< %jp{起動要求キューイング数をTCBに格納するときの型} */
#endif
#define _KERNEL_TCB_TBITDEF_ACTCNT										/**< %jp{起動要求キューイング数のビットフィールド宣言時の幅} */

#endif


/*  %jp{起床要求キューイング数}%en{Wakeup queuing count} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_WUPCNT		: (_KERNEL_TSK_TBIT_WUPCNT+1)	/**< %jp{起床要求キューイング数のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_WUPCNT		: _KERNEL_TSK_TBIT_WUPCNT		/**< %jp{起床要求キューイング数のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TCBにビットフィールドを利用しない場合} */

#if (_KERNEL_TSK_TMAX_WUPCNT <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WUPCNT <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WUPCNT <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WUPCNT <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WUPCNT <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WUPCNT <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_WUPCNT <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TSK_T_WUPCNT;			/**< %jp{起床要求キューイング数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TCB_T_WUPCNT;			/**< %jp{起床要求キューイング数をTCBに格納するときの型} */
#endif
#define _KERNEL_TCB_TBITDEF_WUPCNT										/**< %jp{起床要求キューイング数のビットフィールド宣言時の幅} */

#endif


/*  %jp{強制待ち要求ネスト数}%en{Suspend nest count} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_SUSCNT		: (_KERNEL_TSK_TBIT_SUSCNT+1)	/**< %jp{強制待ち要求ネスト数のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_SUSCNT		: _KERNEL_TSK_TBIT_SUSCNT		/**< %jp{強制待ち要求ネスト数のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TCBにビットフィールドを利用しない場合} */

#if (_KERNEL_TSK_TMAX_SUSCNT <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_SUSCNT <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_SUSCNT <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_SUSCNT <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_SUSCNT <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_SUSCNT <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_SUSCNT <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TSK_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TCB_T_SUSCNT;			/**< %jp{強制待ち要求ネスト数をTCBに格納するときの型} */
#endif
#define _KERNEL_TCB_TBITDEF_SUSCNT										/**< %jp{強制待ち要求ネスト数のビットフィールド宣言時の幅} */

#endif


typedef _KERNEL_T_MTXHDL				_KERNEL_TSK_T_MTXHDL;
typedef _KERNEL_T_MTXHDL				_KERNEL_TCB_T_MTXHDL;
#define _KERNEL_TCB_TBITDEF_MTXHDL


/*  %jp{タスクデータ}%en{Task data} */
#if _KERNEL_TCB_BITFIELD			/* %jp{TCBにビットフィールドを利用する場合} */

typedef VP_INT							_KERNEL_TSK_T_DATA;
typedef int								_KERNEL_TCB_T_DATA;
#define _KERNEL_TCB_TBITDEF_DATA		: _KERNEL_TSK_TBIT_DATA

#else								/* %jp{TCBにビットフィールドを利用しない場合} */

typedef VP_INT							_KERNEL_TSK_T_DATA;
typedef VP_INT							_KERNEL_TCB_T_DATA;
#define _KERNEL_TCB_TBITDEF_DATA

#endif


/*  %jp{エラーコード}%en{Error code} */
#if _KERNEL_TCB_BITFIELD			/* %jp{TCBにビットフィールドを利用する場合} */

typedef signed int						_KERNEL_TSK_T_ERCD;
typedef signed int						_KERNEL_TCB_T_ERCD;
#define _KERNEL_TCB_TBITDEF_ERCD		: _KERNEL_TSK_TBIT_ERCD

#else								/* %jp{TCBにビットフィールドを利用しない場合} */

typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_ERCD;
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_ERCD;
#define _KERNEL_TCB_TBITDEF_ERCD

#endif


/* %jp{タスク属性}%en{Task attribute} */
typedef ATR								_KERNEL_TSK_T_TSKATR;
typedef ATR								_KERNEL_TCB_T_TSKATR;
#define _KERNEL_TCB_TBITDEF_TSKATR


/* %jp{タスク拡張情報}%jp{Extended information} */
typedef VP_INT							_KERNEL_TSK_T_EXINF;
typedef VP_INT							_KERNEL_TCB_T_EXINF;
#define _KERNEL_TCB_TBITDEF_EXINF


/* %jp{タスクの開始番地}%en{Start address} */
typedef void (*_KERNEL_TSK_T_TASK)(VP_INT exinf);
typedef void (*_KERNEL_TCB_T_TASK)(VP_INT exinf);
#define _KERNEL_TCB_TBITDEF_TASK


/* %jp{スタックサイズ}%en{Stack size} */
typedef SIZE							_KERNEL_TSK_T_STKSZ;
typedef SIZE							_KERNEL_TCB_T_STKSZ;
#define _KERNEL_TCB_TBITDEF_STKSZ


/* %jp{スタック領域の先頭番地}%en{Stack base address} */
typedef VP								_KERNEL_TSK_T_STK;
typedef VP								_KERNEL_TCB_T_STK;
#define _KERNEL_TCB_TBITDEF_STK


/* Initial stack pointer */
typedef VP								_KERNEL_TSK_T_ISP;
typedef VP								_KERNEL_TCB_T_ISP;
#define _KERNEL_TCB_TBITDEF_ISP



/* %jp{相対時間}%en{Relative-Time} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_RELTIM		: (_KERNEL_TSK_TBIT_RELTIM+1)	/**< %jp{相対時間のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_RELTIM		: _KERNEL_TSK_TBIT_RELTIM		/**< %jp{相対時間のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TCBにビットフィールドを利用しない場合} */

#if (_KERNEL_TSK_TMAX_RELTIM <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_RELTIM <= _KERNEL_TMAX_UB) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_RELTIM <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_RELTIM <= _KERNEL_TMAX_UH) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_RELTIM <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_RELTIM <= _KERNEL_TMAX_UW) && !(_KERNEL_OPT_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#elif (_KERNEL_TSK_TMAX_RELTIM <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TSK_T_RELTIM;			/**< %jp{相対時間を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TCB_T_RELTIM;			/**< %jp{相対時間をTCBに格納するときの型} */
#endif
#define _KERNEL_TCB_TBITDEF_RELTIM										/**< %jp{相対時間のビットフィールド宣言時の幅} */

#endif



/* %jp{タスク例外処理ルーチン属性用の型} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

/* %jp{TA_HLNG と TA_ASM の判定に 2bit 必要} */
typedef unsigned int					_KERNEL_TSK_T_TEXATR;
typedef unsigned int					_KERNEL_TCB_T_TEXATR;
#define _KERNEL_TCB_TBITDEF_TEXATR		: 2

#else							/* %jp{TEXCBにビットフィールドを利用しない場合} */

typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_TEXATR;
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_TEXATR;
#define _KERNEL_TCB_TBITDEF_TEXATR

#endif


/* %jp{タスク例外処理ルーチンの起動番地の型} */
typedef void (*_KERNEL_TSK_T_TEXRTN)(TEXPTN texptn, VP_INT exinf);
typedef FP								_KERNEL_TCB_T_TEXRTN;
#define _KERNEL_TCB_TBITDEF_TEXRTN


/* %jp{タスク例外処理禁止状態の型} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_LEAST_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_TEXSTAT;			/**< %jp{タスク例外処理状態を演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_TEXSTAT;			/**< %jp{タスク例外処理状態をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TEXSTAT		: 1 + 1							/**< %jp{タスク例外処理状態のビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TEX_T_TEXSTAT;			/**< %jp{タスク例外処理状態を演算操作するときの型} */
typedef unsigned int					_KERNEL_TEXCB_T_TEXSTAT;		/**< %jp{タスク例外処理状態をTCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TEXSTAT		: 1								/**< %jp{タスク例外処理状態のビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TEXCBにビットフィールドを利用しない場合} */

#if _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_TEXSTAT;			/**< %jp{タスク例外処理状態を演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_TEXSTAT;			/**< %jp{タスク例外処理状態をTCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_TEXSTAT;			/**< %jp{タスク例外処理状態を演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_TEXSTAT;			/**< %jp{タスク例外処理状態をTCBに格納するときの型} */
#endif

#define _KERNEL_TCB_TBITDEF_TEXSTAT										/**< %jp{タスク例外処理状態のビットフィールド宣言時の幅} */

#endif


/* %jp{例外要因パターン用の型} */
#if _KERNEL_TCB_BITFIELD		/* %jp{TCBにビットフィールドを利用する場合} */

#if _KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE	/* %jp{符号付優先の場合1bit増やして符号付を使う} */
typedef signed int						_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef signed int						_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TEXPTN		: _KERNEL_TEX_TBIT_TEXPTN + 1	/**< %jp{例外要因パターンのビットフィールド宣言時の幅} */
#else
typedef unsigned int					_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef unsigned int					_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#define _KERNEL_TCB_TBITDEF_TEXPTN		: _KERNEL_TEX_TBIT_TEXPTN		/**< %jp{例外要因パターンのビットフィールド宣言時の幅} */
#endif

#else							/* %jp{TEXCBにビットフィールドを利用しない場合} */

#if _KERNEL_TEX_TBIT_TEXPTN <= 7 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_B				_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_B				_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 8 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UB				_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UB				_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 15 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_H				_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_H				_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 16 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UH				_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UH				_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 31 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_W				_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_W				_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 32 && !(_KERNEL_PROCATR_SIGNED_INT && !_KERNEL_OPT_CB_SIZE)
typedef _KERNEL_T_FAST_UW				_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UW				_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#elif _KERNEL_TEX_TBIT_TEXPTN <= 63 && _KERNEL_PROCATR_SIGNED_INT
typedef _KERNEL_T_FAST_D				_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_D				_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#else
typedef _KERNEL_T_FAST_UD				_KERNEL_TSK_T_TEXPTN;			/**< %jp{例外要因パターンを演算操作するときの型} */
typedef _KERNEL_T_LEAST_UD				_KERNEL_TCB_T_TEXPTN;			/**< %jp{例外要因パターンをTEXCBに格納するときの型} */
#endif

#define _KERNEL_TCB_TBITDEF_TEXPTN										/**< %jp{例外要因パターンのビットフィールド宣言時の幅} */

#endif




/* -------------------------------------------------------------------- */
/*  TCB definetion                                                      */
/* -------------------------------------------------------------------- */

#include "core/dsp.h"
#include "core/que.h"
#include "core/rdq.h"
#include "core/toq.h"
#include "core/sys.h"



/* -------------------------------------------------------------------- */
/*  TCB definetion                                                      */
/* -------------------------------------------------------------------- */

#if _KERNEL_TCB_SPLIT_RO

/** %jp{タスクコントロールブロック(ROM部)}%en{Task control block for ROM} */
typedef struct _kernel_t_tcb_ro				/* タスクコントロールブロック(ROM部) */
{
#if _KERNEL_TCB_TSKATR
	_KERNEL_TCB_T_TSKATR	tskatr		_KERNEL_TCB_TBITDEF_TSKATR;		/**< %jp{タスク属性}%en{Task attribute} */
#endif

#if _KERNEL_TCB_EXINF
	_KERNEL_TCB_T_EXINF		exinf		_KERNEL_TCB_TBITDEF_EXINF;		/**< %jp{タスクの拡張情報}%en{Task extend information} */
#endif

#if _KERNEL_TCB_TASK
	_KERNEL_TCB_T_TASK		task		_KERNEL_TCB_TBITDEF_TASK;		/**< %jp{タスクの起動番地}%en{Task start address} */
#endif

#if _KERNEL_TCB_TSKPRI
	_KERNEL_TCB_T_TPRI		itskpri		_KERNEL_TCB_TBITDEF_TPRI;		/**< %jp{タスクの起動時優先度}%en{Task initial priority} */
#endif

#if _KERNEL_TCB_STKSZ
	_KERNEL_TCB_T_STKSZ		stksz		_KERNEL_TCB_TBITDEF_STKSZ;		/**< %jp{タスクのスタックのサイズ（バイト数）}%en{Task stack size(in bytes)} */
#endif

#if _KERNEL_TCB_STK
	_KERNEL_TCB_T_STK		stk			_KERNEL_TCB_TBITDEF_STK;		/**< %jp{タスクのスタック領域の先頭番地}%en{Base address of task stack space} */
#endif

#if _KERNEL_TCB_ISP
	_KERNEL_TCB_T_ISP		isp			_KERNEL_TCB_TBITDEF_ISP;		/**< %jp{スタックポインタの初期値}%en{Task initial stack pointer} */
#endif

#if _KERNEL_TCB_TEXATR
	_KERNEL_TCB_T_TEXATR	texatr		_KERNEL_TCB_TBITDEF_TEXATR;		/**< %jp{タスク例外処理ルーチン属性} */
#endif

#if _KERNEL_TCB_TEXRTN
	_KERNEL_TCB_T_TEXRTN	texrtn		_KERNEL_TCB_TBITDEF_TEXRTN;		/**< %jp{タスク例外処理ルーチンの起動番地} */
#endif
} _KERNEL_T_TCB_RO;

typedef const _KERNEL_T_TCB_RO		*_KERNEL_T_TCB_RO_PTR;


/** %jp{タスクコントロールブロック(RAM部)}%en{Task control block for RAM} */
typedef struct _kernel_t_tcb
{
#if _KERNEL_TCB_CTXCB
	_KERNEL_T_CTXCB			ctxcb;										/**< %jp{タスクのコンテキスト}%en{Execution context control block} */
#endif

#if _KERNEL_TCB_QUE
	_KERNEL_T_QUE			*pk_que;									/**< %jp{属しているキュー}%en{Pointer of the queue for which the task connected} */
#endif

#if _KERNEL_TCB_QUEOBJ
	_KERNEL_QUEOBJ														/**< %jp{キューに接続する為のオブジェクト}%en{Object for queue connection} */
#endif

#if _KERNEL_TCB_TOQOBJ
	_KERNEL_TOQOBJ														/* %jp{タイムアウトキューに接続する為のオブジェクト}%en{Timeout queue object} */
#endif

#if _KERNEL_TCB_TSKSTAT
	_KERNEL_TCB_T_TSKSTAT	tskstat		_KERNEL_TCB_TBITDEF_TSKSTAT;	/**< %jp{タスク状態}%en{Task state} */
#endif

#if _KERNEL_TCB_TSKPRI
	_KERNEL_TCB_T_TPRI		tskpri		_KERNEL_TCB_TBITDEF_TPRI;		/**< %jp{タスクの現在優先度}%en{Task current priority} */
#endif

#if _KERNEL_TCB_TSKBPRI
	_KERNEL_TCB_T_TPRI		tskbpri		_KERNEL_TCB_TBITDEF_TPRI;		/**< %jp{タスクのベース優先度}%en{Task base priority} */
#endif

#if _KERNEL_TCB_TSKWAIT
	_KERNEL_TCB_T_TSKWAIT	tskwait		_KERNEL_TCB_TBITDEF_TSKWAIT;	/**< %jp{待ち要因}%en{Reason for waiting} */
#endif

#if _KERNEL_TCB_WOBJID
	_KERNEL_TCB_T_WOBJID	wobjid		_KERNEL_TCB_TBITDEF_WOBJID;		/**< %jp{待ち対象のオブジェクトのID番号}%en{Object ID number for which the task waiting} */
#endif

#if _KERNEL_TCB_ACTCNT
	_KERNEL_TCB_T_ACTCNT	actcnt		_KERNEL_TCB_TBITDEF_ACTCNT;		/**< %jp{起動要求キューイング回数}%en{Activation request count} */
#endif

#if _KERNEL_TCB_WUPCNT
	_KERNEL_TCB_T_WUPCNT	wupcnt		_KERNEL_TCB_TBITDEF_WUPCNT;		/**< %jp{起床要求キューイング回数}%en{Wakeup request count} */
#endif

#if _KERNEL_TCB_SUSCNT
	_KERNEL_TCB_T_SUSCNT	suscnt		_KERNEL_TCB_TBITDEF_SUSCNT;		/**< %jp{強制待ち要求ネスト回数}%en{Suspension count} */
#endif

#if _KERNEL_TCB_MTXHDL
	_KERNEL_TCB_T_MTXHDL	mtxhdl		_KERNEL_TCB_TBITDEF_MTXHDL;		/**< %jp{所有するミューテックスのリスト} */	
#endif

#if _KERNEL_TCB_ERCD
	_KERNEL_TCB_T_ERCD		ercd		_KERNEL_TCB_TBITDEF_ERCD;		/**< %jp{待ち解除時のエラーコード}%en{error code} */
#endif

#if _KERNEL_TCB_DATA
	_KERNEL_TCB_T_DATA		data		_KERNEL_TCB_TBITDEF_DATA;		/**< %jp{タスク同期時の受け渡しデータ}%en{task data} */
#endif

#if _KERNEL_TCB_TSKID
	_KERNEL_TCB_T_TSKID		tskid		_KERNEL_TCB_TBITDEF_TSKID;		/**< %jp{タスクID番号の逆引き用}%en{Task object ID} */
#endif

#if _KERNEL_TCB_TEXSTAT
	_KERNEL_TCB_T_TEXSTAT	texstat		_KERNEL_TCB_TBITDEF_TEXSTAT;	/**< %jp{タスク例外処理状態} */
#endif

#if _KERNEL_TCB_RASPTN
	_KERNEL_TCB_T_TEXPTN	rasptn		_KERNEL_TCB_TBITDEF_TEXPTN;		/**< %jp{タスク例外処理要因} */
#endif


/* %jp{ポインタ管理時にROM部/RAM部を分離する場合はポインタを張る} */
#if _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY
	const _KERNEL_T_TCB_RO	*tcb_ro;
#endif
} _KERNEL_T_TCB;

typedef _KERNEL_T_TCB			*_KERNEL_T_TCB_PTR;


#else


/** %jp{タスクコントロールブロック}%en{Task Control Block} */
typedef struct _kernel_t_tcb
{
#if _KERNEL_TCB_CTXCB
	_KERNEL_T_CTXCB			ctxcb;										/**< %jp{タスクのコンテキスト}%en{Execution context control block} */
#endif

#if _KERNEL_TCB_QUE
	_KERNEL_T_QUE			*pk_que;									/**< %jp{属しているキュー}%en{Pointer of the queue for which the task connected} */
#endif

#if _KERNEL_TCB_QUEOBJ
	_KERNEL_QUEOBJ														/**< %jp{キューに接続する為のオブジェクト}%en{Object for queue connection} */
#endif
	
#if _KERNEL_TCB_TOQOBJ
	_KERNEL_TOQOBJ														/**< %jp{タイムアウトキューに接続する為のオブジェクト}%en{Timeout queue object} */
#endif

#if _KERNEL_TCB_TSKSTAT
	_KERNEL_TCB_T_TSKSTAT	tskstat		_KERNEL_TCB_TBITDEF_TSKSTAT;	/**< %jp{タスク状態}%en{Task state} */
#endif

#if _KERNEL_TCB_TSKPRI
	_KERNEL_TCB_T_TPRI		tskpri		_KERNEL_TCB_TBITDEF_TPRI;		/**< %jp{タスクの現在優先度}%en{Task current priority} */
#endif

#if _KERNEL_TCB_TSKBPRI
	_KERNEL_TCB_T_TPRI		tskbpri		_KERNEL_TCB_TBITDEF_TPRI;		/**< %jp{タスクのベース優先度}%en{Task base priority} */
#endif

#if _KERNEL_TCB_TSKWAIT
	_KERNEL_TCB_T_TSKWAIT	tskwait		_KERNEL_TCB_TBITDEF_TSKWAIT;	/**< %jp{待ち要因}%en{Reason for waiting} */
#endif

#if _KERNEL_TCB_WOBJID
	_KERNEL_TCB_T_WOBJID	wobjid		_KERNEL_TCB_TBITDEF_WOBJID;		/**< %jp{待ち対象のオブジェクトのID番号}%en{Object ID number for which the task waiting} */
#endif

#if _KERNEL_TCB_ACTCNT
	_KERNEL_TCB_T_ACTCNT	actcnt		_KERNEL_TCB_TBITDEF_ACTCNT;		/**< %jp{起動要求キューイング回数}%en{Activation request count} */
#endif

#if _KERNEL_TCB_WUPCNT
	_KERNEL_TCB_T_WUPCNT	wupcnt		_KERNEL_TCB_TBITDEF_WUPCNT;		/**< %jp{起床要求キューイング回数}%en{Wakeup request count} */
#endif

#if _KERNEL_TCB_SUSCNT
	_KERNEL_TCB_T_SUSCNT	suscnt		_KERNEL_TCB_TBITDEF_SUSCNT;		/**< %jp{強制待ち要求ネスト回数}%en{Suspension count} */
#endif

#if _KERNEL_TCB_MTXHDL
	_KERNEL_TCB_T_MTXHDL	mtxhdl		_KERNEL_TCB_TBITDEF_MTXHDL;		/**< %jp{所有するミューテックスのリスト} */	
#endif

#if _KERNEL_TCB_ERCD
	_KERNEL_TCB_T_ERCD		ercd		_KERNEL_TCB_TBITDEF_ERCD;		/**< %jp{待ち解除時のエラーコード}%en{error code} */
#endif

#if _KERNEL_TCB_DATA
	_KERNEL_TCB_T_DATA		data		_KERNEL_TCB_TBITDEF_DATA;		/**< %jp{タスク同期時の受け渡しデータ}%en{task data} */
#endif

#if _KERNEL_TCB_TSKID
	_KERNEL_TCB_T_TSKID		tskid		_KERNEL_TCB_TBITDEF_TSKID;		/**< %jp{タスクID番号の逆引き用}%en{Task object ID} */
#endif

#if _KERNEL_TCB_TEXSTAT
	_KERNEL_TCB_T_TEXSTAT	texstat		_KERNEL_TCB_TBITDEF_TEXSTAT;	/**< %jp{タスク例外処理状態} */
#endif

#if _KERNEL_TCB_RASPTN
	_KERNEL_TCB_T_TEXPTN	rasptn		_KERNEL_TCB_TBITDEF_TEXPTN;		/**< %jp{タスク例外処理要因} */
#endif
	
	
#if _KERNEL_TCB_TSKATR
	_KERNEL_TCB_T_TSKATR	tskatr		_KERNEL_TCB_TBITDEF_TSKATR;		/**< %jp{タスク属性}%en{Task attribute} */
#endif

#if _KERNEL_TCB_EXINF
	_KERNEL_TCB_T_EXINF		exinf		_KERNEL_TCB_TBITDEF_EXINF;		/**< %jp{タスクの拡張情報}%en{Task extend information} */
#endif

#if _KERNEL_TCB_TASK
	_KERNEL_TCB_T_TASK		task		_KERNEL_TCB_TBITDEF_TASK;		/**< %jp{タスクの起動番地}%en{Task start address} */
#endif

#if _KERNEL_TCB_ITSKPRI
	_KERNEL_TCB_T_TPRI		itskpri		_KERNEL_TCB_TBITDEF_TPRI;		/**< %jp{タスクの起動時優先度}%en{Task initial priority} */
#endif

#if _KERNEL_TCB_STKSZ
	_KERNEL_TCB_T_STKSZ		stksz		_KERNEL_TCB_TBITDEF_STKSZ;		/**< %jp{タスクのスタックのサイズ（バイト数）}%en{Task stack size(in bytes)} */
#endif

#if _KERNEL_TCB_STK
	_KERNEL_TCB_T_STK		stk			_KERNEL_TCB_TBITDEF_STK;		/**< %jp{タスクのスタック領域の先頭番地}%en{Base address of task stack space} */
#endif

#if _KERNEL_TCB_ISP
	_KERNEL_TCB_T_ISP		isp			_KERNEL_TCB_TBITDEF_ISP;		/**< %jp{スタックポインタの初期値}%en{Task initial stack pointer} */
#endif

#if _KERNEL_TCB_TEXATR
	_KERNEL_TCB_T_TEXATR	texatr		_KERNEL_TCB_TBITDEF_TEXATR;		/**< %jp{タスク例外処理ルーチン属性} */
#endif

#if _KERNEL_TCB_TEXRTN
	_KERNEL_TCB_T_TEXRTN	texrtn		_KERNEL_TCB_TBITDEF_TEXRTN;		/**< %jp{タスク例外処理ルーチンの起動番地} */
#endif
} _KERNEL_T_TCB;

typedef _KERNEL_T_TCB				_KERNEL_T_TCB_RO;
typedef const _KERNEL_T_TCB_RO		*_KERNEL_T_TCB_RO_PTR;
typedef _KERNEL_T_TCB				*_KERNEL_T_TCB_PTR;

#endif



/* ------------------------------------------ */
/*  ID range                                  */
/* ------------------------------------------ */

extern const ID							_kernel_max_tskid;										/**< %jp{タスクIDの最大値} */

#define _KERNEL_TSK_TMIN_ID				1														/**< %jp{タスクIDの最小値} */
#define _KERNEL_TSK_TMAX_ID				(_kernel_max_tskid)										/**< %jp{タスクIDの最大値} */

#define _KERNEL_TSK_CHECK_TSKID(tskid)	((tskid) >= _KERNEL_TSK_TMIN_ID && (tskid) <= _KERNEL_TSK_TMAX_ID)
																								/**< %jp{ID範囲チェック} */


/* ------------------------------------------ */
/*  Control block tables                      */
/* ------------------------------------------ */

#if _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_BLKARRAY
#if _KERNEL_TCB_SPLIT_RO

/* %jp{ブロック配列管理でRO分離の場合}%en{block array} */
extern  _KERNEL_T_TCB					_kernel_tcb_tbl[];										/**< %jp{タスクコントロールブロックテーブル} */
extern const _KERNEL_T_TCB_RO			_kernel_tcb_ro_tbl[];									/**< %jp{タスクコントロールブロック(リードオンリー部)テーブル} */
#define _KERNEL_TSK_ID2TCB(tskid)		(&_kernel_tcb_tbl[(tskid) - _KERNEL_TSK_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_TSK_CHECK_EXS(tskid)	(_kernel_tcb_ro_tbl[(tskid) - _KERNEL_TSK_TMIN_ID].task != NULL)				
																								/**< %jp{オブジェクトの存在チェック} */

#else

/* %jp{ブロック配列管理の場合}%en{block array} */
extern  _KERNEL_T_TCB					_kernel_tcb_tbl[];										/**< %jp{タスクコントロールブロックテーブル} */
#define _KERNEL_TSK_ID2TCB(tskid)		(&_kernel_tcb_tbl[(tskid) - _KERNEL_TSK_TMIN_ID])		/**< %jp{コントロールブロックの取得} */
#define _KERNEL_TSK_CHECK_EXS(tskid)	(_kernel_tcb_tbl[(tskid) - _KERNEL_TSK_TMIN_ID].task != NULL)				
																								/**< %jp{オブジェクトの存在チェック} */

#endif

#elif _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY

/* %jp{ポインタ配列管理の場合}%en{pointer array} */
extern  _KERNEL_T_TCB					*_kernel_tcb_tbl[];										/**< %jp{タスクコントロールブロックテーブル} */
#define _KERNEL_TSK_ID2TCB(tskid)		(_kernel_tcb_tbl[(tskid) - _KERNEL_TMIN_TSKID])			/**< %jp{タスクIDからTCB アドレスを取得} */
#define _KERNEL_TSK_CHECK_EXS(tskid)	(_KERNEL_TSK_ID2TCB(tskid) != NULL)						/**< %jp{オブジェクトの存在チェック} */

#endif



/* ------------------------------------------ */
/*  Convert Handle                            */
/* ------------------------------------------ */

#if _KERNEL_TSKHDL_ID		/* %jp{タスクハンドルにIDを使う}%en{TSKHDL is ID} */

#define _KERNEL_TSK_ID2TSKHDL(tskid)			(tskid)
#define _KERNEL_TSK_TSKHDL2ID(tskhdl)			(tskhdl)
#define _KERNEL_TSK_TCB2TSKHDL(tcb)				_KERNEL_TSK_TCB2ID(tcb)
#define _KERNEL_TSK_TSKHDL2TCB(tskhdl)			_KERNEL_TSK_ID2TCB(tskhdl)
#define _KERNEL_TSK_GET_TSKHDL(tskid, tcb)		(tskid)

#else						/* %jp{タスクハンドルにTCBのアドレスを使う}%en{TSKHDL is Address of TCB} */

#define _KERNEL_TSK_ID2TSKHDL(tskid)			_KERNEL_TSK_ID2TCB(tskid)
#define _KERNEL_TSK_TSKHDL2ID(tskhdl)			_KERNEL_TSK_TCB2ID(tskhdl)
#define _KERNEL_TSK_TCB2TSKHDL(tskhdl)			(tskhdl)
#define _KERNEL_TSK_TSKHDL2TCB(tskhdl)			(tskhdl)
#define _KERNEL_TSK_GET_TSKHDL(tskid, tcb)		(tcb)

#endif



/* ------------------------------------------ */
/*   Accessor for TCB                         */
/* ------------------------------------------ */

/* tcb_ro */
#if !_KERNEL_TCB_SPLIT_RO
#define _KERNEL_TSK_GET_TCB_RO(tskid, tcb)		(tcb)
#else
#if _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_BLKARRAY		/* %jp{TCBを単純配列で管理}%en{array of block} */
#define _KERNEL_TSK_GET_TCB_RO(tskid, tcb)		(&_kernel_tcb_ro_tbl[(tskid)])
#elif _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY		/* %jp{TCBをポインタ配列で管理}%en{array of pointer} */
#define _KERNEL_TSK_GET_TCB_RO(tskid, tcb)		((tcb)->tcb_ro)
#endif
#endif


/* ctxcb */
#define _KERNEL_TSK_GET_CTXCB(tcb)				(&(tcb)->ctxcb)

/* que */
#if _KERNEL_TCB_QUE
#define _KERNEL_TSK_SET_QUE(tcb, x)				do { (tcb)->pk_que = (_KERNEL_T_QUE *)(x); } while(0)
#define _KERNEL_TSK_GET_QUE(tcb)				((_KERNEL_T_QUE *)(tcb)->pk_que)
#else	/* %jp{TCBに所属キューの情報を持たせない場合は別情報からの探索で求める} */
#define _KERNEL_TSK_SET_QUE(tcb, x)				do { } while(0)
#define _KERNEL_TSK_GET_QUE(tcb)				_kernel_get_que(tcb)
#endif

/* queobj */
#if _KERNEL_TCB_QUEOBJ
#define _KERNEL_TSK_CRE_QUEOBJ(tcb)				_KERNEL_CRE_QUEOBJ(tcb)
#define _KERNEL_TSK_DEL_QUEOBJ(tcb)				_KERNEL_DEL_QUEOBJ(tcb)
#else
#define _KERNEL_TSK_CRE_QUEOBJ(tcb)				do { } while(0)
#define _KERNEL_TSK_DEL_QUEOBJ(tcb)				do { } while(0)
#endif

/* toqobj */
#if _KERNEL_TCB_QUEOBJ
#define _KERNEL_TSK_CRE_TOQOBJ(tcb)				_KERNEL_CRE_TOQOBJ(tcb)
#define _KERNEL_TSK_DEL_TOQOBJ(tcb)				_KERNEL_DEL_TOQOBJ(tcb)
#else
#define _KERNEL_TSK_CRE_TOQOBJ(tcb)				do { } while(0)
#define _KERNEL_TSK_DEL_TOQOBJ(tcb)				do { } while(0)
#endif


/* tskstat */
#if _KERNEL_TCB_TSKSTAT
#define _KERNEL_TSK_SET_TSKSTAT(tcb, x)			do { (tcb)->tskstat = (_KERNEL_TCB_T_TSKSTAT)(x); } while(0)
#define _KERNEL_TSK_GET_TSKSTAT(tcb)			((_KERNEL_TSK_T_TSKSTAT)(tcb)->tskstat)
#else
#define _KERNEL_TSK_SET_TSKSTAT(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_TSKSTAT(tcb)			0
#endif

/* tskpri */
#if _KERNEL_TCB_TSKPRI	/* %jp{通常のTCBへのアクセサ} */
#define _KERNEL_TSK_SET_TSKPRI(tcb, x)			do { (tcb)->tskpri = (x); } while(0)
#define _KERNEL_TSK_GET_TSKPRI(tcb)				((tcb)->tskpri)
#else
#if _KERNEL_TCB_ITSKPRI	/* %jp{優先度固定(ROM配置)時のアクセサ} */
#define _KERNEL_TSK_SET_TSKPRI(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_TSKPRI(tcb)				((tcb)->itskpri)
#else					/* %jp{優先度未使用時(全てFIFO順)は1に固定する} */
#define _KERNEL_TSK_SET_TSKPRI(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_TSKPRI(tcb)				(1)
#endif
#endif

/* tskbpri */
#if _KERNEL_TCB_TSKBPRI
#define _KERNEL_TSK_SET_TSKBPRI(tcb, x)			do { (tcb)->tskbpri = (x); } while(0)
#define _KERNEL_TSK_GET_TSKBPRI(tcb)			((tcb)->tskbpri)
#else
#define _KERNEL_TSK_SET_TSKBPRI(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_TSKBPRI(tcb)			_KERNEL_TSK_GET_TSKPRI(tcb)
#endif

/* tskwait */
#if _KERNEL_TCB_TSKWAIT
#define _KERNEL_TSK_SET_TSKWAIT(tcb, x)			do { (tcb)->tskwait = (x); } while(0)
#define _KERNEL_TSK_GET_TSKWAIT(tcb)			((tcb)->tskwait)
#else
#define _KERNEL_TSK_SET_TSKWAIT(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_TSKWAIT(tcb)			(0)
#endif

/* wobjid */
#if _KERNEL_TCB_WOBJID
#define _KERNEL_TSK_SET_WOBJID(tcb, x)			do { (tcb)->wobjid = (x); } while(0)
#define _KERNEL_TSK_GET_WOBJID(tcb)				((tcb)->wobjid)
#else
#define _KERNEL_TSK_SET_WOBJID(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_WOBJID(tcb)				(0)
#endif

/* actcnt */
#if _KERNEL_TCB_ACTCNT
#define _KERNEL_TSK_SET_ACTCNT(tcb, x)			do { (tcb)->actcnt = (x); } while(0)
#define _KERNEL_TSK_GET_ACTCNT(tcb)				((tcb)->actcnt)
#else
#define _KERNEL_TSK_SET_ACTCNT(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_ACTCNT(tcb)				(0)
#endif

/* wupcnt */
#if _KERNEL_TCB_WUPCNT
#define _KERNEL_TSK_SET_WUPCNT(tcb, x)			do { (tcb)->wupcnt = (x); } while(0)
#define _KERNEL_TSK_GET_WUPCNT(tcb)				((tcb)->wupcnt)
#else
#define _KERNEL_TSK_SET_WUPCNT(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_WUPCNT(tcb)				(0)
#endif

/* suscnt */
#if _KERNEL_TCB_SUSCNT
#define _KERNEL_TSK_SET_SUSCNT(tcb, x)			do { (tcb)->suscnt = (x); } while(0)
#define _KERNEL_TSK_GET_SUSCNT(tcb)				((tcb)->suscnt)
#else
#define _KERNEL_TSK_SET_SUSCNT(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_SUSCNT(tcb)				(0)
#endif

/* mtxhdl */
#if _KERNEL_TCB_MTXHDL
#define _KERNEL_TSK_SET_MTXHDL(tcb, x)			do { (tcb)->mtxhdl = (x); } while(0)
#define _KERNEL_TSK_GET_MTXHDL(tcb)				((tcb)->mtxhdl)
#else
#define _KERNEL_TSK_SET_MTXHDL(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_MTXHDL(tcb)				_KERNEL_MTXHDL_NULL
#endif

/* ercd */
#if _KERNEL_TCB_ERCD
#define _KERNEL_TSK_SET_ERCD(tcb, x)			do { (tcb)->ercd = (x); } while(0)
#define _KERNEL_TSK_GET_ERCD(tcb)				((tcb)->ercd)
#else
#define _KERNEL_TSK_SET_ERCD(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_ERCD(tcb)				(E_OK)
#endif

/* data */
#if _KERNEL_TCB_DATA
#define _KERNEL_TSK_SET_DATA(tcb, x)			do { (tcb)->data = (x); } while(0)
#define _KERNEL_TSK_GET_DATA(tcb)				((tcb)->data)
#else
#define _KERNEL_TSK_SET_DATA(tcb, x)			do { } while(0)
#define _KERNEL_TSK_GET_DATA(tcb)				(0)
#endif

/* texstat */
#if _KERNEL_TCB_TEXSTAT
#define _KERNEL_TSK_SET_TEXSTAT(tcb, x)			do { (tcb)->texstat = (_KERNEL_TCB_T_TEXSTAT)(x); } while (0)
#define _KERNEL_TSK_GET_TEXSTAT(tcb)				((_KERNEL_TSK_T_TEXSTAT)(tcb)->texstat)
#else
#define _KERNEL_TSK_SET_TEXSTAT(tcb, x)			do { } while (0)
#define _KERNEL_TSK_GET_TEXSTAT(tcb)			(_KERNEL_TXS_DIS)
#endif

/* rasptn */
#if _KERNEL_TCB_RASPTN
#define _KERNEL_TSK_SET_RASPTN(tcb, x)			do { (tcb)->rasptn = (_KERNEL_TCB_T_TEXPTN)(x); } while (0)
#define _KERNEL_TSK_GET_RASPTN(tcb)				((_KERNEL_TSK_T_TEXPTN)(tcb)->rasptn)
#else
#define _KERNEL_TSK_SET_RASPTN(texcb, x)		do { } while (0)
#define _KERNEL_TSK_GET_RASPTN(texcb)			(0)
#endif


/* tskid */
#if _KERNEL_TCB_TSKID
#define _KERNEL_TSK_SET_TSKID(tcb_ro, x)		do { (tcb_ro)->tskid = (x); } while(0)
#define _KERNEL_TSK_GET_TSKID(tcb_ro)			((tcb_ro)->tskid)
#else
#define _KERNEL_TSK_SET_TSKID(tcb_ro, x)		do { } while(0)
#define _KERNEL_TSK_GET_TSKID(tcb_ro)			(0)
#endif

/* tskatr */
#if _KERNEL_TCB_TSKATR
#define _KERNEL_TSK_SET_TSKATR(tcb_ro, x)		do { (tcb_ro)->tskatr = (x); } while(0)
#define _KERNEL_TSK_GET_TSKATR(tcb_ro)			((tcb_ro)->tskatr)
#else	/* %jp{tskatr未使用時はTA_HLNGに固定する} */
#define _KERNEL_TSK_SET_TSKATR(tcb_ro, x)		do { } while(0)
#define _KERNEL_TSK_GET_TSKATR(tcb_ro)			(TA_HLNG)
#endif

/* exinf */
#if _KERNEL_TCB_EXINF
#define _KERNEL_TSK_SET_EXINF(tcb_ro, x)		do { (tcb_ro)->exinf = (x); } while(0)
#define _KERNEL_TSK_GET_EXINF(tcb_ro)			((tcb_ro)->exinf)
#else
#define _KERNEL_TSK_SET_EXINF(tcb_ro, x)		do { } while(0)
#define _KERNEL_TSK_GET_EXINF(tcb_ro)			(0)
#endif

/* task */
#if _KERNEL_TCB_TASK
#define _KERNEL_TSK_SET_TASK(tcb_ro, x)			do { (tcb_ro)->task = (_KERNEL_TCB_T_TASK)(x); } while(0)
#define _KERNEL_TSK_GET_TASK(tcb_ro)			((_KERNEL_TSK_T_TASK)(tcb_ro)->task)
#else
#define _KERNEL_TSK_SET_TASK(tcb_ro, x)			do { } while(0)
#define _KERNEL_TSK_GET_TASK(tcb_ro)			(0)
#endif

/* tskipri */
#if _KERNEL_TCB_ITSKPRI
#define _KERNEL_TSK_SET_ITSKPRI(tcb_ro, x)		do { (tcb_ro)->itskpri = (x); } while(0)
#define _KERNEL_TSK_GET_ITSKPRI(tcb_ro)			((tcb_ro)->itskpri)
#else	/* %jp{tskatr未使用時はTA_HLNGに固定する} */
#define _KERNEL_TSK_SET_ITSKPRI(tcb_ro, x)		do { } while(0)
#define _KERNEL_TSK_GET_ITSKPRI(tcb_ro)			(1)
#endif

/* stksz */
#if _KERNEL_TCB_STKSZ
#define _KERNEL_TSK_SET_STKSZ(tcb_ro, x)		do { (tcb_ro)->stksz = (x); } while(0)
#define _KERNEL_TSK_GET_STKSZ(tcb_ro)			((tcb_ro)->stksz)
#else
#define _KERNEL_TSK_SET_STKSZ(tcb_ro, x)		do { } while(0)
#define _KERNEL_TSK_GET_STKSZ(tcb_ro)			(0)
#endif

/* stk */
#if _KERNEL_TCB_STK
#define _KERNEL_TSK_SET_STK(tcb_ro, x)			do { (tcb_ro)->stk = (x); } while(0)
#define _KERNEL_TSK_GET_STK(tcb_ro)				((tcb_ro)->stk)
#else
#define _KERNEL_TSK_SET_STK(tcb_ro, x)			do { } while(0)
#define _KERNEL_TSK_GET_STK(tcb_ro)				(0)
#endif

/* isp */
#if _KERNEL_TCB_ISP
#define _KERNEL_TSK_SET_ISP(tcb_ro, x)			do { (tcb_ro)->isp = (x); } while(0)
#define _KERNEL_TSK_GET_ISP(tcb_ro)				((tcb_ro)->isp)
#else
#define _KERNEL_TSK_SET_ISP(tcb_ro, x)			do { } while(0)
#define _KERNEL_TSK_GET_ISP(tcb_ro)				((VP)((UB *)_KERNEL_TSK_GET_STK(tcb_ro) + _KERNEL_TSK_GET_STKSZ(tcb_ro)))
#endif

/* texatr */
#if _KERNEL_TCB_TEXATR
#define _KERNEL_TSK_SET_TEXATR(tcb_ro, x)		do { (tcb_ro)->texatr = (_KERNEL_TCB_T_TEXATR)(x); } while (0)
#define _KERNEL_TSK_GET_TEXATR(tcb_ro)			((_KERNEL_TSK_T_TEXATR)(tcb_ro)->texatr)
#else
#define _KERNEL_TSK_SET_TEXATR(texcb_ro, x)		do { } while (0)
#define _KERNEL_TSK_GET_TEXATR(texcb_ro)		(0)
#endif

/* texrtn */
#if _KERNEL_TCB_TEXRTN
#define _KERNEL_TSK_SET_TEXRTN(tcb_ro, x)		do { (tcb_ro)->texrtn = (_KERNEL_TCB_T_TEXRTN)(x); } while (0)
#define _KERNEL_TSK_GET_TEXRTN(tcb_ro)			((_KERNEL_TSK_T_TEXRTN)(tcb_ro)->texrtn)
#else
#define _KERNEL_TSK_SET_TEXRTN(tcb_ro, x)		do { } while (0)
#define _KERNEL_TSK_GET_TEXRTN(tcb_ro)			(0)
#endif



/* ------------------------------------------ */
/*   Macro functions                          */
/* ------------------------------------------ */

#if _KERNEL_TCB_TSKSTAT
#define _KERNEL_TSK_SNS_RDY(tcb)	(_KERNEL_TSK_GET_TSKSTAT(tcb) == _KERNEL_TTS_RDY)
#define _KERNEL_TSK_SNS_WAI(tcb)	(_KERNEL_TSK_GET_TSKSTAT(tcb) & _KERNEL_TTS_WAI)
#define _KERNEL_TSK_SNS_SUS(tcb)	(_KERNEL_TSK_GET_TSKSTAT(tcb) & _KERNEL_TTS_SUS)
#else
#define _KERNEL_TSK_SNS_RDY(tcb)	()
#define _KERNEL_TSK_SNS_WAI(tcb)	()
#define _KERNEL_TSK_SNS_SUS(tcb)	(_KERNEL_TSK_GET_SUSCNT(tcb) > 0)
#endif


#ifdef __cplusplus
extern "C" {
#endif

ER   _kernel_cre_tsk(ID tskid, const T_CTSK *pk_ctsk);		/**< %jp{タスクの生成} */
void _kernel_exe_tex(_KERNEL_T_TSKHDL tskhdl);				/**< %jp{タスク例外処理の実行} */

#ifdef __cplusplus
}
#endif



#endif	/* _KERNEL__object__tskobj_h__ */



/* end of file */
