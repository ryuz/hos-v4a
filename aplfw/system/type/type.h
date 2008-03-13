/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  type.h
 * @brief %jp{基本型定義}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__type_h__
#define __HOS__type_h__

	
/* ---------------------------------- */
/*             基本部                 */
/* ---------------------------------- */

/* 基本型 */
typedef	signed char			_HOS_SINT8;
typedef	unsigned char		_HOS_UINT8;
typedef	signed short		_HOS_SINT16;
typedef	unsigned short		_HOS_UINT16;
typedef	signed long			_HOS_SINT32;
typedef	unsigned long		_HOS_UINT32;

/* 64bit型 */
#if defined(_HOS_LONGLONG) || defined(__GNUC__) || defined(__ARMCC_VERSION)
#define _HOS_ENABLE64
typedef	signed long long	_HOS_SINT64;
typedef	unsigned long long	_HOS_UINT64;
#elif defined(_MSC_VER)
#define _HOS_ENABLE64
typedef	signed __int64		_HOS_SINT64;
typedef	unsigned __int64	_HOS_UINT64;
#else
typedef	signed long			_HOS_SINT64;
typedef	unsigned long		_HOS_UINT64;
#endif


/* NULL */
#ifndef NULL
#ifdef __cplusplus
#define NULL				(0)
#else
#define NULL				((void *)0)
#endif
#endif



/* ---------------------------------- */
/*            環境依部                */
/* ---------------------------------- */

#define MEMALIGN			sizeof(void *)		/* メモリアライメント定義 */

typedef long				VPARAM;				/* 任意のパラメータ型 */
typedef unsigned long		MEMSIZE;			/* メモリサイズの型 */
typedef unsigned long		FILESIZE;			/* ファイルサイズの型 */
typedef unsigned long		TIME;				/* 時間の型 */



/* ---------------------------------- */
/*            実装依部                */
/* ---------------------------------- */

/* 無効ハンドルの定義 */
#define HANDLE_NULL		(0)

/* ハンドル型の定義 */
typedef void*	HANDLE;




#endif	 /* __HOS__type_h__ */



/* end of file */
