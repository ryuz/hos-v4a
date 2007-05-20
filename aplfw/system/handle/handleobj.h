/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handle.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__hdlobj_h__
#define __HOS__hdlobj_h__


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

void    HandleObj_Create(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods);	/* コンストラクタ */
void    HandleObj_Delete(C_HANDLEOBJ *self);										/* デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__hdlobj_h__ */


/* end of file */
