/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  type.h
 * @brief %jp{基本型定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__type_h__
#define __HOS__type_h__

	
/* ---------------------------------- */
/*             基本部                 */
/* ---------------------------------- */

/* 基本型 */
typedef	signed char			INT_S8;
typedef	unsigned char		INT_U8;
typedef	signed short		INT_S16;
typedef	unsigned short		INT_U16;
typedef	signed long			INT_S32;
typedef	unsigned long		INT_U32;

/* NULL */
#ifndef NULL
#define	NULL				(0)
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
