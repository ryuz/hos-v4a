/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバオブジェクトの基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__drvobj_h__
#define __HOS__drvobj_h__


#include "system/handle/handleobj.h"
#include "file.h"


struct c_drvobj;
struct c_fileobj;

/* デバイスドライバオブジェクト基本クラス メソッドテーブル */
typedef struct t_drvobj_methods
{
	T_HANDLEOBJ_METHODS		HandleObj_Methods;		/**< ハンドルオブジェクトを継承 */
	
	HANDLE    (*pfncOpen)(struct c_drvobj *self, const char *pszPath, int iMode);
	void      (*pfncClose)(struct c_drvobj *self, struct c_fileobj *pFileObj);
	FILE_ERR  (*pfncIoControl)(struct c_drvobj *self, struct c_fileobj *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
	FILE_POS  (*pfncSeek)(struct c_drvobj *self, struct c_fileobj *pFileObj, FILE_POS Offset, int iOrign);
	FILE_SIZE (*pfncRead)(struct c_drvobj *self, struct c_fileobj *pFileObj, void *pBuf, FILE_SIZE Size);
	FILE_SIZE (*pfncWrite)(struct c_drvobj *self, struct c_fileobj *pFileObj, const void *pData, FILE_SIZE Size);
	FILE_ERR  (*pfncFlush)(struct c_drvobj *self, struct c_fileobj *pFileObj);
	FILE_ERR  (*pfncGetInformation)(struct c_drvobj *self, char *pszInformation, int iLen);
} T_DRVOBJ_METHODS;


/* デバイスドライバオブジェクト基本クラス */
typedef struct c_drvobj
{
	C_HANDLEOBJ				HandleObj;				/**< ハンドルオブジェクトを継承 */
} C_DRVOBJ;


#include "system/file/fileobj.h"


#ifdef __cplusplus
extern "C" {
#endif

HANDLE    DrvObj_Create(const T_DRVOBJ_METHODS *pMethods);							/**< 生成 */
void      DrvObj_Delete(HANDLE hDriver);											/**< 削除 */

#ifdef __cplusplus
}
#endif

#define  DrvObj_GetMethods(self)						((const T_DRVOBJ_METHODS *)HandleObj_GetMethods(&(self)->HandleObj))

/* 仮想関数呼び出し用マクロ */
#define  DrvObj_vOpen(self, pszPath, iMode)				(DrvObj_GetMethods(self)->pfncOpen((self), (pszPath), (iMode)))
#define  DrvObj_vClose(self, pFileObj)					(DrvObj_GetMethods(self)->pfncClose((self), (pFileObj)))
#define  DrvObj_vIoControl(self, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize)	\
														(DrvObj_GetMethods(self)->pfncIoControl((self), (pFileObj), (iFunc), (pInBuf), (InSize), (pOutBuf), (OutSize)))
#define  DrvObj_vSeek(self, pFileObj, Offset, iOrign)	(DrvObj_GetMethods(self)->pfncSeek((self), (pFileObj), (Offset), (iOrign)))
#define  DrvObj_vRead(self, pFileObj, pBuf, Size)		(DrvObj_GetMethods(self)->pfncRead((self), (pFileObj), (pBuf), (Size)))
#define  DrvObj_vWrite(self, pFileObj, pData, Size)		(DrvObj_GetMethods(self)->pfncWrite((self), (pFileObj), (pData), (Size)))
#define  DrvObj_vFlush(self, pFileObj)					(DrvObj_GetMethods(self)->pfncFlush((self), (pFileObj)))


#endif	/* __HOS__drvobj_h__ */


/* end of file */
