/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * @version $Id: handle.h,v 1.1 2006-11-05 16:11:07 ryuz Exp $
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

/* ハンドルオブジェクトクラスのメソッドテーブル定義 */
typedef struct t_handleobj_methods
{
	void (*pfncDelete)(HANDLE handle);		/* デストラクタ */
} T_HANDLEOBJ_METHODS;


/* ハンドルオブジェクトクラス定義 */
typedef struct c_handleobj
{
	const T_HANDLEOBJ_METHODS *pMethods;
} C_HANDLEOBJ;


#ifdef __cplusplus
extern "C" {
#endif

void HndleObj_Create(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods);	/* コンストラクタ */
void HndleObj_Delete(C_HANDLEOBJ *self);										/* デストラクタ */

void Handle_Close(HANDLE handle);			/* ハンドルを閉じる */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__handle_h__ */


/* end of file */
