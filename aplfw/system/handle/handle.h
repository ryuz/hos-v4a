/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__handle_h__
#define __HOS__handle_h__


/* 無効ハンドルの定義 */
#define HANDLE_NULL		(0)

/* ハンドル型の定義 */
typedef void*	HANDLE;


#ifdef __cplusplus
extern "C" {
#endif

void Handle_Close(HANDLE handle);			/* ハンドルを閉じる */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__handle_h__ */


/* end of file */
