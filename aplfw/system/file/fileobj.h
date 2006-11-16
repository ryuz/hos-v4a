/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fileobj.h
 * @brief %jp{ファイルオブジェクト}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__fileobj_h__
#define __HOS__fileobj_h__


#include "system/file/file.h"
#include "system/handle/hdlobj.h"


/* ファイルオブジェクトクラス基本メソッドテーブル */
typedef struct t_fileobj_methods
{
	T_HANDLEOBJ_METHODS HandlObjMethods;
	FILE_ERR  (*pfncIoControl)(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize);
	FILE_POS  (*pfncSeek)(HANDLE hFile, FILE_POS Offset, int iOrign);
	FILE_SIZE (*pfncRead)(HANDLE hFile, void *pBuf, FILE_SIZE Size);
	FILE_SIZE (*pfncWrite)(HANDLE hFile, const void *pData, FILE_SIZE Size);
} T_FILEOBJ_METHODS;


/* ファイルブジェクト基本クラス定義 */
typedef struct c_fileobj
{
	C_HANDLEOBJ HandleObj;								/* ハンドルオブジェクトを継承 */
} C_FILEOBJ;


/* ハンドル変換 */
#define FILE_HANDLE2OBJ(hFile)		((C_FILEOBJ *)hFile)


#ifdef __cplusplus
extern "C" {
#endif

void     FileObj_Create(C_FILEOBJ *self, const T_FILEOBJ_METHODS* pMethods);
void     FileObj_Delete(C_FILEOBJ *self);
#define  FileObj_GetMethods(self)			((T_FILEOBJ_METHODS *)HandleObj_GetMethods(&(self)->HandleObj))

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__file_h__ */


/* end of file */
