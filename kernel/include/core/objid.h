/**
 *  Hyper Operating System V4 Advance
 *
 * @file  objid.h
 * @brief %jp{タスクブジェクトのID用の型定義}%en{define object ID type}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core_objid_h__
#define _KERNEL__core_objid_h__



/* ---------------------------------- */
/*            Task-ID                 */
/* ---------------------------------- */

/* %jp{サイズに適した型とする} */
#if (_KERNEL_TMAX_TSKID <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B		_KERNEL_T_TSKID;							/**< %jp{タスクIDの型}%en{type of Task-ID} */
#elif (_KERNEL_TMAX_TSKID <= _KERNEL_TMAX_UB) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UB		_KERNEL_T_TSKID;							/**< %jp{タスクIDの型}%en{type of Task-ID} */
#elif (_KERNEL_TMAX_TSKID <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H		_KERNEL_T_TSKID;							/**< %jp{タスクIDの型}%en{type of Task-ID} */
#elif (_KERNEL_TMAX_TSKID <= _KERNEL_TMAX_UH) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UH		_KERNEL_T_TSKID;							/**< %jp{タスクIDの型}%en{type of Task-ID} */
#elif (_KERNEL_TMAX_TSKID <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W		_KERNEL_T_TSKID;							/**< %jp{タスクIDの型}%en{type of Task-ID} */
#elif (_KERNEL_TMAX_TSKID <= _KERNEL_TMAX_UW) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UW		_KERNEL_T_TSKID;							/**< %jp{タスクIDの型}%en{type of Task-ID} */
#elif (_KERNEL_TMAX_TSKID <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D		_KERNEL_T_TSKID;							/**< %jp{タスクIDの型}%en{type of Task-ID} */
#else
typedef _KERNEL_T_FAST_UD		_KERNEL_T_TSKID;							/**< %jp{タスクIDの型}%en{type of Task-ID} */
#endif



/* ---------------------------------- */
/*           Semaphore-ID             */
/* ---------------------------------- */

/* %jp{サイズに適した型とする} */
#if (_KERNEL_TMAX_SEMID <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B		_KERNEL_T_SEMID;							/**< %jp{セマフォIDの型}%en{type of Semaphore-ID} */
#elif (_KERNEL_TMAX_SEMID <= _KERNEL_TMAX_UB) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UB		_KERNEL_T_SEMID;							/**< %jp{セマフォIDの型}%en{type of Semaphore-ID} */
#elif (_KERNEL_TMAX_SEMID <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H		_KERNEL_T_SEMID;							/**< %jp{セマフォIDの型}%en{type of Semaphore-ID} */
#elif (_KERNEL_TMAX_SEMID <= _KERNEL_TMAX_UH) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UH		_KERNEL_T_SEMID;							/**< %jp{セマフォIDの型}%en{type of Semaphore-ID} */
#elif (_KERNEL_TMAX_SEMID <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W		_KERNEL_T_SEMID;							/**< %jp{セマフォIDの型}%en{type of Semaphore-ID} */
#elif (_KERNEL_TMAX_SEMID <= _KERNEL_TMAX_UW) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UW		_KERNEL_T_SEMID;							/**< %jp{セマフォIDの型}%en{type of Semaphore-ID} */
#elif (_KERNEL_TMAX_SEMID <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D		_KERNEL_T_SEMID;							/**< %jp{セマフォIDの型}%en{type of Semaphore-ID} */
#else
typedef _KERNEL_T_FAST_UD		_KERNEL_T_SEMID;							/**< %jp{セマフォIDの型}%en{type of Semaphore-ID} */
#endif



/* ---------------------------------- */
/*           Eventflag-ID             */
/* ---------------------------------- */

/* %jp{サイズに適した型とする} */
#if (_KERNEL_TMAX_FLGID <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B		_KERNEL_T_FLGID;							/**< %jp{イベントフラグIDの型}%en{type of Eventflag-ID} */
#elif (_KERNEL_TMAX_FLGID <= _KERNEL_TMAX_UB) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UB		_KERNEL_T_FLGID;							/**< %jp{イベントフラグIDの型}%en{type of Eventflag-ID} */
#elif (_KERNEL_TMAX_FLGID <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H		_KERNEL_T_FLGID;							/**< %jp{イベントフラグIDの型}%en{type of Eventflag-ID} */
#elif (_KERNEL_TMAX_FLGID <= _KERNEL_TMAX_UH) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UH		_KERNEL_T_FLGID;							/**< %jp{イベントフラグIDの型}%en{type of Eventflag-ID} */
#elif (_KERNEL_TMAX_FLGID <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W		_KERNEL_T_FLGID;							/**< %jp{イベントフラグIDの型}%en{type of Eventflag-ID} */
#elif (_KERNEL_TMAX_FLGID <= _KERNEL_TMAX_UW) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UW		_KERNEL_T_FLGID;							/**< %jp{イベントフラグIDの型}%en{type of Eventflag-ID} */
#elif (_KERNEL_TMAX_FLGID <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D		_KERNEL_T_FLGID;							/**< %jp{イベントフラグIDの型}%en{type of Eventflag-ID} */
#else
typedef _KERNEL_T_FAST_UD		_KERNEL_T_FLGID;							/**< %jp{イベントフラグIDの型}%en{type of Eventflag-ID} */
#endif



/* ---------------------------------- */
/*            Mutex-ID                */
/* ---------------------------------- */

/* %jp{サイズに適した型とする} */
#if (_KERNEL_TMAX_MTXID <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B		_KERNEL_T_MTXID;							/**< %jp{ミューテックスIDの型}%en{type of Mutex-ID} */
#elif (_KERNEL_TMAX_MTXID <= _KERNEL_TMAX_UB) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UB		_KERNEL_T_MTXID;							/**< %jp{ミューテックスIDの型}%en{type of Mutex-ID} */
#elif (_KERNEL_TMAX_MTXID <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H		_KERNEL_T_MTXID;							/**< %jp{ミューテックスIDの型}%en{type of Mutex-ID} */
#elif (_KERNEL_TMAX_MTXID <= _KERNEL_TMAX_UH) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UH		_KERNEL_T_MTXID;							/**< %jp{ミューテックスIDの型}%en{type of Mutex-ID} */
#elif (_KERNEL_TMAX_MTXID <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W		_KERNEL_T_MTXID;							/**< %jp{ミューテックスIDの型}%en{type of Mutex-ID} */
#elif (_KERNEL_TMAX_MTXID <= _KERNEL_TMAX_UW) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UW		_KERNEL_T_MTXID;							/**< %jp{ミューテックスIDの型}%en{type of Mutex-ID} */
#elif (_KERNEL_TMAX_MTXID <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D		_KERNEL_T_MTXID;							/**< %jp{ミューテックスIDの型}%en{type of Mutex-ID} */
#else
typedef _KERNEL_T_FAST_UD		_KERNEL_T_MTXID;							/**< %jp{ミューテックスIDの型}%en{type of Mutex-ID} */
#endif



/* ---------------------------------- */
/*            Mailbox-ID              */
/* ---------------------------------- */

/* %jp{サイズに適した型とする} */
#if (_KERNEL_TMAX_MBXID <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B		_KERNEL_T_MBXID;							/**< %jp{メールボックスIDの型}%en{type of Mailbox-ID} */
#elif (_KERNEL_TMAX_MBXID <= _KERNEL_TMAX_UB) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UB		_KERNEL_T_MBXID;							/**< %jp{メールボックスIDの型}%en{type of Mailbox-ID} */
#elif (_KERNEL_TMAX_MBXID <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H		_KERNEL_T_MBXID;							/**< %jp{メールボックスIDの型}%en{type of Mailbox-ID} */
#elif (_KERNEL_TMAX_MBXID <= _KERNEL_TMAX_UH) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UH		_KERNEL_T_MBXID;							/**< %jp{メールボックスIDの型}%en{type of Mailbox-ID} */
#elif (_KERNEL_TMAX_MBXID <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W		_KERNEL_T_MBXID;							/**< %jp{メールボックスIDの型}%en{type of Mailbox-ID} */
#elif (_KERNEL_TMAX_MBXID <= _KERNEL_TMAX_UW) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UW		_KERNEL_T_MBXID;							/**< %jp{メールボックスIDの型}%en{type of Mailbox-ID} */
#elif (_KERNEL_TMAX_MBXID <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D		_KERNEL_T_MBXID;							/**< %jp{メールボックスIDの型}%en{type of Mailbox-ID} */
#else
typedef _KERNEL_T_FAST_UD		_KERNEL_T_MBXID;							/**< %jp{メールボックスIDの型}%en{type of Mailbox-ID} */
#endif



/* ---------------------------------- */
/*     Fixed-Size Memory Pool-ID      */
/* ---------------------------------- */

/* %jp{サイズに適した型とする} */
#if (_KERNEL_TMAX_MPFID <= _KERNEL_TMAX_B) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_B		_KERNEL_T_MPFID;							/**< %jp{固定長メモリプールIDの型}%en{type of Fixed-Size Memory Pool-ID} */
#elif (_KERNEL_TMAX_MPFID <= _KERNEL_TMAX_UB) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UB		_KERNEL_T_MPFID;							/**< %jp{固定長メモリプールIDの型}%en{type of Fixed-Size Memory Pool-ID} */
#elif (_KERNEL_TMAX_MPFID <= _KERNEL_TMAX_H) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_H		_KERNEL_T_MPFID;							/**< %jp{固定長メモリプールIDの型}%en{type of Fixed-Size Memory Pool-ID} */
#elif (_KERNEL_TMAX_MPFID <= _KERNEL_TMAX_UH) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UH		_KERNEL_T_MPFID;							/**< %jp{固定長メモリプールIDの型}%en{type of Fixed-Size Memory Pool-ID} */
#elif (_KERNEL_TMAX_MPFID <= _KERNEL_TMAX_W) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_W		_KERNEL_T_MPFID;							/**< %jp{固定長メモリプールIDの型}%en{type of Fixed-Size Memory Pool-ID} */
#elif (_KERNEL_TMAX_MPFID <= _KERNEL_TMAX_UW) && !_KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_UW		_KERNEL_T_MPFID;							/**< %jp{固定長メモリプールIDの型}%en{type of Fixed-Size Memory Pool-ID} */
#elif (_KERNEL_TMAX_MPFID <= _KERNEL_TMAX_D) && _KERNEL_OPT_SIGNED_INT
typedef _KERNEL_T_FAST_D		_KERNEL_T_MPFID;							/**< %jp{固定長メモリプールIDの型}%en{type of Fixed-Size Memory Pool-ID} */
#else
typedef _KERNEL_T_FAST_UD		_KERNEL_T_MPFID;							/**< %jp{固定長メモリプールIDの型}%en{type of Fixed-Size Memory Pool-ID} */
#endif



#endif	/* _KERNEL__core_objid_h__ */



/* end of file */
