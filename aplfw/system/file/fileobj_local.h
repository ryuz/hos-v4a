/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fileobj_local.h
 * @brief %jp{ファイルオブジェクト ローカルヘッダファイル}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fileobj_local_h__
#define __HOS__fileobj_local_h__


#include "fileobj.h"
#include "system/handle/handleobj_local.h"
#include "system/sysapi/sysapi.h"


#ifdef __cplusplus
extern "C" {
#endif

void FileObj_Constructor(C_FILEOBJ *self, const T_FILEOBJ_METHODS *pMethods, struct c_drvobj *pDrvObj, int iMode);	/**< コンストラクタ */
void FileObj_Destructor(C_FILEOBJ *self);																			/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__fileobj_local_h__ */


/* end of file */
