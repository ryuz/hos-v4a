/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fileobj.h
 * @brief %jp{ファイルオブジェクト}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fileobj_h__
#define __HOS__fileobj_h__


#include "system/handle/handleobj.h"
#include "system/file/file.h"

struct c_drvobj;

/* ファイルオブジェクトクラス基本メソッドテーブル */
typedef struct t_fileobj_methods
{
	T_HANDLEOBJ_METHODS	HandlObjMethods;	/* ハンドルオブジェクトを継承 */
} T_FILEOBJ_METHODS;


/* ファイルブジェクト基本クラス定義 */
typedef struct c_fileobj
{
	C_HANDLEOBJ		HandleObj;				/* ハンドルオブジェクトを継承 */
	struct c_drvobj	*pDrvObj;				/* ドライバへの参照 */
} C_FILEOBJ;


#include "drvobj.h"


/* ハンドル変換 */
#define FILE_HANDLE2OBJ(hFile)		((C_FILEOBJ *)(hFile))


#ifdef __cplusplus
extern "C" {
#endif

void FileObj_Create(C_FILEOBJ *self, struct c_drvobj *pDrvObj, const T_FILEOBJ_METHODS *pMethods);
void FileObj_Delete(HANDLE self);

#ifdef __cplusplus
}
#endif




#endif	/* __HOS__file_h__ */


/* end of file */
