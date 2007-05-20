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


#include "file.h"


struct c_drvobj;
struct c_fileobj;

/* デバイスドライバオブジェクト基本クラス メソッドテーブル */
typedef struct t_drvobj_methods
{
	void      (*pfncDelete)(struct c_drvobj *self);
	HANDLE    (*pfncOpen)(struct c_drvobj *self, const char *pszPath, int iMode);
	void      (*pfncClose)(struct c_drvobj *self, struct c_fileobj *pFileObj);
	FILE_ERR  (*pfncIoControl)(struct c_drvobj *self, struct c_fileobj *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
	FILE_POS  (*pfncSeek)(struct c_drvobj *self, struct c_fileobj *pFileObj, FILE_POS Offset, int iOrign);
	FILE_SIZE (*pfncRead)(struct c_drvobj *self, struct c_fileobj *pFileObj, void *pBuf, FILE_SIZE Size);
	FILE_SIZE (*pfncWrite)(struct c_drvobj *self, struct c_fileobj *pFileObj, const void *pData, FILE_SIZE Size);
	FILE_ERR  (*pfncFlush)(struct c_drvobj *self, struct c_fileobj *pFileObj);
} T_DRVOBJ_METHODS;


/* デバイスドライバオブジェクト基本クラス */
typedef struct c_drvobj
{
	const T_DRVOBJ_METHODS *pMethods;
} C_DRVOBJ;


#include "system/file/fileobj.h"


#ifdef __cplusplus
extern "C" {
#endif

void      DrvObj_Create(C_DRVOBJ *self, const T_DRVOBJ_METHODS *pMethods);		/**< コンストラクタ */
void      DrvObj_Delete(C_DRVOBJ *self);											/**< デストラクタ */

HANDLE    DrvObj_Open(C_DRVOBJ *self, const char *pszPath, int iMode);
void      DrvObj_Close(C_DRVOBJ *self, struct c_fileobj *pFileObj);
FILE_ERR  DrvObj_IoControl(C_DRVOBJ *self, struct c_fileobj *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize);
FILE_POS  DrvObj_Seek(C_DRVOBJ *self, struct c_fileobj *pFileObj, FILE_POS Offset, int iOrign);
FILE_SIZE DrvObj_Read(C_DRVOBJ *self, struct c_fileobj *pFileObj, void *pBuf, FILE_SIZE Size);
FILE_SIZE DrvObj_Write(C_DRVOBJ *self, struct c_fileobj *pFileObj, const void *pData, FILE_SIZE Size);
FILE_ERR  DrvObj_Flush(C_DRVOBJ *self, struct c_fileobj *pFileObj);

#ifdef __cplusplus
}
#endif


/* 仮想関数呼び出し用マクロ */
#define  DrvObj_vOpen(self, pszPath, iMode)				((self)->pMethods->pfncOpen((self), (pszPath), (iMode)))
#define  DrvObj_vClose(self, pFileObj)					((self)->pMethods->pfncClose((self), (pFileObj)))
#define  DrvObj_vIoControl(self, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize)	\
														((self)->pMethods->pfncIoControl((self), (pFileObj), (iFunc), (pInBuf), (InSize), (pOutBuf), (OutSize)))
#define  DrvObj_vSeek(self, pFileObj, Offset, iOrign)	((self)->pMethods->pfncSeek((self), (pFileObj), (Offset), (iOrign)))
#define  DrvObj_vRead(self, pFileObj, pBuf, Size)		((self)->pMethods->pfncRead((self), (pFileObj), (pBuf), (Size)))
#define  DrvObj_vWrite(self, pFileObj, pData, Size)		((self)->pMethods->pfncWrite((self), (pFileObj), (pData), (Size)))
#define  DrvObj_vFlush(self, pFileObj)					((self)->pMethods->pfncFlush((self), (pFileObj)))


#endif	/* __HOS__drvobj_h__ */


/* end of file */
