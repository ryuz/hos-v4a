/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  cmpl.h
 * @brief %jp{コンパイラ判定ヘッダファイル}%en{uITRON4.0 kernel type header file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__core__cmpl_h__
#define _KERNEL__core__cmpl_h__

#if !defined(__STDC_VERSION__)
#define __STDC_VERSION__	0
#endif

#if __STDC_VERSION__ >= 199901L && !defined(SDCC)

/* C99(ISO/IEC 9899:1999) */
#define _KERNEL_CMPL_STDINT_H			TRUE						/**< %jp{stdint.hは利用可能か？} */

#elif defined(__GNUC__) && !defined(__STRICT_ANSI__)

/* gcc */
#if defined(__LONG_LONG_MAX__)

#define _KERNEL_CMPL_STDINT_H			FALSE						/**< %jp{stdint.hは利用可能か？} */
#define _KERNEL_CMPL_64BIT				TRUE						/**< %jp{64ビット整数は利用可能か？} */
#define _KERNEL_CMPL_INT64				long long					/**< %jp{符号付き64ビット整数の宣言名} */
#define _KERNEL_CMPL_UINT64				unsigned long long			/**< %jp{符号無し64ビット整数の宣言名} */
#define _KERNEL_CMPL_CONSTNAT_INT64(x)	(x ## LL)					/**< %jp{符号付き64ビット整数の定数生成} */
#define _KERNEL_CMPL_CONSTNAT_UINT64(x)	(x ## ULL)					/**< %jp{符号無し64ビット整数の定数生成} */
#define _KERNEL_CMPL_TMIN_INT64			(-__LONG_LONG_MAX__-1)		/**< %jp{符号付き64ビット整数の最小値} */
#define _KERNEL_CMPL_TMAX_INT64			__LONG_LONG_MAX__ 			/**< %jp{符号付き64ビット整数の最大値} */
#define _KERNEL_CMPL_TMIN_UINT64		(0ULL)						/**< %jp{符号無し64ビット整数の最小値} */
#define _KERNEL_CMPL_TMAX_UINT64		(__LONG_LONG_MAX__*2ULL+1)	/**< %jp{符号無し64ビット整数の最大値} */
#define _KERNEL_CMPL_PTR_SIZE			32							/**< %jp{ポインタサイズを定義するか？} */

#endif

#elif defined(_MSC_VER)

/* Visual-C++ */
#define _KERNEL_CMPL_STDINT_H			FALSE						/**< %jp{stdint.hは利用可能か？} */

#define _KERNEL_CMPL_64BIT				TRUE						/**< %jp{64ビット整数は利用可能か？} */
#define _KERNEL_CMPL_INT64				signed __int64				/**< %jp{符号付き64ビット整数の宣言名} */
#define _KERNEL_CMPL_UINT64				unsigned __int64			/**< %jp{符号無し64ビット整数の宣言名} */
#define _KERNEL_CMPL_CONSTNAT_INT64(x)	(x)							/**< %jp{符号付き64ビット整数の定数生成} */
#define _KERNEL_CMPL_CONSTNAT_UINT64(x)	(x)							/**< %jp{符号無し64ビット整数の定数生成} */
#define _KERNEL_CMPL_TMIN_INT64			(-9223372036854775808)		/**< %jp{符号付き64ビット整数の最小値} */
#define _KERNEL_CMPL_TMAX_INT64			9223372036854775807			/**< %jp{符号付き64ビット整数の最大値} */
#define _KERNEL_CMPL_TMIN_UINT64		0							/**< %jp{符号無し64ビット整数の最小値} */
#define _KERNEL_CMPL_TMAX_UINT64		18446744073709551615		/**< %jp{符号無し64ビット整数の最大値} */
#define _KERNEL_CMPL_PTR_SIZE			32							/**< %jp{ポインタサイズを定義するか？} */


#elif defined(__ARMCC_VERSION) && !defined(__STRICT_ANSI__)

/* armcc */
#define _KERNEL_CMPL_STDINT_H			TRUE						/**< %jp{stdint.hは利用可能か？} */

#else

/* ANSI-C (ISO/IEC 9899:1990) standard compiler */
#define _KERNEL_CMPL_STDINT_H			FALSE						/**< %jp{stdint.hは利用可能か？} */
#define _KERNEL_CMPL_64BIT				FALSE						/**< %jp{64ビット整数は利用可能か？} */

#endif


#endif	/* _KERNEL__core__cmpl_h__ */


/* end of file */
