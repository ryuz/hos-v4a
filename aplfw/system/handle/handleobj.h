/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handleobj.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__handleobj_h__
#define __HOS__handleobj_h__


#include "system/handle/handle.h"


/* ハンドルオブジェクトクラスのメソッドテーブル定義 */
typedef struct t_handleobj_methods
{
	void (*pfncClose)(HANDLE Handle);		/* 閉じる */
} T_HANDLEOBJ_METHODS;


/* ハンドルオブジェクトクラス定義 */
typedef struct c_handleobj
{
	const T_HANDLEOBJ_METHODS	*pMethods;

	struct c_handleobj			*pParent;		/* 親プロセスのハンドル */
	struct c_handleobj			*pChild;		/* 現プロセスが所有するハンドル */
	struct c_handleobj			*pNext;			/* 次のハンドル */
	struct c_handleobj			*pPrev;			/* 前のハンドル */
} C_HANDLEOBJ;


#ifdef __cplusplus
extern "C" {
#endif

#define HandleObj_GetMethods(self)			((self)->pMethods)

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__handleobj_h__ */


/* end of file */
