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


/* ハンドル変換 */
#define FILE_HANDLE2OBJ(hFile)		((C_FILEOBJ *)(hFile))


#ifdef __cplusplus
extern "C" {
#endif

void FileObj_Delete(C_FILEOBJ *self);	/**< デストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__fileobj_local_h__ */


/* end of file */
