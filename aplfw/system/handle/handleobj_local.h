/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  handleobj.h
 * @brief %jp{ハンドルオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__handleobj_local_h__
#define __HOS__handleobj_local_h__


#include "handleobj.h"



#ifdef __cplusplus
extern "C" {
#endif

void    HandleObj_Constructor(C_HANDLEOBJ *self, const T_HANDLEOBJ_METHODS *pMethods);	/* コンストラクタ */
void    HandleObj_Destructor(C_HANDLEOBJ *self);										/* デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__handleobj_h__ */


/* end of file */
