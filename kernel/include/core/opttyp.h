/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  opttyp.h
 * @brief %jp{カーネル内部用最適化型定義ヘッダファイル}%en{optimized type for kernel internal}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core__opttyp_h__
#define _KERNEL__core__opttyp_h__



/* %jp{カーネルで標準に使う型選択} */
#if (_KERNEL_OPT_RW_SIZE <= _KERNEL_OPT_SPEED)

/* %jp{サイズ重視最適化の場合} */

/* %jp{最適化オプションに適した少なくとも8bitを表せる最速の符号付き整数型} */
typedef _KERNEL_T_LEAST_B		_KERNEL_T_OPT_B;
#define _KERNEL_TMIN_OPT_B		_KERNEL_TMIN_LEAST_B
#define _KERNEL_TMAX_OPT_B		_KERNEL_TMAX_LEAST_B
#define _KERNEL_TBIT_OPT_B		_KERNEL_TBIT_LEAST_B

/* %jp{最適化オプションに適した少なくとも8bitを表せる最速の符号無し整数型} */
typedef _KERNEL_T_LEAST_UB		_KERNEL_T_OPT_UB;
#define _KERNEL_TMIN_OPT_UB		_KERNEL_TMIN_LEAST_UB
#define _KERNEL_TMAX_OPT_UB		_KERNEL_TMAX_LEAST_UB
#define _KERNEL_TBIT_OPT_UB		_KERNEL_TBIT_LEAST_UB

/* %jp{最適化オプションに適した少なくとも16bitを表せる最速の符号付き整数型} */
typedef _KERNEL_T_LEAST_H		_KERNEL_T_OPT_H;
#define _KERNEL_TMIN_OPT_H		_KERNEL_TMIN_LEAST_H
#define _KERNEL_TMAX_OPT_H		_KERNEL_TMAX_LEAST_H
#define _KERNEL_TBIT_OPT_H		_KERNEL_TBIT_LEAST_H

/* %jp{最適化オプションに適した少なくとも16bitを表せる最速の符号無し整数型} */
typedef _KERNEL_T_LEAST_UH		_KERNEL_T_OPT_UH;
#define _KERNEL_TMIN_OPT_UH		_KERNEL_TMIN_LEAST_UH
#define _KERNEL_TMAX_OPT_UH		_KERNEL_TMAX_LEAST_UH
#define _KERNEL_TBIT_OPT_UH		_KERNEL_TBIT_LEAST_UH

/* %jp{最適化オプションに適した少なくとも32bitを表せる最速の符号付き整数型} */
typedef _KERNEL_T_LEAST_W		_KERNEL_T_OPT_W;
#define _KERNEL_TMIN_OPT_W		_KERNEL_TMIN_LEAST_W
#define _KERNEL_TMAX_OPT_W		_KERNEL_TMAX_LEAST_W
#define _KERNEL_TBIT_OPT_W		_KERNEL_TBIT_LEAST_W

/* %jp{最適化オプションに適した少なくとも32bitを表せる最速の符号無し整数型} */
typedef _KERNEL_T_LEAST_UW		_KERNEL_T_OPT_UW;
#define _KERNEL_TMIN_OPT_UW		_KERNEL_TMIN_LEAST_UW
#define _KERNEL_TMAX_OPT_UW		_KERNEL_TMAX_LEAST_UW
#define _KERNEL_TBIT_OPT_UW		_KERNEL_TBIT_LEAST_UW


#if _KERNEL_ENABLE64

/* %jp{最適化オプションに適した少なくとも64bitを表せる最速の符号付き整数型} */
typedef _KERNEL_T_LEAST_D		_KERNEL_T_OPT_D;
#define _KERNEL_TMIN_OPT_D		_KERNEL_TMIN_LEAST_D
#define _KERNEL_TMAX_OPT_D		_KERNEL_TMAX_LEAST_D
#define _KERNEL_TBIT_OPT_D		_KERNEL_TBIT_LEAST_D

/* %jp{最適化オプションに適した少なくとも64bitを表せる最速の符号無し整数型} */
typedef _KERNEL_T_LEAST_UD		_KERNEL_T_OPT_UD;
#define _KERNEL_TMIN_OPT_UD		_KERNEL_TMIN_LEAST_UD
#define _KERNEL_TMAX_OPT_UD		_KERNEL_TMAX_LEAST_UD
#define _KERNEL_TBIT_OPT_UD		_KERNEL_TBIT_LEAST_UD

#endif

#else

/* %jp{速度重視最適化の場合} */

/* %jp{最適化オプションに適した少なくとも8bitを表せる最速の符号付き整数型} */
typedef _KERNEL_T_FAST_B		_KERNEL_T_OPT_B;
#define _KERNEL_TMIN_OPT_B		_KERNEL_TMIN_FAST_B
#define _KERNEL_TMAX_OPT_B		_KERNEL_TMAX_FAST_B
#define _KERNEL_TBIT_OPT_B		_KERNEL_TBIT_FAST_B

/* %jp{最適化オプションに適した少なくとも8bitを表せる最速の符号無し整数型} */
typedef _KERNEL_T_FAST_UB		_KERNEL_T_OPT_UB;
#define _KERNEL_TMIN_OPT_UB		_KERNEL_TMIN_FAST_UB
#define _KERNEL_TMAX_OPT_UB		_KERNEL_TMAX_FAST_UB
#define _KERNEL_TBIT_OPT_UB		_KERNEL_TBIT_FAST_UB

/* %jp{最適化オプションに適した少なくとも16bitを表せる最速の符号付き整数型} */
typedef _KERNEL_T_FAST_H		_KERNEL_T_OPT_H;
#define _KERNEL_TMIN_OPT_H		_KERNEL_TMIN_FAST_H
#define _KERNEL_TMAX_OPT_H		_KERNEL_TMAX_FAST_H
#define _KERNEL_TBIT_OPT_H		_KERNEL_TBIT_FAST_H

/* %jp{最適化オプションに適した少なくとも16bitを表せる最速の符号無し整数型} */
typedef _KERNEL_T_FAST_UH		_KERNEL_T_OPT_UH;
#define _KERNEL_TMIN_OPT_UH		_KERNEL_TMIN_FAST_UH
#define _KERNEL_TMAX_OPT_UH		_KERNEL_TMAX_FAST_UH
#define _KERNEL_TBIT_OPT_UH		_KERNEL_TBIT_FAST_UH

/* %jp{最適化オプションに適した少なくとも32bitを表せる最速の符号付き整数型} */
typedef _KERNEL_T_FAST_W		_KERNEL_T_OPT_W;
#define _KERNEL_TMIN_OPT_W		_KERNEL_TMIN_FAST_W
#define _KERNEL_TMAX_OPT_W		_KERNEL_TMAX_FAST_W
#define _KERNEL_TBIT_OPT_W		_KERNEL_TBIT_FAST_W

/* %jp{最適化オプションに適した少なくとも32bitを表せる最速の符号無し整数型} */
typedef _KERNEL_T_FAST_UW		_KERNEL_T_OPT_UW;
#define _KERNEL_TMIN_OPT_UW		_KERNEL_TMIN_FAST_UW
#define _KERNEL_TMAX_OPT_UW		_KERNEL_TMAX_FAST_UW
#define _KERNEL_TBIT_OPT_UW		_KERNEL_TBIT_FAST_UW


#if _KERNEL_ENABLE64

/* %jp{最適化オプションに適した少なくとも64bitを表せる最速の符号付き整数型} */
typedef _KERNEL_T_FAST_D		_KERNEL_T_OPT_D;
#define _KERNEL_TMIN_OPT_D		_KERNEL_TMIN_FAST_D
#define _KERNEL_TMAX_OPT_D		_KERNEL_TMAX_FAST_D
#define _KERNEL_TBIT_OPT_D		_KERNEL_TBIT_FAST_D

/* %jp{最適化オプションに適した少なくとも64bitを表せる最速の符号無し整数型} */
typedef _KERNEL_T_FAST_UD		_KERNEL_T_OPT_UD;
#define _KERNEL_TMIN_OPT_UD		_KERNEL_TMIN_FAST_UD
#define _KERNEL_TMAX_OPT_UD		_KERNEL_TMAX_FAST_UD
#define _KERNEL_TBIT_OPT_UD		_KERNEL_TBIT_FAST_UD

#endif

#endif



#if defined(_KERNEL_PROCATR_SIGNED_INT) && _KERNEL_PROCATR_SIGNED_INT > 0
/* %jp{符号付きが得意なプロセッサの場合} */

typedef	_KERNEL_T_PROC_INT		_KERNEL_T_VINT;
#define _KERNEL_TMIN_VINT		_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_VINT		_KERNEL_TMAX_PROC_INT
#define _KERNEL_TBIT_VINT		_KERNEL_TBIT_PROC_INT

typedef	_KERNEL_T_B				_KERNEL_T_VB;
#define _KERNEL_TMIN_VB			_KERNEL_TMIN_B
#define _KERNEL_TMAX_VB			_KERNEL_TMAX_B
#define _KERNEL_TBIT_VB			_KERNEL_TBIT_B

typedef	_KERNEL_T_OPT_B			_KERNEL_T_OPT_VB;
#define _KERNEL_TMIN_OPT_VB		_KERNEL_TMIN_OPT_B
#define _KERNEL_TMAX_OPT_VB		_KERNEL_TMAX_OPT_B
#define _KERNEL_TBIT_OPT_VB		_KERNEL_TBIT_OPT_B

typedef	_KERNEL_T_H				_KERNEL_T_VH;
#define _KERNEL_TMIN_VH			_KERNEL_TMIN_H
#define _KERNEL_TMAX_VH			_KERNEL_TMAX_H
#define _KERNEL_TBIT_VH			_KERNEL_TBIT_H

typedef	_KERNEL_T_OPT_H			_KERNEL_T_OPT_VH;
#define _KERNEL_TMIN_OPT_VH		_KERNEL_TMIN_OPT_H
#define _KERNEL_TMAX_OPT_VH		_KERNEL_TMAX_OPT_H
#define _KERNEL_TBIT_OPT_VH		_KERNEL_TBIT_OPT_H

typedef	_KERNEL_T_W				_KERNEL_T_VW;
#define _KERNEL_TMIN_VW			_KERNEL_TMIN_W
#define _KERNEL_TMAX_VW			_KERNEL_TMAX_W
#define _KERNEL_TBIT_VW			_KERNEL_TBIT_W

typedef	_KERNEL_T_OPT_W			_KERNEL_T_OPT_VW;
#define _KERNEL_TMIN_OPT_VW		_KERNEL_TMIN_OPT_W
#define _KERNEL_TMAX_OPT_VW		_KERNEL_TMAX_OPT_W
#define _KERNEL_TBIT_OPT_VW		_KERNEL_TBIT_OPT_W

#if _KERNEL_ENABLE64

typedef	_KERNEL_T_D				_KERNEL_T_VD;
#define _KERNEL_TMIN_VD			_KERNEL_TMIN_D
#define _KERNEL_TMAX_VD			_KERNEL_TMAX_D
#define _KERNEL_TBIT_VD			_KERNEL_TBIT_D

typedef	_KERNEL_T_OPT_D			_KERNEL_T_OPT_VD;
#define _KERNEL_TMIN_OPT_VD		_KERNEL_TMIN_OPT_D
#define _KERNEL_TMAX_OPT_VD		_KERNEL_TMAX_OPT_D
#define _KERNEL_TBIT_OPT_VD		_KERNEL_TBIT_OPT_D

#endif

#else
/* %jp{符号無しが得意なプロセッサの場合} */

typedef	_KERNEL_T_PROC_UINT		_KERNEL_T_VINT;
#define _KERNEL_TMIN_VINT		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_VINT		_KERNEL_TMAX_PROC_UINT
#define _KERNEL_TBIT_VINT		_KERNEL_TBIT_PROC_UINT

typedef	_KERNEL_T_UB			_KERNEL_T_VB;
#define _KERNEL_TMIN_VB			_KERNEL_TMIN_UB
#define _KERNEL_TMAX_VB			_KERNEL_TMAX_UB
#define _KERNEL_TBIT_VB			_KERNEL_TBIT_UB

typedef	_KERNEL_T_OPT_UB		_KERNEL_T_OPT_VB;
#define _KERNEL_TMIN_OPT_VB		_KERNEL_TMIN_OPT_UB
#define _KERNEL_TMAX_OPT_VB		_KERNEL_TMAX_OPT_UB
#define _KERNEL_TBIT_OPT_VB		_KERNEL_TBIT_OPT_UB

typedef	_KERNEL_T_UH			_KERNEL_T_VH;
#define _KERNEL_TMIN_VH			_KERNEL_TMIN_UH
#define _KERNEL_TMAX_VH			_KERNEL_TMAX_UH
#define _KERNEL_TBIT_VH			_KERNEL_TBIT_UH

typedef	_KERNEL_T_OPT_UH		_KERNEL_T_OPT_VH;
#define _KERNEL_TMIN_OPT_VH		_KERNEL_TMIN_OPT_UH
#define _KERNEL_TMAX_OPT_VH		_KERNEL_TMAX_OPT_UH
#define _KERNEL_TBIT_OPT_VH		_KERNEL_TBIT_OPT_UH

typedef	_KERNEL_T_UW			_KERNEL_T_VW;
#define _KERNEL_TMIN_VW			_KERNEL_TMIN_UW
#define _KERNEL_TMAX_VW			_KERNEL_TMAX_UW
#define _KERNEL_TBIT_VW			_KERNEL_TBIT_UW

typedef	_KERNEL_T_OPT_UW		_KERNEL_T_OPT_VW;
#define _KERNEL_TMIN_OPT_VW		_KERNEL_TMIN_OPT_UW
#define _KERNEL_TMAX_OPT_VW		_KERNEL_TMAX_OPT_UW
#define _KERNEL_TBIT_OPT_VW		_KERNEL_TBIT_OPT_UW

#if _KERNEL_ENABLE64

typedef	_KERNEL_T_UD			_KERNEL_T_VD;
#define _KERNEL_TMIN_VD			_KERNEL_TMIN_UD
#define _KERNEL_TMAX_VD			_KERNEL_TMAX_UD
#define _KERNEL_TBIT_VD			_KERNEL_TBIT_UD

typedef	_KERNEL_T_OPT_UD		_KERNEL_T_OPT_VD;
#define _KERNEL_TMIN_OPT_VD		_KERNEL_TMIN_OPT_UD
#define _KERNEL_TMAX_OPT_VD		_KERNEL_TMAX_OPT_UD
#define _KERNEL_TBIT_OPT_VD		_KERNEL_TBIT_OPT_UD

#endif


#endif


#endif	/* _KERNEL__core__opttyp_h__ */


/* end of file */
