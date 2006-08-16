/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  pitrncfg.h
 * @brief %jp{itrncfgのパーサー}%en{perser for itrncfg.h}
 *
 * @version $Id: parssys.h,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__prser_pitrncfg_h__
#define _KERNEL__prser_pitrncfg_h__


#if _KERNEL_CFG_MEM_ALIGN <= 0
#define _KERNEL_MEM_ALIGN			(sizeof(void *))
#else
#define _KERNEL_MEM_ALIGN			_KERNEL_CFG_MEM_ALIGN
#endif


/* %jp{INT型のbit数を定義する} */
#if _KERNEL_CFG_TBIT_INT <= 0		/* default */
#define _KERNEL_TBIT_INT		_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_INT		_KERNEL_CFG_TBIT_INT
#endif

/* %jp{UINT型のbit数を定義する} */
#if _KERNEL_CFG_TBIT_UINT <= 0		/* default */
#define _KERNEL_TBIT_UINT		_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_UINT		_KERNEL_CFG_TBIT_UINT
#endif


/* %jp{VP_INTをポインタ型とするか} */
#define _KERNEL_VP_INT_PTR		_KERNEL_CFG_VP_INT_PTR


/* %jp{BOOL型のbit数を定義する} */
#if _KERNEL_CFG_TBIT_BOOL <= 0		/* default */
#define _KERNEL_TBIT_BOOL		_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_BOOL		_KERNEL_CFG_TBIT_BOOL
#endif


/*  %jp{FN型のbit数を定義する}%en{Function code} */
#if _KERNEL_CFG_TBIT_FN <= 0			/* default */
#define _KERNEL_TBIT_FN			_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_FN			_KERNEL_CFG_TBIT_FN
#endif


/* %jp{ER型のbit数を定義する}%en{Error code(signed integer)} */
#if _KERNEL_CFG_TBIT_ER <= 0			/* default */
#define _KERNEL_TBIT_ER			_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_ER			_KERNEL_CFG_TBIT_ER
#endif


/* %jp{ID型のbit数を定義する}%en{Object ID number(signed integer)} */
#if _KERNEL_CFG_TBIT_ID <= 0			/* default */
#define _KERNEL_TBIT_ID			_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_ID			_KERNEL_CFG_TBIT_ID
#endif


/* %jp{ATR型のbit数を定義する}%en{Object attribute(unsigned integer)} */
#if _KERNEL_CFG_TBIT_ATR <= 0		/* default */
#define _KERNEL_TBIT_ATR			_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_ATR			_KERNEL_CFG_TBIT_ATR
#endif


/* %jp{STAT型のbit数を定義する}%en{Object state(unsigned integer)} */
#if _KERNEL_CFG_TBIT_STAT <= 0		/* default */
#define _KERNEL_TBIT_STAT		_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_STAT		_KERNEL_CFG_TBIT_STAT
#endif


/* %jp{MODE型のbit数を定義する}%en{Service call operational mode(unsigned integer)} */
#if _KERNEL_CFG_TBIT_MODE <= 0		/* default */
#define _KERNEL_TBIT_MODE		_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_MODE		_KERNEL_CFG_TBIT_MODE
#endif


/* %jp{PRI型のbit数を定義する}%en{Priority(signed integer)} */
#if _KERNEL_CFG_TBIT_PRI <= 0		/* default */
#define _KERNEL_TBIT_PRI		_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_PRI		_KERNEL_CFG_TBIT_PRI
#endif


/* %jp{SIZE型のbit数を定義する}%en{Memory area size(unsigned integer)} */
#if _KERNEL_CFG_TBIT_SIZE <= 0		/* default */
#define _KERNEL_TBIT_SIZE		_KERNEL_TBIT_UINTPTR
#else
#define _KERNEL_TBIT_SIZE		_KERNEL_CFG_TBIT_SIZE
#endif


/* %jp{TMO型のbit数を定義する}%en{Timeout} */
#if _KERNEL_CFG_TBIT_TMO <= 0		/* default */
#define _KERNEL_TBIT_TMO		_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_TMO		_KERNEL_CFG_TBIT_TMO
#endif


/* %jp{RELTIM型のbit数を定義する}%en{Relative time(unsigned integer, unit of time is implementation-defined)} */
#if _KERNEL_CFG_TBIT_RELTIM <= 0		/* default */
#define _KERNEL_TBIT_RELTIM		_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_RELTIM		_KERNEL_CFG_TBIT_RELTIM
#endif


/* %jp{SYSTIM型のbit数を定義する}%en{System time(unsigned integer, unit of time is implementation-defined)} */
#define _KERNEL_SYSTIM_STRUCT	_KERNEL_CFG_SYSTIM_STRUCT
#if _KERNEL_CFG_TBIT_SYSTIM < 0		/* default */
#if _KERNEL_SYSTIM_STRUCT		/* %jp{構造体化するなら} */
#define _KERNEL_TBIT_SYSTIM		48
#else
#define _KERNEL_TBIT_SYSTIM		32
#endif
#else
#define _KERNEL_TBIT_SYSTIM		_KERNEL_CFG_TBIT_SYSTIM
#endif


/* %jp{ER_BOOL型のbit数を定義する}%en{Error code or a boolean value} */
#if _KERNEL_CFG_TBIT_ER_BOOL <= 0
#if _KERNEL_TBIT_ER >= _KERNEL_TBIT_BOOL
#define _KERNEL_TBIT_ER_BOOL	_KERNEL_TBIT_ER
#else
#define _KERNEL_TBIT_ER_BOOL	_KERNEL_TBIT_BOOL
#endif
#else
#define _KERNEL_TBIT_ER_BOOL	_KERNEL_CFG_TBIT_ER_BOOL
#endif


/* %jp{ER_IDのbit数を定義する}%en{Error code or an object ID number} */
#if _KERNEL_CFG_TBIT_ER_ID <= 0
#if _KERNEL_TBIT_ER >= _KERNEL_TBIT_ID
#define _KERNEL_TBIT_ER_ID		_KERNEL_TBIT_ER
#else
#define _KERNEL_TBIT_ER_ID		_KERNEL_TBIT_ID
#endif
#else
#define _KERNEL_TBIT_ER_ID		_KERNEL_CFG_TBIT_ER_ID
#endif


/* %jp{ER_IDのbit数を定義する}%en{Error code or an object ID number} */
#if _KERNEL_CFG_TBIT_ER_ID <= 0
#if _KERNEL_TBIT_ER >= _KERNEL_TBIT_ID
#define _KERNEL_TBIT_ER_ID		_KERNEL_TBIT_ER
#else
#define _KERNEL_TBIT_ER_ID		_KERNEL_TBIT_ID
#endif
#else
#define _KERNEL_TBIT_ER_ID		_KERNEL_CFG_TBIT_ER_ID
#endif


/**< %jp{ER_UINTのbit数を定義する}%en{Error code or an unsigned integer} */
#if _KERNEL_CFG_TBIT_ER_UINT <= 0
#if _KERNEL_TBIT_ER >= _KERNEL_TBIT_UINT
#define _KERNEL_TBIT_ER_UINT	_KERNEL_TBIT_ER
#else
#define _KERNEL_TBIT_ER_UINT	_KERNEL_TBIT_UINT
#endif
#else
#define _KERNEL_TBIT_ER_UINT	_KERNEL_CFG_TBIT_ER_UINT
#endif



/**< %jp{タスク例外要因のパターン(符号無し整数)}%en{Bit pattern for the task exception code(unsigned integer)} */
#if _KERNEL_CFG_TBIT_TEXPTN <= 0
#define _KERNEL_TBIT_TEXPTN		_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_TEXPTN		_KERNEL_CFG_TBIT_TEXPTN
#endif


#if _KERNEL_CFG_TBIT_FLGPTN <= 0
#define _KERNEL_TBIT_FLGPTN		_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_FLGPTN		_KERNEL_CFG_TBIT_FLGPTN
#endif


#if _KERNEL_CFG_TBIT_RDVPTN <= 0
#define _KERNEL_TBIT_RDVPTN		_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_RDVPTN		_KERNEL_CFG_TBIT_RDVPTN
#endif


#if _KERNEL_CFG_TBIT_RDVNO <= 0

#define _KERNEL_TBIT_RDVNO		_KERNEL_TBIT_PROC_UINT
#else
#define _KERNEL_TBIT_RDVNO		_KERNEL_CFG_TBIT_RDVNO
#endif


#if _KERNEL_CFG_TBIT_OVRTIM <= 0
#define _KERNEL_TBIT_OVRTIM		_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_OVRTIM		_KERNEL_CFG_TBIT_OVRTIM
#endif


#if _KERNEL_CFG_TBIT_INHNO <= 0
#define _KERNEL_TBIT_INHNO		_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_INHNO		_KERNEL_CFG_TBIT_INHNO
#endif


#if _KERNEL_CFG_TBIT_INTNO <= 0
#define _KERNEL_TBIT_INTNO		_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_INTNO		_KERNEL_CFG_TBIT_INTNO
#endif


#if _KERNEL_CFG_TBIT_EXCNO <= 0
#define _KERNEL_TBIT_EXCNO		_KERNEL_TBIT_PROC_INT
#else
#define _KERNEL_TBIT_EXCNO		_KERNEL_CFG_TBIT_EXCNO
#endif


/* */
/* %jp{優先度の範囲}%en{Priority Range} */
#if _KERNEL_CFG_TMAX_TPRI <= 0
#define _KERNEL_TMAX_TPRI		_KERNEL_TMAX_PROC_INT					/**< %jp{タスク優先度の最大値}%en{Maximum task priority} */
#else
#define _KERNEL_TMAX_TPRI		_KERNEL_CFG_TMAX_TPRI					/**< %jp{タスク優先度の最大値}%en{Maximum task priority} */
#endif

#if _KERNEL_CFG_TMAX_MPRI <= 0
#define _KERNEL_TMAX_MPRI		_KERNEL_TMAX_PROC_INT					/**< %jp{メッセージ優先度の最大値}%en{Maximum message priority} */
#else
#define _KERNEL_TMAX_MPRI		_KERNEL_CFG_TMAX_MPRI					/**< %jp{メッセージ優先度の最大値}%en{Maximum message priority} */
#endif


/* %jp{キューイング／ネスト回数の最大値}%en{Maximum Nesting/Queueing Count} */
#define _KERNEL_TMAX_ACTCNT		_KERNEL_CFG_TMAX_ACTCNT					/**< %jp{タスク起動要求キューイング数の最大値(-1の時デフォルト値)} */
#define _KERNEL_TMAX_WUPCNT		_KERNEL_CFG_TMAX_WUPCNT					/**< %jp{タスク起床要求キューイング数の最大値(-1の時デフォルト値)} */
#define _KERNEL_TMAX_SUSCNT		_KERNEL_CFG_TMAX_SUSCNT					/**< %jp{タスク強制待ち要求ネスト数の最大値(-1の時デフォルト値)} */


/* */

#if _KERNEL_CFG_TEX_TBIT_TEXPTN < 0								/**< %jp{タスク例外要因のビット数} */
#define _KERNEL_TEX_TBIT_TEXPTN	_KERNEL_TBIT_TEXPTN
#else
#define _KERNEL_TEX_TBIT_TEXPTN	_KERNEL_CFG_TEX_TBIT_TEXPTN
#endif

#if _KERNEL_CFG_FLG_TBIT_FLGPTN < 0								/**< %jp{イベントフラグのビット数} */
#define _KERNEL_FLG_TBIT_FLGPTN	_KERNEL_TBIT_FLGPTN
#else
#define _KERNEL_FLG_TBIT_FLGPTN	_KERNEL_CFG_FLG_TBIT_FLGPTN
#endif

#if _KERNEL_CFG_RDV_TBIT_RDVPTN < 0
#define _KERNEL_RDV_TBIT_RDVPTN	_KERNEL_TBIT_RDVPTN				/**< %jp{ランデブ条件のビット数} */
#else
#define _KERNEL_RDV_TBIT_RDVPTN	_KERNEL_CFG_RDV_TBIT_RDVPTN
#endif


/* %jp{セマフォの最大値}%en{Maximum value of the maximum definable semaphore resource count} */
#if _KERNEL_CFG_TMAX_MAXSEM <= 0
#define _KERNEL_TMAX_MAXSEM		_KERNEL_TMAX_PROC_UINT
#else
#define _KERNEL_TMAX_MAXSEM		_KERNEL_CFG_TMAX_MAXSEM
#endif



#endif	/* _KERNEL__prser_pitrncfg_h__ */


/* end of file */
