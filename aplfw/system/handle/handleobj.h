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
	void (*pfncClose)(HANDLE handle);		/* 閉じる */
} T_HANDLEOBJ_METHODS;


/* ハンドルオブジェクトクラス定義 */
typedef struct c_handleobj
{
	const T_HANDLEOBJ_METHODS *pMethods;
} C_HANDLEOBJ;


#ifdef __cplusplus
extern "C" {
#endif

HANDLE  HandleObj_Create(const T_HANDLEOBJ_METHODS *pMethods);							/* 生成 */
void    HandleObj_Delete(HANDLE Handle);												/* 削除 */

#define HandleObj_GetMethods(self)			((self)->pMethods)

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__handleobj_h__ */


/* end of file */
