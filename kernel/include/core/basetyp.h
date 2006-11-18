/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  basetyp.h
 * @brief %jp{カーネル型定義ヘッダファイル}%en{basic type header file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__core__basetyp_h__
#define _KERNEL__core__basetyp_h__


/* %jp{コンパイラ判別} */
#include "core/cmpl.h"



#include <limits.h>

#if _KERNEL_CMPL_STDINT_H
#include <stdint.h>
#endif


/* %jp{厳密な幅の型定義} */

#if _KERNEL_CMPL_STDINT_H		/* %jp{stdint.h が使える場合} */

/* %jp{8bit幅の符号付き整数型} */
typedef int8_t						_KERNEL_T_B;
#define _KERNEL_TMIN_B				INT8_MIN
#define _KERNEL_TMAX_B				INT8_MAX
#define _KERNEL_TBIT_B				8

/* %jp{8bit幅の符号無し整数型} */
typedef uint8_t						_KERNEL_T_UB;
#define _KERNEL_TMIN_UB				0
#define _KERNEL_TMAX_UB				UINT8_MAX
#define _KERNEL_TBIT_UB				8

/* %jp{16bit幅の符号付き整数型} */
typedef int16_t						_KERNEL_T_H;
#define _KERNEL_TMIN_H				INT16_MIN
#define _KERNEL_TMAX_H				INT16_MAX
#define _KERNEL_TBIT_H				16

/* %jp{16bit幅の符号無し整数型} */
typedef uint16_t					_KERNEL_T_UH;
#define _KERNEL_TMIN_UH				0
#define _KERNEL_TMAX_UH				UINT16_MAX
#define _KERNEL_TBIT_UH				16

/* %jp{32bit幅の符号付き整数型} */
typedef int32_t						_KERNEL_T_W;
#define _KERNEL_TMIN_W				INT32_MIN
#define _KERNEL_TMAX_W				INT32_MAX
#define _KERNEL_TBIT_W				32

/* %jp{32bit幅の符号無し整数型} */
typedef uint32_t					_KERNEL_T_UW;
#define _KERNEL_TMIN_UW				0
#define _KERNEL_TMAX_UW				UINT32_MAX
#define _KERNEL_TBIT_UW				32

/* %jp{64bit幅の符号付き整数型} */
typedef int64_t						_KERNEL_T_D;
#define _KERNEL_TMIN_D				INT64_MIN
#define _KERNEL_TMAX_D				INT64_MAX
#define _KERNEL_TBIT_D				64

/* %jp{64bit幅の符号無し整数型} */
typedef uint64_t					_KERNEL_T_UD;
#define _KERNEL_TMIN_UD				0
#define _KERNEL_TMAX_UD				UINT64_MAX
#define _KERNEL_TBIT_UD				64

/* %jp{64bit型の有効化} */
#define _KERNEL_ENABLE64			TRUE

/* %jp{64bit定数の定義} */
#define _KERNEL_CONSTNAT_INT64(x)	(x ## LL)
#define _KERNEL_CONSTNAT_UINT64(x)	(x ## ULL)

#else	/* %jp{stdint.h が使えない場合} */

/* %jp{8bit幅の符号付き整数型} */
typedef signed char					_KERNEL_T_B;
#define _KERNEL_TMIN_B				SCHAR_MIN
#define _KERNEL_TMAX_B				SCHAR_MAX
#define _KERNEL_TBIT_B				8

/* %jp{8bit幅の符号無し整数型} */
typedef unsigned char				_KERNEL_T_UB;
#define _KERNEL_TMIN_UB				0
#define _KERNEL_TMAX_UB				UCHAR_MAX
#define _KERNEL_TBIT_UB				8

/* %jp{16bit幅の符号付き整数型} */
typedef signed short				_KERNEL_T_H;
#define _KERNEL_TMIN_H				SHRT_MIN
#define _KERNEL_TMAX_H				SHRT_MAX
#define _KERNEL_TBIT_H				16

/* %jp{16bit幅の符号無し整数型} */
typedef unsigned short				_KERNEL_T_UH;
#define _KERNEL_TMIN_UH				0
#define _KERNEL_TMAX_UH				USHRT_MAX
#define _KERNEL_TBIT_UH				16

/* %jp{32bit幅の符号付き整数型} */
typedef signed long					_KERNEL_T_W;
#define _KERNEL_TMIN_W				LONG_MIN
#define _KERNEL_TMAX_W				LONG_MAX
#define _KERNEL_TBIT_W				32

/* %jp{32bit幅の符号無し整数型} */
typedef unsigned long				_KERNEL_T_UW;
#define _KERNEL_TMIN_UW				0
#define _KERNEL_TMAX_UW				ULONG_MAX
#define _KERNEL_TBIT_UW				32


#if _KERNEL_CMPL_64BIT	/* %jp{コンパイラが64bitをサポートしているなら} */

/* %jp{64bit幅の符号付き整数型} */
typedef _KERNEL_CMPL_INT64			_KERNEL_T_D;	
#define _KERNEL_TMIN_D				_KERNEL_CMPL_TMIN_INT64
#define _KERNEL_TMAX_D				_KERNEL_CMPL_TMAX_INT64
#define _KERNEL_TBIT_D				64

/* %jp{64bit幅の符号無し整数型} */
typedef _KERNEL_CMPL_UINT64			_KERNEL_T_UD;	
#define _KERNEL_TMIN_UD				_KERNEL_CMPL_TMIN_UINT64
#define _KERNEL_TMAX_UD				_KERNEL_CMPL_TMAX_UINT64
#define _KERNEL_TBIT_UD				64

/* %jp{64bit型の有効化} */
#define _KERNEL_ENABLE64			TRUE

/* %jp{64bit定数の定義} */
#define _KERNEL_CONSTNAT_INT64(x)	_KERNEL_CMPL_CONSTNAT_INT64(x)
#define _KERNEL_CONSTNAT_UINT64(x)	_KERNEL_CMPL_CONSTNAT_UINT64(x)

#else	/* %jp{コンパイラが64bitを未サポートなら} */

/* %jp{64bit型は無効} */
#define _KERNEL_ENABLE64			FALSE

#endif

#endif	/* _KERNEL_CMPL_STDINT_H */



/* %jp{プロセッサに適した符号付き整数型} */
typedef int							_KERNEL_T_PROC_INT;
#define _KERNEL_TMIN_PROC_INT		INT_MIN
#define _KERNEL_TMAX_PROC_INT		INT_MAX
#if (_KERNEL_TMIN_PROC_INT >= _KERNEL_TMIN_B) && (_KERNEL_TMAX_PROC_INT <= _KERNEL_TMAX_B)
#define _KERNEL_TBIT_PROC_INT		_KERNEL_TBIT_B
#elif (_KERNEL_TMIN_PROC_INT >= _KERNEL_TMIN_H) && (_KERNEL_TMAX_PROC_INT <= _KERNEL_TMAX_H)
#define _KERNEL_TBIT_PROC_INT		_KERNEL_TBIT_H
#elif (_KERNEL_TMIN_PROC_INT >= _KERNEL_TMIN_W) && (_KERNEL_TMAX_PROC_INT <= _KERNEL_TMAX_W)
#define _KERNEL_TBIT_PROC_INT		_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_PROC_INT		_KERNEL_TBIT_UD
#endif

/* %jp{プロセッサに適した符号無し整数型} */
typedef unsigned  int				_KERNEL_T_PROC_UINT;
#define _KERNEL_TMIN_PROC_UINT		0
#define _KERNEL_TMAX_PROC_UINT		UINT_MAX
#if (_KERNEL_TMIN_PROC_UINT >= _KERNEL_TMIN_UB) && (_KERNEL_TMAX_PROC_UINT <= _KERNEL_TMAX_UB)
#define _KERNEL_TBIT_PROC_UINT		_KERNEL_TBIT_UB
#elif (_KERNEL_TMIN_PROC_UINT >= _KERNEL_TMIN_UH) && (_KERNEL_TMAX_PROC_UINT <= _KERNEL_TMAX_UH)
#define _KERNEL_TBIT_PROC_UINT		_KERNEL_TBIT_UH
#elif (_KERNEL_TMIN_PROC_UINT >= _KERNEL_TMIN_UW) && (_KERNEL_TMAX_PROC_UINT <= _KERNEL_TMAX_UW)
#define _KERNEL_TBIT_PROC_UINT		_KERNEL_TBIT_UW
#else
#define _KERNEL_TBIT_PROC_UINT		_KERNEL_TBIT_UD
#endif



#if _KERNEL_CMPL_STDINT_H		/* %jp{stdint.h が使える場合} */

/* %jp{メモリサイズ重視の型定義} */

/* %jp{少なくとも8bitを表せる最小の符号付き整数型} */
typedef int_least8_t				_KERNEL_T_LEAST_B;
#define _KERNEL_TMIN_LEAST_B		INT_LEAST8_MIN
#define _KERNEL_TMAX_LEAST_B		INT_LEAST8_MAX
#if (_KERNEL_TMIN_LEAST_B >= _KERNEL_TMIN_B) && (_KERNEL_TMAX_LEAST_B <= _KERNEL_TMAX_B)
#define _KERNEL_TBIT_LEAST_B		_KERNEL_TBIT_B
#elif (_KERNEL_TMIN_LEAST_B >= _KERNEL_TMIN_H) && (_KERNEL_TMAX_LEAST_B <= _KERNEL_TMAX_H)
#define _KERNEL_TBIT_LEAST_B		_KERNEL_TBIT_H
#elif (_KERNEL_TMIN_LEAST_B >= _KERNEL_TMIN_W) && (_KERNEL_TMAX_LEAST_B <= _KERNEL_TMAX_W)
#define _KERNEL_TBIT_LEAST_B		_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_LEAST_B		_KERNEL_TBIT_D
#endif

/* %jp{少なくとも8bitを表せる最小の符号無し整数型} */
typedef uint_least8_t				_KERNEL_T_LEAST_UB;	
#define _KERNEL_TMIN_LEAST_UB		0
#define _KERNEL_TMAX_LEAST_UB		UINT_LEAST8_MAX
#if (_KERNEL_TMIN_LEAST_UB >= _KERNEL_TMIN_UB) && (_KERNEL_TMAX_LEAST_UB <= _KERNEL_TMAX_UB)
#define _KERNEL_TBIT_LEAST_UB		_KERNEL_TBIT_B
#elif (_KERNEL_TMIN_LEAST_UB >= _KERNEL_TMIN_UH) && (_KERNEL_TMAX_LEAST_UB <= _KERNEL_TMAX_UH)
#define _KERNEL_TBIT_LEAST_UB		_KERNEL_TBIT_H
#elif (_KERNEL_TMIN_LEAST_UB >= _KERNEL_TMIN_UW) && (_KERNEL_TMAX_LEAST_UB <= _KERNEL_TMAX_UW)
#define _KERNEL_TBIT_LEAST_UB		_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_LEAST_UB		_KERNEL_TBIT_D
#endif

/* %jp{少なくとも16bitを表せる最小の符号付き整数型} */
typedef int_least16_t				_KERNEL_T_LEAST_H;
#define _KERNEL_TMIN_LEAST_H		INT_LEAST16_MIN
#define _KERNEL_TMAX_LEAST_H		INT_LEAST16_MAX
#if (_KERNEL_TMIN_LEAST_H >= _KERNEL_TMIN_H) && (_KERNEL_TMAX_LEAST_H <= _KERNEL_TMAX_H)
#define _KERNEL_TBIT_LEAST_H		_KERNEL_TBIT_H
#elif (_KERNEL_TMIN_LEAST_H >= _KERNEL_TMIN_W) && (_KERNEL_TMAX_LEAST_H <= _KERNEL_TMAX_W)
#define _KERNEL_TBIT_LEAST_H		_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_LEAST_H		_KERNEL_TBIT_D
#endif

/* %jp{少なくとも16bitを表せる最小の符号無し整数型} */
typedef uint_least16_t				_KERNEL_T_LEAST_UH;	
#define _KERNEL_TMIN_LEAST_UH		0
#define _KERNEL_TMAX_LEAST_UH		UINT_LEAST16_MAX
#if (_KERNEL_TMIN_LEAST_UH >= _KERNEL_TMIN_UH) && (_KERNEL_TMAX_LEAST_UH <= _KERNEL_TMAX_UH)
#define _KERNEL_TBIT_LEAST_UH		_KERNEL_TBIT_UH
#elif (_KERNEL_TMIN_LEAST_UH >= _KERNEL_TMIN_UW) && (_KERNEL_TMAX_LEAST_UH <= _KERNEL_TMAX_UW)
#define _KERNEL_TBIT_LEAST_UH		_KERNEL_TBIT_UW
#else
#define _KERNEL_TBIT_LEAST_UH		_KERNEL_TBIT_UD
#endif

/* %jp{少なくとも32bitを表せる最小の符号付き整数型} */
typedef int_least32_t				_KERNEL_T_LEAST_W;
#define _KERNEL_TMIN_LEAST_W		INT_LEAST32_MIN
#define _KERNEL_TMAX_LEAST_W		INT_LEAST32_MAX
#if (_KERNEL_TMIN_LEAST_W >= _KERNEL_TMIN_W) && (_KERNEL_TMAX_LEAST_W <= _KERNEL_TMAX_W)
#define _KERNEL_TBIT_LEAST_W		_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_LEAST_W		_KERNEL_TBIT_D
#endif

/* %jp{少なくとも32bitを表せる最小の符号無し整数型} */
typedef uint_least32_t				_KERNEL_T_LEAST_UW;
#define _KERNEL_TMIN_LEAST_UW		0
#define _KERNEL_TMAX_LEAST_UW		UINT_LEAST32_MAX
#if (_KERNEL_TMIN_LEAST_UW >= _KERNEL_TMIN_UW) && (_KERNEL_TMAX_LEAST_UW <= _KERNEL_TMAX_UW)
#define _KERNEL_TBIT_LEAST_UW		_KERNEL_TBIT_UW
#else
#define _KERNEL_TBIT_LEAST_UW		_KERNEL_TBIT_UD
#endif

/* %jp{少なくとも64bitを表せる最小の符号付き整数型} */
typedef int_least64_t				_KERNEL_T_LEAST_D;
#define _KERNEL_TMIN_LEAST_D		INT_LEAST64_MIN
#define _KERNEL_TMAX_LEAST_D		INT_LEAST64_MAX
#define _KERNEL_TBIT_LEAST_D		_KERNEL_TBIT_D

/* %jp{少なくとも64bitを表せる最小の符号無し整数型} */
typedef uint_least64_t				_KERNEL_T_LEAST_UD;
#define _KERNEL_TMIN_LEAST_UD		0
#define _KERNEL_TMAX_LEAST_UD		UINT_LEAST64_MAX
#define _KERNEL_TBIT_LEAST_UD		_KERNEL_TBIT_UD


/* %jp{速度重視の型定義} */

/* %jp{少なくとも8bitを表せる最速の符号付き整数型} */
typedef int_fast8_t					_KERNEL_T_FAST_B;
#define _KERNEL_TMIN_FAST_B			INT_FAST8_MIN
#define _KERNEL_TMAX_FAST_B			INT_FAST8_MAX
#if (_KERNEL_TMIN_FAST_B >= _KERNEL_TMIN_B) && (_KERNEL_TMAX_FAST_B <= _KERNEL_TMAX_B)
#define _KERNEL_TBIT_FAST_B			_KERNEL_TBIT_B
#elif (_KERNEL_TMIN_FAST_B >= _KERNEL_TMIN_H) && (_KERNEL_TMAX_FAST_B <= _KERNEL_TMAX_H)
#define _KERNEL_TBIT_FAST_B			_KERNEL_TBIT_H
#elif (_KERNEL_TMIN_FAST_B >= _KERNEL_TMIN_W) && (_KERNEL_TMAX_FAST_B <= _KERNEL_TMAX_W)
#define _KERNEL_TBIT_FAST_B			_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_FAST_B			_KERNEL_TBIT_D
#endif

/* %jp{少なくとも8bitを表せる最速の符号無し整数型} */
typedef uint_fast8_t				_KERNEL_T_FAST_UB;	
#define _KERNEL_TMIN_FAST_UB		0
#define _KERNEL_TMAX_FAST_UB		UINT_FAST8_MAX
#if (_KERNEL_TMIN_FAST_UB >= _KERNEL_TMIN_UB) && (_KERNEL_TMAX_FAST_UB <= _KERNEL_TMAX_UB)
#define _KERNEL_TBIT_FAST_UB		_KERNEL_TBIT_B
#elif (_KERNEL_TMIN_FAST_UB >= _KERNEL_TMIN_UH) && (_KERNEL_TMAX_FAST_UB <= _KERNEL_TMAX_UH)
#define _KERNEL_TBIT_FAST_UB		_KERNEL_TBIT_H
#elif (_KERNEL_TMIN_FAST_UB >= _KERNEL_TMIN_UW) && (_KERNEL_TMAX_FAST_UB <= _KERNEL_TMAX_UW)
#define _KERNEL_TBIT_FAST_UB		_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_FAST_UB		_KERNEL_TBIT_D
#endif

/* %jp{少なくとも16bitを表せる最速の符号付き整数型} */
typedef int_fast16_t				_KERNEL_T_FAST_H;
#define _KERNEL_TMIN_FAST_H			INT_FAST16_MIN
#define _KERNEL_TMAX_FAST_H			INT_FAST16_MAX
#if (_KERNEL_TMIN_FAST_H >= _KERNEL_TMIN_H) && (_KERNEL_TMAX_FAST_H <= _KERNEL_TMAX_H)
#define _KERNEL_TBIT_FAST_H			_KERNEL_TBIT_H
#elif (_KERNEL_TMIN_FAST_H >= _KERNEL_TMIN_W) && (_KERNEL_TMAX_FAST_H <= _KERNEL_TMAX_W)
#define _KERNEL_TBIT_FAST_H			_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_FAST_H			_KERNEL_TBIT_D
#endif

/* %jp{少なくとも16bitを表せる最速の符号無し整数型} */
typedef uint_fast16_t				_KERNEL_T_FAST_UH;	
#define _KERNEL_TMIN_FAST_UH		0
#define _KERNEL_TMAX_FAST_UH		UINT_FAST16_MAX
#if (_KERNEL_TMIN_FAST_UH >= _KERNEL_TMIN_UH) && (_KERNEL_TMAX_FAST_UH <= _KERNEL_TMAX_UH)
#define _KERNEL_TBIT_FAST_UH		_KERNEL_TBIT_UH
#elif (_KERNEL_TMIN_FAST_UH >= _KERNEL_TMIN_UW) && (_KERNEL_TMAX_FAST_UH <= _KERNEL_TMAX_UW)
#define _KERNEL_TBIT_FAST_UH		_KERNEL_TBIT_UW
#else
#define _KERNEL_TBIT_FAST_UH		_KERNEL_TBIT_UD
#endif

/* %jp{少なくとも32bitを表せる最速の符号付き整数型} */
typedef int_fast32_t				_KERNEL_T_FAST_W;
#define _KERNEL_TMIN_FAST_W			INT_FAST32_MIN
#define _KERNEL_TMAX_FAST_W			INT_FAST32_MAX
#if (_KERNEL_TMIN_FAST_W >= _KERNEL_TMIN_W) && (_KERNEL_TMAX_FAST_W <= _KERNEL_TMAX_W)
#define _KERNEL_TBIT_FAST_W			_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_FAST_W			_KERNEL_TBIT_D
#endif

/* %jp{少なくとも32bitを表せる最速の符号無し整数型} */
typedef uint_fast32_t				_KERNEL_T_FAST_UW;
#define _KERNEL_TMIN_FAST_UW		0
#define _KERNEL_TMAX_FAST_UW		UINT_FAST32_MAX
#if (_KERNEL_TMIN_FAST_UW >= _KERNEL_TMIN_UW) && (_KERNEL_TMAX_FAST_UW <= _KERNEL_TMAX_UW)
#define _KERNEL_TBIT_FAST_UW		_KERNEL_TBIT_UW
#else
#define _KERNEL_TBIT_FAST_UW		_KERNEL_TBIT_UD
#endif

/* %jp{少なくとも64bitを表せる最速の符号付き整数型} */
typedef int_fast64_t				_KERNEL_T_FAST_D;
#define _KERNEL_TMIN_FAST_D			INT_FAST64_MIN
#define _KERNEL_TMAX_FAST_D			INT_FAST64_MAX
#define _KERNEL_TBIT_FAST_D			_KERNEL_TBIT_D

/* %jp{少なくとも64bitを表せる最速の符号無し整数型} */
typedef uint_fast64_t				_KERNEL_T_FAST_UD;
#define _KERNEL_TMIN_FAST_UD		0
#define _KERNEL_TMAX_FAST_UD		UINT_FAST64_MAX
#define _KERNEL_TBIT_FAST_UD		_KERNEL_TBIT_UD


/* %jp{ポインタが格納可能な整数型定義} */

/* %jp{ポインタが格納可能な符号付き整数型} */
typedef intptr_t					_KERNEL_T_INTPTR;
#define _KERNEL_TMIN_INTPTR			INTPTR_MIN
#define _KERNEL_TMAX_INTPTR			INTPTR_MAX
#if (_KERNEL_TMIN_INTPTR >= _KERNEL_TMIN_B) && (_KERNEL_TMAX_INTPTR <= _KERNEL_TMAX_B)
#define _KERNEL_TBIT_INTPTR			_KERNEL_TBIT_B
#elif (_KERNEL_TMIN_INTPTR >= _KERNEL_TMIN_H) && (_KERNEL_TMAX_INTPTR <= _KERNEL_TMAX_H)
#define _KERNEL_TBIT_INTPTR			_KERNEL_TBIT_H
#elif (_KERNEL_TMIN_INTPTR >= _KERNEL_TMIN_W) && (_KERNEL_TMAX_INTPTR <= _KERNEL_TMAX_W)
#define _KERNEL_TBIT_INTPTR			_KERNEL_TBIT_W
#else
#define _KERNEL_TBIT_INTPTR			_KERNEL_TBIT_D
#endif

/* %jp{ポインタが格納可能な符号無し整数型} */
typedef uintptr_t					_KERNEL_T_UINTPTR;
#define _KERNEL_TMIN_UINTPTR		0
#define _KERNEL_TMAX_UINTPTR		UINTPTR_MAX
#if (_KERNEL_TMIN_UINTPTR >= _KERNEL_TMIN_UB) && (_KERNEL_TMAX_UINTPTR <= _KERNEL_TMAX_UB)
#define _KERNEL_TBIT_UINTPTR		_KERNEL_TBIT_UB
#elif (_KERNEL_TMIN_UINTPTR >= _KERNEL_TMIN_UH) && (_KERNEL_TMAX_UINTPTR <= _KERNEL_TMAX_UH)
#define _KERNEL_TBIT_UINTPTR		_KERNEL_TBIT_UH
#elif (_KERNEL_TMIN_UINTPTR >= _KERNEL_TMIN_UW) && (_KERNEL_TMAX_UINTPTR <= _KERNEL_TMAX_UW)
#define _KERNEL_TBIT_UINTPTR		_KERNEL_TBIT_UW
#else
#define _KERNEL_TBIT_UINTPTR		_KERNEL_TBIT_UD
#endif


#else	/* %jp{stdint.h が使えない場合} */

/* %jp{メモリサイズ重視の型定義} */

/* %jp{少なくとも8bitを表せる最小の符号付き整数型} */
typedef _KERNEL_T_B					_KERNEL_T_LEAST_B;
#define _KERNEL_TMIN_LEAST_B		_KERNEL_TMIN_B
#define _KERNEL_TMAX_LEAST_B		_KERNEL_TMAX_B
#define _KERNEL_TBIT_LEAST_B		_KERNEL_TBIT_B

/* %jp{少なくとも8bitを表せる最小の符号無し整数型} */
typedef _KERNEL_T_UB				_KERNEL_T_LEAST_UB;
#define _KERNEL_TMIN_LEAST_UB		_KERNEL_TMIN_UB
#define _KERNEL_TMAX_LEAST_UB		_KERNEL_TMAX_UB
#define _KERNEL_TBIT_LEAST_UB		_KERNEL_TBIT_UB

/* %jp{少なくとも16bitを表せる最小の符号付き整数型} */
typedef _KERNEL_T_H					_KERNEL_T_LEAST_H;
#define _KERNEL_TMIN_LEAST_H		_KERNEL_TMIN_H
#define _KERNEL_TMAX_LEAST_H		_KERNEL_TMAX_H
#define _KERNEL_TBIT_LEAST_H		_KERNEL_TBIT_H

/* %jp{少なくとも16bitを表せる最小の符号無し整数型} */
typedef _KERNEL_T_UH				_KERNEL_T_LEAST_UH;
#define _KERNEL_TMIN_LEAST_UH		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_LEAST_UH		_KERNEL_TMAX_UH
#define _KERNEL_TBIT_LEAST_UH		_KERNEL_TBIT_UH

/* %jp{少なくとも32bitを表せる最小の符号付き整数型} */
typedef _KERNEL_T_W					_KERNEL_T_LEAST_W;
#define _KERNEL_TMIN_LEAST_W		_KERNEL_TMIN_W
#define _KERNEL_TMAX_LEAST_W		_KERNEL_TMAX_W
#define _KERNEL_TBIT_LEAST_W		_KERNEL_TBIT_W

/* %jp{少なくとも32bitを表せる最小の符号無し整数型} */
typedef _KERNEL_T_UW				_KERNEL_T_LEAST_UW;
#define _KERNEL_TMIN_LEAST_UW		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_LEAST_UW		_KERNEL_TMAX_UW
#define _KERNEL_TBIT_LEAST_UW		_KERNEL_TBIT_UW


#if _KERNEL_ENABLE64

/* %jp{少なくとも64bitを表せる最小の符号付き整数型} */
typedef _KERNEL_T_D					_KERNEL_T_LEAST_D;
#define _KERNEL_TMIN_LEAST_D		_KERNEL_TMIN_D
#define _KERNEL_TMAX_LEAST_D		_KERNEL_TMAX_D
#define _KERNEL_TBIT_LEAST_D		_KERNEL_TBIT_D

/* %jp{少なくとも64bitを表せる最小の符号無し整数型} */
typedef _KERNEL_T_UD				_KERNEL_T_LEAST_UD;
#define _KERNEL_TMIN_LEAST_UD		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_LEAST_UD		_KERNEL_TMAX_UD
#define _KERNEL_TBIT_LEAST_UD		_KERNEL_TBIT_UD

#endif


/* %jp{速度重視の型定義} */

/* %jp{少なくとも8bitを表せる最速の符号付き整数型} */
#if (_KERNEL_TMIN_B >= _KERNEL_TMIN_PROC_INT) && (_KERNEL_TMAX_B <= _KERNEL_TMAX_PROC_INT)
typedef _KERNEL_T_PROC_INT			_KERNEL_T_FAST_B;
#define _KERNEL_TMIN_FAST_B			_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_FAST_B			_KERNEL_TMAX_PROC_INT
#define _KERNEL_TBIT_FAST_B			_KERNEL_TBIT_PROC_INT
#else
typedef _KERNEL_T_B					_KERNEL_T_FAST_B;
#define _KERNEL_TMIN_FAST_B			_KERNEL_TMIN_B
#define _KERNEL_TMAX_FAST_B			_KERNEL_TMAX_B
#define _KERNEL_TBIT_FAST_B			_KERNEL_TBIT_B
#endif

/* %jp{少なくとも8bitを表せる最速の符号無し整数型} */
#if (_KERNEL_TMIN_UB >= _KERNEL_TMIN_PROC_UINT) && (_KERNEL_TMAX_UB <= _KERNEL_TMAX_PROC_UINT)
typedef _KERNEL_T_PROC_UINT			_KERNEL_T_FAST_UB;
#define _KERNEL_TMIN_FAST_UB		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_FAST_UB		_KERNEL_TMAX_PROC_UINT
#define _KERNEL_TBIT_FAST_UB		_KERNEL_TBIT_PROC_UINT
#else
typedef _KERNEL_T_UB				_KERNEL_T_FAST_UB;
#define _KERNEL_TMIN_FAST_UB		_KERNEL_TMIN_UB
#define _KERNEL_TMAX_FAST_UB		_KERNEL_TMAX_UB
#define _KERNEL_TBIT_FAST_UB		_KERNEL_TBIT_UB
#endif

/* %jp{少なくとも16bitを表せる最速の符号付き整数型} */
#if (_KERNEL_TMIN_H >= _KERNEL_TMIN_PROC_INT) && (_KERNEL_TMAX_H <= _KERNEL_TMAX_PROC_INT)
typedef _KERNEL_T_PROC_INT			_KERNEL_T_FAST_H;
#define _KERNEL_TMIN_FAST_H			_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_FAST_H			_KERNEL_TMAX_PROC_INT
#define _KERNEL_TBIT_FAST_H			_KERNEL_TBIT_PROC_INT
#else
typedef _KERNEL_T_H					_KERNEL_T_FAST_H;
#define _KERNEL_TMIN_FAST_H			_KERNEL_TMIN_H
#define _KERNEL_TMAX_FAST_H			_KERNEL_TMAX_H
#define _KERNEL_TBIT_FAST_H			_KERNEL_TBIT_H
#endif

/* %jp{少なくとも16bitを表せる最速の符号無し整数型} */
#if (_KERNEL_TMIN_UH >= _KERNEL_TMIN_PROC_UINT) && (_KERNEL_TMAX_UH <= _KERNEL_TMAX_PROC_UINT)
typedef _KERNEL_T_PROC_UINT			_KERNEL_T_FAST_UH;
#define _KERNEL_TMIN_FAST_UH		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_FAST_UH		_KERNEL_TMAX_PROC_UINT
#define _KERNEL_TBIT_FAST_UH		_KERNEL_TBIT_PROC_UINT
#else
typedef _KERNEL_T_UH				_KERNEL_T_FAST_UH;
#define _KERNEL_TMIN_FAST_UH		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_FAST_UH		_KERNEL_TMAX_UH
#define _KERNEL_TBIT_FAST_UH		_KERNEL_TBIT_UH
#endif

/* %jp{少なくとも32bitを表せる最速の符号付き整数型} */
#if (_KERNEL_TMIN_W >= _KERNEL_TMIN_PROC_INT) && (_KERNEL_TMAX_W <= _KERNEL_TMAX_PROC_INT)
typedef _KERNEL_T_PROC_INT			_KERNEL_T_FAST_W;
#define _KERNEL_TMIN_FAST_W			_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_FAST_W			_KERNEL_TMAX_PROC_INT
#define _KERNEL_TBIT_FAST_W			_KERNEL_TBIT_PROC_INT
#else
typedef _KERNEL_T_W					_KERNEL_T_FAST_W;
#define _KERNEL_TMIN_FAST_W			_KERNEL_TMIN_W
#define _KERNEL_TMAX_FAST_W			_KERNEL_TMAX_W
#define _KERNEL_TBIT_FAST_W			_KERNEL_TBIT_W
#endif

/* %jp{少なくとも32bitを表せる最速の符号無し整数型} */
#if (_KERNEL_TMIN_UW >= _KERNEL_TMIN_PROC_UINT) && (_KERNEL_TMAX_UW <= _KERNEL_TMAX_PROC_UINT)
typedef _KERNEL_T_PROC_UINT			_KERNEL_T_FAST_UW;
#define _KERNEL_TMIN_FAST_UW		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_FAST_UW		_KERNEL_TMAX_PROC_UINT
#define _KERNEL_TBIT_FAST_UW		_KERNEL_TBIT_PROC_UINT
#else
typedef _KERNEL_T_UW				_KERNEL_T_FAST_UW;
#define _KERNEL_TMIN_FAST_UW		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_FAST_UW		_KERNEL_TMAX_UW
#define _KERNEL_TBIT_FAST_UW		_KERNEL_TBIT_UW
#endif


#if _KERNEL_ENABLE64

/* %jp{少なくとも64bitを表せる最速の符号付き整数型} */
#if (_KERNEL_TMIN_D >= _KERNEL_TMIN_PROC_INT) && (_KERNEL_TMAX_D <= _KERNEL_TMAX_PROC_INT)
typedef _KERNEL_T_PROC_INT			_KERNEL_T_FAST_D;
#define _KERNEL_TMIN_FAST_D			_KERNEL_TMIN_PROC_INT
#define _KERNEL_TMAX_FAST_D			_KERNEL_TMAX_PROC_INT
#define _KERNEL_TBIT_FAST_D			_KERNEL_TBIT_PROC_INT
#else
typedef _KERNEL_T_D					_KERNEL_T_FAST_D;
#define _KERNEL_TMIN_FAST_D			_KERNEL_TMIN_D
#define _KERNEL_TMAX_FAST_D			_KERNEL_TMAX_D
#define _KERNEL_TBIT_FAST_D			_KERNEL_TBIT_D
#endif

/* %jp{少なくとも64bitを表せる最速の符号無し整数型} */
#if (_KERNEL_TMIN_UD >= _KERNEL_TBIT_PROC_UINT) && (_KERNEL_TMAX_UD <= _KERNEL_TMAX_PROC_UINT)
typedef _KERNEL_T_PROC_UINT			_KERNEL_T_FAST_UD;
#define _KERNEL_TMIN_FAST_UD		_KERNEL_TMIN_PROC_UINT
#define _KERNEL_TMAX_FAST_UD		_KERNEL_TMAX_PROC_UINT
#define _KERNEL_TBIT_FAST_UD		_KERNEL_TBIT_PROC_UINT
#else
typedef _KERNEL_T_UD				_KERNEL_T_FAST_UD;
#define _KERNEL_TMIN_FAST_UD		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_FAST_UD		_KERNEL_TMAX_UD
#define _KERNEL_TBIT_FAST_UD		_KERNEL_TBIT_UD
#endif

#endif


#if defined(_KERNEL_CMPL_PTR_SIZE)	/* %jp{ポインタサイズが定義されていたら} */
#if _KERNEL_CMPL_PTR_SIZE <= 16		/* %jp{ポインタサイズが16bit以下} */

/* %jp{ポインタが格納可能な整数型定義} */
typedef _KERNEL_T_H					_KERNEL_T_INTPTR;
#define _KERNEL_TMIN_INTPTR			_KERNEL_TMIN_H
#define _KERNEL_TMAX_INTPTR			_KERNEL_TMAX_H
#define _KERNEL_TBIT_INTPTR			_KERNEL_TBIT_H

/* %jp{ポインタが格納可能な符号無し整数型} */
typedef _KERNEL_T_UH				_KERNEL_T_UINTPTR;
#define _KERNEL_TMIN_UINTPTR		_KERNEL_TMIN_UH
#define _KERNEL_TMAX_UINTPTR		_KERNEL_TMAX_UH
#define _KERNEL_TBIT_UINTPTR		_KERNEL_TBIT_UH

#elif _KERNEL_CMPL_PTR_SIZE <= 32	/* %jp{ポインタサイズが32bit以下} */

/* %jp{ポインタが格納可能な整数型定義} */
typedef _KERNEL_T_W					_KERNEL_T_INTPTR;
#define _KERNEL_TMIN_INTPTR			_KERNEL_TMIN_W
#define _KERNEL_TMAX_INTPTR			_KERNEL_TMAX_W
#define _KERNEL_TBIT_INTPTR			_KERNEL_TBIT_W

/* %jp{ポインタが格納可能な符号無し整数型} */
typedef _KERNEL_T_UW				_KERNEL_T_UINTPTR;
#define _KERNEL_TMIN_UINTPTR		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_UINTPTR		_KERNEL_TMAX_UW
#define _KERNEL_TBIT_UINTPTR		_KERNEL_TBIT_UW

#else	/* %jp{ポインタサイズが32bitを超える} */

/* %jp{ポインタが格納可能な整数型定義} */
typedef _KERNEL_T_D					_KERNEL_T_INTPTR;
#define _KERNEL_TMIN_INTPTR			_KERNEL_TMIN_D
#define _KERNEL_TMAX_INTPTR			_KERNEL_TMAX_D
#define _KERNEL_TBIT_INTPTR			_KERNEL_TBIT_D

/* %jp{ポインタが格納可能な符号無し整数型} */
typedef _KERNEL_T_UD				_KERNEL_T_UINTPTR;
#define _KERNEL_TMIN_UINTPTR		_KERNEL_TMIN_UD
#define _KERNEL_TMAX_UINTPTR		_KERNEL_TMAX_UD
#define _KERNEL_TBIT_UINTPTR		_KERNEL_TBIT_UD

#endif

#else	/* %jp{ポインタサイズが未定義なら} */

/* %jp{ポインタが格納可能な整数型定義} */
typedef _KERNEL_T_W					_KERNEL_T_INTPTR;
#define _KERNEL_TMIN_INTPTR			_KERNEL_TMIN_W
#define _KERNEL_TMAX_INTPTR			_KERNEL_TMAX_W
#define _KERNEL_TBIT_INTPTR			_KERNEL_TBIT_W

/* %jp{ポインタが格納可能な符号無し整数型} */
typedef _KERNEL_T_UW				_KERNEL_T_UINTPTR;
#define _KERNEL_TMIN_UINTPTR		_KERNEL_TMIN_UW
#define _KERNEL_TMAX_UINTPTR		_KERNEL_TMAX_UW
#define _KERNEL_TBIT_UINTPTR		_KERNEL_TBIT_UW

#endif

#endif


/* %jp{ポインタ型} */
typedef void*						_KERNEL_T_VP;
#if defined(_KERNEL_CMPL_PTR_SIZE)
#define _KERNEL_TBIT_VP				_KERNEL_CMPL_PTR_SIZE
#else
#define _KERNEL_TBIT_VP				_KERNEL_TBIT_INTPTR
#endif




#if _KERNEL_ENABLE64

/** %jp{ビット幅算出マクロ} */
#define _KERNEL_MAXNUM2BIT(x)											\
	(																	\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000000000) ?  0 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000000001) ?  1 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000000003) ?  2 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000000007) ?  3 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000000000f) ?  4 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000000001f) ?  5 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000000003f) ?  6 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000000007f) ?  7 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000000000ff) ?  8 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000000001ff) ?  9 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000000003ff) ? 10 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000000007ff) ? 11 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000000fff) ? 12 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000001fff) ? 13 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000003fff) ? 14 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000007fff) ? 15 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000000ffff) ? 16 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000001ffff) ? 17 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000003ffff) ? 18 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000007ffff) ? 19 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000000fffff) ? 20 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000001fffff) ? 21 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000003fffff) ? 22 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000007fffff) ? 23 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000000ffffff) ? 24 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000001ffffff) ? 25 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000003ffffff) ? 26 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000007ffffff) ? 27 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000000fffffff) ? 28 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000001fffffff) ? 29 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000003fffffff) ? 30 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000007fffffff) ? 31 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000000ffffffff) ? 32 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000001ffffffff) ? 33 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000003ffffffff) ? 34 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000007ffffffff) ? 35 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000000fffffffff) ? 36 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000001fffffffff) ? 37 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000003fffffffff) ? 38 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000007fffffffff) ? 39 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000000ffffffffff) ? 40 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000001ffffffffff) ? 41 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000003ffffffffff) ? 42 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000007ffffffffff) ? 43 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00000fffffffffff) ? 44 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00001fffffffffff) ? 45 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00003fffffffffff) ? 46 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00007fffffffffff) ? 47 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0000ffffffffffff) ? 48 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0001ffffffffffff) ? 49 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0003ffffffffffff) ? 50 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0007ffffffffffff) ? 51 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x000fffffffffffff) ? 52 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x001fffffffffffff) ? 53 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x003fffffffffffff) ? 54 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x007fffffffffffff) ? 55 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x00ffffffffffffff) ? 56 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x01ffffffffffffff) ? 57 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x03ffffffffffffff) ? 58 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x07ffffffffffffff) ? 59 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x0fffffffffffffff) ? 60 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x1fffffffffffffff) ? 61 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x3fffffffffffffff) ? 62 :		\
		(x) <= _KERNEL_CONSTNAT_INT64(0x7fffffffffffffff) ? 63 : 64		\
	)

#else


/** %jp{ビット幅算出マクロ} */
#define _KERNEL_MAXNUM2BIT(x)			\
	(									\
		(x) <= 0x00000000 ?  0 :		\
		(x) <= 0x00000001 ?  1 :		\
		(x) <= 0x00000003 ?  2 :		\
		(x) <= 0x00000007 ?  3 :		\
		(x) <= 0x0000000f ?  4 :		\
		(x) <= 0x0000001f ?  5 :		\
		(x) <= 0x0000003f ?  6 :		\
		(x) <= 0x0000007f ?  7 :		\
		(x) <= 0x000000ff ?  8 :		\
		(x) <= 0x000001ff ?  9 :		\
		(x) <= 0x000003ff ? 10 :		\
		(x) <= 0x000007ff ? 11 :		\
		(x) <= 0x00000fff ? 12 :		\
		(x) <= 0x00001fff ? 13 :		\
		(x) <= 0x00003fff ? 14 :		\
		(x) <= 0x00007fff ? 15 :		\
		(x) <= 0x0000ffff ? 16 :		\
		(x) <= 0x0001ffff ? 17 :		\
		(x) <= 0x0003ffff ? 18 :		\
		(x) <= 0x0007ffff ? 19 :		\
		(x) <= 0x000fffff ? 20 :		\
		(x) <= 0x001fffff ? 21 :		\
		(x) <= 0x003fffff ? 22 :		\
		(x) <= 0x007fffff ? 23 :		\
		(x) <= 0x00ffffff ? 24 :		\
		(x) <= 0x01ffffff ? 25 :		\
		(x) <= 0x03ffffff ? 26 :		\
		(x) <= 0x07ffffff ? 27 :		\
		(x) <= 0x0fffffff ? 28 :		\
		(x) <= 0x1fffffff ? 29 :		\
		(x) <= 0x3fffffff ? 30 :		\
		(x) <= 0x7fffffff ? 31 : 32		\
	)

#endif


#endif	/* _KERNEL__core__basetyp_h__ */


/* end of file */
